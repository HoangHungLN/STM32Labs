/*
 * manualTraffic.c
 *
 *  Created on: Nov 4, 2025
 *      Author: Hoàng Hưng
 */

#include "manualTraffic.h"

void manualTrafic_run(){
	switch (mode){
		case MANUAL_RED_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_AMBER2_Pin
									|EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);

			if(isButtonPressed(1)){
				mode = MANUAL_RED_AMBER;
				setTimer(1, 2000);
			}

			if(isButtonPressed(2)){
				mode = NORMAL_RED_GREEN;
				display_number[0] = red_time;
				display_number[1] = green_time;
				init7seg();
				setTimer(0, 250);
				timeCnt = 0;
			}
			break;
		case MANUAL_RED_AMBER:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_AMBER2_GPIO_Port, LED_AMBER2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin|LED_GREEN1_Pin|LED_RED2_Pin|LED_GREEN2_Pin
									|EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);

			if(isTimerExpired(1)){
				mode = MANUAL_GREEN_RED;
			}

			if(isButtonPressed(2)){
				mode = NORMAL_RED_AMBER;
				display_number[0] = amber_time;
				display_number[1] = amber_time;
				init7seg();
				setTimer(0, 250);
				timeCnt = 0;
			}
			break;
		case MANUAL_GREEN_RED:
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin|LED_RED1_Pin|LED_GREEN2_Pin|LED_AMBER2_Pin
									|EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);

			if(isButtonPressed(1)){
				mode = MANUAL_AMBER_RED;
				setTimer(1, 2000);
			}

			if(isButtonPressed(2)){
				mode = NORMAL_GREEN_RED;
				display_number[0] = green_time;
				display_number[1] = red_time;
				init7seg();
				setTimer(0, 250);
				timeCnt = 0;
			}
			break;
		case MANUAL_AMBER_RED:
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin|LED_RED1_Pin|LED_GREEN2_Pin|LED_AMBER2_Pin
									|EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
			if(isTimerExpired(1)){
				mode = MANUAL_RED_GREEN;
			}

			if(isButtonPressed(2)){
				mode = NORMAL_AMBER_RED;
				display_number[0] = amber_time;
				display_number[1] = amber_time;
				init7seg();
				setTimer(0, 250);
				timeCnt = 0;
			}
			break;
		default:
			break;

	}
}
