#include "us_sensor.h"
#include "time_systick.h"
#include "sensor_IT.h"
#include "callback_functions.h"
#include "services_config.h"


Sensor_IT_TypeDef structSensor_US_AVC;

uint64_t	counter[ULTRASONIC_NB] = {0};


void US_echo_config(void){
	structSensor_US_AVC.pin = ULTRASONIC_AVC_ECHO_PIN;
	structSensor_US_AVC.port = ULTRASONIC_AVC_ECHO_PORT;
	structSensor_US_AVC.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_US_AVC.gpioMode = GPIO_Mode_IPD;
	structSensor_US_AVC.triggerType = EXTI_Trigger_Rising_Falling;
	structSensor_US_AVC.priority = ULTRASONIC_PRIO;
	Sensor_IT_Config(&structSensor_US_AVC);	
}

void US_tri_config(void){
	GPIO_InitTypeDef GPIO_InitStructure;

   GPIO_InitStructure.GPIO_Pin = ULTRASONIC_TRIG_PIN;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_SPEED;

   GPIO_Init(ULTRASONIC_TRIG_PORT, &GPIO_InitStructure);
}

void trig(void){
	GPIO_WriteBit(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, Bit_SET);
}

void untrig(void){
	GPIO_WriteBit(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, Bit_RESET);
}

__weak void US_Callback(US_Pos_t pos){}

void US_EXTI_Callback (uint16_t GPIO_Pin){
	static int state[ULTRASONIC_NB] = {0};
	static uint64_t time_rising[ULTRASONIC_NB] = {0};
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


