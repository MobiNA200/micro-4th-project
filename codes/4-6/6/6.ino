#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};
byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {

  lcd.begin(16, 2);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
}
void loop() {
  int sensorReading = analogRead(A0);
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  for (int i = 0; i <= 15; i++) {
    if (i % 2 == 0) {
      lcd.setCursor(i, 0);
      lcd.write(3);
      delay(300);
      lcd.clear();
    } else if (i % 2 != 0) {
      lcd.setCursor(i, 0);
      lcd.write(4);
      delay(300);
      lcd.clear();
    }
  }
  for (int i = 15; i >= 0; i--) {
    if (i % 2 == 0) {
      lcd.setCursor(i, 1);
      lcd.write(4);
      delay(300);
      lcd.clear();
    } else if (i % 2 != 0) {
      lcd.setCursor(i, 1);
      lcd.write(3);

      delay(300);
      lcd.clear();
    }
  }
}