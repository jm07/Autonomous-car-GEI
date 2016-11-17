#ifndef _MOTOR_FRONT_H_
#define _MOTOR_FRONT_H_

#include "motor_control.h"
#include "services_config.h"

typedef enum {
  LEFT,
  RIGHT,
  STOP
} Direction;

extern Motor_TypeDef motor_front;

void initFrontMotor(void);
void commandFrontMotor(Direction direction);
void enableFrontMotor(void);
void disableFrontMotor(void);

#endif // _MOTOR_FRONT_H_
