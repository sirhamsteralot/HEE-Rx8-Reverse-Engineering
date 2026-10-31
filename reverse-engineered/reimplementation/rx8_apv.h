#ifndef RX8_APV_H
#define RX8_APV_H
#include <stdint.h>
/* Arithmetic reconstruction. APV identity is inferred; physical polarity unknown. */
typedef struct { uint16_t channel_a_ticks, channel_b_ticks; } rx8_apv_ticks;
float rx8_apv_scaled_sample(uint16_t sample);
float rx8_apv_signed_fraction(float magnitude_percent, uint8_t direction_flag);
/* Precondition: finite fraction in [-1,1]. No out-of-range ECU behavior modeled. */
rx8_apv_ticks rx8_apv_split_ticks(float fraction, uint16_t period);
#endif
