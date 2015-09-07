/*
2015-8-8 CKS

*/

#define DETECT_PIN A4

//4.8*1023/5.0
//#define LOW_THRESHOLD 982 // too high
//#define LOW_THRESHOLD 500 // too low, doesn't register plug-in

// Use two threshold to handle hysteresis.
// When unplugged, Vcc is 5V.
// When plugged in, Vcc is 4.6-4.7V.
#define LOW_THRESHOLD 941 // 4.6V
//#define HIGH_THRESHOLD 1002 // 4.9V
#define HIGH_THRESHOLD 961 // 4.7V

int mode = 1; // start state
unsigned long start, finished, elapsed;
int val = 0;

void setup()
{

    // Start serial connection.
    // Note, this baudrate needs to match the setting ino.ini.
    Serial.begin(57600);//works!

    pinMode(DETECT_PIN, INPUT);
    
}

void loop()
{
    // It takes about 100 microseconds (0.0001 s) to read an analog input,
    // so the maximum reading rate is about 10,000 times a second. 
    val = analogRead(DETECT_PIN);
    //Serial.println(val);
    
    if(mode == 1){
        // Waiting for drop from high to low.
        if(val <= LOW_THRESHOLD){
            start = millis();
            mode = 2;
            Serial.println("Went low.");
        }
    }else if(mode == 2){
        // Waiting for rise from low to high.
        if(val >= HIGH_THRESHOLD){
            finished = millis();
            mode = 3;
            Serial.println("Went high.");
        }
    }else if(mode == 3){
        // Done display time.
        elapsed = finished - start;
        Serial.println(((String)"elapsed(ms): ") + elapsed);
        mode = 1;
    }else{
        delay(1000);
    }
}
