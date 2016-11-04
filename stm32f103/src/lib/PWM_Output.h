#ifndef _PWM_OUTPUT_H_
#define _PWM_OUTPUT_H_

#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

#define COUNTER_CLOCK_FREQ_1MHz  1000000 
#define PWM_MODE_1               1
#define PWM_MODE_2               2

typedef enum {
  PWM_INIT_OK,
  PWM_NOT_CHANNEL_1_2_3_4,
  PWM_NOT_MODE_1_2
} PWM_InitReturnType;

typedef struct {
  uint16_t outputPin;
  GPIO_TypeDef* outputPinPort;
  TIM_TypeDef* timer;
  uint16_t timerChannel;
  uint16_t periodUs;
  uint16_t dutyCyclePercent;
  GPIOSpeed_TypeDef speed;
  uint16_t mode;
} PWM_InitTypeDef;

PWM_InitReturnType PWM_initialize(PWM_InitTypeDef* init_struct);
void PWM_CmdPeriod(PWM_InitTypeDef* init_struct, uint16_t period_us);
void PWM_CmdDutyCycle(PWM_InitTypeDef* init_struct, uint16_t duty_cycle_percent);

#endif // _PWM_OUTPUT_H_
