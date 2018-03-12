
float temp;
int sensorPin = A4;
int ledPin = 2;
    
void setup() {
    Serial.begin(115200);
    pinMode(sensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {

    float moisture = getMoistPercent();
    Serial.print(moisture*100);
    Serial.println("% moisture - Oleander");

    if (moisture < 0.20){
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
    delay(1000);
}

float getMoistPercent() {
    float reading = analogRead(sensorPin);
    float percent = (reading/1023);
    return percent;    
}

