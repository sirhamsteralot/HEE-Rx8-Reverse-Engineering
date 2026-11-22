#!/usr/bin/env python3
"""Append reviewed throttle/DBW (drive-by-wire) aliases to the curated TSVs (idempotent).

Runs after review_dsc_can_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the pedal (APP, AN4/AN5) -> demand -> throttle-plate
request/torque chain, the plate TP (AN18/AN19) feedback + plausibility/learning,
the limp/home override, the ATU-II ch7D (TO7D/PB7) PWM duty path, the DBW relay
PE0 (already recorded from the starting/cranking pass), and the Mode 22 PID
0x1410 settlement. Also corrects three mislabeled RAM rows (see REPLACES).
Writes metadata/throttle_dbw_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_throttle_dbw'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("0001150e", "dbw_task9_batch", "high",
     "Task-table rec[9] @ROM 0x4a20 entry 0x64ba tail-calls 0x1150e (pool 0x656c=0x0001150e at 0x64d4); batch pool 0x116b8=0x000199d4 (pedal/TP sensor batch), 0x116c8=0x00022f86 (DBW control batch), 0x116e4=0x00021b4c (throttle torque batch) — words read from ROM, jsr sites in disasm."),
    ("000199d4", "pedal_tp_sensor_batch", "high",
     "Sensor/percent batch called from 0x1150e (pool 0x116b8=0x000199d4): runs 0x18f60/0x18fa4/0x18fe8/0x1933a/0x193c4 (pedal AN4/AN5 -> volts -> percent -> demand), 0x1b08e/0x1b14c/0x1b940 (plate AN18/AN19 -> TP volts -> plate position), learning/plausibility 0x1b166/0x1b3f2/0x1b6fc/0x1ba20/0x1bcae (callgraph.tsv rows for caller 000199d4)."),
    ("000094f0", "pedal_adc_raw_to_volts", "high",
     "AN4/AN5 raw (0xffff9eec/0xffff9eee from the 0x6884 sweep) range-checked against pool words 0x6eeb0=0xf5c3 (upper) / 0x6eeb4=0x11ec (lower), faults 0xffffa110/a111; a108 = 0.0f (0x6eec0) + raw * 6.341f (0x6eeb8=0x40cae979) * 7.6294e-05f; a10c = 3.488f (0x6eec4=0x405f3b64) + raw * 6.341 * 7.6294e-05. Called from 0x60c8 ref_getSensorStuff__ (pool 0x6250)."),
    ("00018f60", "pedal_volts_clamp_latch", "high",
     "a9c4 = DAT_ffff9eec (pool 0x19058=0xffff9eec, 0x1904a=0x0000a9c4), a9c8 = 0xffffa112, a99c = rx8_min_float(25.0f @0x6eed0 via pool 0x19068, a108 @0xffffa108 pool 0x19064) via 0x23f4 (pool 0x1906c); called from 0x199d4."),
    ("0001933a", "pedal_learned_zero_subtract", "high",
     "a9ac = rx8_max_float(0.0, a99c - readValue_float(0xffff8068)) and a9b0 likewise with 0xffff8070 (pools 0x19386=0x8068, 0x19388=0x8070/0x8078, 0x1938c=0xa99c/0xa9a4, helpers 0x193bc=0x3dc22 ref_readValue_float, 0x19394=0x23e4 rx8_max_float, outputs 0x19390=0xa9ac/0xa9b0). Learned default 0x412db22d=10.856 written by 0x18fe8."),
    ("0001b08e", "plate_tp1_volts_latch", "high",
     "ad5c = DAT_ffff9f08 (AN18 raw; pools 0x1b12c=0xffff9f08, 0x1b0e6=0xad5c), ad30/ad54 from 0xffffa218/0xffffa222 (pools 0x1b138=0xffffa218, 0x1b130=0xffffa222, 0x1b0f0=0xad30/0xad54); filter 0x23b0 via pool 0x1b148. Called from 0x199d4."),
    ("0001b14c", "plate_tp2_volts_latch", "high",
     "ad5e = DAT_ffff9f0a (AN19 raw; pools 0x1b1d0=0xffff9f0a, 0x1b1c0=0xad5e/0xad34), ad34 from 0xffffa21c/0xffffa224 (pools 0x1b1dc=0xffffa21c, 0x1b1d4=0xffffa224). Called from 0x199d4."),
    ("000228dc", "throttle_pedal_to_plate_request_map", "high",
     "3D lookup lookup_3d_descriptor_scaled(rpm 0xffffb548, demand 0xffffa9bc, tbl) with gear flags b2cc/b2cd/b2ce selecting descriptors 0x6a458 (1/2), 0x6a474 (neutral), 0x6a490 (5/6), 0x6a4ac (3/4) (pools 0x229ca=0xa9bc, 0x229cc=0xb548/0xb2cc, 0x229d0=0xb2cd/0xb2ce, 0x229dc=0x6a458, 0x229e0=0x6a474, 0x229e4=0x6a490, 0x229e8=0x6a4ac); result clamped [0, 84.0f @0x7372c via pool 0x229f0] by 0x2404 (pool 0x229f4) into 0xffffb398 (pool 0x229ec) with 12-deep history shift (b3ec..b3c4, pool 0x229f8=0xffffb3ec). Called from batch 0x22f86."),
    ("00022a14", "pedal_demand_filter_coeffs", "high",
     "b3d4 = first_order_filter(a9bc, b3d4, 0.1, 1e-5); rate-decay flag b3ed at +/-2.0; filter coefficients from 2D tables 0x6a354/0x6a368/0x6a37c/0x6a390 (rpm) selected by gear flags/auto trans 0xffffb534, coolant tables 0x6a3a4/0x6a3b8, base thresholds 0x6a3cc/0x6a3e0/0x6a3f4-0x6a430; base position b38c compared against b3dc with 2.0 hysteresis -> b3ee. Called from batch 0x22f86."),
    ("00022d26", "throttle_base_position_filter", "high",
     "b390 = first_order_filter(b38c, b390, 0.25, 1e-5); b394 = (b38c <= 2.0). Called from batch 0x22f86."),
    ("00022db4", "throttle_servo_override", "high",
     "Servo/homing override in batch 0x22f86. dir b400 = (b4b0 >= readValue_float(0xffff807c, default 15.0f @0x6f438)+0.5f @0x747b8) with hysteresis; mode byte ccbc; duty b3f8: mode!=1 -> 0.0; mode==1 && b401==0 -> min(b410+learned, learned+0.5); else decay max(5.0f @0x747bc, b3f8-0.05f @0x747c0) when counters b3fc/b3fe > 1. Pools 0x22e9e-0x22f18 verified: 0x22ea0=0xb4b0, 0x22ea2=0xccbc, 0x22ea4=0xb3f8, 0x22ea6=0xb410, 0x22ebc=0xffffb400, 0x22ec0=0xffffb3fc, 0x22ec4=0xffffb3fe, 0x22ec8/0x22f18=0xffffb401."),
    ("000233ec", "throttle_target_plate_position", "high",
     "Arbitrated plate target: b424 = clamp(b2b8, b418=tbl 0x6a4c8(coolant), b38c+b2a4) when b2cf==1 (DSC torque limit), = max(b38c+b2a4, b2bc) when b2d0==1 (DSC mode C max opening), else clamp(b38c+b2a4, 0, 84.0) with fuel-cut decel reduction via tbls 0x6a4dc/0x6a4f0/0x6a504 (descriptors 0x6a4c8/0x6a4dc/0x6a4f0/0x6a504) -> b434/b422; b410 = FUN_0005ccb4(b424) (raw counts, PIDs 0x004c/0x091a). Called from batch 0x22f86."),
    ("000231f0", "learned_pedal_value_calc", "high",
     "b40c = clamp(arg0, 0, readValue_float(0xffff808c, default 110.0f=0x42de0000)); arg0 = b404+learned807c (ccbb), b3f8 (ccbc), cc88+learned (ccbd), else b410+learned807c; fault path b423==1 -> b40c = 99.0. rpm gates b435 (>=500/300 rpm), b420 countdown (tbl PTR 0x6a518), b436 = engine_stopped_latch a41c. Called from batch 0x22f86."),
    ("00023558", "throttle_position_delta_calc", "high",
     "b414 = b410 - b428 (0.0 when ccc9 set); b428 = b410. Called from batch 0x22f86."),
    ("00022f86", "dbw_control_batch", "high",
     "DBW control batch from 0x1150e (pool 0x116c8=0x00022f86), mask 0x10 around two call groups: 0x474fc (home offset cc88), 0x22f1c, 0x48558, then 0x22db4, 0x233ec, 0x231f0, 0x23558, 0x228dc, 0x22a14, 0x22d26, relay_hold_output_pd11 0x251d0 (callgraph.tsv rows for caller 00022f86)."),
    ("00021b4c", "throttle_torque_request_batch", "high",
     "Throttle torque batch from task rec[18] 0x64e8 -> 0x11534 -> 0x1150e (pool 0x116e4=0x00021b4c); mask 0x10; calls 0x21970 (gear mode flags), 0x218c4 ref_throttlePlateControl_Related (DSC torque-request limit), 0x21ae8 ref_getThrottleBasedTorque_Related (callgraph.tsv rows for caller 00021b4c)."),
    ("00021970", "throttle_gear_mode_flags", "high",
     "Sets b2cc/b2cd/b2ce from AT gear bytes 0xffffbc41/bc42/bc43 (and automatic_transmission_ffffb534); calls ref_throttlePlatePosToTorqueOutput_ 0x21a80; computes b2d4 = idle_air b2a4 + b38c, b2c0 = tbl 0x6a180 (Throttle Position To Torque), b2c4/b2e0 = tbl 0x6a164 (Trans Requested Torque To Throttle Plate Position). Called from 0x21b4c."),
    ("00033e98", "plate_range_high_fault", "high",
     "c108 = 1 when ad48 (plate % of 84) >= 200.0f (ROM 0x79be0=0x43480000), clear hysteresis 196.48 = 200.0 - 3.52f (ROM 0x79be4=0x406147ae); pools 0x33f6a=0xad48, 0x33f6c=0xc108. Called from fueling_main_task 0x20e40; consumers 0x33dc8/0x34230 kill accel enrichment."),
    ("0004595a", "tp_correlation_fault_check", "high",
     "TP1/TP2 correlation: |a9ac - a9b0| < thr -> good counter cbf2, else bad counter cbee; thr = 3.5f (ROM 0x7c77c=0x40600000, via pool 0x45a00) when learned-valid 0xffff8078==1, else 9.536f (ROM 0x7c790=0x41189375, pool 0x45acc); cbf2 > 0x18 -> cbec=1; cbee > 0x1c -> 0xffff872c=1 and DTC 0x6c via 0x5fd38. Pools 0x459f8=0xffffcbf2, 0x459f0=0xffffcbf0, 0x45ad0=0xffffcbee, 0x45ac4=0x872c/0xcbec, 0x459dc=0xa9ac/0x8078. Called from 0x38e12."),
    ("00025198", "ch7d_pwm_duty_ratio", "high",
     "b570 = clamp(b354, 0, 100.0f) / 100.0f (pools 0x251c0=0xb354, 0x251c2=0xb570, 0x251c4=0x42c80000, helper 0x251c8=0x2404), then tail jmp 0xb2c0 (pool 0x251cc) with r4=0. Called from 0x2253c."),
    ("0000b2c0", "ch7d_pwm_duty_write", "high",
     "0xb2c0(ch, fr4): a210[ch] = (u32)(fr4 * 65536.0f) (pools 0xb37c=0xffffa210, 0xb390=0x47800000); if a214[ch]==1 and ch==0: BFR7D 0xfffff596 = rx8_mul_s32_shift16_saturate(a210[0], 0xffff9f50) via 0x231c (pools 0xb380=0xffffa214, 0xb374=0xf596, 0xb38c=0xffff9f50, 0xb394=0x231c). Sole caller 0x25198 (only ROM pointer word to 0xb2c0 is 0x251cc)."),
    ("0002253c", "ch7d_pwm_duty_batch", "high",
     "Batch called from 0x118d0 (task[13] 0x65b2 -> pool 0x66d8=0x000118d0 -> pool 0x11a88=0x0002253c): mask 0x10, calls 0x22574, 0x22630, 0x25198 (pools 0x22560=0x3920, 0x22564=0x22574, 0x22568=0x22630, 0x2256c=0x25198)."),
    ("00022574", "ch7d_pwm_enable_condition", "high",
     "b358 = engine_running 0xffffa428==1 && engine_running_timer 0xffffa424 >= tbl 0x6a340(coolant-model delta b35c, b386) && coolant valid (>= -50.0f @0x7353c) && 9.0f <= battery 0xffffb590 < 16.0f (@0x73540/0x73544) && 0xffffcd70==0; else b358=0. Called from 0x2253c."),
    ("00022630", "ch7d_pwm_duty_control_loop", "high",
     "Closed-loop duty b354 (0-100%): PID-ish on 0xffffaa78 (filtered AN11/AN23 pair ratio) — P (aa78-30.0f @0x7355c)*4.5f (@0x73550), I b364 += (aa78-30)*0.1875f (@0x73554), D (b36c-aa78)*0.75f (@0x73558), hysteresis 39/44/40/45 -> b389/b38a (@0x7354c/0x73548); feedforward/limit tbls 0x6a2cc/0x6a2f4 (aa78), 0x6a324 (rpm, maf aa38), 0x6a2e0 (battery) -> b360 = b378*min(b370,b374); timer b368 -> tbl 0x6a308; b354=0 when b358==0. Called from 0x2253c."),
    ("0000b23c", "ch7d_pwm_off_init", "high",
     "Init (from mainInit 0x61a8 chain): a214=0, a210=0, TSTR2 0xfffff400 bit7 clear, CYLR7D/TCNT7D/BFR7D/DTR7D=1 then BFR7D=0, TSTR2 bit7 set (pools 0xb36c=0xe0/0xf400, 0xb36e=0xf400, 0xb370=0xf58e/0xf586, 0xb374=0xf596/0xf59e, 0xb37c=0xffffa210, 0xb380=0xffffa214, 0xb378=0x7d00)."),
]

# RAM corrections: address -> (old_alias, new_alias, type, reader, evidence)
RAM_REPLACES = [
    ("ffffa9b4", "throttle_position_1_percent", "accelerator_pedal_1_percent", "float", "000193c4",
     "CORRECTION (was 'throttle_position_1_percent'): a9b4 = clamp(a9ac/12.7f*100, 0, 100) where a9ac comes from AN4 (0xffff9eec) via 0x94f0/0x18f60/0x1933a — the PEDAL (APP1) percent; it feeds demand a9bc (0x193c4) and the pedal-to-plate maps 0x228dc, and the cruise pedal-override 0x4c896 compares it against cruise output bcf8. The throttle PLATE position is ad44 (AN18/AN19 chain). Pool 0x194d4=0x6ef18 (12.7f), 0x194d0=0x42c80000 (100.0f), 0x194e0=0x2404 (clamp)."),
    ("ffffa9b8", "throttle_position_2_percent", "accelerator_pedal_2_percent", "float", "000193c4",
     "CORRECTION (was 'throttle_position_2_percent'): a9b8 = same chain from AN5 (0xffff9eee) — the PEDAL (APP2) percent; see a9b4. Pool 0x194bc=0xa9b4/0xa9b0, 0x194be=0xa9b0."),
    ("ffffad5e", "inferred_pedal_volts_ffffad5e", "inferred_throttle_sensor_2_volts_ffffad5e", "uint16", "00056d4c",
     "CORRECTION (was 'inferred_pedal_volts_ffffad5e'): ad5e = DAT_ffff9f0a = AN19 raw, latched by 0x1b14c (pool 0x1b1d0=0xffff9f0a, 0x1b1c0=0xad5e) — the throttle PLATE TP2 volts (pair with ad5c/AN18, PID 0x0011). The pedal volts are a9c4/a9c6 (AN4/AN5). PID 0x0047/0x0918 handlers read ad5e."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffff9eec", "adc_an4_pedal_raw", "uint16", "000094f0",
     "ADDR4H (0xfffff808) latched here by the 0x6884 ADC sweep (pool 0x6a1c=0xffff9ee4 base, +2n); read by 0x18f60 (pool 0x19058=0xffff9eec) into a9c4 (pool 0x1904a). Pedal APP1 raw. Harness: accelerator pedal sensor terminals 4X/5AE/5C/4Y/5AB/5F (B1-14 A-F); pin->terminal is board routing."),
    ("ffff9eee", "adc_an5_pedal_raw", "uint16", "000094f0",
     "ADDR5H latched at 0xffff9eee by the 0x6884 sweep; pedal APP2 raw; feeds a9c6 via 0x18fa4."),
    ("ffff9f08", "adc_an18_plate_tp1_raw", "uint16", "0001b08e",
     "ADDR18H latched here by the 0x6884 sweep; read by 0x1b08e (pool 0x1b12c=0xffff9f08) into ad5c (pool 0x1b0e6) — throttle PLATE TP1 volts (PID 0x0011 via 0x5553e, PID 0x1154 raw). Harness: throttle body TP signal 1J (B1-19 A)."),
    ("ffff9f0a", "adc_an19_plate_tp2_raw", "uint16", "0001b14c",
     "ADDR19H latched here by the 0x6884 sweep; read by 0x1b14c (pool 0x1b1d0=0xffff9f0a) into ad5e (pool 0x1b1c0) — throttle PLATE TP2 volts. Harness: TP signal 1M (B1-19 D)."),
    ("ffffa108", "pedal_1_scaled_volts", "float", "000094f0",
     "a108 = 0.0f + AN4 raw * 6.341f (0x6eeb8) * 7.6294e-05f (0x94f0); range-checked [0x11ec, 0xf5c3) with faults a110/a111 -> DTC 0x66/0x67 (TP... pedal channel 1)."),
    ("ffffa99c", "pedal_1_volts_clamped25", "float", "00018f60",
     "a99c = rx8_min_float(25.0f, a108) in 0x18f60 (pools 0x19064=0xffffa108, 0x19068=0x6eed0, 0x1906c=0x23f4, store 0x19042=0xa99c)."),
    ("ffffa9ac", "pedal_1_volts_zeroed", "float", "0001933a",
     "a9ac = max(0, a99c - learned zero 0xffff8068) in 0x1933a (pools 0x19386=0x8068, 0x1938c=0xa99c, 0x19394=0x23e4, store 0x19390=0xa9ac)."),
    ("ffffad44", "inferred_throttle_position", "float", "0001b940",
     "Plate position 0-84 (deg-ish): ad44 = ad38/ad3c (from AN18/AN19 via 0x1b08e/0x1b14c -> a218/a21c -> ad30/ad34, learned zeros 0xffff807c/0xffff8084) in 0x1b940; limp value 20.0 when cc99==1; ad48 = ad44/84.0f (0x42a80000)*100. Read by PID 0x093c handler 0x56e04, tbl 0x6a180 lookups 0x21a80/0x21ae8, fault 0x33e98."),
    ("ffffb398", "throttle_plate_request", "float", "000228dc",
     "Pedal-to-plate request: lookup_3d(rpm, a9bc, gear tbl 0x6a458/0x6a474/0x6a490/0x6a4ac) clamp [0, 84.0f @0x7372c] -> b398 (pools 0x229ec=0xffffb398, 0x229f0=0x7372c, 0x229f4=0x2404), 12-deep history b3c4..b398. Written by 0x228dc."),
    ("ffffb424", "throttle_target_plate_percent", "float", "000233ec",
     "Arbitrated plate target percent from 0x233ec (DSC limit b2cf/b2b8, DSC mode C b2d0/b2bc, idle air + base b2a4+b38c, fuel-cut decel, clamp 84.0); converted to raw counts b410 = 0x5ccb4(b424)."),
    ("ffffb3f8", "throttle_servo_override_duty", "float", "00022db4",
     "Servo/homing override duty float written by 0x22db4 (pool 0x22ea4=0xb3f8); 0.0 when mode ccbc!=1; decay max(5.0, b3f8-0.05) with counters b3fc/b3fe; read by 0x231f0/0x233ec (mode ccbb/ccbc branches)."),
    ("ffffb400", "throttle_servo_direction", "uint8", "00022db4",
     "Direction byte written by 0x22db4 (pool 0x22ebc=0xffffb400): 1 when target b4b0 >= learned 0xffff807c + 0.5f. No other reader found in ROM (whole-ROM pool scan)."),
    ("ffffccbc", "throttle_servo_mode", "uint8", "000487d6",
     "Servo mode byte written by engine_stop_conditions_eval 0x487d6 (fault mode =1 with ccc0, engine-stopping =1, else 0); read by 0x22db4, 0x231f0, 0x1b166 and others."),
    ("ffffb2cc", "throttle_gear_mode_1_2", "uint8", "00021970",
     "Gear-mode flags b2cc/b2cd/b2ce set by 0x21970 from AT bytes bc41/bc42/bc43 + automatic_transmission b534; select the pedal-to-plate map (0x228dc) and the 0x21970 branch."),
    ("ffffb2cf", "dsc_torque_limit_active", "uint8", "000218c4",
     "Set by ref_throttlePlateControl_Related 0x218c4 when DSC mode bit bbcc==1 && desired torque bbd4 <= b2c0 (or a966==1); gates the b424 clamp in 0x233ec (b2b8 = tbl 0x6a164 trans requested-torque-to-plate)."),
    ("ffffb2d0", "dsc_mode_c_active", "uint8", "000218c4",
     "Set by 0x218c4 when bbcc==1 && bbca==0; b2bc = tbl 0x6a150 'DSC Mode C - Max Throttle Plate Opening Allowed'(rpm) -> max clamp of b424 in 0x233ec."),
    ("ffffb354", "ch7d_pwm_duty_percent", "float", "00022630",
     "0-100% PWM duty computed by 0x22630 (PID loop on 0xffffaa78, limit b360, enable b358 -> 0); read by 0x25198 (clamp/100 -> b570 -> 0xb2c0) and stall monitors 0x4162e/0x416bc."),
    ("ffffb358", "ch7d_pwm_enable", "uint8", "00022574",
     "Enable flag from 0x22574 (engine running, timer, coolant valid, battery 9-16V, !cd70); gates b368 counter and forces b354=0 in 0x22630 when clear."),
    ("ffffcd70", "throttle_fault_latch", "uint8", "00022574",
     "Stuck-duty latch set by 0x4a11c when monitors 0x4162e/0x416bc see b354 stuck <10% or >=90% (counters c911-c918); read by 0x22574 -> disables the PWM duty loop (b358=0 -> b354=0)."),
    ("ffffad60", "tp_plausibility_fault_a", "uint8", "0001ba20",
     "Set by 0x1ba20 when engine off/idle conditions with stable plate history (ad61==0, ccb4>7, 80a2==0) -> ad60=1; read by shutdown_allowed_flag 0x48cc0 (blocks PD11 relay hold) and 0x487d6."),
    ("ffffad61", "tp_plausibility_fault_b", "uint8", "0001bd9e",
     "Set by 0x1bd9e; NOT(engine running && no cc98/cc99/b4f7/b4fb/b4fd && !873c) in 0x1ba20; read by 0x48cc0/0x487d6."),
    ("ffff872c", "tp_correlation_fault_latch", "uint8", "0004595a",
     "Set by 0x4595a when TP1/TP2 bad-correlation counter cbee > 0x1c -> DTC 0x6c (P0122/23-family TP correlation; dtc_set_fault 0x5fd38(0x6c))."),
    ("ffffc108", "tp_range_high_fault", "uint8", "00033e98",
     "Set by 0x33e98 when plate percent ad48 >= 200.0 (hyst 196.48); consumers 0x33dc8/0x34230 zero the accel-enrichment accumulators c0c8/c104."),
    ("ffffcbec", "tp_correlation_ok", "uint8", "0004595a",
     "Set by 0x4595a when TP1/TP2 good-correlation counter cbf2 > 0x18 (pool 0x45ad0=0xffffcbee)."),
    ("ffff8068", "learned_pedal_zero_1", "float", "00018fe8",
     "Learned APP1 zero (default 0x412db22d=10.856f), adapted by 0x18fe8 under stability gates, reset when TP fault cc9b/cc9c; subtracted in 0x1933a (pool 0x19386=0x8068). E2RAM-backed via 0x244bc/0x23844."),
    ("ffff8070", "learned_pedal_zero_2", "float", "00018fe8",
     "Learned APP2 zero; subtracted in 0x1933a (pool 0x19388=0x8070)."),
    ("ffff8084", "learned_plate_zero_2", "float", "0001b3f2",
     "Learned plate TP2 zero (default 15.0f=0x41700000), adapted by 0x1b3f2 with 0xffff807c; subtracted in 0x1b940 (ad3c)."),
    ("ffff9f50", "ch7d_pwm_period", "uint16", "0000b308",
     "PWM period 32000 (0x7d00) written by atu_ch7d_pwm_enable 0xb308 (pool 0xb378=0x7d00); used by 0xb2c0 (pool 0xb38c=0xffff9f50) to scale duty q16 into BFR7D."),
]

# Pre-existing rows this subsystem relies on (kept in the JSON record; not re-appended).
RAM_CARRIED = {
    "ffffcfb7": ("pe0_relay_flag", "uint8", "0003a0ec",
                 "DBW relay flag: PE0 (PEDR_W 0xfffff754 bit 0x1, pkg pin 7) = (0xffffcfb7 == 0) driven by relay_output_pair_pd7_pe0 0x3a0ec; 0xffffcfb7 computed by 0x4ef86 from 3D tables 0x6b3c8/0x6b3dc. Pool 0x3a1b0=0xffffcfb7 anchors it. Harness candidate: DBW relay control 4C."),
    "ffffa9bc": ("inferred_ram_a9bc_ffffa9bc", "float", "000193c4",
                 "Throttle demand percent: a9bc = min(max(a9b4, cruise output 0xffffbcf8), limiter 0xffffc028), capped 13.5 (a914) / 15.0 (cc9b&&cc9c); input to the pedal-to-plate maps 0x228dc."),
    "ffffb410": ("inferred_ram_b410_ffffb410", "uint16", "000233ec",
                 "Target plate position raw counts: b410 = FUN_0005ccb4(b424) in 0x233ec; read by PIDs 0x004c/0x091a (diag_encode_b410 0x55864), servo 0x22db4/0x231f0/0x1b166."),
    "ffffa210": ("ch7d_pwm_duty_q16", "uint32", "0000b2c0",
                 "Duty percent * 65536 written by 0xb2c0 (pool 0xb37c=0xffffa210, scale 0xb390=0x47800000) from 0x25198; BFR7D = duty*32000>>16 (0xb308/0xb2c0)."),
    "ffffa214": ("ch7d_pwm_enabled", "uint8", "0000b308",
                 "Once-only enable flag for the ch7D (TO7D/PB7) PWM setup in 0xb308 (pool 0xb380=0xffffa214); cleared by 0xb23c init."),
    "ffffb570": ("inferred_ram_b570_ffffb570", "float", "00025198",
                 "b570 = clamp(b354,0,100)/100 written by 0x25198 (pools 0x251c0=0xb354, 0x251c2=0xb570); read by PID 0x1631 handler 0x5730e."),
    "ffff807c": ("inferred_ram_807c_ffff807c", "float", "00022db4",
                 "Learned plate zero 1 (default 15.0f=0x41700000 @0x6f438), E2RAM-backed; read by 0x22db4 (pool 0x22e9e=0x807c), 0x1b940, 0x231f0."),
    "ffffb40c": ("candidate_learned_pedal_value", "float", "000231f0",
                 "b40c = clamp(b410+learned807c, 0, learned 0xffff808c default 110.0f) in 0x231f0; 99.0 on fault path b423. E2RAM-persisted (0x244bc)."),
    "ffffb414": ("throttle_pedal_position_delta", "float", "00023558",
                 "b414 = b410 - b428 (0 when ccc9) in 0x23558; exported by e2ram_block_encode 0x244bc."),
    "ffffa1d4": ("adc_pair_ratio_filtered", "float", "0000aee8",
                 "Filtered AN11/AN23 pair ratio (0xaee8, coeff 0.25); copied to 0xffffaa78 by 0x1ac00; consumed by the 0x22630 duty loop."),
}

LOOKUP = [
    # original descriptor address, alias, evidence
    ("0006a458", "tbl_throttle_pedal_to_throttle_plate_request_gear_1_2",
     "RX8Defs 'Throttle Pedal to Throttle Plate Request - Gear 1/2' (3D 21x18 uint16); used by 0x228dc (pool 0x229dc=0x6a458)."),
    ("0006a474", "tbl_throttle_pedal_to_throttle_plate_request_gear_neutral",
     "RX8Defs '... - Gear Neutral'; pool 0x229e0=0x6a474 in 0x228dc."),
    ("0006a490", "tbl_throttle_pedal_to_throttle_plate_request_gear_5_6",
     "RX8Defs '... - Gear 5/6'; pool 0x229e4=0x6a490 in 0x228dc."),
    ("0006a4ac", "tbl_throttle_pedal_to_throttle_plate_request_gear_3_4",
     "RX8Defs '... - Gear 3/4'; pool 0x229e8=0x6a4ac in 0x228dc."),
    ("0006a150", "tbl_dsc_mode_c_max_throttle_plate_opening_allowed",
     "RX8Defs 'DSC Mode C - Max Throttle Plate Opening Allowed'; 2D lookup in 0x218c4 -> b2bc -> clamp in 0x233ec."),
    ("0006a164", "tbl_trans_requested_torque_to_throttle_plate_position",
     "RX8Defs 'Trans Requested Torque To Throttle Plate Position'; 3D lookup in 0x218c4/0x21a80 -> b2e4/b2b8/b2c4."),
    ("0006a180", "tbl_throttle_position_to_torque",
     "RX8Defs 'Throttle Position To Torque'; 3D lookups in 0x21a80/0x21ae8/0x21970 -> b2c0/b2e8/b2c8."),
]


def read_rows(path, fields):
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
    all_ram = [(a, al, t, r, ev) for a, al, t, r, ev in RAM] + \
              [(a, na, t, r, ev) for a, oa, na, t, r, ev in RAM_REPLACES] + \
              [(a, al, t, r, ev) for a, (al, t, r, ev) in RAM_CARRIED.items()]
    for a, alias, typ, reader, ev in all_ram:
        assert list((b / 'decompiled/functions').glob(reader + '_*')), 'reader %s has no function file' % reader

    added_fn = updated_fn = added_ram = added_lut = replaced = 0
    conflicts = []

    p = b / 'source_review/accepted_function_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'confidence', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, conf, ev in FUNCTIONS:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('function %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            elif existing[a]['confidence'] != conf or existing[a]['evidence'] != ev:
                # re-run with an updated confidence/evidence: refresh the row in place
                existing[a].update({'alias': alias, 'confidence': conf, 'evidence': ev, '_raw': None})
                updated_fn += 1
            continue
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev, '_raw': None})
        added_fn += 1
    if not conflicts and (added_fn or updated_fn):
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    p = b / 'source_review/accepted_ram_aliases.tsv'
    fields = ['address', 'alias', 'type', 'reader', 'evidence']
    rows = read_rows(p, fields)
    existing = {r['address']: r for r in rows}
    for a, old, new, typ, reader, ev in RAM_REPLACES:
        if a in existing:
            if existing[a]['alias'] == new:
                continue
            if existing[a]['alias'] != old:
                conflicts.append('ram %s: have %s, expected old %s' % (a, existing[a]['alias'], old))
            else:
                existing[a].update({'alias': new, 'type': typ, 'reader': reader, 'evidence': ev, '_raw': None})
                replaced += 1
        else:
            rows.append({'address': a, 'alias': new, 'type': typ, 'reader': reader, 'evidence': ev, '_raw': None})
            added_ram += 1
    for a, alias, typ, reader, ev in RAM:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('ram %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'type': typ, 'reader': reader, 'evidence': ev, '_raw': None})
        added_ram += 1
    if not conflicts and (added_ram or replaced):
        write_rows(p, fields, rows)

    p = b / 'source_review/accepted_lookup_aliases.tsv'
    fields = ['original', 'alias', 'basis', 'evidence']
    rows = read_rows(p, fields)
    pairs = {(r['original'], r['alias']) for r in rows}
    for orig, alias, ev in LOOKUP:
        if (orig, alias) in pairs:
            continue
        rows.append({'original': orig, 'alias': alias, 'basis': BASIS, 'evidence': ev, '_raw': None})
        added_lut += 1
    if not conflicts and added_lut:
        write_rows(p, fields, rows)

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
        'date': '2026-11-22',
        'pass': 'throttle_dbw_subsystem_analysis',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1), plus SH-2E emulator harness runs (tests/test_throttle_dbw.py). Report: docs/subsystem-logic/throttle_dbw_control_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM} | {
            a: {'alias': new, 'type': t, 'reader': r, 'evidence': ev} for a, old, new, t, r, ev in RAM_REPLACES} | {
            a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, (al, t, r, ev) in RAM_CARRIED.items()},
        'ram_carried_note': 'entries pre-existing from other passes (starting_cranking pe0_relay_flag, uds_dispatch, fueling); repeated here so this record is self-contained',
        'corrections': {a: {'old_alias': old, 'new_alias': new} for a, old, new, t, r, ev in RAM_REPLACES},
        'lookup_aliases': {o: {'alias': al, 'evidence': ev} for o, al, ev in LOOKUP},
        'pid_1410_settlement': {
            'dispatch_record': '0x5f394 (pid 0x1410, len 2, handler 0x56f6c)',
            'handler': '0x56f6c reads float 0xffffbe24 (pool 0x57018=0xbe24), encodes u16 via 0x2490 with step 8.0f (pool 0x57048=0x41000000)',
            'meaning': 'injector pulse time (0xffffbe24 written by injector_pulse_time_arbitrate 0x2fea8); step 8 us. The upstream logger alias "Throttle Pedal Position" at 0x221410 does not match this ROM; throttle plate = PID 0x0011/0x093c, pedal = PID 0x0049/0x004a.',
        },
        'rom_unchanged': True,
        'ghidra_database_updated': False,
        'pin_sources': 'Sh7055h.pdf (SH7055F HW manual ADE 602-155B): PB7/TO7D = pkg pin 154, PBCRL=0x4000 selects TO7D PWM (written at 0x51de, pool 0x52d8=0x4000/0x52da=0xf734); PE0 = pkg pin 7; PEDR_W 0xfffff754 from symbols.tsv; harness terminals from docs/architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md (throttle body 1B/1C/2F/1M/1Q/1J, pedal 4X/5AE/5C/4Y/5AB/5F, DBW relay 4C); chip-pin->terminal routing unresolved (board)',
    }
    (b / 'metadata/throttle_dbw_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'function_rows_updated': updated_fn,
        'ram_rows_added': added_ram,
        'ram_rows_replaced': replaced,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
