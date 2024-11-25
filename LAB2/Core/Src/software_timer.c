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

// debug led, led y0, led y1
//int debug_led_flag = 0;
//int led_y0_flag = 0;
//int led_y1_flag = 0;
//
//int debug_led_counter = 0;
//int led_y0_counter = 0;
//int led_y1_counter = 0;

//uint16_t timer_MUL = 0;

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

//void setTimer_debug_led(uint16_t duration){
//	timer_MUL = duration/TIMER_CYCLE_2;
//	debug_led_counter = timer_MUL;
//	debug_led_flag = 0;
//}
//
//void setTimer_led_y0(uint16_t duration){
//	timer_MUL = duration/TIMER_CYCLE_2;
//	led_y0_counter = timer_MUL;
//	led_y0_flag = 0;
//}
//
//void setTimer_led_y1(uint16_t duration){
//	timer_MUL = duration/TIMER_CYCLE_2;
//	led_y1_counter = timer_MUL;
//	led_y1_flag = 0;
//}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2){
		if (timer2_counter > 0){
			timer2_counter--;
			if (timer2_counter == 0){
				flag_timer2 == 1;
			}
		}
		// 1ms interrupt here
//		led7_Scan();
	}
}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	if (htim->Instance == TIM2){
//		if (debug_led_counter > 0){
//			debug_led_counter--;
//			if (debug_led_counter == 0){
//				debug_led_flag = 1;
//			}
//		}
//		if (led_y0_counter > 0){
//			led_y0_counter--;
//			if (led_y0_counter == 0){
//				led_y0_flag = 1;
//			}
//		}
//		if (led_y1_counter > 0){
//			led_y1_counter--;
//			if (led_y1_counter == 0){
//				led_y1_flag = 1;
//			}
//		}
//	}
//}
