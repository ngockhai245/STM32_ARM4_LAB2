/*
 * software_timer.c
 *
 *  Created on: Nov 24, 2024
 *      Author: LENOVO
 */

#include "software_timer.h"
#include "led7_seg.h"

#define TIMER_CYCLE_2 1



int timer2_flag = 0;
int shift_right_counter = 0;

int digits[4] = {2, 4, 5, 7};



void shiftRightDigits(){
	int lastDigit = digits[3];// bien luu gia tri so cuoi cung
	for (int i = 3; i > 0; i--){//dich phai
		digits[i] = digits[i - 1];
	}
	digits[0] = lastDigit;// dua so cuoi cung len dau tien
}




void display_shiftRightDigits(){
	for (int i = 0; i < 4; i++){
		led7_SetDigit(digits[i], i, 0);
	}
}



void timer_init(){
	HAL_TIM_Base_Start_IT(&htim2);

	display_shiftRightDigits();
	setTimer2(SHIFT_RIGHT_DELAY);
}

/**
  * @brief  Set duration of software timer interrupt
  * @param  duration Duration of software timer interrupt
  * @retval None
  */


void setTimer2(uint16_t duration){
	int timer_MUL = duration/TIMER_CYCLE_2;
	shift_right_counter = timer_MUL;
	timer2_flag = 0;
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2){
		if (shift_right_counter > 0){
			shift_right_counter--;
			if (shift_right_counter <= 0){
				timer2_flag = 1;
			}
		}
		led7_Scan();
	}
}


