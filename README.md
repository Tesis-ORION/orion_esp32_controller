# orion_esp32_controller
[![language](https://img.shields.io/badge/language-Python3-239120)](#)
[![OS](https://img.shields.io/badge/OS-Ubuntu_24.04-0078D4)](#)
[![CPU](https://img.shields.io/badge/CPU-x86%2C%20x64%2C%20ARM%2C%20ARM64-FF8C00)](#)
[![GitHub release](https://img.shields.io/badge/release-v1.0.9-4493f8)](#)
[![GitHub release date](https://img.shields.io/badge/release_date-february_2025-96981c)](#)
[![GitHub last commit](https://img.shields.io/badge/last_commit-may_2025-96981c)](#)

⭐ Star us on GitHub — it motivates us a lot!

## Table of Contents
- [About](#-about)
- [Demostration](#-demostration)
- [How to Build](#-how-to-build)
- [License](#-license)

## 🚀 About

**orion esp32 controller** is a package for Micro-ROS Jazzy that uses platformio and allow us to control sensors such as Servos, Screen TFT 22 ILI9225, Touch sensors and IMU using Micro-ROS with an ESP-32 and publish the respective topics to ROS2 Jazzy.

## 🎥 Demostration
TODO



## Flash Esp32
This image is for reference to the next steps:

![image](https://github.com/miguelgonrod/OpenCV-microRos-ledController/assets/49737722/1cb9e118-9004-4f53-9843-e682e02711fb)


To flash the esp32 microcontroller with the Micro-Ros code you need to have vsCode with the plugin PlatformIO, first you need to clone the repo and move the orion_esp32_controller to your Micro-Ros/src workspace.
To create your Micro-Ros workspace you can follow the oficial guide: https://micro.ros.org/docs/tutorials/core/first_application_linux/
```
$ git clone https://github.com/Tesis-ORION/orion_esp32_controller -b microROS
$ mv orion_esp32_controller ~/microros_ws/src
$ code src/orion_esp32_controller
```
now you have to plug your esp32 to the computer and give permissions to the /dev/ttyUSB# port or add yourself to dialout group:
```
$ sudo chmod 777 /dev/ttyUSB0
$ sudo usermod -aG dialout $USER
```

If this step gives you errors or it doesn't flash in further steps you can look up for your ttyUSB number using:
```
$ ls /dev/ttyUSB*
```
Next step is to modify your code to make esp32 connect to your network and your computer, in the MicroROS.cpp file you have to change your ip in the line 33 (if you don't know how to get your ip use the next command):
```
$ ifconfig
```
Now change your wifi SSID in line 36 and your wifi password in line 37, remenber to connect you computer to the same network you specified in the code.


Now you have to hold BOOT button (you can see wich button it is in the previous image) while clicking the flas button in vscode (this button only shows up when you have PlatformIO extension installed):

![vscode](https://github.com/miguelgonrod/OpenCV-microRos-ledController/assets/49737722/691014fe-b4bf-4477-9031-df654b96beb3)

If you can see a message that says "[success]" you are ready to go, in any other case create an issue to help you.

Physical connections:
TODO

## Run
To run the microROS-agent and ROS 2 nodes you have to follow this steps.
In your terminal use this commands to run microROS-agent:
```
$ cd microros_ws
$ source install/setup.bash
$ ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888
```

Also if you want to check if the topics are enable you can run in another terminal:
```
$ source /opt/ros/jazzy/setup.bash
$ ros2 topic list
```

## 📃 License

orion_esp32_controller is available under the BSD-3-Clause license. See the LICENSE file for more details.
