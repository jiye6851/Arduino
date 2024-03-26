int touchSensor = 2;      // 정전식 터치 센서 핀
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int count = 0;            // 손을 얼마나 오래 대었는지 카운트 해주는 변수
 
void setup() {
  pinMode(touchSensor, INPUT);      // 정전식 터치센서 입력으로 설정
  pinMode(led1, OUTPUT);            // LED 출력으로 설정
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT); 
  Serial.begin(9600);              // 시리얼 모니터 시작, 속도는 9600
}
 
void loop() {
  int value = digitalRead(touchSensor);   // 터치가 되었는지 안도
    
  if(value == 1){                       // 터치가 되었을 때
    digitalWrite(led1, HIGH);           // LED 1이 켜짐
    count++;
    Serial.println("Touch!!");           // 터치가 되었다고 시리얼모니터에 출력

    if (count > 60)
      digitalWrite(led4, HIGH);
    else if (count > 40)
      digitalWrite(led3, HIGH);
    else if (count > 20)
      digitalWrite(led2, HIGH);  
  }else{
    count--;
    Serial.println("nothing...");      // 터치가 되지 않았다고 시리얼 모니터에 'nothing...' 출력
    
    if(count < 0)
      count = 0;

    if (count <= 0)
      digitalWrite(led1, LOW);
    else if (count < 20)
      digitalWrite(led2, LOW);
    else if (count < 40)
      digitalWrite(led3, LOW);
    else if (count < 60)
      digitalWrite(led4, LOW);  
  }
  delay(30);
} 
 
