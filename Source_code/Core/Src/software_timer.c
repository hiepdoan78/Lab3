/*
 * software_timer.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Hiepm
 */

#include "software_timer.h"

int timer_counter1;
int timer1_flag;
int timer_counter2;
int timer2_flag;


void setTimer1(int duration1){
	timer_counter1 = duration1/TICK;
	timer1_flag = 0;
}

void setTimer2(int duration2){
	timer_counter2 = duration2/TICK;
	timer2_flag = 0;
}


void  timerRun(){
	if(timer_counter1 > 0){
		timer_counter1--;
		if(timer_counter1 <= 0){
			timer1_flag = 1;
		}
	}
	if(timer_counter2 > 0){
			timer_counter2--;
			if(timer_counter2 <= 0){
				timer2_flag = 1;
			}
		}

}
