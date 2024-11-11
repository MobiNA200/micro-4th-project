int ledpin = 9;
int val = 0;
void setup() {
  pinMode(ledpin , OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  analogWrite(ledpin, val / 4);
  Serial.print(val);
}