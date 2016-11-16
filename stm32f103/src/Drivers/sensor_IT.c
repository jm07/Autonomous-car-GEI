#include "sensor_IT.h"

#define IF_DEFINE_NUM(n) \
	if (initStructSensor->pin == GPIO_Pin_##n) { \
		GPIO_PinSource_Sensor = GPIO_PinSource##n;\
		EXTI_Line_Sensor = EXTI_Line##n;\
		EXTI_IRQn_Sensor = EXTI##n##_IRQn;\
	}\

#define IF_DEFINE_NUM_2(n,n1,n2) \
	if (initStructSensor->pin == GPIO_Pin_##n) { \
		GPIO_PinSource_Sensor = GPIO_PinSource##n;\
		EXTI_Line_Sensor = EXTI_Line##n;\
		EXTI_IRQn_Sensor = EXTI##n1##_##n2##_IRQn;\
	}\

// Private functions
static void GPIO_Configuration(Sensor_IT_TypeDef* initStructSensor);
static void EXTI_Config(Sensor_IT_TypeDef* initStructSensor);

//public functions

void Sensor_IT_Config(Sensor_IT_TypeDef* initStructSensor) {
	// Configure the GPIO port
	GPIO_Configuration(initStructSensor);

	//Configure external interruption
	EXTI_Config(initStructSensor);
}


unsigned int Sensor_IT_Read(Sensor_IT_TypeDef* structSensor) {
	return GPIO_ReadInputDataBit(structSensor->port, structSensor->pin);
}

// Private functions
void GPIO_Configuration(Sensor_IT_TypeDef* initStructSensor) {
   GPIO_InitTypeDef GPIO_InitStructure;

   // GPIO_Pin_Sensor configuration
   GPIO_InitStructure.GPIO_Pin = initStructSensor->pin;
   GPIO_InitStructure.GPIO_Mode = initStructSensor->gpioMode;
   GPIO_InitStructure.GPIO_Speed = initStructSensor->gpioSpeed;

   GPIO_Init(initStructSensor->port, &GPIO_InitStructure);
}

void EXTI_Config(Sensor_IT_TypeDef* initStructSensor) {
	EXTI_InitTypeDef 	EXTI_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	uint8_t 					GPIO_PortSource_Sensor;
	uint8_t 					GPIO_PinSource_Sensor;
	uint32_t 					EXTI_Line_Sensor;
	uint8_t 					EXTI_IRQn_Sensor;

	if (initStructSensor->port == GPIOA) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOA;
	} else if (initStructSensor->port == GPIOB) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOB;
	} else if (initStructSensor->port == GPIOC) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOC;
	} else if(initStructSensor->port == GPIOD) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOD;
	} else if(initStructSensor->port == GPIOE) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOE;
	} else if(initStructSensor->port == GPIOF) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOF;
	} else if(initStructSensor->port == GPIOG) {
			GPIO_PortSource_Sensor = GPIO_PortSourceGPIOG;
	}

  IF_DEFINE_NUM(0)
	else IF_DEFINE_NUM(1)
	else IF_DEFINE_NUM(2)
	else IF_DEFINE_NUM(3)
	else IF_DEFINE_NUM(4)
	else IF_DEFINE_NUM_2(5,9,5)
	else IF_DEFINE_NUM_2(6,9,5)
	else IF_DEFINE_NUM_2(7,9,5)
	else IF_DEFINE_NUM_2(8,9,5)
	else IF_DEFINE_NUM_2(9,9,5)
	else IF_DEFINE_NUM_2(10,15,10)
	else IF_DEFINE_NUM_2(11,15,10)
	else IF_DEFINE_NUM_2(12,15,10)
	else IF_DEFINE_NUM_2(13,15,10)
	else IF_DEFINE_NUM_2(14,15,10)
	else IF_DEFINE_NUM_2(15,15,10)

	GPIO_EXTILineConfig(GPIO_PortSource_Sensor,  GPIO_PinSource_Sensor);

	EXTI_InitStructure.EXTI_Line = EXTI_Line_Sensor;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = initStructSensor->triggerType;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI_IRQn_Sensor;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = initStructSensor->priority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
