#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to

dht DHT;

int testLED = 13;

void setup() {

  Serial.begin(9600);
  delay(500);//Delay to let system boot

  pinMode(testLED, OUTPUT);

  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

  digitalWrite(testLED, LOW);
}

void loop() {
  //Start of Program

  DHT.read11(dht_apin);

  float temperature = DHT.temperature;
  if (temperature > 32.00) {  
    digitalWrite(testLED, HIGH);   

  }
  else if (temperature = 32.00) {
    digitalWrite(testLED, LOW);
    }
  else if (temperature < 32.00) {     
    digitalWrite(testLED, LOW);

  }
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(temperature);
  Serial.println("C  ");

  delay(5000);//Wait 5 seconds before accessing sensor again.

  //Fastest should be once every two seconds.

}// end loop()
