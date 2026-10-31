#!/usr/bin/env python3
"""Append reviewed knock-control / loop-mode aliases to the curated TSVs (idempotent).

Runs before annotate_source_review.py and name_lookup_variables.py in
scripts/rebuild.sh, so the evidence notes and the named views pick the rows up.
Rows are keyed by address (functions, RAM) or by original token (lookup tables);
an existing row with the same key but a different alias aborts the pass.
"""
from pathlib import Path
import csv, json, sys

b = Path(__file__).resolve().parents[1]

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("00013826", "knock_enable_gate", "high",
     "Sets DAT_ffffa73d: engine-running timer 0xffffa424 >= 0x177, coolant >= 10 C, load >= tbl 0x6af54 (0.5 flat, RPM axis 800-9600), RPM < 5000."),
    ("0001388a", "knock_sensor_health_gate", "high",
     "Sets DAT_ffffa73e = (0xffffcd64 && 0xffffcd66); both set by 0x49fac after >30 healthy knock-sensor counts."),
    ("000138b2", "knock_active_gate", "high",
     "Sets DAT_ffffa73c = DAT_ffffa73d && DAT_ffffa73e; gates attack (0x13a60) and slow recovery (0x13b40)."),
    ("000139c4", "knock_retard_learn_to_eeprom", "high",
     "When DAT_ffffa73f set: filters knock_retard_ffffa734 toward EEPROM 0xffff8038 (rx8_first_order_filter 0.0039/1e-05), clamps via 0x13bd2, writes back with ref_updateMemoryAtAddress_float."),
    ("00013a60", "knock_retard_attack", "high",
     "Knock retard target: disabled (a73d==0) -> 0; sensors unhealthy (a73e==0) -> tbl 0x6afa4(RPM); activation edge (a74c==0 && a73c==1) -> tbl 0x6afb8(learned retard); active && attack condition (c05c==1) -> -1.0 deg/cycle (retard is negative, clamped <= 0). Writes a744, then clamped a734 = 0x13bd2(result), mirror a738."),
    ("00013b40", "knock_retard_slow_recovery", "high",
     "Active && !c05c: +0.35 deg per 62 counts (two u8 saturating counters a74a/a74b selected by c05d); result clamped via 0x13bd2, mirror a738 updated."),
    ("00013bd2", "knock_retard_clamp", "high",
     "Clamps param to [tbl 0x6af68 (alt 0x6af7c when DAT_ffffb534==1 && 4<DAT_ffffbc3d), tbl 0x6af90](RPM) via rx8_clamp_float and returns it (SH fr0). Export bug fixed by review_knock_loop_labels_apply.py: was void with discarded clamp result."),
    ("000125bc", "knock_retard_apply_leading", "high",
     "a648 = ((a734 - a6ac) - max(a750, c9a0)) + a5e0 + b288 - a66c: knock retard minus rough correction, minus max(coolant derate, cold-start reduction), plus idle/base term, plus A/C retard, minus trim."),
    ("000125f6", "knock_retard_apply_trailing", "high",
     "Trailing mirror of 0x125bc using a738/a6b0/a754/c9a4/b28c -> a658."),
    ("000123ba", "leading_timing_add_corrections", "high",
     "a634 = a640 + a648: base leading timing plus total corrections."),
    ("000123ca", "trailing_timing_add_corrections", "high",
     "a63c = a650 + a658: base trailing timing plus total corrections."),
    ("00011f00", "leading_base_timing_calc", "high",
     "RX8Defs 'Ignition Leading - Base Timing' plate; blends calibrated base with open-loop cap by weight b118; safe-mode cap via b12d."),
    ("0001206c", "trailing_base_timing_calc", "high",
     "RX8Defs 'Ignition Timing Trailing Base' plate; same blend structure as 0x11f00."),
    ("00049fac", "knock_sensor_health_persistence", "high",
     "0xffffa325==0 (no fault) for >30 counts -> cd64=cd66=1; fault 1/2 -> cd67/cd65 with counters cd68/cd6a/cd6c; cleared by DTC 0x23/0x24 active or d1c5."),
    ("0004a084", "knock_sensor_dtc_report", "high",
     "Raises DTC 0x23/0x24 via FUN_0005fd38 from cd65/cd67 (cd64/cd66 reported as status 2)."),
    ("000336c4", "knock_threshold_setup", "high",
     "3D load/RPM level tables 0x6b2b8/0x6b2f0/0x6b2d4/0x6b304 -> a328; raw u16 thresholds 0x6b270/0x6b27c and 0x6b288/0x6b294 -> c090/c092 -> a37e/a37c (defaults 94/193); stability check -> c05d and c0ac hold counter; latches c078 = a324."),
    ("00033632", "knock_filter_constants_init", "high",
     "Sets c060=0.0625, c064~0.1289, c068=0.0078125, c05d=0 (calm-state filter constants; 0x336c4 switches to 0.15625 / ROM 0x7a23c on transient)."),
    ("00033970", "knock_attack_condition", "high",
     "Sets c05c: knock latched (c078) && engine running (a428) && run timer >= 0xfa && leading and trailing timing both > 5 deg - thresholdA*0.15625 (timing not already deeply retarded)."),
    ("000335e4", "knock_condition_snapshots_init", "high",
     "Resets knock state via 0xc116(0); stores snapshots c06c/c070/c074 (RPM/load/throttle), c098/c09c/c0a0 and constants."),
    ("0000c486", "knock_magnitude_integrate", "high",
     "Knock magnitude core: voltage = (a378 - a326)*5/65536; magnitude vs tbl 0x6b250 minus command-code term; noise filter, per-rotor integrators a33c/a350, baseline a348, combined level a34c; sets a324 = (a364 <= a330), knock detected."),
    ("0000c8dc", "knock_sensor_sci_command", "high",
     "SCI front-end on ATU window: rotor alternation a383/a384, reference select by a386 (ROM 0x7a750/0x7a752), command-code mapping a368->a380/a381 (6/5/4/2/0 bands), send via update_serial_command_bits_3_to_5_and_send or sci0_configure_sync_and_exchange_command."),
    ("0000c3ce", "knock_voltage_sample", "high",
     "a37a = DAT_ffff9ef8 (knock ADC raw); in the 200-2000 RPM window filters into a378; sets a386 = (raw RPM >= 10000)."),
    ("0000c276", "knock_reference_adc_read", "high",
     "a326 = ref_readADCResult(): knock reference-channel ADC."),
    ("0000c116", "reset_knock_state_on_mode_change", "high",
     "Inherited name ref_enableDisableCruiseControl__ is a misnomer: on mode change (a38c != param) only resets a384=0xff, a385=0, a324=0. Callers: 0x335e4 (init, param 0) and 0x339ea (RPM window)."),
    ("000339ea", "knock_state_reset_rpm_window", "high",
     "6500/7000 RPM hysteresis -> 0xc116(1) at/above 7000, 0xc116(0) below 6500; called from 0x19cf4 vehicle-speed task."),
    ("0001c13c", "closed_loop_enable_condition", "high",
     "Computes ae1e (CL allowed: coolant >= 35 C, engine time >= tbl 0x6990c vs catalyst-temp model, open loop inactive b12c==0, O2 in tolerance, no DTC-ish conditions) and ae1f (CL active = ae1e && cd5c==0 && lambda feedback aa80/aa81)."),
    ("0001f0c4", "open_loop_request_condition", "high",
     "Sets b12a=1 when load/throttle exceed 'Closed Loop Fuelling Threshold' tables 0x69d24/0x69d38/0x69d4c/0x69d60/0x69d74 with hysteresis flags b1b6/b1b7, throttle threshold b15c and timers b148/b14e."),
    ("0001ee30", "set_open_loop_flag", "high",
     "Inherited name ref_setClosedLoopBool is a misnomer (polarity): sets b12c = (b12a != 0), i.e. the OPEN-loop flag; b12c blocks closed loop in 0x1c13c and selects open-loop targets in 0x1ee4a."),
    ("0001ee4a", "open_loop_fueling_targets", "high",
     "When b12c==1: open-loop base/tip-in/target/rich-limit lookups (0x69cac/0x69cc0, 0x69e80/0x69e9c, 0x69cd4/0x69d10, safe-mode variants via b12d) -> b120; zeroes b120 in closed loop."),
    ("0005535e", "diag_ol_status_byte", "high",
     "OBD PID 0x0003 'OL Status' high byte: 2 (closed loop) or 0x10 when ae1f==1, 4 (OL-DTC) when ae1e==0, 8 when coolant >= 35 C, 1 when cold."),
    ("000553d8", "diag_ol_status_low_byte", "high",
     "Low byte of the 2-byte PID 0x0003 response; always 0 in this ROM; handler 0x568ca packs FUN_0005535e()<<8 | this."),
    ("000142a4", "ignition_timing_main_task", "high",
     "Task[6] worker chain: runs the knock state machine (0x13826/0x1388a/0x138b2/0x13a60/0x13b40/0x13bd2/0x139c4), correction apply (0x125bc/0x125f6/0x123ba/0x123ca) and base timing (0x11f00/0x1206c) -> leading/trailing_ignition_timing 0xffffa630/a638."),
    ("000145c8", "timing_retard_fast_task", "medium",
     "0x1391c knock-seen counter + 0x13b40 slow recovery + throttle/rev-limit/AC retards; reached from task-table record 0x64e8 (ROM 0x4ab8, dispatch mechanism unresolved)."),
    ("000390b8", "knock_sensor_monitor_task", "medium",
     "0x49fac health persistence + 0x4a084 DTC report + 0x384de/0x3856c monitor counters; reached from task[10] 0x64f6 -> 0x11744."),
    ("000064ba", "knock_sensor_fault_task", "medium",
     "Task[9] entry: runs ref_knockSensorADCFault (0xc290: ADC 0xffff9f0e vs ROM 0xc831/0x3ef9 -> a325 fault status)."),
    ("0001467c", "knock_rough_correction_update", "medium",
     "0x12ed0 + 0x13034 targets + 0x13210 rough knock correction toward a6bc/a6c0 + 0x43870; reached from task[13] 0x65b2 -> 0x118d0."),
    ("00013034", "knock_rough_correction_targets", "high",
     "a6bc/a6c0 rough-knock correction targets from RX8Defs 'Ignition 4..17' descriptors 0x69630-0x6974c."),
    ("0003d010", "o2_monitor_integrator", "medium",
     "c5ec integrator loaded from tbl 0x6b61c vs catalyst-temp model, decays by MAF*0.1; out-of-tolerance check in 0x3cd06 sets c5fc/c5fd; 0x3ccec calls it then sets c5f0=-40.0, c5f4=200.0."),
    ("00022144", "evap_open_loop_condition", "medium",
     "b319 = 1 iff b318 && b12c==1 (open loop) && be00 >= 66.5 && ae1f==0 && !b2f6 && !b0c8 && !b0c9; reached from ref_evapRelated 0x21b8a."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffa73d", "knock_enable", "uint8", "0001388a", "Set by 0x13826: run timer >= 0x177, coolant >= 10 C, load >= 0.5, RPM < 5000."),
    ("ffffa73e", "knock_sensors_healthy", "uint8", "0001388a", "Set by 0x1388a = cd64 && cd66 (0x49fac health persistence)."),
    ("ffffa73c", "knock_active", "uint8", "00013b40", "Set by 0x138b2 = a73d && a73e; gates attack (0x13a60) and slow recovery (0x13b40)."),
    ("ffffa73f", "knock_seen_learn_trigger", "uint8", "000139c4", "When set, 0x139c4 learns the current retard into EEPROM 0xffff8038."),
    ("ffffa748", "knock_seen_counter", "uint16", "0001391c", "Incremented by 0x1391c on knock-seen events (called from 0x145c8)."),
    ("ffffa744", "knock_recovery_target", "float", "00013a60", "Attack/recovery target written by 0x13a60: 0 when disabled, tbl 0x6afa4 when sensors unhealthy, tbl 0x6afb8 on activation edge, else previous retard."),
    ("ffffa74a", "knock_recovery_counter_a", "uint8", "00013b40", "Slow-recovery pacing counter (c05d==0 path); +0.35 deg per 62 counts."),
    ("ffffa74b", "knock_recovery_counter_b", "uint8", "00013b40", "Slow-recovery pacing counter (c05d==1 path)."),
    ("ffffa74c", "knock_active_previous", "uint8", "00013a60", "Previous a73c; activation-edge detection (a74c==0 && a73c==1)."),
    ("ffffa738", "knock_retard_mirror", "float", "000125f6", "Copy of clamped a734 written by 0x13a60/0x13b40; consumed by 0x125f6 trailing apply."),
    ("ffffa324", "knock_detected", "uint8", "000336c4", "Set by 0xc486: a364 <= a330 (integrated knock level over threshold); latched into c078 by 0x336c4."),
    ("ffffa384", "knock_rotor_index", "uint8", "0000c8dc", "Rotor/channel index 0xff (init) or 0/1; alternates per ATU window in 0xc8dc."),
    ("ffffc078", "knock_detected_latched", "uint8", "00033970", "0x336c4 latches a324 here; 0x33970 requires it for the attack condition c05c."),
    ("ffffc05c", "knock_attack_condition", "uint8", "00013a60", "Set by 0x33970: knock latched && running && timing not already deeply retarded; selects -1.0 deg/cycle attack in 0x13a60."),
    ("ffffc05d", "knock_transient_flag", "uint8", "00013b40", "Set by 0x336c4 stability check (0 = stable); selects recovery counter a74a vs a74b and filter constants."),
    ("ffffc060", "knock_filter_coeff_a", "float", "0000c486", "Noise-step scale 0.0625 (calm) / 0.15625 (transient); used in the 0xc486 integrator step."),
    ("ffffc064", "knock_filter_coeff_b", "float", "0000c486", "Noise-excess gain ~0.1289; used in the 0xc486 integrator step (x2 on decay)."),
    ("ffffc068", "knock_filter_coeff_c", "float", "0000c486", "Baseline slow-filter coefficient 0.0078125 (calm) / ROM 0x7a23c (transient)."),
    ("ffffa328", "knock_level_threshold", "float", "0000c486", "Selected knock level threshold (from 0x336c4 3D tables); compared against per-rotor noise threshold a350 in 0xc486."),
    ("ffffa37e", "knock_ignition_threshold_a", "uint16", "0000c7ba", "Threshold A (default 94; = c090 from 0x336c4); used by 0xc7ba coil outputs and the 0x33970 attack condition."),
    ("ffffa37c", "knock_ignition_threshold_b", "uint16", "0000c7ba", "Threshold B (default 193; = c092); used by 0xc7ba coil outputs."),
    ("ffffc090", "knock_threshold_a_raw", "uint16", "00033970", "Raw u16 threshold A from tbl 0x6b270 (or alt 0x6b27c when cd60 set); moved to a37e."),
    ("ffffc092", "knock_threshold_b_raw", "uint16", "000336c4", "Raw u16 threshold B from tbl 0x6b288 (or alt 0x6b294 when cd60 set); moved to a37c."),
    ("ffffc0ac", "knock_transient_hold_counter", "uint16", "000336c4", "Counts down tbl 0x6b264 (raw u8 << 1 = 20 cycles) while conditions are stable; expiry sets c05d=1."),
    ("ffffa378", "knock_voltage_sample", "uint16", "0000c486", "Filtered knock ADC sample (u16) from 0xc3ce; converted to volts in 0xc486."),
    ("ffffa326", "knock_voltage_reference", "uint16", "0000c486", "Knock reference-channel ADC (0xc276); subtracted from a378 in 0xc486."),
    ("ffffa37a", "knock_adc_raw", "uint16", "0000c3ce", "Raw knock sensor ADC 0xffff9ef8 read in 0xc3ce."),
    ("ffffa374", "knock_adc_filtered", "float", "0000c3ce", "First-order filtered knock ADC (coeff 0.004, snap 1.0) valid in the 200-2000 RPM window."),
    ("ffffa370", "knock_voltage", "float", "0000c486", "Knock voltage = (a378 - a326) * 5/65536 V."),
    ("ffffa330", "knock_magnitude", "float", "0000c486", "Knock magnitude vs tbl 0x6b250 minus command-code term a381[a384]<<5, clamped >= 0."),
    ("ffffa32c", "knock_noise_filtered", "float", "0000c486", "Filtered (a330 - a348) noise term (coeff c060)."),
    ("ffffa344", "knock_integrator_step", "float", "0000c486", "Per-event integrator step min(|a32c|, c060*|a330 - a334[a384]|), floor 1.0."),
    ("ffffa348", "knock_baseline_slow", "float", "0000c486", "Slow baseline of a330 (coeff c068); part of the combined level a34c."),
    ("ffffa34c", "knock_level_combined", "float", "0000c486", "a33c[a384] + a348, clamped >= 0; stored to a334[a384]."),
    ("ffffa334", "knock_level_running", "float[2]", "0000c486", "Per-rotor running knock level a334[0..1]."),
    ("ffffa33c", "knock_level_integrator", "float[2]", "0000c486", "Per-rotor level integrators a33c[0..1] (+/-= a344)."),
    ("ffffa350", "knock_noise_threshold", "float[2]", "0000c486", "Per-rotor noise thresholds a350[0..1], clamped to [tbl 0x6b2a0 min, a358+8 max]."),
    ("ffffa358", "knock_noise_floor", "float", "0000c486", "Lookup(raw RPM, tbl 0x6b2ac) noise floor; a35c = 2x the excess above it."),
    ("ffffa360", "knock_noise_excess", "float", "0000c486", "a350 - 2x excess, clamped >= 0; drives the threshold command term."),
    ("ffffa364", "knock_threshold_command_base", "float", "0000c486", "Base threshold command (64 + a328*a360 clamped 64..255)."),
    ("ffffa368", "knock_threshold_command", "float[2]", "0000c8dc", "Per-rotor threshold command a368[0..1] = a364 + a360*2; mapped to command codes in 0xc8dc."),
    ("ffffa387", "knock_reference_voltage", "uint8[2]", "0000c8dc", "Per-channel reference bytes from ROM 0x7a750/0x7a752 selected by a386."),
    ("ffffa389", "knock_reference_voltage_latched", "uint8[2]", "0000c486", "Latched a387 values; a change forces a32c = 40 (noise reset)."),
    ("ffffa381", "knock_command_code", "uint8[2]", "0000c486", "Mapped command codes a381[0..1] from a368 (6/5/4/2/0 bands)."),
    ("ffffa380", "knock_command_code_current", "uint8", "0000c8dc", "Current command code a380 sent over SCI."),
    ("ffffa38c", "knock_state_mode", "uint8", "0000c116", "Mode value passed to 0xc116; a change resets rotor index and knock state."),
    ("ffffa386", "high_rpm_10k_flag", "uint8", "0000c8dc", "Set by 0xc3ce when raw RPM >= 10000; selects reference table 0x7a752 vs 0x7a750 (both 01 01 in this ROM)."),
    ("ffffa325", "knock_sensor_fault_status", "uint8", "00049fac", "Knock sensor ADC fault: 0 OK, 1/2 per-channel fault (0xc290: ADC 0xffff9f0e vs ROM 0xc831/0x3ef9)."),
    ("ffffcd64", "knock_sensor_healthy_a", "uint8", "0001388a", "Set by 0x49fac after >30 healthy counts (channel A); gates a73e."),
    ("ffffcd66", "knock_sensor_healthy_b", "uint8", "0001388a", "Channel B counterpart of cd64."),
    ("ffffcd65", "knock_sensor_fault_a", "uint8", "0004a084", "Channel A fault persistence -> DTC 0x23 via 0x4a084."),
    ("ffffcd67", "knock_sensor_fault_b", "uint8", "0004a084", "Channel B fault persistence -> DTC 0x24 via 0x4a084."),
    ("ffffcd68", "knock_sensor_healthy_counter", "uint16", "00049fac", "Healthy-count counter (>30 -> cd64/cd66)."),
    ("ffffcd6a", "knock_sensor_fault_counter_a", "uint16", "00049fac", "Channel A fault counter."),
    ("ffffcd6c", "knock_sensor_fault_counter_b", "uint16", "00049fac", "Channel B fault counter."),
    ("ffffa6ac", "rough_knock_correction_leading", "float", "000125bc", "Per-rotor rough knock correction (leading) from 0x13210; subtracted in 0x125bc."),
    ("ffffa6b0", "rough_knock_correction_trailing", "float", "000125f6", "Trailing counterpart; subtracted in 0x125f6."),
    ("ffffa750", "coolant_timing_derate_leading", "float", "000125bc", "Coolant-based timing derate (leading) from 0x13ecc (a76c * fVar2); max() with cold-start c9a0 in 0x125bc."),
    ("ffffa754", "coolant_timing_derate_trailing", "float", "000125f6", "Trailing counterpart (a770 * fVar2)."),
    ("ffffa648", "leading_timing_correction_total", "float", "000123ba", "Total leading correction written by 0x125bc; added to base in 0x123ba."),
    ("ffffa658", "trailing_timing_correction_total", "float", "000123ca", "Total trailing correction from 0x125f6; added in 0x123ca."),
    ("ffffa634", "leading_timing_with_corrections", "float", "00012300", "a640 + a648 clamped into leading_ignition_timing_ffffa630 (0x12300)."),
    ("ffffa63c", "trailing_timing_with_corrections", "float", "00012300", "a650 + a658 clamped into trailing_ignition_timing_ffffa638."),
    ("ffffb288", "ac_compressor_leading_timing_retard", "float", "000125bc", "A/C compressor timing retard (leading): -5.0 deg while ramping else 0 (0x214f8)."),
    ("ffffb28c", "ac_compressor_trailing_timing_retard", "float", "000125f6", "Trailing counterpart (0x215f8)."),
    ("ffffc9a0", "cold_start_timing_reduction_leading", "float", "000125bc", "Cold-start timing reduction (leading): min(c9a8, tbl 0x6b83c(RPM)) * clamp((ECT+30)*0.01, 0, 1) when ca44==1 && ca3f>1 (0x12630)."),
    ("ffffc9a4", "cold_start_timing_reduction_trailing", "float", "000125f6", "Trailing mirror set in 0x12754."),
    ("ffff9f80", "engine_speed_rpm_raw", "float", "0000c3ce", "Raw RPM = 120e6 / crank period sum (ISR 0x803e); window and 10k-flag checks in 0xc3ce."),
    ("ffff9f88", "crank_period_accumulator", "float", "0000c7ba", "Sum of DAT_ffff9fd0[] periods; RPM denominator (ISR 0x803e); used by 0xc7ba coil scaling."),
    ("ffff9ef8", "knock_sensor_adc_raw", "uint16", "0000c3ce", "Knock sensor ADC result read in 0xc3ce."),
    ("ffffb12a", "open_loop_request", "uint8", "0001ee30", "Set by 0x1f0c4 when load/throttle exceed the closed-loop fuelling thresholds; consumed by 0x1ee30."),
    ("ffffb12c", "open_loop_active", "uint8", "0001c13c", "OPEN-loop flag (polarity corrected): = (b12a != 0), set by 0x1ee30; blocks closed loop in 0x1c13c, selects open-loop targets in 0x1ee4a, gates evap 0x22144. Earlier sessions mislabeled this as the closed-loop flag."),
    ("ffffae1e", "closed_loop_allowed", "uint8", "0005535e", "CL allowed (0x1c13c): warm, warmup time met, not open loop, O2 healthy, no DTC-ish conditions."),
    ("ffffae1f", "closed_loop_active", "uint8", "0005535e", "CL active = ae1e && cd5c==0 && lambda feedback (aa80/aa81); drives the OBD status byte 0x5535e."),
    ("ffffb120", "open_loop_fuel_target", "float", "000306e8", "Open-loop fuel target computed by 0x1ee4a (b130*b134 or b138*b13c blend); zero in closed loop."),
    ("ffffb12d", "safe_mode", "uint8", "00011f00", "0x1ee4a: 1 unless (b534==1 && 4<bc3d) or (b534==0 && 3<baed); selects Safe Mode CAL tables and the base-timing cap in 0x11f00/0x1206c."),
    ("ffffaa80", "lambda_in_target_band", "uint8", "0001c13c", "0x1ac00: 1 when no DTC, 0.99 <= lambda target 0xffffadfc < 1.01, ad0c==1, engine running; CL-active ingredient (ae1f)."),
    ("ffffcd60", "safe_mode", "uint8", "0001ee4a", "0 = safe mode active: selects the knock threshold table pair in 0x336c4 (0x6b270/0x6b288 vs alts) and is checked in 0x200c6."),
    ("ffffc150", "engine_load_delta", "float", "0001391c", "|load - c188| (engine load delta) from 0x34364; c154 holds the signed delta."),
    ("ffffaddc", "intake_air_temperature", "float", "0001a086", "Working copy of intake_air_temperature_ffff9f60 (0x1be00/0x1be4a; fault default 20.0 C at 0x1be54); Kelvin conversion 295/(x+273) at 0x1a086."),
    ("ffffa424", "engine_running_timer", "uint16", "00013826", "Engine-running time counter (100 Hz); gates knock enable (>= 0x177) and the attack condition (>= 0xfa)."),
    ("ffffa428", "engine_running", "uint8", "00013210", "Engine running flag; zeroes rough knock corrections in 0x13210; ingredient of the attack condition."),
    ("ffffa426", "engine_on_time_counter", "uint16", "00021cde", "Engine on-time counter (0x21cde)."),
    ("ffffa42c", "engine_injectors_off", "uint8", "0003d010", "Injectors-off flag checked by the 0x3d010 O2 monitor integrator."),
]

