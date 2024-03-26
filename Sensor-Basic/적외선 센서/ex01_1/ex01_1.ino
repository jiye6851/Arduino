// IR 무선 적외선리모컨 실험
#include <IRremote.h> //IR리모컨라이브러리

int RECV_PIN = 3; //IR 수신센서 포트설정
IRrecv irrecv(RECV_PIN); // 리모컨 수신 설정 정의
decode_results results; //구조체정의

int led = 6;

void setup()
{
  Serial.begin(9600);//시리얼포트 속도를 9600bps로 지정
  irrecv.enableIRIn(); // 리모컨 수신 시작
}

void loop()
{
  if (irrecv.decode(&results)) //IR리모컨 라이브러리 호출
  {
    Serial.println(results.value, HEX); //리모컨 수신코드를 출력     
    irrecv.resume(); // 다음 값을 수신
  }
  if (results.value == 0xFD609F) {
    digitalwrite(led, HIGH);
  }
  if (results.value == 0xFD20DF) {
    digitalwrite(led, LOW);
  }
}