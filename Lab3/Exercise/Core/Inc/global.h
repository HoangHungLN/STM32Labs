/*
 * global.h
 *
 *  Created on: Oct 24, 2025
 *      Author: Hoàng Hưng
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "main.h"

#define INIT			0
#define MODE1_NORMAL	1
#define MODE2_MOD_RED	2
#define MODE3_MOD_AMBER 3
#define MODE4_MOD_GREEN 4

#define NORMAL_RED		11
#define NORMAL_AMBER	12
#define NORMAL_GREEN	13

extern int mode;
extern int road1_state;
extern int road2_state;

extern int red_time;
extern int amber_time;
extern int green_time;

extern int counter_road1;
extern int counter_road2;
extern int led_buffer[4];
extern int xled_index;
extern int yled_index;

#endif /* INC_GLOBAL_H_ */
