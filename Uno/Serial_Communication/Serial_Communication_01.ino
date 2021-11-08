void setup(){
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char a = Serial.read();
    if (a=='a')
    {
      delay(100);
      digitalWrite(4, HIGH);
    }
    else if (a=='A')
    {
      delay(100);
      digitalWrite(4, LOW);
    }
  }
  
  else if (Serial.available())
  {
    char b = Serial.read();
    if (b=='b')
    {
      delay(100);
      digitalWrite(5, HIGH);
    }
    else if (b=='B')
    {
      delay(100);
      digitalWrite(5, LOW);
    }
  }

  else if (Serial.available())
  {
    char c = Serial.read();
    if (c=='c')
    {
      delay(100);
      digitalWrite(6, HIGH);
    }
    else if (c=='C')
    {
      delay(100);
      digitalWrite(6, LOW);
    }
  }

  else if (Serial.available())
  {
    char d = Serial.read();
    if (d=='d')
    {
      delay(100);
      digitalWrite(7, HIGH);
    }
    else if (d=='D')
    {
      delay(100);
      digitalWrite(7, LOW);
    }
  }
}
