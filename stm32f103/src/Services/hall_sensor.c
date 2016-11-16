#include "hall_sensor.h"
#include "sensor_IT.h"
#include "callback_functions.h"
#include "services_config.h"

Sensor_IT_TypeDef structSensor_AVG;
Sensor_IT_TypeDef structSensor_AVD;
Sensor_IT_TypeDef structSensor_ARG;
Sensor_IT_TypeDef structSensor_ARD;


void Hall_Config(void){
	structSensor_AVG.pin = HALL_AVG_PIN;
	structSensor_AVG.port = HALL_AVG_PORT;
	structSensor_AVG.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_AVG.gpioMode = GPIO_Mode_IPU;
	structSensor_AVG.triggerType = EXTI_Trigger_Falling;
	structSensor_AVG.priority = HALL_PRIO;
	Sensor_IT_Config(&structSensor_AVG);
	
	structSensor_AVD.pin = HALL_AVD_PIN;
	structSensor_AVD.port = HALL_AVD_PORT;
	structSensor_AVD.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_AVD.gpioMode = GPIO_Mode_IPU;
	structSensor_AVD.triggerType = EXTI_Trigger_Falling;
	structSensor_AVD.priority = HALL_PRIO;
	Sensor_IT_Config(&structSensor_AVD);
	
	structSensor_ARG.pin = HALL_ARG_PIN;
	structSensor_ARG.port = HALL_ARG_PORT;
	structSensor_ARG.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_ARG.gpioMode = GPIO_Mode_IPU;
	structSensor_ARG.triggerType = EXTI_Trigger_Falling;
	structSensor_ARG.priority = HALL_PRIO;
	Sensor_IT_Config(&structSensor_ARG);
	
	structSensor_ARD.pin = HALL_ARD_PIN;
	structSensor_ARD.port = HALL_ARD_PORT;
	structSensor_ARD.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_ARD.gpioMode = GPIO_Mode_IPU;
	structSensor_ARD.triggerType = EXTI_Trigger_Falling;
	structSensor_ARD.priority = HALL_PRIO;
	Sensor_IT_Config(&structSensor_ARD);
}

__weak void Hall_Callback(Hall_Pos_t pos){}


void HALL_EXTI_Callback (uint16_t GPIO_Pin){
	Hall_Callback(Hall_Pin_2_int(GPIO_Pin));
}


