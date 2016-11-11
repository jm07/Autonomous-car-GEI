#ifndef __SENSOR_IT_H
#define __SENSOR_IT_H

#include <stdint.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_exti.h>
#include "IT_functions.h"

typedef struct {
	uint16_t outputPin;
	GPIO_TypeDef* outputPinPort;
	GPIOSpeed_TypeDef speed;
	GPIOMode_TypeDef mode;
	EXTITrigger_TypeDef triggerType;
	uint8_t NVIC_IRQChannelPreemptionPriority;
	uint8_t NVIC_IRQChannelSubPriority;
} Sensor_IT_TypeDef;

void Sensor_IT_Config(Sensor_IT_TypeDef* initStructSensor);

unsigned int Sensor_IT_Read(Sensor_IT_TypeDef* structSensor);

#endif // __SENSOR_IT_H
