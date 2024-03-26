// 가변저항 값을 시리얼 모니터로 출력

const int POT = A0;
// 아날로그 입력 0 번 핀을 사용하는 가변저항 POT 상수 선언

void setup()
{
  Serial.begin(9600); // 9600 속도로 시리얼 통신 시작
}

void loop()
{
  int val = analogRead(POT);
  int per = map(val, 0, 1023, 0, 100);
  
  Serial.print("Anlog Reading: ");
  Serial.print(val);
  Serial.print("  ");
  
  Serial.print("Percentage: ");
  Serial.print(per);
  Serial.println("%"); 
  
  delay(1000);
}