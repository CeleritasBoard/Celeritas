/*
  * i2c_queue.h
  *
  * Created on: Sep 11, 2024
  * 	   Author: badam
  */

#ifndef INC_I2C_QUEUE_H_
#define INC_I2C_QUEUE_H_

#define QUEUE_SIZE 256
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    void *data;         // pointer to the data array
    uint16_t item_size; // size of a signle item in queue (in bytes)
    uint8_t head;       // starting index of the queue (0 - QUEUE_SIZE-1)
    uint8_t tail;       // ending index of the queue (0 - QUEUE_SIZE-1)
    uint8_t size;       // number of elements in the queue (0 - QUEUE_SIZE)
} Queue;

void queue_init(Queue* queue);
void queue_put(Queue* queue, void* item, bool priority);
bool queue_get(Queue* queue, void* data);
void queue_clear(Queue* queue);
bool queue_delete(Queue* queue, bool (*condition)(void* item));

#endif /* INC_I2C_QUEUE_H_ */