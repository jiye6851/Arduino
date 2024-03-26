extern volatile unsigned long timer0_millis; //타이머변수
unsigned long timeVal; //이전시간
unsigned long readTime; //현재타이머시간
int hour, min, sec;
boolean state=false;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{ 
  if(Serial.available()){
    String inString = Serial.readStringUntil('\n');    
    int index1 = inString.indexOf(':'); 
    int index2 = inString.indexOf(':',index1+1);   
    int index3 = inString.length();
    
    hour = inString.substring(0, index1).toInt();
    min = inString.substring(index1+1,index2).toInt();
    sec = inString.substring(index2+1,index3).toInt();
  
    
    timer0_millis = ((long)hour*3600+min*60+sec)*1000;
    state=true;
    timeVal=millis();
  }
  if(state==true){ //시리얼모니털 출력 시작
    
    if(millis()-timeVal>=1000){ //1초 단위 출력
     readTime = millis()/1000;
      
     if(millis()>=86400000){
       timer0_millis=0;
     }
     timeVal = millis();
   
     sec = readTime%60;
     min = (readTime/60)%60;
     hour = (readTime/(60*60))%24;       
      
     Serial.print(hour);
     Serial.print(" : ");
     Serial.print(min);
     Serial.print(" : ");
     Serial.println(sec);      
    }
  }
}