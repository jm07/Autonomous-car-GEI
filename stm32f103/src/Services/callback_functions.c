#include <stdint.h>
#include "callback_functions.h"
#include "IT_functions.h"
#include "sensor_IT.h"
#include "hall_sensor.h"
#include "us_sensor.h"

__weak void US_EXTI_Callback (uint16_t GPIO_Pin){}
__weak void HALL_EXTI_Callback (uint16_t GPIO_Pin){}
	
void GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(Hall_Pin_2_int(GPIO_Pin) != HALL_ERROR)
		HALL_EXTI_Callback(GPIO_Pin);
	else if(US_Pin_2_int(GPIO_Pin) != US_ERROR)
		US_EXTI_Callback(GPIO_Pin);
	else
		{}
}

Hall_Pos_t Hall_Pin_2_int(uint16_t GPIO_Pin){
		  if(GPIO_Pin == pin_AVG) return AVG;
	else if(GPIO_Pin == pin_AVD) return AVD;
	else if(GPIO_Pin == pin_ARG) return ARG;
	else if(GPIO_Pin == pin_ARD) return ARD;
	else return HALL_ERROR;
}

US_Pos_t US_Pin_2_int(uint16_t GPIO_Pin){
		  if(GPIO_Pin == pin_US_AV1) return US_AV1;
	else if(GPIO_Pin == pin_US_AV2) return US_AV2;
	else if(GPIO_Pin == pin_US_AV3) return US_AV3;
	else if(GPIO_Pin == pin_US_AR1) return US_AR1;
	else if(GPIO_Pin == pin_US_AR2) return US_AR2;
	else if(GPIO_Pin == pin_US_AR3) return US_AR3;
	else return US_ERROR;
}
