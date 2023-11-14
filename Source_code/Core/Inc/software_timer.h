/*
 * software_timer.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Hiepm
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_



#endif /* INC_SOFTWARE_TIMER_H_ */

#include "global.h"

extern int timer_counter1;
extern int timer1_flag;
extern int timer_counter2;
extern int timer2_flag;

void setTimer1(int duration1);
void setTimer2(int duration2);

void timerRun();
