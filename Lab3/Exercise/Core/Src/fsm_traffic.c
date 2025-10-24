/*
 * fsm_normally_traffic.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Hoàng Hưng
 */

#include "fsm_traffic.h"
#include "display.h"

int tmp_time = 0;

void fsm_traffic_run(){
	switch(mode){
		case INIT:
			mode = MODE1_NORMAL;
			setTimer(0, red_time * 1000);
			setTimer(1, green_time * 1000);
			setTimer(2, 10);
			counter_road1 = red_time;
			counter_road2 = green_time;
			break;
		case MODE1_NORMAL:
			normal_trafficLight();
			normal_trafficTime();

			if(isButtonPressed(0)){
				mode = MODE2_MOD_RED;
				setTimer(2, 10);
				setTimer(3, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = red_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 2;
			}
			break;
		case MODE2_MOD_RED:
			if(isTimerExpired(3) == 1){
				setTimer(3, 250);
				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
			}

			if(isButtonPressed(1)){
				tmp_time++;
				if(tmp_time >= 100){
					tmp_time = 0;
				}
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
			}

			if(isTimerExpired(2)){
				setTimer(2, 250);
				x_update7SEG(xled_index, led_buffer[xled_index]);
				xled_index = (xled_index + 1) % 2;
				y_update7SEG(yled_index, led_buffer[yled_index]);
				yled_index = 5 - yled_index;
			}

			if(isButtonPressed(2)){
				red_time = tmp_time;
				mode = MODE3_MOD_AMBER;
				setTimer(2, 10);
				setTimer(3, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = amber_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 3;
			}

			if(isButtonPressed(0)){
				mode = MODE3_MOD_AMBER;
				setTimer(2, 10);
				setTimer(3, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = amber_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 3;
			}
			break;
		case MODE3_MOD_AMBER:
			if(isTimerExpired(3) == 1){
				setTimer(3, 250);
				HAL_GPIO_TogglePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin);
				HAL_GPIO_TogglePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin);
			}

			if(isButtonPressed(1)){
				tmp_time++;
				if(tmp_time >= 100){
					tmp_time = 0;
				}
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
			}

			if(isTimerExpired(2)){
				setTimer(2, 250);
				x_update7SEG(xled_index, led_buffer[xled_index]);
				xled_index = (xled_index + 1) % 2;
				y_update7SEG(yled_index, led_buffer[yled_index]);
				yled_index = 5 - yled_index;
			}

			if(isButtonPressed(2)){
				amber_time = tmp_time;
				mode = MODE4_MOD_GREEN;
				setTimer(2, 10);
				setTimer(3, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = green_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 4;
			}

			if(isButtonPressed(0)){
				mode = MODE4_MOD_GREEN;
				setTimer(2, 10);
				setTimer(3, 250);
				HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin|LED_GREEN2_Pin, GPIO_PIN_SET);
				tmp_time = green_time;
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
				led_buffer[2] = 0;
				led_buffer[3] = 4;
			}
			break;
		case MODE4_MOD_GREEN:
			if(isTimerExpired(3) == 1){
				setTimer(3, 250);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			}

			if(isButtonPressed(1)){
				tmp_time++;
				if(tmp_time >= 100){
					tmp_time = 0;
				}
				led_buffer[0] = tmp_time / 10;
				led_buffer[1] = tmp_time % 10;
			}

			if(isTimerExpired(2)){
				setTimer(2, 250);
				x_update7SEG(xled_index, led_buffer[xled_index]);
				xled_index = (xled_index + 1) % 2;

				y_update7SEG(yled_index, led_buffer[yled_index]);
				yled_index = 5 - yled_index;
			}

			if(isButtonPressed(2)){
				green_time = tmp_time;
				mode = MODE1_NORMAL;
				setTimer(0, red_time * 1000);
				setTimer(1, green_time * 1000);
				setTimer(2, 10);
				counter_road1 = red_time;
				counter_road2 = green_time;
				counter = 0;
				road1_state = NORMAL_RED;
				road2_state = NORMAL_GREEN;
			}

			if(isButtonPressed(0)){
				mode = MODE1_NORMAL;
				setTimer(0, red_time * 1000);
				setTimer(1, green_time * 1000);
				setTimer(2, 10);
				counter_road1 = red_time;
				counter_road2 = green_time;
				counter = 0;
				road1_state = NORMAL_RED;
				road2_state = NORMAL_GREEN;
			}
			break;
		default:
			break;
	}
}
