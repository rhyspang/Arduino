#include "MotorCar.h"
#include "Arduino.h"


MotorCar::MotorCar(uint8_t speedFrontLeftPin, uint8_t dirFrontLeftPin,
			 uint8_t speedFrontRightPin, uint8_t dirFrontRightPin,
			 uint8_t speedBackLeftPin, uint8_t dirBackLeftPin,
			 uint8_t speedBackRightPin, uint8_t dirBackRightPin
			 ) {
	_speedPin[0] = _speedFrontLeftPin = speedFrontLeftPin;
	_dirPin[0] = _dirFrontLeftPin = dirFrontLeftPin;
	_speedPin[1] = _speedFrontRightPin = speedFrontRightPin;
	_dirPin[1] = _dirFrontRightPin = dirFrontRightPin;
	
	_speedPin[2] = _speedBackLeftPin = speedBackLeftPin;
	_dirPin[2] = _dirBackLeftPin = dirBackLeftPin;
	_speedPin[3] = _speedBackRightPin = speedBackRightPin;
	_dirPin[3] = _dirBackRightPin = dirBackRightPin;
	
	for(uint8_t i = 0; i < WHEEL_NUM; i++ ) {
		pinMode(_speedPin[i], OUTPUT);
		pinMode(_dirPin[i], OUTPUT);
	}
 }
 
 void MotorCar::goForward(uint8_t speed = SPEED_DEFAULT, int time = TIME_DEFAULT) {
	 checkSpeed(speed);
	 for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		digitalWrite(_dirPin[i], LOW);
		analogWrite(_speedPin[i], speed);
	 } 
	 delay(time);
 }
 
 void MotorCar::goBack(uint8_t speed = SPEED_DEFAULT, int time = TIME_DEFAULT) {
	 checkSpeed(speed);
	 for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		digitalWrite(_dirPin[i], HIGH);
		analogWrite(_speedPin[i], MAX_SPEED-speed);
	 } 
	 delay(time);
 }
 
 void MotorCar::goLeft(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT, int time = TIME_DEFAULT) {
	 checkSpeed(speed);
	 checkArc(arc);
	for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		if( i == 1 || i == 2 ) {
			digitalWrite(_dirPin[i], LOW);
			analogWrite(_speedPin[i], speed);
		}else {
			digitalWrite(_dirPin[i], LOW);
			analogWrite(_speedPin[i], (double)arc/MAX_ARC*speed );
		}
	} 
	delay(time);
 }
 
 void MotorCar::goRight(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT, int time = TIME_DEFAULT) {
	 checkSpeed(speed);
	 checkArc(arc);
	 for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		if( i == 0 || i == 3 ) {
			digitalWrite(_dirPin[i], LOW);
			analogWrite(_speedPin[i], speed);
		}else {
			digitalWrite(_dirPin[i], LOW);
			analogWrite(_speedPin[i], (double)arc/MAX_ARC*speed );
		}
	 } 
	 delay(time);
 }
 
 void MotorCar::goBackLeft(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT, int time = TIME_DEFAULT) {
	 checkSpeed(speed);
	 checkArc(arc);
	 for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		if( i == 1 || i == 2 ) {
			digitalWrite(_dirPin[i], HIGH);
			analogWrite(_speedPin[i], MAX_SPEED-speed);
		}else {
			digitalWrite(_dirPin[i], HIGH);
			analogWrite(_speedPin[i], (MAX_SPEED-(double)arc/MAX_ARC));
		}
	 } 
	 delay(time);
 } 
 
 void MotorCar::goBackRight(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT, int time = TIME_DEFAULT) {
	checkSpeed(speed);
	checkArc(arc);
	for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		if( i == 0 || i == 3 ) {
			digitalWrite(_dirPin[i], HIGH);
			analogWrite(_speedPin[i], MAX_SPEED-speed);
		}else {
			digitalWrite(_dirPin[i], HIGH);
			analogWrite(_speedPin[i], (MAX_SPEED-(double)arc/MAX_ARC));
		}
	 } 
	 delay(time);
 }
 
 
 void MotorCar::stop() {
	for (uint8_t i = 0; i < WHEEL_NUM; i++) {
		digitalWrite(_dirPin[i], LOW);
		analogWrite(_speedPin[i], 0);
	} 
 }
 
 void MotorCar::circle(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT, int time = TIME_DEFAULT) {
	 goRight(speed, arc);
	 delay(STAYTIME<<1);
 }
 void MotorCar::wriggle(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT) {
	 uint8_t r = 4;
	 while(r--) {
		goLeft(speed, arc);
		goRight(speed, arc);
	 }
	 
 }
 
 void MotorCar::joggling() {
	goForward(MAX_SPEED, 50);
	goBack(MAX_SPEED, 50);
 }
 
 void MotorCar::dancing(uint8_t speed = SPEED_DEFAULT, uint8_t arc = ARC_DEFAULT, int time = TIME_DEFAULT>>2) {
	 for(uint8_t i = 0; i < 2; i++ ) {
		joggling();
		goForward(speed, time);
		joggling();
		goBack(speed, time);
		goLeft(speed, arc, time);
		goBackRight(speed, arc, time);
		goRight(speed, arc, time);
		goBackLeft(speed, arc, time);
	 }
	 goRight(speed, arc);
	 delay(STAYTIME<<1);
	 goLeft(speed, arc);
	 delay(STAYTIME<<1);
 }
 
 void MotorCar::goWithMaxSpeed(int time = TIME_DEFAULT) {
	 goForward(MAX_SPEED, time);
 }
 
 void inline MotorCar::checkSpeed(uint8_t& speed) {
	if (speed > MAX_SPEED)	speed = MAX_SPEED;
	if (speed < 0)		speed = 0;
 }
 
 void inline MotorCar::checkArc(uint8_t& arc) {
	 if (arc < 0)	arc = 0;
	 if (arc > MAX_ARC)	arc = MAX_ARC;
 }