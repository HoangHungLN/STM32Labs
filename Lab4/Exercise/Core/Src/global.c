/*
 * global.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Hoàng Hưng
 */

#include "global.h"

int mode = INIT;

int red_time = 5;
int amber_time = 2;
int green_time = 3;

int xled_index = 0;
int yled_index = 2;
int led_buffer[4] = {0, 0, 0, 0};
