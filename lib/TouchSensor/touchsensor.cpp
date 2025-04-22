#include "touchsensor.h"

Touchsensor::Touchsensor(){};

void Touchsensor::initialize(){
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