#ifndef TOUCHSENSOR_H
#define TOUCHSENSOR_H

#include <Arduino.h>

#define touch_pin 15

class Touchsensor{
    public:
        Touchsensor();
        void initialize();
        int read();

};


#endif