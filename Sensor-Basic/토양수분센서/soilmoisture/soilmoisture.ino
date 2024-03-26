int red = 12;
int blue = 5;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  int soil = analogRead(A1);
  Serial.println(soil);
  if(soil < 500)
    digitalWrite(blue, HIGH);
  else
  {
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    delay(200);
    digitalWrite(red,LOW);
  }
  delay(500);
}