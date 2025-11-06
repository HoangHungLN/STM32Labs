/*
 * LEDTraffic.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Hoàng Hưng
 */

#include "lightTraffic.h"

void LEDTraffic_On(LedID id) {
    switch(id) {
        case LED_RED1:     HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET); break;
        case LED_AMBER1:   HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin, GPIO_PIN_SET); break;
        case LED_GREEN1:   HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET); break;
        case LED_RED2:     HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_SET); break;
        case LED_AMBER2:   HAL_GPIO_WritePin(GPIOA, LED_AMBER2_Pin, GPIO_PIN_SET); break;
        case LED_GREEN2:   HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin, GPIO_PIN_SET); break;
        case BLINKING_LED:   HAL_GPIO_WritePin(GPIOA, BLINKING_LED_Pin, GPIO_PIN_SET); break;
    }
}

void LEDTraffic_Off(LedID id) {
    switch(id) {
        case LED_RED1:     HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_RESET); break;
        case LED_AMBER1:   HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin, GPIO_PIN_RESET); break;
        case LED_GREEN1:   HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_RESET); break;
        case LED_RED2:     HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin, GPIO_PIN_RESET); break;
        case LED_AMBER2:   HAL_GPIO_WritePin(GPIOA, LED_AMBER2_Pin, GPIO_PIN_RESET); break;
        case LED_GREEN2:   HAL_GPIO_WritePin(GPIOA, LED_GREEN2_Pin, GPIO_PIN_RESET); break;
        case BLINKING_LED:   HAL_GPIO_WritePin(GPIOA, BLINKING_LED_Pin, GPIO_PIN_RESET); break;
    }
}

void LEDTraffic_Toggle(LedID id) {
    switch(id) {
        case LED_RED1:     HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin); break;
        case LED_AMBER1:   HAL_GPIO_TogglePin(GPIOA, LED_AMBER1_Pin); break;
        case LED_GREEN1:   HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin); break;
        case LED_RED2:     HAL_GPIO_TogglePin(GPIOA, LED_RED2_Pin); break;
        case LED_AMBER2:   HAL_GPIO_TogglePin(GPIOA, LED_AMBER2_Pin); break;
        case LED_GREEN2:   HAL_GPIO_TogglePin(GPIOA, LED_GREEN2_Pin); break;
        case BLINKING_LED:   HAL_GPIO_TogglePin(GPIOA, BLINKING_LED_Pin); break;
    }
}
