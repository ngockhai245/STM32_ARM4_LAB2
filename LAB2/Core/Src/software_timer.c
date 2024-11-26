/*
 * software_timer.c
 *
 *  Created on: Nov 24, 2024
 *      Author: LENOVO
 */

#include "software_timer.h"
#include "led7_seg.h"

#define TIMER_CYCLE_2 1



int colon_flag = 0;
int colon_counter = 0;
int time_update_flag = 0;
int time_update_counter = 0;

int hour = 05;
int minute = 47;

int colon_status = 0;


void updateTime(){
	minute++;
	if (minute >= 60){
		minute = 0;
		hour++;
		if (hour >= 24){
			hour = 0;
		}
	}
	setTimer_time_update(TIME_UPDATE_COUNTER);
}


void updateColon(){
	colon_status = !colon_status;
	led7_SetColon(colon_status);
	setTimer_colon(COLON_BLINK_COUNTER);
}


void displayTime(){
	int hour1stNum = hour / 10;
	int hour2ndNum = hour % 10;
	int minute1stNum = minute / 10;
	int minute2ndNum = minute % 10;

	led7_SetDigit(hour1stNum, 0, 0);
	led7_SetDigit(hour2ndNum, 1, 0);
	led7_SetDigit(minute1stNum, 2, 0);
	led7_SetDigit(minute2ndNum, 3, 0);
}


// init timer interrupt
void timer_init(){
	HAL_TIM_Base_Start_IT(&htim2);
	setTimer_colon(COLON_BLINK_COUNTER);
	setTimer_time_update(TIME_UPDATE_COUNTER);
	displayTime();
}

/**
  * @brief  Set duration of software timer interrupt
  * @param  duration Duration of software timer interrupt
  * @retval None
  */
//void setTimer2(uint16_t duration){
//	timer2_MUL = duration/TIMER_CYCLE_2;
//	timer2_counter = timer2_MUL;
//	flag_timer2 = 0;
//}


void setTimer_colon(uint16_t duration){
	int timer_MUL = duration/TIMER_CYCLE_2;
	colon_counter = timer_MUL;
	colon_flag = 0;
}


void setTimer_time_update(uint16_t duration){
	int timer_MUL = duration/TIMER_CYCLE_2;
	time_update_counter = timer_MUL;
	time_update_flag = 0;
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2){
		if (colon_counter > 0){
			colon_counter--;
			if (colon_counter <= 0){
				colon_flag = 1;
			}
		}
		if (time_update_counter > 0){
			time_update_counter--;
			if (time_update_counter <= 0){
				time_update_flag = 1;
			}
		}
		led7_Scan();
	}
}


