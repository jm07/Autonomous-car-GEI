#ifndef __CALLBACK_FUNCTIONS_H
#define __CALLBACK_FUNCTIONS_H

#include <stdint.h>
#include "hall_sensor.h"
#include "us_sensor.h"

Hall_Position       get_hall_position(uint16_t GPIO_Pin);
Ultrasonic_Position get_ultrasonic_position(uint16_t GPIO_Pin);


#endif // __SCALLBACK_FUNCTIONS_H
