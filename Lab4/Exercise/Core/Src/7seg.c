/*
 * 7seg.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Hoàng Hưng
 */

#include "7seg.h"

int segTable[10][7] = {
		{0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1},
		{0,0,1,0,0,1,0},
		{0,0,0,0,1,1,0},
		{1,0,0,1,1,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,0,0,0},
		{0,0,0,1,1,1,1},
		{0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0}
};

void x_display7SEG(int num){
	if(num < 0 || num > 9) return;
	HAL_GPIO_WritePin(a_7SEG_GPIO_Port, a_7SEG_Pin, segTable[num][0]);
	HAL_GPIO_WritePin(b_7SEG_GPIO_Port, b_7SEG_Pin, segTable[num][1]);
	HAL_GPIO_WritePin(c_7SEG_GPIO_Port, c_7SEG_Pin, segTable[num][2]);
	HAL_GPIO_WritePin(d_7SEG_GPIO_Port, d_7SEG_Pin, segTable[num][3]);
	HAL_GPIO_WritePin(e_7SEG_GPIO_Port, e_7SEG_Pin, segTable[num][4]);
	HAL_GPIO_WritePin(f_7SEG_GPIO_Port, f_7SEG_Pin, segTable[num][5]);
	HAL_GPIO_WritePin(g_7SEG_GPIO_Port, g_7SEG_Pin, segTable[num][6]);
}

void y_display7SEG(int num){
	if(num < 0 || num > 9) return;
	HAL_GPIO_WritePin(a_7SEG2_GPIO_Port, a_7SEG2_Pin, segTable[num][0]);
	HAL_GPIO_WritePin(b_7SEG2_GPIO_Port, b_7SEG2_Pin, segTable[num][1]);
	HAL_GPIO_WritePin(c_7SEG2_GPIO_Port, c_7SEG2_Pin, segTable[num][2]);
	HAL_GPIO_WritePin(d_7SEG2_GPIO_Port, d_7SEG2_Pin, segTable[num][3]);
	HAL_GPIO_WritePin(e_7SEG2_GPIO_Port, e_7SEG2_Pin, segTable[num][4]);
	HAL_GPIO_WritePin(f_7SEG2_GPIO_Port, f_7SEG2_Pin, segTable[num][5]);
	HAL_GPIO_WritePin(g_7SEG2_GPIO_Port, g_7SEG2_Pin, segTable[num][6]);
}

void x_update7SEG (int index, int num) {
	switch (index) {
		case 0:
			x_display7SEG(num);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			break;
		case 1:
			x_display7SEG(num);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

void y_update7SEG (int index, int num) {
	switch (index) {
		case 2:
			y_display7SEG(num);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break;
		case 3:
			y_display7SEG(num);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}
