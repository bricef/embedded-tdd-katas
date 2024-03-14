/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#ifdef BUILD_LOCAL
    #include "mock-pico.h"
#else
    #include "pico/stdlib.h"
#endif

#include "rgbdriver.h"


int main() {
    // stdio_init_all();
    // printf("Hello, world!\n");

    RGB* rgb = rgb_init();

    while (true){
        rgb_blink(rgb, 1,0,0, 500);
        rgb_blink(rgb, 1,0,0, 500);
        rgb_blink(rgb, 1,0,0, 500);

        rgb_blink(rgb, 0,1,0, 500);
        rgb_blink(rgb, 0,1,0, 500);

        rgb_blink(rgb, 0,0,1, 500);
    }

}