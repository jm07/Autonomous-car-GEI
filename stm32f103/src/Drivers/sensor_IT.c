#include <stdint.h>
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <misc.h>
#include <stm32f10x_exti.h>
#include "sensor_IT.h"

#define IF_DEFINE_NUM(n) \
	if (initStructS->outputPin == GPIO_Pin_##n){\
		GPIO_PinSource_Sensor = GPIO_PinSource##n;\
		EXTI_Line_Sensor = EXTI_Line##n;\
		EXTI_IRQn_Sensor = EXTI##n##_IRQn;\
	}\

#define IF_DEFINE_NUM_2(n,n1,n2) \
	if (initStructS->outputPin == GPIO_Pin_##n){\
		GPIO_PinSource_Sensor = GPIO_PinSource##n;\
		EXTI_Line_Sensor = EXTI_Line##n;\
		EXTI_IRQn_Sensor = EXTI##n1##_##n2##_IRQn;\
	}\
	

#define RCC_APBxPeriphClockCmd_GPIO_Sensor  RCC_APB2PeriphClockCmd
#define RCC_APBxPeriph_GPIO_Sensor          RCC_APB2Periph_GPIOC

Sensor_IT_TypeDef* initStructS;

static void RCC_Configuration(void);
static void GPIO_Configuration(void);
static void EXTI_Config(void);

//public functions

void Sensor_IT_Config(Sensor_IT_TypeDef* initStructSensor) {
	initStructS = initStructSensor;
	
   // System clocks configuration
	RCC_Configuration();

   // Configure the GPIO port
   GPIO_Configuration();
	
	//Configure external interruption
	EXTI_Config();
}


unsigned int Sensor_IT_Read(Sensor_IT_TypeDef* structSensor){
	return GPIO_ReadInputDataBit(structSensor->outputPinPort, structSensor->outputPin);
}


//Private functions
	
void RCC_Configuration(void) {
   // GPIO_Sensor clock enable
   RCC_APBxPeriphClockCmd_GPIO_Sensor(RCC_APBxPeriph_GPIO_Sensor, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}

void GPIO_Configuration(void) {
   GPIO_InitTypeDef GPIO_InitStructure;

   // GPIO_Pin_Sensor configuration
   GPIO_InitStructure.GPIO_Pin = initStructS->outputPin;
   GPIO_InitStructure.GPIO_Mode = initStructS->mode;
   GPIO_InitStructure.GPIO_Speed = initStructS->speed;

   GPIO_Init(initStructS->outputPinPort, &GPIO_InitStructure);
}

void EXTI_Config(void){
	EXTI_InitTypeDef 	EXTI_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	uint8_t 				GPIO_PortSource_Sensor;
	uint8_t 				GPIO_PinSource_Sensor;
	uint32_t 			EXTI_Line_Sensor;
	uint8_t 				EXTI_IRQn_Sensor;
	
	if (initStructS->outputPinPort == GPIOA){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOA;
	}else if(initStructS->outputPinPort == GPIOB){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOB;
	}else if(initStructS->outputPinPort == GPIOC){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOC;
	}else if(initStructS->outputPinPort == GPIOD){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOD;
	}else if(initStructS->outputPinPort == GPIOE){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOE;
	}else if(initStructS->outputPinPort == GPIOF){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOF;
	}else if(initStructS->outputPinPort == GPIOG){
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOG;
	}
	
		  IF_DEFINE_NUM(0)
	else IF_DEFINE_NUM(1)
	else IF_DEFINE_NUM(2)
	else IF_DEFINE_NUM(3)
	else IF_DEFINE_NUM(4)
	else IF_DEFINE_NUM_2(5,9,5)
	else IF_DEFINE_NUM_2(6,9,5)
	else IF_DEFINE_NUM_2(7,9,5)
	else IF_DEFINE_NUM_2(8,9,5)
	else IF_DEFINE_NUM_2(9,9,5)
	else IF_DEFINE_NUM_2(10,15,10)
	else IF_DEFINE_NUM_2(11,15,10)
	else IF_DEFINE_NUM_2(12,15,10)
	else IF_DEFINE_NUM_2(13,15,10)
  	else IF_DEFINE_NUM_2(14,15,10)
	else IF_DEFINE_NUM_2(15,15,10)
		
		
	GPIO_EXTILineConfig(GPIO_PortSource_Sensor,  GPIO_PinSource_Sensor);	
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line_Sensor;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = initStructS->triggerType;  
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI_IRQn_Sensor;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = initStructS->NVIC_IRQChannelPreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = initStructS->NVIC_IRQChannelSubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
