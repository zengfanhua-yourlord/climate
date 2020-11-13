#ifndef _head_h_
#define _head_h_
#define oncommand 0x00
#define offcommand 0x01
int lightpin=4;
int light2pin=8;
int waterpin=7;
//int fanpin=9;
int temp = 3;
int humi = 5;
 //int errortime=0;
 int tempset;
 int humiset;
// #define errortext 0xFF
//down this is dht11 set
#include <dht11.h>
#define Temperature_COMMAND  0x10   //采集命令字
#define Humidity_COMMAND     0x11   //采集命令字

/*-----( Declare objects )-----*/
dht11 DHT11;

/*-----( Declare Constants, Pin Numbers )-----*/
#define DHT11PIN 2

byte comdata[3]={0};      //定义数组数据，存放串口接收数据
 #endif
