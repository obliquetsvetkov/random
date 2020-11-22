int pwm_pin = 3;
int temp = -1; // init to invalid
int oldtemp = -1; // buffer since parseint returns 0 on empty (why it passes the serial check in the first place idk)

void setup() {
  // freq and resolution are valid for board used: TeensyLC. Check your board supports this.
  analogWriteFrequency(3, 25000); // frequency setup - 11bit sits at 23437.5hz; close enough.
  analogWriteResolution(11); // 2047 is max value.
  pinMode(pwm_pin, OUTPUT);
  Serial.begin(9600); //now that python works this is useful
  setPwmDuty(2047 * 0.1); // start low
}

void loop() {
  if (Serial.available() > 0) {
    temp = Serial.parseInt(); // reads entire number at once
    //Serial.println(temp);
  }

  if (temp == 0) {
    temp = oldtemp; //buffer for 0
  }

// this could probably be made and mapped better, but this is functional:
  if (temp <= 40) {
    setPwmDuty(2047 * 0.1);
  }
  else if (temp > 40 && temp <= 45) {
    setPwmDuty(2047 * 0.2);
    oldtemp = 42;
  }
  else if (temp > 45 && temp <= 50) {
    setPwmDuty(2047 * 0.4);
    oldtemp = 47;
  }
  else if (temp > 50 && temp <= 55) {
    setPwmDuty(2047 * 0.5);
    oldtemp = 52;
  }
  else if (temp > 55 && temp <= 60) {
    setPwmDuty(2047 * 0.6);
    oldtemp = 57;
  }
  else if (temp > 60 && temp <= 65) {
    setPwmDuty(2047 * 0.7);
    oldtemp = 62;
  }
  else if (temp > 65 && temp <= 70) {
    setPwmDuty(2047 * 0.8);
    oldtemp = 67;
  }
  else if (temp > 70 && temp <= 75) {
    setPwmDuty(2047 * 0.9);
    oldtemp = 72;
  }
  else if (temp > 75) {
    setPwmDuty(2047 * 1);
    oldtemp = 77;
  }

}

void setPwmDuty(int duty){
  analogWrite(3, duty);
  //Serial.println(duty);
}
