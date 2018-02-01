int TRESH = 250;
void SetSpeed(int Speed)
{
  analogWrite(9, Speed);
  analogWrite(10, Speed);
}
void moveBackward()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void moveForward()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void arcRight()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
void spotRight()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void arcLeft()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void spotLeft()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void Stop()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  SetSpeed(125);
  Serial.begin(115200);
}

void loop()
{

  int L2 = analogRead(A5);
  int L1 = analogRead(A4);
  int C = analogRead(A3);
  int R1 = analogRead(A2);
  int R2 = analogRead(A1);

  Serial.println();
  Serial.print(L2);
  Serial.print("\t");
  Serial.print(L1);
  Serial.print("\t");
  Serial.print(C);
  Serial.print("\t");
  Serial.print(R1);
  Serial.print("\t");
  Serial.println(R2);


  if (L2 < TRESH && L1 < TRESH && C > TRESH && R1 < TRESH && R2 < TRESH)    //only center if high
  {
    moveForward();
    Serial.print(" moveForward");
  }
   if (L2 < TRESH && L1 > TRESH && C > TRESH && R1 > TRESH && R2 < TRESH)    //C,R1,L1 is high
  {
    moveForward();
    Serial.print(" moveForward");
  }
  else if ( L2 < TRESH && L1 < TRESH && C < TRESH && R1 > TRESH && R2 < TRESH )  // R1 is high
  {
    arcRight();
    Serial.print("moveRight");
  }
  else if ( L2 < TRESH && L1 > TRESH && C < TRESH && R1 < TRESH && R2 < TRESH )   //L1 is high
  {
    arcLeft();
    Serial.print("moveLeft");
  }
  else if ( L2 > TRESH && L1 < TRESH && C < TRESH && R1 < TRESH && R2 < TRESH )   //L2 is only high
  {
    spotLeft();
    Serial.print("moveLeft");
  }
  else if ( L2 < TRESH && L1 < TRESH && C < TRESH && R1 < TRESH && R2 > TRESH)   // R2 is only high
  {
    spotRight();
    Serial.print("moveRIGHT");
  }
  else if ( L2 > TRESH && L1 > TRESH && C > TRESH && R1 < TRESH && R2 < TRESH ) // L2,L1,C is high
  {
    spotLeft();
    Serial.print("moveLeft");
  }
  else if ( L2 < TRESH && L1 < TRESH && C > TRESH && R1 >TRESH && R2 > TRESH ) // R2,R1,C is high
  {
    spotRight();
    Serial.print("moveLeft");
  }
  else if ( L2 > TRESH && L1 > TRESH && C < TRESH && R1 < TRESH && R2 < TRESH )   //L2,L1 is high
  {
    spotLeft();
    Serial.print("moveLeft");
  }
  else if ( L2 < TRESH && L1 < TRESH && C < TRESH && R1 > TRESH && R2 > TRESH )   // R1 and R2 is high
  {
    spotRight();
    Serial.print("moveRIGHT");
  }
  else if ( L2 > TRESH && L1 > TRESH && C > TRESH && R1 > TRESH && R2 > TRESH )  // all are high
  {
     Stop();
     delay(500);
//    moveForward();
//    delay(500);
//    Serial.print("Stop");
  }
  else
  {
    arcRight();
    Serial.print("moveRIGHT");
  }
  delay(10);

}

