// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
    Serial.begin(57600); // must match ino.ini
}


void loop()
{
    myservo.write(90); // 0-180, center is 90
    
    Serial.println("Servo centered.");
    delay(1000);
}
