#ifndef __HALL_SENSOR_H
#define __HALL_SENSOR_H

#include "sensor_IT.h"

#define HALL_NB 			4

#define pin_AVG 						    GPIO_Pin_9
#define port_AVG						    GPIOC
#define preemptionPrio_AVG 		  0x0F
#define subPrio_AVG 					  0x0F

#define pin_AVD 						    GPIO_Pin_5
#define port_AVD						    GPIOC
#define preemptionPrio_AVD 		  0x0F
#define subPrio_AVD 					  0x0F

#define pin_ARG 						    GPIO_Pin_10
#define port_ARG						    GPIOC
#define preemptionPrio_ARG 		  0x0F
#define subPrio_ARG 					  0x0F

#define pin_ARD 						    GPIO_Pin_15
#define port_ARD						    GPIOC
#define preemptionPrio_ARD 		  0x0F
#define subPrio_ARD 					  0x0F

typedef enum Hall_Pos_t {
	AVG = 0,
	AVD = 1,
	ARG = 2,
	ARD = 3
} Hall_Pos_t;

void Hall_Config(void);

void Hall_Callback(int pos);

#endif // __HALL_SENSOR_H
