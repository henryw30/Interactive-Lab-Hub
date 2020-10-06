/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int sensor_pin = A0;    // select the input pin for the potentiometer
int sensor_value = 0;  // variable to store the value coming from the sensor

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  sensor_value = analogRead(sensor_pin) / 10; //divide by 10 for better range of times
}

void loop() {
  sensor_value = analogRead(sensor_pin) / 10; //divide by 10 for better range of times
  
  for (pos = 0; pos <= sensor_value; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos = sensor_value; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}
