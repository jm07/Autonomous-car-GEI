#ifndef __SENSOR_TRI_H
#define __SENSOR_TRI_H

#include <stdint.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_exti.h>


typedef struct {
	uint16_t outputPin;
	GPIO_TypeDef* outputPinPort;
	GPIOSpeed_TypeDef speed;
	GPIOMode_TypeDef mode;
} Sensor_Tri_TypeDef;

void Sensor_Tri_Config(Sensor_Tri_TypeDef* initStructSensor);


#endif // __SENSOR_TRI_H
