#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
float temp; // 실수형 타입의 변수 설정
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup()
{
  Serial.begin(9600);            
}
 
 
void loop()
{
  lcd.init(); 
  int val = analogRead(A0); // 온도센서의 output에서 들어온 신호를 받아줄 변수지정 
  temp = val*0.48828125; // 화씨->섭씨로 변환한 값을 변수로 지정
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Temperature");
  lcd.setCursor(6,1);
  lcd.print(temp, 1);
  lcd.setCursor(12,1);
  lcd.print("C");
  delay(1000);
}