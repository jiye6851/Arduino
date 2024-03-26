  int M1 = 5; //#1 Motor Input A 
  int M2 = 6; //#2 Motor Input A 
  
  void setup() {
  pinMode(M1, OUTPUT);    // 5번핀 출력모드
  pinMode(M2, OUTPUT);    // 6번핀 출력모드
  }
 
  void loop() {
  digitalWrite(M1, LOW);   
  digitalWrite(M2, HIGH);  
  digitalWrite(M1, HIGH); 
  digitalWrite(M2, LOW);
  delay(3000);           // 3초간 대기 후 반복
}