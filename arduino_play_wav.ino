//https://github.com/TMRh20/TMRpcm/wiki

#include <SD.h>

#include <TMRpcm.h>

#define SD_ChipSelectPin 10  //arduino UNO pin10を使用

TMRpcm audio;

void setup(){
   pinMode(2,INPUT) ;  //arduino UNO pin2にスイッチを接続
   audio.speakerPin = 9;  //arduino UNO pin9に音声出力
   
   if (!SD.begin(SD_ChipSelectPin)) {  //SDカードの存在を確認
   return;
   }
   audio.play("music1.wav");  //music1.wavを再生する
}

void loop(){
     if (digitalRead(2) == HIGH) {  //スイッチが押される
     audio.pause();  //曲の一時停止または再生
     }
}
