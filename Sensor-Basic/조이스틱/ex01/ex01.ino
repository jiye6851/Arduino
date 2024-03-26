int Joy_x = 0;    
int Joy_y = 1;
int Joy_sw = 2;    //조이스틱의 스위치 버튼
 
void setup()
{
  pinMode(Joy_sw, INPUT);         // Z를 입력모드로 설정
  Serial.begin(9600);          // 시리얼 통신을, 9600bps속도로 설정
}
 
void loop()
{
  int x = analogRead(Joy_x);      // 조이스틱 X축의 아날로그 신호를 변수 x에 저장
  int y = analogRead(Joy_y);      // 조이스틱 Y축의 아날로그 신호를 변수 y에 저장
  int sw = digitalRead(Joy_sw);      // 조이스틱의 SW값의 디지털 신호를 변수 sw에 저장 
  Serial.print("X: ");                   
  Serial.print(x);                          //시리얼 모니터에 'X: x값'을 출력
  Serial.print("  Y: ");
  Serial.print(y);                          //시리얼 모니터에 '  Y: y값'을 출력
  Serial.print("  SW: ");
  Serial.println(sw);                        //시리얼 모니터에 '  Z: z값'을 출력하고 줄넘기기 
  delay(500);                                // 500ms 대기
} 
