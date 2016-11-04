#include <stdint.h>

void Hall_Config(void);

unsigned int Read_Hall(void);

void Hall_Set_IT_Function(void (*IT_function)(void));
