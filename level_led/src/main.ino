
#define INPUT_PIN A0
#define LED_PIN 13

bool sensorValue = false;  // variable to store the value coming from the sensor

void setup() {

    // start serial connection
    Serial.begin(57600); // must match ano.ini
    
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, sensorValue);
    
    // set pullup on analog pin 0
    // Because the signal pin is wired to ground, we need to enable the pullup resistor to form a voltage divider.
    pinMode(INPUT_PIN, INPUT);
    digitalWrite(INPUT_PIN, HIGH);

}

void loop() {

    // read the value from the sensor:
    sensorValue = !digitalRead(INPUT_PIN);
    //Serial.println(sensorValue);
  
    digitalWrite(LED_PIN, sensorValue);
    
    //delay(1000);
}
