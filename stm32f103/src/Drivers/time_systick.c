#include <stdint.h>
#include "time_systick.h"

void initSystick(void) {
  timeMicros = 0;
  while (SysTick_Config(SystemCoreClock / SYSTICK_MICROS) != 0);
  NVIC_SetPriority(SysTick_IRQn, 0);
}

uint64_t micros(void) {
  return timeMicros;
}

// Systick's interruption, add things here if you feel like to
void SysTick_Handler(void) {
  timeMicros++;
}
