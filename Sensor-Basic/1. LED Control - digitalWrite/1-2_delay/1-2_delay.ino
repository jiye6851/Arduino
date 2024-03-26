// 실습 1-2 delay를 이용해 LED 깜박이기
const int LED = 11; // 11번 핀을 사용하는 LED 상수 정의

void setup()
{
  pinMode(LED, OUTPUT); // LED를 출력으로 지정
}

void loop()
{
  digitalWrite(LED, HIGH); // LED 핀에 HIGH 출력
  delay(1000); // 아두이노를 1000ms 동안 멈춤 (10초)
  digitalWrite(LED, LOW); // LED 핀에 LOW 출력
  delay(1000);
}