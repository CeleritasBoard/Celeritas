/*
 * ReMeasure.c
 *
 * Created on: Sep 5, 2024
 * 	   Author: badam
 */

#include "ReMeasure.h"
#include "RequestQueue.h"
#include <string.h>

void reMeasure(unsigned char id, unsigned char dec[]) {
    Request new_request;
    new_request.ID = id;
    new_request.type = (RequestType)dec[0];  // Assuming first byte is the type
    new_request.is_priority = dec[1];
    new_request.is_header = dec[2];
    new_request.limit = dec[3];
    new_request.start_time = (dec[4] << 24) | (dec[5] << 16) | (dec[6] << 8) | dec[7];
    new_request.min_voltage = dec[9];
    new_request.max_voltage = dec[10];

    request_queue_put(new_request);
}
