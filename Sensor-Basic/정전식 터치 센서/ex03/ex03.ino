#define Touch 7 // 정전식 터치 센서를 7번에 연결

int touchCounter = 0; // 터치 센서를 누른 횟수를 저장하는 변수
int lastTouchState = 0; // 이전 버튼 스위치 상태를 읽어 저장

void setup() {
  pinMode(Touch, INPUT);
  Serial.begin(9600);
}

void loop() {
  int touchState = digitalRead(Touch); // 터치 센서 스위치 값을 읽어 touchState에 저장

  //터치 센서 상태가 바뀌었으면
  if (touchState != lastTouchState) {
    // 터치 센서가 눌리면
    if (touchState == HIGH) {
      touchCounter++; // 터치 센서를 누른 횟수 증가
      Serial.println("TOUCHED");
      Serial.print("number of touch sensor pushes: ");
      Serial.println(touchCounter);
    }
    else {
      Serial.println("not touched");
    }
    delay(100)
    
    // 현재 touchState를 다음 루프에서 lastTouchState로 사용
    lastTouchState = toushState; 
    
  }
}
