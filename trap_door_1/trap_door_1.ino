#include <Servo.h>


const int OPEN_POS = 90;

const int SERVO_PIN = 3;
const int BUTTON_PIN = 7;

Servo servo_1;
int buttonState;
int currentPos;

void setup()
{ 
  pinMode(BUTTON_PIN, INPUT);
  servo_1.attach(SERVO_PIN);
  currentPos = 0;
  buttonState = 0;
}

int setPositionBlocking(int target_pos, int pin=SERVO_PIN) {
  // Returns current servo position
//  target_pos = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo_1.write(target_pos);
  int pos = servo_1.read();
  while (pos != target_pos) {
    delay(1);
  }
  return servo_1.read();
}

int getButtonState(int pin=BUTTON_PIN) {
  // return 1 if button pressed
  buttonState = digitalRead(pin);
  if (buttonState == HIGH) {
    return 1;
  }
  return 0;
}

void loop() 
{
  buttonState = digitalRead(BUTTON_PIN);

  // Button acts as toggle, only functioning after movement has stopped
  if (getButtonState(BUTTON_PIN) == 1) {
    // Block until position is reached
    currentPos = setPositionBlocking(abs(currentPos - OPEN_POS));
  } 
}
