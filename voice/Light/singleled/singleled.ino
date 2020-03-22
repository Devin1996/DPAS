
String voice;

const int IN1 = 6;


void setup() {
  Serial.begin(9600);
    
    pinMode (IN1, OUTPUT);

}

void loop() {

  while (Serial.available())   
  {                            
  delay(10);                   
  char c = Serial.read();      
  if (c == '#') {break;}       
  voice += c;                  
  } 

  if (voice.length() > 0) {
    Serial.println(voice); 
 
       if(voice == "*light on")                                
     {
  digitalWrite(IN1, LOW);


  
     }  
  else if(voice == "*light off")                             
     {
      

  digitalWrite(IN1, HIGH);

     }
  }
 voice="";  
}
