#include "hall_sensor.h"
#include "sensor_IT.h"
#include "callback_functions.h"

Sensor_IT_TypeDef structSensor_AVG;
Sensor_IT_TypeDef structSensor_AVD;
Sensor_IT_TypeDef structSensor_ARG;
Sensor_IT_TypeDef structSensor_ARD;


void Hall_Config(void){
	structSensor_AVG.outputPin = pin_AVG;
	structSensor_AVG.outputPinPort = port_AVG;
	structSensor_AVG.speed = GPIO_Speed_50MHz;
	structSensor_AVG.mode = GPIO_Mode_IPU;
	structSensor_AVG.triggerType = EXTI_Trigger_Falling;
	structSensor_AVG.priority = preemptionPrio_AVG;
	Sensor_IT_Config(&structSensor_AVG);
	
	structSensor_AVD.outputPin = pin_AVD;
	structSensor_AVD.outputPinPort = port_AVD;
	structSensor_AVD.speed = GPIO_Speed_50MHz;
	structSensor_AVD.mode = GPIO_Mode_IPU;
	structSensor_AVD.triggerType = EXTI_Trigger_Falling;
	structSensor_AVD.priority = preemptionPrio_AVD;
	Sensor_IT_Config(&structSensor_AVD);
	
	structSensor_ARG.outputPin = pin_ARG;
	structSensor_ARG.outputPinPort = port_ARG;
	structSensor_ARG.speed = GPIO_Speed_50MHz;
	structSensor_ARG.mode = GPIO_Mode_IPU;
	structSensor_ARG.triggerType = EXTI_Trigger_Falling;
	structSensor_ARG.priority = preemptionPrio_ARG;
	Sensor_IT_Config(&structSensor_ARG);
	
	structSensor_ARD.outputPin = pin_ARD;
	structSensor_ARD.outputPinPort = port_ARD;
	structSensor_ARD.speed = GPIO_Speed_50MHz;
	structSensor_ARD.mode = GPIO_Mode_IPU;
	structSensor_ARD.triggerType = EXTI_Trigger_Falling;
	structSensor_ARD.priority = preemptionPrio_ARD;
	Sensor_IT_Config(&structSensor_ARD);
}

__weak void Hall_Callback(Hall_Pos_t pos){}


void HALL_EXTI_Callback (uint16_t GPIO_Pin){
	Hall_Callback(Hall_Pin_2_int(GPIO_Pin));
}


