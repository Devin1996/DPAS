#define IN1 13
#define IN2 12
#define IN3 11
#define IN4 10

//const int ENA = 9;
//const int ENB = 3;


void setup() {

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  //pinMode (ENA, OUTPUT);
  //pinMode (ENB, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {

  //analogWrite(ENA, 255);
  //analogWrite(ENB, 255); 

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  // put your main code here, to run repeatedly:

}
