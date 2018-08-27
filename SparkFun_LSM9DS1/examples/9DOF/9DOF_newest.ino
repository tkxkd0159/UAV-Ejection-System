/*****************************************************************

The LSM9DS1 has a maximum voltage of 3.6V. 

*****************************************************************/
#include <Wire.h> 
#include <SPI.h>
#include <SparkFunLSM9DS1.h> // Calculate Data


LSM9DS1 imu;


#define LSM9DS1_M  0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW

#define PRINT_CALCULATED

#define PRINT_SPEED 500 // ~ms 
static unsigned long lastPrint = 0; // Keep track of print time

// Earth's magnetic field varies by location. Add or subtract 

// http://www.ngdc.noaa.gov/geomag-web/#declination
#define DECLINATION -8.45 // Declination (degrees) in seoul

void setup() 
{
  
  Serial.begin(115200);
  
  // Before initializing the IMU, there are a few settings
  // we may need to adjust. Use the settings struct to set
  // the device's communication mode and addresses:
  imu.settings.device.commInterface = IMU_MODE_I2C;
  imu.settings.device.mAddress = LSM9DS1_M;
  imu.settings.device.agAddress = LSM9DS1_AG;
  // The above lines will only take effect AFTER calling
  // imu.begin(), which verifies communication with the IMU
  // and turns it on.
  if (!imu.begin())
  {
    Serial.println("Failed to communicate with LSM9DS1.");
    Serial.println("Double-check wiring.");
    Serial.println("Default settings in this sketch will " \
                  "work for an out of the box LSM9DS1 " \
                  "Breakout, but may need to be modified " \
                  "if the board jumpers are.");
    while (1)
      ;
  }
}

void loop()
{
  // Update the sensor values whenever new data is available
  if ( imu.gyroAvailable() )
  {
    // To read from the gyroscope,  first call the
    // readGyro() function. When it exits, it'll update the
    // gx, gy, and gz variables with the most current data.
    imu.readGyro();
  }
  if ( imu.accelAvailable() )
  {
    // To read from the accelerometer, first call the
    // readAccel() function. When it exits, it'll update the
    // ax, ay, and az variables with the most current data.
    imu.readAccel();
  }
  if ( imu.magAvailable() )
  {
    // To read from the magnetometer, first call the
    // readMag() function. When it exits, it'll update the
    // mx, my, and mz variables with the most current data.
    imu.readMag();
  }
  
  if ((lastPrint + PRINT_SPEED) < millis())
  {

    printAccel(); 
    printGyro();  
    printMag();   
    
    // Call print attitude. The LSM9DS1's mag x and y
    // axes are opposite to the accelerometer, so my, mx are
    // substituted for each other.
    printAttitude(imu.ax, imu.ay, imu.az, 
                 -imu.my, -imu.mx, imu.mz);
    Serial.println();
    
    lastPrint = millis(); // Update lastPrint time
  }
}

void printGyro()
{
  // Now we can use the gx, gy, and gz variables as we please.
  // Either print them as raw ADC values, or calculated in DPS.
  Serial.print("Gyro: ");
#ifdef PRINT_CALCULATED
  // If you want to print calculated values, you can use the
  // calcGyro helper function to convert a raw ADC value to
  // DPS. Give the function the value that you want to convert.
  Serial.print(imu.calcGyro(imu.gx), 2);
  Serial.print(", ");
  Serial.print(imu.calcGyro(imu.gy), 2);
  Serial.print(", ");
  Serial.print(imu.calcGyro(imu.gz), 2);
  Serial.println(" deg/s");
#elif defined PRINT_RAW
  Serial.print(imu.gx);
  Serial.print(", ");
  Serial.print(imu.gy);
  Serial.print(", ");
  Serial.println(imu.gz);
#endif
}

void printAccel()
{  
  // Now we can use the ax, ay, and az variables as we please.
  // Either print them as raw ADC values, or calculated in g's.
  Serial.print("Accel: ");
#ifdef PRINT_CALCULATED
  // If you want to print calculated values, you can use the
  // calcAccel helper function to convert a raw ADC value to
  // g's. Give the function the value that you want to convert.
  Serial.print(-imu.calcAccel(imu.ax), 2);
  Serial.print(", ");
  Serial.print(-imu.calcAccel(imu.ay), 2);
  Serial.print(", ");
  Serial.print(-imu.calcAccel(imu.az), 2);
  Serial.println(" g");
#elif defined PRINT_RAW 
  Serial.print(imu.ax);
  Serial.print(", ");
  Serial.print(imu.ay);
  Serial.print(", ");
  Serial.println(imu.az);
#endif

}

void printMag()
{  
  // Now we can use the mx, my, and mz variables as we please.
  // Either print them as raw ADC values, or calculated in Gauss.
  Serial.print("Mag: ");
#ifdef PRINT_CALCULATED

  /* If you want to print calculated values, you can use the
   calcMag helper function to convert a raw ADC value to
   Gauss. Give the function the value that you want to convert.*/
   
  Serial.print(-imu.calcMag(imu.my), 2);
  Serial.print(", ");
  Serial.print(-imu.calcMag(imu.mx), 2);
  Serial.print(", ");
  Serial.print(imu.calcMag(imu.mz), 2);
  Serial.println(" gauss");
#elif defined PRINT_RAW
  Serial.print(imu.mx);
  Serial.print(", ");
  Serial.print(imu.my);
  Serial.print(", ");
  Serial.println(imu.mz);
#endif
}


void printAttitude(float ax, float ay, float az, float mx, float my, float mz)
{
  float real_ax= -ax;
  float real_ay = -ay;
  float real_az = az; 
  float roll = atan2(real_ay, real_az);
  float pitch;
  if (real_az >= 0)
  
  pitch = asin(-real_ax/sqrt(real_ax*real_ax + real_ay * real_ay + real_az * real_az));

  else if(real_az < 0 && real_ax < 0)
  
  pitch = -asin(-real_ax/sqrt(real_ax*real_ax + real_ay * real_ay + real_az * real_az))+ PI;

  else if(real_az < 0 && real_ax >= 0)
  
   pitch = -asin(-real_ax/sqrt(real_ax*real_ax + real_ay * real_ay + real_az * real_az)) - PI;
   
  float heading;

  if (mx == 0)
    heading = (my < 0) ? PI : 0; //if mx<0, then heading=PI else 0

  
 
    
  else
  
    heading = atan2(mx, my);
    
  heading += DECLINATION * PI / 180;


  if (heading < 0)
      heading += 2*PI;



  

  
  // Convert everything from radians to degrees:
  heading *= 180.0 / PI;
  pitch *= 180.0 / PI;
  roll  *= 180.0 / PI;

  Serial.print("Pitch: ");
  Serial.print(pitch, 2); Serial.println(" deg");
  Serial.print("Roll: ");
  Serial.print(roll, 2); Serial.println(" deg");
  Serial.print("Heading: "); 
  Serial.print(heading, 2);Serial.println(" deg");

}
