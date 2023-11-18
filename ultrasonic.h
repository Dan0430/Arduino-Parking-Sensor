
#ifndef ultrasonic_h
#define ultrasonic_h

#include "Arduino.h"
#include <inttypes.h>

class ultrasonic
{
  public:
   
    ultrasonic(int trigPin, int echoPin);

    void pulse();
    int inches();
    int cm();
  
  private:
    
    int _measurement;
    int _trig, _echo;
    long _duration, _distance;

};

#endif