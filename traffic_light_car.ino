include <Time.h>

time_t deadline;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,INPUT);
  deadline = millis()+10000;
  digitalWrite(12,HIGH);
}
 
void loop(){
  if (button_pressed()) {
    if (deadline-millis()>5000) {
      deadline = millis()+5000;
    }
  }
  else {
    if (deadline <=millis()) {
      switchToGreen();
      deadline = millis()+10000;
    }
  } 
}

void switchToGreen() {
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(5000);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}



bool button_pressed(){
  return digitalRead(2) == HIGH; 
}
