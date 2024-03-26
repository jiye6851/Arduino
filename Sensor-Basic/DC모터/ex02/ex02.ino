int M1A = 6; //#1 Motor Input A 
int M1B = 7; //#1 Motor input B 
int M2A = 8; //#2 Motor input A
int M2B = 9; //#2 Motor input B
 
void setup()
{
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
 
  Serial.begin(9600);
  Serial.println("Number for Motor Control "); // Initial words 
  Serial.println("1. Forward");
  Serial.println("2. Backward");
  Serial.println("3. Left");
  Serial.println("4. Right");
  Serial.println("5. Stop");
  Serial.println();  
}
 
void loop()
{
  char user_input;
   
  while(Serial.available())
  {
    user_input = Serial.read(); // Get Input from Serial Monitor
    if (user_input =='1'){
       Forward();
    }
    else if(user_input =='2'){
      Backward();
    }
    else if(user_input =='3'){
      Left();
    }
    else if(user_input =='4'){
      Right();
    }
    else if(user_input =='5'){
      Stop();
    }
    else{
      Serial.println("Wrong Number");
    }
  }
}
 
void Forward() // Motor 1: Left Side of Car, Motor 2: Right Side of Car
{
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();
   
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);  
  Serial.println("Motor 2 Forward");
  Serial.println();
}
 
void Backward()
{
  digitalWrite(M1A, LOW); 
  digitalWrite(M1B, HIGH);
  Serial.print("Motor 1 Backward");
  Serial.println();
   
  digitalWrite(M2A, LOW); 
  digitalWrite(M2B, HIGH);
  Serial.println("Motor 2 Backward");
  Serial.println();
}
 
void Left()
{
  digitalWrite(M1A, LOW); 
  digitalWrite(M1B, HIGH);
  Serial.print("Motor 1 Backward");
  Serial.println();
   
  digitalWrite(M2A, HIGH); 
  digitalWrite(M2B, LOW);
  Serial.println("Motor 2 Forward");
  Serial.println();
}
 
void Right()
{
  digitalWrite(M1A, HIGH); 
  digitalWrite(M1B, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();
   
  digitalWrite(M2A, LOW); 
  digitalWrite(M2B, HIGH);
  Serial.println("Motor 2 Backward");
  Serial.println();
}
 
void Stop()
{
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    Serial.print("Motor 1 Stop");
    Serial.println();
     
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);
    Serial.println("Motor 2 Stop");
    Serial.println();
}