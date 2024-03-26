#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(32, 16, 2);
 
 
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  
  Serial.begin(9600);
}
 
 
void loop()
{
  if (Serial.available() == true) {
    
    String inString = Serial.readStringUntil('\n');   
    Serial.print(inString);
    
    lcd.setCursor(0,0); 
    lcd.print(inString);
  	delay(1000);
  }
}