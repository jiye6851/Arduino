  `int RED = 3;
int YELLOW = 2;
int GREEN = 1;

int trig = 8;
int echo = 9;

float timer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  int num = 0;
  while (num < 2000) {
    num = random(7000);
  }
  Serial.println("Whoever is closest to 0 wins!");
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  
  Serial.println("Ready");
  delay(1000);
  
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  
  delay(num);
  
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  
  Serial.println("-----------------START-----------------");
  timer = 0;
  
  delay(100);
  
  int duration, distance;
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = ((float)340 * duration) / 10000 / 2; // 거리 계산
  
  while ( distance >= 7) { // 초음파의 거리가 7cm 안으로 들어올 때 까지 계속 측정
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
    timer++;
	duration = pulseIn(echo, HIGH);
    distance = ((float)340 * duration) / 10000 / 2; // 거리 계산
  }
  
  if (distance < 7) // 7cm 안으로 들어왔을 경우
  {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    Serial.println(timer);
    Serial.println("");
    
    delay(3000);
  }
}