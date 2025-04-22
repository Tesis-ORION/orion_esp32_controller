#include <Arduino.h>
#include "MicroROS.h"
#include "servomotor.h"

MicroROS ros_servo ;

void setup() {
    ros_servo.initialize();
    ros_servo.subscriber_define();
    ros_servo.executors_start();
}

void loop() {
    ros_servo.start_receiving_msgs();
}