#include <ultrasonic.h>
#include <LiquidCrystal.h>

//Start Ultrasonic library/ trigPin, echoPin
ultrasonic ultrasonic(12 ,11);

const int rs = 4, en = 5, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Set LED pin
int led = 2;


void setup() {
  
  //Init LED Pin
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  lcd.begin(16,2);

  //Start optional Serial
  Serial.begin(9600);
}

void loop() {
  
  //Imperial or Metric measurement
  int distance = ultrasonic.inches();
//int distance = ultrasonic.cm();
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(distance);
  lcd.print(" in.");
  //Set distance to trigger LED
  if (distance <= 2)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
  
  delay(500);
}