LOOKUP = [
    # original token, alias, evidence
    ("DAT_0006af54", "tbl_knock_enable_load_floor_0006af54",
     "12 u8 cells, all 0x32 x mult 0.01 = 0.5 flat load floor; RPM axis 0x795e8 (800-9600); used by knock_enable_gate 0x13826."),
    ("PTR_DAT_0006af68", "tbl_knock_retard_clamp_min_0006af68",
     "u8 cells 0x6c(108) -> -10 deg ... 0x80 -> 0 vs RPM 2000-5000 (axis 0x79624); retard clamp minimum in knock_retard_clamp 0x13bd2."),
    ("PTR_DAT_0006af7c", "tbl_knock_retard_clamp_min_alt_0006af7c",
     "u8 cells -10/-7.5/-5/-5/-5/-5/0 vs RPM (axis 0x79648); alternative minimum selected when b534==1 && 4<bc3d (0x13bd2)."),
    ("DAT_0006af90", "tbl_knock_retard_clamp_max_0006af90",
     "15 u8 cells all 0x80 -> 0.0 deg vs RPM 800-6400 (axis 0x7966c); retard clamp maximum (retard is <= 0)."),
    ("DAT_0006afa4", "tbl_knock_recovery_target_0006afa4",
     "u8 cells -10 x9, -8, -6, -4, -2, 0, 0 vs RPM 500-5500 (axis 0x796b8); recovery target when knock sensors unhealthy (0x13a60)."),
    ("DAT_0006afb8", "tbl_knock_learned_retard_scale_0006afb8",
     "13 u8 cells all 0x80 -> 0.0; axis 0x79704 = learned EEPROM retard -8.4..+8.4 deg; activation-edge target (0x13a60)."),
    ("PTR_DAT_0006b264", "tbl_knock_transient_hold_0006b264",
     "{count=1, type=0}; data byte 0x0a -> raw_u8 lookup << 1 = 20-cycle transient hold counter (0x336c4)."),
    ("PTR_DAT_0006b27c", "tbl_ignition_timing_threshold_a_alt_0006b27c",
     "Raw u16 2D threshold A alternative selected when cd60 set (0x336c4); pair with 0x6b270."),
    ("PTR_DAT_0006b294", "tbl_ignition_timing_threshold_b_alt_0006b294",
     "Raw u16 2D threshold B alternative selected when cd60 set (0x336c4); pair with 0x6b288."),
    ("DAT_0006b2b8", "tbl_knock_level_3d_a_0006b2b8",
     "3D 20x12 scaled (type 0x0c, mult 0.05) knock level vs load/RPM; -> a328 (0x336c4)."),
    ("DAT_0006b2d4", "tbl_knock_level_3d_b_0006b2d4",
     "3D 20x12 scaled knock level table B (0x336c4)."),
    ("DAT_0006b2f0", "tbl_knock_level_3d_c_0006b2f0",
     "3D 1x1 raw knock level table C (0x336c4)."),
    ("DAT_0006b304", "tbl_knock_level_3d_d_0006b304",
     "3D 1x1 raw knock level table D (0x336c4)."),
    ("DAT_0006990c", "tbl_closed_loop_warmup_time_0006990c",
     "Raw u16 2D, 15 cells vs catalyst-temp-model axis 0x6f7e0 (data 0x6f81c); engine warmup time before closed loop is allowed (0x1c13c). Overrides the generated RX8Defs descriptor alias on rebuild."),
    ("tbl_table_2d_304_check_datatype_0006990c", "tbl_closed_loop_warmup_time_0006990c",
     "Chained rename of the auto RX8Defs descriptor name already integrated into current exports; same table as the row above."),
]

