// (음극) 단일 7-세그먼트 LED의 각 세그먼트 점멸하기

int pinA = 2, pinB = 3, pinC = 4, pinD = 5,
	pinE = 6, pinF = 7, pinG = 8, pinDP = 9;

void setup()
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 2; i < 10; i++) {
    Serial.print(" i is ");
    Serial.println(i);
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
  delay(1000);
}