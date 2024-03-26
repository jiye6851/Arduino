int infrared  = A0;
int piezo = 8;

void setup() {
  // 부저 핀을 OUTPUT으로 설정합니다.
  pinMode(piezo, OUTPUT);
  // 적외선 장애물 감지 센서의 상태를 확인하기 위하여 시리얼 통신의 속도를 설정합니다.
  Serial.begin(9600);
}

void loop() {
  // 적외선 감지 센서 부터 센서값을 읽습니다.
  // 감지되면 0, 감지되지 않으면 1이 나옵니다.
  int state = analogRead(infrared);

  // 측정된 센서값을 시리얼 모니터에 출력합니다.
  Serial.print("Infrared = ");
  Serial.println(state);

  // 장애물이 감지되었다면(센서값이 100이하라면)
  if(state < 100){
    // 경보를 출력합니다.
    tone(piezo, 2093);
    delay(10);
    tone(piezo, 523);
    delay(10);
    // 경보 메세지를 시리얼 모니터에 출력합니다.
    Serial.println("Warring");
  }

  /// 장애물이 감지 되지 않았다면
  else{
    // 부저를 출력하지 않습니다.
    noTone(piezo);
    // 안전 메세지를 시리얼 모니터에 출력합니다.
    Serial.println("Safe");
  }
}