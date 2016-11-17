#include <stdint.h>
#include "hall_sensor.h"
#include "services_config.h"
#include "motor_front.h"
#include "motor_rear.h"

__IO int front = 0;
__IO int rear = 0;

uint64_t cpt = 500;
uint64_t tps = 0;

static int c[HALL_NB]={0};

void count_pulse(Hall_Position pos);

int main(void) {
	initServices();
	Hall_Config();
  initFrontMotor();
  initRearMotor();
	while(1){
		// control rear motors
		if (rear == 1) {
			enableRearMotor();
			commandRearMotor(70);
		} else if (rear == 2) {
			enableRearMotor();
			commandRearMotor(-70);
		} else {
			disableRearMotor();
		}
		
		// control front motor
		if (front == 1) {
			enableFrontMotor();
			commandFrontMotor(LEFT);
		} else if (front == 2) {
			enableFrontMotor();
			commandFrontMotor(RIGHT);
		} /*else if (front == 3) enableFrontMotor();
		else if (front == 4) disableFrontMotor();
		else commandFrontMotor(STOP);*/
		else {
			disableFrontMotor();
		}

	}
	
  return 0;
}

void hall_callback(Hall_Position pos){
	count_pulse(pos);
	/*while(tps < cpt){
		tps++;
	}*/
	if(pos == HALL_AVG || pos == HALL_AVD){
		//commandFrontMotor(STOP);
		disableFrontMotor();
		front = 0;
	}
}

void count_pulse(Hall_Position pos){
	c[(int)pos]++;
}
