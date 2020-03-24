#include <DHT.h>
#include <DHT_U.h>



#include "DHT.h"                       // Include the DHT library.

#define DHTPIN 8                       // Set the DHT Pin.
#define DHTTYPE DHT11                  // Set the DHT type.


DHT dht(DHTPIN, DHTTYPE);              
const int blueLED = 13;  
const int yellowLED = 11; 
const int whiteLED = 12; // Adds a led light (in that case, it is blue) to pin 10.

void setup() {
  Serial.begin(9600);


  pinMode(blueLED, OUTPUT);            // Change to output the blue pin.
  pinMode(yellowLED, OUTPUT);          // Change to output the yellow pin.
  pinMode(whiteLED, OUTPUT);           // Change to output the white pin.

  dht.begin();                         // Launch the DHT11 sensor.
  digitalWrite(blueLED, LOW);          // Turn off LED.
  digitalWrite(yellowLED, LOW);        // Turn off LED.
  digitalWrite(whiteLED, LOW);         // Turn off LED.

  Serial.print("Temperature:");           // Print "Temperature:" on LCD Screen.


  Serial.print("Humidity   :");           // Print "Humidity:" on LCD Screen.
}

void loop() {
  delay(500);                         // Wait 0.5 seconds before updating the values.
  float T = dht.readTemperature();    // Read temperature in Celsius. If you want the Temperature in Fahrenheit, simply add "true" between the parentheses ==> float T = dht.readTemperature(True);
  float H = dht.readHumidity();       // Read humidity in percentage.

  if (isnan(H) && isnan(T)) {         // See if H (the Humidity variable) is NaN (Not A Number) && (Logical AND) See if T (the Temperature variable) is NaN to show error.
    Serial.print("ERROR");               // Print error where there's the error.
    return;                           // Repeat the process with each update (each second).
  }

  if (T > 22) {                       // See if the temperature is bigger than 22C.
    digitalWrite(blueLED, HIGH);    // The yellow led will turn on.

  }
  else if (T < 22) {                  // If the temperature is smaller than 22C.

    digitalWrite(blueLED, LOW);     // The yellow led will turn off.

  }

  else if (T = 22) {                  // If the temperature is equal than 22C.

    digitalWrite(blueLED, LOW);       // The blue led will turn off.
  }


  Serial.print(T);                       // Print the temperature.

  Serial.print(H);                       // Print the humidity level.
}
