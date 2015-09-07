/*
2015.8.31 CKS
Tests reading data from a HC-SR501 PIR sensor.

http://robotic-controls.com/learn/sensors/pir-sensor-hc-sr501
https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/
*/

#define DETECT_PIN 8

int val;

void setup() {

    pinMode(DETECT_PIN, INPUT);
    
    Serial.begin(57600); // must match ino.ini
}

void loop() {
    
    val = digitalRead(DETECT_PIN); //read state of the PIR
  
    if (val == LOW) {
        Serial.println("No motion"); //if the value read is low, there was no motion
    }
    else {
        Serial.println("Motion!"); //if the value read was high, there was motion
    }
    
  
    //Serial.println("Hello World!");
    delay(1000);
}
