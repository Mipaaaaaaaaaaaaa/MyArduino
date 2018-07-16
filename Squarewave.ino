int BUTTON = 2;

int buttonState = 0;
int lastButtonState = LOW;
int flag = -1;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
unsigned long startTime = 0;
unsigned long endTime = 0;
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON,INPUT);
}

void loop() {   
  //Serial.println("Start");
  int reading = digitalRead(BUTTON);

  if( reading != lastButtonState ){
    lastDebounceTime = millis();
  }
  if( (millis() - lastDebounceTime ) > debounceDelay ){
      if( reading != buttonState ){
      buttonState = reading;
      if( buttonState == HIGH ){
       startTime = millis();
       flag = 0;
      }
      if( buttonState == LOW ){
        endTime = millis();
        flag = 1;
      }
      }
  }
  if( flag == 1 ){
    int Time = endTime - startTime;
    Serial.print("Time:");
    Serial.println(Time);
    flag = -1;
  }
  lastButtonState = reading;
}
