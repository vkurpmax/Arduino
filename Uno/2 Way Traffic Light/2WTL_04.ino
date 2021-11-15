/*
 * Traffic Light [2 Way]
 * I think this is not applicable
 */
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, 1);
  digitalWrite(11, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 1);
    delay(9000);
  digitalWrite(13, 0);
  digitalWrite(12, 1);
  delay(3000);
  digitalWrite(12,0);
  digitalWrite(11, 1);
  digitalWrite(8, 0);
  digitalWrite(10, 1);
  delay(9000);
  digitalWrite(10, 0);
  digitalWrite(9, 1);
  delay(3000);
}
