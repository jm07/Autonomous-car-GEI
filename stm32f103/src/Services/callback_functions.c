#include <stdint.h>
#include "callback_functions.h"
#include "IT_functions.h"
#include "sensor_IT.h"
#include "hall_sensor.h"
#include "us_sensor.h"
#include "services_config.h"

__weak void ultrasonic_exti_callback (uint16_t GPIO_Pin){}
__weak void hall_exti_callback (uint16_t GPIO_Pin){}
	
void GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (get_hall_position(GPIO_Pin) != HALL_POSITION_ERROR)
		hall_exti_callback(GPIO_Pin);
	else if (get_ultrasonic_position(GPIO_Pin) != ULTRASONIC_POSITION_ERROR)
		ultrasonic_exti_callback(GPIO_Pin);
	else
		{}
}

Hall_Position get_hall_position(uint16_t GPIO_Pin) {
		   if (GPIO_Pin == HALL_AVG_PIN) return HALL_AVG;
	else if (GPIO_Pin == HALL_AVD_PIN) return HALL_AVD;
	else if (GPIO_Pin == HALL_ARG_PIN) return HALL_ARG;
	else if (GPIO_Pin == HALL_ARD_PIN) return HALL_ARD;
	else return HALL_POSITION_ERROR;
}

Ultrasonic_Position get_ultrasonic_position(uint16_t GPIO_Pin) {
		   if (GPIO_Pin == ULTRASONIC_AVC_ECHO_PIN) return ULTRASONIC_AVC;
	else if (GPIO_Pin == ULTRASONIC_AVG_ECHO_PIN) return ULTRASONIC_AVG;
	else if (GPIO_Pin == ULTRASONIC_AVD_ECHO_PIN) return ULTRASONIC_AVD;
	else if (GPIO_Pin == ULTRASONIC_ARC_ECHO_PIN) return ULTRASONIC_ARC;
	else if (GPIO_Pin == ULTRASONIC_ARG_ECHO_PIN) return ULTRASONIC_ARG;
	else if (GPIO_Pin == ULTRASONIC_ARD_ECHO_PIN) return ULTRASONIC_ARD;
	else return ULTRASONIC_POSITION_ERROR;
}
