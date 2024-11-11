int tring = 9;
int echo = 10;
int led =11;
int duration ;
int dist;
void setup() {
  Serial.begin(9600);
  pinMode(tring , OUTPUT);
  pinMode(echo , INPUT);
}
void loop() {
  digitalWrite(tring , LOW);
  delayMicroseconds(2);
  digitalWrite(tring , HIGH);
  delayMicroseconds(10);
  digitalWrite(tring , LOW);
  duration = pulseIn(echo , HIGH);
  dist = (duration / 2) * 0.0343;
  Serial.println(dist);

  if (dist <= 30){
    int m = map(dist , 30 , 4 , 0 , 255);
    analogWrite(led , m);
  }
  else{
    analogWrite(led , LOW);
  }
  delay(10);
}
