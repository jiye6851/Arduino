#include "LedControl.h"
#include <Keypad.h>

LedControl lc = LedControl(12, 11, 10, 1);

byte dot[16][8] =
{
  {
    B11000000,  B11000000,  B00000000,  B00000000,
    B00000000,  B00000000,  B00000000,  B00000000  
  },
  {
    B00110000,  B00110000,  B00000000,  B00000000,
   B00000000,  B00000000,  B00000000,  B00000000   
  },  
  {
    B00001100,  B00001100,  B00000000,  B00000000,
    B00000000,  B00000000,  B00000000,  B00000000 
  },
  {
    B00000011,  B00000011,  B00000000,  B00000000,
    B00000000,  B00000000,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B11000000,  B11000000,
    B00000000,  B00000000,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00110000,  B00110000,
    B00000000,  B00000000,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00001100,  B00001100,
    B00000000,  B00000000,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00000011,  B00000011,
    B00000000,  B00000000,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00000000,  B00000000,
    B11000000,  B11000000,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00000000,  B00000000,
    B00001100,  B00001100,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00000000,  B00000000,
    B00000011,  B00000011,  B00000000,  B00000000
  },
  {
    B00000000,  B00000000,  B00000000,  B00000000,
    B00000000,  B00000000,  B11000000,  B11000000
  },
    {
    B00000000,  B00000000,  B00000000,  B00000000,
    B00000000,  B00000000,  B00110000,  B00110000
  },
    {
    B00000000,  B00000000,  B00000000,  B00000000,
    B00000000,  B00000000,  B00001100,  B00001100
  },
    {
    B00000000,  B00000000,  B00000000,  B00000000,
    B00000000,  B00000000,  B00000011,  B00000011
  }
};

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

int ran = random(0, 15); 
int count = 0;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);

  Serial.begin(9600);
}
 
void loop() {
  display_dot(ran);
  keyPress();
  if (millis() % 500 == 0)
    ran = random(0, 15);

  if (millis() < 10000 && count >= 20) {
    Serial.print("게임 승리!");
    delay(100000);
  }
  else if (millis() == 10000) {
    Serial.print("게임 오버!");
    delay(100000);
  }
}
 
void display_dot(int a)
{
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(0, i, dot[a][i]);
    }
}

void keyPress(){  // 키 입력 함수
  customKey = customKeypad.getKey();
  if(customKey){  //키 입력 신호가 있을때만 작동
    switch (customKey) {
      case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': 
      if (customKey - '0' == ran) {
        count++;   
        Serial.print("count = ");
        Serial.println(count);     
      } 
      break;

      case 'a': case 'b': case 'c': case 'd': 
      case 'e': case 'f':
      int temp = customKey - 'a' + 10;
      if (temp == ran) {
        count++;   
        Serial.print("count = ");
        Serial.println(count);     
      } 
      break;
    }

  }
}