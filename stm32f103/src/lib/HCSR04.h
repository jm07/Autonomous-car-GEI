#ifndef _HCSR04_H_
#define _HCSR04_H_

#include "stm32f10x_gpio.h" 
#include "stm32f10x_tim.h"

#define TIM_NO_FILTER 0x0

typedef enum {
  INIT_OK,
  TIM_ONLY_CHANNEL_1_2_ACCEPTED
} HCSR04_InitReturnType;

typedef struct {
  uint16_t echoPin;
  uint16_t trigPin;
  GPIO_TypeDef* echoPinPort;
  GPIO_TypeDef* trigPinPort;
  GPIOSpeed_TypeDef speed;
  TIM_TypeDef* timerForEchoPin;
  uint16_t timerChannelForEchoPin;
} HCSR04_InitTypeDef;

HCSR04_InitReturnType HCSR04_Initialize(HCSR04_InitTypeDef* init_struct);

#endif // _HCSR04_H_
