#define key1 digitalRead(A0)
void setup() {
  // put your setup code here, to run once:
pinMode(A0 , INPUT);
for(int i = 0 ; i <= 5 ; i ++){
  pinMode(i , OUTPUT);
}
randomSeed(analogRead(A0));
Serial.begin(9600);
}

void loop() {
  if(key1 == 0){
    int random1 = random(1 , 7);
    for(int i = 0 ; i <= 5 ; i++){
      digitalWrite (i ,  LOW);
    }
    digitalWrite(random1 - 1 , HIGH);
    Serial.println(random1);
    delay(1000);
  }
}
