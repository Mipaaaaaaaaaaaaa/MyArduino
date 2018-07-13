int LED = 3;

int i = 0;
int count = 5;

void setup() {
  // put your setup code here, to run once:
  //pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 // if( i >= 150 ){
 // count = -5;
 // }
 //  if( i <= 0 ){
 //   count = 5;
 //  }
 // i = i + count;
 // delay(50);
  analogWrite(LED,analogRead(A0));
}
