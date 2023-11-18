#include "Arduino.h"
#include "ultrasonic.h"

//Init function with inputs trig pin, echo pin
ultrasonic::ultrasonic(int trigPin, int echoPin)
{
    _trig = trigPin;
    _echo = echoPin;
    
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    
}

//Pulse loop to get trig duration
void ultrasonic::pulse()
{

    digitalWrite(_trig, LOW);
    delayMicroseconds(2);
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig, LOW);
    delayMicroseconds(2);

    //Time
    _duration = pulseIn(_echo, HIGH) / 2;
    //Divide by two because of travel back and forth from sensor
}

//Distance = Speed * Time

//Convert Duration to Distance in Inches
int ultrasonic::inches()
{
  pulse();
  _distance = _duration * 0.0135;
  return(_distance);
}

//Convert Duration to Distance in Centimeters
int ultrasonic::cm()
{
  pulse();
  _distance = _duration * 0.034;
  return(_distance);
}