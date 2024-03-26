const int trig = 11;
const int echo = 12;

const int red = 3;
const int green = 5;
const int blue = 6;

void setup() {
  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
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

  Serial.print(distance);
  Serial.println("cm"); 
  
  if(distance <= 5){
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue,0);
    delay(1000);
  }
  else if(distance <= 10){
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue,0);
    delay(1000);
  }
  else{
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue,255);
    delay(1000);
  }
}
