#ifndef _MOTOR_DIRECTION_H_
#define _MOTOR_DIRECTION_H_

#include "motor_control.h"

#define DIRECTION_PORT_1      GPIOB
#define DIRECTION_PORT_2      GPIOB
#define DIRECTION_PIN_1       8 
#define DIRECTION_PIN_2       9
#define DIRECTION_CHANNEL_1   TIM_Channel_3
#define DIRECTION_CHANNEL_2   TIM_Channel_4
#define DIRECTION_TIMER       TIM4
#define DIRECTION_GPIO_SPEED  GPIO_Speed_50MHz
#define DIRECTION_MOTOR_SPEED (0)

typedef enum {
  LEFT,
  RIGHT,
  STOP
} Direction;

void directionInit(Motor_TypeDef motor_direction);
void cmdDirection(Motor_TypeDef motor_direction, Direction direction);

#endif // _MOTOR_DIRECTION_H_