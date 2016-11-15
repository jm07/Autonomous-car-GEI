#include <stdint.h>
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <misc.h>
#include <stm32f10x_exti.h>
#include "sensor_tri.h"

#define IF_DEFINE_NUM(n) \
	if (initStruct->outputPin == GPIO_Pin_##n){\
		GPIO_PinSource_Sensor = GPIO_PinSource##n;\
	}\

#define IF_DEFINE_NUM_2(n,n1,n2) \
	if (initStruct->outputPin == GPIO_Pin_##n){\
		GPIO_PinSource_Sensor = GPIO_PinSource##n;\
	}\
	

Sensor_Tri_TypeDef* initStruct;

static void GPIO_Configuration(void);

//public functions

void Sensor_Tri_Config(Sensor_Tri_TypeDef* initStructensor) {
	initStruct = initStructensor;
   // Configure the GPIO port
   GPIO_Configuration();
	
}


void GPIO_Configuration(void) {
   GPIO_InitTypeDef GPIO_InitStructure;

   // GPIO_Pin_Sensor configuration
   GPIO_InitStructure.GPIO_Pin = initStruct->outputPin;
   GPIO_InitStructure.GPIO_Mode = initStruct->mode;
   GPIO_InitStructure.GPIO_Speed = initStruct->speed;

   GPIO_Init(initStruct->outputPinPort, &GPIO_InitStructure);
}