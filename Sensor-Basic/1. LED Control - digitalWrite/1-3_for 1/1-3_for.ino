// 실습 1-3 For 문을 통해 LED 깜빡이는 속도 조절하기

const int LED = 11; // 11번 핀을 사용하는 LED 상수 정의

void setup()
{
  pinMode(LED, OUTPUT); // LED를 출력으로 지정
  Serial.begin(9600);  // 컴퓨터와 아두이노 통신 설정
}

void loop()
{
  for (int i=100; i<=1000; i+=100) // 100부터 시작하여 1000이 될때까지 반복, 100씩 증가
  {
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i);
    Serial.println(i); // 시리얼 모니터에 i 값 출력
  }
}