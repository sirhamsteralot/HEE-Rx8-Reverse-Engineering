#include "rx8_math.h"
#include <assert.h>
#include <math.h>
int main(void)
{
    assert(rx8_first_order_filter(10, 2, 0.25f, 0) == 4);
    assert(rx8_first_order_filter(10, 2, 0, 0) == 2);
    assert(rx8_first_order_filter(10, 2, 1, 0) == 10);
    assert(rx8_first_order_filter(10, NAN, 0.5f, 0) == 10);
    assert(rx8_first_order_filter(10, INFINITY, 0.5f, 0) == 10);
    assert(rx8_first_order_filter(10, 9, 0.5f, 0.6f) == 10);
    assert(rx8_first_order_filter(10, 9, 0.5f, 0.5f) == 9.5f);
    assert(rx8_absolute_difference(-3, 4) == 7);
    assert(rx8_clamp_float(5, 0, 10) == 5);
    assert(rx8_clamp_float(-5, 0, 10) == 0);
    assert(rx8_clamp_float(15, 0, 10) == 10);
    assert(rx8_clamp_float(NAN, 0, 10) == 0);
    assert(rx8_max_float(NAN, 4) == 4);
    assert(isnan(rx8_max_float(4, NAN)));
    assert(rx8_min_float(NAN, 4) == 4);
    assert(isnan(rx8_min_float(4, NAN)));
    assert(signbit(rx8_max_float(0.0f, -0.0f)));
    assert(signbit(rx8_min_float(0.0f, -0.0f)));
    assert(rx8_add_u8_saturate(0, 0) == 0);
    assert(rx8_add_u8_saturate(61, 1) == 62);
    assert(rx8_add_u8_saturate(254, 1) == 255);   /* 0xfe < sum -> saturate */
    assert(rx8_add_u8_saturate(255, 1) == 255);
    assert(rx8_add_u8_saturate(200, 200) == 255);
    assert(rx8_add_u8_saturate(0x1ff, 1) == 255);   /* inputs truncated to u8 first */
    assert(rx8_add_u8_saturate(0x100 + 5, 0x100 + 6) == 11);
    return 0;
}
