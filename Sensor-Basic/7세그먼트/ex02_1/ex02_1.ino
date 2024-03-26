
int pin[]={2, 3, 4, 5, 6, 7, 8, 9};       // 캐소드형 LED 세그먼트 출력핀 정의
int led_num = 8;                        // 7 세그먼트 LED
int BUTTON = 12;                      // 택트 스위치 Pin 번호
int num = 0;                             // 현재 LED 에 표시되고 있는 숫자

int digitForNum[11][8] = { 
                                          // 각 숫자에 대한 LED 설정 값을 정의
                                          // a  b  c  d  e  f  g dp  세그먼트 순
       {0, 0, 0, 0, 0, 0, 0, 1},  	// Dot Point 
       {1, 1, 1, 1, 1, 1, 0, 0},  	// 0
       {0, 1, 1, 0, 0, 0, 0, 0}, 	  // 1
       {1, 1, 0, 1, 1, 0, 1, 0},  	// 2
       {1, 1, 1, 1, 0, 0, 1, 0},  	// 3
       {0, 1, 1, 0, 0, 1, 1, 0}, 	  // 4
       {1, 0, 1, 1, 0, 1, 1, 0},  	// 5
       {1, 0, 1, 1, 1, 1, 1, 0},  	// 6
       {1, 1, 1, 0, 0, 0, 0, 0},  	// 7
       {1, 1, 1, 1, 1, 1, 1, 0}, 	  // 8
       {1, 1, 1, 1, 0, 1, 1, 0},  	// 9   
};

void setup () {
  for (int i=0; i < led_num; i++){          // 각 세그먼트 입력핀 초기화
      pinMode (pin[i], OUTPUT); 
  }  
  pinMode(BUTTON, INPUT_PULLUP);  // 택트 스위치를 INPUT_PULLUP으로 설정
}

void loop () {
  if(digitalRead(BUTTON) == LOW){ 
    num = random(1, 11);  
  }  
               // 0부터 9까지 숫자를 순서대로 표시합니다.
  for (int j=0; j < led_num; j++) {
               // 각 숫자에 대한 각각 LED의 로직레벨을 설정합니다.
      digitalWrite(pin[j], digitForNum[num][j]);      
  }
    delay (100);                         // 숫자 표시 후 0.1초 대기
}
