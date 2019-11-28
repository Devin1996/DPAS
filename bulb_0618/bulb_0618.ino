String voice;
 
#define GREEN 10
#define BLUE 11
#define RED 9
 
void setup() 
{                                            
  Serial.begin(9600);
   pinMode(GREEN, OUTPUT);
   pinMode(BLUE, OUTPUT);
   pinMode(RED, OUTPUT);
   
   analogWrite(RED,0); 
   analogWrite(GREEN,0);                   
   analogWrite(BLUE,0);
}
 
  int redVal;
  int greenVal;
  int blueVal;
 
 
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
 
       if(voice == "*red")                                
     {
     analogWrite(RED,255); 
     analogWrite(GREEN,0);
     analogWrite(BLUE,0);
     }  
  else if(voice == "*green")                             
     {
    analogWrite(GREEN,255);
    analogWrite(RED,0);
    analogWrite(BLUE,0);
     }
  else if(voice == "*blue")
     {
    analogWrite(RED,0);
    analogWrite(BLUE,255);
    analogWrite(GREEN,0);
     }
  
  else if(voice == "*light off")
     {
    analogWrite(RED,0);
    analogWrite(GREEN,0);
    analogWrite(BLUE,0);
     }
   else if(voice == "*light on")
     {
    analogWrite(RED,220);
    analogWrite(GREEN,245);
    analogWrite(BLUE,250);
     }
    
      else if(voice == "*fade light") 
     {
 
 
     redVal = 255;  
     blueVal = 0;
     greenVal = 0;
     for(int i = 0; i < 255; i += 1) 
    {
    greenVal += 1;
    redVal -= 1;
    analogWrite(GREEN, 255 - greenVal);
    analogWrite(RED, 255 - redVal);
    delay(10);
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for(int i = 0; i < 255; i += 1)
  {
    blueVal += 1;
    greenVal -= 1;
    analogWrite(BLUE, 255 - blueVal);
    analogWrite(GREEN, 255 - greenVal);
    delay(10);
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1)
  {
    redVal += 1;
    blueVal -= 1;
    analogWrite(RED, 255 - redVal);
    analogWrite(BLUE, 255 - blueVal);
    delay(10);
  }
       
   
     
       }
  }

   
voice="";                                                       
}

