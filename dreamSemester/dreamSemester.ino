#include <TinyGPS++.h>
#include <string.h>
#include <Servo.h>


//#define SBUF_SIZE 64
Servo Biteservo;
TinyGPSPlus gps;  

char sbuf[64];
char FC_data[28];
char ejec_data[12];

char buf_lon[4], buf_lat[4],buf_roll[4], buf_pitch[4], buf_yaw[4], buf_ejeclon[4], buf_ejeclat[4];



signed int sbuf_cnt=0;
float roll, pitch, yaw;
float gps_lon, gps_lat,ejeclon, ejeclat;
byte HDOP;
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
           
       }
     else if(sbuf[sbuf_cnt]=='*')
       {   sbuf_cnt=-1;
       }

     sbuf_cnt++;
     if(sbuf_cnt>=64) sbuf_cnt=0;
  }
  
  return result;
}



void setup()
{
  Serial.begin(9600); //xbee
  Serial1.begin(9600); //GPS
  Serial2.begin(115200); //IMU
  Biteservo.attach(2);
  Biteservo.write(123);
}

void loop()
{

  
if(Parser(euler, 3))
  {
    roll = euler[0];
    pitch = euler[1];
    yaw = euler[2];
  }


 
  if(Serial1.available() > 0){
    
    if(gps.encode(Serial1.read())){
      displayInfo();
    }
    
  }

  
    Data_struc();
//    FCCtoGCS_Data();

    



    Serial.write(FC_data, sizeof(FC_data));

  
/*
if(roll>60){

  Biteservo.write(0);

  ejeclon = gps.location.lng();
  ejeclat = gps.location.lat();

  memcpy(&buf_ejeclon, &ejeclon, sizeof(float));
  memcpy(&buf_ejeclat, &ejeclat, sizeof(float));

 ejec_data[0] = 0xDD;
 ejec_data[1] = 0xDD;
 ejec_data[2] = buf_ejeclon[0];
 ejec_data[3] = buf_ejeclon[1];
 ejec_data[4] = buf_ejeclon[2];
 ejec_data[5] = buf_ejeclon[3];
 ejec_data[6] = buf_ejeclat[0];
 ejec_data[7] = buf_ejeclat[1];
 ejec_data[8] = buf_ejeclat[2];
 ejec_data[9] = buf_ejeclat[3];
 ejec_data[10] = 0xDF;
 ejec_data[11] = 0xDF;

 Serial.write(ejec_data, sizeof(ejec_data));
 }
  */


   



  
}

void Data_struc()
{

  memcpy(&buf_lon, &gps_lon, sizeof(float));
  memcpy(&buf_lat, &gps_lat, sizeof(float));
  //memcpy(&buf_hdop, &gps_hdop, sizeof(long));
  memcpy(&buf_roll, &roll, sizeof(float));
  memcpy(&buf_pitch, &pitch, sizeof(float));
  memcpy(&buf_yaw, &yaw, sizeof(float));

  
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
  
  if (gps.location.isValid())
  {
   gps_lon = gps.location.lng();
   gps_lat = gps.location.lat();
  

  }
  
  if(gps.hdop.isValid()){
       
      gps_hdop = gps.hdop.hdop();
  
}
}
