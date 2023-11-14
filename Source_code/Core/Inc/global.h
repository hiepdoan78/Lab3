/*
 * global.h
 *
 *  Created on: Nov 1, 2023
 *      Author: Hiepm
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "display_7seg.h"
#include "software_timer.h"
#include "led_status.h"

#define INIT			0
#define RED1_GREEN2		1
#define RED1_YELLOW2	2
#define RED2_GREEN1		3
#define RED2_YELLOW1	4

extern int currentState;
extern int mode;
extern int index_led;
extern int light, counter;
extern int TICK;

#endif /* INC_GLOBAL_H_ */
