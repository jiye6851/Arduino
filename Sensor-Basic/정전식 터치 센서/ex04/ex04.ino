/*  터치 센서는 신체가 닿으면 HIGH(1) 디지털 입력 값을 반환하는 센서로
 *  버튼 스위치처럼 사용할 수 있다.
 *  delay 시간을 짧게 하면 터치 횟수를 정확히 셀 수 없다. 
 *  이 스케치는 터치센서의 기본 사용 방법과 센서가 눌려진 횟수를 세는 방법에 대해 알아본다.
 */
 
#define Touch 7             // 정전식 터치 센서를 7번에 연결
 
int touchCounter = 0;         // 터치 센서를 누른 횟수를 저장하는 변수
int lastTouchState = 0;         // 이전 버튼 스위치 상태를 읽어 저장
 
void setup() {
  pinMode(Touch, INPUT);     // 7번핀에 연결된 터치 센서를 입력으로 설정
  Serial.begin(9600);           // 9600속도로 시리얼 통신 시작
}
 
void loop() {
  int touchState = digitalRead(Touch); // 터치 센서 스위치 값을 읽어 touchState에 저장
 
  if (touchState != lastTouchState) {  // 터치 센서 상태가 바뀌었으면
    if (touchState == HIGH) {                      // 터치 센서가 눌리면
      touchCounter ++;                                // 터치 센서 누른 횟수를 증가
      Serial.println("TOUCHED");                       // 시리얼 창에 “TOUCHED” 쓰고 줄 바꿈
      Serial.print("number of touch sensor pushes: ");    // 시리얼 창에 “~: ” 쓰고
      Serial.println(touchCounter);                      // 연결해서 터치 센서 누른 횟수 쓰고 줄 바꿈
    } else {                        // 터치 센서가 TOUCHED에서 not touched으로 바뀌었으면
      Serial.println("not touched");                     // 시리얼 창에 “not touched” 쓰고 줄 바꿈
    }
    delay(100);
  }
   lastTouchState = touchState;             // 현재 touchState를 다음 루프에서 lastTouchState로 사용
}
 
