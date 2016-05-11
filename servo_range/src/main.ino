// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.


#include <Servo.h>

#define SERVO_PIN 9

Servo myservo;    // create servo object to control a servo
                                // a maximum of eight servo objects can be created

int pos = 0;        // variable to store the servo position

int center = 90;
int range = 30;
int offset = 7;

int upper_endstop = center + range + offset;
int lower_endstop = center - range + offset;

int speed = 30; // ms between step

void setup()
{
    myservo.attach(SERVO_PIN);    // attaches the servo on pin 9 to the servo object
    
    Serial.begin(57600); // must match ino.ini
}


void loop()
{

    Serial.println("Servo moving up...");
    for(pos = center; pos < upper_endstop; pos += 1)
    {
        myservo.write(pos);
        delay(speed);
    }
    
    Serial.println("Servo moving down...");
    for(pos = upper_endstop; pos > lower_endstop; pos-=1)
    {
        myservo.write(pos);
        delay(speed);
    }

    Serial.println("Servo centering...");
    for(pos = lower_endstop; pos < center; pos += 1)
    {
        myservo.write(pos);
        delay(speed);
    }
    
}
