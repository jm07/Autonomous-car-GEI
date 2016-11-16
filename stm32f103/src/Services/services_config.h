#ifndef _SERVICE_CONFIG_H_
#define _SERVICE_CONFIG_H_

#include "stm32f10x_gpio.h"
#include "time_systick.h"

// Global definitions
#define GPIO_SPEED  GPIO_Speed_50MHz

// ------------------------------------------- //
// ------------- Ultrasonic sensors ---------- //
// ------------------------------------------- //

// Number of ultra sonic sensors
#define ULTRASONIC_NB 6

// All ultrasonic sensor interrupts share the same priority
#define ULTRASONIC_PRIO 10

// All ultrasonic sensors share the same trigger pin
#define ULTRASONIC_TRIG_PIN	GPIO_Pin_6
#define ULTRASONIC_TRIG_PORT	GPIOC

// Front center
#define ULTRASONIC_AVC_ECHO_PIN	GPIO_Pin_8
#define ULTRASONIC_AVC_ECHO_PORT	GPIOC

// Front left
#define ULTRASONIC_AVG_ECHO_PIN	GPIO_Pin_2
#define ULTRASONIC_AVG_ECHO_PORT	GPIOC

// Front right
#define ULTRASONIC_AVD_ECHO_PIN	GPIO_Pin_3
#define ULTRASONIC_AVD_ECHO_PORT	GPIOC

// Rear center
#define ULTRASONIC_ARC_ECHO_PIN	GPIO_Pin_4
#define ULTRASONIC_ARC_ECHO_PORT	GPIOC

// Rear left
#define ULTRASONIC_ARG_ECHO_PIN	GPIO_Pin_7
#define ULTRASONIC_ARG_ECHO_PORT	GPIOC

// Rear right
#define ULTRASONIC_ARD_ECHO_PIN	GPIO_Pin_8
#define ULTRASONIC_ARD_ECHO_PORT	GPIOC


// ------------------------------------------- //
// ---------------- Hall sensors-------------- //
// ------------------------------------------- //

// Number of hall sensors
#define HALL_NB 4

// All hall sensor interrupts share the same priority
#define HALL_PRIO 15

// Front left
#define HALL_AVG_PIN  GPIO_Pin_9
#define HALL_AVG_PORT GPIOC

// Front right
#define HALL_AVD_PIN  GPIO_Pin_5
#define HALL_AVD_PORT GPIOC

// Rear left
#define HALL_ARG_PIN  GPIO_Pin_10
#define HALL_ARG_PORT GPIOC

// Rear right
#define HALL_ARD_PIN  GPIO_Pin_15
#define HALL_ARD_PORT GPIOC


// ------------------------------------------- //
// ---------------- Rear motor --------------- //
// ------------------------------------------- //

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


// ------------------------------------------- //
// ---------------- Front motor -------------- //
// ------------------------------------------- //

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

// ------------------------------------------- //
// -------------- Init function -------------- //
// ------------------------------------------- //
void initServices(void);

#endif // _SERVICE_CONFIG_H_
