
int digit = 0;

byte digits[10][7] =
{
{0,0,0,0,0,0,1},
{1,0,0,1,1,1,1},
{0,0,1,0,0,1,0},
{0,0,0,0,1,1,0},
{1,0,0,1,1,0,0},
{0,1,0,0,1,0,0},
{0,1,0,0,0,0,0},
{0,0,0,1,1,1,1},
{0,0,0,0,0,0,0},
{0,0,0,1,1,0,0}
};

void setup()
{
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  
  for(int i =2; i<10; i++){
  	pinMode(i,OUTPUT);
}
  //7세그먼트 점 led 항시 off
  digitalWrite(9, HIGH);
}

void loop(){
 ColorChanger();
 digiter();
}

 //7세그먼트 숫자 표시기
 void digiter(){
   
   if(digitalRead(12)== HIGH){
 	++digit;
   if(digit >9){
     digit =0;
   }
  }
  if(digitalRead(13)== HIGH){
  	--digit;
    if(digit<0){
    digit =9;
     }
  	}
   int pin =2;
 	for(int i =0; i<7;i++) {
 		digitalWrite(pin +i, digits[digit][i]);                  
    }
  delay(200);
}

 //LED 적색 녹색 전환기
 void ColorChanger(){
  if(digit<8){
  	digitalWrite(11,HIGH);
  	digitalWrite(10,LOW);
  }else{
    digitalWrite(11,LOW);
  	digitalWrite(10,HIGH);
  }
}