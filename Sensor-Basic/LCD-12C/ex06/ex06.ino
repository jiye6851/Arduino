#include <NewPing.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
#define TRIGGER_PIN  12 
#define ECHO_PIN     11  
#define MAX_DISTANCE 200 
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup() {
  Serial.begin(9600); 
  lcd.init();
  lcd.backlight();    
}
 
void loop() {
  lcd.setCursor(4,0);
  lcd.print("Distance");  
  lcd.setCursor(5,1);
  lcd.print(sonar.ping_cm());   
  lcd.setCursor(8,1);
  lcd.print("cm");      
  delay(300);
  lcd.clear();
}