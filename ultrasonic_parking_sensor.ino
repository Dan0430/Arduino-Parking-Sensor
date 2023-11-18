#include <ultrasonic.h>

//Start Ultrasonic library/ trigPin, echoPin
ultrasonic ultrasonic(12 ,11);

//Set LED pin
int led = 2;


void setup() {
  
  //Init LED Pin
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  //Start optional Serial
  Serial.begin(9600);
}

void loop() {
  
  //Imperial or Metric measurement
  int distance = ultrasonic.inches();
//int distance = ultrasonic.cm();
  
  Serial.println(distance);
  
  //Set distance to trigger LED
  if (distance <= 3)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
  
  delay(250);
}
