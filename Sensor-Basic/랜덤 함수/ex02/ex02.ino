const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;

int ran = 0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
}

void loop() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  
  ran = random(3); // 0~2 사이의 랜덤한 숫자
  
  switch (ran) {
    case 0: 
    	digitalWrite(LED1, HIGH); 
    	break;
    case 1:
    	digitalWrite(LED2, HIGH); 
    	break;
    default:
    	digitalWrite(LED3, HIGH);
  }
  delay(200);
  
}