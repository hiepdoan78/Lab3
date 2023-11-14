/*
 * fsm_normal_mode.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Hiepm
 */
#include "fsm_normal_mode.h"
int countRed1 = 5, countGreen1 = 3, countYellow1 = 2,countRed2 = 5, countGreen2 = 3, countYellow2 = 2;
void fsmNormalMode(){
	displayAll7Seg(light, counter);
	if(timer1_flag == 1){
		setTimer1(1000);
		switch (currentState){
			case INIT:
				light = countRed1;
				counter = countGreen2;
				currentState = RED1_GREEN2;
			case RED1_GREEN2:
				setRed1Green2();
				light--;
				counter--;
				if (counter < 0){
					light = countRed1 - countGreen2;
					counter = countYellow2;
					currentState = RED1_YELLOW2;
				}
				 break;
			case RED1_YELLOW2:
				setRed1Yellow2();
				light--;
				counter--;
				if (counter < 0){
					counter = countRed2;
					light = countGreen1;
					currentState = RED2_GREEN1;
				}
				break;
			case RED2_GREEN1:
				setRed2Green1();
				light--;
				counter--;
				if (light < 0){
					light = countRed2 - countGreen1;
					counter = countYellow1;
					currentState = RED2_YELLOW1;
				}
				break;
			case RED2_YELLOW1 :
				setRed2Yellow1();
				light--;
				counter--;
				if (light < 0){
					counter = countRed1;
					light = countGreen2;
					currentState = RED1_GREEN2;
				}
				break;
			default:
				break;
			}

	}
	}
