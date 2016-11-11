#include "stm32f10x.h"

#include "PWM_Output.h"
#include "motor_control.h"


int main (void)
{
  
  // for PWM test, TIM3-CH1 --> PA06, TIM3-CH2 --> PA07 (no remap)
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
  
  PWM_TypeDef pwm1;
  PWM_TypeDef pwm2;
  Motor_TypeDef motor;
  
  pwm1.outputPin = GPIO_Pin_6;
  pwm1.outputPinPort = GPIOA;
  pwm1.speed = GPIO_Speed_50MHz;
  pwm1.timer = TIM3;
  pwm1.timerChannel = TIM_Channel_1;
  
  pwm2.outputPin = GPIO_Pin_7;
  pwm2.outputPinPort = GPIOA;
  pwm2.speed = GPIO_Speed_50MHz;
  pwm2.timer = TIM3;
  pwm2.timerChannel = TIM_Channel_2;
  
  motor.pwm1 = &pwm1;
  motor.pwm2 = &pwm2;
  
  motorInit(&motor);
  motorCmd(&motor, 30);
  
 	while (1);
}
