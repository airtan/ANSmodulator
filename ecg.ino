#include <Wire.h>

int SLAVE_ADDRESS = 0x04;   //I2Cのアドレス『0x04』
const int heartPin = A1;
const int threshold_v = 400;
const int threshold_t = 350;
int p = 0;
int snap_time = 0;

void setup() {
  //シリアル通信の初期化しシリアルモニタへ文字列を出力できるようにする
  Serial.begin(9600);
  
    //I2C接続を開始する 
//  Wire.begin(SLAVE_ADDRESS);

  //I2Cで受信したときに呼び出す関数を登録する
//  Wire.onReceive(ReceiveMassage);

  //I2Cでリクエスト受信したときに呼び出す関数を登録する 
//  Wire.onRequest(sendData);
}
void loop() {
  int heartValue = analogRead(heartPin);
  if (heartValue > threshold_v && p == 0){
    Serial.println(heartValue);
    p = p + 1;
    snap_time = millis();
    }
  int present_time = millis();
  int RRI = present_time - snap_time;
  if(heartValue > threshold_v && RRI > threshold_t){
    Serial.println(RRI);
//    Wire.write(RRI);
    snap_time = 0;
    snap_time = millis();
    }
}



void ReceiveMassage(int n){
  char cmd = Wire.read();     //文字を読む
  Serial.println(cmd);       //シリアルポートにcmdを出力し表示する
}
