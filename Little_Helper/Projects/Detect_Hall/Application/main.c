#include <stdint.h>

#include <stm32f10x.h>
#include <stm32f10x_exti.h>
#include "led.h"
#include "hall_sensor.h"

void count_pulse(void);


int main(void) {
	LED_Config();
	Hall_Config();
	Hall_Set_IT_Function(&count_pulse);
	while(1){};
	
  return 0;
}

void count_pulse(void){
	static int c=0;
	LED_Toggle();
	c++;
}
