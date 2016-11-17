#ifndef _TIME_SYSTICK_H_
#define _TIME_SYSTICK_H_

#include "stm32f10x.h"

#define SYSTICK_MICROS  1000000

static uint64_t timeMicros;

void initSystick(void);
uint64_t micros(void);

#endif // _TIME_SYSTICK_H_
