void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);  //what is connected and where? (LED:OUTPUT, BUTTON:INPUT)
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,INPUT);
}
 
void loop(){
  if (digitalRead(2)==HIGH)    //if button is pushed, do...
    switchToGreen();
  else 
    digitalWrite(12,HIGH);
}

void switchToGreen() {
  digitalWrite(12,HIGH); //LED is on 
  delay (5000);         // Wait 
  digitalWrite(12,LOW); //LED is off
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(5000);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
}

