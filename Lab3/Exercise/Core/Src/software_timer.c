/*
 * sofwar_timer.c
 *
 *  Created on: Sep 25, 2025
 *      Author: Hoàng Hưng
 */

#include "software_timer.h"

#define TICK 10

int timer_counter[MAX_TIMER];
int timer_flag[MAX_TIMER];

void setTimer(int index, int duration){
	if(index < 0 || index >= MAX_TIMER) return;
	timer_counter[index] = duration / TICK;
	timer_flag[index] = 0;
}

int isTimerExpired(int index){
	if(timer_flag[index] == 1){
		return 1;
	}
	return 0;
}

void timerRun(){
	for(int i = 0; i < MAX_TIMER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
