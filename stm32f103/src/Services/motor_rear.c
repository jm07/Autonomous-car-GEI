#include "motor_rear.h"

Motor_TypeDef motor_rear;

void initRearMotor(void) {
  PWM_TypeDef pwm1;
  PWM_TypeDef pwm2;
  
  pwm1.outputPin = REAR_MOTOR_IN1_PIN;
  pwm1.outputPinPort = REAR_MOTOR_IN1_PORT;
  pwm1.speed = GPIO_SPEED;
  pwm1.timer = REAR_MOTOR_TIMER;
  pwm1.timerChannel = REAR_MOTOR_IN1_CHANNEL;
  
  pwm2.outputPin = REAR_MOTOR_IN2_PIN;
  pwm2.outputPinPort = REAR_MOTOR_IN2_PORT;
  pwm2.speed = GPIO_SPEED;
  pwm2.timer = REAR_MOTOR_TIMER;
  pwm2.timerChannel = REAR_MOTOR_IN2_CHANNEL;
  
  motor_rear.pwm1 = pwm1;
  motor_rear.pwm2 = pwm2;
  motor_rear.enablePin = REAR_MOTOR_EN_PIN;
  motor_rear.enablePort = REAR_MOTOR_EN_PORT;
  
  motorInit(&motor_rear);
}

void commandRearMotor(int speed) {
  motorCmd(&motor_rear, speed);
}

void enableRearMotor(void) {
  motorEnable(&motor_rear, MOTOR_ON);
}

void disableRearMotor(void) {
  motorEnable(&motor_rear, MOTOR_OFF);
}