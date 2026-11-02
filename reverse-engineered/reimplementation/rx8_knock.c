/* Hand reconstruction from this ROM's SH disassembly, not recovered original
 * source. Addresses identify the original routines; the branch structure is
 * kept exactly as decompiled (including where the ROM does NOT write the
 * recovery-target RAM cell). The clamp is the shared rx8_clamp_float 0x2404,
 * which 0x13bd2 calls after its two table lookups; here the lookup results
 * arrive as inputs. Host tests cover ordinary values and edge cases, not SH
 * FPU exception modes or instruction-level rounding. Build without fast-math
 * or contraction when reviewing.
 */
#include "rx8_knock.h"
#include "rx8_math.h"

/* 0x00013a60. Note: the ROM writes 0xffffa744 (recovery_target) only on the
 * sensors-unhealthy and activation-edge paths; on all other paths the cell
 * keeps its previous value, so `recovery_target` is left untouched here too.
 */
float rx8_knock_retard_attack(rx8_knock_state *st, const rx8_knock_inputs *in)
{
    uint8_t previous_active = in->active;
    float target;
    if (in->enable == 0) {
        target = 0.0f;
    } else if (in->sensors_healthy == 0) {
        target = in->failsafe_target;
        st->recovery_target = target;
    } else {
        target = st->retard;
        if (st->active_previous == 0) {
            if (in->active == 1) {
                target = in->learned_target;
                st->recovery_target = target;
            }
        } else if (in->active == 1 && in->attack_condition == 1) {
            target = st->retard - 1.0f;
        }
    }
    st->retard = rx8_clamp_float(target, in->clamp_min, in->clamp_max);
    st->retard_mirror = st->retard;
    st->active_previous = previous_active;
    return st->retard;
}

/* 0x00013b40. Pacing: a step is taken when the selected counter exceeds 61
 * (0x3d), i.e. every 62 counts; the counter is a saturating u8 (0x2478). The
 * transient flag selects counter a74b instead of a74a and zeroes the other.
 */
float rx8_knock_retard_recover(rx8_knock_state *st, const rx8_knock_inputs *in)
{
    float target = st->retard;
    if (in->active == 1 && in->attack_condition == 0) {
        if (in->transient == 0) {
            st->counter_b = 0;
            if (0x3d < st->counter_a) {
                target = st->retard + 0.35f;
                st->counter_a = 0;
            }
            st->counter_a = (uint8_t)rx8_add_u8_saturate(st->counter_a, 1);
        } else {
            st->counter_a = 0;
            if (0x3d < st->counter_b) {
                st->counter_b = 0;
                target = st->retard + 0.35f;
            }
            st->counter_b = (uint8_t)rx8_add_u8_saturate(st->counter_b, 1);
        }
    } else {
        st->counter_a = 0;
        st->counter_b = 0;
    }
    st->retard = rx8_clamp_float(target, in->clamp_min, in->clamp_max);
    st->retard_mirror = st->retard;
    return st->retard;
}
