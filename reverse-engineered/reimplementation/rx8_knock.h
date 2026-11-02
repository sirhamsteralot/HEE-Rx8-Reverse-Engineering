#ifndef RX8_KNOCK_H
#define RX8_KNOCK_H
/* Readable reconstructions of the knock-retard state machine of
 * 60E15120_N3J1E (see docs/investigations/60E15120_N3J1E/knock_control_report.md).
 * The ROM functions read/write global RAM; here that state is passed
 * explicitly so the logic is host-testable. The 2-D calibration lookups
 * (lookup_2d_descriptor_scaled 0x2068) stay inside the ROM: their results are
 * plain float inputs to these functions. See rx8_knock.c for limits. */
#include <stdint.h>

/* State mirrored from RAM: knock_retard_ffffa734 + mirror _ffffa738,
 * knock_recovery_target_ffffa744, knock_active_previous_ffffa74c,
 * knock_recovery_counter_a/b_ffffa74a/a74b. */
typedef struct {
    float retard;
    float retard_mirror;
    float recovery_target;
    uint8_t active_previous;
    uint8_t counter_a;
    uint8_t counter_b;
} rx8_knock_state;

/* Decision inputs: gate flags knock_enable_ffffa73d, sensors_healthy_ffffa73e,
 * knock_active_ffffa73c, attack_condition_ffffc05c, transient_flag_ffffc05d,
 * plus the lookup results the ROM would compute at the current RPM/learned
 * value: tbl_0x6afa4 (fail-safe), tbl_0x6afb8 (learned), tbl_0x6af68 or alt
 * 0x6af7c (clamp min), tbl_0x6af90 (clamp max). */
typedef struct {
    uint8_t enable;
    uint8_t sensors_healthy;
    uint8_t active;
    uint8_t attack_condition;
    uint8_t transient;
    float failsafe_target;
    float learned_target;
    float clamp_min;
    float clamp_max;
} rx8_knock_inputs;

/* 0x00013a60 knock_retard_attack: pick the retard target (0 when disabled,
 * fail-safe table when sensors unhealthy, learned value on the activation
 * edge, -1.0 deg/cycle under attack condition, hold otherwise), clamp it via
 * 0x00013bd2 semantics, update the mirror and previous-active latch. Returns
 * the new retard. */
float rx8_knock_retard_attack(rx8_knock_state *st, const rx8_knock_inputs *in);

/* 0x00013b40 knock_retard_slow_recovery: while active without attack
 * condition, add +0.35 deg per 62 pacing counts (counter a74a, or a74b when
 * the transient flag is set; both saturating u8), then clamp. Inactive resets
 * both counters. Returns the new retard. */
float rx8_knock_retard_recover(rx8_knock_state *st, const rx8_knock_inputs *in);

#endif
