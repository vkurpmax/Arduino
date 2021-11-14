/*Created by Vkurpmax
  as an assignment for Microcontroller S5 (UTS)
  1st November 2021
  This is a simple concept of 2 way traffic light.
*/

int M1 = 2;    int M2 = 5;
int K1 = 3;    int K2 = 6;
int H1 = 4;    int H2 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(K1, OUTPUT);
  pinMode(H1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(H2, OUTPUT);
}

void loop() {
  digitalWrite(M1, 1);  digitalWrite(H2, 1);
  delay(3000);  
                        digitalWrite(H2, 0);
                        digitalWrite(K2, 1);
  delay(1000);          
                        digitalWrite(K2, 0);
                        digitalWrite(M2, 1);
  delay(1000);
  digitalWrite(M1, 0);
  digitalWrite(H1, 1);
  delay(3000);
  digitalWrite(H1, 0);
  digitalWrite(K1, 1);
  delay(1000);
  digitalWrite(K1, 0);                  
  digitalWrite(M1, 1);
  delay(1000);
                        digitalWrite(M2, 0);
}
