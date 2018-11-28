#include <TinyGPS++.h>
#include <string.h>



#define SBUF_SIZE 64

static const uint32_t IMUBaud = 115200;
static const uint32_t GPSBaud = 9600;

char sbuf[SBUF_SIZE];
char buf_lon[4], buf_lat[4], buf_hdop[4], buf_roll[4], buf_pitch[4], buf_yaw[4];
char FC_data[28];

signed int sbuf_cnt=0;
float roll, pitch, yaw, gps_hdop, gps_lon, gps_lat;
float euler[3];

int Parser(float *item, int number_of_item)
{
  int n,i;
  int rbytes;
  char *addr; 
  int result = 0;
  
  rbytes = Serial2.available();
  for(n=0;n<rbytes;n++)
  {
    sbuf[sbuf_cnt] = Serial2.read();
    if(sbuf[sbuf_cnt]==0x0a)
       {
           addr = strtok(sbuf,",");
           for(i=0;i<number_of_item;i++)
           {
              item[i] = atof(addr);
              addr = strtok(NULL,",");
           }

           result = 1;

         // Serial.print("\n\r");
         // for(i=0;i<number_of_item;i++)  {  Serial.print(item[i]);  Serial.print(" "); }
       }
     else if(sbuf[sbuf_cnt]=='*')
       {   sbuf_cnt=-1;
       }

     sbuf_cnt++;
     if(sbuf_cnt>=SBUF_SIZE) sbuf_cnt=0;
  }
  
  return result;
}




TinyGPSPlus gps;



void setup()
{
  Serial.begin(57600);
  Serial1.begin(GPSBaud);
  Serial2.begin(IMUBaud);


  //Serial.print(F("Testing System v. ")); Serial.println(TinyGPSPlus::libraryVersion());
  //Serial.println();
}

void loop()
{
if(Parser(euler, 3))
  {
    roll = euler[0];
    pitch = euler[1];
    yaw = euler[2];

    
   //  Serial.print("\n\r");
   //  Serial.print(euler[0]);   Serial.print(" ");
    // Serial.print(euler[1]);   Serial.print(" ");
    // Serial.print(euler[2]);   Serial.print(" ");
  }


 
  if(Serial1.available() > 0){
    
    if(gps.encode(Serial1.read())){
      displayInfo();
    }
    
  }

  
    Data_struc();
    FCCtoGCS_Data();
    Serial.write(FC_data, sizeof(FC_data));

 /* if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
  
  }
*/
  
}

void Data_struc()
{
  memcpy(&gps_lon, buf_lon, sizeof(float));
  memcpy(&gps_lat, buf_lat, sizeof(float));
  memcpy(&gps_hdop, buf_hdop, sizeof(float));
  memcpy(&roll, buf_roll, sizeof(float));
  memcpy(&pitch, buf_pitch, sizeof(float));
  memcpy(&yaw, buf_yaw, sizeof(float));
  
}

void FCCtoGCS_Data()
{
  FC_data[0] = 0xFF;
  FC_data[1] = 0xFF;
  
  FC_data[2] = buf_lat[0];
  FC_data[3] = buf_lat[1];
  FC_data[4] = buf_lat[2];
  FC_data[5] = buf_lat[3];
  
  FC_data[6] = buf_lon[0];
  FC_data[7] = buf_lon[1];
  FC_data[8] = buf_lon[2];
  FC_data[9] = buf_lon[3];

  FC_data[10] = buf_hdop[0];
  FC_data[11] = buf_hdop[1];
  FC_data[12] = buf_hdop[2];
  FC_data[13] = buf_hdop[3];

  FC_data[14] = buf_roll[0];
  FC_data[15] = buf_roll[1];
  FC_data[16] = buf_roll[2];
  FC_data[17] = buf_roll[3];

  FC_data[18] = buf_pitch[0];
  FC_data[19] = buf_pitch[1];
  FC_data[20] = buf_pitch[2];
  FC_data[21] = buf_pitch[3];

  FC_data[22] = buf_yaw[0];
  FC_data[23] = buf_yaw[1];
  FC_data[24] = buf_yaw[2];
  FC_data[25] = buf_yaw[3];

  FC_data[26] = 0xFE;
  FC_data[27] = 0xFE;

  
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid() || gps.hdop.isValid())
  {
   gps_lon = gps.location.lng();
   gps_lat = gps.location.lat();
   gps_hdop = gps.hdop.hdop();
    
   // Serial.print(gps.location.lat(), 6);  // (data, significant figure)
   // Serial.print(F(","));
  //  Serial.println(gps.location.lng(), 6);
   // Serial.print(gps.hdop.hdop(), 3);
  }
  else
  {
    //Serial.print(F("INVALID"));
  }

  //Serial.println();
}
