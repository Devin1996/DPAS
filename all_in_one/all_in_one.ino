/*NSBM Green University
School of computing
UGC SE 17.1
System Fundemental Group Project
Smart Home power automation system
 
M A DEVIN CHANDULA
K H Gunewardene
Gayan Palliyaguru
T H Wickramesinghe
*/
#include <Servo.h>
String voice;
// light variables 
#define RED 13
#define GREEN 12
#define BLUE 11 
//garrage door variables
#define trigPin 10
#define echoPin 9
//garrage lift elavator variables
const int IN1 = 6;
const int IN2 = 7;
const int ENA = 5;

Servo servo; 
int sound = 250;

void setup() {
  Serial.begin(9600);
 
  //light system setup
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  analogWrite(RED,0); 
  analogWrite(GREEN,0);                   
  analogWrite(BLUE,0);
  
  //garrage dioor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(8);

  //garrage elavator
    pinMode (IN1, OUTPUT);
    pinMode (IN2, OUTPUT);
    pinMode (ENA, OUTPUT);
  
}

  int redVal;
  int greenVal;
  int blueVal;

void loop() {
  analogWrite(ENA, 125);//elavator speed
  //voice system loop begins here
  while (Serial.available())   
  {                            
  delay(10);                   
  char c = Serial.read();      
  if (c == '#') {break;}       
  voice += c;                  
  } 
 
  if (voice.length() > 0) {
    Serial.println(voice); 
 //light system loop begins here
       if(voice == "*red")                                
     {
     analogWrite(RED,255); 
     analogWrite(GREEN,0);
     analogWrite(BLUE,0);
     }  
  else if(voice == "*green")                             
     {
    analogWrite(GREEN,255);
    analogWrite(RED,0);
    analogWrite(BLUE,0);
     }
  else if(voice == "*blue")
     {
    analogWrite(RED,0);
    analogWrite(BLUE,255);
    analogWrite(GREEN,0);
     }
  
  else if(voice == "*light off")
     {
    analogWrite(RED,0);
    analogWrite(GREEN,0);
    analogWrite(BLUE,0);
     }
   else if(voice == "*light on")
     {
    analogWrite(RED,220);
    analogWrite(GREEN,245);
    analogWrite(BLUE,250);
     }
    
      else if(voice == "*fade light") 
     {
 
 
     redVal = 255;  
     blueVal = 0;
     greenVal = 0;
     for(int i = 0; i < 255; i += 1) 
    {
    greenVal += 1;
    redVal -= 1;
    analogWrite(GREEN, 255 - greenVal);
    analogWrite(RED, 255 - redVal);
    delay(10);
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for(int i = 0; i < 255; i += 1)
  {
    blueVal += 1;
    greenVal -= 1;
    analogWrite(BLUE, 255 - blueVal);
    analogWrite(GREEN, 255 - greenVal);
    delay(10);
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1)
  {
    redVal += 1;
    blueVal -= 1;
    analogWrite(RED, 255 - redVal);
    analogWrite(BLUE, 255 - blueVal);
    delay(10);
  }
       
   
     
       }
       //light system ends here
       //garrage elavator loop starts here
    else if(voice == "*lift up")                                
     {
  digitalWrite(IN1, HIGH);
  delay(5000);
  digitalWrite(IN2, LOW);
  delay(5000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
     }  
  else if(voice == "*lift down")                             
     {
      
  digitalWrite(IN2, HIGH);
  delay(5000);
  digitalWrite(IN1, LOW);
  delay(5000);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
     }
     //garrage elavator loop starts here
  }



   
voice="";  

//garrage door loop begins here
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 8) {
Serial.println("the distance is less than 60");
servo.write(0);
delay(7000);
}
else {
servo.write(90);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(500);                                                     
//garrage loop ends here

}


