
#include "rgbdriver.h"
#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdlib.h>

#define RGB_MASK 0b00000010000000110000000000000000
#define RED      17
#define GREEN    16
#define BLUE     25
#define LOW false
#define HIGH true

RGB* rgb_init() {
    gpio_init_mask(RGB_MASK);
    gpio_set_dir_out_masked(RGB_MASK);
    gpio_set_mask(RGB_MASK);
    RGB* rgb = malloc(sizeof(RGB));
    return rgb;
}

void rgb_set(RGB* rgb, bool red, bool green, bool blue) {
    gpio_put(RED, !red);
    gpio_put(GREEN, !green);
    gpio_put(BLUE, !blue);
}

void rgb_get(RGB* rgb, bool* red, bool* green, bool* blue) {
    *red = !gpio_get(RED);
    *green = !gpio_get(GREEN);
    *blue = !gpio_get(BLUE);
}

void rgb_off(RGB* rgb) {
    rgb_set(rgb, false, false, false);
}

void rgb_blink(RGB* rgb, bool r, bool g, bool b, int ms) {
    rgb_set(rgb, r,g,b);
    sleep_ms(ms/2);
    rgb_off(rgb);
    sleep_ms(ms/2);
}

void rgb_free(RGB* rgb) {
    free(rgb);
}