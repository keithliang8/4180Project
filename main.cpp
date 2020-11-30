#include "mbed.h"
//#include "wave_player.h"
//#include "SDFileSystem.h"
#include "Motor.h"
#include "rtos.h"
//#include "RGBLed.h"
#include "ultrasonic.h"
#include "Speaker.h"
Speaker speak(p26); //Speaker
Serial blue(p28,p27); //Bluetooth Module
Motor A(p21, p5, p13); // pwm, fwd, rev, can brake Back Left
Motor B(p22, p14, p8); // pwm, fwd, rev, can brake Back Right
Motor C(p23, p11, p12); // pwm, fwd, rev, can brake Front Right
Motor D(p24, p9, p10); // pwm, fwd, rev, can brake Front Left
DigitalOut myled(LED2);
//AnalogOut DACout(p18);
//wave_player waver(&DACout);
float RmotorSpeed = 0.0;
float LmotorSpeed = 0.0;

int triggerDist = 300;

void dist(int distance)
{
    if(distance <= triggerDist) {
        RmotorSpeed = 0.0;
        LmotorSpeed = 0.0;
        A.speed(LmotorSpeed);
        B.speed(RmotorSpeed);
        C.speed(RmotorSpeed);
        D.speed(LmotorSpeed);
        speak.PlayNote(500.0, 2, 0.2);
    }
}
ultrasonic mu(p6, p7, .1, 1, &dist);

void startSonar(void const* argument){
    mu.startUpdates();
    while(1) {
        mu.checkDistance();
        Thread::wait(50);
    }
}

void turnRight(){
    A.speed(0.5);
    B.speed(-0.5);
    C.speed(-0.5);
    D.speed(0.5);
    wait(1.05);
    A.speed(0);
    B.speed(0);
    C.speed(0);
    D.speed(0);
}
void turnLeft(){
    A.speed(-0.5);
    B.speed(0.5);
    C.speed(0.5);
    D.speed(-0.5);
    wait(1.2);
    A.speed(0);
    B.speed(0);
    C.speed(0);
    D.speed(0);
}

int main()
{
    Thread thread1(startSonar);

    char bnum = 0;
    char bhit = 0;
    while(1) 
    {

        A.speed(LmotorSpeed);
        B.speed(RmotorSpeed);
        C.speed(RmotorSpeed);
        D.speed(LmotorSpeed);
        
        if (blue.getc() == '!') {
            char cmd = blue.getc();
            if (cmd == 'B') { //button data packet
                bnum = blue.getc(); //button number
                bhit = blue.getc(); //1=hit, 0=release
                if (blue.getc() == char(~('!' + 'B' + bnum + bhit))) { //checksum OK?
                    switch (bnum) {
                        case '1': //number button 1
                            if (bhit=='1') {
                                //add hit code here
                                RmotorSpeed += 0.2;
                                LmotorSpeed += 0.2; // speed up
                            } else {
                                //add release code here
                            }
                            break;
                        case '2': //number button 2
                            if (bhit=='1') {
                                //add hit code here
                            } else {
                                //add release code here
                                LmotorSpeed -= 0.2; 
                                RmotorSpeed -= 0.2;// slow down
                            }
                            break;
                        case '3': //number button 3
                            if (bhit=='1') {
                                //add hit code here
                            } else {
                                //add release code here
                                LmotorSpeed = 0.0;
                                RmotorSpeed = 0.0;
                            }
                            break;
                        case '4': //number button 4
                            if (bhit=='1') {
                                speak.PlayNote(969.0, .2, 0.2);
                            } else {
                                //add release code here
                                
                            }
                            break;
                        case '5': //button 5 up arrow
                            if (bhit=='1') {
                                if(LmotorSpeed > 0 && RmotorSpeed > 0) {
                                }
                                else if(LmotorSpeed <= 0 && RmotorSpeed <= 0) {
                                    LmotorSpeed = 0.4;
                                    RmotorSpeed = 0.4;
                                }
                            } else {
                                //add release code here
                            }
                            break;
                        case '6': //button 6 down arrow
                            if (bhit=='1') {
                                if(LmotorSpeed < 0 && RmotorSpeed < 0) {
                                
                                }
                                else if(LmotorSpeed >= 0 && RmotorSpeed >= 0) {
                                    LmotorSpeed = -0.4;
                                    RmotorSpeed = -0.4;
                                }
                            } else {
                                //add release code here
                            }
                            break;
                        case '7': //button 7 left arrow
                            if (bhit=='1') {
                                LmotorSpeed = 0.25*RmotorSpeed;
                            } else {
                                //add release code here
                            }
                            break;
                        case '8': //button 8 right arrow
                            if (bhit=='1') {
                                RmotorSpeed = 0.25*LmotorSpeed;
                            } else {
                                //add release code here
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
            else if (cmd == 'X') {
                char first = blue.getc();
                char second = blue.getc();
                char comma = blue.getc();
                char third = blue.getc();
                char fourth = blue.getc();
                int secondnum = second - '0';
                float xdist = secondnum * .75;
                int fourthnum = fourth - '0';
                float ydist = fourthnum * .75;
                if(third == '+'){
                    A.speed(0.5);
                    B.speed(0.5);
                    C.speed(0.5);
                    D.speed(0.5);
                    wait(ydist);
                    A.speed(0);
                    B.speed(0);
                    C.speed(0);
                    D.speed(0);
                }
                else if(third == '-'){
                    A.speed(-0.5);
                    B.speed(-0.5);
                    C.speed(-0.5);
                    D.speed(-0.5);
                    wait(ydist);
                    A.speed(0);
                    B.speed(0);
                    C.speed(0);
                    D.speed(0);
                }
                if(first == '+'){
                    turnRight();
                    A.speed(0.5);
                    B.speed(0.5);
                    C.speed(0.5);
                    D.speed(0.5);
                    wait(xdist);
                    A.speed(0);
                    B.speed(0);
                    C.speed(0);
                    D.speed(0);
                     }
                else if(first == '-'){
                    turnLeft();
                    A.speed(0.5);
                    B.speed(0.5);
                    C.speed(0.5);
                    D.speed(0.5);
                    wait(xdist);
                    A.speed(0);
                    B.speed(0);
                    C.speed(0);
                    D.speed(0); }
                
            }
        }
    }
}