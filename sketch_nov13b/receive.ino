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
