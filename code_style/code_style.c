#include "code_style.h"

/**
 * Documentation supplementaire
 */
AmandineReturnType SensorName_initialize(SensorName_TypeDef* sensor) {
    // creation des variables
    GPIO_InitTypeDef gpioPin;
    TIM_TimeBaseInitTypeDef timerBase;

    // affectation des variables
    gpioPin.GPIO_Pin = sensor->pinNumber;
    timer.TIM_Prescaler = sensor->candy.alexCandy;

    // initialisation des peripheriques
    GPIO_Init(sensor->portName, &gpioPin);
    TIM_TimeBaseInit(sensor->timer, &timerBase);

    // un petit check si necessaire
    // par exemple au cas ou on choisit un channel qui n'existe pas
    if (sensor->type == DJELASSI) {
        // holy shit it's Djelassi!!!
        return DJELASSI;
    } else if (sensor->type == MAYIMA) {
        // nah it's Mayima, it's ok
        return MAYIMA;
    } else if (sensor->type == SOMETHING) {
        // we're cool right?
        return SOMETHING;
    } else {
        // no not Moustaid again...
        return DEFINITELY_NOT_MOUSTAID
    }
}


/**
 * Documentation supplementaire
 */
 uint16_t SensorName_read(SensorName_TypeDef* sensor) {
     return sensor->speed; // brooommm
 }

 
/**
 * Documentation supplementaire
 */
 void SensorName_cmdCandy(SensorName_TypeDef* sensor, CandyForAlex candy_written_like_this) {
     sensor->candy = candy_written_like_this;
     someSimpleFunction(candy_written_like_this);
 }

 
/**
 * Documentation supplementaire
 */
 void SensorName_cmdSpeed(SensorName_TypeDef* sensor, uint16_t speed) {
     sensor->speed = speed;
     anotherFunctionAppearsFromNowhere(&sensor);
 }