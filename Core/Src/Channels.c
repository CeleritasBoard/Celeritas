/*
 * Channels.c
 *
 *  Created on: Nov 30, 2024
 *      Author: hpraszpi
 *
 *
 *  Manages ADC channels.
 */
#include "Channels.h"
#include "main.h"
#include "stm32f3xx_hal_adc_ex.h"
#include <stdint.h>


extern ADC_HandleTypeDef hadc1;

void select_channel(uint32_t channel, uint32_t sampling_time) {
	ADC_ChannelConfTypeDef sConfig;
	sConfig.Channel = channel;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SingleDiff = ADC_SINGLE_ENDED;
	sConfig.SamplingTime = sampling_time;
	sConfig.OffsetNumber = ADC_OFFSET_NONE;
	sConfig.Offset = 0;

	HAL_ADC_ConfigChannel(&hadc1, &sConfig);
}

void select_temperature_channel(){
	select_channel(ADC_CHANNEL_TEMPSENSOR, ADC_SAMPLETIME_601CYCLES_5); // internal temperature sensor channel
}

void select_measurement_channel() {
	select_channel(ADC_CHANNEL_MEASUREMENT, ADC_SAMPLETIME_1CYCLE_5); // input channel for sampling the analog signal chain
}

void select_refint_channel() {
	select_channel(ADC_CHANNEL_VREFINT, ADC_SAMPLETIME_61CYCLES_5); // internal reference channel for measuring supply voltage of the processor core
}										// datasheet: typical 1.23 V
/*
void select_vbat_channel() {			// internal channel for measuring controller periferals
	select_channel(ADC_CHANNEL_VBAT);	// datasheet: half of the real value (as vbat can be higher than VDDA
}*/
