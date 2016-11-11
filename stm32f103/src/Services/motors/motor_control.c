#include "motor_control.h"

void motorInit(Motor_TypeDef* init_struct) {
  init_struct->pwm1->mode = PWM_MODE_1;
  init_struct->pwm1->dutyCyclePercent = MOTOR_PWM_DEFAULT_DUTY_CYCLE;
  init_struct->pwm1->periodUs = MOTOR_PWM_PERIOD_US;
  
  init_struct->pwm2->mode = PWM_MODE_2;
  init_struct->pwm2->dutyCyclePercent = MOTOR_PWM_DEFAULT_DUTY_CYCLE;
  init_struct->pwm2->periodUs = MOTOR_PWM_PERIOD_US;
  
  if ((init_struct->pwm1->timer != init_struct->pwm2->timer) || \
      (init_struct->pwm1->speed != init_struct->pwm1->speed)) {
    init_struct->pwm2->timer = init_struct->pwm1->timer;
    init_struct->pwm2->speed = init_struct->pwm1->speed;
  } else {}
  
  PWM_initialize(init_struct->pwm1);
  PWM_initialize(init_struct->pwm2);
}


void motorCmd(Motor_TypeDef* motor_struct, int16_t speed) {
  uint16_t dutyCycle = 0;
  uint16_t dutyCycleRange = (uint16_t)(DUTY_CYCLE_MAX - DUTY_CYCLE_MIN);
  uint16_t speedRange = (uint16_t)(MOTOR_SPEED_MAX - MOTOR_SPEED_MIN);
  int16_t speedAux;
  if (speed > MOTOR_SPEED_MAX) speedAux = MOTOR_SPEED_MAX;
  else if (speed < MOTOR_SPEED_MIN) speedAux = MOTOR_SPEED_MIN;
  else speedAux = speed;
  dutyCycle = (uint16_t)((speedAux - MOTOR_SPEED_MIN) * dutyCycleRange / speedRange + DUTY_CYCLE_MIN);
  PWM_CmdDutyCycle(motor_struct->pwm1, dutyCycle);
  PWM_CmdDutyCycle(motor_struct->pwm2, dutyCycle);
}
