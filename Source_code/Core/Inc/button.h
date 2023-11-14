/*
 * button.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Hiepm
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_



#endif /* INC_BUTTON_H_ */



#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#include "global.h"

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

int isKey1Pressed();
int isKey2Pressed();
int isKey3Pressed();

void getKeyInput();
