#include "time_systick.h"

void initSystick(void) {
  timeMicros = 0;
  while (SysTick_Config(SystemCoreClock / SYSTICK_MICROS) != 0);
  NVIC_SetPriority(SysTick_IRQn, 0);
}

unsigned long long micros(void) {
  return timeMicros;
}

// Systick's interruption, add things here if you feel like to
void SysTick_Handler(void) {
  timeMicros++;
}