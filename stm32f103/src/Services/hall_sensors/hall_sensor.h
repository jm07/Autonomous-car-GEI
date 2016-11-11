#ifndef __HALL_SENSOR_H
#define __HALL_SENSOR_H

#include "sensor_IT.h"

void Hall_Config(void);

void Hall_AVG_Callback(void);
void Hall_AVD_Callback(void);
void Hall_ARG_Callback(void);
void Hall_ARD_Callback(void);

#endif // __HALL_SENSOR_H
