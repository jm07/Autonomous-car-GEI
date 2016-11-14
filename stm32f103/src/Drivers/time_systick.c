#include "time_systick.h"

void initSystick(void) {
  timeMicros = 0;
  NVIC_SetPriority(SysTick_IRQn, 0);
  while (SysTick_Config(SystemCoreClock / SYSTICK_MICROS) != 0);
}

unsigned long long micros(void) {
  return timeMicros;
}

void SysTick_Handler(void) {
  timeMicros++;
}