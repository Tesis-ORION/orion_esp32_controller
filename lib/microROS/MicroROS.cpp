#include "MicroROS.h"

rcl_subscription_t servo_status_sub;
std_msgs__msg__Int32 angle;

rcl_subscription_t screen_status_sub;
std_msgs__msg__Int32 faces;

rcl_publisher_t touch_pub;
std_msgs__msg__Int32 touch_status;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

Servomotor myservomotor;
Touchsensor mysensor;
Screen myscreen;

int prev = 0;

MicroROS::MicroROS(){
}

void MicroROS::initialize(){
    Serial.begin(115200);
    Serial.println("Servomotor Led node started");
    myservomotor.initialize();
    mysensor.initialize();
    myscreen.initialize();
    myscreen.drawEmotion(0); 

    // Adding Wifi
    IPAddress agent_ip(192, 168, 245, 198); // change this line to your computer IP
    size_t agent_port = 8888; // Don't change this port unless you know what you are doing and you have 8888 port already in use

    char ssid[] = "Miguel"; // change this line with your wifi name
    char psk[]= "Ruta2005*"; // change this line with your password

    set_microros_wifi_transports(ssid, psk, agent_ip, agent_port);
    //set_microros_serial_transports(Serial);  // uncomment this line if you want to use serial instead of wifi

    delay(2000);

    allocator = rcl_get_default_allocator();
    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "servo_status_sub", "", &support);
}


void MicroROS::executors_start(){
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  //rclc_executor_add_subscription(&executor, &servo_status_sub, &angle,&MicroROS::servo_status_callback, ON_NEW_DATA);
  rclc_executor_add_subscription(&executor, &screen_status_sub, &faces,&MicroROS::screen_status_callback, ON_NEW_DATA);

  Serial.println("Executors Started");
}

void MicroROS::servo_subscriber_define(){

    rclc_subscription_init_default(
    &servo_status_sub,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "/servo_angle");

}

void MicroROS::screen_subscriber_define(){

    rclc_subscription_init_default(
    &screen_status_sub,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "/emotion/int");

    Serial.println("Subscriptor a /emotion definido");

}

void MicroROS::touch_publisher_define() {
    rclc_publisher_init_default(
        &touch_pub,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "/touchsensor_status"
    );
}

void MicroROS::servo_status_callback(const void *msg_recv){
    const std_msgs__msg__Int32 * recieved_data = (const std_msgs__msg__Int32 *) msg_recv ;
    int status_received = recieved_data->data;

    Serial.println(status_received);

    if(status_received >= 0 && status_received <= 180) {
        myservomotor.position(status_received);
    }
    else{
        Serial.println("Not valid angle");
    }
}

void MicroROS::screen_status_callback(const void *msg_recv){
    const std_msgs__msg__Int32 * recieved_data = (const std_msgs__msg__Int32 *) msg_recv ;
    int emotion_received = recieved_data->data;

    Serial.println(emotion_received);

    if(prev != emotion_received){
        myscreen.drawEmotion(emotion_received);
        prev = emotion_received;
    }
}

void MicroROS::publish_touch() {
    touch_status.data = mysensor.read();
    rcl_publish(&touch_pub, &touch_status, NULL);
}

void MicroROS::start_receiving_msgs(){
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
    delay(100);
}