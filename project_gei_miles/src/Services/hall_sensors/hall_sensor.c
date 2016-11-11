#include "hall_sensor.h"
#include "sensor_IT.h"

#define pin_AVG 						GPIO_Pin_9
#define port_AVG						GPIOC
#define preemptionPrio_AVG 		0x0F
#define subPrio_AVG 					0x0F
#define Sensor_IT_AVG_Callback 	Sensor_IT9_Callback

#define pin_AVD 						GPIO_Pin_5
#define port_AVD						GPIOC
#define preemptionPrio_AVD 		0x0F
#define subPrio_AVD 					0x0F
#define Sensor_IT_AVD_Callback 	Sensor_IT5_Callback

#define pin_ARG 						GPIO_Pin_10
#define port_ARG						GPIOC
#define preemptionPrio_ARG 		0x0F
#define subPrio_ARG 					0x0F
#define Sensor_IT_ARG_Callback 	Sensor_IT10_Callback

#define pin_ARD 						GPIO_Pin_15
#define port_ARD						GPIOC
#define preemptionPrio_ARD 		0x0F
#define subPrio_ARD 					0x0F
#define Sensor_IT_ARD_Callback 	Sensor_IT15_Callback

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
	structSensor_AVG.NVIC_IRQChannelPreemptionPriority = preemptionPrio_AVG;
	structSensor_AVG.NVIC_IRQChannelSubPriority = subPrio_AVG;
	Sensor_IT_Config(&structSensor_AVG);
	
	structSensor_AVD.outputPin = pin_AVD;
	structSensor_AVD.outputPinPort = port_AVD;
	structSensor_AVD.speed = GPIO_Speed_50MHz;
	structSensor_AVD.mode = GPIO_Mode_IPU;
	structSensor_AVD.triggerType = EXTI_Trigger_Falling;
	structSensor_AVD.NVIC_IRQChannelPreemptionPriority = preemptionPrio_AVD;
	structSensor_AVD.NVIC_IRQChannelSubPriority = subPrio_AVD;
	Sensor_IT_Config(&structSensor_AVD);
	
	structSensor_ARG.outputPin = pin_ARG;
	structSensor_ARG.outputPinPort = port_ARG;
	structSensor_ARG.speed = GPIO_Speed_50MHz;
	structSensor_ARG.mode = GPIO_Mode_IPU;
	structSensor_ARG.triggerType = EXTI_Trigger_Falling;
	structSensor_ARG.NVIC_IRQChannelPreemptionPriority = preemptionPrio_ARG;
	structSensor_ARG.NVIC_IRQChannelSubPriority = subPrio_ARG;
	Sensor_IT_Config(&structSensor_ARG);
	
	structSensor_ARD.outputPin = pin_ARD;
	structSensor_ARD.outputPinPort = port_ARD;
	structSensor_ARD.speed = GPIO_Speed_50MHz;
	structSensor_ARD.mode = GPIO_Mode_IPU;
	structSensor_ARD.triggerType = EXTI_Trigger_Falling;
	structSensor_ARD.NVIC_IRQChannelPreemptionPriority = preemptionPrio_ARD;
	structSensor_ARD.NVIC_IRQChannelSubPriority = subPrio_ARD;
	Sensor_IT_Config(&structSensor_ARD);
}

__weak void Hall_AVG_Callback(void){}
__weak void Hall_AVD_Callback(void){}
__weak void Hall_ARG_Callback(void){}
__weak void Hall_ARD_Callback(void){}


void Sensor_IT_AVG_Callback(void){
	Hall_AVG_Callback();
}

void Sensor_IT_AVD_Callback(void){
	Hall_AVD_Callback();
}

void Sensor_IT_ARG_Callback(void){
	Hall_ARG_Callback();
}

void Sensor_IT_ARD_Callback(void){
	Hall_ARD_Callback();
}
