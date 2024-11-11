#include <LiquidCrystal.h>
LiquidCrystal lcd (12 , 11 , 5 , 4 , 3 , 2 );
int tring = 9;
int echo = 10;
int duration ;
int dist;
void setup() {
  Serial.begin(9600);
  pinMode(tring , OUTPUT);
  pinMode(echo , INPUT);
  lcd.begin(16 , 2);
  lcd.clear();
}
void loop() {
  digitalWrite(tring , LOW);
  delayMicroseconds(2);
  digitalWrite(tring , HIGH);
  delayMicroseconds(10);
  digitalWrite(tring , LOW);
  
  duration = pulseIn(echo , HIGH);
  dist = (duration / 2) * 0.0343;
  delay(1000);
  lcd.println(dist);
  lcd.setCursor(0 , 1);
  Serial.println(dist);
}
