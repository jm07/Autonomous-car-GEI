#ifndef _PWM_OUTPUT_H_
#define _PWM_OUTPUT_H_

#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

typedef struct {
  uint16_t outputPin;
  GPIO_TypeDef* outputPinPort;
  TIM_TypeDef* timer;
  
  
} PWM_InitTypeDef;

#endif // _PWM_OUTPUT_H_
