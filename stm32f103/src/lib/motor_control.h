#ifndef _MOTOR_CONTROL_H_
#define _MOTOR_CONTROL_H_

#include "PWM_Output.h"

#define MOTOR_PWM_PERIOD_US           500
#define MOTOR_PWM_DEFAULT_DUTY_CYCLE  50
#define MOTOR_MAX_SPEED               100

typedef struct {
  uint16_t pwmPin1;
  uint16_t pwmPin2;
  GPIO_TypeDef* pwmPort1;
  GPIO_TypeDef* pwmPort2;
  TIM_TypeDef* pwmTimer;
  uint16_t pwm1TimerChannel;
  uint16_t pwm2TimerChannel;
  uint16_t periodUs;
  uint16_t gpioSpeed;
} motorInitTypeDef;

#endif // _MOTOR_CONTROL_H_