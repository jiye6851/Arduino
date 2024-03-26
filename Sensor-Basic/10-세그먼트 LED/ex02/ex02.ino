int LED[10] = {2,3,4,5,6,7,8,9,10,11};
int value = 0;

int Joy_x = A0;    // 조이스틱 X
int Joy_y = A1;    // 조이스틱 Y
int Joy_SW = 13;   // 조이스틱 스위치 버튼

void setup() {
  for (int i =0; i < 10; i++) {
    pinMode(LED[i], OUTPUT);
  }

  pinMode(Joy_SW,INPUT);         // joy_SW를 입력모드로 설정
  Serial.begin(9600);          // 시리얼 통신을, 9600bps속도로 설정

}

void loop() {
  int x = analogRead(Joy_x);      // 조이스틱 X축의 아날로그 신호를 변수 x에 저장
  int y = analogRead(Joy_y);      // 조이스틱 Y축의 아날로그 신호를 변수 y에 저장
  int sw = digitalRead(Joy_SW);      // 조이스틱 SW의 디지털 신호를 변수 sw에 저장 

  if (x > 800) {
    value++;

    if (value > 10) // value가 10 초과가 될 경우 10으로 조정
      value = 10;
  }
  if (x < 100) {
        value--;

    if (value < 0) // value가 0 미만이 될 경우 0으로 조정
      value = 0;
  }

  Serial.print(value); // value 값을 시리얼 모니터에 출력
  Serial.print("\tX: ");
  Serial.println(x);

  for (int i =0; i < value; i++) {
    digitalWrite(LED[i], HIGH);
  }

  for (int i =value; i < 10; i++) {
    digitalWrite(LED[i], LOW);
  }

  delay(1000);
}
