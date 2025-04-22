#include <Arduino.h>
#include "MicroROS.h"
#include "servomotor.h"
#include "screen.h"

MicroROS ros_servo ;
Screen myscreen;

void setup() {
    ros_servo.initialize();
    //ros_servo.servo_subscriber_define();
    //ros_servo.touch_publisher_define();
    ros_servo.executors_start();
    myscreen.initialize();
}

void loop() {
    ros_servo.start_receiving_msgs();
    ros_servo.publish_touch();
    myscreen.display();
}