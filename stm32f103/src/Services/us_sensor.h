#ifndef __US_SENSOR_H
#define __US_SENSOR_H

#include <stdint.h>


typedef enum US_Pos_t {
	US_ERROR  = -1,
	US_AV1 = 0, 
	US_AV2 = 1, 
	US_AV3 = 2, 
	US_AR1 = 3,
	US_AR2 = 4,
	US_AR3 = 5
} US_Pos_t;


uint64_t US_pulse_duration(US_Pos_t US_Pos);

void trig(void);

void untrig(void);

void US_echo_config(void);

void US_tri_config(void);

void US_Callback(US_Pos_t pos);


#endif // __US_SENSOR_H

