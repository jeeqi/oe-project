#include <AirqualityGp2y10.h>
AirqualityGp2y10 AirqualityGp2y10(0,2);//set IO,first Nuberm must be analog IO;the other must be didital IO
//int DustPin1 = 0;
//int LedPin1 = 2;
void setup()
{
  Serial.begin(9600);
//  pinMode(LedPin1, OUTPUT);//set Led driver
}
void loop()
{  
   Serial.println(AirqualityGp2y10.APIair(5));//set test time s.
}
///////

