#ifndef TOUCHSENSOR_H
#define TOUCHSENSOR_H

#include <Arduino.h>

class Touchsensor{
    public:
        Touchsensor();
        void initialize(int pin);
        int read();
        void setTouchPin(int pin);

    private:
        int touch_pin = 2;
};


#endif