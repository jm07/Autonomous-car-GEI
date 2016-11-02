#include "HCSR04.h"

HCSR04_InitReturnType HCSR04_Initialize(HCSR04_InitTypeDef* init_struct) {
  GPIO_InitTypeDef echoPin;
  GPIO_InitTypeDef trigPin;
  TIM_ICInitTypeDef timerForEchoPin;
  
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
  
  // configure timer for echo pin
  timerForEchoPin.TIM_Channel = init_struct->timerChannelForEchoPin;
  timerForEchoPin.TIM_ICFilter = TIM_NO_FILTER;
  timerForEchoPin.TIM_ICPolarity = TIM_ICPolarity_Rising;
  timerForEchoPin.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  timerForEchoPin.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_PWMIConfig(init_struct->timerForEchoPin, &timerForEchoPin);
  TIM_SelectSlaveMode(init_struct->timerForEchoPin, TIM_SlaveMode_Reset);
  TIM_SelectMasterSlaveMode(init_struct->timerForEchoPin, TIM_MasterSlaveMode_Enable);
  if (init_struct->timerChannelForEchoPin == TIM_Channel_1) {
    TIM_SelectInputTrigger(init_struct->timerForEchoPin, TIM_TS_TI1FP1);
    TIM_ITConfig(init_struct->timerForEchoPin, TIM_IT_CC1, ENABLE);
  } else if (init_struct->timerChannelForEchoPin == TIM_Channel_1) {
    TIM_SelectInputTrigger(init_struct->timerForEchoPin, TIM_TS_TI2FP2);
    TIM_ITConfig(init_struct->timerForEchoPin, TIM_IT_CC2, ENABLE);
  } else {
    return TIM_ONLY_CHANNEL_1_2_ACCEPTED;
  }
  TIM_Cmd(init_struct->timerForEchoPin, ENABLE);
  
  return INIT_OK;
}
