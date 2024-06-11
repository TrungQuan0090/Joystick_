// xuong 1019
// giua 502
// len 0

long t=1000;

void servo(int x){    //thay doi xung ppm
  digitalWrite(5, 1);
  delayMicroseconds(x);
  digitalWrite(5, 0);
  delay(10);
  delayMicroseconds(1000-x);
}

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(A5, INPUT);
}

void loop() {
  long js = analogRead(A5);
  Serial.println(js);
  
  while(js>1000){
    t-=10;
    if(t>2500)
      t=2500;
    servo(t);
    js = analogRead(A5);
  }

  while(js<10){
    t+=10;
    if(t<500)
      t=500;
    servo(t);
    js = analogRead(A5);
  }

}
