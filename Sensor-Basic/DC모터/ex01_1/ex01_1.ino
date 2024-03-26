  int M1 = 5; //#1 Motor Input A 
  int M2 = 6; //#2 Motor Input A 
  
  int speed = 150;

  void setup() {
  pinMode(M1, OUTPUT);    // 5번핀 출력모드
  pinMode(M2, OUTPUT);    // 6번핀 출력모드
  }
 
  void loop() {
  analogWrite(M1, 0);   
  analogWrite(M2, speed);  
  analogWrite(M1, speed); 
  analogWrite(M2, 0);
  delay(3000);           // 3초간 대기 후 반복
}