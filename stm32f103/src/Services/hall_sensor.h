#ifndef __HALL_SENSOR_H
#define __HALL_SENSOR_H

#include <stdint.h>

typedef enum Hall_Pos_t {
	HALL_ERROR  = -1,
	AVG = 0, 
	AVD = 1, 
	ARG = 2, 
	ARD = 3
} Hall_Pos_t;

void Hall_Config(void);

void Hall_Callback(Hall_Pos_t pos);

#endif // __HALL_SENSOR_H
