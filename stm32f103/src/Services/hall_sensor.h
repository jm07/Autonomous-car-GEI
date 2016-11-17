#ifndef __HALL_SENSOR_H
#define __HALL_SENSOR_H

#include <stdint.h>

typedef enum Hall_Position {
	HALL_POSITION_ERROR  = -1,
	HALL_AVG = 0,
	HALL_AVD = 1,
	HALL_ARG = 2,
	HALL_ARD = 3
} Hall_Position;

void Hall_Config(void);

void hall_callback(Hall_Position pos);

#endif // __HALL_SENSOR_H
