#include "Arduino.h"
#include "UtraIndensity.h"
UtraIndensity::UtraIndensity(int Pin)//pin1 must be analog IO
{
    TestPin = Pin;
}
///////////////
int UtraIndensity::UvNum()// Detection interval of Uv
{
    int Sensorvoltage = 0;//  signed int Sensorvoltage1 = 0;
    int UltraNum = 0;// UV intensity

    Sensorvoltage = analogRead(TestPin)*4.8; //read voltage
    Serial.println(Sensorvoltage);//test
    //  Sensorvoltage1= Sensorvoltage*4.8;//0.00488v=4.8mV
    // determine the UV intensity
    //voltage (mV)   50-- 227 / 227--318/ 318--408 / 408--503   /503--606/ 606--696/ 696--795/ 795--881 / 881-976 /976--1079 /1079--1170/ 1170++
    //UV intensity \:    0         1         2         3           4           5      6           7          8         9          10        11
if(Sensorvoltage < 50)
     {UltraNum = 0;}
   else if(Sensorvoltage >50 && Sensorvoltage < 227)
     {UltraNum = 1;}
      else if(Sensorvoltage > 227 && Sensorvoltage < 318 )
             {UltraNum = 2;}
             else if(Sensorvoltage > 317 && Sensorvoltage < 408 )
                    {UltraNum = 3;}
                  else if(Sensorvoltage > 408 && Sensorvoltage < 503 )
                         {UltraNum == 4;}
                          else if(Sensorvoltage > 503 && Sensorvoltage < 606 )
                                 {UltraNum = 5;}
                                  else if(Sensorvoltage > 606 && Sensorvoltage < 696 )
                                         {UltraNum = 6;}
                                         else if(Sensorvoltage > 696 && Sensorvoltage < 795 )
                                                {UltraNum = 7;}
                                                else if(Sensorvoltage > 795 && Sensorvoltage < 881 )
                                                       {UltraNum = 8;}
                                                       else if(Sensorvoltage > 881 && Sensorvoltage < 976 )
                                                              {UltraNum = 9;}
                                                              else if(Sensorvoltage > 976 && Sensorvoltage < 1079 )
                                                                     {UltraNum = 10;}
                                                                     else if(Sensorvoltage > 1079 && Sensorvoltage < 1170 )
                                                                            {UltraNum ==11;}
                                                                            else if(Sensorvoltage > 1170 )
                                                                                   {UltraNum = 11;}

    return(UltraNum);
}
 
