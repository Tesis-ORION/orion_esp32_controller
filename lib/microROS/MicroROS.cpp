#include "MicroROS.h"
#include <nav_msgs/msg/odometry.h>

rcl_publisher_t odom_pub;
nav_msgs__msg__Odometry odom_msg;

MicroROS::MicroROS(){
}

void MicroROS::initialize(){
    Serial.begin(115200);
    Serial.println("ROS Odom node started");

    // Configuración de Wifi
    IPAddress agent_ip(192, 168, 0, 12); // Cambia esta IP a la IP de tu computadora
    size_t agent_port = 8888; // Puerto para la comunicación

    char ssid[] = "SSID";  // Cambia esto por el nombre de tu red wifi
    char psk[] = "Password";    // Cambia esto por tu contraseña wifi

    //set_microros_wifi_transports(ssid, psk, agent_ip, agent_port);
    set_microros_serial_transports(Serial);  // Descomenta esta línea si prefieres usar puerto serial

    delay(2000);

    allocator = rcl_get_default_allocator();
    rclc_support_init(&support, 0, NULL, &allocator);
    rclc_node_init_default(&node, "odom_publisher_node", "", &support);
}

void MicroROS::executors_start(){
    rclc_executor_init(&executor, &support.context, 1, &allocator);

    Serial.println("Executors Started");

    // Publicador para el mensaje de odometría
    rclc_publisher_init_default(
        &odom_pub,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(nav_msgs, msg, Odometry),
        "/odom"
    );
}

void MicroROS::publish_odometry(){
    // Simulación de valores de odometría
    static float x = 0.0, y = 0.0, z = 0.0;
    static float vx = 0.1, vy = 0.0, vz = 0.0;  // Velocidad en el espacio
    static float roll = 0.0, pitch = 0.0, yaw = 0.0;

    // Llenar el mensaje de odometría
    odom_msg.header.stamp.sec = 0;
    odom_msg.header.stamp.nanosec = 0;
    odom_msg.pose.pose.position.x = x;
    odom_msg.pose.pose.position.y = y;
    odom_msg.pose.pose.position.z = z;
    odom_msg.pose.pose.orientation.x = roll;
    odom_msg.pose.pose.orientation.y = pitch;
    odom_msg.pose.pose.orientation.z = yaw;
    odom_msg.pose.pose.orientation.w = 1.0;
    
    odom_msg.twist.twist.linear.x = vx;
    odom_msg.twist.twist.linear.y = vy;
    odom_msg.twist.twist.linear.z = vz;
    
    // Publicar el mensaje de odometría
    rcl_publish(&odom_pub, &odom_msg, NULL);

    // Actualizar la posición (simulando movimiento)
    x += vx * 0.1;  // Actualización por tiempo
    y += vy * 0.1;
    z += vz * 0.1;
    yaw += 0.05;  // Cambio en la orientación (yaw)

    // Imprimir valores de odometría para monitoreo
    Serial.print("Posición (X, Y, Z): ");
    Serial.print(x); Serial.print(", ");
    Serial.print(y); Serial.print(", ");
    Serial.println(z);
    Serial.print("Velocidad (VX, VY, VZ): ");
    Serial.print(vx); Serial.print(", ");
    Serial.print(vy); Serial.print(", ");
    Serial.println(vz);
}

void MicroROS::start_receiving_msgs(){
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
    delay(100);
    publish_odometry();
}
