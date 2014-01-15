#include "Arduino.h"
#include "AirqualityGp2y10.h"
 
AirqualityGp2y10::AirqualityGp2y10(int pin1,int pin2)//pin1 must be analog IO;pin2 must be digital IO
{
  pinMode(pin2, OUTPUT);//set Led driver
  DustPin = pin1;	
  LedPin = pin2;
}
 
float AirqualityGp2y10::AirDensity()
{       
 	int DustVal;
       	float Airdensity;
        
       digitalWrite(LedPin,LOW);// power on the LED
	delayMicroseconds(280);
	DustVal=analogRead(DustPin); // read the dust value via pin 5 on the sensor
	delayMicroseconds(40);
	digitalWrite(LedPin,HIGH); // turn the LED off
	delayMicroseconds(9680);
//	Serial.println(DustVal*0.0048); //test
	Airdensity = DustVal*0.00488/1.1198/5;//air density of Solid particles// average value of air density
       delay(90);
//		Serial.println(Airdensity); //test

       return Airdensity;
}
//
float AirqualityGp2y10::aver(int num)	 //º¯Êý¶¨Òå
{
    float sum=0,temp;
    float sum1[num];
    int i = 0,j = 0;
    for(i=0;i<num;i++)
    {
      sum1[i]=AirDensity();/////
    }
    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(sum1[i]>sum1[j])
            {
                temp=sum1[i];
                sum1[i]=sum1[j];
                sum1[j]=temp;
            }
        }
    }
    for(i=0;i<num;i++)
    sum+=sum1[i];
    return(sum/num);
}
//
int AirqualityGp2y10::APIair(int Time)
{
   int DensityAPI;
   float Density;
   
   Density = aver(Time*10);//////
//Serial.println(Density);//test
   if(Density<0.05)//1
     {
         DensityAPI=Density/0.001;
     } 
     else if(Density>0.05 && Density<0.15) //2
            {
               DensityAPI=50+(Density-0.05)/0.002;
            }
             else if(Density>0.15 && Density<0.35) //3
                    {
                       DensityAPI=98+(Density-0.15)/0.002;
                    }
                   else if(Density>0.35 && Density<0.4) //4
                        {
                             DensityAPI=200+(Density-0.35)/0.0007;
                        }
                         else if(Density>0.42 && Density<0.5) //5
                              {
                                   DensityAPI=300+(Density-0.42)/0.008;
                               }
                               else if(Density>0.5 && Density<0.6) //6
                                      {
                                           DensityAPI=400+(Density-0.5)/0.001;
                                      }
      return(DensityAPI);
}
