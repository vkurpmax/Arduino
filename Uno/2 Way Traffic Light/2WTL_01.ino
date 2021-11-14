/*Not applicable
  
  Created by Vkurpmax
  as an assignment for Microcontroller S5
  1st November 2021
*/

int M1 = 1;     int M2 = 4;
int K1 = 2;     int K2 = 5;
int H1 = 3;     int H2 = 6;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(M1, OUTPUT);
  pinMode(K1, OUTPUT);
  pinMode(H1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(H2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(M1, HIGH);         digitalWrite(H2, HIGH);
  delay(2000);
  
  digitalWrite(M1, LOW);          digitalWrite(H2, LOW);
  digitalWrite(K1, HIGH);         digitalWrite(K2, HIGH);
  delay(500);

  digitalWrite(K1, LOW);          digitalWrite(K2, LOW);
  digitalWrite(H1, HIGH);         digitalWrite(M2, HIGH);
  delay(2000); 
  
  digitalWrite(H1, LOW);          digitalWrite(M2, LOW); 
  digitalWrite(K1, HIGH);         digitalWrite(K2, HIGH);
  delay(500);
  digitalWrite(K1, LOW);          digitalWrite(K2, LOW);
}
