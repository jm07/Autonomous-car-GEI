#ifndef __HALL_SENSOR_H
#define __HALL_SENSOR_H

#include "sensor_IT.h"

#define pin_AVG 						    GPIO_Pin_9
#define port_AVG						    GPIOC
#define preemptionPrio_AVG 		  0x0F
#define subPrio_AVG 					  0x0F
#define Sensor_IT_AVG_Callback 	Sensor_IT9_Callback

#define pin_AVD 						    GPIO_Pin_5
#define port_AVD						    GPIOC
#define preemptionPrio_AVD 		  0x0F
#define subPrio_AVD 					  0x0F
#define Sensor_IT_AVD_Callback 	Sensor_IT5_Callback

#define pin_ARG 						    GPIO_Pin_10
#define port_ARG						    GPIOC
#define preemptionPrio_ARG 		  0x0F
#define subPrio_ARG 					  0x0F
#define Sensor_IT_ARG_Callback 	Sensor_IT10_Callback

#define pin_ARD 						    GPIO_Pin_15
#define port_ARD						    GPIOC
#define preemptionPrio_ARD 		  0x0F
#define subPrio_ARD 					  0x0F
#define Sensor_IT_ARD_Callback 	Sensor_IT15_Callback

void Hall_Config(void);

void Hall_AVG_Callback(void);
void Hall_AVD_Callback(void);
void Hall_ARG_Callback(void);
void Hall_ARD_Callback(void);

#endif // __HALL_SENSOR_H
