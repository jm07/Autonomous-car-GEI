#include "motor_direction.h"

void directionInit(Motor_TypeDef motor_direction) {
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
  
  PWM_TypeDef pwm1;
  PWM_TypeDef pwm2;
  
  pwm1.outputPin = DIRECTION_PIN_1;
  pwm1.outputPinPort = DIRECTION_PORT_1;
  pwm1.speed = DIRECTION_GPIO_SPEED;
  pwm1.timer = DIRECTION_TIMER;
  pwm1.timerChannel = DIRECTION_CHANNEL_1;
  
  pwm2.outputPin = DIRECTION_PIN_2;
  pwm2.outputPinPort = DIRECTION_PORT_2;
  pwm2.speed = DIRECTION_GPIO_SPEED;
  pwm2.timer = DIRECTION_TIMER;
  pwm2.timerChannel = DIRECTION_CHANNEL_2;
  
  motor_direction.pwm1 = &pwm1;
  motor_direction.pwm2 = &pwm2;
  
  motorInit(&motor_direction);
  motorCmd(&motor_direction, 0);
}

void cmdDirection(Motor_TypeDef motor_direction, Direction direction) {
  switch (direction) {
    case (LEFT) :
      motorCmd(&motor_direction, -DIRECTION_MOTOR_SPEED);
      break;
    case (RIGHT) :
      motorCmd(&motor_direction, DIRECTION_MOTOR_SPEED);
      break;
    case (STOP) :
    default :
      motorCmd(&motor_direction, 0);
      break;
  }
}