#include "motor_control.h"

void motorInit(motorInitTypeDef* init_struct) {
  PWM_InitTypeDef pwm1;
  PWM_InitTypeDef pwm2;
  
  pwm1.speed = init_struct->gpioSpeed;
  pwm1.mode = PWM_MODE_1;
  pwm1.dutyCyclePercent = MOTOR_PWM_DEFAULT_DUTY_CYCLE;
  pwm1.outputPin = init_struct->pwmPin1;
  pwm1.outputPinPort = init_struct->pwmPort1;
  pwm1.periodUs = MOTOR_PWM_PERIOD_US;
  pwm1.timer = init_struct->pwmTimer;
  pwm1.timerChannel = init_struct->pwm1TimerChannel;
  
  pwm2.speed = init_struct->gpioSpeed;
  pwm2.mode = PWM_MODE_2;
  pwm2.dutyCyclePercent = MOTOR_PWM_DEFAULT_DUTY_CYCLE;
  pwm2.outputPin = init_struct->pwmPin2;
  pwm2.outputPinPort = init_struct->pwmPort2;
  pwm2.periodUs = MOTOR_PWM_PERIOD_US;
  pwm2.timer = init_struct->pwmTimer;
  pwm2.timerChannel = init_struct->pwm2TimerChannel;
  
  PWM_initialize(&pwm1);
  PWM_initialize(&pwm2);
}


void motorCmd(motorInitTypeDef* motor_struct, int16_t speed) {
  if (speed >
}