
#include "DHT.h"
#include "DHT_U.h"

int sen = 3;
float temp;
float hum;

DHT dht
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    Serial.print("Temparature is: ");
    Serial.print(temp);
    Serial.print("Humidity is: ");
    Serial.print(hum);
    delay(500);
}
