
#include "us_sensor.h"
#include "time_systick.h"
#include "sensor_IT.h"
#include "callback_functions.h"
#include "services_config.h"


Sensor_IT_TypeDef structSensor_US_AVC;

uint64_t	counter[ULTRASONIC_NB] = {0};

static void ultrasonic_trigger(void);

static void ultrasonic_untrigger(void);

static void ultrasonic_config_echo_pin(void);

static void ultrasonic_config_trig_pin(void);


void ultrasonic_config_echo_pin(void){
	structSensor_US_AVC.pin = ULTRASONIC_AVC_ECHO_PIN;
	structSensor_US_AVC.port = ULTRASONIC_AVC_ECHO_PORT;
	structSensor_US_AVC.gpioSpeed = GPIO_SPEED;
	structSensor_US_AVC.gpioMode = GPIO_Mode_IPD;
	structSensor_US_AVC.triggerType = EXTI_Trigger_Rising_Falling;
	structSensor_US_AVC.priority = ULTRASONIC_PRIO;
	Sensor_IT_Config(&structSensor_US_AVC);
}

void ultrasonic_config_trig_pin(void){
	GPIO_InitTypeDef GPIO_InitStructure;

   GPIO_InitStructure.GPIO_Pin = ULTRASONIC_TRIG_PIN;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_SPEED;

   GPIO_Init(ULTRASONIC_TRIG_PORT, &GPIO_InitStructure);
}

void ultrasonic_config(void){
	ultrasonic_config_echo_pin();
	ultrasonic_config_trig_pin();
}

void ultrasonic_trig_all(void){
	uint64_t t_trig = 0;
	ultrasonic_trigger();
	t_trig = micros();
	while(micros() - t_trig > TEMPS_DUREE){};
	
}

void ultrasonic_trigger(void){
	GPIO_WriteBit(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, Bit_SET);
}

void ultrasonic_untrigger(void){
	GPIO_WriteBit(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, Bit_RESET);
}

__weak void ultrasonic_callback(Ultrasonic_Position pos){}

void ultrasonic_exti_callback (uint16_t GPIO_Pin){
	static int state[ULTRASONIC_NB] = {0};
	static uint64_t time_rising[ULTRASONIC_NB] = {0};
	Ultrasonic_Position position = get_ultrasonic_position(GPIO_Pin);
	if(state[position] == 0){
		state[position] = 1;
		time_rising[position] = micros();
	}else{
		state[position] = 0;
		counter[position] = micros() - time_rising[position];
		ultrasonic_callback(position);
	}
}

 uint64_t ultrasonic_get_pulse_duration(Ultrasonic_Position pos){
	if(pos != -1)
		return counter[pos];
	else return 0;
}
