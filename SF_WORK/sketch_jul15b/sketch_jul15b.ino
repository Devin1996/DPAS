const int IN1 = 6;
const int IN2 = 7;
const int ENA = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(ENA, 75);
  //analogWrite(ENB, 125); 

  digitalWrite(IN1, HIGH);
  delay(5000);
  digitalWrite(IN2, LOW);
  delay(5000);
  digitalWrite(IN2, HIGH);
  delay(5000);
  digitalWrite(IN1, LOW);
  delay(5000);

}
