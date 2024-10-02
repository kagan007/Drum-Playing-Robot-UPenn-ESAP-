#define enableBridge 4
#define motorForward 18
#define motorReverse 19

void forward(int power, int Time){
  analogWrite(motorForward, power);
  delay(Time);
}

void backward(int power, int Time){
  analogWrite(motorReverse, power);
  delay(Time);
}

void setup() {
  pinMode(enableBridge, OUTPUT);
  pinMode(motorForward, OUTPUT);
  pinMode(motorReverse, OUTPUT);
}

void loop() {
  digitalWrite(enableBridge, HIGH);

  for (int i = 50; i < 150; i+=10){
    forward(i, 250);
    delay(1000);
  }
  for (int i = 150; i > 50; i-=10){
    forward(i, 250);
    delay(1000);
  }
}
