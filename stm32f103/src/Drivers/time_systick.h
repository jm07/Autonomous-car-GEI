#ifndef _TIME_SYSTICK_H_
#define _TIME_SYSTICK_H_

#include "stm32f10x.h"

#define SYSTICK_MICROS  1000000

static unsigned long long timeMicros;

void initSystick(void);
unsigned long long micros(void);

#endif // _TIME_SYSTICK_H_
