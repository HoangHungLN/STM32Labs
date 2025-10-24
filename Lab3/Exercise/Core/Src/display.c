/*
 * display.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Hoàng Hưng
 */

#include "display.h"

int display_number[2];

int counter = 0;

void normal_trafficLight(){
	switch(road1_state){
		case NORMAL_RED:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			display_number[0] = counter_road1;
			if(isTimerExpired(0) == 1){
				road1_state = NORMAL_GREEN;
				setTimer(0, green_time * 1000);
				counter_road1 = green_time;
			}
			break;
		case NORMAL_AMBER:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			display_number[0] = counter_road1;
			if(isTimerExpired(0) == 1){
				road1_state = NORMAL_RED;
				setTimer(0, red_time * 1000);
				counter_road1 = red_time;
			}
			break;
		case NORMAL_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			display_number[0] = counter_road1;
			if(isTimerExpired(0) == 1){
				road1_state = NORMAL_AMBER;
				setTimer(0, amber_time * 1000);
				counter_road1 = amber_time;
			}
			break;
		default:
			break;
	}

	switch(road2_state){
		case NORMAL_RED:
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
			display_number[1] = counter_road2;
			if(isTimerExpired(1) == 1){
				road2_state = NORMAL_GREEN;
				setTimer(1, green_time * 1000);
				counter_road2 = green_time;
			}
			break;
		case NORMAL_AMBER:
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
			display_number[1] = counter_road2;
			if(isTimerExpired(1) == 1){
				road2_state = NORMAL_RED;
				setTimer(1, red_time * 1000);
				counter_road2 = red_time;
			}
			break;
		case NORMAL_GREEN:
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			display_number[1] = counter_road2;
			if(isTimerExpired(1) == 1){
				road2_state = NORMAL_AMBER;
				setTimer(1, amber_time * 1000);
				counter_road2 = amber_time;
			}
			break;
		default:
			break;
	}
}

void normal_trafficTime(){
	if(isTimerExpired(2) == 1){
		setTimer(2, 250);
		counter++;

		if(counter >= 4){
			counter = 0;
			counter_road1--;
			counter_road2--;
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
