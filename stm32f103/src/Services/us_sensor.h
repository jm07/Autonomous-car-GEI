#ifndef __US_SENSOR_H
#define __US_SENSOR_H

#include <stdint.h>


typedef enum Ultrasonic_Position {
	ULTRASONIC_POSITION_ERROR  = -1,
	ULTRASONIC_AVC = 0,
	ULTRASONIC_AVG = 1,
	ULTRASONIC_AVD = 2,
	ULTRASONIC_ARC = 3,
	ULTRASONIC_ARG = 4,
	ULTRASONIC_ARD = 5
} Ultrasonic_Position;


uint64_t ultrasonic_get_distance(Ultrasonic_Position pos);

void ultrasonic_trig_all(void);

void ultrasonic_config(void);

void ultrasonic_callback(Ultrasonic_Position pos);


#endif // __US_SENSOR_H
