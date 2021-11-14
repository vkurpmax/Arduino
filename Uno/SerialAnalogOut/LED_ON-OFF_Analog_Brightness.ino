const int analogOutPin = 5; //Use PWM Pin
int outpunValue = 0;
int pos = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  for (pos = 0; pos <= 255; pos += 1) {
    analogWrite(analogOutPin, pos);
    Serial.print("output = ");
    Serial.println(pos);
    delay(50);
  }
  for (pos = 255; pos >= 0; pos -= 1) {
    analogWrite(analogOutPin, pos);
    Serial.print("output = ");
    Serial.println(pos);
    delay(50);
  }
}
