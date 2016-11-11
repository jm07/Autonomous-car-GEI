#include "stm32f10x.h"

#include "HCSR04.h"
#include "PWM_Output.h"
#include "motor_control.h"

__IO float freq = 0.0;
__IO float duty = 0.0;
__IO float pulse = 0.0;
__IO float period = 0.0;

void NVIC_Configuration(void);

int main (void)
{
  // for HC-SR04, echo pin PA04, trig pin PA05
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
  
  // for PWM test, TIM3-CH1 --> PA06, TIM3-CH2 --> PA07 (no remap)
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
  
  HCSR04_InitTypeDef HCSR04;
  PWM_TypeDef pwm1;
  PWM_TypeDef pwm2;
  Motor_TypeDef motor;
  
  NVIC_Configuration();
  
  HCSR04.echoPin = GPIO_Pin_6;
  HCSR04.echoPinPort = GPIOB;
  HCSR04.trigPin = GPIO_Pin_5;
  HCSR04.trigPinPort = GPIOA;
  HCSR04.speed = GPIO_Speed_50MHz;
  HCSR04.timerForEchoPin = TIM4;
  HCSR04.timerChannelForEchoPin = TIM_Channel_1;
  HCSR04_initialize(&HCSR04);
  
  
  pwm1.outputPin = GPIO_Pin_7;
  pwm1.outputPinPort = GPIOA;
  pwm1.periodUs = 52; 
  pwm1.dutyCyclePercent = 30;
  pwm1.speed = GPIO_Speed_50MHz;
  pwm1.mode = PWM_MODE_1;
  pwm1.timer = TIM3;
  pwm1.timerChannel = TIM_Channel_2;
  
  PWM_initialize(&pwm1);
  
  /*
  pwm2.outputPin = GPIO_Pin_6;
  pwm2.outputPinPort = GPIOA;
  pwm2.periodUs = 500; 
  pwm2.dutyCyclePercent = 20;
  pwm2.speed = GPIO_Speed_50MHz;
  pwm2.mode = PWM_MODE_2;
  pwm2.timer = TIM3;
  pwm2.timerChannel = TIM_Channel_1;
  
  motor.pwm1 = &pwm1;
  motor.pwm2 = &pwm2;
  
  motorInit(&motor);
  motorCmd(&motor, -70);
  */
  
 	while (1) {
  };
}

void TIM4_IRQHandler(void) {
  /* Clear TIM3 Capture compare interrupt pending bit */
  TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);
 
  /* Get the Input Capture value */
  pulse = (float)TIM_GetCapture2(TIM4);
  period = (float)TIM_GetCapture1(TIM4);
  if (period != 0) duty = pulse / period;
}

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the TIM3 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
