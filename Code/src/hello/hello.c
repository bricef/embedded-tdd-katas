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


#define RGB_MASK 0b00000010000000110000000000000000
#define RED      17
#define GREEN    16
#define BLUE     25
#define LOW false
#define HIGH true

int main() {
    stdio_init_all();
    printf("Hello, world!\n");
    gpio_init_mask(RGB_MASK);
    gpio_set_dir_out_masked(RGB_MASK);
    gpio_set_mask(RGB_MASK);
    while (true){
        gpio_put(RED, LOW);
        sleep_ms(500);
        gpio_put(RED, HIGH);
        
        gpio_put(GREEN, LOW);
        sleep_ms(500);
        gpio_put(GREEN, HIGH);

        gpio_put(BLUE, LOW);
        sleep_ms(500);
        gpio_put(BLUE, HIGH);
    }

}