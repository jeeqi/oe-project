#ifndef AirqualityGp2y10_H
#define AirqualityGp2y10_H 
#include "Arduino.h"
 
class AirqualityGp2y10
{
  public:
    AirqualityGp2y10(int Pin1,int pin2);
    int APIair(int Time);
  private:
    int DustPin;
    int LedPin;
    float aver(int num);	 //º¯Êý¶¨Òå
    float AirDensity();
};
#endif
