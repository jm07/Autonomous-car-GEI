#include "PWM_Output.h"

PWM_InitReturnType PWM_initialize(PWM_InitTypeDef* init_struct) {
  TIM_TimeBaseInitTypeDef timeBaseInit;
  TIM_OCInitTypeDef outputCaptureInit;
  GPIO_InitTypeDef pinInit;
  uint16_t prescalerVal = 0;
  
  // configure output pin
  pinInit.GPIO_Mode = GPIO_Mode_AF_PP;
  pinInit.GPIO_Pin = init_struct->outputPin;
  pinInit.GPIO_Speed = init_struct->speed;
  GPIO_Init(init_struct->outputPinPort, &pinInit);
  
  // configure timer output compare
  prescalerVal = (uint16_t)(SystemCoreClock / COUNTER_CLOCK_FREQ_1MHz) - 1; 
  timeBaseInit.TIM_Period = init_struct->periodUs;
  timeBaseInit.TIM_Prescaler = prescalerVal;
  timeBaseInit.TIM_ClockDivision = TIM_CKD_DIV1;
  timeBaseInit.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(init_struct->timer, &timeBaseInit);
  
  // configure a timer channel as pwm output mode 1
  outputCaptureInit.TIM_OCMode = TIM_OCMode_PWM1;
  outputCaptureInit.TIM_OutputState = TIM_OutputState_Enable;
  outputCaptureInit.TIM_Pulse = (uint16_t)(init_struct->periodUs * init_struct->dutyCyclePercent / 100) - 1;
  outputCaptureInit.TIM_OCPolarity = TIM_OCPolarity_High;
  if (init_struct->timerChannel == TIM_Channel_1) {
    TIM_OC1Init(init_struct->timer, &outputCaptureInit);
    TIM_OC1PreloadConfig(init_struct->timer, TIM_OCPreload_Enable);
  } else if (init_struct->timerChannel == TIM_Channel_2) {
    TIM_OC2Init(init_struct->timer, &outputCaptureInit);
    TIM_OC2PreloadConfig(init_struct->timer, TIM_OCPreload_Enable);
  } else if (init_struct->timerChannel == TIM_Channel_3) {
    TIM_OC3Init(init_struct->timer, &outputCaptureInit);
    TIM_OC3PreloadConfig(init_struct->timer, TIM_OCPreload_Enable);
  } else if (init_struct->timerChannel == TIM_Channel_4) {
    TIM_OC4Init(init_struct->timer, &outputCaptureInit);
    TIM_OC4PreloadConfig(init_struct->timer, TIM_OCPreload_Enable);
  } else return PWM_NOT_CHANNEL_1_2_3_4;
  TIM_ARRPreloadConfig(init_struct->timer, ENABLE);
  TIM_Cmd(init_struct->timer, ENABLE);
  
  return PWM_INIT_OK;
}