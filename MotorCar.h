#ifndef Motor_Car_h
#define Motor_Car_h

#define   STAYTIME 				2000
#define	  WHEEL_NUM 			(1 << 2)
#define   MAX_SPEED				0xFE	
#define   MAX_ARC				10
#define	  SPEED_DEFAULT			200
#define   ARC_DEFAULT			3
#define   TIME_DEFAULT			2000
#define	  SECOND				1000
#include "Arduino.h"

class MotorCar{
public :
	MotorCar(uint8_t, uint8_t,
			 uint8_t, uint8_t,
			 uint8_t, uint8_t,
			 uint8_t, uint8_t);
			 
	void goForward(uint8_t, int);
	void goBack(uint8_t, int);
	void goLeft(uint8_t, uint8_t, int);
	void goRight(uint8_t, uint8_t, int);
	void goBackRight(uint8_t, uint8_t, int);
	void goBackLeft(uint8_t, uint8_t, int);
	void goWithMaxSpeed(int);
	void circle(uint8_t, uint8_t, int);
	void stop();
	void wriggle(uint8_t, uint8_t);
	void dancing(uint8_t, uint8_t, int);
	void joggling();
	
private :
	uint8_t _speedFrontLeftPin;
	uint8_t _speedFrontRightPin;
	uint8_t _speedBackLeftPin;
	uint8_t _speedBackRightPin;
	
	uint8_t _dirFrontLeftPin;
	uint8_t _dirFrontRightPin;
	uint8_t _dirBackLeftPin;
	uint8_t _dirBackRightPin;
	
	uint8_t _speedPin[WHEEL_NUM], _dirPin[WHEEL_NUM];
	
	uint8_t _speed;
	void checkSpeed(uint8_t& speed);
	void checkArc(uint8_t& arc);
		
};
#endif