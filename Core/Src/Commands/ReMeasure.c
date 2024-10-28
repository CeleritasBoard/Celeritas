/*
 * ReMeasure.c
 *
 * Created on: Sep 5, 2024
 * 	   Author: badam
 */

#include "Commands/ReMeasure.h"
#include "RequestQueue.h"
#include "Request.h"
#include "SettingsStore.h"
#include "Measurements.h"
#include <string.h>

void reMeasure(uint8_t id, uint8_t dec[]) {
    Request new_request;
    // Almost all the parameters of a Request is given by settings
    // (which currently doesn't exists), so I gave some sample here.
    new_request.ID = id;
    new_request.type = getSetting(MODE_OF_OPERATION);
    new_request.is_priority = /*dec[4] & 0x80*/ false; // the first bit of byte 5
    new_request.is_header = /*dec[4] & 0x40*/ false; // the second bit of byte 5
    new_request.limit = getSetting(DURATION);
    //new_request.start_time = (dec[0] << 24) | (dec[1] << 16) | (dec[2] << 8) | dec[3];
    new_request.start_time = 100;
    new_request.min_voltage = getSetting(MIN_VOLTAGE);
    new_request.max_voltage = getSetting(MAX_VOLTAGE);
    new_request.samples = getSetting(SAMPLES);
    new_request.resolution = getSetting(RESOLUTION);
    request_queue_put(new_request);
}
