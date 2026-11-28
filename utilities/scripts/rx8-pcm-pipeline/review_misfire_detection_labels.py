#!/usr/bin/env python3
"""Append reviewed misfire-detection / monitor aliases to the curated TSVs (idempotent).

Covers the crank-fluctuation misfire monitor: the per-crank-tick
dispatch 0x287aa (posted from the CMI10B sector path 0xcf96 -> 0xa156 ->
0x11c98), the sector-period ring copy, the learned-roughness baseline residual
(0x28198/0x2837c), the per-rotor event arm/count chain (0x27fb4/0x28022 ->
0x447e2/0x4489c -> 0x26a42/0x26b34), the sustained window (0x44436) and the two
DTC evaluation windows (0x44b46 -> 0x44cec at 400 ticks, 0x445ba -> 0x44724 at
2000 ticks -> dtc_set_fault_xdefault 0x5fd3c slots 0/1 = P0300/P0301/P0302).
Writes data/labels/60E15120_N3J1E/misfire_detection_labels.json and moves the
misfire_* entries out of the eeprom_content record (storage layer stays there).

Runs after review_eeprom_content_labels.py and before annotate_source_review.py
in scripts/rebuild.sh.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py)
BASIS = 'misfire_detection'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("000287aa", "misfire_monitor_tick", "high",
     "Per-crank-tick misfire pass, SR-masked (jsr 0x3920 at 0x287b0, tail jmp @r3 at 0x28994 to the SR restore): 44 jsr calls in body 0x287aa-0x288be in the order 0x2711a, 0x26940, 0x26982, 0x280be, 0x28118, 0x28198, 0x2842c, 0x44a78, 0x44a9e, 0x26934, 0x2853c, 0x28648, 0x26bda, 0x26d04, 0x26d5c, 0x26d70, 0x26f38, 0x26fc0, 0x28b10, 0x28b50, 0x271b0, 0x27306, 0x27390, 0x273d4, 0x27520, 0x276ec, 0x2837c, 0x27fb4, 0x28022, 0x447e2, 0x4489c, 0x4493a, 0x26a42, 0x26aa0, 0x4499c, 0x449e4, 0x44a1e, 0x4441e, 0x44436, 0x44b16, 0x44b46, 0x4458a, 0x445ba (pool-resolved targets verified in the disassembly). Called from crank_tick_message_handler 0x11c98 (group-1 rec[9] @ ROM 0xd98c, posted by 0xcf96 via 0xa156)."),
    ("00026940", "misfire_sector_ring_copy", "high",
     "8-float copy: DAT_ffffb664..0xffffb680 = DAT_ffffa390..0xffffa3ac (sector-period ring written by crank_edge_period_update 0xcf96). 66-byte body, all mov.l pairs; called from 0x287aa."),
    ("00026982", "sector_parity_latch", "high",
     "DAT_ffffb660 = DAT_ffffa3b0 = crank sector slot index 0..5 latched in the CMI10B sector path (0xcf96 writes 0xffffa3b0); &1 selects the rotor bank everywhere in the monitor. Called from 0x287aa."),
    ("000280be", "misfire_high_rpm_flag", "high",
     "DAT_ffffba70 = (5000.0 <= engine_speed_rpm_ffffb548); DAT_ffffba60 = (ba70 != 0); DAT_ffffba5e = 9, DAT_ffffba5f = 0xc (mov #imm at 0x280b8/0x280bc). Called from 0x287aa."),
    ("00028118", "misfire_sector_counter", "high",
     "While engine_stopped_latch 0xffffa41c == 0: DAT_ffffba5c saturates up at 0x8000 (rx8_add_u16_saturate 0x2460) and DAT_ffffba6c = max(DAT_ffffb67c - DAT_ffffb680, 0.0) (rx8_max_float 0x23e4). Called from 0x287aa."),
    ("00026934", "misfire_aux_pool_update", "medium",
     "12-byte body: calls FUN_0000cf30(DAT_ffffba5e, DAT_ffffba5f) with ba5e=9/ba5f=0xc from 0x280be. Called from 0x287aa."),
    ("0002853c", "misfire_threshold_a_calc", "high",
     "DAT_ffffba78 = DAT_ffffba74 (one-tick delay); fVar4 = lookup_3d(load 0xffffc0b4, rpm 0xffffb548, tbl 0x6a630 [10x17, x 0.16..1.1, y 780..8500, data 3.75..45.86]); coolant correction lookup_2d(coolant 0xffffa98c, tbl 0x6a5e0 when 0xffffb53a==1 else 0x6a5f4 [9 cells, -40..120 C, raw 128 = x1.0]) selected when DAT_ffffba60!=0: ba74 = corr * fVar4 (ba88 = corr), else ba74 = ba94 + ba84 * fVar4 with ba84 = same coolant table and ba94 = 40.0 (pool 0x74d38) when 0xffffa6b7, 40.0 (0x74d3c) when 0xffffa6b8, else 0.0 (0x74d40). Pools verified: 0x2861c=0x6a630, 0x2862c=0x6a5e0, 0x28630=0x6a5f4, 0x28638=0x74d38. Called from 0x287aa."),
    ("00028648", "misfire_threshold_b_calc", "high",
     "Same shape as 0x2853c for the secondary threshold: DAT_ffffba80 = DAT_ffffba7c (delay); 3D tbl 0x6a644 (10x17, data 6..125) x coolant tbl 0x6a608/0x6a61c -> ba7c (ba90 = corr) when ba60, else ba98 + ba8c*fVar4 with 40.0 constants (pools 0x2873c=0x74d44, 0x28740=0x74d48). Pools verified: 0x28720=0x6a644, 0x28730=0x6a608, 0x28734=0x6a61c. Called from 0x287aa."),
    ("00026bda", "misfire_load_delta_gate", "medium",
     "DAT_ffffb6b0 = lookup_2d(rpm, tbl 0x6a658 when DAT_ffffba5c < 0x33 else 0x6a66c [18 cells, 500..9000 rpm, raw 26 = x0.203]); if engine_load_delta 0xffffc150 < b6b0: b6aa pulse (set 1 when b6b8==0, else b6b8-- and clear), else b6b8=0, b6aa=0. Called from 0x287aa."),
    ("00026d04", "misfire_persistence_count", "medium",
     "If DAT_ffffb6ad==1: clears b6ab/b6a8/b6ad; else b6a8 = saturate(b6a8+1, 0xff) (0x2460) and b6ab = (b6a8 != 0). Called from 0x287aa."),
    ("00026d5c", "misfire_load_floor_lookup", "high",
     "DAT_ffffb698 = lookup_2d_descriptor_scaled(rpm 0xffffb548, tbl 0x6a680 [18 cells, 1000..9000 rpm, 20..71 raw]). Called from 0x287aa; consumed by the enable window 0x26d70."),
    ("00026d70", "misfire_enable_window", "high",
     "DAT_ffffb6ac = 1 only when b6aa!=0 && DAT_ffffb6a0 >= 3000.0 (pool 0x75450) && b6ab!=0 && DAT_ffffb0ca==0 && coolant 0xffffa98c > 0.0 && DAT_ffffa92c > 0.0 && 660.0 <= rpm < 4500.0 && load 0xffffc0b4 >= b698 && engine_stopped_latch 0xffffa41c == 0 && DAT_ffffd1c5 == 0; else 0. Also bumps b6bc when b6c0==0 && d1c5==0 && b6bf==ba60. Pools verified: 0x26e08=0x75450 (3000.0), 0x26e14=0xffffb6c0, 0x26e18=0xffffb6bf. Called from 0x287aa."),
    ("00026f38", "misfire_fault_persistence", "medium",
     "If rpm >= 660.0: b6be = 0. If engine not stopped (a41c==0) && b6be==1: b6a4 = 4, b6a6 = 0xf; else if b6ac==0: b6a4 = 0xff, b6a6 = 0xf; else if b6a4!=0: b6a4--. b6a4/b6a6 feed the supply gate 0x26fc0. Called from 0x287aa."),
    ("00026fc0", "misfire_supply_gate", "high",
     "DAT_ffffb69c = 0 when inferred_battery_voltage 0xffffb590 < 11.0 (float pool 0x75474 = 11.0) or (DAT_ffffb6a4 != 0 && DAT_ffffb6a6 != 0), else 1. Pools verified: 0x27020=0x75474, 0x26ff8=0xb590, 0x2700c=0xffffb6a4, 0x27008=0xffffb6a6. Gates the 400/2000-tick counters and both event arms. Called from 0x287aa."),
    ("00028b10", "misfire_window_400_tick", "high",
     "DAT_ffffba9c = 0 when DAT_ffffd1c5==1; else wraps at 400 (0x190) and increments (rx8_add_u16_saturate 0x2460) only while b69c==1. Pools: 0x28ba0=0x0190, 0x28ba8=0x2460. Called from 0x287aa."),
    ("00028b50", "misfire_window_2000_tick", "high",
     "DAT_ffffba9e = 0 and DAT_ffffbaa0 = 1 when DAT_ffffd1c5==1; else wraps at 2000 (0x7d0) and increments while b69c==1. The 400/2000 evaluations fire at ba9c==400 / ba9e==2000 (0x26aa0, 0x44b16/0x44b46, 0x4458a/0x445ba). Called from 0x287aa."),
    ("00027306", "misfire_learn_hold_decay", "medium",
     "If sector_parity_bank 0xffffb660 == 1 and DAT_ffffba04 != 0: DAT_ffffba04-- (learn-hold counter decays once per odd sector). Called from 0x287aa."),
    ("00027390", "misfire_ol_fuel_gate", "medium",
     "DAT_ffffba0c = lookup_2d(open_loop_fuel_target 0xffffb120, tbl 0x6a6ac [5 cells, axis 0..0.5, data 1.25]); DAT_ffffba08 = 0 when DAT_ffffaa70 < ba0c || DAT_ffffb0ca != 0 || DAT_ffffba18 == 0, else 1. Called from 0x287aa."),
    ("000273d4", "misfire_sustained_gate", "medium",
     "DAT_ffffba09 = 1 when (DAT_ffffba80 <= DAT_ffffba50 || ba08==1 || 1 < DAT_ffffcb60) && (1 < DAT_ffffb688 || 1 < DAT_ffffb68a || (DAT_ffffc928 < 0.85 || 1.15 < DAT_ffffc928)) && DAT_ffffba04 != 0. Called from 0x287aa."),
    ("00027520", "misfire_learn_steady_state", "high",
     "DAT_ffffba0a = 1 (learn allowed) only when b69c==1 && engine_running_timer 0xffffa424 >= 0x9c4 (2500) && injectors not off (0xffffa42c==0) && DAT_ffffba19 < 8 && |DAT_ffffad50| within tolerance band && engine_load_delta 0xffffc150 < 1.05 && DAT_ffffb0ca==0 && DAT_ffffba1a < 0x10 && coolant 0xffffa98c >= 70.0 && 660.0 <= rpm < 8500.0 && DAT_ffffaa81==0 && DAT_ffffba1c==0 && DAT_ffffba1b < 8 && DAT_ffffb2f0 > 0.0 (else 0.2 < DAT_ffffb220) && DAT_ffffb2f4 >= 0x271; on fail ba06 = 8, on pass ba06 decays. Pools: 0x2765c=0x2440, 0x27660=0x23dc, 0x27664=0xffffba0a, 0x27668=0xffffba06. Called from 0x287aa."),
    ("00026a42", "misfire_event_count", "high",
     "Per rotor bank (sector_parity_bank_ffffb660&1): passes DAT_ffffba24/25 and DAT_ffffba26/27 to 0x26b34 with counter addresses 0xffffb688/0xffffb68e (parity 1) or 0xffffb68a/0xffffb68c (parity 0); clears all counters and DAT_ffffb694 when DAT_ffffd1c5==1. Pools verified: 0x26b08=0xb688, 0x26b0a=0xb68a, 0x26b0c=0xb68c, 0x26b0e=0xb68e, 0x26b10=0xb694, 0x26b28=0xffffba26, 0x26b2c=0xffffba24. Called from 0x287aa."),
    ("00026b34", "misfire_counter_bump", "high",
     "If either event flag == 1: increments both u16 counters (saturate 0xff, mov.w 0x26b8e=0x00ff, helper 0x2460) and sets DAT_ffffb694 = 1, else DAT_ffffb694 = 0 (pools 0x26b90=0xb694). Called from 0x26a42."),
    ("0002842c", "misfire_deviation_delay_line", "high",
     "DAT_ffffba58 = DAT_ffffba54; DAT_ffffba54 = DAT_ffffba50; DAT_ffffba4c = DAT_ffffb668 - DAT_ffffb664 (+ DAT_ffffb67c - DAT_ffffb680 when 0x3b < DAT_ffffba5c || DAT_ffffba6c < 13.133, pool 0x75758); DAT_ffffba50 = max(0, DAT_ffffba4c) (rx8_max_float 0x23e4). Delay line of the sector-speed deviation (ring copies 0xffffb664-0xffffb680 from 0xffffa390-0xffffa3ac via 0x26940). Pools verified: 0x284e4=0xba54, 0x284e6=0xba58, 0x284e8=0xba50, 0x284ea=0xba4c, 0x284ec=0xb664, 0x284ee=0xb668, 0x28500=0xffffba6c, 0x28504=0x23e4. Called from 0x287aa."),
    ("00027fb4", "misfire_event_arm", "high",
     "DAT_ffffba28 = lookup_2d_scaled(rpm 0xffffb548, tbl 0x6a6b8 [17 cells, 700..8500 rpm]); per rotor bank (DAT_ffffb660&1) sets (&DAT_ffffba24)[parity] = 1 when (DAT_ffffb53a==1 || engine_load 0xffffc0b4 >= DAT_ffffba28) && DAT_ffffb69c==1 && DAT_ffffb6c6==1 && DAT_ffffba40 > DAT_ffffba78, cleared otherwise. Arm asm: cmp/eq 0x1 on b53a at 0x27fda, bt/s 0x27fea skips the load compare (fcmp/gt at 0x27fe4, T = ba28 > load) when neutral; b69c/b6c6 compared at 0x27ff0/0x27ffc; final fcmp/gt at 0x2800a requires ba40 > ba78. Pools verified: 0x28058=0xb660, 0x2805c=0xb53a, 0x2805e=0xc0b4, 0x28060=0xb69c, 0x28062=0xb6c6, 0x28064=0xba78, 0x28066=0xba40, 0x2806c=0x6a6b8, 0x28070=0x2068, 0x28074=0xffffba28, 0x28078=0xffffba24. Called from 0x287aa. Corrects the earlier evidence string: the neutral flag and the load floor are OR-ed, not AND-ed."),
    ("00028022", "misfire_event_arm_secondary", "high",
     "Per rotor bank: if DAT_ffffba50 <= DAT_ffffba80 || DAT_ffffb69c != 1 -> (&DAT_ffffba26)[parity] = 0 else 1. Pools verified: 0x28058=0xb660, 0x2807c=0xffffba26, 0x28068=0xba80, 0x2806a=0xba50, 0x28060=0xb69c. Called from 0x287aa."),
    ("000447e2", "misfire_threshold_check_rpm", "high",
     "Per rotor bank: if event flag DAT_ffffba24/25 == 1, clears it when DAT_ffffcb8c*DAT_ffffba44 < DAT_ffffba48 || DAT_ffffcb90*DAT_ffffba44 < DAT_ffffba40 (cb8c/cb90 = RPM lookups tbl 0x6b9f4/0x6ba00 from 0x44a78; ba44/ba48 = delayed DAT_ffffba40), else bumps counters DAT_ffffcb78/0xffffcb7a (0x2460) when DAT_ffffd1c5==0; counters zeroed when d1c5==1. Pools verified: 0x4487e=0xcb78, 0x44880=0xcb7a, 0x44886=0xba44, 0x44888=0xcb8c, 0x4488a=0xcb90, 0x44894=0xffffba24, 0x4488c=0xb660, 0x4488e=0xba48, 0x44890=0xba40, 0x44898=0x2460. Called from 0x287aa."),
    ("0004489c", "misfire_threshold_check_load", "high",
     "Same shape on the secondary flags DAT_ffffba26/27 with DAT_ffffcb94*DAT_ffffba54 < DAT_ffffba58 || DAT_ffffcb98*DAT_ffffba54 < DAT_ffffba50 (cb94/cb98 = load-limit lookups tbl 0x6ba0c/0x6ba18 from 0x44a9e); counters DAT_ffffcb7c/0xffffcb7e. Pools verified: 0x4494e=0xba54, 0x44950=0xcb94, 0x44952=0xcb98, 0x44954=0xcb7e, 0x44956=0xcb7c, 0x44964=0xffffba26, 0x4495a=0xba58, 0x4495c=0xba50, 0x44968=0x2460. Called from 0x287aa."),
    ("00044a78", "misfire_threshold_rpm_lookup", "high",
     "DAT_ffffcb8c = lookup_2d_descriptor_scaled(rpm 0xffffb548, tbl 0x6b9f4 [12 cells, RPM axis 0x7c43c = 780..8500]); DAT_ffffcb90 = lookup_2d_scaled(rpm, tbl 0x6ba00 [12 cells, axis 0x7c49c]). Pools verified: 0x44ac4=0xb548, 0x44ad0=0x6b9f4, 0x44ad4=0x2068, 0x44ac6=0xcb8c, 0x44ad8=0x6ba00, 0x44ac8=0xcb90. Called from 0x287aa."),
    ("00044a9e", "misfire_threshold_load_lookup", "high",
     "DAT_ffffcb94 = lookup_2d_scaled(rpm, tbl 0x6ba0c [12 cells, axis 0x7c4fc, data 0.3..0.75]); DAT_ffffcb98 = lookup_2d_scaled(rpm, tbl 0x6ba18 [12 cells, axis 0x7c55c, data 0.6..0.95]). Used by 0x4489c as cb94*ba54 < ba58 || cb98*ba54 < ba50. Called from 0x287aa."),
    ("0004493a", "misfire_counter_delay", "high",
     "DAT_ffffcb80 = DAT_ffffcb78; DAT_ffffcb82 = DAT_ffffcb7c (one-tick delay of the rpm/load threshold counters). Pools: 0x4495e=0xcb78, 0x4495c... verified 0x4495e=0xcb78, 0x44960=0xcb80, 0x44962=0xcb82, 0x44956=0xcb7c. Called from 0x287aa."),
    ("00026aa0", "misfire_window_snapshot", "high",
     "At DAT_ffffba9c == 400 (0x190): DAT_ffffb690 = max(DAT_ffffcb78, DAT_ffffcb7c); at DAT_ffffba9e == 2000 (0x7d0): DAT_ffffb692 = max(DAT_ffffcb7a, DAT_ffffcb7e); max helper 0x23e4. Pools verified: 0x26b14=0xba9c, 0x26b16=0x0190, 0x26b18=0xcb7c, 0x26b1a=0xcb78, 0x26b30=0x23e4, 0x26b1c=0xb690, 0x26b1e=0xba9e. Called from 0x287aa."),
    ("0004499c", "misfire_count_floor_lookup", "high",
     "When b69c==1 && d1c5==0: DAT_ffffcb84 = min(DAT_ffffcb84, rx8_lookup_3d_raw_u16(load 0xffffc0b4, rpm 0xffffb548, tbl 0x6b9e0 [10x8, x 0.125..1.2, y 500..4000])); init 1000 on d1c5. Called from 0x287aa."),
    ("000449e4", "misfire_load_ceiling_lookup", "medium",
     "DAT_ffffcb88 = lookup_2d_scaled(rpm, tbl 0x6b9cc [13 cells, 700..6500 rpm, raw 58..96]); DAT_ffffcb86 = 0 when cb88 < load 0xffffc0b4 || rpm > 3910.0, else 1. Called from 0x287aa."),
    ("00044a1e", "misfire_high_rpm_latch", "medium",
     "DAT_ffffcb87 = 1 when 5000.0 <= rpm 0xffffb548; 0 when d1c5==1. Called from 0x287aa; gates the 400-tick fault branch 0x44b46."),
    ("0004441e", "misfire_type_count_lookup", "high",
     "DAT_ffffcb64 = lookup_3d_descriptor_scaled(load 0xffffc0b4, rpm 0xffffb548, tbl 0x6b9ac [10x17, x 0.16..1.1, y 780..8500, data 5..79.7]). Called from 0x287aa; feeds the sustained window 0x44436."),
    ("00044436", "misfire_sustained_window", "high",
     "Sustained-event window: if load within [DAT_ffffba50, DAT_ffffba80] && b69c==1 && b53a==0 && !((4000.0 <= rpm (pool 0x44514=0x7bf58) || vehicle_speed 0xffffbbb4 < 0.0 (pool 0x7bf5c)) && !(b694==0 && cb68==0)): bumps DAT_ffffcb60/0xffffcb62 (saturate 1000, mov.w 0x444bc=0x03e8, helper 0x2460); DAT_ffffcb68 = 0x28 when b694 else decays. Pools verified: 0x444ec=0xcb60, 0x444ee=0xcb62, 0x44504=0xffffcb68, 0x444e8=0xd1c5, 0x444f4=0xba50, 0x444f6=0xb694, 0x44510=0xffffcb64, 0x444f8=0xba80, 0x444fa=0xb69c, 0x444fc=0xb53a, 0x44514=0x7bf58 (4000.0), 0x44518=0x7bf5c (0.0), 0x444fe=0xbbb4, 0x4451c=0x2460. Called from 0x287aa."),
    ("00044b16", "misfire_400_threshold", "medium",
     "At DAT_ffffba9c == 400: DAT_ffffcba2 = 100 when DAT_ffffcf90 < 0.0, else DAT_ffffcb84. Called from 0x287aa."),
    ("00044b46", "misfire_dtc_evaluate_400", "high",
     "400-tick DTC evaluation (DAT_ffffba9c==400): uVar3 = encode(decode(1.0,0,b690) * decode(0.5,0,lookup_2d_raw_u16(rpm, tbl 0x6ba24 [23 cells, 400..9200])), 1.0, 0); if b690 < cba2 || uVar3 < cb60: cb9d=1 (and cb9e=0) unless cb87==1 (rpm>=5000 latch); else cb9e=1, rotor bits cb9f/cba0 from uVar3*0.9 vs counters b688/b68a -> cb9c; calls 0x44cec; then resets cb9c, b688, b68a, cb78, cb7c, cb60, cb84=1000, cb87, cb9f, cba0. Called from 0x287aa."),
    ("00044cec", "misfire_dtc_set_400", "high",
     "Calls dtc_set_fault_xdefault (pool 0x44d54 = 0x5fd3c, ROM-verified) with slot 0: code 4 (or 2 when ref_driveCycleDetectMAYBE_ 0x65690 detects a drive cycle) when DAT_ffffcb9d==1, else code 1 with rotor bits (cb9c&3) when cb9e==1. Pools verified: 0x44d54=0x5fd3c, 0x44d50=0xcb9d, 0x44d58=0x65690, 0x44d52=0xcb9e. DTC slot table 0x7e560 slots 0/1 = 0x0300 (P0300). Called from 0x44b46."),
    ("0004458a", "misfire_2000_threshold", "high",
     "At DAT_ffffba9e == 2000 (0x7d0): DAT_ffffcb72 = 0xff when DAT_ffffcf90 < 0.0, else 100. Pools: 0x44674=0xba9e, 0x44676=0x07d0, 0x44680=0xffffcb72, 0x44678=0xcf90. Called from 0x287aa."),
    ("000445ba", "misfire_dtc_evaluate", "high",
     "Misfire DTC evaluation on the 2000-tick (DAT_ffffba9e == 2000, mov.w 0x445f4=0x07d0): clears cb6d/cb6e/cb6c/cb6f/cb70 when d1c5==1; else fVar4 = decode(1.0, 0, b692) (rx8_decode_u16_affine 0x24c0), cb74 = rx8_lookup_2d_raw_u16(rpm, tbl 0x6b9c0 [23 cells, 400..9200 rpm]), fVar5 = decode(0.5, 0, cb74), uVar2 = encode(fVar4*fVar5, 1.0, 0) (0x2490); if b692 < cb72 || uVar2 < cb62 -> cb6d=1 (pending) else cb6e=1 (confirmed) with rotor bits cb6f/cb70 from encode(fVar4*0.9) vs counters b68c/b68e -> cb6c; then bsr 0x44724 (asm 0x446ea) and resets cb6c, b68c, b68e, cb7a, cb7e, cb62, baa0, cb6f, cb70. Pools verified: 0x4466a=0xcb6d, 0x4466e=0xcb6c, 0x44670=0xcb6f, 0x44672=0xcb70, 0x44666=0xd1c5, 0x4466c=0xcb6e, 0x44674=0xba9e, 0x44676=0x07d0, 0x4467a=0xb692, 0x44690=0x24c0, 0x4467c=0xb548, 0x44694=0x6b9c0, 0x44698=0x20c4, 0x4469c=0xffffcb74, 0x446a4=0x2490, 0x44680=0xffffcb72, 0x4467e=0xcb62, 0x4478e=0xcb6e, 0x44790=0xb68c. Called from 0x287aa."),
    ("00044724", "misfire_dtc_set", "high",
     "Calls dtc_set_fault_xdefault (pool 0x447ac = 0x5fd3c, ROM-verified) with slot 1: code 4 (or 2 if drive-cycle detected via 0x65690) when DAT_ffffcb6d, else code 1 with rotor bits bVar4 = DAT_ffffcb6c&3 when cb6e. Pools verified: 0x447ac=0x5fd3c, 0x4479c=0xcb6c, 0x4479a=0xbaa0, 0x4479e=0xbaa1, 0x447a0=0xcb6d, 0x447b0=0x65690, 0x4478e=0xcb6e. DTC slot table 0x7e560 slots 0/1 = 0x0300 (P0300, both rotors), prefixes 0x7e55a = 0x0300/0x0301/0x0302 (P0300/P0301/P0302) selected per rotor bits by ref_lookupCodeTypeMisfire 0x5f98a (pool 0x5f9e4=0x7e55a). Called from 0x445ba."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffa390", "sector_period_ring", "float[8]", "0000cf96",
     "8-entry ring of crank sector periods: crank_edge_period_update 0xcf96 shifts DAT_ffffa3ac..0xffffa398 down and writes DAT_ffffa390 = (DAT_ffffa3d7 * 6666666.0) / period_ticks, period = ICR0AH 0xfffff434 (pool 0xd00a=0xf434) difference stored at 0xffffa3cc; 6666666.0 float at ROM 0xd124 (pool 0xd124). Copied to 0xffffb664-0xffffb680 by 0x26940."),
    ("ffffa3b0", "crank_sector_slot", "uint8", "0000cf96",
     "Sector slot index iVar5 (0..5) of the matched edge, written by 0xcf96 (pool 0xd11c=0xffffa390 ring base); latched to sector_parity_bank 0xffffb660 by 0x26982."),
    ("ffffb664", "misfire_sector_ring_copy", "float[8]", "00026940",
     "Copy of the crank sector-period ring 0xffffa390..0xffffa3ac made by misfire_sector_ring_copy 0x26940; read by the deviation math 0x28198/0x2842c/0x28118 (cells 0xffffb664..0xffffb680)."),
    ("ffffb660", "sector_parity_bank", "uint16", "00026982",
     "DAT_ffffb660 = DAT_ffffa3b0 = crank sector slot 0..5; &1 selects the rotor bank in the learned table (0x271b0/0x276ec/0x28198) and the event/counter indexing (0x27fb4/0x28022/0x26a42/0x447e2/0x4489c): bank 0 reads value_pos 0xffff8108, bank 1 reads value_neg 0xffff8328."),
    ("ffffb688", "misfire_counter_bank1_a", "uint16", "00026a42",
     "Per-rotor misfire event counters bumped by 0x26a42/0x26b34 when the event flags are set (saturate 0xff); bank1 pair 0xffffb688/0xffffb68c, bank0 pair 0xffffb68a/0xffffb68e; DAT_ffffb694 = any event this tick; snapshotted into b690/b692 by 0x26aa0 and consumed by the DTC evaluations 0x44b46/0x445ba."),
    ("ffffb68a", "misfire_counter_bank0_a", "uint16", "00026a42",
     "Bank0 counterpart of 0xffffb688 (parity 0 pair 0xffffb68a/0xffffb68e); rotor-bit source for P0301/P0302 in 0x44b46 (cba0) and reset there."),
    ("ffffb68c", "misfire_counter_bank1_b", "uint16", "00026a42",
     "Bank1 second counter; rotor-bit source in 0x445ba (cb6f) and reset there."),
    ("ffffb68e", "misfire_counter_bank0_b", "uint16", "00026a42",
     "Bank0 second counter; rotor-bit source in 0x445ba (cb70) and reset there."),
    ("ffffb694", "misfire_any_event_tick", "uint8", "00026b34",
     "Set by 0x26b34 when any per-rotor event flag fired this tick; gates the sustained window 0x44436 (DAT_ffffcb68)."),
    ("ffffb69c", "misfire_supply_enable", "uint8", "00026fc0",
     "0 when battery 0xffffb590 < 11.0 (pool 0x75474) or fault persistence b6a4/b6a6 set, else 1 (0x26fc0). Gates the 400/2000-tick counters 0x28b10/0x28b50, both event arms 0x27fb4/0x28022 and the count-floor lookup 0x4499c."),
    ("ffffb6c6", "misfire_cell_learned", "uint8", "000271b0",
     "Set by e2ram_learned_table_learn_gate 0x271b0 only when the current cell flag (0xffff8548+cell*2+bank*0x88, pool 0x27270) is set and a learned neighbour cell covers the current RPM; gates the residual filter 0x2837c and the event arm 0x27fb4."),
    ("ffffba04", "misfire_learn_hold", "uint8", "00027306",
     "Learn-hold counter: decremented by 0x27306 once per odd sector (b660==1); gates the learn 0x276ec (ba04!=0 && ba06==0) and the sustained gate 0x273d4."),
    ("ffffba24", "misfire_event_flag_a", "uint8[2]", "00027fb4",
     "Per-rotor (sector parity) misfire event flags: set by 0x27fb4 when (b53a==1 || load >= ba28) && b69c==1 && b6c6==1 && ba40 > ba78; checked/cleared by 0x447e2; counted by 0x26a42 into 0xffffb688-0xffffb68e; DTC-evaluated by 0x44b46/0x445ba -> P0300/P0301/P0302."),
    ("ffffba26", "misfire_event_flag_b", "uint8[2]", "00028022",
     "Secondary per-rotor event flags on the DAT_ffffba50/0xffffba80 path (0x28022); checked/cleared by 0x4489c (load-limit thresholds)."),
    ("ffffba28", "misfire_load_floor", "float", "00027fb4",
     "DAT_ffffba28 = lookup_2d_scaled(rpm, tbl 0x6a6b8 [17 cells, 700..8500 rpm]); load floor for the primary event arm 0x27fb4 (bypassed in neutral b53a==1). Pool 0x28074=0xffffba28."),
    ("ffffba30", "misfire_residual", "float", "00028198",
     "DAT_ffffba30 = DAT_ffffba2c - learned value (DAT_ffffba64+4*parity): excess sector-speed deviation above the learned baseline, per rotor bank (0x28198)."),
    ("ffffba34", "misfire_residual_filtered_bank0", "float", "0002837c",
     "Filtered DAT_ffffba30 for rotor bank 0 (0x2837c, rx8_first_order_filter k=0.125) when b6c6==1 (cell learned), else 0."),
    ("ffffba38", "misfire_residual_filtered_bank1", "float", "0002837c",
     "Filtered DAT_ffffba30 for rotor bank 1 (0x2837c)."),
    ("ffffba40", "misfire_excess_deviation", "float", "0002837c",
     "DAT_ffffba40 = max(0, DAT_ffffba3c): the excess deviation above the learned baseline; thresholded by 0x447e2 (RPM thresholds) and armed via 0x27fb4 against ba78."),
    ("ffffba44", "misfire_excess_deviation_delayed", "float", "00028198",
     "DAT_ffffba48 = DAT_ffffba44; DAT_ffffba44 = DAT_ffffba40 (0x28198): one-tick delay of the excess deviation used by the 0x447e2 threshold check."),
    ("ffffba50", "misfire_deviation_now", "float", "0002842c",
     "DAT_ffffba50 = max(0, DAT_ffffba4c): current sector-speed deviation (0x2842c); secondary arm threshold vs ba80 (0x28022) and sustained window bound (0x44436)."),
    ("ffffba54", "misfire_deviation_d1", "float", "0002842c",
     "One-tick-delayed copy of DAT_ffffba50 (0x2842c: ba54 = ba50, ba58 = ba54); load-threshold check operand in 0x4489c."),
    ("ffffba58", "misfire_deviation_d2", "float", "0002842c",
     "Two-tick-delayed copy of DAT_ffffba50 (0x2842c); load-threshold check operand in 0x4489c (cb94*ba54 < ba58)."),
    ("ffffba60", "misfire_high_rpm_active", "uint8", "000280be",
     "Set by 0x280be when rpm >= 5000.0 (ba70); selects the coolant-corrected x 3D-threshold form in 0x2853c/0x28648."),
    ("ffffba78", "misfire_threshold_a", "float", "0002853c",
     "Primary per-tick misfire threshold (one-tick delayed ba74): 3D tbl 0x6a630 (load x rpm) times a coolant correction (tbl 0x6a5e0/0x6a5f4) when ba60, else +40.0/ba94 form; computed by 0x2853c. Arm comparison ba40 > ba78 in 0x27fb4."),
    ("ffffba80", "misfire_threshold_b", "float", "00028648",
     "Secondary threshold (delayed ba7c): 3D tbl 0x6a644 x coolant tbl 0x6a608/0x6a61c when ba60, computed by 0x28648; compared against ba50 in 0x28022."),
    ("ffffba9c", "misfire_window_400", "uint16", "00028b10",
     "400-tick window counter (wraps at 400 = 0x190) counted while b69c==1, zeroed on d1c5; the 400-tick evaluation fires at ==400 (0x26aa0/0x44b16/0x44b46)."),
    ("ffffba9e", "misfire_window_2000", "uint16", "00028b50",
     "2000-tick window counter (wraps at 2000 = 0x7d0) counted while b69c==1; the 2000-tick evaluation fires at ==2000 (0x26aa0/0x4458a/0x445ba)."),
    ("ffffb690", "misfire_event_count_400", "uint16", "00026aa0",
     "Snapshot at ba9c==400: max(cb78, cb7c) (0x26aa0); compared in the 400-tick DTC evaluation 0x44b46."),
    ("ffffb692", "misfire_event_count_2000", "uint16", "00026aa0",
     "Snapshot at ba9e==2000: max(cb7a, cb7e) (0x26aa0); compared in the 2000-tick DTC evaluation 0x445ba against cb72 and the rpm-lookup product."),
    ("ffffcb60", "misfire_sustained_counter_a", "uint16", "00044436",
     "Sustained-event counter bumped by 0x44436 (saturate 1000) while the misfire window conditions hold; consumed by 0x273d4, 0x44b46, 0x445ba."),
    ("ffffcb62", "misfire_sustained_counter_b", "uint16", "00044436",
     "Second sustained counter (0x44436); compared in the 2000-tick evaluation 0x445ba (uVar2 < cb62)."),
    ("ffffcb68", "misfire_sustained_decay", "uint8", "00044436",
     "Set to 0x28 by 0x44436 when any event fired this tick (b694), decays otherwise; part of the sustained-window gate."),
    ("ffffcb6c", "misfire_dtc_rotor_bits", "uint8", "000445ba",
     "Rotor bits assembled in 0x445ba from cb70<<1 | cb6f (bank0/bank1) for the 2000-tick DTC set 0x44724 (code 1 -> P0301/P0302 selection via prefix table 0x7e55a)."),
    ("ffffcb6d", "misfire_dtc_pending", "uint8", "000445ba",
     "Set by 0x445ba when the 2000-tick count (b692) or the rpm-scaled product falls below the window thresholds (cb72/cb62); 0x44724 then sets slot 1 with code 4 (or 2 on drive cycle)."),
    ("ffffcb6e", "misfire_dtc_confirmed", "uint8", "000445ba",
     "Set by 0x445ba when the 2000-tick evaluation passes; 0x44724 then sets slot 1 with code 1 and the rotor bits cb6c."),
    ("ffffcb72", "misfire_threshold_2000", "uint16", "0004458a",
     "2000-tick window threshold: 0xff when DAT_ffffcf90 < 0.0 else 100, written by 0x4458a at ba9e==2000; compared against b692 in 0x445ba."),
    ("ffffcb78", "misfire_rpm_counter_a", "uint16", "000447e2",
     "Primary rpm-threshold counter bumped by 0x447e2 while the event flag survives the cb8c/cb90 threshold products; delayed to cb80 by 0x4493a, snapshotted to b690 by 0x26aa0."),
    ("ffffcb7a", "misfire_rpm_counter_b", "uint16", "000447e2",
     "Second rpm-threshold counter (0x447e2); snapshotted to b692 by 0x26aa0 at ba9e==2000."),
    ("ffffcb7c", "misfire_load_counter_a", "uint16", "0004489c",
     "Load-threshold counter bumped by 0x4489c; delayed to cb82 by 0x4493a, snapshotted to b690 by 0x26aa0."),
    ("ffffcb7e", "misfire_load_counter_b", "uint16", "0004489c",
     "Second load-threshold counter (0x4489c); snapshotted to b692 by 0x26aa0 at ba9e==2000."),
    ("ffffcb8c", "misfire_threshold_rpm_a", "float", "00044a78",
     "RPM-dependent misfire threshold from tbl 0x6b9f4 (12 cells, axis 0x7c43c = 780..8500 rpm); used by 0x447e2 as cb8c*ba44 < ba48. Second threshold DAT_ffffcb90 from tbl 0x6ba00."),
    ("ffffcb90", "misfire_threshold_rpm_b", "float", "00044a78",
     "Second RPM threshold from tbl 0x6ba00 (12 cells, axis 0x7c49c); used by 0x447e2 as cb90*ba44 < ba40."),
    ("ffffcb94", "misfire_threshold_load_a", "float", "00044a9e",
     "Load-limit A lookup (tbl 0x6ba0c) -> DAT_ffffcb94; used by 0x4489c as cb94*ba54 < ba58."),
    ("ffffcb98", "misfire_threshold_load_b", "float", "00044a9e",
     "Load-limit B lookup (tbl 0x6ba18) -> DAT_ffffcb98; used by 0x4489c as cb98*ba54 < ba50."),
]


def read_rows(path, fields):
    """Return list of dicts; rows keep their raw line in '_raw' for byte-exact rewrite."""
    if not path.exists():
        return []
    with path.open(newline='', encoding='utf-8', errors='surrogateescape') as f:
        text = f.read()
    lines = text.split('\n')
    rows = []
    rdr = csv.DictReader(lines, delimiter='\t')
    for raw, row in zip(lines[1:], rdr):
        if raw == '' and all(v in (None, '') for v in row.values()):
            continue
        row = {k: (v if v is not None else '') for k, v in row.items()}
        row['_raw'] = raw
        rows.append(row)
    return rows


def write_rows(path, fields, rows):
    """Rewrite preserving original lines byte-exactly; only appended rows are new."""
    with path.open('w', newline='', encoding='utf-8', errors='surrogateescape') as f:
        f.write('\t'.join(fields) + '\n')
        for r in rows:
            raw = r.get('_raw')
            if raw is not None:
                f.write(raw + '\n')
            else:
                f.write('\t'.join(r.get(k, '') for k in fields) + '\n')


def main():
    index = {r['address'] for r in read_rows(b / 'decompiled/function_index.tsv',
                                             ['address', 'name', 'body_bytes', 'status', 'file'])}
    for a, alias, conf, ev in FUNCTIONS:
        assert a in index, 'function %s not in index' % a
    for a, alias, typ, reader, ev in RAM:
        assert list((b / 'decompiled/functions').glob(reader + '_*')), 'reader %s has no function file' % reader

    added_fn = added_ram = 0
    conflicts = []

    p = b / 'source_review/accepted_function_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'confidence', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, conf, ev in FUNCTIONS:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('function %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev, '_raw': None})
        added_fn += 1
    if not conflicts and added_fn:
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    p = b / 'source_review/accepted_ram_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, typ, reader, ev in RAM:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('ram %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'type': typ, 'reader': reader, 'evidence': ev, '_raw': None})
        added_ram += 1
    if not conflicts and added_ram:
        write_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'], rows)

    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')

    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text()) if vp.exists() else {
        'date': '', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    if BASIS not in val.get('sources', []):
        val.setdefault('sources', []).append(BASIS)
    vp.write_text(json.dumps(val, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    record = {
        'date': '',
        'pass': BASIS,
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: docs/subsystem-logic/misfire_detection_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/misfire_detection_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
