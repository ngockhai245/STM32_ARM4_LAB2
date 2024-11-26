/*
 * software_timer.h
 *
 *  Created on: Nov 24, 2024
 *      Author: LENOVO
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "tim.h"
#include "software_timer.h"

#define TIMER_CYCLE_2 1
#define SHIFT_RIGHT_DELAY 1000

extern int timer2_flag;
extern int shift_right_counter;


void timer_init();
void setTimer2(uint16_t duration);
void shiftRightDigits();
void display_shiftRightDigits();



#endif /* INC_SOFTWARE_TIMER_H_ */
