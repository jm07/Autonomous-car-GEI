#include <stdint.h>
#include "hall_sensor.h"
#include "services_config.h"

static int c[HALL_NB]={0};

void count_pulse(Hall_Pos_t pos);

int main(void) {
	Hall_Config();
	while(1){};
	
  return 0;
}

void Hall_Callback(Hall_Pos_t pos){
		count_pulse(pos);
}

void count_pulse(Hall_Pos_t pos){
	c[(int)pos]++;
}
