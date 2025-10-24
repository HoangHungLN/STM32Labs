/*
 * global.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Hoàng Hưng
 */

#include "global.h"

int mode = INIT;
int road1_state = NORMAL_RED;
int road2_state = NORMAL_GREEN;

int red_time = 5;
int amber_time = 2;
int green_time = 3;

int counter_road1 = 0;
int counter_road2 = 0;
int xled_index = 0;
int yled_index = 2;
int led_buffer[4] = {0, 0, 0, 0};
