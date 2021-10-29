/*LED Berkedip
 * menyala selama 1 detik
 * mati selama 1 detik
 */
int pinLED = 12;

void setup() {
  // put your setup code here, to run once:
pinMode (pinLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinLED, HIGH);
delay(1000);
digitalWrite(pinLED, LOW);
delay(1000);
}
