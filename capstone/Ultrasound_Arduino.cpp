const int trigPin = 2;    // 초음파 센서의 TRIG 핀
const int echoPin = 3;    // 초음파 센서의 ECHO 핀

void setup() {
  Serial.begin(9600);     // 시리얼 통신 시작
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
 EstDistance();

}


void EstDistance(){
  // 거리 측정
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  // 거리 값을 시리얼 통신으로 전송
  Serial.println(distance);
  
  delay(1000);  // 1초 대기
}