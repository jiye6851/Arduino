void setup() {
  Serial.begin(9600);
  byte patterns = 12;  //표현할 글자 수
  for (byte i = 0; i <= (patterns * 8); i++) { // 글자수당 8열
    Serial.print(i); 
    if (i < 10) Serial.print("  : ");
    else Serial.print(" : ");
    for (byte k = 0; k < 8; k++) {  
      byte val = (i+k) % 8;
      Serial.print(val);
    }
    Serial.println();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
