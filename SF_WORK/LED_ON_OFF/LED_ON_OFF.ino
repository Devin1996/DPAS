int LED_INPUT = 9; // Initializing pin number 

void setup() //The setup function will only run once, after each powerup.It initializes and sets the initial values
{
  Serial.begin(9600);   //Sets the baud for serial data transmission (Bits Per Second)
  pinMode(LED_INPUT,OUTPUT); //Specify behaviour of pin to work either as an input or an output
}

void loop() 
{
  char data;  //Recived data will get stored in this variable
  if(Serial.available()) //Here We're checking whether data is available or not
  {
    data=Serial.read(); //Data received
    if(data=='f')//LED ON
    {
      digitalWrite(LED_INPUT,HIGH);  // Write a HIGH or a LOW value to a digital pin
    }
    if(data=='b')//LED OFF
    {
      digitalWrite(LED_INPUT,LOW);
    }
  }
}