BASIS = "source_review_knock_loop"


def read_rows(path, fields):
    if not path.exists():
        return []
    with path.open(newline='') as f:
        return list(csv.DictReader(f, delimiter='\t'))


def write_rows(path, fields, rows):
    with path.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter='\t')
        w.writeheader()
        w.writerows(rows)


def main():
    # Fail fast on missing targets before touching anything.
    index = {r['address'] for r in read_rows(b / 'decompiled/function_index.tsv',
                                             ['address', 'name', 'size', 'status', 'file'])}
    for a, alias, conf, ev in FUNCTIONS:
        assert a in index, 'function %s not in index' % a
    for a, alias, typ, reader, ev in RAM:
        assert list((b / 'decompiled/functions').glob(reader + '_*')), 'reader %s has no function file' % reader

    added_fn = added_ram = added_lut = 0
    conflicts = []

    p = b / 'source_review/accepted_function_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'confidence', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, conf, ev in FUNCTIONS:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('function %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev})
        added_fn += 1
    if not conflicts:
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    p = b / 'source_review/accepted_ram_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, typ, reader, ev in RAM:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('ram %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'type': typ, 'reader': reader, 'evidence': ev})
        added_ram += 1
    if not conflicts:
        write_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'], rows)

    p = b / 'source_review/accepted_lookup_aliases.tsv'
    fields = ['original', 'alias', 'basis', 'evidence']
    rows = read_rows(p, fields)
    pairs = {(r['original'], r['alias']) for r in rows}
    for orig, alias, ev in LOOKUP:
        if (orig, alias) in pairs:
            continue
        rows.append({'original': orig, 'alias': alias, 'basis': BASIS, 'evidence': ev})
        added_lut += 1
    if not conflicts:
        write_rows(p, fields, rows)

    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')

    # Keep the source_review record counts in step with the TSVs.
    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text()) if vp.exists() else {
        'date': '2026-10-29', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['date'] = '2026-10-29'
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    vp.write_text(json.dumps(val, indent=2) + '\n')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
