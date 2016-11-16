#include "us_sensor.h"
#include "time_systick.h"
#include "sensor_tri.h"


Sensor_IT_TypeDef structSensor_US_AV1;
Sensor_Tri_TypeDef structSensor_US_Tri;

uint64_t	counter[US_NB] = {0};


void US_echo_config(void) {
	structSensor_US_AV1.pin = pin_US_AV1;
	structSensor_US_AV1.port = port_US_AV1;
	structSensor_US_AV1.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_US_AV1.gpioMode = GPIO_Mode_IPD;
	structSensor_US_AV1.triggerType = EXTI_Trigger_Rising_Falling;
	structSensor_US_AV1.priority = preemptionPrio_US_AV1;
	Sensor_IT_Config(&structSensor_US_AV1);
}

void US_tri_config(void) {
	structSensor_US_Tri.pin = pin_US_TRI;
	structSensor_US_Tri.port = port_US_TRI;
	structSensor_US_Tri.gpioSpeed = GPIO_Speed_50MHz;
	structSensor_US_Tri.gpioMode = GPIO_Mode_Out_PP;
	Sensor_Tri_Config(&structSensor_US_Tri);
}

void trig(void) {
	GPIO_WriteBit(structSensor_US_Tri.port, structSensor_US_Tri.pin, Bit_SET);
}

void untrig(void) {
	GPIO_WriteBit(structSensor_US_Tri.port, structSensor_US_Tri.pin, Bit_RESET);
}

__weak void US_Callback(int pos) {}

void US_EXTI_Callback (uint16_t GPIO_Pin) {
	static int state[US_NB] = {0};
	static uint64_t time_rising[US_NB] = {0};
	int US_Pos = GPIO_Pin_2_int(GPIO_Pin);
	if (US_Pos != -1) {
		if (state[US_Pos] == 0) {
			state[US_Pos] = 1;
			time_rising[US_Pos] = micros();
		} else {
			state[US_Pos] = 0;
			counter[US_Pos] = micros() - time_rising[US_Pos];
			US_Callback(US_Pos);
		}
	}
}

 uint64_t US_pulse_duration(int US_Pos) {
	if (US_Pos != -1)
		return counter[US_Pos];
	else return 0;
}


int GPIO_Pin_2_int(uint16_t GPIO_Pin) {
  if(GPIO_Pin == pin_US_AV1) return US_AV1;
	else if(GPIO_Pin == pin_US_AV2) return US_AV2;
	else if(GPIO_Pin == pin_US_AV3) return US_AV3;
	else if(GPIO_Pin == pin_US_AR1) return US_AR1;
	else if(GPIO_Pin == pin_US_AR2) return US_AR2;
	else if(GPIO_Pin == pin_US_AR3) return US_AR3;
	else return -1;
}
