byte rowPin[8] = {2, 7, 19, 5, 13, 18, 12, 16};  // {1행, 2행, 3행, 4행, 5행, 6행, 7행, 8행}
byte colPin[8] = {6, 11, 10, 3, 17, 4, 8, 9};    // {1열, 2열, 3열, 4열, 5열, 6열, 7열, 8열} 

byte pattern[8] = {
0b01000010,
0b10100101,
0b10011001,
0b10000001,
0b10000001,
0b01000010,
0b00100100,
0b00011000};

void setup() {
 for (int i = 0; i < 8; i++) {
  pinMode(rowPin[i], OUTPUT); // 모든 행 제어 핀모드 OUTPUT 설정 
  pinMode(colPin[i], OUTPUT); // 모든 열 제어 핀모드 OUTPUT 설정 
 }
}

void loop() {   
  for (int i = 0; i < 8; i++) {     // delay(500); 시간 간격으로 아래로 한칸씩 행 이동행 제어핀 전체 켜고 끄기
    setonoff(pattern[i]);           // 8개 열의 상태값을 pattern 변수에서 추출한뒤 설정하는 사용자 함수
    digitalWrite(rowPin[i], HIGH);  // 해당 행 제어핀에 전원공급, LED ON 준비(열 제어핀 상태에 따라 ON)
    delay(1);                     // 전원공급 상태 유지 시간
    digitalWrite(rowPin[i], LOW);   // 해당 행 제어핀에 전원차단, 열 제어핀 상태에 상관없이 OFF)
  }
}

void setonoff(byte state) {    
  for(int i = 0; i < 8; i++) {  // 8개 열의 상태값을 pattern 변수에서 추출  
    bool a = state >> i & 0x01? LOW : HIGH; // bool 자료형 사용 변수값 변경 비트 마스크
    digitalWrite(colPin[i], a); // 열 제어핀 0b11111111 비트값에 맞게 설정 
  }
}
