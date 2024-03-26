const int trig = 11;
const int echo = 12;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  float Length, distance; // Lengtg와 distance를 지역변수로 선언

  digitalWrite(trig, LOW); // 초기화
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); // trigger 신호 발생
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  Length = pulseIn(echo, HIGH);
  distance = ((float)(340 * Length) / 10000) / 2; // 거리 계산

  Serial.print(distance); // 모니터 출력
  Serial.println("cm");

  delay(1000);
}

