/* Created by Ralph Nader on 1/10/19.
   Copyright  2019 Ralph Nader. All rights reserved.
   Made with  for everyone.
   Spread your knowledge.
   If you have any error or question, email me at "ralph@driple.co".
*/
#include <LiquidCrystal.h>             // Include the LiquidCrystal library.
#include "DHT.h"                       // Include the DHT library.

#define DHTPIN 8                       // Set the DHT Pin.
#define DHTTYPE DHT11                  // Set the DHT type.

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);   // Creates a LiquidCrystal object. Parameters: (RS, Enable (E), d4, d5, d6, d7).
DHT dht(DHTPIN, DHTTYPE);              // Creates a DHT object. Parameters: (DHT Pin, DHT Type).

const int yellowLED = 9;               // Adds a led light (in that case, it is yellow) to pin 9.
const int blueLED = 10;                // Adds a led light (in that case, it is blue) to pin 10.
const int whiteLED = 11;               // Adds a led light (in that case, it is white) to pin 11.

void setup() {
  lcd.begin(16, 2);                    // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display.
  lcd.setCursor(0, 0);                 // Set the cursor to column 0, line 0.
  pinMode(blueLED, OUTPUT);            // Change to output the blue pin.
  pinMode(yellowLED, OUTPUT);          // Change to output the yellow pin.
  pinMode(whiteLED, OUTPUT);           // Change to output the white pin.

  dht.begin();                         // Launch the DHT11 sensor.
  digitalWrite(blueLED,LOW);           // Turn off LED.
  digitalWrite(yellowLED,LOW);         // Turn off LED.
  digitalWrite(whiteLED, LOW);         // Turn off LED.

  lcd.print("Temperature:");           // Print "Temperature:" on LCD Screen.
  
  lcd.setCursor(0, 1);                 // Set the cursor to column 0, line 1.
  lcd.print("Humidity   :");           // Print "Humidity:" on LCD Screen.
}

void loop() {
  delay(500);                         // Wait 0.5 seconds before updating the values.
  float T = dht.readTemperature();    // Read temperature in Celsius. If you want the Temperature in Fahrenheit, simply add "true" between the parentheses ==> float T = dht.readTemperature(True);
  float H = dht.readHumidity();       // Read humidity in percentage.

  if (isnan(H) && isnan(T)) {         // See if H (the Humidity variable) is NaN (Not A Number) && (Logical AND) See if T (the Temperature variable) is NaN to show error. 
    lcd.print("ERROR");               // Print error where there's the error.
    return;                           // Repeat the process with each update (each second).
  }

  if(T>22){                           // See if the temperature is bigger than 22C.
    digitalWrite(yellowLED, HIGH);    // The yellow led will turn on.
    digitalWrite(blueLED, LOW);       // The blue led will turn off.
    digitalWrite(whiteLED, LOW);      // The white led will turn off.s
    
  }
  else if(T<22){                      // If the temperature is smaller than 22C.
    digitalWrite(blueLED, HIGH);      // The blue led will turn on.
    digitalWrite(yellowLED, LOW);     // The yellow led will turn off.
    digitalWrite(whiteLED, LOW);      // The white led will turn off.
  }

  else if(T=22){                      // If the temperature is equal than 22C.
    digitalWrite(whiteLED, HIGH);     // The white led will turn on.
    digitalWrite(yellowLED, LOW);     // The yellow led will turn off.
    digitalWrite(blueLED, LOW);       // The blue led will turn off.
  }

  lcd.setCursor(12, 0);               // Set the cursor to column 12, line 0.
  lcd.print(T);                       // Print the temperature.
  lcd.setCursor(12, 1);               // Set the cursor to column 12, line 1.
  lcd.print(H);                       // Print the humidity level.
}