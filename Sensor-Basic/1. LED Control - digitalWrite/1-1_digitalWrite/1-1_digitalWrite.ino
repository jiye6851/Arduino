// 실습 1-1 digitalWrite로 LED 켜보기
int LED = 11; // 11번 핀을 사용하는 LED 상수 정의
void setup()
{
  pinMode(LED, OUTPUT); // LED를 출력으로 지정
  digitalWrite(LED, HIGH); // LED 핀에 HIGH 출력

}

void loop()
{
}