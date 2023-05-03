
//Led Pattern (1,1,3)
int a[13]={1,0,0,1,0,0,1,0,1,0,1,0,2};

int count =0;
unsigned long previousMillis = 0;
const long delayTime = 300;

void setup(){
  pinMode(13,OUTPUT);
}

void loop(){  
  
  LedReader(13,a[count]);
       
}

  void LedReader(int pin, int ArryIndex){
    //time checker
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis < delayTime) return;
    {
       previousMillis = currentMillis;
       LedReader(13,a[count]);
    } 
    //pattern reader
    switch(ArryIndex){
      case 0:
         digitalWrite(pin,LOW);
         count++;
         break;
      case 1:
      digitalWrite(pin, HIGH);
         count++;
         break;
      case 2:
         digitalWrite(pin, LOW);
         count=0;
         break;
    }
  }

 
