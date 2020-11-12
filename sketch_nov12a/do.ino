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
