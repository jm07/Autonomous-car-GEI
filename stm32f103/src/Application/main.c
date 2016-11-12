#include "hall_sensor.h"
#include "PWM_Output.h"
#include "motor_control.h"
#include "tim_mapping.h"

Motor_TypeDef motor;
__IO int cmd = 55;
__IO int g = 0;
__IO int d = 0;

int main(void) {
  /*
  Motor_TypeDef motor_av;
	Hall_Config();
  directionInit(motor_av);
  cmdDirection(motor_av, LEFT);
	while(1){
    if (cmd == 1) cmdDirection(motor_av, LEFT);
    else if (cmd == 2) cmdDirection(motor_av, RIGHT);
    else cmdDirection(motor_av, STOP);
  }
  */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
  
  PWM_TypeDef pwm1;
  PWM_TypeDef pwm2;
  
  TIM_CH timPwm1;
  TIM_CH timPwm2;
  GPIO_Pin gpioPwm1;
  GPIO_Pin gpioPwm2;
  
  timPwm1.timer = TIM3;
  timPwm2.timer = TIM3;
  timPwm1.channel = TIM_Channel_1;
  timPwm2.channel = TIM_Channel_2;
  
  gpioPwm1 = timMap(timPwm1, NO_REMAP);
  gpioPwm2 = timMap(timPwm2, NO_REMAP);
  
	Hall_Config();
  
  pwm1.outputPin = gpioPwm1.pin;
  pwm1.outputPinPort = gpioPwm1.port;
  pwm1.speed = GPIO_Speed_50MHz;
  pwm1.timer = TIM3;
  pwm1.timerChannel = TIM_Channel_1;
  
  pwm2.outputPin = gpioPwm2.pin;
  pwm2.outputPinPort = gpioPwm2.port;
  pwm2.speed = GPIO_Speed_50MHz;
  pwm2.timer = TIM3;
  pwm2.timerChannel = TIM_Channel_2;
  
  motor.pwm1 = &pwm1;
  motor.pwm2 = &pwm2;
  
  motorInit(&motor);
  motorCmd(&motor, cmd);
  
  while(1) {/*
    if (cmd == 1) motorCmd(&motor, 30);
    else if (cmd == 2) motorCmd(&motor, -30);
    else motorCmd(&motor, 0);*/
    motorCmd(&motor, cmd);
  }
}

void Hall_AVG_Callback(void) {
  motorCmd(&motor, 45);
  cmd = 45;
  g++;
}
void Hall_AVD_Callback(void) {
  motorCmd(&motor, 45);
  cmd = 45;
  d++;
}

