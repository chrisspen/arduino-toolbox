int led = 13;
int power = 12;

void setup(){
    
    Serial.begin(57600); // must match ino.ini

    pinMode(led, OUTPUT);
    
    // set power pin low to disconnect EN from ground, keeping us on.
    pinMode(power, OUTPUT);
    digitalWrite(power, LOW);
}

void loop(){
    for(int i=5; i>0; i-=1){
        Serial.println(((String)"Countdown: ") + i);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
    
    // Setting power high activates EN transistor, shorting EN to GND, turning us off.
    Serial.println(((String)"Shutting down..."));
    digitalWrite(power, HIGH);
    Serial.println(((String)"Shut down!"));
}
