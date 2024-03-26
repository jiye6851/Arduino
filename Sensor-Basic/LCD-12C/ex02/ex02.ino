#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
 
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hellow, world!");
}
 
 
void loop()
{
  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int position = 0; position < 35; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}