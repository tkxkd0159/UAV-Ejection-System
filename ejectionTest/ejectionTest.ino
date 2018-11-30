#include <string.h>
#include <Servo.h>

#define SBUF_SIZE 64
Servo Biteservo;

static const uint32_t IMUBaud = 115200;
static const uint32_t XBEEBaud = 9600;

char sbuf[SBUF_SIZE];
signed int sbuf_cnt=0;
float roll, pitch, yaw;
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
     if(sbuf_cnt>=SBUF_SIZE) sbuf_cnt=0;
  }
  
  return result;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(XBEEBaud);
  Serial2.begin(IMUBaud);
  Biteservo.attach(2);
  Biteservo.write(123);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if(Parser(euler, 3))
  { 
     Serial.print("\n\r");
     
     Serial.print(euler[0]);   Serial.print(" ");
     Serial.print(euler[1]);   Serial.print(" ");
     Serial.print(euler[2]);   Serial.print(" ");
    roll = euler[0];
    pitch = euler[1];
    yaw = euler[2];
  }
  
else{
  Serial.print(F("INVALID"));
  Serial.print("\n\r");
}
    


 if(roll > 60 || roll< -60){
  Serial.print(777);
  Biteservo.write(0);
  }

}
