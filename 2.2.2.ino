#define pin 10
float dutyCycle;

void lightUp(float dutyCycle){ //create dutyCycle function
  float timeOn = float(dutyCycle*100); //set the time interval that the PWM will send HIGH voltage
  float timeOff = float((1-dutyCycle)*100); //set the time interval that the PWM will send LOW voltage
  digitalWrite(pin, HIGH); //send HIGH voltage
  delayMicroseconds(100 * dutyCycle); // remain at HIGH for a certain fraction of time
  digitalWrite(pin, LOW); //send LOW voltage 
  delayMicroseconds(100 * (1-dutyCycle)); //remain at LOW for the remaining fraction of time
}

void setup() {
  pinMode(pin, OUTPUT); //set pin 10 as OUTPUT
}

void loop() {
  for (float i = 1; i <= 2000; i++){ //loop 2000 times 
    lightUp(i/10000.0); // call lightUp function
  }
  for(float j = 8000; j >= 1; j--){ //loop 8000 times
    lightUp(j/8000.0); // call lightUp function
  }
  for (float i = 1; i <= 2000; i++){ //loop 2000 times 
    lightUp(i/10000.0); // call lightUp function
  }
  for(float j = 8000; j >= 1; j--){ //loop 8000 times
    lightUp(j/8000.0); // call lightUp function
  }
  delay(1000);
}
