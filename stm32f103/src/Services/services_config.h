#ifndef _SERVICE_CONFIG_H_
#define _SERVICE_CONFIG_H_

#include "stm32f10x_gpio.h"
#include "time_systick.h"

#define GPIO_SPEED  GPIO_Speed_50MHz

// ---------------------- //
// ----- Rear motor ----- //
// ---------------------- //

// IN1 pin
#define REAR_MOTOR_IN1_PIN        GPIO_Pin_0
#define REAR_MOTOR_IN1_PORT       GPIOB
#define REAR_MOTOR_IN1_CHANNEL    TIM_Channel_3

// IN2 pin
#define REAR_MOTOR_IN2_PIN        GPIO_Pin_1
#define REAR_MOTOR_IN2_PORT       GPIOB
#define REAR_MOTOR_IN2_CHANNEL    TIM_Channel_4

// EN pin
#define REAR_MOTOR_EN_PIN         GPIO_Pin_4
#define REAR_MOTOR_EN_PORT        GPIOA

// Timer
#define REAR_MOTOR_TIMER          TIM3


// ---------------------- //
// ---- Front motor ----- //
// ---------------------- //

// IN1 pin
#define FRONT_MOTOR_IN1_PIN       GPIO_Pin_6
#define FRONT_MOTOR_IN1_PORT      GPIOA
#define FRONT_MOTOR_IN1_CHANNEL   TIM_Channel_1

// IN2 pin
#define FRONT_MOTOR_IN2_PIN       GPIO_Pin_7
#define FRONT_MOTOR_IN2_PORT      GPIOA
#define FRONT_MOTOR_IN2_CHANNEL   TIM_Channel_2

// EN pin
#define FRONT_MOTOR_EN_PIN        GPIO_Pin_5
#define FRONT_MOTOR_EN_PORT       GPIOA

// Timer
#define FRONT_MOTOR_TIMER         TIM3

// Speed
#define FRONT_MOTOR_SPEED         30


// ----- Init function ----- //
void initServices(void); 

#endif // _SERVICE_CONFIG_H_
