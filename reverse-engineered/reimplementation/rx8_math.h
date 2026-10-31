#ifndef RX8_MATH_H
#define RX8_MATH_H
/* Readable reconstructions of five ROM helpers. See rx8_math.c for limits. */
float rx8_first_order_filter(float current, float previous, float coefficient, float snap_threshold);
float rx8_absolute_difference(float a, float b);
float rx8_max_float(float a, float b);
float rx8_min_float(float a, float b);
float rx8_clamp_float(float value, float lower, float upper);
#endif
