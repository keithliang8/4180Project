# Four Wheel Bluetooth Car
Final Project for ECE 4180 <br>
By: Matthew Ramberger and Keith Liang <br>
ECE 4180 Section B: Fall 2020 <br>
# Video Demonstration
Youtube Link:
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
| VCC  | Vout  |
| VM  | Barrel Jack Output  |
| A01  | 3rd Motor Red |
| A02  | 3rd Motor Black  |
| B01  | 4th Motor Red  |
| B02  | 4th Motor Black  |
| AI1  | Mbed p11 |
| AI2  | Mbed p12 |
| BI1  | Mbed p9 |
| BI2  | Mbed p10 |
| PWMA | Mbed p23 |
| PWMB | Mbed p24 |
| STBY | 330 ohm to Vout |

## 2nd Dual H-Bridge
| H-Bridge Pin      | Connection         |
| ------------- | ------------- |
| GND  | GND  |
| VCC  | Vout  |
| VM  | Barrel Jack Output  |
| A01  | 1st Motor Red |
| A02  | 1st Motor Black  |
| B01  | 2nd Motor Red  |
| B02  | 2nd Motor Black  |
| AI1  | Mbed p5 |
| AI2  | Mbed p13 |
| BI1  | Mbed p14 |
| BI2  | Mbed p8 |
| PWMA | Mbed p21 |
| PWMB | Mbed p22 |
| STBY | 330 ohm to Vout |
