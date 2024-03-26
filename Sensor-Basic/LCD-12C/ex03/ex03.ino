#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,16,2);  
 
int val=0;
 
void setup()
{
  lcd.init();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);                  
  lcd.backlight();  
}
 
void loop()
{
  val = analogRead(A0);
  if (val <= 250) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);;
    lcd.setCursor(5,0);
    lcd.print("Color");
    lcd.setCursor(5,1);
    lcd.print("<B>");
  }
  else if(val > 250 && val <= 500){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    lcd.setCursor(5,0);
    lcd.print("Color");
    lcd.setCursor(5,1);
    lcd.print("<G>");
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    lcd.setCursor(5,0);
    lcd.print("Color");
    lcd.setCursor(5,1);
    lcd.print("<R>");
  } 
}