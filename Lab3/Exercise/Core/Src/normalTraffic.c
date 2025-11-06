/*
 * normalTraffic.c
 *
 *  Created on: Nov 3, 2025
 *      Author: Hoàng Hưng
 */

#include "normalTraffic.h"

int timeCnt = 0;
int display_number[2] = {0, 0};
int tmp_time = 0;

void normalTraffic_run(){
	switch(mode){
		case INIT:
			mode = NORMAL_RED_GREEN;
			display_number[0] = red_time;
			display_number[1] = green_time;
			setTimer(0, 250);
			init7seg();
			break;
		case NORMAL_RED_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin, GPIO_PIN_SET);

			display7seg();

			if(timeCnt >= green_time*TIMER0_FREQ){ //TICK when led time out
				mode = NORMAL_RED_AMBER;
				timeCnt = 0;
				display_number[0] = amber_time;
				display_number[1] = amber_time;
				setTimer(0, 250);
			}

			if(isButtonLongPressed(2)){
				mode = MANUAL_RED_GREEN;
				xled_index = 0;
				yled_index = 2;
			}

			if(isButtonPressed(0)){
				mode = MODE2_MOD_RED;
				tmp_time = red_time;
				setTimer(0, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				led_buffer[0] = red_time / 10;
				led_buffer[1] = red_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 2;
			}

			break;
		case NORMAL_RED_AMBER:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);

			display7seg();

			if(timeCnt >= amber_time*TIMER0_FREQ){ //TICK when led time out
				mode = NORMAL_GREEN_RED;
				timeCnt = 0;
				display_number[0] = green_time;
				display_number[1] = red_time;
				setTimer(0, 250);
			}

			if(isButtonLongPressed(2)){
				mode = MANUAL_RED_AMBER;
				setTimer(1, 2000);
				xled_index = 0;
				yled_index = 2;
			}

			if(isButtonPressed(0)){
				mode = MODE2_MOD_RED;
				tmp_time = red_time;
				setTimer(0, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				led_buffer[0] = red_time / 10;
				led_buffer[1] = red_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 2;
			}
			break;
		case NORMAL_GREEN_RED:
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin|LED_RED1_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);

			display7seg();

			if(timeCnt >= green_time*TIMER0_FREQ){ //TICK when led time out
				mode = NORMAL_AMBER_RED;
				timeCnt = 0;
				display_number[0] = amber_time;
				display_number[1] = amber_time;
				setTimer(0, 250);
			}

			if(isButtonLongPressed(2)){
				mode = MANUAL_GREEN_RED;
				xled_index = 0;
				yled_index = 2;
			}

			if(isButtonPressed(0)){
				mode = MODE2_MOD_RED;
				tmp_time = red_time;
				setTimer(0, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				led_buffer[0] = red_time / 10;
				led_buffer[1] = red_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 2;
			}
			break;
		case NORMAL_AMBER_RED:
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin|LED_RED1_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);

			display7seg();

			if(timeCnt >= amber_time*TIMER0_FREQ){ //TICK when led time out
				mode = NORMAL_RED_GREEN;
				timeCnt = 0;
				display_number[0] = red_time;
				display_number[1] = green_time;
				setTimer(0, 250);
			}

			if(isButtonLongPressed(2)){
				mode = MANUAL_AMBER_RED;
				setTimer(1, 2000);
				xled_index = 0;
				yled_index = 2;
			}

			if(isButtonPressed(0)){
				mode = MODE2_MOD_RED;
				tmp_time = red_time;
				setTimer(0, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				led_buffer[0] = red_time / 10;
				led_buffer[1] = red_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 2;
			}
			break;
		default:
			break;
	}
}

void init7seg(){
	xled_index = 0;
	yled_index = 2;
	led_buffer[0] = display_number[0] / 10;
	led_buffer[2] = display_number[1] / 10;

	x_update7SEG(xled_index, led_buffer[xled_index]);
	xled_index = (xled_index + 1) % 2;

	y_update7SEG(yled_index, led_buffer[yled_index]);
	yled_index = 5 - yled_index;
}

void display7seg(){
	if(isTimerExpired(0)){ //TICK every 1/TIMER0_FREQ
		setTimer(0, 250);
		timeCnt++;

		if(timeCnt % TIMER0_FREQ == 0){ // TICK every second
			display_number[0]--;
			display_number[1]--;
		}

		led_buffer[0] = display_number[0] / 10;
		led_buffer[1] = display_number[0] % 10;
		led_buffer[2] = display_number[1] / 10;
		led_buffer[3] = display_number[1] % 10;

		x_update7SEG(xled_index, led_buffer[xled_index]);
		xled_index = (xled_index + 1) % 2;

		y_update7SEG(yled_index, led_buffer[yled_index]);
		yled_index = 5 - yled_index;
	}
}
