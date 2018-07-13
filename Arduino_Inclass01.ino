#define LED 13
#define BUTTON 2

int buttonState = 0;
int LEDState = HIGH;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);

  digitalWrite(LED,LEDState);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED,HIGH);
  //delay(10);
  int reading = digitalRead(BUTTON);
  if( reading != lastButtonState ){
    lastDebounceTime = millis();
  }
  if( (millis() - lastDebounceTime ) > debounceDelay ){
    if( reading != buttonState ){
      buttonState = reading;
      if( buttonState == HIGH ){
        LEDState = !LEDState;
      }
  }
  }
  digitalWrite(LED,LEDState);
  lastButtonState = reading;
}
