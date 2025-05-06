#include "touchsensor.h"

Touchsensor::Touchsensor(){};

void Touchsensor::initialize(int pin){
    touch_pin = pin;
    pinMode(touch_pin, INPUT);
}

int Touchsensor::read() 
{                  
    int state = digitalRead(touch_pin);
    if (state == HIGH) {
        return 1;
    }
    else{
        return 0;
    }
}

void Touchsensor::setTouchPin(int pin){
    touch_pin = pin;
}