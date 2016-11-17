#include <stdint.h>
#include "hall_sensor.h"
#include "services_config.h"

static int c[HALL_NB]={0};

void count_pulse(Hall_Position pos);

int main(void) {
	initServices();
	Hall_Config();
	while(1){};
	
  return 0;
}

void hall_callback(Hall_Position pos){
		count_pulse(pos);
}

void count_pulse(Hall_Position pos){
	c[(int)pos]++;
}
