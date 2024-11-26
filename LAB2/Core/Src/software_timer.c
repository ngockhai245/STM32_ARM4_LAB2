/*
 * software_timer.c
 *
 *  Created on: Nov 24, 2024
 *      Author: LENOVO
 */

#include "software_timer.h"
#include "led7_seg.h"

#define TIMER_CYCLE_2 1
#define COUNTER_SCAN_1HZ 500
#define COUNTER_SCAN_25HZ 20
#define COUNTER_SCAN_100HZ 5

int counter_scan = COUNTER_SCAN_25HZ;


// software timer variable
int flag_timer2 = 0;
int timer2_counter = 0;
int timer2_MUL = 0;



// init timer interrupt
void timer_init(){
	HAL_TIM_Base_Start_IT(&htim2);
}

/**
  * @brief  Set duration of software timer interrupt
  * @param  duration Duration of software timer interrupt
  * @retval None
  */
void setTimer2(uint16_t duration){
	timer2_MUL = duration/TIMER_CYCLE_2;
	timer2_counter = timer2_MUL;
	flag_timer2 = 0;
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2){
		if (timer2_counter > 0){
			timer2_counter--;
			if (timer2_counter == 0){
				flag_timer2 = 1;
			}
		}
		// 1ms interrupt here
		// led7_Scan();
		if (counter_scan > 0){
			counter_scan--;
			if (counter_scan == 0){
				led7_Scan();
				counter_scan = COUNTER_SCAN_25HZ;
			}
		}
	}
}


