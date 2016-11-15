#include <stdint.h>
#include "us_sensor.h"
#include "time_systick.h"
#include "hall_sensor.h"

#define TEMPS_TRIG 50e3
#define TEMPS_DUREE 15e3
static uint64_t d[US_NB]={0};
uint64_t t_temp =0;
uint64_t t_now =0;
int trig_state = 0;
int sous = 0;

int main(void) {
	Hall_Config();
	US_echo_config();
	US_tri_config();
	initSystick();
	t_now = micros();
	while(1){
		t_now = micros();
		if(t_now - t_temp > TEMPS_TRIG){
			trig();
			trig_state = 1;
			t_temp = micros();
		}
		sous = t_now - t_temp;
		if(sous > TEMPS_DUREE && trig_state){
			untrig();
			trig_state = 0;
		}
	}
	
  return 0;
}

void US_Callback(int pos){
		d[pos] = US_pulse_duration(pos)/58;
}


