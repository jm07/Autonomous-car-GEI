#include "hall_sensor.h"

Sensor_IT_TypeDef structSensor_AVG;
Sensor_IT_TypeDef structSensor_AVD;
Sensor_IT_TypeDef structSensor_ARG;
Sensor_IT_TypeDef structSensor_ARD;


void Hall_Config(void) {
	structSensor_AVG.pin= pin_AVG;
	structSensor_AVG.port= port_AVG;
	structSensor_AVG.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_AVG.gpioMode = GPIO_Mode_IPU;
	structSensor_AVG.triggerType = EXTI_Trigger_Falling;
	structSensor_AVG.NVIC_IRQChannelPreemptionPriority = preemptionPrio_AVG;
	structSensor_AVG.NVIC_IRQChannelSubPriority = subPrio_AVG;
	Sensor_IT_Config(&structSensor_AVG);

	structSensor_AVD.pin = pin_AVD;
	structSensor_AVD.port = port_AVD;
	structSensor_AVD.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_AVD.gpioMode = GPIO_Mode_IPU;
	structSensor_AVD.triggerType = EXTI_Trigger_Falling;
	structSensor_AVD.NVIC_IRQChannelPreemptionPriority = preemptionPrio_AVD;
	structSensor_AVD.NVIC_IRQChannelSubPriority = subPrio_AVD;
	Sensor_IT_Config(&structSensor_AVD);

	structSensor_ARG.pin = pin_ARG;
	structSensor_ARG.port = port_ARG;
	structSensor_ARG.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_ARG.gpioMode = GPIO_Mode_IPU;
	structSensor_ARG.triggerType = EXTI_Trigger_Falling;
	structSensor_ARG.NVIC_IRQChannelPreemptionPriority = preemptionPrio_ARG;
	structSensor_ARG.NVIC_IRQChannelSubPriority = subPrio_ARG;
	Sensor_IT_Config(&structSensor_ARG);

	structSensor_ARD.pin = pin_ARD;
	structSensor_ARD.port = port_ARD;
	structSensor_ARD.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_ARD.gpioMode = GPIO_Mode_IPU;
	structSensor_ARD.triggerType = EXTI_Trigger_Falling;
	structSensor_ARD.NVIC_IRQChannelPreemptionPriority = preemptionPrio_ARD;
	structSensor_ARD.NVIC_IRQChannelSubPriority = subPrio_ARD;
	Sensor_IT_Config(&structSensor_ARD);
}

static int GPIO_Pin_2_int(uint16_t GPIO_Pin);

__weak void Hall_Callback(int pos) {}


void HALL_EXTI_Callback (uint16_t GPIO_Pin) {
	int pin = GPIO_Pin_2_int(GPIO_Pin);
	//if(pin != -1)
		Hall_Callback(pin);
}


int GPIO_Pin_2_int(uint16_t GPIO_Pin) {
	if(GPIO_Pin == pin_AVG) return AVG;
	else if(GPIO_Pin == pin_AVD) return AVD;
	else if(GPIO_Pin == pin_ARG) return ARG;
	else if(GPIO_Pin == pin_ARD) return ARD;
	else return -1;
}
