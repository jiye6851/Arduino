#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

int next = 9;
int previous = 8;

void setup() {
  pinMode(next, INPUT);
  pinMode(previous, INPUT);

  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(25);
  myDFPlayer.play(1);
}
void loop() {
  if (digitalRead(next)) {
    myDFPlayer.next();
    delay(100);
  }

  if (digitalRead(previous)) {
    myDFPlayer.previous();
    delay(100);
  }

  if (myDFPlayer.available()) {
    uint8_t type = myDFPlayer.readType();
    if (type == DFPlayerPlayFinished) {
      Serial.println("Play Finished!");
      myDFPlayer.next();
    }
  }

}