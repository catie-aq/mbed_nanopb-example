/*
 * Copyright (c) 2023, CATIE, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"

#include "environment.pb.h"
#include "pb.h"
#include "pb_decode.h"
#include "pb_encode.h"

namespace {
#define PERIOD_MS 500ms
}

uint8_t buf_in[50], buf_out[50];
static Environment env_in;

int main()
{
    env_in.temperature = 25.0;
    env_in.humidity = 57.6;
    env_in.pressure = 1013.0;

    pb_ostream_t stream_out = pb_ostream_from_buffer(buf_out, sizeof(buf_out));
    pb_istream_t stream_in = pb_istream_from_buffer(buf_in, sizeof(buf_in));

    while (true) {
        printf("Encoding...\n");
        if (!pb_encode(&stream_out, Environment_fields, &env_in)) {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream_out));
            continue;
        }
        printf("%s\n", buf_out);

        printf("Decoding...\n");
        for (size_t i = 0; i < stream_out.bytes_written; ++i) {
            buf_in[i] = buf_out[i];
        }
        if (!pb_decode(&stream_in, Environment_fields, &env_in)) {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream_in));
            continue;
        }
        printf("Decoded values (stub data): temperature: %3.2f, humidity: %3.2f, pressure: %3.2f\n",
                env_in.temperature,
                env_in.humidity,
                env_in.pressure);

        ThisThread::sleep_for(PERIOD_MS);
    }
}
