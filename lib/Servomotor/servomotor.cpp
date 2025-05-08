#include "servomotor.h"
  
Servo myservo;

Servomotor::Servomotor(){};

void Servomotor::initialize(){
  myservo.attach(servo_pin);   
}

void Servomotor::position(int targetAngle) 
{
  int currentAngle = myservo.read();
  int step = (targetAngle > currentAngle) ? 1 : -1;

  Serial.print("writting angle: ");
  Serial.println(targetAngle);

  while (currentAngle != targetAngle) {
    currentAngle += step;
    myservo.write(currentAngle);
    delay(10);
  }
}
