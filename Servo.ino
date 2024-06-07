#include <Servo.h>
Servo servoincubadora;

void setup() {
  servoincubadora.attach(3);

}

void loop() {
  servoincubadora.write(0);
  delay(2000);
  servoincubadora.write(15);
  delay(2000);
   servoincubadora.write(0);
  delay(2000);
  servoincubadora.write(15);
  delay(2000);
  servoincubadora.write(0);
  delay(7200000);

}