/*
 * lightTraffic.h
 *
 *  Created on: Nov 5, 2025
 *      Author: Hoàng Hưng
 */

#ifndef INC_LIGHTTRAFFIC_H_
#define INC_LIGHTTRAFFIC_H_

#include "main.h"

typedef enum {
    LED_RED1,
    LED_AMBER1,
    LED_GREEN1,
    LED_RED2,
    LED_AMBER2,
    LED_GREEN2,
    BLINKING_LED
} LedID;

void LEDTraffic_On(LedID id);
void LEDTraffic_Off(LedID id);
void LEDTraffic_Toggle(LedID id);

#endif /* INC_LIGHTTRAFFIC_H_ */
