#include <stdint.h>
#include "hall_sensor.h"

static int c[HALL_NB]={0};

void count_pulse(int pos);

int main(void) {
	Hall_Config();
	while(1){};
	
  return 0;
}

void Hall_Callback(int pos){
		count_pulse(pos);
}

void count_pulse(int pos){
	c[(int)pos]++;
}
