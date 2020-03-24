//set pin numbers
//const won't change
const int led1 = 13;
const int led2 = 12;//the number of the LED pin
const int ldrPin = A0;  //the number of the LDR pin


void setup() {

  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);//initialize the LED pin as an output
  pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
}

void loop() {

  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

  //check if the LDR status is <= 300
  //if it is, the LED is HIGH

   if (ldrStatus <=300) {

    digitalWrite(led1, HIGH);               //turn LED on
    Serial.println("LDR is DARK, LED is ON");
    digitalWrite(led2, LOW);
   }
  else {

    digitalWrite(led1, LOW);          //turn LED off
    Serial.println("---------------");
    digitalWrite(led2, HIGH);
  }



  
}
