/* Hand reconstruction from this ROM's SH disassembly, not recovered original source.
 * Addresses identify the original routines. Branch predicates intentionally retain
 * their ordering: replacing them with fminf/fmaxf changes some NaN behavior.
 * Host tests check ordinary values and selected IEEE-754 edge cases, not SH FPU
 * exception modes, denormal behavior, or instruction-level rounding equivalence.
 * Build without fast-math or contraction when reviewing the host implementation.
 */
#include "rx8_math.h"
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <float.h>
_Static_assert(sizeof(float) == 4 && FLT_RADIX == 2 && FLT_MANT_DIG == 24,
               "Requires IEEE-style binary32 float");

/* 0x000023b0: FR4=current, FR5=previous, FR6=coefficient, FR7=threshold.
 * The exponent mask rejects NaN/Inf previous state before applying the filter.
 * FR0 is the actual return register; automatic inference initially chose R0.
 */
float rx8_first_order_filter(float current, float previous, float coefficient,
                            float snap_threshold)
{
    uint32_t bits;
    memcpy(&bits, &previous, sizeof(bits));
    if ((bits & UINT32_C(0x7f800000)) == UINT32_C(0x7f800000))
        return current;
    float delta = previous - current;
    float gain = 1.0f - coefficient;
    float filtered = current + gain * delta;
    return snap_threshold > fabsf(current - filtered) ? current : filtered;
}

/* 0x000023dc */
float rx8_absolute_difference(float a, float b) { return fabsf(a - b); }
/* 0x000023e4 */
float rx8_max_float(float a, float b) { return a > b ? a : b; }
/* 0x000023f4 */
float rx8_min_float(float a, float b) { return b > a ? a : b; }
/* 0x00002404. No assumption that lower <= upper is inserted. */
float rx8_clamp_float(float value, float lower, float upper)
{
    if (!(value > lower)) return lower;
    return upper > value ? value : upper;
}

/* 0x00002478: both inputs are truncated to uint8 before the add; the sum
 * saturates at 255. Callers (e.g. knock recovery counters 0x13b40) pass u8
 * RAM values, so the truncation is normally a no-op. */
uint32_t rx8_add_u8_saturate(uint32_t left, uint32_t right)
{
    uint32_t sum = (left & 0xffu) + (right & 0xffu);
    return sum > 0xfeu ? 0xffu : sum;
}
