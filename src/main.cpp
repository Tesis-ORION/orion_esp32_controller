#include <Arduino.h>
#include "MicroROS.h"

MicroROS ros_servo ;

void setup() {
    ros_servo.initialize();
    //ros_servo.servo_subscriber_define();
    ros_servo.screen_subscriber_define();
    //ros_servo.touch_publisher_define();
    ros_servo.executors_start();
}

void loop() {
    ros_servo.start_receiving_msgs();
    //ros_servo.publish_touch();
}