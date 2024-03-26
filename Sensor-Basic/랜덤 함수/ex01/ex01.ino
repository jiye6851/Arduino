const int GREEN= 9;  
const int BLUE = 10;    
const int RED = 11;   
const int BUTTON = 2;

int ran1;
int ran2;
int ran3;

void setup()
{
  pinMode (GREEN, OUTPUT); 
  pinMode (BLUE, OUTPUT);  
  pinMode (RED, OUTPUT);  
  pinMode (BUTTON, INPUT); 
  .
  Serial.begin(9600);
}

void loop() {

{
  ran1 = random(1, 256);
  ran2 = random(1, 256);
  ran3 = random(1, 256);
  
  analogWrite(GREEN, ran1);
  analogWrite(BLUE, ran2);
  analogWrite(RED, ran3);
  
  Serial.print("LED color : ");
  Serial.print(ran1);
  Serial.print(" ");
  Serial.print(ran2);
  Serial.print(" ");
  Serial.println(ran3);
  
  delay(500);
}