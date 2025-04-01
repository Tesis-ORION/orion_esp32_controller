#ifndef MICROROS_H
#define MICROROS_H

#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <nav_msgs/msg/odometry.h>

class MicroROS {
public:
    MicroROS();
    void initialize();
    void executors_start();
    void publish_odometry();
    void start_receiving_msgs();

    rclc_executor_t executor;
    rclc_support_t support;
    rcl_allocator_t allocator;
    rcl_node_t node;

private:
};

#endif