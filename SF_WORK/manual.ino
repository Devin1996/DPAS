#include <Servo.h>
#define trigPin 10
#define echoPin 9
Servo servo;
int sound = 250;

int light=13;
int fan=12;
int door=11;
int lift=10;

int Received=0;
int light_state =0;
int fan_state = 0;
int door_state = 0;
int lift_state = 0;


void setup(){
  
  Serial.begin(9600);
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(door,OUTPUT);
  pinMode(lift,OUTPUT);
  
}

void loop(){
 
 if(Serial.available()>0)
 { 
    Received = Serial.read();
    
 }
////////////////LIGHT/////////////////////
if (light_state == 0 && Received == '1')
  {
    digitalWrite(light,HIGH);
    light_state=1;
    Received=0;  
  }
if (light_state ==1 && Received == '1')
  {
    digitalWrite(light,LOW);
    light_state=0;
    Received=0;
  }
///////////////////////////////////////////



////////////////fan/////////////////////
if (vent_state == 0 && Received == '2')
  {
    digitalWrite(fan,HIGH);
    fan_state=1;
    Received=0;  
  }
if (vent_state ==1 && Received == '2')
  {
    digitalWrite(fan,LOW);
    fan_state=0;
    Received=0;
  }
///////////////////////////////////////////




////////////////door/////////////////////
if (pc_state == 0 && Received == '3')
  {
    digitalWrite(pc,HIGH);
    pc_state=1;
    Received=0;  
  }
if (pc_state ==1 && Received == '3')
  {
    digitalWrite(pc,LOW);
    pc_state=0;
    Received=0;
  }
///////////////////////////////////////////




  
////////////////Lift/////////////////////
 if (Received =='4'){
   digitalWrite(lift,HIGH);   
  }  
 if (Received == '4'){
 digitalWrite(lift,LOW);
 }
 ///////////////////////////////////////////

 
 
}
