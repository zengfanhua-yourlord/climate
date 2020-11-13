#include  "head.h"

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); //serial start command
   
}

void loop() {
  
analogWrite(temp,pid(DHT11.temperature/*analogRead(0)*/,tempset,10,255));
analogWrite(humi,pid(DHT11.humidity,humiset,10,255));
//analogWrite(fanpin,255-pid(DHT11.humidity,humiset,10,255));

//
while (Serial.available() > 0)   //不断检测串口是否有数据
   {
        receive_data();            //接受串口数据
        test_do_data();               //测试数据是否正确并更新标志位
   }
}
