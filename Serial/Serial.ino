#include<SoftwareSerial.h>
#include<MsTimer2.h>
SoftwareSerial mySerial(A2,A3);
//设置阴极接口
int a = 13;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int p = 8;
//设置阳极接口
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;
int i = 1;
int j = 1;
//设置变量
int del = 100;  //此处数值对时钟进行微调
static double volt;
static int Number = 0;
static int digit[4] = {0};
static int Nowdigit = 1;
byte segs[7] = { a, b, c, d, e, f, g };
byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,0,1,0,0 }   // = 9
                             };

                        
void lightSegments(int x);
void clearLEDs();
void dispDec(int x);
void pickDigit(int x);

void flash(){
    if( mySerial.available() ){
    volt = (double)(mySerial.read()/51.0);
    Number = volt * 1000;
    Serial.print("Number: ");
    Serial.println(Number);
   // mySerial.println("hello");
    digit[1] = Number/1000%10;
    digit[2] = Number/100%10;
    digit[3] = Number/10%10;
    digit[4] = Number%10;

  //    int Start = millis();
  //    delayMicroseconds(20);
  //    Serial.println(millis()-Start);
    for( j = 0 ; j < 80 ; j ++ ){
      display_drive(); 
    }
    }
    else {
      Serial.println("UNAVAILABLE!");
    }
}

void display_drive(){
  switch(Nowdigit){
    case 1:    clearLEDs();
               pickDigit(1);
               lightSegments(digit[1]);
               dispDec(0);
               delayMicroseconds(del);
               break;
    case 2:    clearLEDs();
               pickDigit(2);
               lightSegments(digit[2]);
               delayMicroseconds(del);
               break;
    case 3:    clearLEDs();
               pickDigit(3);
               lightSegments(digit[3]);
               delayMicroseconds(del);
               break;
    case 4:    clearLEDs();
               pickDigit(4);
               lightSegments(digit[4]);
               delayMicroseconds(del);
               break;
  }
  Nowdigit++;
  if( Nowdigit == 5 ){
    Nowdigit = 1;
  }
}

void setup()
{
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
  mySerial.begin(4800);
  MsTimer2::set(20,flash);
  MsTimer2::start();
}

void loop()
{
}

void pickDigit(int x)  //定义pickDigit(x),其作用是开启dx端口
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  switch(x)
  {
  case 1:
    digitalWrite(d1, HIGH);
    break;
  case 2:
    digitalWrite(d2, HIGH);
    break;
  case 3:
    digitalWrite(d3, HIGH);
    break;
  default:
    digitalWrite(d4, HIGH);
    break;
  }
}

void dispDec(int x)  //设定开启小数点
{
  digitalWrite(p, LOW);
}

void clearLEDs()  //清屏
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

// 点亮对应数字的数码管
void lightSegments(int x) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segs[i], seven_seg_digits[x][i]);
  }
}
