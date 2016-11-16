#ifndef __HALL_SENSOR_H
#define __HALL_SENSOR_H

#include <stdint.h>

typedef enum Hall_Pos_t {
	HALL_ERROR  = -1,
	HALL_AVG = 0,
	HALL_AVD = 1,
	HALL_ARG = 2,
	HALL_ARD = 3
} Hall_Pos_t;

void Hall_Config(void);

void Hall_Callback(Hall_Pos_t pos);

#endif // __HALL_SENSOR_H
