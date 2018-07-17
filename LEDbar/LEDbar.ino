

void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);              
  Serial.begin(9600);
}


void loop(){
  int LIGHT = analogRead(0)/127;
  int i;
  Serial.println(LIGHT);
  for( i = 2 ; i - 2 <= LIGHT ; i ++ ){
    digitalWrite( i , HIGH );
  }
  for( i = LIGHT + 2 ; i <= 9 ; i ++ ){
    digitalWrite( i , LOW );
  }

}

