// 전자시계 만들기

#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
virtuabotixRTC myRTC(6, 7, 8);
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup()  {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  myRTC.setDS1302Time(00, 48, 8, 7, 25, 7, 2020);
}
 
void loop()  {
  myRTC.updateTime();
  lcd.setCursor(1,0);
  lcd.print(myRTC.year);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.dayofmonth); 
  lcd.print("/");
  switch (myRTC.dayofweek) {
    case 1: 
      lcd.print("Sun");
      break;
    case 2: 
      Serial.print("MON");
      break;
    case 3: 
      lcd.print("TUE");
      break;
    case 4:   
      lcd.print("WED");
      break;
    case 5:  
      lcd.print("THU");
      break;
    case 6:   
      lcd.print("FRI");
      break;
    case 7:    
      lcd.print("SAT");
      break;
  }     
  lcd.setCursor(5,1);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
 
  delay(1000);
  lcd.clear();
}