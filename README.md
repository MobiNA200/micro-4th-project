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

## آزمایش شماره 4 : تاس دیجیتال

در این آزمایش، 6 عدد LED به پایه های دیجیتال 0 تا 5 آردوینو متصل می شوند. 
هر LED با استفاده از یک مقاومت به آردوینو متصل می شود تا از آسیب به آن 
2
جلوگیری شود. همچنین یک کلید فشاری به ورودی آنالوگ 0A متصل میشود که 
به عنوان ورودی برای فعالسازی تولید عدد تصادفی استفاده میشود.
هنگامی که کلید فشرده میشود، آردوینو یک LED بین 6 LED روشن میکند و 
سپس مطابق با LED روشن شده، عدد متناظر را در سلایر مانیتور نمایش میدهد.

کد :

```c++
#define key1 digitalRead(A0)
void setup() {
 pinMode(A0, INPUT); 
 for (int i = 0; i <= 5; i++) {
 pinMode(i, OUTPUT); 
 }
 randomSeed(analogRead(A0)); 
 Serial.begin(9600); 
}
void loop() {
 if (key1 == 0) { 
 int random1 = random(1, 7); 
 for (int i = 0; i <= 5; i++) {
 digitalWrite(i, LOW); 
 }
 digitalWrite(random1 - 1, HIGH); 
 Serial.println(random1); 
 delay(1000); 
 }
}
```
شماتیک :

![shematic](./shematic/photos%20of%20projects/4-4.jpg "shematic")

## آزمایش شماره 5 : نمایش متن روی LCD

در این آزمایش، نمایشگر LCD به پین های مشخصی از آردوینو متصل شده است. 
با استفاده از کتابخانه ```LiquidCrystal```، ما میتوانیم کنترل نمایشگر را به سادگی 
بدست بگیریم. در این برنامه، ابتدا LCD را  راه اندازی و سپس پیام های متنی روی آن 
نمایش داده می شود.

کد :

```c++
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
lcd.begin(16, 2);
lcd.clear();
}
void loop() {
lcd.print("MobiNA , Tara");
lcd.setCursor(0, 1);
lcd.print("LCD TutorialMobi");
}
```
شماتیک :

![shematic](./shematic/photos%20of%20projects/4-5%20,%204-6.jpg "shematic")

## آزمایش شماره 6 : آدمک متحرک روی LCD

در این آزمایش، دو کاراکتر سفارشی به نامهای frownie(چهره ناراحت( و
armsDownو armsUpبرای نشان دادن یک کاراکتر با دستهای باال و پایین 
طراحی شدهاند. این کاراکترها به صورت متحرک از سمت چپ به راست و 
بالعکس در نمایشگر LCD حرکت میکنند. سرعت حرکت این کاراکترها به 
ورودی آنالوگ از سنسور متصل به پایه 0A بستگی دارد که با تغییر ولتاژ 
ورودی، سرعت حرکت متغیر میشود.

```c++
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
0b10001};
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
} 
else if (i % 2 != 0) {
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
```

![shematic](./shematic/photos%20of%20projects/4-5%20,%204-6.jpg "shema")

## آزمایش شماره 7 : اندازهگیری فاصله با التراسونیک و نمایش رویLCD

در این آزمایش، سنسور آلتراسونیک 04SR-HC به آردوینو متصل شده است و با 
ارسال پالس صوتی و دریافت آن، زمان رفت و برگشت پالس صوتی را محاسبه 
میکند. این زمان برای محاسبه فاصله جسم استفاده میشود. پس از محاسبه 
فاصله، مقدار آن در سلایر مانیتور و نمایشگر LCD نمایش داده میشود.

کد :

```c++
#include <LiquidCrystal.h>
LiquidCrystal lcd (12 , 11 , 5 , 4 , 3 , 2 );
int tring = 9;
int echo = 10;
int duration ;
int dist;
void setup() {Serial.begin(9600);
pinMode(tring , OUTPUT);
pinMode(echo , INPUT);
lcd.begin(16 , 2);
lcd.clear();}
void loop() {digitalWrite(tring , LOW);
delayMicroseconds(2);
digitalWrite(tring , HIGH);
delayMicroseconds(10);
digitalWrite(tring , LOW);
duration = pulseIn(echo , HIGH);
dist = (duration / 2) * 0.0343;
delay(1000);
lcd.println(dist);
lcd.setCursor(0 , 1);
Serial.println(dist);}
```

شماتیک :

![shematic](./shematic/photos%20of%20projects/4-7.jpg "shema")

## آزمایش شماره 8 : کنترل روشنایی LED بر اساس فاصله

در این آزمایش، از سنسور آلتراسونیک 04SR-HC برای اندازه گیری فاصله 
استفاده میشود. فاصله محاسبه شده از جسم تا سنسور به عنوان ورودی برای
 LEDاستفاده شده است. با نزدیک تر شدن جسم به سنسور، شدت نور LED افزایش 
یافته و با دور شدن جسم، شدت نور کاهش مییابد. این کار با استفاده از تابع 
mapانجام میشود که فاصله اندازهگیری شده را به محدوده مناسب برای کنترل 
شدت نور LED تبدیل میکند.
 کد :
```c++
int tring = 9;
int echo = 10;
int led =11;
int duration ;
int dist;
void setup() {
Serial.begin(9600);
pinMode(tring , OUTPUT);
pinMode(echo , INPUT);}
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
analogWrite(led , m);}
else{
analogWrite(led , LOW);
}
delay(10);
}
```

 شماتیک :
 ![shematic](./shematic/photos%20of%20projects/4-8.jpg "shema")
