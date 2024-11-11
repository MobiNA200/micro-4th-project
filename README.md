# micro-4th-project
# micro-4th-project
## آزمایش شماره 1 : تغییر تدریجی شدت نور
در این آزمایش، LEDبه پایه دیجیتال 9 آردوینو که قابلیت PWM دارد، متصل 
میشود. با استفاده از تابع ```()analogWrite```، میتوانیم سیگنال PWM را به پایه 
متصل به LED اعمال کنیم و شدت نور آن را به تدریج تغییر دهیم. به طوری که هر نیم ثانیه نور به تدریج زیاد و کم میشه.

کد :
```c++
int led = 9;
void setup() {
 pinMode(led, OUTPUT);
}
void loop() {
 for (int i = 0; i < 255; i = i + 5) {
 analogWrite(led, i); 
 delay(50); 
 }
 for (int i = 255; i >= 0; i = i - 5) {
 analogWrite(led, i); 
 delay(50); 
 }
}
```
شماتیک کد :

![shematic](./shematic/photos%20of%20projects/4-1.jpg "Shw=ematic")
