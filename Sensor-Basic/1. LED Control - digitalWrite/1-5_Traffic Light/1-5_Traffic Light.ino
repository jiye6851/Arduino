// 실습 1-4 신호등 만들어보기
const int GREEN = 2; // 2번 핀을 사용하는 LED 상수 정의
const int YELLOW = 3;
const int RED = 4;

void setup()
{
  pinMode(GREEN, OUTPUT); // LED를 출력으로 지정
  pinMode(YELLOW, OUTPUT); 
  pinMode(RED, OUTPUT);
}

void loop()
{
  digitalWrite(GREEN, HIGH);
  delay(1000);
  digitalWrite(GREEN, LOW);

  digitalWrite(YELLOW, HIGH);
  delay(2000);
  digitalWrite(YELLOW, LOW);

  digitalWrite(RED, HIGH);
  delay(3000);
  digitalWrite(RED, LOW);

}