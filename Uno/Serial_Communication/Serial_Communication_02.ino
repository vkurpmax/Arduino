unsigned int tunda;
int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;

void setup(){
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char c = Serial.read(); //gets one byte from serial buffer
    if (c=='c')
    {
      tunda = tunda + 10;
      Serial.print("delay :");
      Serial.println(tunda);
    }
    else if (c=='C')
    {
      tunda = tunda - 10;
      Serial.print("delay :");
      Serial.println(tunda);
    }
  }
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  delay(tunda);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  delay(tunda);
}
