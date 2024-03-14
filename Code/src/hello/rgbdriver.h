#ifndef RGBDRIVER_H
#define RGBDRIVER_H

#include <stdbool.h>

struct RGB_ {};

typedef struct RGB_ RGB;

RGB* rgb_init(void);

void rgb_set(RGB* rgb, bool r, bool g, bool b);
void rgb_get(RGB* rgb, bool* r, bool* g, bool* b);
void rgb_off(RGB* rgb);
void rgb_blink(RGB* rgb, bool r, bool g, bool b, int ms);

void rgb_free(RGB* rgb);


#endif // RGBDRIVER_H