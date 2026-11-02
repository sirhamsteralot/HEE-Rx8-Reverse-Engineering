#include "rx8_knock.h"
#include <assert.h>
#include <math.h>

static rx8_knock_inputs base_inputs(void)
{
    rx8_knock_inputs in = {1, 1, 1, 0, 0, -10.0f, -2.8f, -10.0f, 0.0f};
    return in;
}

static rx8_knock_state base_state(void)
{
    rx8_knock_state st = {-3.0f, -3.0f, 777.0f, 1, 0, 0};
    return st;
}

int main(void)
{
    /* --- 0x13a60 attack / hold / edge selection --- */
    {   /* disabled -> target 0, clamped to [min,max]; recovery_target untouched */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        in.enable = 0;
        assert(rx8_knock_retard_attack(&st, &in) == 0.0f);
        assert(st.retard == 0.0f && st.retard_mirror == 0.0f);
        assert(st.recovery_target == 777.0f);
        assert(st.active_previous == 1);
    }
    {   /* sensors unhealthy -> fail-safe target, written to recovery_target */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        in.sensors_healthy = 0;
        in.failsafe_target = -6.0f;
        assert(rx8_knock_retard_attack(&st, &in) == -6.0f);
        assert(st.recovery_target == -6.0f);
        assert(st.retard_mirror == -6.0f);
    }
    {   /* activation edge (prev=0, active=1) -> learned value from tbl 0x6afb8 */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        st.active_previous = 0;
        in.learned_target = -2.8f;
        assert(rx8_knock_retard_attack(&st, &in) == -2.8f);
        assert(st.recovery_target == -2.8f);
        assert(st.active_previous == 1);   /* latches the entry value of active */
    }
    {   /* edge path but active==0 -> hold previous retard, target cell untouched */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        st.active_previous = 0;
        in.active = 0;
        assert(rx8_knock_retard_attack(&st, &in) == -3.0f);
        assert(st.recovery_target == 777.0f);
        assert(st.active_previous == 0);
    }
    {   /* active + attack condition -> -1.0 deg/cycle */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        in.attack_condition = 1;
        assert(rx8_knock_retard_attack(&st, &in) == -4.0f);
        assert(st.recovery_target == 777.0f);
    }
    {   /* attack clamps at the min table (-10 deg) */
        rx8_knock_state st = {-9.5f, -9.5f, 0, 1, 0, 0};
        rx8_knock_inputs in = base_inputs();
        in.attack_condition = 1;
        assert(rx8_knock_retard_attack(&st, &in) == -10.0f);
    }
    {   /* active but no attack condition -> hold */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        assert(rx8_knock_retard_attack(&st, &in) == -3.0f);
    }
    {   /* previous active but now inactive -> hold (no attack branch taken) */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        in.active = 0;
        in.attack_condition = 1;
        assert(rx8_knock_retard_attack(&st, &in) == -3.0f);
    }
    {   /* learned target above the max table clamps to max (0 deg) */
        rx8_knock_state st = base_state();
        rx8_knock_inputs in = base_inputs();
        st.active_previous = 0;
        in.learned_target = 5.0f;
        assert(rx8_knock_retard_attack(&st, &in) == 0.0f);
    }

    /* --- 0x13b40 slow recovery pacing --- */
    {   /* counter at 61: no step yet, counter -> 62 */
        rx8_knock_state st = {-3.0f, -3.0f, 0, 1, 61, 7};
        rx8_knock_inputs in = base_inputs();
        assert(rx8_knock_retard_recover(&st, &in) == -3.0f);
        assert(st.counter_a == 62 && st.counter_b == 0);
    }
    {   /* counter at 62 (> 0x3d): step +0.35 deg, counter restarts at 1 */
        rx8_knock_state st = {-3.0f, -3.0f, 0, 1, 62, 0};
        rx8_knock_inputs in = base_inputs();
        float r = rx8_knock_retard_recover(&st, &in);
        assert(r == -3.0f + 0.35f);
        assert(st.counter_a == 1 && st.counter_b == 0);
        assert(st.retard_mirror == r);
    }
    {   /* transient flag selects counter_b and zeroes counter_a */
        rx8_knock_state st = {-3.0f, -3.0f, 0, 1, 9, 62};
        rx8_knock_inputs in = base_inputs();
        in.transient = 1;
        float r = rx8_knock_retard_recover(&st, &in);
        assert(r == -3.0f + 0.35f);
        assert(st.counter_a == 0 && st.counter_b == 1);
    }
    {   /* recovery step clamps at the max table (0 deg) */
        rx8_knock_state st = {-0.2f, -0.2f, 0, 1, 62, 0};
        rx8_knock_inputs in = base_inputs();
        assert(rx8_knock_retard_recover(&st, &in) == 0.0f);
    }
    {   /* not active -> both counters reset, retard held (clamped) */
        rx8_knock_state st = {-3.0f, -3.0f, 0, 1, 30, 40};
        rx8_knock_inputs in = base_inputs();
        in.active = 0;
        assert(rx8_knock_retard_recover(&st, &in) == -3.0f);
        assert(st.counter_a == 0 && st.counter_b == 0);
    }
    {   /* active but attack condition set -> counters reset, no recovery */
        rx8_knock_state st = {-3.0f, -3.0f, 0, 1, 30, 40};
        rx8_knock_inputs in = base_inputs();
        in.attack_condition = 1;
        assert(rx8_knock_retard_recover(&st, &in) == -3.0f);
        assert(st.counter_a == 0 && st.counter_b == 0);
    }
    return 0;
}
