const int row[8] = {2, 7, 19, 5, 13, 18, 12, 16};
const int col[8] = {6, 11, 10, 3, 17, 4, 8, 9};

int pixels[8][8]; // 좌표값 이차원 배열 선언

int x = 4; // x, y 좌표 초기값 -> 6행, 6열
int y = 4;

void setup() {
  Serial.begin(9600);
  for (int thisPin = 0; thisPin < 8; thisPin++) {  
    pinMode(col[thisPin], OUTPUT);    
    pinMode(row[thisPin], OUTPUT);
    digitalWrite(col[thisPin], HIGH);  // 열 제어핀에 5V(HIGH)를 주어 확실하게 토트가 OFF 되도록 함
  }
  for (int x = 0; x < 8; x++) {    // 이차원배열 모든 좌표값을 HIGH 로 초기화
    for (int y = 0; y < 8; y++) {  // refreshScreen() 함수에 의해
      pixels[x][y] = HIGH;         // 열 상태 값은 HIGH로 변경됨
    }
  }
}

void loop() {
  readSensors();    // 좌표 값 읽기
  refreshScreen();  // 좌표 값 쓰기
}

void readSensors() {  
  if (Serial.available() > 0) {  // x, y 좌표값 읽기
    String temp = Serial.readStringUntil('\n');
    if (temp.indexOf(",") != -1) {
      pixels[x][y] = HIGH;  // 새 좌표값을 읽기 전에 이전 좌표의 도트 끄기
      String x_temp = temp.substring(0, temp.indexOf(","));
      String y_temp = temp.substring(temp.indexOf(",") + 1, temp.length());
      x = x_temp.toInt();
      y = y_temp.toInt();
    }
  }
  pixels[x][y] = LOW; // 이차원배열 인데스 x,y에 LOW값 입력, refreshScreen() 함수에 의해 
}                     // y열의 상태 값 LOW, 해당 도트 켜짐

void refreshScreen() {
  for (int x = 0; x < 8; x++) {    // 8개 행 제어 
    digitalWrite(row[x], HIGH);    // 한개 행 5V 걸어서 열 상태값에 따라 켜지고 꺼지도록 준비
    for (int y = 0; y < 8; y++) {  // 8개 열 제어
      int thisPixel = pixels[x][y]; // 현재 행열 상태값 HIGH 또는 LOW 저장
      digitalWrite(col[y], thisPixel); // 현재 열 제어핀에 상태값 쓰기 - 열 전체 도트 영향 받음
      if (thisPixel == LOW) {          // 만약 현재 열에 LOW 값이 있으면 다음행으로 넘어갈 때 꺼진상태를 유지하기위해 
        digitalWrite(col[y], HIGH);    // 현재 열이 꺼지도록 초기화 한다.
      }
    }
    digitalWrite(row[x], LOW);    // 현재 행에 0V를 주어 다음 행 제어시 영향을 받지 않도록 한다.  
  }
}
