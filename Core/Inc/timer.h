/*
 * timer.h
 *
 * Created on: Oct 4
 *     Author: adamg
 */

#ifndef INC_TIMER_H
#define INC_TIMER_H

#include <stdbool.h>
#include <stdint.h>

void TIM1_IRQHandler(void);
void Set_SystemTime(uint32_t timestamp);
uint32_t Get_SystemTime(void);

extern volatile uint32_t current_unix_time;

#endif
