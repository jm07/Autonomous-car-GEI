#include "stm32f10x.h"

__IO unsigned long long time = 0;

int main(void) {
  NVIC_SetPriority(SysTick_IRQn, 0);
  while (SysTick_Config(SystemCoreClock / 1000000) != 0);
  while(1);
}

void SysTick_Handler(void) {
  time++;
}