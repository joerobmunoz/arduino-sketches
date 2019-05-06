#include <Servo.h>

Servo serv;  // create servo object to control a servo
// twelve servo objects can be created on most boards


int PWM_PIN = 2;
int MAX_POS = 180;
int MIN_POS = 0;

int pos = 0;    // 0 origin

void setup() {
    serv.attach(PWM_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos=MIN_POS; pos<=MAX_POS; pos+=1) {
    serv.write(pos);
    delay(5);
  }

  for (pos=MAX_POS; pos>=MIN_POS; pos-=1) {
    serv.write(pos);
    delay(5);
  }
}
