#include <Servo.h>
Servo Biteservo;         //servomotor 를 정의합니다.
int pos=0;

void setup() {
  Biteservo.attach(2);       //신호를 받을부분의 핀을 선정합니다. 저희는 2번핀에 준비합니다.
}

void loop() {
  for(pos = 20; pos < 160; pos+=1) //서보의 위치 0~180도 각을 정의합니다.
  {
    Biteservo.write(50);             
    delay(10);
  }
if(pos==160)
  {
    Biteservo.write(100);            
    delay(1000);
  }


 /*   Biteservo.write(123);             // close 122, open 0
  
   delay(1000);

    Biteservo.write(0);*/
 

}

  


