#define RELAY_1 3
#define RELAY_2 6
#define RELAY_3 9
#define PIRpin_1 2
#define PIRpin_2 5
#define PIRpin_3 8

 
void setup() {
  pinMode(PIRpin_1, INPUT);
  pinMode(PIRpin_2, INPUT);
  pinMode(PIRpin_3, INPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
}
void loop() {
      if (digitalRead(PIRpin_1) == LOW) {
        digitalWrite(RELAY_1, HIGH);
      }
      if (digitalRead(PIRpin_1) == HIGH) {
        digitalWrite(RELAY_1, LOW);
      }
      if (digitalRead(PIRpin_2) == LOW) {
        digitalWrite(RELAY_2, HIGH);
      }
      if (digitalRead(PIRpin_2) == HIGH) {
        digitalWrite(RELAY_2, LOW);
      }
      if (digitalRead(PIRpin_3) == HIGH) {
        digitalWrite(RELAY_3, HIGH);
      }
      if (digitalRead(PIRpin_3) == LOW) {
        digitalWrite(RELAY_3, LOW);
      }
} 
