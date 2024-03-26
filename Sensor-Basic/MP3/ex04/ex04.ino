#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

int up = 9;
int down = 8;

void setup() {
  pinMode(up, INPUT);
  pinMode(down, INPUT);

  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(25);
  myDFPlayer.play(1);
}
void loop() {
  if (digitalRead(up)) {
    myDFPlayer.volumeUp();
    delay(100);
    Serial.print("volume: ");
    Serial.println(myDFPlayer.readVolume());
  }

  if (digitalRead(down)) {
    myDFPlayer.volumeDown();
    delay(100);
    Serial.print("volume: ");
    Serial.println(myDFPlayer.readVolume());
  }

  if (myDFPlayer.available()) {
    uint8_t type = myDFPlayer.readType();
    if (type == DFPlayerPlayFinished) {
      Serial.println("Play Finished!");
      myDFPlayer.play(1);
    }
  }

}