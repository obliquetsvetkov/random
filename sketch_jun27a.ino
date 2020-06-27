int pwm_pin = 3;

void setup() {
  analogWriteFrequency(3, 25000); // frequency setup - 11bit sits at 23437.5hz
  analogWriteResolution(11);
  pinMode(pwm_pin, OUTPUT);

  setPwmDuty(768); //33%?
}

void loop() {

//    setPwmDuty(0); //not actually 0
//    delay(2000);
//    setPwmDuty(512); //very slight difference to '0'
//    delay(2000);
//    setPwmDuty(1024); //these are nice clear steps
//    delay(2000);
//    setPwmDuty(1535); //0-2048 to adjust duty cycle
//    delay(2000);    
//    setPwmDuty(2047); // max power
//    delay(2000);
}

void setPwmDuty(int duty){
  analogWrite(3, duty);
  //Serial.println(duty);
}
