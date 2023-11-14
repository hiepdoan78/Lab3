/*
 * fsm_mode_2.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Hiepm
 */
#include "fsm_mode_2.h"
int red_value_set = 0;
void fsmMode2(){

	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET); // turn off orther leds
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
	if(timer1_flag == 1){
		setTimer1(250);
		HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin); // blinky all red leds
		HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
	}
	if(isKey2Pressed() == 1){
				red_value_set++;
				if(red_value_set > 99){
					red_value_set = 0;
			}

		}
	if(isKey3Pressed() == 1){
		countRed1 = red_value_set;
		countRed2 = countRed1;
		red_value_set = 0;
		}
	displayAll7Seg(mode, red_value_set); // display the time value set for red leds
}
