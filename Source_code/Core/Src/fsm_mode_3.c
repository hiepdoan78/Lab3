/*
 * fsm_mode_4.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Hiepm
 */

#include <fsm_mode_3.h>
int yellow_value_set = 0;
void fsmMode3(){

	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET); // turn off orther leds
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);

	if(timer1_flag == 1){
		setTimer1(250);
		HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin); // blinky all yellow leds
		HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
	}

	if(isKey2Pressed() == 1){
		yellow_value_set++;
		if(yellow_value_set > 99){
			yellow_value_set = 0;
		}

	}
	if(isKey3Pressed() == 1){
		countYellow1 = yellow_value_set;
		countYellow2 = countYellow1;
		yellow_value_set = 0;
		}

	displayAll7Seg(mode, yellow_value_set); // display the time value set for yellow leds
}

