/*
 * fsm_mode_3.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Hiepm
 */

#include <fsm_mode_4.h>
int green_value_set = 0;
void fsmMode4(){

	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);// turn off orther leds
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	if(timer1_flag == 1){
	setTimer1(250);
	HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin); // blinky all green leds
	HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
	}
	if(isKey2Pressed() == 1){
			green_value_set++;
			if(green_value_set > 99){
				green_value_set = 0;
			}
		}
	if(isKey3Pressed() == 1){
		countGreen1 = green_value_set;
		countGreen2 = countGreen1;
		green_value_set = 0;
		}

	displayAll7Seg(mode, green_value_set); // display the time value set for green leds
}

