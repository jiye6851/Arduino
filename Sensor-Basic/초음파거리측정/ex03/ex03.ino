int echo = 4; 
int trig = 5;
int buzzer = 13; // 스피커

int timer = 0; // 시간

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  float Length, distance; // Lengtg와 distance를 지역변수로 선언
  digitalWrite(trig,HIGH);
  digitalWrite(trig,LOW);

  Length = pulseIn(echo, HIGH);
  distance = ((float)(340 * Length) / 10000) / 2; // 거리 계산
  
  Serial.print(distance);
  Serial.print("cm");

  if(distance < 50){ // 50cm 이하일 시 
    delay(1000);
    timer++;

   Serial.print("   timer :");
   Serial.println(timer);

    if(timer == 10){ // 10초 동안 50cm 이하 상태였을 경우
      while(1){
        tone(buzzer,262,500);
        delay(1000);
      }
    }
  } else {
    timer = 0;
  }
}