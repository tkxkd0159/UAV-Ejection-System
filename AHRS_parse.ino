char Buffer[20];
char chkbuf[2];

int roll, pitch, yaw, sof, sum;
byte trigger = 0;



void setup() {

  Serial.begin(115200);

}



void loop() {




  int cnt = 0;

  //data receive status

  if (Serial.available() < 1) {

    return 0;

  }

if(trigger == 0){    
byte temp = 0; 
while(1){
  
   char tempdata = Serial.read();
   chkbuf[temp] = tempdata;
   temp= temp+1;
   if(temp[0]== 0x55 && temp[1] == 0x55){
    trigger = 1;
       break;
   } 
   
   if(temp == 2){
    temp = 0}
   }
}


  while (cnt!=11) {

    if (Serial.available() < 1) {

      continue;   // when serial have no data, skip while

    }

  char data = Serial.read();

    Buffer[cnt] = data;
    cnt++;
}
  

   
      
sscanf(Buffer,"%d%d%d%d",&roll,&pitch,&yaw,&sum);

  Serial.print("Roll = ");Serial.print(roll);Serial.print(" ");

  Serial.print("Pitch = "); Serial.print(pitch);Serial.print(" ");

  Serial.print("Yaw = "); Serial.println(yaw);
  
    

trigger = 0;
    

  }


  
