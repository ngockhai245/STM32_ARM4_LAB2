/*
 * software_timer.c
 *
 *  Created on: Nov 24, 2024
 *      Author: LENOVO
 */

#include "software_timer.h"
#include "led7_seg.h"

#define TIMER_CYCLE_2 1

// software timer variable
uint16_t flag_timer2 = 0;
uint16_t timer2_counter = 0;
uint16_t timer2_MUL = 0;

void timer_init(){
	HAL_TIM_Base_Start_IT(&htim2);
}

void set_timer2(uint16_t duration){
	timer2_MUL = duration/TIMER_CYCLE_2;
	timer2_counter = timer2_MUL;
	flag_timer2 = 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2){
		if (timer2_counter > 0){
			timer2_counter--;
			if (timer2_counter == 0){
				flag_timer2 == 1;
				timer2_counter = timer2_MUL;
			}
		}
		// 1ms interrupt here
		led7_Scan();
	}
}
