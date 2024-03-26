//여러 줄을 묶은 매크로 '\' 이용, '\' 뒤에 어떤것도 없어야됨
#define SPACE { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0} \
}
#define H { \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
}
#define E  { \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}  \
}
#define L { \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}  \
}
#define O { \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
}
#define W { \
    {1, 0, 0, 0, 0, 0, 0, 1},\
    {1, 0, 0, 0, 0, 0, 1, 0},\
    {1, 0, 0, 0, 0, 0, 1, 0},\
    {0, 1, 0, 1, 0, 0, 1, 0},\
    {0, 1, 0, 1, 0, 1, 0, 0},\
    {0, 1, 0, 1, 0, 1, 0, 0},\
    {0, 0, 1, 1, 0, 1, 0, 0},\
    {0, 0, 0, 1, 1, 0, 0, 0},\
}
#define R { \
    {1, 1, 1, 1, 1, 0, 0, 0},\
    {1, 0, 0, 0, 1, 0, 0, 0},\
    {1, 0, 0, 0, 1, 0, 0, 0},\
    {1, 1, 1, 1, 1, 0, 0, 0},\
    {1, 0, 1, 0, 0, 0, 0, 0},\
    {1, 0, 0, 1, 0, 0, 0, 0},\
    {1, 0, 0, 0, 1, 0, 0, 0},\
    {1, 0, 0, 0, 0, 1, 0, 0},\
}
#define D { \
    {1, 1, 1, 1, 1, 0, 0, 0},\
    {1, 1, 0, 0, 1, 1, 0, 0},\
    {1, 1, 0, 0, 0, 1, 1, 0},\
    {1, 1, 0, 0, 0, 1, 1, 0},\
    {1, 1, 0, 0, 0, 1, 1, 0},\
    {1, 1, 0, 0, 0, 1, 1, 0},\
    {1, 1, 0, 0, 1, 1, 0, 0},\
    {1, 1, 1, 1, 1, 0, 0, 0},\
}

byte rowPin[8] = {2, 7, 19, 5, 13, 18, 12, 16};  // {1행, 2행, 3행, 4행, 5행, 6행, 7행, 8행}
byte colPin[8] = {6, 11, 10, 3, 17, 4, 8, 9};    // {1열, 2열, 3열, 4열, 5열, 6열, 7열, 8열} 

const int numPatterns = 11;  //표현할 글자 수
unsigned long startTime = 0;

byte patterns[numPatterns][8][8] = {  //표현할 문자 패턴, numPatterns 의 갯수에 맞게 표시
  H,E,L,L,O,W,O,R,L,D,SPACE      //H,E,L,L,O,SPACE
};
                   
void setup() {
 for (byte i = 0; i < 8; i++) {
  pinMode(rowPin[i], OUTPUT);
  pinMode(colPin[i], OUTPUT);
 }
}

void loop() {
  setonoff();
}

void setonoff() { 
  for (byte i = 0; i < numPatterns; i++,  startTime = millis()) { // 1초후 단어간 이동, 시간 초기화
    while (millis() - startTime < 900) {  // 1초 동안 문자 표시
      for (byte j = 0; j < 8; j++) { // row 위치 조정
        for (byte k =0; k < 8; k++) { // col 위치 조정
          boolean a = !patterns[i][j][k]; // 3차원 배열값 가져오기
          digitalWrite(colPin[k], a); // col 핀 제어
        }
        digitalWrite(rowPin[j], HIGH); // row 핀 제어
        delay(1);
        digitalWrite(rowPin[j], LOW);
      }
    }
    delay(100); // 단어간 구분 - 껏다 킴
  }
}
