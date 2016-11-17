#include <stdint.h>
#include "us_sensor.h"
#include "time_systick.h"
#include "hall_sensor.h"
#include "services_config.h"


static uint64_t d[ULTRASONIC_NB]={0};


int main(void) {
	uint64_t t_trig =0;
	
	Hall_Config();
	ultrasonic_config();
	initSystick();
	while(1){
		ultrasonic_trig_all();
		t_trig = micros();
		while(micros() - t_trig > TEMPS_TRIG){}
	}
	
  return 0;
}

void ultrasonic_callback(Ultrasonic_Position pos){
		d[pos] = ultrasonic_get_pulse_duration(pos);
}


