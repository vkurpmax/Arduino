#define pirPin A5
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5*60000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;

void setup() {
   Serial.begin(9600);
   pinMode(pirPin, INPUT);
   pinMode(13, OUTPUT);
   pinMode(A0, OUTPUT);
}

void loop() {
   PIRSensor();
}

void PIRSensor() {
   if(digitalRead(pirPin) == HIGH) {
      if(lockLow) {
         PIRValue = 1;
         lockLow = false;
         Serial.println("Motion detected.");
         digitalWrite(13,HIGH);
         digitalWrite(A0,LOW);
         delay(50);
      }
      takeLowTime = true;
   }
   if(digitalRead(pirPin) == LOW) {
      if(takeLowTime){
         lowIn = millis();takeLowTime = false;
      }
      if(!lockLow && millis() - lowIn > pause) {
         PIRValue = 0;
         lockLow = true;
         Serial.println("Motion ended.");
         digitalWrite(13,LOW);
         digitalWrite(A0,HIGH);
         delay(50);
      }
   }
}
