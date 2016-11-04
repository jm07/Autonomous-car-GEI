#include <stdint.h>
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <misc.h>
#include <stm32f10x_exti.h>
#include "hall_sensor.h"

#define GPIO_Hall                         GPIOC
#define GPIO_Pin_Hall                     GPIO_Pin_7
#define GPIO_PortSource_Hall					GPIO_PortSourceGPIOC
#define GPIO_PinSource_Hall					GPIO_PinSource7
#define RCC_APBxPeriphClockCmd_GPIO_Hall  RCC_APB2PeriphClockCmd
#define RCC_APBxPeriph_GPIO_Hall          RCC_APB2Periph_GPIOC
#define EXTI_Line_Hall							EXTI_Line7
#define EXTI_IRQn_Hall							EXTI9_5_IRQn
#define EXTI_IRQHandler_Hall					EXTI9_5_IRQHandler

void (*user_function)(void);
static void RCC_Configuration(void);
static void GPIO_Configuration(void);
static void EXTI_Config(void);

//public functions

void Hall_Config(void) {
   // System clocks configuration
	RCC_Configuration();

   // Configure the GPIO port
   GPIO_Configuration();
	
	//Configure external interruption
	EXTI_Config();
}


unsigned int Read_Hall(void){
	return GPIO_ReadInputDataBit(GPIO_Hall, GPIO_Pin_Hall);
}

void Hall_Set_IT_Function(void (*IT_function)(void)){
	user_function = IT_function;
}


//Private functions
	
void RCC_Configuration(void) {
   // GPIO_Hall clock enable
   RCC_APBxPeriphClockCmd_GPIO_Hall(RCC_APBxPeriph_GPIO_Hall, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}

void GPIO_Configuration(void) {
   GPIO_InitTypeDef GPIO_InitStructure;

   // GPIO_Pin_Hall configuration
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_Hall;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

   GPIO_Init(GPIO_Hall, &GPIO_InitStructure);
}

void EXTI_Config(void){
	EXTI_InitTypeDef 	EXTI_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	GPIO_EXTILineConfig(GPIO_PortSource_Hall,  GPIO_PinSource_Hall);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line_Hall;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  //detection du passage 5V -> 0V
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI_IRQn_Hall;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI_IRQHandler_Hall(void){
	user_function();
	EXTI_ClearITPendingBit(EXTI_Line_Hall);
}
