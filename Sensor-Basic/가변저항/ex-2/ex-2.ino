// 가변저항으로 LED 밝기 제어
int LED = 3;
int POT = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(POT);
  analogWrite(LED, data/4); // data값을 4로 나누어 0~1023 사이 값을 0~255으로 만든다.

}
