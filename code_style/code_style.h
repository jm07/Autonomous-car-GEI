#ifndef _CODE_STYLE_H_
#define _CODE_STYLE_H_

// tous les includes ici
#include "amandine_file.h"
#include "alexandre_file.h"
#include "no_one_file.h"

// tous les constants ici, en majuscule
#define MARCY   0.01f
#define JAMAL   0xBAD0
#define PHAN    NULL
#define JAMARCY (JAMAL + MARCY) 

// structure de donnees
typedef enum {
    DJELASSI,               // 0
    MAYIMA,                 // 1
    SOMETHING,              // 2
    DEFINITELY_NOT_MOUSTAID // 3
} AmandineReturnType;

typedef struct {
    uint16_t alexCandy;
    float alexSize;
} CandyForAlex;

typedef struct {
    uint16_t pinNumber;
    GPIO_TypeDef* portName; // pointeur
    TIM_TypeDef* timer;     // pointeur
    uint16_t channel;
    uint16_t speed;
    CandyForAlex candy;
    int type;
} SensorName_TypeDef;

// declaration des fonctions

/**
 * API documentation (purpose, parameters, return values, pre/postconditions etc.) 
 */
AmandineReturnType SensorName_Initialize(SensorName_TypeDef* sensor);


/**
 * API documentation
 */
uint16_t SensorName_read(SensorName_TypeDef* sensor);


/**
 * API documentation
 */
void SensorName_cmdCandy(SensorName_TypeDef* sensor, CandyForAlex candy_written_like_this);


/**
 * API documentation
 */
void SensorName_cmdSpeed(SensorName_TypeDef* sensor, uint16_t speed);

#endif // _CODE_STYLE_H_
