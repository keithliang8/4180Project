# Four Wheel Bluetooth Car
Final Project for ECE 4180 <br>
By: Matthew Ramberger and Keith Liang <br>
ECE 4180 Section B: Fall 2020 <br>
# Video Demonstration
Youtube Link: https://youtu.be/viqLZLIYhG8
# Project Description
This project creates a bluetooth controlled car where the user can use the Bluefruit Connect app to control the car. The user can control the direction, speed, and can even honk a horn. The user can also input coordinates that the car will go to autonomously.
*   Parts List
    *   1x LPC1768 mbed
    *   2x Dual H-Bridge
    *   1x Adafruit Bluefruit LE UART Friend
    *   1x HC-SR04 Sonar Sensor
    *   4x DC Motor
    *   4x Motor Wheel Attachment
    *   1x Breadboard Mount Speaker
    *   1x Audio Amplifier
    *   1x Breadboard Compatible DC Barrel Jack Adapter
    *   4x AA Batteries
    *   1x Battery Holder
    *   1x Large Breadboard
    *   1x Mini Breadboard
# Pin Connections
## 1st Dual H-Bridge
| H-Bridge Pin      | Connection         |
| ------------- | ------------- |
| GND  | GND  |
| VCC  | Mbed Vout  |
| VM  | Barrel Jack Output  |
| A01  | Motor C Red |
| A02  | Motor C Black  |
| B01  | Motor D Red  |
| B02  | Motor D Black  |
| AI1  | Mbed p11 |
| AI2  | Mbed p12 |
| BI1  | Mbed p9 |
| BI2  | Mbed p10 |
| PWMA | Mbed p23 |
| PWMB | Mbed p24 |
| STBY | 330 ohm to Mbed Vout |

## 2nd Dual H-Bridge
| H-Bridge Pin      | Connection         |
| ------------- | ------------- |
| GND  | GND  |
| VCC  | Mbed Vout  |
| VM  | Barrel Jack Output  |
| A01  | Motor A Red |
| A02  | Motor A Black  |
| B01  | Motor B Red  |
| B02  | Motor B Black  |
| AI1  | Mbed p5 |
| AI2  | Mbed p13 |
| BI1  | Mbed p14 |
| BI2  | Mbed p8 |
| PWMA | Mbed p21 |
| PWMB | Mbed p22 |
| STBY | 330 ohm to Mbed Vout |

## Audio Amplifier
| Audio Amplifier Pin      | Connection         |
| ------------- | ------------- |
| IN+  | Mbed p26  |
| IN-  | GND  |
| OUT+  | Speaker +  |
| OUT-  | Speaker - |
| PWR+  | Mbed Vout  |
| PWR-  | GND  |

## Bluetooth Module 
| Bluetooth Module Pin      | Connection         |
| ------------- | ------------- |
| CTS  | GND  |
| TXO  | Mbed p27  |
| RXI  | Mbed p28  |
| VIN  | Mbed VU |
| GND  | GND  |

## Sonar
| Sonar Pin      | Connection         |
| ------------- | ------------- |
| GND  | GND  |
| ECHO  | Mbed p7  |
| TRIG  | Mbed p6  |
| VCC | Barrel Jack Output |

# Bluefruit Connect Controls
![Pi 4 Pinout](/20201129_200715.jpg) <br>
This control pad lets the user control the car. The up button starts the car going forward at a low speed. Pressing 1 makes the car increase its speed while pressing 2 makes the car decrease its speed. Pressing down makes the robot go backwards at a low speed. The left and right buttons will make the robot turn in the direction pressed. Button 3 will stop the robot in its place. Button 4 is a horn that will make a beep when held down. <br> <br>
![Pi 4 Pinout](/20201129_200729.jpg)
