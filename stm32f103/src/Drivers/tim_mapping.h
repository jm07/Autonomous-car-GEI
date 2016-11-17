#ifndef _TIM_MAPPING_H_
#define _TIM_MAPPING_H_

#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
} GPIO_Pin;

typedef struct {
    TIM_TypeDef* timer;
    uint16_t channel;
} TIM_CH;

typedef enum {
    NO_REMAP,
    REMAP
} RemapMode;

GPIO_Pin timMap(TIM_CH timerChannel, RemapMode remap_mode) {
    GPIO_Pin gpioPin;
    TIM_TypeDef* timer = timerChannel.timer;
    uint16_t channel = timerChannel.channel;
    GPIO_TypeDef* port;
    uint16_t pin;
    if (timer == TIM1) {
        port = GPIOA;
        if (channel == TIM_Channel_1) pin = GPIO_Pin_8;
        else if (channel == TIM_Channel_2) pin = GPIO_Pin_9;
        else if (channel == TIM_Channel_3) pin = GPIO_Pin_10;
        else if (channel == TIM_Channel_4) pin = GPIO_Pin_11;
        else {}
    } else if (timer == TIM2) {
        if (remap_mode == NO_REMAP) {
            port = GPIOA;
            if (channel == TIM_Channel_1) pin = GPIO_Pin_0;
            else if (channel == TIM_Channel_2) pin = GPIO_Pin_1;
            else if (channel == TIM_Channel_3) pin = GPIO_Pin_2;
            else if (channel == TIM_Channel_4) pin = GPIO_Pin_3;
            else {}
        } else {
            if (channel == TIM_Channel_1) {
                port = GPIOA;
                pin = GPIO_Pin_15;
            }
            else if (channel == TIM_Channel_2) {
                port = GPIOB;
                pin = GPIO_Pin_3;
            }
            else if (channel == TIM_Channel_3) {
                port = GPIOB;
                pin = GPIO_Pin_10;
            }
            else if (channel == TIM_Channel_4) {
                port = GPIOB;
                pin = GPIO_Pin_11;
            }
            else {}
        }
    } else if (timer == TIM3) {
        if (remap_mode == NO_REMAP) {
            if (channel == TIM_Channel_1) {
                port = GPIOA;
                pin = GPIO_Pin_6;
            }
            else if (channel == TIM_Channel_2) {
                port = GPIOA;
                pin = GPIO_Pin_7;
            }
            else if (channel == TIM_Channel_3) {
                port = GPIOB;
                pin = GPIO_Pin_0;
            }
            else if (channel == TIM_Channel_4) {
                port = GPIOB;
                pin = GPIO_Pin_1;
            }
            else {}
        } else {
            port = GPIOC;
            if (channel == TIM_Channel_1) pin = GPIO_Pin_6;
            else if (channel == TIM_Channel_2) pin = GPIO_Pin_7;
            else if (channel == TIM_Channel_3) pin = GPIO_Pin_8;
            else if (channel == TIM_Channel_4) pin = GPIO_Pin_9;
            else {}
        }
    } else if (timer == TIM4) {
        if (remap_mode == NO_REMAP) {
            port = GPIOB;
            if (channel == TIM_Channel_1) pin = GPIO_Pin_6;
            else if (channel == TIM_Channel_2) pin = GPIO_Pin_7;
            else if (channel == TIM_Channel_3) pin = GPIO_Pin_8;
            else if (channel == TIM_Channel_4) pin = GPIO_Pin_9;
            else {}
        } else {
            port = GPIOD;
            if (channel == TIM_Channel_1) pin = GPIO_Pin_12;
            else if (channel == TIM_Channel_2) pin = GPIO_Pin_13;
            else if (channel == TIM_Channel_3) pin = GPIO_Pin_14;
            else if (channel == TIM_Channel_4) pin = GPIO_Pin_15;
            else {}
        }
    } else {}
    gpioPin.pin = pin;
    gpioPin.port = port;
    return gpioPin;
}

#endif // _TIM_MAPPING_H_