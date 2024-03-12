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

int main() {
    stdio_init_all();
    printf("Hello, world!\n");
}