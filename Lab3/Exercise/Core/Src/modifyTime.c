/*
 * modifyTime.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Hoàng Hưng
 */

#include "modifyTime.h"

void modifyTime_run(){
	switch(mode){
		case MODE2_MOD_RED:
			if(isTimerExpired(0)){
				setTimer(0, 250);
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);

				x_update7SEG(xled_index, led_buffer[xled_index]);
				xled_index = (xled_index + 1) % 2;

				y_update7SEG(yled_index, led_buffer[yled_index]);
				yled_index = 5 - yled_index;
			}

			if(isButtonPressed(1)){
				tmp_time = (tmp_time + 1) % 100;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
			}

			if(isButtonPressed(2)){
				red_time = tmp_time;
			}

			if(isButtonPressed(0)){
				mode = MODE3_MOD_AMBER;
				setTimer(0, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = amber_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 3;
				init7seg();
			}
			break;
		case MODE3_MOD_AMBER:
			if(isTimerExpired(0)){
				setTimer(0, 250);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
				HAL_GPIO_TogglePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin);

				x_update7SEG(xled_index, led_buffer[xled_index]);
				xled_index = (xled_index + 1) % 2;

				y_update7SEG(yled_index, led_buffer[yled_index]);
				yled_index = 5 - yled_index;
			}

			if(isButtonPressed(1)){
				tmp_time = (tmp_time + 1) % 100;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
			}

			if(isButtonPressed(2)){
				amber_time = tmp_time;
			}

			if(isButtonPressed(0)){
				mode = MODE4_MOD_GREEN;
				setTimer(0, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = green_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 4;
				init7seg();
			}
			break;
		case MODE4_MOD_GREEN:
			if(isTimerExpired(0)){
				setTimer(0, 250);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);

				x_update7SEG(xled_index, led_buffer[xled_index]);
				xled_index = (xled_index + 1) % 2;

				y_update7SEG(yled_index, led_buffer[yled_index]);
				yled_index = 5 - yled_index;
			}

			if(isButtonPressed(1)){
				tmp_time = (tmp_time + 1) % 100;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
			}

			if(isButtonPressed(2)){
				green_time = tmp_time;
			}

			if(isButtonPressed(0)){
				modifyWrongTime();
				mode = NORMAL_RED_GREEN;
				display_number[0] = red_time;
				display_number[1] = green_time;
				init7seg();
				timeCnt = 0;
				setTimer(0, 250);
			}
			break;
		default:
			break;
	}
}

void modifyWrongTime(){
	if(green_time + amber_time < red_time){
		green_time = green_time + (red_time - (amber_time + green_time));
	}
	if(green_time + amber_time > red_time){
		red_time = red_time + ((green_time + amber_time) - red_time);
	}
}
