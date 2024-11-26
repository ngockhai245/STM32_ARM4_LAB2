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
#define COLON_BLINK_COUNTER 250
#define TIME_UPDATE_COUNTER 60000

extern int colon_flag;
extern int time_update_flag;



void timer_init();
void setTimer_colon(uint16_t duration);
void setTimer_time_update(uint16_t duration);
void displayTime();
void updateColon();
void updateTime();



#endif /* INC_SOFTWARE_TIMER_H_ */
