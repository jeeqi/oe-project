#ifndef UtraIndensity_h
#define UtraIndensity_h
 #include "Arduino.h"
 
class UtraIndensity
{
  public:
    UtraIndensity(int Pin);
    int UvNum();
  private:
    int TestPin;
};
#endif
