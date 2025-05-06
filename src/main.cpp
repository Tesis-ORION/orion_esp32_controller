#include <Arduino.h>
#include "MicroROS.h"

MicroROS orion_micro ;

void setup() {
    orion_micro.initialize();
    //ros_servo.servo_subscriber_define();
    orion_micro.screen_subscriber_define();
    orion_micro.touch_publisher_define1();
    orion_micro.touch_publisher_define2();
    orion_micro.touch_publisher_define3();
    orion_micro.touch_publisher_define4();
    orion_micro.executors_start();
}

void loop() {
    orion_micro.start_receiving_msgs();
    orion_micro.publish_touch();
}