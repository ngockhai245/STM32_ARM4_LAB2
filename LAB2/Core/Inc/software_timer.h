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

extern uint16_t flag_timer2;

extern int debug_led_flag;
extern int led_y0_flag;
extern int led_y1_flag;

void timer_init();
void setTimer2(uint16_t duration);

void setTimer_debug_led(uint16_t duration);
void setTimer_led_y0(uint16_t duration);
void setTimer_led_y1(uint16_t duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
