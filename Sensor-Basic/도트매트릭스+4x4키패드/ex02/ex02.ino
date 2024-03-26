#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','a','b'},
  {'c','d','e','f'}
};
byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = {6, 7, 8, 9}; 

char customKey;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
}


void keyPress();

void loop(){
  keyPress();
}

void keyPress(){  // 키 입력 함수
  customKey = customKeypad.getKey();
  if(customKey){  //키 입력 신호가 있을때만 작동
    Serial.println(customKey);
  }
}