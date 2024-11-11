## آزمایش شماره 2 و 3 : کنترل نور LED با پتانسیوم متر و نمایش آن در سریال مانیتور

در این آزمایش، پتانسیومتر به پین 0A آردوینو متصل شده و LED نیز به پین 
دیجیتال 9 وصل شده است. با چرخاندن محور پتانسیومتر، نور LED کم و زیاد 
میشود و مقدار ولتاژ خروجی آن تغییر میکند که در سلایر مانیتور نمایش داده 
میشود.

کد :
```c++
int led = 9;
int val = 0;
void setup() {
pinMode(led, OUTPUT);
Serial.begin(9600);
}
void loop() {
val = analogRead(A0);
analogWrite(led, val / 4);
Serial.println(val * 5 / 1023);
delay(1000);
}
```
شماتیک کد :

![shematic](./shematic/photos%20of%20projects/4-2%20,%204-3.jpg "shema")
