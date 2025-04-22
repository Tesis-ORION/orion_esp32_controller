#ifndef MICROROS_H
#define MICROROS_H

#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>

#include "servomotor.h"
#include "touchsensor.h"

class MicroROS {
public:
    MicroROS();
    void initialize();
    void servo_subscriber_define();
    void touch_publisher_define();
    static void servo_status_callback(const void *msg_recv);
    void publish_touch();
    void start_receiving_msgs();
    void executors_start();

private:
};

#endif