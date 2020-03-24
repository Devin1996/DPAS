
String voice;

const int led = 13;


void setup() {
  Serial.begin(9600);
    
    pinMode (led, OUTPUT);

}

void loop() {
voiceControlLight();

}

void voiceControlLight(){
    while (Serial.available())   
  {                            
  delay(10);                   
  char c = Serial.read();      
  if (c == '#') {break;}       
  voice += c;                  
  } 

  if (voice.length() > 0) {
    Serial.println(voice); 
 
       if(voice == "*light off")                                
     {
  digitalWrite(led, HIGH);


  
     }  
  else if(voice == "*light on")                             
     {
      

  digitalWrite(led, LOW);

     }
  }
 voice="";  
  }
