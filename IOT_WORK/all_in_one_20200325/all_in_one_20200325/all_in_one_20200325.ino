/*Devin Chandula*/
#include "dht.h"

#define dht_apin A0

dht DHT;

String voice;

const int singleVoiceLED = 13;
const int fanTestLED = 12;


void setup() {
  Serial.begin(9600);
  //Delay to let system boot
  delay(500);
  
  pinMode (singleVoiceLED, OUTPUT);
  pinMode(fanTestLED, OUTPUT);

  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

  digitalWrite(fanTestLED, LOW);
  digitalWrite(singleVoiceLED, LOW);

}

void loop() {

  SingleLightVoiceControl();
  TempConreolledFan();
  

}

//voice controlled single light

void SingleLightVoiceControl() {
  while (Serial.available())
  {
    delay(10);
    char c = Serial.read();
    if (c == '#') {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);

    if (voice == "*light on")
    {
      digitalWrite(singleVoiceLED, HIGH);

    }
    else if (voice == "*light off")
    {

      digitalWrite(singleVoiceLED, LOW);
      

    }
  }
  voice = "";
}

//turn on the fan when temp is high
void TempConreolledFan(){
    
  DHT.read11(dht_apin);

  float temp = DHT.temperature;
  float humidity = DHT.humidity;
 
  if (temp > 34.00) {  
    digitalWrite(fanTestLED, HIGH);   

  }
  else if (temp = 32.00) {
    digitalWrite(fanTestLED, LOW);
    }
  else if (temp < 32.00) {     
    digitalWrite(fanTestLED, LOW);

  }
  Serial.print("Current humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(temp);
  Serial.println("C  ");

  delay(2500);//Wait 2.5 seconds before accessing sensor again.

  }
