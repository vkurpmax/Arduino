#define OUR_LED 12

void setup() {
  // put your setup code here, to run once:
  pinMode(OUR_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(OUR_LED, HIGH);  //turn on LED
  delay(1000);
  digitalWrite(OUR_LED, LOW);
  delay(1000);
}
