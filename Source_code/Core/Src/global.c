/*
 * global.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Hiepm
 */


#include "global.h"

int mode = 1; // set initial mode
int currentState = INIT; // set current state for mode 1
int index_led = 0;
int light = 0, counter = 0;// set counter for mode 1
int TICK = 10; // set timer duration
