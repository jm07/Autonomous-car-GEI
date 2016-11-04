#include "stm32f10x.h"

#include "HCSR04.h"
#include "PWM_Output.h"

int main (void)
{
  // for HC-SR04, echo pin PA04, trig pin PA05
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  // for PWM test, TIM3-CH1 --> PA06, TIM3-CH2 --> PA07 (no remap)
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
  
  HCSR04_InitTypeDef HCSR04;
  PWM_InitTypeDef pwm1;
  PWM_InitTypeDef pwm2;
  
  /*
  HCSR04.echoPin = GPIO_Pin_4;
  HCSR04.echoPinPort = GPIOA;
  HCSR04.trigPin = GPIO_Pin_5;
  HCSR04.trigPinPort = GPIOA;
  HCSR04.speed = GPIO_Speed_50MHz;
  HCSR04.timerForEchoPin = TIM2;
  HCSR04.timerChannelForEchoPin = TIM_Channel_1;
  HCSR04_initialize(&HCSR04);
  */
  
  pwm1.outputPin = GPIO_Pin_7;
  pwm1.outputPinPort = GPIOA;
  pwm1.periodUs = 500; 
  pwm1.dutyCyclePercent = 20;
  pwm1.speed = GPIO_Speed_50MHz;
  pwm1.mode = PWM_MODE_1;
  pwm1.timer = TIM3;
  pwm1.timerChannel = TIM_Channel_2;
  
  pwm2.outputPin = GPIO_Pin_6;
  pwm2.outputPinPort = GPIOA;
  pwm2.periodUs = 500; 
  pwm2.dutyCyclePercent = 20;
  pwm2.speed = GPIO_Speed_50MHz;
  pwm2.mode = PWM_MODE_2;
  pwm2.timer = TIM3;
  pwm2.timerChannel = TIM_Channel_1;
  
  PWM_initialize(&pwm1);
  PWM_initialize(&pwm2);
  
 	while (1);
}
