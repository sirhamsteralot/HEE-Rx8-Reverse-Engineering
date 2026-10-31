#!/usr/bin/env python3
"""Append reviewed fueling-chain aliases to the curated TSVs (idempotent).

Runs after review_knock_loop_labels.py and before annotate_source_review.py
in scripts/rebuild.sh, so the evidence notes and the named views pick the
rows up. Rows are keyed by address (functions, RAM) or by original token
(lookup tables); an existing row with the same key but a different alias
aborts the pass. Also writes metadata/fueling_labels.json recording the pass.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_fueling'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("00021246", "fueling_slow_task", "high",
     "Task[11] worker (0x6584 -> 0x117ac) under interrupt mask 0x10: open_loop_request_condition, set_open_loop_flag, open_loop_fueling_targets, open_loop_changeover_enrichment (0x2024c), warmup_fueling_compensation (0x32e08), 0x20298/0x2048c/0x20288, rear-O2 chain (0x1d6b4/0x1d772/0x1d850/0x1d8dc/0x1e134), maf_operating_range (0x1e842), 0x1e448, LTFT-for-CAN (0x1e900), 0x1ea56/0x1e99c/0x1eae0/0x1eba6/0x1ecee, 0x188a4, fuel_cut_rpm_condition (0x18cfe), rev_limit_conditionals (0xee82)."),
    ("000211fe", "fueling_condition_flags_task", "high",
     "Task 0x64f6 -> 0x11744 chain under mask 0x10: load/RPM band flags 0x1ff38, throttle/load band flags 0x1f6ae, 0x1fd48, blend_weight_update (0x200c6), off-throttle fuel-cut resume base 0xe560 (tbl 0x68f48), 0x3133c (tbl 0x6aca4), calculate_air_charge (0x314d0), secondary-air enrichment (0x31624), injector_temp_multiplier_lookup (0x2fd3e)."),
    ("00020e40", "fueling_main_task", "high",
     "Called from ref_engineControlTASK 0x11ba4; three masked blocks: enrichments + injection_angle_limit_lookup (0xe48e) + load_delta_enrichment (0x33ec4) + cranking_pulse_adder (0x30678); fuel core: calc_fuel_volume_request (0x306e8), calculate_fuel_amount_per_rotation (0x30948), injector_pulse_time_arbitrate (0x2fea8), cold_start_enrichment (0x1ddfc); closed-loop conditions (0x1c13c chain)."),
    ("000200c6", "blend_weight_update", "high",
     "Sets DAT_ffffb11c/b118: 1.0 in normal conditions (no c590/cca1 fault, coolant plausible b1d0, c644<=1000, mode flags clear), decays -0.0667/call while open_loop_active with b142/b154/b157/b159 set, else 0.0. Consumed by open_loop_fueling_targets (0x1ee4a: OL target blend) and leading/trailing_base_timing_calc (0x11f00/0x1206c: base-timing blend). Resolves knock-review unresolved item 2."),
    ("000306e8", "calc_fuel_volume_request", "high",
     "Core fuel-mass calc: bed0 = engine_load*0.07196; bed4 = tbl 0x6ac88 'Fuel Injection - Engine Load Compensation'(RPM); bf1c = tbl DAT_0006ac38(coolant); bf14 = (b0d0 - c0c8 - ae08 - b21c + max(c104,cde0) + min(bf1c, c00c+b120) + max(ae10,b124) + 1.0) * ad ecc * bed4; beac = FUN_0005c024(bf14); beb0 = beac*bed0."),
    ("000314d0", "calculate_air_charge", "high",
     "bf68 = rpm*load/38.07; bf44 = tbl 0x6ad44(bf68) * tbl 0x6ad30(battery V); bf4c = baro*353.0163/((IAT+273)*101.32) (density ratio); bf50 = min(bf44*0.6345*bf4c/(60*rpm), 2.0) air charge per cycle; bf54 = first-order-filtered bf50/load, clamp 50."),
    ("00030948", "calculate_fuel_amount_per_rotation", "high",
     "Per-injector fuel amounts per rotation: bec8/beec/bed8/bedc/bee0 from injector temp multipliers (bde4/bde8/bdec) * flow rates (be0c/be10/be14) * 6e7/rpm * (tbl 0x6ac4c/360) * 369.472/475.93, minus latencies be40/be44; bee4/bee8 = divide-with-zero-fallback ratios."),
    ("0002fea8", "injector_pulse_time_arbitrate", "high",
     "Cranking (!engine_running): be30 = be38 = be5c + latency be44; running: be30 = be50+be44, be38 = be54+be44; be28 = be24 = (cranking? be58 : be4c) + latency be40; be2c = be30, be34 = be38; cranking decay counter be3c from tbl 0x6bab0 'Primary Fuel Injector Cranking Pulse Decay Time'(coolant), decrementing while running."),
    ("00008a68", "injector_pulse_set_channel", "high",
     "Per-channel ATU-II output program: Per-channel fuel request array, 0x18-byte stride from a010 (= base a004+0xc); pulse = (latency a094[ch] + a010[ch*0x18]) >> 4 per disasm 0x8a8e-0x8aa0.; start compare = a014[ch*0x18] (or TCNT1A+3 if within 0x7fff) -> GR1A; clears a016/a018 and the channel TIER bit."),
    ("00008340", "injector_pulse_set_dispatch", "medium",
     "4-byte thunk to injector_pulse_set_channel (0x8a68); called from six wrappers 0x59a4/0x59b2/0x59c0/0x59ce/0x59dc/0x59ea (per-injector dispatch, one per channel)."),
    ("000086f8", "set_fuel_injector_latency", "high",
     "param_1 ch 0/1/2 -> a094/a0a0, a098/a0a4, a09c/a0a8 (latency value + mirror pair per channel); called by injector_latency_cal_lookup (0x2ff78) with ch0 = secondary, ch1/2 = primary."),
    ("000086ac", "injector_zero_offset_set", "medium",
     "param_1 ch 0/1/2 -> a0ac/a0b8, a0b0/a0bc, a0b4/a0c0 (zero/offset pair per channel); caller 0x10208 ref_setAllInjectorto0_."),
    ("000085e4", "injector_channel_disable", "high",
     "Per-channel off: clears channel TIER bit, GR1A = TCNT1A-1, DCNT8A = 0 (FUN_0000a8a4), a017 = 0. Wiring review: six injector channels on 2M/2J/2G/2D/3A/3D; firmware index-to-terminal mapping unresolved."),
    ("0002ff78", "injector_latency_cal_lookup", "high",
     "be40 = 3D tbl 0x6aa64 'Injector Latency Secondary'(MRP be04/be08, battery V b590); be44 = 3D tbl 0x6aa80 'Injector Latency Primary'; quantized /0.25 to int -> set_fuel_injector_latency(0, secondary), (1, primary), (2, primary)."),
    ("0002fd3e", "injector_temp_multiplier_lookup", "high",
     "bde4/bde8/bdec = 3D weighted-engine-temp x load multipliers for primary / secondary-1 / secondary-2 injectors (tbls 0x6a9a4/0x6a9c0/0x6a9dc); consumed by calculate_fuel_amount_per_rotation (0x30948)."),
    ("00032e08", "warmup_fueling_compensation", "high",
     "c014 = tbl 0x6ae28 'Warmup Fueling - Load Based Multiplier'(load) * 3D tbl 0x6ae3c 'Warmup Fueling'(coolant, catalyst-temp model); c018 = 3D tbl 0x6ae58 (or coolant-fault variant 0x6ae74)(rpm, coolant); c00c = c014 + c018; c010 = warmup-complete flag (catalyst-temp model >= 5 C, or >= 200 C when ce33)."),
    ("0002024c", "open_loop_changeover_enrichment", "high",
     "b124 = 0 when b146 == 0, else tbl 0x69e00 'Open Loop Changeover Enrichment'(RPM); b124 feeds calc_fuel_volume_request (0x306e8) via max(ae10, b124)."),
    ("00033ec4", "load_delta_enrichment", "high",
     "c138 = tbl 0x6b124(load delta c158); c13c = tbl 0x6b0c0(load); c134 = c138*1.0*c13c when c158 >= 0 else 0; c140 = 3D tip-in tbl 0x6b160 (or 0x6b17c when warmup c010) (rpm, coolant); injectors off (a42c) -> c140 = 0; c110 decays toward 1.0 at -0.0078125 when c14c set."),
    ("000307e0", "closed_loop_fuel_trim", "high",
     "Closed loop (ae1f): beb4 = clamp((max(bf40, c01c+b0c4) + min(tbl 0x6ac38(coolant), open_loop_fuel_target b120) + 1.0) * ad ecc - 1.0, -1, 2); filtered (0.0625) into beb8; open loop: beb4 = 0. STFT-style trim around lambda target."),
    ("00033ad2", "calculate_engine_load", "high",
     "engine_load c0b4 = min(first_order_filter(c0b0, c0b4, 0.2 or 1.0 by c0c4), c0b8); forced 0.525 when a41c or (c0c5==0 && injectors off a42c); c0c5 = previous a42c. PID 0x0043 'Engine Load' encodes c0b4 (handler 0x56b8a)."),
    ("00007438", "maf_sensor_scaling", "high",
     "9f78 = tbl 0x69788 'MAF Scaling'(raw 9eea * 5/65536); fault status 9f7c: 0 raw < 0xac0, 2 raw >= 0xfae2, else 1."),
    ("00019f4e", "maf_voltage_and_fault_counters", "medium",
     "aa2c = rx8_decode_u16_affine(0x38a00000, 0, raw 9eea) (MAF voltage); aa35/aa36 saturating fault counters (raw >= 0xf852 / < 0x7ae); when faulted: a9e4 = aa2c, a9e8 = 9f78 (MAF scaled latched)."),
    ("00019f40", "maf_filtered_update", "medium",
     "mass_air_flow a9ec = a9e8 (scaled/latched MAF); a9f4 = a9e8."),
    ("0001a418", "maf_per_rotation_calc", "medium",
     "aa54 = tbl 0x697b4(rpm) filter coefficient; aa48 = filter(maf a9ec, aa48, aa54); aa3c = min(maf*60/rpm, 5.0) (air per rotation, 60 = 2 rotors x 30?); aa38 = filtered maf*60/rpm, 0.1560058 when rpm ~ 0."),
    ("0001e842", "maf_operating_range", "high",
     "b0fe = MAF range index 0..3 from mass_air_flow a9ec bands (<1, <9, <22, else) with hysteresis flags b101/b102/b103."),
    ("0000e48e", "injection_angle_limit_lookup", "medium",
     "a434/a438/a43c = max injection angle 1/2/3 vs RPM (defs 0x68ef8/0x68f0c/0x68f20 'Fuel Injector - Unknown - Max Injection Angle', x2 deg MAYBE)."),
    ("00030678", "cranking_pulse_adder", "high",
     "When cranking && injectors off (a42c) && ce32: be94 += be58 (cranking pulse adder accumulated into pulse arbitration)."),
    ("0000e2a8", "update_injectors_off_flag", "high",
     "engine_injectors_off a42c = 1 iff !engine_running (a428) && !a41c."),
    ("0000ee64", "rev_limit_fuel_cut_init", "high",
     "When DAT_ffff9f8c == 1: clears rev-limit state a4a4/a4a5/a4a8."),
    ("0000edc4", "fuel_cut_arbitration", "medium",
     "Sets fuel-cut flags a444/a445 from requests a464/a465 and param_1 mode (band checks 0/6 vs 12/18, mirrors a4a2/a4a3); calls FUN_0000e2d4."),
    ("00018cfe", "fuel_cut_rpm_condition", "medium",
     "a97c = rpm >= 2500 (clear below 1700), a97d = rpm >= 1700 (clear below 1100); a964 fuel_cut_allowed = (a96a && a97c) || (a96c && a97d)."),
    ("0000ee82", "rev_limit_conditionals", "medium",
     "a4a6 = coolant < 18 C (set below 18, clear at 20); when b534==0 && baec active && mode changed: a4ae = 0x0f countdown (a4aa active flag, a4ad = previous baec)."),
    ("0001ddfc", "cold_start_enrichment", "medium",
     "Cranking: b0c4 = 0.0 (both coolant/IAT branches store 0.0 in this ROM); running: b0c4 = max(b0c4 - 0.0, 0.0). b0c4 feeds calc_fuel_volume_request (0x306e8) and closed_loop_fuel_trim (0x307e0)."),
    ("00056b8a", "diag_engine_load", "high",
     "RomRaider PID 0x0043 'Engine Load' handler: encodes engine_load_ffffc0b4 via rx8_encode_u16_affine_saturate (step 0x3b808080 ~ 0.00392) as u16 BE."),
    ("00056b9e", "diag_lambda_target", "high",
     "RomRaider PID 0x0044 'Lambda Target' handler: encodes lambda_target_ffffadfc (step 0x38000000) as u16 BE."),
    ("00056b22", "diag_air_fuel_ratio", "high",
     "RomRaider PID 0x0034 'Air Fuel Ratio' handler: packs FUN_000556ec (DAT_ffffaa6c) and FUN_00055702 (DAT_ffffaa7c) as two u16 BE words."),
    ("00056f6c", "diag_injector_pulse_time", "medium",
     "PID 0x1410 handler (logger def conflicts: 'Injector Pulse Time' vs 'Throttle Pedal Position' - do not trust either name): encodes DAT_ffffbe24 with step 8 (0x41000000); logger expr x*8*0.001 ms."),
    ("000556ec", "diag_afr_word_a", "medium",
     "Encodes DAT_ffffaa6c (step 0x38000000) as the high u16 word of PID 0x0034 'Air Fuel Ratio'."),
    ("00055702", "diag_afr_word_b", "medium",
     "Encodes DAT_ffffaa7c (mult 0x3b800000, offset 0xc3000000 = -96.0) as the low u16 word of PID 0x0034."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffbed0", "fuel_load_scale", "float", "000306e8", "bed0 = engine_load_ffffc0b4 * 0.07196; multiplied into final fuel volume beb0 = beac * bed0."),
    ("ffffbed4", "fuel_load_compensation", "float", "000306e8", "bed4 = lookup_3d tbl 0x6ac88 'Fuel Injection - Engine Load Compensation'(RPM); multiplier in bf14."),
    ("ffffbf1c", "fuel_coolant_compensation", "float", "000306e8", "bf1c = lookup_2d tbl DAT_0006ac38(coolant); added via min(bf1c, c00c + open_loop_fuel_target b120) in bf14."),
    ("ffffbf14", "fuel_correction_sum", "float", "000306e8", "bf14 = (b0d0 - c0c8 - ae08 - b21c + max(c104,cde0) + min(bf1c, c00c+b120) + max(ae10,b124) + 1.0) * ad ecc * bed4; scaled by FUN_0005c024 into beac."),
    ("ffffbeac", "fuel_volume_scaled", "float", "000306e8", "beac = FUN_0005c024(bf14) (diagnostic-scaler transform); beb0 = beac * bed0."),
    ("ffffbeb0", "fuel_volume_final", "float", "000306e8", "beb0 = beac * bed0: final requested fuel volume; read by open_loop_request_condition (0x1f0c4) as snapshot_DAT_ffffbeb0."),
    ("ffffbf68", "airflow_rpm_load_product", "float", "000314d0", "bf68 = rpm * load / 38.07; axis for tbl 0x6ad44 in calculate_air_charge."),
    ("ffffbf44", "airflow_corrected", "float", "000314d0", "bf44 = tbl 0x6ad44(bf68) * tbl 0x6ad30(battery V b590)."),
    ("ffffbf4c", "air_density_ratio", "float", "000314d0", "bf4c = baro*353.0163 / ((IAT+273)*101.32): pressure/temperature density ratio."),
    ("ffffbf50", "air_charge_per_cycle", "float", "000314d0", "bf50 = min(bf44*0.6345*bf4c/(60*rpm), 2.0); 2.0 when rpm ~ 0."),
    ("ffffbf54", "air_charge_filtered", "float", "000314d0", "bf54 = first_order_filter(bf50/load, bf54, 1.0, 1e-05) clamped to 50.0."),
    ("ffffbec8", "fuel_amount_per_rotation_a", "float", "00030948", "bec8 = fuel amount per rotation (bde4*be0c path) * tbl 0x6ac4c/360 * 369.472; per-injector amounts computed in calculate_fuel_amount_per_rotation."),
    ("ffffbeec", "fuel_amount_per_rotation_b", "float", "00030948", "beec = (bdec*be14 path) * 475.93; see 0x30948."),
    ("ffffbed8", "fuel_amount_per_rotation_c", "float", "00030948", "bed8 = (6e7/rpm - 608 - be40) / fVar7 * 369.472; latency-compensated variant."),
    ("ffffbedc", "fuel_amount_per_rotation_d", "float", "00030948", "bedc = (6e7/rpm - 608 - be44) / fVar4 * 475.93."),
    ("ffffbee0", "fuel_amount_per_rotation_e", "float", "00030948", "bee0 = (6e7/rpm - 608 - be44) / fVar5 * 475.93."),
    ("ffffbee4", "fuel_ratio_a", "float", "00030948", "bee4 = rx8_divide_with_zero_fallback(0x493e8ed3, fVar5); ratio derived from per-rotation amounts."),
    ("ffffbee8", "fuel_ratio_b", "float", "00030948", "bee8 = rx8_divide_with_zero_fallback(0x48fafa8d, fVar4)."),
    ("ffffbe24", "injector_pulse_time", "float", "0002fea8", "Final arbitrated pulse time be24 = be28; encoded by diag PID 0x1410 handler 0x56f6c (step 8; logger x*8*0.001 ms)."),
    ("ffffbe28", "injector_pulse_time_base", "float", "0002fea8", "be28 = (cranking? be58 : be4c) + injector_latency_primary be40; copied to be24."),
    ("ffffbe2c", "injector_pulse_time_ch1", "float", "0002fea8", "be2c = be30 (running: be50 + be44; cranking: be5c + be44)."),
    ("ffffbe30", "injector_pulse_time_ch2", "float", "0002fea8", "be30 = running? be50 + be44 : be5c + be44 (latency be44 added)."),
    ("ffffbe34", "injector_pulse_time_ch3", "float", "0002fea8", "be34 = be38."),
    ("ffffbe38", "injector_pulse_time_ch4", "float", "0002fea8", "be38 = running? be54 + be44 : be5c + be44."),
    ("ffffbe3c", "cranking_decay_counter", "uint8", "0002fea8", "Cranking: loaded from tbl 0x6bab0 'Primary Fuel Injector Cranking Pulse Decay Time'(coolant); decrements while running."),
    ("ffffbe40", "injector_latency_secondary", "float", "0002ff78", "be40 = 3D tbl 0x6aa64 'Injector Latency Secondary'(MRP, battery V), quantized /0.25; added to pulse times in 0x2fea8."),
    ("ffffbe44", "injector_latency_primary", "float", "0002ff78", "be44 = 3D tbl 0x6aa80 'Injector Latency Primary'(MRP, battery V), quantized /0.25."),
    ("ffffbe58", "injector_pulse_crank", "float", "00030678", "Cranking pulse base; added into be94 by cranking_pulse_adder (0x30678) and into be28 by 0x2fea8."),
    ("ffffbe5c", "injector_pulse_crank_base", "float", "0002fea8", "Cranking base for be30/be38 while engine not running."),
    ("ffffbe94", "cranking_pulse_adder", "float", "00030678", "be94 += be58 when cranking && injectors off && ce32 (diag cranking pulse adder)."),
    ("ffffa094", "injector_latency_ch0", "float", "000086f8", "Latency channel 0 (secondary) value; pair a0a0 mirror; read in injector_pulse_set_channel (0x8a68) pulse = a094[ch] + (a010[ch*0x18]>>4)."),
    ("ffffa098", "injector_latency_ch1", "float", "000086f8", "Latency channel 1 (primary); pair a0a4 mirror."),
    ("ffffa09c", "injector_latency_ch2", "float", "000086f8", "Latency channel 2 (primary); pair a0a8 mirror."),
    ("ffffa0a0", "injector_latency_ch0_mirror", "float", "000086f8", "Mirror of a094 written by the same call."),
    ("ffffa0a4", "injector_latency_ch1_mirror", "float", "000086f8", "Mirror of a098."),
    ("ffffa0a8", "injector_latency_ch2_mirror", "float", "000086f8", "Mirror of a09c."),
    ("ffffa0ac", "injector_zero_offset_ch0", "float", "000086ac", "Zero/offset channel 0; pair a0b8 mirror; caller 0x10208 ref_setAllInjectorto0_."),
    ("ffffa0b0", "injector_zero_offset_ch1", "float", "000086ac", "Zero/offset channel 1; pair a0bc."),
    ("ffffa0b4", "injector_zero_offset_ch2", "float", "000086ac", "Zero/offset channel 2; pair a0c0."),
    ("ffffa0b8", "injector_zero_offset_ch0_mirror", "float", "000086ac", "Mirror of a0ac."),
    ("ffffa0bc", "injector_zero_offset_ch1_mirror", "float", "000086ac", "Mirror of a0b0."),
    ("ffffa0c0", "injector_zero_offset_ch2_mirror", "float", "000086ac", "Mirror of a0b4."),
    ("ffffa010", "injector_fuel_request_array", "int", "00008a68", "Per-channel fuel request array, 0x18-byte stride from a010 (= base a004+0xc); pulse = (latency a094[ch] + a010[ch*0x18]) >> 4 per disasm 0x8a8e-0x8aa0."),
    ("ffffa014", "injector_start_angle_array", "short", "00008a68", "Per-channel start compare, 0x18-byte stride from a014; written to ATU-II GR1A."),
    ("ffffa017", "injector_channel_enable_flag", "uint8", "000085e4", "Checked/cleared per channel (0x18 stride) by injector_channel_disable (0x85e4)."),
    ("ffffa018", "injector_channel_tier_flag", "uint8", "000085e4", "Per-channel ATU-II TIER enable mirror; cleared when channel disabled or pulsed."),
    ("ffffc010", "warmup_complete_flag", "uint8", "00032e08", "c010 = 1 when catalyst-temp model >= 5 C (or >= 200 C when ce33 set); selects warmup vs fault speed-based tables and tip-in table pair."),
    ("ffffc014", "warmup_load_multiplier", "float", "00032e08", "c014 = tbl 0x6ae28 'Warmup - Load Based Multiplier'(load) * 3D tbl 0x6ae3c 'Warmup Fueling'(coolant, cat model)."),
    ("ffffc018", "warmup_rpm_multiplier", "float", "00032e08", "c018 = 3D tbl 0x6ae58 (or coolant-fault 0x6ae74)(rpm, coolant)."),
    ("ffffc00c", "warmup_enrichment_total", "float", "00032e08", "c00c = c014 + c018; feeds calc_fuel_volume_request (0x306e8: min(bf1c, c00c + b120)) and closed_loop_fuel_trim (0x307e0)."),
    ("ffffb124", "open_loop_changeover_enrichment", "float", "0002024c", "b124 = tbl 0x69e00 'Open Loop Changeover Enrichment'(RPM) when b146 != 0 else 0; feeds 0x306e8 via max(ae10, b124)."),
    ("ffffc158", "load_delta_input", "float", "00033ec4", "c158 = load delta input; c134 = tbl 0x6b124(c158) * tbl 0x6b0c0(load) when c158 >= 0."),
    ("ffffc138", "load_delta_scale", "float", "00033ec4", "c138 = lookup_2d tbl 0x6b124(c158)."),
    ("ffffc13c", "load_scale_2d", "float", "00033ec4", "c13c = lookup_2d tbl 0x6b0c0(engine_load)."),
    ("ffffc134", "load_delta_enrichment", "float", "00033ec4", "c134 = c138 * c13c (0 when load delta < 0)."),
    ("ffffc110", "tip_in_decay", "float", "00033ec4", "c110 = max(c110 - 0.0078125, 1.0) when c14c set."),
    ("ffffc140", "tip_in_enrichment", "float", "00033ec4", "c140 = 3D tbl 0x6b160 (or 0x6b17c when warmup c010)(rpm, coolant); 0 when injectors off."),
    ("ffffc14c", "tip_in_mode_flag", "uint8", "00033ec4", "c14c gates the c110 decay in load_delta_enrichment."),
    ("ffffbeb4", "closed_loop_trim_raw", "float", "000307e0", "beb4 = clamp((max(bf40, c01c+b0c4) + min(tbl 0x6ac38(coolant), b120) + 1)*ad ecc - 1, -1, 2) in closed loop; 0 in open loop."),
    ("ffffbeb8", "closed_loop_trim_filtered", "float", "000307e0", "beb8 = first_order_filter(beb4, beb8, 0.0625, 1e-05); STFT-style trim."),
    ("ffffbf20", "cl_coolant_compensation", "float", "000307e0", "bf20 = lookup_2d tbl DAT_0006ac38(coolant); used in closed_loop_fuel_trim."),
    ("ffffc0b0", "engine_load_raw", "float", "00033ad2", "c0b0 = raw load input filtered into engine_load c0b4 (coeff 0.2, or 1.0 when c0c4 set)."),
    ("ffffc0b8", "engine_load_max", "float", "00033ad2", "c0b8 = clamp maximum for engine_load c0b4 = min(filter(c0b0,...), c0b8)."),
    ("ffffc0c4", "load_filter_fast_flag", "uint8", "00033ad2", "c0c4 selects filter coefficient 1.0 vs 0.2 in calculate_engine_load."),
    ("ffffc0c5", "injectors_off_previous", "uint8", "00033ad2", "c0c5 = previous engine_injectors_off a42c; forces load 0.525 on injector-off edge."),
    ("ffff9eea", "maf_adc_raw", "uint16", "00007438", "Raw MAF ADC value; scaled *5/65536 into tbl 0x69788 'MAF Scaling'; fault bands <0xac0 / >=0xfae2."),
    ("ffff9f78", "maf_scaled", "float", "00007438", "9f78 = lookup_2d tbl 0x69788(raw * 5/65536); latched into a9e8 by maf_voltage_and_fault_counters (0x19f4e)."),
    ("ffff9f7c", "maf_fault_status", "uint8", "00007438", "9f7c: 0 = raw < 0xac0 (low), 1 = normal, 2 = raw >= 0xfae2 (high)."),
    ("ffffaa2c", "maf_voltage", "float", "00019f4e", "aa2c = rx8_decode_u16_affine(0x38a00000, 0, raw 9eea): MAF voltage; latched into a9e4 on fault."),
    ("ffffaa35", "maf_high_fault_counter", "uint8", "00019f4e", "Saturating counter incremented while raw >= 0xf852."),
    ("ffffaa36", "maf_low_fault_counter", "uint8", "00019f4e", "Saturating counter incremented while raw < 0x7ae; cleared otherwise."),
    ("ffffa9e4", "maf_voltage_latched", "float", "00019f4e", "a9e4 = aa2c when MAF faulted (>2 on either counter or raw in 0x7ae..0xf852 window)."),
    ("ffffa9e8", "maf_scaled_latched", "float", "00019f4e", "a9e8 = 9f78 (maf_scaled) on fault; becomes mass_air_flow a9ec via 0x19f40."),
    ("ffffaa54", "maf_filter_coeff", "float", "0001a418", "aa54 = lookup_2d tbl 0x697b4(rpm); filter coefficient for MAF per-rotation calc."),
    ("ffffaa48", "maf_filter_state", "float", "0001a418", "aa48 = first_order_filter(maf, aa48, aa54)."),
    ("ffffaa3c", "maf_per_rotation", "float", "0001a418", "aa3c = min(maf*60/rpm, 5.0) (maf*0x42700000/rpm)."),
    ("ffffaa38", "maf_per_rotation_filtered", "float", "0001a418", "aa38 = filtered maf*60/rpm; 0.1560058 when rpm ~ 0."),
    ("ffffaa4c", "maf_filter_mode", "uint8", "0001a418", "aa4c selects filtered vs instantaneous MAF for the per-rotation calc."),
    ("ffffb0fe", "maf_range_index", "uint8", "0001e842", "b0fe = 0..3 MAF operating range from mass_air_flow bands (<1, <9, <22)."),
    ("ffffb101", "maf_band_low", "uint8", "0001e842", "b101 = maf < 1 (hysteresis 0.4)."),
    ("ffffb102", "maf_band_mid", "uint8", "0001e842", "b102 = maf < 9 (hysteresis 8.4)."),
    ("ffffb103", "maf_band_high", "uint8", "0001e842", "b103 = maf < 22 (hysteresis 21.4); all clear -> range 3."),
    ("ffffa434", "max_injection_angle_1", "float", "0000e48e", "a434 = tbl 0x68ef8(rpm) 'Max Injection Angle1???'."),
    ("ffffa438", "max_injection_angle_2", "float", "0000e48e", "a438 = tbl 0x68f0c(rpm) 'Max Injection Angle2???'."),
    ("ffffa43c", "max_injection_angle_3", "float", "0000e48e", "a43c = tbl 0x68f20(rpm) 'Max Injection Angle3???'."),
    ("ffffa41c", "engine_stopped_latch", "uint8", "0000e2a8", "a41c blocks the injectors-off flag a42c; also forces load 0.525 in calculate_engine_load (0x33ad2)."),
    ("ffffa444", "fuel_cut_flag_a", "uint8", "0000edc4", "Set by fuel_cut_arbitration (0xedc4) from request a464 / mode param."),
    ("ffffa445", "fuel_cut_flag_b", "uint8", "0000edc4", "Second fuel-cut flag set alongside a444 in 0xedc4."),
    ("ffffa464", "fuel_cut_request_a", "uint8", "0000edc4", "Input request: when set, a444 = a445 = 1 unconditionally."),
    ("ffffa465", "fuel_cut_request_b", "uint8", "0000edc4", "Input request: with a4a3/a4a2 mirrors gates a444 by param_1 band (0/12 vs 6/18)."),
    ("ffffa4a2", "fuel_cut_request_a_prev", "uint8", "0000edc4", "Mirror of a464 stored at end of 0xedc4."),
    ("ffffa4a3", "fuel_cut_request_b_prev", "uint8", "0000edc4", "Mirror of a465 stored at end of 0xedc4."),
    ("ffffa964", "fuel_cut_allowed", "uint8", "00018cfe", "a964 = (a96a && rpm>=2500) || (a96c && rpm>=1700); set by fuel_cut_rpm_condition (0x18cfe)."),
    ("ffffa97c", "rpm_above_2500_flag", "uint8", "00018cfe", "a97c = rpm >= 2500 (clear below 1700) - hysteresis."),
    ("ffffa97d", "rpm_above_1700_flag", "uint8", "00018cfe", "a97d = rpm >= 1700 (clear below 1100) - hysteresis."),
    ("ffffa96a", "decel_cut_request_a", "uint8", "00018cfe", "a96a: decel/overrun cut request input to fuel_cut_rpm_condition (0x18cfe)."),
    ("ffffa96c", "decel_cut_request_b", "uint8", "00018cfe", "a96c: second request input; pairs with a96a in the a964 OR."),
    ("ffffa4a6", "coolant_below_18c_flag", "uint8", "0000ee82", "a4a6 = coolant < 18 C (clear at 20) - cold-engine rev-limit derate condition."),
    ("ffffa4aa", "rev_limit_countdown_active", "uint8", "0000ee82", "a4aa = (a4ae != 0); set by rev_limit_conditionals (0xee82)."),
    ("ffffa4ad", "rev_limit_mode_previous", "uint8", "0000ee82", "a4ad = previous DAT_ffffbaec (mode) for change detection."),
    ("ffffa4ae", "rev_limit_countdown", "uint8", "0000ee82", "a4ae = 0x0f on mode change (b534==0 && baec active && a4ad==0 && baec != 7), decremented while a4aa."),
    ("ffffa4a4", "rev_limit_state_a", "uint8", "0000ee64", "Cleared by rev_limit_fuel_cut_init (0xee64) when 9f8c==1."),
    ("ffffa4a5", "rev_limit_state_b", "uint8", "0000ee64", "Cleared by 0xee64."),
    ("ffffa4a8", "rev_limit_state_c", "uint8", "0000ee64", "Cleared by 0xee64."),
    ("ffffb11c", "fuel_blend_weight", "float", "000200c6", "Set with b118 by blend_weight_update (0x200c6): 1.0 normal, decays -0.0667 in open loop, 0 on faults; weights the implausible-coolant OL target branch in 0x1ee4a."),
    ("ffffb118", "timing_blend_weight", "float", "000200c6", "Same producer as b11c (0x200c6); blends base ignition timing with the open-loop cap in 0x11f00/0x1206c."),
    ("ffffb1d0", "coolant_plausible_flag", "uint8", "000200c6", "b1d0 = 1 when coolant >= -40 C (clear below -43); gates blend-weight set in 0x200c6."),
    ("ffffb170", "ol_baro_base_correction", "float", "0001ee4a", "b170 = tbl 0x69cac/0x69cc0 'Open Loop Fuelling Base Correction (Throttle)'(baro) (safe-mode variant selected by cd60==0)."),
    ("ffffb174", "ol_rich_limit", "float", "0001ee4a", "b174 = tbl 0x69ce8/0x69cfc 'Open Loop Fuelling Rich Limit'(baro) (safe-mode pair)."),
    ("ffffb190", "ol_tip_in_target", "float", "0001ee4a", "b190 = 3D tbl 0x69e80/0x69eb8 'Open Loop Target - Throttle Tip In'(rpm, throttle)."),
    ("ffffb194", "ol_target_3d", "float", "0001ee4a", "b194 = 3D tbl 0x69e9c/0x69ed4 'Open Loop Target'(load, rpm)."),
    ("ffffb198", "ol_tip_in_implausible", "float", "0001ee4a", "b198 = 3D tip-in vs coolant-implausible tables 0x69ef0/0x69f28 (gear 5-6 vs 1-4 select by safe_mode b12d)."),
    ("ffffb19c", "ol_target_implausible_3d", "float", "0001ee4a", "b19c = 3D 'Open Loop Target - Coolant Temp Implausible'(load, rpm) 0x69f0c/0x69f44."),
    ("ffffb130", "ol_fuel_target_main", "float", "0001ee4a", "b130 = max(b170*b190, b194); normal OL target product."),
    ("ffffb134", "ol_coolant_correction", "float", "0001ee4a", "b134 = tbl 0x69cd4 'Open Loop Target - Coolant Temperature Correction'(coolant)."),
    ("ffffb138", "ol_fuel_target_implausible", "float", "0001ee4a", "b138 = max(b174*b198, b19c); coolant-implausible OL target product."),
    ("ffffb13c", "ol_temperature_correction_b", "float", "0001ee4a", "b13c = tbl 0x69d10 'Open Loop Temperature Correction #B'(coolant)."),
    ("ffffb150", "ol_target_select", "uint8", "0001ee4a", "b150 != 0 (with coolant plausible b1d9) selects b120 = b130*b134; else blended implausible branch weighted by b11c."),
    ("ffffb15c", "cl_throttle_threshold", "float", "0001f0c4", "b15c = tbl 0x69d74 'Closed Loop Fuelling Threshold (Throttle Position)'(rpm); compared against throttle ad44 in open_loop_request_condition."),
    ("ffffb160", "cl_load_threshold_a", "float", "0001f0c4", "b160 = tbl 0x69d24 'Closed Loop Fuelling Threshold (Engine Load A)'(rpm)."),
    ("ffffb164", "cl_load_threshold_b", "float", "0001f0c4", "b164 = tbl 0x69d38 (Engine Load B)(rpm)."),
    ("ffffb168", "cl_load_threshold_c", "float", "0001f0c4", "b168 = tbl 0x69d4c (Engine Load C)(rpm)."),
    ("ffffb16c", "cl_unknown_threshold_a", "float", "0001f0c4", "b16c = tbl 0x69d60 'Closed Loop Fuelling Threshold (Unknown A)'(rpm)."),
    ("ffffb1b6", "cl_load_a_exceeded", "uint8", "0001f0c4", "b1b6 = load >= b160 (hysteresis -0.04) in 0x1f0c4."),
    ("ffffb1b7", "cl_load_b_exceeded", "uint8", "0001f0c4", "b1b7 = load >= b164 (hysteresis) in 0x1f0c4."),
    ("ffffb1b8", "cl_load_c_exceeded", "uint8", "0001f0c4", "b1b8 = load >= b168 (hysteresis) in 0x1f0c4."),
    ("ffffb1b1", "coolant_above_78_flag", "uint8", "0001f0c4", "b1b1 = coolant >= 80 (clear below 78) in open_loop_request_condition."),
    ("ffffb178", "cl_load_threshold_2d_a", "float", "0001ff38", "b178 = tbl 0x69d88(rpm); load compare with hysteresis -> b1b9."),
    ("ffffb17c", "cl_load_threshold_2d_b", "float", "0001ff38", "b17c = tbl 0x69d9c(rpm) -> b1bb."),
    ("ffffb1b9", "load_above_thresh_a", "uint8", "0001ff38", "b1b9 = load >= b178 (hysteresis -0.04); part of OL band condition in 0x1ff38."),
    ("ffffb1bb", "load_above_thresh_b", "uint8", "0001ff38", "b1bb = load > b17c (hysteresis) in 0x1ff38."),
    ("ffffb1ba", "rpm_above_800_flag", "uint8", "0001ff38", "b1ba = rpm >= 1000 (clear below 800) in 0x1ff38."),
    ("ffffb1bc", "rpm_above_5300_flag", "uint8", "0001ff38", "b1bc = rpm > 5500 (clear below 5300) in 0x1ff38."),
    ("ffffb1d8", "coolant_above_97_flag", "uint8", "0001ff38", "b1d8 = coolant >= 100 (clear below 97) in 0x1ff38."),
    ("ffffb144", "ol_condition_timer", "uint16", "0001ff38", "b144 decremented when band condition (b154) holds; set to 0x493e (18750) when coolant < 97; b159 = timer-expired flag."),
    ("ffffb154", "ol_band_condition", "uint8", "0001ff38", "b154 = b1b9 && !b1bb && b1ba && !b1bc (load/RPM band); feeds b144 countdown and blend_weight_update (0x200c6)."),
    ("ffffb159", "ol_timer_expired", "uint8", "0001ff38", "b159 = (b144 == 0 && b1d8); checked in 0x200c6 decay condition."),
    ("ffffb180", "cl_load_threshold_2d_c", "float", "0001f6ae", "b180 = tbl 0x69db0(rpm); throttle/load band compares -> b1be/b1c2 in 0x1f6ae."),
    ("ffffb184", "cl_load_threshold_2d_d", "float", "0001f6ae", "b184 = tbl 0x69dc4(rpm)."),
    ("ffffb188", "cl_load_threshold_2d_e", "float", "0001f6ae", "b188 = tbl 0x69dd8(rpm) -> b1c6."),
    ("ffffb18c", "cl_load_threshold_2d_f", "float", "0001f6ae", "b18c = tbl 0x69dec(rpm) -> b1ca."),
    ("ffffb1c6", "load_above_thresh_c", "uint8", "0001f6ae", "b1c6 = load >= b188 (hysteresis) in 0x1f6ae."),
    ("ffffb1ca", "load_above_thresh_d", "uint8", "0001f6ae", "b1ca = load > b18c (hysteresis) in 0x1f6ae."),
    ("ffffb1c7", "rpm_above_5300_flag_b", "uint8", "0001f6ae", "b1c7 = rpm > 5500 (clear below 5300); second copy in 0x1f6ae."),
    ("ffffb1cb", "rpm_above_9800_flag", "uint8", "0001f6ae", "b1cb = rpm > 10000 (clear below 9800) in 0x1f6ae."),
    ("ffffb142", "ol_decay_enable_a", "uint8", "000200c6", "b142 checked (with b157) in the blend_weight_update decay condition 0x200c6."),
    ("ffffb152", "ol_decay_enable_b", "uint8", "000200c6", "b152 checked in the fault branch of 0x200c6."),
    ("ffffb157", "ol_decay_enable_c", "uint8", "000200c6", "b157 must be set (with b142) for the b11c/b118 decay branch in 0x200c6."),
    ("ffffaa6c", "diag_afr_word_a", "float", "000556ec", "Encoded (step 0x38000000) as high word of PID 0x0034 'Air Fuel Ratio'."),
    ("ffffaa7c", "diag_afr_word_b", "float", "00055702", "Encoded (mult 0.0625, offset -96.0) as low word of PID 0x0034."),
]

LOOKUP = [
    # original, alias, evidence
    ("DAT_0006ac38", "tbl_fuel_coolant_compensation_0006ac38",
     "2D lookup vs coolant used by calc_fuel_volume_request 0x306e8 (bf1c) and closed_loop_fuel_trim 0x307e0 (bf20). Descriptor not matched to an RX8Defs table (nearest matched neighbours 0x6ac4c 'Table 2D - 182', 0x6ac60 'Secondary Injectors Allowed Threshold - Coolant Temperature Based'); name is a dataflow hypothesis."),
]


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
                                             ['address', 'name', 'body_bytes', 'status', 'file'])}
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
    val['date'] = '2026-10-30'
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    vp.write_text(json.dumps(val, indent=2) + '\n')

    record = {
        'date': '2026-10-30',
        'pass': 'fueling_chain_labeling',
        'basis': BASIS,
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'lookup_aliases': {o: {'alias': al, 'evidence': ev} for o, al, ev in LOOKUP},
        'backup': 'backups/pre_fueling_labels.zip',
        'rom_unchanged': True,
        'ghidra_database_updated': False,
        'notes': 'Fueling chain: MAF->load->air charge->fuel volume->per-rotation amounts->pulse arbitration->ATU-II injector outputs; OL/CL target selection; warmup/changeover/tip-in enrichments; fuel cut and rev limit; diag PIDs 0x0034/0x0043/0x0044/0x1410. Resolves knock-review unresolved item 2 (blend weights b11c/b118 producer 0x200c6).',
    }
    (b / 'metadata/fueling_labels.json').write_text(json.dumps(record, indent=2) + '\n')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
