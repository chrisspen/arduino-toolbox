// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.
//
// On standard servos a parameter value of 1000 is fully counter-clockwise, 2000 is fully clockwise, and 1500 is in the middle. 
//
// Note that some manufactures do not follow this standard very closely so that servos often respond to values between 700 and 2300. 

#define SERVO_RANGE 600
#define SERVO_CENTER 1400
#define SERVO_LOWER SERVO_CENTER - SERVO_RANGE
#define SERVO_UPPER SERVO_CENTER + SERVO_RANGE

#define SERVO_PIN 6

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
	myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
	Serial.begin(57600); // must match ano.ini
}

void loop()
{
	for(pos = SERVO_LOWER; pos < SERVO_UPPER; pos += 1)  // goes from 0 degrees to 180 degrees
	{                                  // in steps of 1 degree
		myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
		Serial.println(pos); Serial.flush();
	}
	for(pos = SERVO_UPPER; pos>=SERVO_LOWER; pos-=1)     // goes from 180 degrees to 0 degrees
	{
		myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
		Serial.println(pos); Serial.flush();
	}
}
