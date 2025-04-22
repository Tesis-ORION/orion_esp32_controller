#include "servomotor.h"
  
Servo myservo;

Servomotor::Servomotor(){};

void Servomotor::initialize(){
  myservo.attach(servo_pin);   
}

void Servomotor::position(int angle) 
{                  
  myservo.write(angle);
  Serial.print("writting angle: ");
  Serial.println(angle);
}