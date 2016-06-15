#include <MotorCar.h>
int val;
int speed = 150;
MotorCar c(3,8,5,2,6,4,9,7);

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, LOW);
  delay(3000);
}
void loop() {
  
  val = Serial.read();
  delay(1000);
  if( -1 != val ) {
     digitalWrite(13,HIGH);
    if(1 == val) {
        c.goForward(speed, 2000);
        c.stop();
    }
    if( 2 == val) {
      
      c.goBack(speed, 2000);
      c.stop();
    }
    if(3 == val) {
      c.goLeft(speed, 3, 1000);
      c.stop();
    }
    if(4 == val) {
      c.goRight(speed, 3, 1000);
      c.stop();
    }
    if(5 == val) {
      c.goBackLeft(speed, 3, 1000);
      c.stop();
    }
    if(6 == val) {
      c.goBackRight(speed, 3, 1000);
      c.stop();
    }

    if(7 == val) {
      c.goWithMaxSpeed(2000);
      c.stop();
    }
    if(8 == val) {
     // c.circle(speed, 3, 2000);
      c.circle(speed, 3, 2000 );
      c.stop();
    }
    if(9 == val) {
      c.dancing(255, 3, 800);
      c.stop();
    }
    digitalWrite(13,LOW);
  }
  
  /*
  c.goForward(speed);
  c.stop(2);
  c.goBack(speed);
  c.stop(2);
  c.goRight(speed, 0);
  c.stop(2);
  c.goLeft(speed, 0);
  c.stop(2);

  c.goBackRight(speed, 0);
  c.stop(2);
  c.goBackLeft(speed, 0);
  c.stop(5);
  */
}
