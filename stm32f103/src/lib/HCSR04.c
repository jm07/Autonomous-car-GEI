#include "HCSR04.h"

HCSR04_InitReturnType HCSR04_initialize(HCSR04_InitTypeDef* init_struct) {
  GPIO_InitTypeDef echoPin;
  GPIO_InitTypeDef trigPin;
  TIM_ICInitTypeDef inputCaptureInit;
  uint16_t prescalerVal = 0;
  
  // configure echo pin
  echoPin.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  echoPin.GPIO_Pin = init_struct->echoPin;
  echoPin.GPIO_Speed = init_struct->speed;
  GPIO_Init(init_struct->echoPinPort, &echoPin);
  
  // configure trig pin
  trigPin.GPIO_Mode = GPIO_Mode_Out_PP;
  trigPin.GPIO_Pin = init_struct->trigPin;
  trigPin.GPIO_Speed = init_struct->speed;
  GPIO_Init(init_struct->trigPinPort, &trigPin);
  
  prescalerVal = (uint16_t)(SystemCoreClock / 1000000) - 1;
  TIM_PrescalerConfig(init_struct->timerForEchoPin, prescalerVal, TIM_PSCReloadMode_Immediate);
  
  // configure timer for echo pin
  inputCaptureInit.TIM_Channel = init_struct->timerChannelForEchoPin;
  inputCaptureInit.TIM_ICFilter = TIM_NO_FILTER;
  inputCaptureInit.TIM_ICPolarity = TIM_ICPolarity_Rising;
  inputCaptureInit.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  inputCaptureInit.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_PWMIConfig(init_struct->timerForEchoPin, &inputCaptureInit);
  
  TIM_SelectSlaveMode(init_struct->timerForEchoPin, TIM_SlaveMode_Reset);
  TIM_SelectMasterSlaveMode(init_struct->timerForEchoPin, TIM_MasterSlaveMode_Enable);
  
  if (init_struct->timerChannelForEchoPin == TIM_Channel_1) {
    TIM_SelectInputTrigger(init_struct->timerForEchoPin, TIM_TS_TI1FP1);
    TIM_ITConfig(init_struct->timerForEchoPin, TIM_IT_CC1, ENABLE);
  } else if (init_struct->timerChannelForEchoPin == TIM_Channel_2) {
    TIM_SelectInputTrigger(init_struct->timerForEchoPin, TIM_TS_TI2FP2);
    TIM_ITConfig(init_struct->timerForEchoPin, TIM_IT_CC2, ENABLE);
  } else {
    return HCSR04_NOT_CHANNEL_1_2;
  }
  
  TIM_Cmd(init_struct->timerForEchoPin, ENABLE);
  
  return HCSR04_INIT_OK;
}

void HRSR04_setTrig(HCSR04_InitTypeDef* init_struct) {
  GPIO_SetBits(init_struct->trigPinPort, init_struct->trigPin);
}

void HRSR04_resetTrig(HCSR04_InitTypeDef* init_struct) {
  GPIO_ResetBits(init_struct->trigPinPort, init_struct->trigPin);
}
