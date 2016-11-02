#include "stm32f10x.h"

#include "HCSR04.h"
#include "PWM_Output.h"

int main (void)
{
  // for HC-SR04
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  // for PWM test, TIM3-CH2 --> PA07 (no remap)
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
  
  HCSR04_InitTypeDef HCSR04;
  PWM_InitTypeDef pwm;
  
  HCSR04.echoPin = GPIO_Pin_4;
  HCSR04.echoPinPort = GPIOA;
  HCSR04.trigPin = GPIO_Pin_5;
  HCSR04.trigPinPort = GPIOA;
  HCSR04.speed = GPIO_Speed_50MHz;
  HCSR04.timerForEchoPin = TIM2;
  HCSR04.timerChannelForEchoPin = TIM_Channel_1;
  
  HCSR04_initialize(&HCSR04);
  
  pwm.outputPin = GPIO_Pin_7;
  pwm.outputPinPort = GPIOA;
  pwm.periodUs = 100;
  pwm.dutyCyclePercent = 30;
  pwm.speed = GPIO_Speed_50MHz;
  pwm.timer = TIM3;
  pwm.timerChannel = TIM_Channel_2;
  
  PWM_initialize(&pwm);
  
	while (1);
}
