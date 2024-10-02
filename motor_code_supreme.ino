#define rightMotorForward 18
#define rightMotorReverse 19
#define leftMotorForward 4
#define leftMotorReverse 5

int init_time;
int end_time;

void forward(int motorpin, int power, int Time){
  analogWrite(motorpin, power);
  delay(Time);
  analogWrite(motorpin, 0);
}

void setup() {
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorReverse, OUTPUT);
  
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorReverse, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  init_time = micros();
  forward(leftMotorForward, 250, 50);
  delay(125);
  forward(rightMotorForward, 250, 60);
  delay(125);
  end_time = micros();
  Serial.println(end_time-init_time);
  
}
