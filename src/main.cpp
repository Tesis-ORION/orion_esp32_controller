#include <Arduino.h>
#include "MicroROS.h"

MicroROS micro_ros_node;

void setup() {
    micro_ros_node.initialize();

    micro_ros_node.executors_start();
}

void loop() {
    micro_ros_node.start_receiving_msgs();
}