int joy_x = A0;
int joy_y = A1;
int joy_sw = 2;
int BUTTON = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(joy_sw, INPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(joy_x);
  int y = analogRead(joy_y);
  int sw = digitalRead(joy_sw);  
  int button = digitalRead(BUTTON);  
  
  Serial.print(x);
  Serial.print("|");
  Serial.print(y);
  Serial.print("|");
  Serial.println(button);

  delay(20);
}
