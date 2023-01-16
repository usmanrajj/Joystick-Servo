/*
Rajj YT 
Full vedio available on Youtube :-
https://youtu.be/689DTKWTTWA

Circuit diagram :-\
https://github.com/usmanrajj/Joystick-Servo
*/

#include <Servo.h>        // Add this Library

Servo servo1;             // 1st Servo name
Servo servo2;             // 2ns Servo name

int xpin = A0;            // Connect RVx pin with Analog Pin A0
int ypin = A1;            // Connect RVy pin with Analog Pin A1
int s1=9;                 // Connect servo1 with digital Pin 9
int s2=11;                // Connect servo2 with digital Pin 11

void setup(){
  Serial.begin(9600);       // Initialize Serial Monitor
  pinMode(xpin,INPUT);      // Rvx-pin act as Input
  pinMode(ypin,INPUT);      // Rvy-pin act as Input
  servo1.attach(s1);        // Servo1 is connected with s1(pin 9)
  servo2.attach(s2);        // Servo2 is connected with s2(pin 11)
}
void loop(){
  int x_axis=analogRead(xpin);        // Store x Coordinates in x_axis variable
  int y_axis=analogRead(ypin);        // Store y Coordinates in y_axis variable
  int angle1=x_axis/5.6;              // convert into angles
  int angle2=y_axis/5.6;              // 1023/5.6 = 180' , 0/5.6 = 0'

// Show Data on Serial Monitor

  Serial.print("X-Axis : ");          // Show These lines on Screen
  Serial.print(x_axis);               
  Serial.print("\tY-Axis : ");
  Serial.print(y_axis);
  Serial.print("\tX-Angle : ");
  Serial.print(angle1);
  Serial.print("\tY-angle : ");
  Serial.println(angle2);

  servo1.write(angle1);           // Write these angles on Servo Motor 1
  servo2.write(angle2);           // Write these angles on Servo Motor 2 
}