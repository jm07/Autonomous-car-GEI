#include "IT_functions.h"
#include <stm32f10x_exti.h>
#include <stm32f10x_gpio.h>

#define EXTI_CALLBACKS(n) \
	if(EXTI_GetITStatus(EXTI_Line##n) != RESET){\
		HALL_EXTI_Callback(GPIO_Pin_##n);\
		US_EXTI_Callback(GPIO_Pin_##n);\
		EXTI_ClearITPendingBit(EXTI_Line##n);\
	}\


void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler (void);

__weak void US_EXTI_Callback (uint16_t GPIO_Pin){}
__weak void HALL_EXTI_Callback (uint16_t GPIO_Pin){}

void EXTI0_IRQHandler(void){
	EXTI_CALLBACKS(0);
}

void EXTI1_IRQHandler(void){
	EXTI_CALLBACKS(1);
}

void EXTI2_IRQHandler(void){
	EXTI_CALLBACKS(2);
}

void EXTI3_IRQHandler(void){
	EXTI_CALLBACKS(3);
}

void EXTI4_IRQHandler(void){
	EXTI_CALLBACKS(4);
}

void EXTI9_5_IRQHandler(void)
{
	EXTI_CALLBACKS(5);
	EXTI_CALLBACKS(6);
	EXTI_CALLBACKS(7);
	EXTI_CALLBACKS(8);
	EXTI_CALLBACKS(9);
}

void EXTI15_10_IRQHandler(void)
{
	EXTI_CALLBACKS(10);
	EXTI_CALLBACKS(11);
	EXTI_CALLBACKS(12);
	EXTI_CALLBACKS(13);
	EXTI_CALLBACKS(14);
	EXTI_CALLBACKS(15);
}



