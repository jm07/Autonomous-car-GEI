#include "us_sensor.h"
#include "time_systick.h"
#include "sensor_IT.h"
#include "callback_functions.h"
#include "services_config.h"


Sensor_IT_TypeDef structSensor_US_AV1;

uint64_t	counter[US_NB] = {0};


void US_echo_config(void){
	structSensor_US_AV1.outputPin = pin_US_AV1;
	structSensor_US_AV1.outputPinPort = port_US_AV1;
	structSensor_US_AV1.speed = GPIO_Speed_50MHz;
	structSensor_US_AV1.mode = GPIO_Mode_IPD;
	structSensor_US_AV1.triggerType = EXTI_Trigger_Rising_Falling;
	structSensor_US_AV1.NVIC_IRQChannelPreemptionPriority = preemptionPrio_US_AV1;
	structSensor_US_AV1.NVIC_IRQChannelSubPriority = subPrio_US_AV1;
	Sensor_IT_Config(&structSensor_US_AV1);	
}

void US_tri_config(void){
	GPIO_InitTypeDef GPIO_InitStructure;

   GPIO_InitStructure.GPIO_Pin = pin_US_TRI;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_SPEED;

   GPIO_Init(port_US_TRI, &GPIO_InitStructure);
}

void trig(void){
	GPIO_WriteBit(port_US_TRI, pin_US_TRI, Bit_SET);
}

void untrig(void){
	GPIO_WriteBit(port_US_TRI, pin_US_TRI, Bit_RESET);
}

__weak void US_Callback(US_Pos_t pos){}

void US_EXTI_Callback (uint16_t GPIO_Pin){
	static int state[US_NB] = {0};
	static uint64_t time_rising[US_NB] = {0};
	US_Pos_t US_Pos = US_Pin_2_int(GPIO_Pin);
	if(state[US_Pos] == 0){
		state[US_Pos] = 1;
		time_rising[US_Pos] = micros();
	}else{  					
		state[US_Pos] = 0;
		counter[US_Pos] = micros() - time_rising[US_Pos];
		US_Callback(US_Pos);
	}
}

 uint64_t US_pulse_duration(US_Pos_t US_Pos){
	if(US_Pos != -1)
		return counter[US_Pos];
	else return 0;
}


