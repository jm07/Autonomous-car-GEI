#include "motor_control.h"

void motorInit(Motor_TypeDef* init_struct) {
  GPIO_InitTypeDef enablePin;
  
  // bind pwm1 - mode 1
  init_struct->pwm1.mode = PWM_MODE_1;
  init_struct->pwm1.dutyCyclePercent = MOTOR_PWM_DEFAULT_DUTY_CYCLE;
  init_struct->pwm1.periodUs = MOTOR_PWM_PERIOD_US;
  // bind pwm1 - mode 2
  init_struct->pwm2.mode = PWM_MODE_2;
  init_struct->pwm2.dutyCyclePercent = MOTOR_PWM_DEFAULT_DUTY_CYCLE;
  init_struct->pwm2.periodUs = MOTOR_PWM_PERIOD_US;
  // check wheather 2 pwms have different config
  if ((init_struct->pwm1.timer != init_struct->pwm2.timer) || \
      (init_struct->pwm1.speed != init_struct->pwm1.speed)) {
    init_struct->pwm2.timer = init_struct->pwm1.timer;
    init_struct->pwm2.speed = init_struct->pwm1.speed;
  } else {}
  // initialize pwm
  PWM_initialize(&(init_struct->pwm1));
  PWM_initialize(&(init_struct->pwm2));
  
  // initialize enable pin
  enablePin.GPIO_Mode = GPIO_Mode_Out_PP;
  enablePin.GPIO_Speed = GPIO_Speed_50MHz;
  enablePin.GPIO_Pin = init_struct->enablePin;
  GPIO_Init(init_struct->enablePort, &enablePin);
}

void motorCmd(Motor_TypeDef* motor_struct, int speed) {
  uint16_t dutyCycle = 0;
  uint16_t dutyCycleRange = (uint16_t)(DUTY_CYCLE_MAX - DUTY_CYCLE_MIN);
  uint16_t speedRange = (uint16_t)(MOTOR_SPEED_MAX - MOTOR_SPEED_MIN);
  int speedAux;
  if (speed > MOTOR_SPEED_MAX) speedAux = MOTOR_SPEED_MAX;
  else if (speed < MOTOR_SPEED_MIN) speedAux = MOTOR_SPEED_MIN;
  else speedAux = speed;
  dutyCycle = (uint16_t)((speedAux - MOTOR_SPEED_MIN) * dutyCycleRange / speedRange + DUTY_CYCLE_MIN);
  PWM_CmdDutyCycle(&(motor_struct->pwm1), dutyCycle);
  PWM_CmdDutyCycle(&(motor_struct->pwm2), dutyCycle);
}

void motorEnable(Motor_TypeDef* motor_struct, Motor_Enable enable) {
  if (enable == MOTOR_ON) {
    GPIO_SetBits(motor_struct->enablePort, motor_struct->enablePin);
  } else {
    GPIO_ResetBits(motor_struct->enablePort, motor_struct->enablePin);
  }
}
