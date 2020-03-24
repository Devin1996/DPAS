//garrge elavator for the project
String voice;

const int IN1 = 6;
const int IN2 = 7;

void setup() {
  Serial.begin(9600);
    
    pinMode (IN1, OUTPUT);
    pinMode (IN2, OUTPUT);

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
 
       if(voice == "*lift up")                                
     {
  digitalWrite(IN1, HIGH);
  delay(5000);
  digitalWrite(IN2, LOW);
  delay(5000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
     }  
  else if(voice == "*lift down")                             
     {
      
  digitalWrite(IN2, HIGH);
  delay(5000);
  digitalWrite(IN1, LOW);
  delay(5000);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
     }
  }
 voice="";  
}
