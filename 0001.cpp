#define oncommand 0x00
#define offcommand 0x01
int lightpin=4;
int light2pin=8;
int waterpin=7;
//int fanpin=9;
int temp = 3;
int humi = 5;
 int errortime=0;
 int tempset;
 int humiset;
//down this is dht11 set
#include <dht11.h>
#define Temperature_COMMAND  0x10   //采集命令字
#define Humidity_COMMAND     0x11   //采集命令字

/*-----( Declare objects )-----*/
dht11 DHT11;

/*-----( Declare Constants, Pin Numbers )-----*/
#define DHT11PIN 2

byte comdata[3]={0};      //定义数组数据，存放串口接收数据
 
void receive_data(void);      //接受串口数据
void test_do_data(void);  
//
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


int pid(int give,int set,int wait,int ftmax)//pid control module
{   
int ft=0;
if (give>set&&ft<ftmax)
{
 
  ft++;
  return ft;
 
  }
else if (set<give&&ft>0)
{
  ft--;
  return ft;
  }
  else
  {
    return ft;
    delay(wait);
    }
}
//dht11 module
void receive_data(void)       
{
   int i ;
   for(i=0;i<3;i++)
   {
      comdata[i] =Serial.read();
      //延时一会，让串口缓存准备好下一个字节，不延时可能会导致数据丢失，
       delay(2);
   }
}
 
void test_do_data(void)
{
 
  if(comdata[0] == 0x55)            //0x55和0xAA均为判断是否为有效命令
   {
     if(comdata[1] == 0xAA)
     {
        switch (comdata[2])
        {
            case Temperature_COMMAND: 
            DHT11.read(DHT11PIN);
            Serial.println((float)DHT11.temperature, 2); 
            break;
            case Humidity_COMMAND:  
            DHT11.read(DHT11PIN);
            Serial.println((float)DHT11.humidity, 2); 
            break;

        }
      }
      if(comdata[1] == 0xFF)        //0xFF is  light control mod
      {
        switch (comdata[2])         //a selection
         {
            case oncommand:      //get command
                 light(1);
                 break;
            case offcommand:      //get command
           light(0); 
            break;
             }

             
     /* else 
     {
      Serial.println(errortime+1);
      }*/
   }
    if(comdata[1] == 0xEE)        //0xFF is  water control mod
      {
        switch (comdata[2])         //a selection
         {
            case oncommand:      //get command
                 water(1);
                 break;
            case offcommand:      //get command
           water(0); 
            break;
             }
      }
      if(comdata[1] == 0xDD)        //0xFF is  water control mod
      {
        switch (comdata[2])         //a selection
         {
            case oncommand:      //get command
                 light2(1);
                 break;
            case offcommand:      //get command
           light2(0); 
            break;
             }
      }
  /* else
   {
    Serial.println(errortime+1);
 
   }*/

 if(comdata[1] == 0xBB)        //0xbb is  temp control mod
      {
        tempset=comdata[2];
      }
  if(comdata[1] == 0xCC)        //0xcc is  humi control mod
      {
        humiset=comdata[2];
      }
      

   
}
/*else{
  errortime++;
   Serial.println("errortime");
  Serial.println(errortime); 
}*/
}
void light(int lm)
{
digitalWrite(lightpin,lm);  
}
void light2(int lm)
{
digitalWrite(light2pin,lm);  
}
void water(int ll)
{
  digitalWrite(waterpin,ll);
}

