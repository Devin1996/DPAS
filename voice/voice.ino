#include<SD.h>
#include<TMRpcm.h>
#define SD_ChipselectPin 4
TMRpcm tmrpcm;
void setup() {
  tmrpcm.speakerPin = 9;

  if(!SD.begin(SD_ChipselectPin)){
    return;
    }

    tmrpcm.setVolume(7);
    tmrpcm.play("intro2.wav");
}

void loop() {
  // put your main code here, to run repeatedly:

}
