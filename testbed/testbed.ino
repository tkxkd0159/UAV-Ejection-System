#include <TinyGPS++.h>
#include <string.h>

TinyGPSPlus gps;
 float lon, lati;
 char buf_lon[4], buf_lat[4], packet[28];
 byte HDOP;
 
void setup() {
   
  Serial.begin(9600);
  Serial1.begin(9600);
 
}

void loop()
{
   if(Serial1.available() > 0){
    if (gps.encode(Serial1.read()))
      displayInfo();

      
    }

    
 
}

void displayInfo()
{

  if (gps.location.isValid())
  {
     lon = gps.location.lng();
     lati = gps.location.lat();
     memcpy(&buf_lon, &lon,sizeof(float));
     memcpy(&buf_lat, &lati,sizeof(float));
  }
   if(gps.hdop.isValid()){
    HDOP = gps.hdop.hdop();
   }
  
   packet[0]=0xFF;
   packet[1]=0xFF;
   packet[2]=buf_lat[0];
   packet[3]=buf_lat[1];
   packet[4]=buf_lat[2];
   packet[5]=buf_lat[3];
   packet[6]=buf_lon[0];
   packet[7]=buf_lon[1];
   packet[8]=buf_lon[2];
   packet[9]=buf_lon[3];
   packet[10]=0;
   packet[11]=0;
   packet[12]=0;
   packet[13]=0;
   packet[14]=0;
   packet[15]=0;
   packet[16]=0;
   packet[17]=0;
   packet[18]=0;
   packet[19]=0;
   packet[20]=0;
   packet[21]=0;
   packet[22]=0;
   packet[23]=0;
   packet[24]=0;
   packet[25]=0;
   packet[26]=0xFD;
   packet[27]=0xFD;
   
   /*packet[8]=buf_hdop[0];
   packet[9]=buf_hdop[1];
   packet[10]=buf_hdop[2];
   packet[11]=buf_hdop[3];*/
   

   Serial.write(packet,sizeof(packet));


  }


