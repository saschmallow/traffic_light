#include <Time.h>

time_t deadline;
boolean is_light_on;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,INPUT);
  deadline = millis()+500;
  digitalWrite(11,LOW);
  is_light_on = false;
  Serial.begin(9600);
}
 
void loop(){
  if (millis() > deadline) {
    if (is_light_on) {
      Serial.println("TO OFF");
      digitalWrite(11,LOW);
      deadline = millis()+500;
      is_light_on = false;
    } else {
      Serial.println("TO ON");
      digitalWrite(11,HIGH);
      deadline = millis()+500;
      is_light_on = true;
    }
  }
}

void old_loop(){
    if (button_pressed()) {                // when the button is pressed, check the time that's left. If it's more than 5s, set the deadline to 5s.   
    if (deadline-millis()>5000) {        // otherwise the deadline remains unchanged
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
