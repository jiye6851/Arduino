// IR 무선 적외선리모컨 실험
#include <IRremote.h> //IR리모컨라이브러리

int RECV_PIN = 3; //IR 수신센서 포트설정
IRrecv irrecv(RECV_PIN); // 리모컨 수신 설정 정의
decode_results results; //구조체정의

int M1A = 6; //#1 Motor Input A 
int M1B = 7; //#1 Motor input B 
int M2A = 8; //#2 Motor input A
int M2B = 9; //#2 Motor input B

void setup()
{
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  Serial.begin(9600);//시리얼포트 속도를 9600bps로 지정
  irrecv.enableIRIn(); // 리모컨 수신 시작

  Serial.println("Number for Motor Control "); // Initial words 
  Serial.println("1. Forward");
  Serial.println("2. Backward");
  Serial.println("3. Left");
  Serial.println("4. Right");
  Serial.println("5. Stop");
  Serial.println();  
}

void loop()
{
  if (irrecv.decode(&results)) //IR리모컨 라이브러리 호출
  {
    Serial.println(results.value, HEX); //리모컨 수신코드를 출력     
    irrecv.resume(); // 다음 값을 수신
  }
  if (results.values == 0xFD8877 ){ // 2번 버튼을 눌러 전진
       Forward();
  }
  if (results.values == 0xFD9867 ){ // 8번 버튼을 눌러 후진
      Backward();
  }
  if (results.values == 0xFD28D7 ){ // 4번 버튼을 눌러 좌회전
      Left();
  }
  if (results.values == 0xFD6897 ){ // 6번 버튼을 눌러 우회전
      Right();
  }
  if (results.values == 0xFD1897 ){ // 5번 버튼을 눌러 정지
      Stop();
  }
}

void Forward() // Motor 1: Left Side of Car, Motor 2: Right Side of Car
{
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();
   
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);  
  Serial.println("Motor 2 Forward");
  Serial.println();
}
 
void Backward()
{
  digitalWrite(M1A, LOW); 
  digitalWrite(M1B, HIGH);
  Serial.print("Motor 1 Backward");
  Serial.println();
   
  digitalWrite(M2A, LOW); 
  digitalWrite(M2B, HIGH);
  Serial.println("Motor 2 Backward");
  Serial.println();
}
 
void Left()
{
  digitalWrite(M1A, LOW); 
  digitalWrite(M1B, HIGH);
  Serial.print("Motor 1 Backward");
  Serial.println();
   
  digitalWrite(M2A, HIGH); 
  digitalWrite(M2B, LOW);
  Serial.println("Motor 2 Forward");
  Serial.println();
}
 
void Right()
{
  digitalWrite(M1A, HIGH); 
  digitalWrite(M1B, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();
   
  digitalWrite(M2A, LOW); 
  digitalWrite(M2B, HIGH);
  Serial.println("Motor 2 Backward");
  Serial.println();
}
 
void Stop()
{
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    Serial.print("Motor 1 Stop");
    Serial.println();
     
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);
    Serial.println("Motor 2 Stop");
    Serial.println();
}