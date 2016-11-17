#include <stdint.h>
#include "led.h"
#include "hall_sensor.h"
#include "switch.h"
#include "motor_control.h"


int main(void) {
	LED_Config();
	Hall_Config();
	while(1){};
	
  return 0;
}

void Hall_ARD_Callback(void){
	static int c=0;
	LED_Toggle();
	c++;
}


