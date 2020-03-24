
String voice;

const int singleVoiceLED = 13;


void setup() {
  Serial.begin(9600);

  pinMode (singleVoiceLED, OUTPUT);



}

void loop() {

SingleLedVoiceControl();

}

//voice controlled single light

void SingleLedVoiceControl() {
  while (Serial.available())
  {
    delay(10);
    char c = Serial.read();
    if (c == '#') {
      break;
    }
    voice += c;
  }

  if (voice.length() > 0) {
    Serial.println(voice);

    if (voice == "*light on")
    {
      digitalWrite(singleVoiceLED, LOW);

    }
    else if (voice == "*light off")
    {

      digitalWrite(singleVoiceLED, HIGH);

    }
  }
  voice = "";
}
