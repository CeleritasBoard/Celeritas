/*
 * timer.c
 *
 * Created on: Oct 4, 2024
 *     Author: adamg
 */

#include "stm32f1xx_hal_conf.h"
#include "timer.h"

volatile uint32_t current_unix_time = 0;
TIM_HandleTypeDef htim1;

/**
 * Sets the current system time to the given value. Disables interrupts during
 * the operation to ensure atomicity.
 *
 * @param timestamp The new system time, in seconds since the Unix epoch.
 */
void set_system_time(uint32_t timestamp)
{
	current_unix_time = timestamp;
}



void TIM1_IRQHandler(void)
{
	if (__HAL_TIM_GET_FLAG(&htim1, TIM_FLAG_UPDATE) != RESET)
	{
		if (__HAL_TIM_GET_IT_SOURCE(&htim1, TIM_IT_UPDATE) != RESET)
		{
			__HAL_TIM_CLEAR_IT(&htim1, TIM_FLAG_UPDATE);
			current_unix_time++;
		}
	}
}