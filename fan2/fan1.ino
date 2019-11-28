

#include <DHT.h>
#include <DHT_U.h>

int sen = 3;
int temp;
int hum;

DHT dht(sen, DHT22);
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
    temp = dht.readTemperature();
    hum = dht.readHumidity();
    Serial.print("\nTemparature is: \n");
    Serial.print(temp);
    Serial.print("\nHumidity is: \n");
    Serial.print(hum);
    delay(500);
}
