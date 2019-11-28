//Coded By: Angelo Casimiro (4/27/14)
//Voice Activated Arduino (Bluetooth + Android)
//Feel free to modify it but remember to give credit
#include <SoftwareSerial.h>

SoftwareSerial BT(11, 10); //TX, RX respetively
String voice;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(13, OUTPUT); 

}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 

  if(voice == "*start") 
  {
    digitalWrite(13, HIGH);
  } 
  
  else if(voice == "*stop") 
  {
    digitalWrite(13, LOW);
  }
   

voice="";}} //Reset the variable after initiating
