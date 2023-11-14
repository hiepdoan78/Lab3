/*
 * display_7seg.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Hiepm
 */

#include "display_7seg.h"
int led_buffer[4] = {1, 2, 3, 4};
void display7SEG(int num){
	  char segment[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0X99, 0x92, 0x82, 0xF8, 0x80, 0x90};
	  for (int i = 0; i < 7; ++i){
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (segment[num] >> i) & 1);
	  }
  }

void clearAllLed(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}


void updateLedBuffer(int num1, int num2){
	led_buffer[0] = num1 / 10;
	led_buffer[1] = num1 % 10;
	led_buffer[2] = num2 / 10;
	led_buffer[3] = num2 % 10;
}
void update7Seg(int index){
	clearAllLed();
	switch(index){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			display7SEG(led_buffer[0]);
			index = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display7SEG(led_buffer[1]);
			index = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			display7SEG(led_buffer[2]);
			index = 3;
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led_buffer[3]);
			index = 0;
			break;
		default:
			break;
		}
}

void displayAll7Seg(int num1, int num2){
	updateLedBuffer(num1, num2);
	if(timer2_flag == 1){
		setTimer2(250);
		update7Seg(index_led);
		index_led++;
		if(index_led >= 4){
			index_led = 0;
		}
	}
}
