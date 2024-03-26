int LED[10] = {2,3,4,5,6,7,8,9,10,11};

void setup() {
  for (int i =0; i < 10; i++) {
    pinMode(LED[i], OUTPUT);
  }

}

void loop() {

  for (int i =0; i < 10; i++) {
    digitalWrite(LED[i], HIGH);
    delay(1000);
  }

  for (int i =0; i < 10; i++) {
    digitalWrite(LED[i], LOW);
  }
}
