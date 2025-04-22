#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <ESP32Servo.h>

#define servo_pin 2

class Servomotor{
    public:
        Servomotor();
        void initialize();
        void position(int angle);

};


#endif