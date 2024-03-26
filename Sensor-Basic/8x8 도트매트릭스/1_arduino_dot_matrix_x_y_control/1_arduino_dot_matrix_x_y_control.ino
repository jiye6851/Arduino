/* 아두이노 - 도트 매트릭스 핀연결
byte rowPin[8] = {2, 7, 19, 5, 13, 18, 12, 16};  // {1행, 2행, 3행, 4행, 5행, 6행, 7행, 8행}
byte colPin[8] = {6, 11, 10, 3, 17, 4, 8, 9};    // {1열, 2열, 3열, 4열, 5열, 6열, 7열, 8열}
*/

#define row 2  // 행제어 핀번호
#define col 9  // 열제어 핀번호

void setup() {
  pinMode(row, OUTPUT);  // 행제어 핀 출력 설정
  pinMode(col, OUTPUT);  // 열제어 핀 출력 설정
  digitalWrite(row, HIGH);  // row 핀 제어 - 1행 전원공급
}

void loop() {  
  digitalWrite(col, LOW);   // col핀 제어-1열 전원차단 -> 0V -> 전위차 발생 -> 전류흐름, LED ON
  delay(1000);
  digitalWrite(col, HIGH);  // col핀 제어-1열 전원공급 -> 5V -> 전위차 없음 -> 전류흐르지 않음
  delay(1000);
}
