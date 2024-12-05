/*
  * i2c_queue.c
  *
  * Created on: Sep 11, 2024
  * 	   Author: badam
  */

 #include "i2c_queue.h"
#include "Request.h"
#include "Scheduler.h"
#include "Queue.h"
 #define ITEM_SIZE 16 // 15 elements + checksum

extern volatile uint8_t interrupt_counter;

 volatile Queue i2c_queue = {.item_size = ITEM_SIZE, .head = 0, .tail = 0, .size = 0};

 void i2c_queue_push(uint8_t* item, bool priority, bool checksum){
 	uint8_t new_item[ITEM_SIZE];
 	uint8_t copy_lenght = (checksum) ? ITEM_SIZE - 1 : ITEM_SIZE;
 	for (uint8_t i = 0; i < copy_lenght; i++){
 		new_item[i] = item[i];
 	}

 	if (checksum){
 		new_item[ITEM_SIZE-1] = calculate_checksum(item, ITEM_SIZE-1);
 	}

 	if (i2c_queue.size == QUEUE_SIZE){
 		return; // QUEUE_OVERFLOW_ERROR
 	}

 	queue_push(&i2c_queue, new_item, priority);
 }

 uint8_t* i2c_queue_get(bool* result){
 	return queue_get(&i2c_queue, result);
 }

 void i2c_queue_clear(void){
	queue_clear(&i2c_queue);
}

 uint8_t* i2c_queue_fetch(uint8_t idx, bool* result) {
	 if(i2c_queue.size == 0) {
		 *result = false;
		 return NULL;
	 }

	 result = true;
	 return i2c_queue.data[i2c_queue.head + idx];
 }

 uint8_t i2c_queue_count(bool (*filter)(uint8_t* item)) {
	 if(i2c_queue.size == 0) {
		 return NULL;
	 }

	 uint8_t filtered_count = 0;
	 for (int i = 0; i < i2c_queue.size; i++) {
		 bool res;
		 uint8_t* item = i2c_queue_fetch(i, &res);
		 if(res)
			 if (filter(item)) filtered_count++;
	 }
	 return filtered_count;
 }


void add_header(Request request, uint16_t duration){
	 uint8_t headerData[ITEM_SIZE];

	 headerData[0] = request.ID;
	 headerData[1] = (uint8_t)(interrupt_counter & 0xFF);

	 uint16_t temp = get_temperature();
	 headerData[2] = temp >> 8;
	 headerData[3] = temp & 0xFF;

	 uint32_t localTime = request.start_time;
	 for(int i = 0; i < 4; i++){
		 headerData[4+i] = (uint8_t)(localTime >> 24-i*8);
		 localTime -= (headerData[i] << 24-i*8);
	 }

	 headerData[8] = request.resolution;
	 headerData[9] = request.min_voltage >> 4;
	 headerData[10] = ((request.min_voltage & 0xF) << 4) | (request.max_voltage >> 8);
	 headerData[11] = request.max_voltage & 0xFF;
	 headerData[12] = 0;
	 headerData[13] = 0;
	 headerData[14] = 0;
	 headerData[15] = 0xFF;
	 i2c_queue_push(headerData, request.is_priority, true);

 }


 void add_spectrum(Request request, uint8_t* spectrum, uint8_t resolution){
	 const uint8_t everyBit = 16*8; //120, we can modify to 128 and it should work
	 uint8_t importantBits = everyBit/resolution; // how many bits do we keep in

	 uint8_t bitArr[everyBit]; //120 byte
	 uint8_t data[ITEM_SIZE] = {0x00};
	 for(int i = 0; i < resolution; i++){
		 for(int j = 0; j < importantBits; j++){
			 // Converting to base 2
			 if(spectrum[i] % 2 == 0){
				 spectrum[i] /= 2;
				 bitArr[(i+1)*importantBits-j-1] = 0;
			 }
			 else{
				 spectrum[i] = (spectrum[i]-1)/2;
				 bitArr[(i+1)*importantBits-j-1] = 1;
			 }
		 }
	 }

	 for(int k = 0; k < ITEM_SIZE-1; k++){
		 for(int m = 0; m < 8; m++){
			 if(bitArr[k*8+m] == 1){
				 data[k] += pow(2, 7-m);
			 }
		 }
	 }
	 i2c_queue_push(&data, request.is_priority, false);



}

 void add_error(Request request, uint8_t error_type){
	 uint8_t errorData[15] = {0};
	 errorData[14] = 0xD5;
	 if(error_type == TIMEOUT){
		 errorData[13] = 0xFD;
	 }
	 if(error_type == INTERRUPT){
		 errorData[13] = 0xFB;
	 }
	 if(error_type == CORRUPTED){
	 	errorData[13] = 0xF7;
	 }
	 i2c_queue_push(errorData, request.is_priority, true);
 }
