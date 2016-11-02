#include "stm32f10x.h"

#include "HCSR04.h"

int main (void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  HCSR04_InitTypeDef HCSR04;
  
  HCSR04.echoPin = GPIO_Pin_4;
  HCSR04.echoPinPort = GPIOA;
  HCSR04.trigPin = GPIO_Pin_5;
  HCSR04.trigPinPort = GPIOA;
  HCSR04.speed = GPIO_Speed_50MHz;
  HCSR04.timerForEchoPin = TIM2;
  HCSR04.timerChannelForEchoPin = TIM_Channel_1;
  
  HCSR04_Initialize(&HCSR04);
	while (1);
}
