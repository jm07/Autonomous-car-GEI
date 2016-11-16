#ifndef __CALLBACK_FUNCTIONS_H
#define __CALLBACK_FUNCTIONS_H

#include <stdint.h>
#include "hall_sensor.h"
#include "us_sensor.h"

Hall_Pos_t Hall_Pin_2_int(uint16_t GPIO_Pin);
US_Pos_t US_Pin_2_int(uint16_t GPIO_Pin);


#endif // __SCALLBACK_FUNCTIONS_H
