/* Reconstructed from 60E15120 ROM instruction/register dataflow.
 * Wiring context: 13Electrical.pdf pp16-17, high-power APV at connector B1-37.
 * PCM 3J/3G are motor wires; mapping to MCU bits/direction is NOT confirmed.
 * This module models arithmetic only, with no hardware access or scheduler.
 * Names express the supported APV hypothesis, not recovered original symbols.
 */
#include "rx8_apv.h"

/* 0x43a86 -> 0x24c0: zero offset + uint16 sample * float(0x38a00000).
 * Actual RAM path: 0xffff9ef0 -> 0xffffcab0; source ADC register 0xfffff80c.
 * A voltage interpretation is plausible; no physical voltage was measured.
 */
float rx8_apv_scaled_sample(uint16_t sample)
{
    return 0.0f + (float)sample * 0x1.4p-14f; /* exactly 5/65536 */
}

/* 0x31bec: RAM 0xffffbf84, flag 0xffffbf8b; FR4 argument to 0xaa90. */
float rx8_apv_signed_fraction(float magnitude_percent, uint8_t direction_flag)
{
    float command = magnitude_percent;
    if (direction_flag == 1) command = -command;
    return command / 100.0f;
}

/* 0xaa90: period is read from ROM uint16 at 0x78bb6, value 96 in this ROM.
 * Output corresponds to RAM 0xffffa1c4 and 0xffffa1c6. No saturation is added.
 * For the documented input domain, int32 truncation matches the finite FTRC
 * conversion, followed by a low-16-bit store. NaN/Inf/overflow are unmodeled.
 */
rx8_apv_ticks rx8_apv_split_ticks(float fraction, uint16_t period)
{
    float scaled = fraction * (float)period;
    rx8_apv_ticks result;
    if (scaled < 0.0f) {
        result.channel_a_ticks = 0;
        result.channel_b_ticks = (uint16_t)(int32_t)(-scaled);
    } else {
        result.channel_a_ticks = (uint16_t)(int32_t)scaled;
        result.channel_b_ticks = 0;
    }
    return result;
}
