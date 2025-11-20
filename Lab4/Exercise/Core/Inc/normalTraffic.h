/*
 * normalTraffic.h
 *
 *  Created on: Nov 3, 2025
 *      Author: Hoàng Hưng
 */

#include "global.h"
#include "7seg.h"

extern int timeCnt;
extern int tmp_time;
int display_number[2];

void normalTraffic_run();
void init7seg();
void display7seg();
