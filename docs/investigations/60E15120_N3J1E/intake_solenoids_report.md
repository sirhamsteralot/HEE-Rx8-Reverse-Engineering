# Intake solenoid actuation report — 60E15120_N3J1E (RX-8 PCM, SH7055F / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`decompiled/`), the disassembly and the ROM bytes, with package pins from the
supplied SH7055F hardware manual (`Sh7055h.pdf`), plus dynamic execution of
the SSV and fuel-split functions in the SH-2E emulator (no hardware execution).
Full evidence: [`reviews/intake_solenoids/README.md`](reviews/intake_solenoids/README.md).

**Related reports:** RPM/load thresholds share the [load & fuelling model](load_fueling_report.md) inputs; catalyst-warmup enrichment comes from [fueling control](fueling_control_report.md) (0x31624); the SSV on-term `secondary_injectors_active_flag` (0xffffbecd) comes from the fuel split at 0x30b08 in [fueling control](fueling_control_report.md) (§2.1 here); solenoid tables in [calibration extraction](calibration_extraction_report.md); the secondary-air state is diag-exposed as Mode 22 PID 0x12 (1/4, handler 0x56a06 reads `secondary_air_request_final_ffffa960`) and PID 0x1688/0x1104 status bits — [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md).

## 1. Executive summary

The PCM drives four intake solenoids (SSV, VFAD, VDI, secondary-air) as plain
GPIO bits and the APV (auxiliary port valve) as a closed-loop motor with
software PWM, plus a secondary-air pump relay. All solenoid controls run in
the task 0x64f6 → 0x11744 chain with UDS diagnostic actuator overrides:
**VDI** opens at RPM ≥ 7250 (hyst 7062), **VFAD** at RPM ≥ 5250 (hyst 5062),
**SSV** on a cold/engine-state edge with a 0xbc-cycle counter (coolant 197/200 °C
hysteresis) **or whenever the secondary-injector split is active**
(`secondary_injectors_active_flag` 0xffffbecd, computed in the fueling chain at 0x30b08 — see §2.1), **secondary
air** solenoid + pump at load ≤ 0.8 and RPM ≤ 4000
(catalyst warmup, with matching enrichment fuel from 0x31624 in the fueling
chain). **APV** is position-controlled: target from RPM/MAF/coolant →
dwell/drive counters → staged 100.0/12.5 % command → signed duty split (×96
period) → software PWM on PL5/PL8, with position feedback on ADC6/AN6.

Every output is identified at GPIO-bit level and mapped to a SH7055F package
pin via the hardware manual; the package-pin → PCM-connector-terminal hop is
board routing and deliberately not asserted (see §9).

## 1a. Plain-language summary (what the solenoids do)

- The four intake solenoids (SSV, VFAD, VDI, secondary air) are simple
  **on/off valves** switched by engine-state windows: VDI opens at high RPM
  (>= 7250), VFAD at mid-high RPM (>= 5250), SSV on a cold start **and whenever
  the secondary injectors are active** (high-load/high-RPM fueling — see §2.1),
  and the secondary-air solenoid + pump run at low load/low RPM to warm up the
  catalytic converter.
- The APV is different: it is a **motor with closed-loop position control**
  (target from RPM/airflow/coolant, driven by software PWM, position read
  back on an ADC pin).
- UDS diagnostic actuator overrides can force any of these for testing —
  that is a service command, not normal driving behavior.
- The GPIO-bit to chip-pin mapping is chip-level; pin to PCM-connector
  terminal is board routing and is deliberately not asserted in this report.

## 2. How it works (condensed pseudocode)

```python
# --- periodic chain: task 0x64f6 -> 0x11744 -> wrappers 0x21766 `ssv_control_task_wrapper` / 0x348ea `vdi_control_task_wrapper` / 0x34916 `vfad_control_task_wrapper` (mask 0x10; u32 call targets at ROM 0x11998/0x1199c/0x119a0 re-read this pass) ---
# SSV (GPIO PE7 = PEDR_W 0xfffff754 bit 0x80; pkg pin 16; terminal 1L)
ssv_coolant_hot = coolant >= 200 (clear < 197)            # b2b4
if engine_state aa68 == 0 and prev b2b5 == 1: ssv_on_counter b2b2 = 0xbc
elif b2b2 != 0: b2b2 -= 1
ssv_on = secondary_injectors_active_flag                    # 0xffffbecd: from 0x30b08 (see §2.1)
         or (aa68 == 0 and b2b2 != 0 and not ssv_coolant_hot)   # cold/engine-stopped edge, counter b2b2
ssv_on = diag_override(0x5c9ac, ssv_on)                   # b2b0; UDS actuator test passthrough
set_bit(PEDR_W, 0x80, ssv_on)

# VDI (PD5 = PDDR_W 0xfffff746 bit 0x20; pin 254; terminal 1W)
vdi_cmd = rpm >= 7250 (clear < 7062)                      # c1c0; binary: 7250.0 and -188 offset
set_bit(PDDR_W, 0x20, diag_override(0x5c3c0 `vdi_diag_override`, vdi_cmd))

# VFAD (PE10 = PEDR_W bit 0x400; pin 19; terminal 5Z)
vfad_cmd = rpm >= 5250 (clear < 5062)                     # c1c4
set_bit(PEDR_W, 0x400, diag_override(0x5cdc4 `vfad_diag_override`, vfad_cmd))

# --- secondary air: task 0x6584 -> 0x117ac ---
sec_load_high  = load > 0.8 (clear < 0.75)                 # a961
sec_rpm_high   = rpm > 4000 (clear < 3900)                # a962
sec_air_req    = (bf6c and not sec_load_high and not sec_rpm_high) or d26e
a960 = diag_override(0x5cf7c, sec_air_req)
set_bit(PEDR_W, 0x100, a960 == 1)                         # PE8, pin 17, terminal 1O (solenoid)
set_bit(PBDR_W, 0x4, bf6c == 1)                           # PB2, pin 147 (pump, via 0x316f8)

# --- APV closed loop: task 0x64f6 -> 0x11744 -> apv_control_task 0x31c20 ---
apv_target  bf8d = f(rpm>=200/150 bf99, bf92>0x32, aa68; MAF a9ec, coolant a98c)   # 0x31c6c
bf88 = 0 if (bf8b==0 or (bf88>0x4e1 and cab4==0)) else bf88+1                     # 0x31ece
bf8a = 0 if bf8b==1 else bf8a+1                                                   # 0x31f0a
bf84 = 0  if rpm<2800/3000 or (bf8d==0 and bf88>0x58)
     else 100.0 if bf88<0x32 else 12.5                                             # 0x31f32 (inline float literals; bands u16 @ROM 0x78bb2-0x78bc0)
bf84 = (bf8b ? -bf84 : bf84) / 100.0                                               # 0x31bec
fwd,rev = bf84*96 > 0 ? (int)(bf84*96), 0 : 0, (int)(-bf84*96)                   # 0xaa90; period u16 ROM 0x78bb6 = 96
# 0xa936 software PWM: latch fwd/rev -> `apv_pwm_forward_latched` a1c0 / a1c2 at period boundary (pool 0xa9f6 re-read), drive PLDR_W
#   bit 0x20 (PL5, pin 221) and bit 0x100 (PL8, pin 224) with opposite polarity
# status: PHDR_W bits 0x1000/0x2000 (PH12/PH13, pins 79/80) -> a1bc (0xaac4)
# feedback: ADC6 raw 9ef0 (reg 0xfffff80c, AN6 pin 92) * 5/65536 -> cab0 volts (0x43a86)
```

### 2.1 SSV ↔ secondary injectors: the SSV follows the fuel split

The SSV on-condition's first term, `secondary_injectors_active_flag` (0xffffbecd), is **not**
computed in the intake task — it is produced by the fueling chain's
primary/secondary split function 0x30b08 (called from the periodic fuel task
0x20e40 between `calculate_fuel_amount_per_rotation` 0x30948 and
`injector_pulse_time_arbitrate` 0x2fea8; see
[fueling control §2](fueling_control_report.md)). 0x30b08 computes:

```python
bf24 = lookup2d(coolant, tbl_0x6ac74)        # split_high_rpm_threshold (0xffffbf24): flat 6250 rpm — high-RPM override
bf36 = rpm >= bf24  (188 rpm hysteresis)     # high_rpm_override_flag 0xffffbf36
bf28 = lookup2d(coolant, tbl_0x6ac60)        # secondary_allowed_rpm_threshold (0xffffbf28): "Secondary Injectors
                                             #  Allowed Threshold - Coolant Based" (3000 rpm <= 0 C, 0 warm)
bf37 = rpm >= bf28  (188 rpm hysteresis)     # secondary_allowed_rpm_flag 0xffffbf37
bf04 = fuel_amount_per_rotation_a (bec8); if throttle >= 60%: bf04 *= baro_corr tbl_0x6ab84   # split_fuel_gate_threshold
bf38 = fuel_volume_final (beb0) >= bf04      # split_fuel_gate_wot_flag 0xffffbf38
bf39 = fuel_volume_final (beb0) >= bec8      # split_fuel_gate_flag 0xffffbf39
becd = bf36 or (bf37 and bf38)               # secondary_injectors_active_flag 0xffffbecd -> SSV on-term (0x2178c)
becc = bf36 or (bf37 and bf39)               # secondary_split_gate_flag 0xffffbecc -> gates the fuel split itself:
                                             #   becc==0 => all fuel to primaries (bef4=0),
                                             #   becc==1 => split by ratio tbl_0x6ab70
```

So the dependency runs **from the injectors to the SSV, not the other way
round**: whenever the secondary injectors are actually getting fuel (becd=1),
the SSV is commanded on — even with the engine running, counter at 0, and even
when the coolant-hot flag b2b4 is set (the becd term bypasses the 197/200 °C
hysteresis; only the counter path is blocked by it). Conversely the SSV can be
on with the secondaries off (the cold/engine-stopped counter path). The SSV
state is not read back by the fuel split. Dynamically verified in the SH-2E
emulator (harness calls to 0x2178c / 0x30b08): becd=1 → PE7 high in all
combinations tested; becd=0 with engine running → PE7 low; becd=0 at 0 °C
coolant below 3000 rpm, or with fuel demand below the primary-only amount →
becd/becc clear → PE7 low unless the counter path fires. Script + log:
[`reviews/intake_solenoids/ssv_secondary_injector_link.py`](reviews/intake_solenoids/ssv_secondary_injector_link.py)
+ [`ssv_secondary_injector_link_log.txt`](reviews/intake_solenoids/ssv_secondary_injector_link_log.txt).
(`secondary_split_gate_flag` 0xffffbecc is also read by the open-loop request logic 0x1f0c4/0x1fd48.)

## 3. Actuator → GPIO → package pin → terminal

| Actuator | Control fn | GPIO reg/bit | Port pin | SH7055F pin (Table 1.3) | Terminal |
|---|---|---|---|---|---|
| SSV solenoid | 0x2178c | PEDR_W 0xfffff754, 0x80 | PE7 | 16 | 1L (FSM "SSV control") |
| VFAD solenoid | 0x3493c | PEDR_W, 0x400 | PE10 | 19 | 5Z (FSM "VFAD control", HP ³) |
| VDI solenoid | 0x34844 | PDDR_W 0xfffff746, 0x20 | PD5 | 254 | 1W (FSM "VDI control") |
| Sec-air solenoid | 0x187b8 | PEDR_W, 0x100 | PE8 | 17 | 1O (FSM "AIR control") |
| Sec-air pump | 0x316f8 | PBDR_W 0xfffff738, 0x4 | PB2 | 147 | pump circuit |
| APV motor F/R | 0xa936 | PLDR_W 0xfffff75e, 0x20 / 0x100 | PL5 / PL8 | 221 / 224 | 3J/3G (FSM "APV motor control ∓", HP ³) |
| APV status in | 0xaac4 | PHDR_W 0xfffff72c, 0x1000/0x2000 | PH12/PH13 | 79 / 80 | candidate |
| APV position in | 0x43a86 | ADC6 0xfffff80c → RAM 9ef0 | AN6 | 92 | 3B (FSM "APV opening angle", HP ³; +1S/1U) |

GPIO bits verified in the disassembly (reg low16 + 0xffff high half, masks as
pool literals or `mov #imm`, helper 0x4bbc); pins quoted from `Sh7055h.pdf`
Table 1.3; terminals from `hardware/pcm_connections.tsv`, cross-checked against the supplied
`mazda-rx-8-pcm-pinout-series-1.pdf` (FSM terminal table; markers ³/†/* kept; the PDF has
no chip-pin data, so package-pin → terminal remains board routing).

## 4. Key ROM data and constants

| Address | Contents |
|---|---|
| 0x78bb6 | APV PWM period u16 = 96 (referenced by 0xaa90's pool) |
| 0x78bb2–0x78bc0 | u16 APV counter band thresholds (0x32, 0x59, …) referenced by 0x31f32 |
| 0x31f32 literal pool | APV command levels 100.0 (0x42c80000), 12.5 (0x41480000); RPM 3000.0 (lower bound folded as 3000−200) |
| shared pool 0x77fd0/0x77ff0 | 197.0 (SSV coolant hysteresis); 0x2178c pool has 200.0 |
| 0x34844 pool | 7250.0 and 188.0 (hysteresis lower bound 7062 = 7250−188, folded) |
| 0x3493c / 0x187b8 pools | 5250.0 / 4000.0 and offsets; 0.8 / 0.75 in shared pool |
| 0x5d4a, 0x72732, 0x7323a | 0xbc (SSV on-counter) u16 in shared pools |
| desc 0x6ac60 (data 0x78510) | "Secondary Injectors Allowed Threshold - Coolant Temperature Based" u16 vs coolant: 3000 rpm at ≤ 0 °C, 0 above ~20 °C — feeds becd/becc via 0x30b08 |
| desc 0x6ac74 (data 0x78548) | flat 6250 rpm u16 (0x186a) high-RPM override — bf36 via 0x30b08 |
| desc 0x6ab70 (data 0x78230) | primary/secondary ratio vs rpm (tbl "2D - 177") — the split ratio in 0x30b08 |
| desc 0x6ab84 (data 0x78264) | "Primary Injector Max Barometric Pressure Correction" vs baro — WOT fuel gate bf04 in 0x30b08 |

## 5. Labeling applied

- 26 functions + 26 RAM locations added to `source_review/accepted_*_aliases.tsv`
  by `scripts/review_intake_labels.py` (idempotent; wired into `rebuild.sh`
  after `review_fueling_labels.py`), integrated into all synchronized views
  (per-function files, `decompiled/firmware_decompiled.c`,
  `named/firmware_named.c`, index/callgraph/symbols, `integrated_names.json`).
  Medium-confidence names carry `candidate_` in the views. Record:
  `metadata/intake_labels.json`; backup: `backups/pre_intake_labels.zip`.
- The SSV on-term `secondary_injectors_active_flag` (0xffffbecd) and the rest
  of the fuel-split cells are labeled by `scripts/review_fuel_split_labels.py`
  (record `metadata/fuel_split_labels.json`) — see §2.1.
- Design doc updated: [`design/README.md`](../../architecture/design/README.md) §5.9.

## 6. Corrections made in this pass

1. Binary-level verification found the APV command levels 100.0/12.5 are
   inline literals in 0x31f32's pool, not at ROM 0x78bb8/0x78bbe (those are the
   u16 band thresholds) — evidence text fixed everywhere.
2. Documented that hysteresis lower bounds (7062/5062/3900/2800) are folded
   threshold-minus-offset in the binary, not standalone literals.
3. Injector pulse = (latency + request) >> 4 — the
   shift applies to the sum (four `shar` at 0x8a96-0x8a9e).

## 7. Files

| Artifact | Path |
|---|---|
| Full review + binary verification | [`reviews/intake_solenoids/README.md`](reviews/intake_solenoids/README.md) (§7 = verification pass) |
| Review validation record | `reviews/intake_solenoids/validation.json` |
| SSV ↔ secondary-injector dynamic check (script + log) | [`reviews/intake_solenoids/ssv_secondary_injector_link.py`](reviews/intake_solenoids/ssv_secondary_injector_link.py), [`…_log.txt`](reviews/intake_solenoids/ssv_secondary_injector_link_log.txt) |
| Rename/record manifest | `metadata/intake_labels.json` |
| Pipeline script (idempotent, in `rebuild.sh`) | `scripts/review_intake_labels.py` |
| Design doc subsystem map | [`design/README.md`](../../architecture/design/README.md) §5.9 |
| Pre-change backup | `backups/pre_intake_labels.zip` |
| Hardware manual (pin source) | `Sh7055h.pdf` (workspace root; SH7055F HW manual ADE 602-155B) |
| S-DIAS/S-DAIS synthesis vs community claims (secondary, generated — not primary evidence) | [`../../references/mazda-rx-8-s-dias-intake-system-deep-research-report.pdf`](../../references/mazda-rx-8-s-dias-intake-system-deep-research-report.pdf) |
| Rotary intake acoustic-tuning research (background for VDI/VFAD runner-length staging) | [`../../references/Engine_Acoustic_Tuning_Rotary_Intake_Design.pdf`](../../references/Engine_Acoustic_Tuning_Rotary_Intake_Design.pdf) |

## 8. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256 verified, 3,355 function
  files linked, 168,592 instructions byte-verified against the ROM (also
  re-verified independently in the §7 pass), 1,833 exact reference matches.
- `scripts/verify_readability.py` — pass (3,355 bodies consistent).
- `scripts/verify_math_units.py` — pass. `scripts/design_graph_stats.py` — all
  6 cross-checks true.
- Dynamic (SH-2E emulator, harness calls; no hardware): §2.1 — `ssv_solenoid_control`
  0x2178c drives PE7 high exactly when `DAT_ffffbecd`=1 or the counter path fires;
  0x30b08 sets becd/becc per the rpm/coolant/fuel gates. Script + log in
  [`reviews/intake_solenoids/`](reviews/intake_solenoids/README.md) (§2.1 links).
- Binary-level verification (README §7): 26/26 RAM aliases in reader pools,
  26/26 function names in index, all GPIO reg/mask/helper literals, thunk
  targets, call edges, task-table entry, and PDF pin quotes confirmed.

## 9. Memory map for validation

Check any address in `decompiled/firmware_disassembly.asm` (ROM) or
`decompiled/functions/<address>_*.c` (index in `decompiled/function_index.tsv`),
and alias evidence in `source_review/accepted_*_aliases.tsv`.

### 9.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0002178c | `ssv_solenoid_control` | SSV solenoid: PEDR PE7; coolant/counter/diag logic |
| 0x00021760 / 0x00021766 | `ssv_control_thunk` / `ssv_control_task_wrapper` | thunk (pool 0x21780 → 0x2178c) / task 0x11744 wrapper |
| 0x00034844 | `vdi_solenoid_control` | VDI: PDDR PD5; RPM 7250/7062 → diag 0x5c3c0 `vdi_diag_override` |
| 0x000348e4 / 0x000348ea | `vdi_control_thunk` / `vdi_control_task_wrapper` | thunk (pool 0x34904) / wrapper |
| 0x0003493c | `vfad_solenoid_control` | VFAD: PEDR PE10; RPM 5250/5062 → diag 0x5cdc4 `vfad_diag_override` |
| 0x00034910 / 0x00034916 | `vfad_control_thunk` / `vfad_control_task_wrapper` | thunk (pool 0x34930) / wrapper |
| 0x00031c20 | `apv_control_task` | APV wrapper: 0x31c6c + 0x31ece + 0x31f0a + 0x31f32 + 0x31bec |
| 0x00031c6c | `candidate_apv_target_condition` | APV target bf8d (RPM 200/150 bf99, bf92, aa68, MAF, coolant) |
| 0x00031ece | `apv_position_voltage_counter` | bf88 dwell counter |
| 0x00031f0a | `apv_counter_calc` | bf8a drive counter |
| 0x00031f32 | `apv_command_calc` | bf84 staged 100.0/12.5 (own pool) by bf88 bands; RPM 3000/2800 bf98 |
| 0x00031bec | `candidate_apv_command_wrapper` | sign (bf8b) / 100 → 0xaa90 |
| 0x0000aa90 | `apv_duty_split` | ×96 (ROM 0x78bb6) → fwd a1c4 / rev a1c6 |
| 0x0000a936 | `apv_pwm_service` | soft PWM → PLDR 0x20/0x100 (PL5/PL8); calls 0xaac4 |
| 0x0000aac4 | `apv_drive_status_sample` | PHDR 0x1000/0x2000 → a1bc |
| 0x00043a86 | `apv_position_voltage_scale` | ADC6 9ef0 × 5/65536 → cab0 |
| 0x000187b8 | `secondary_air_solenoid_control` | PEDR PE8; load/RPM/bf6c/d26e → diag 0x5cf7c → a960 |
| 0x000316f8 | `secondary_air_pump_control` | PBDR PB2 = bf6c |
| 0x0003174a | `candidate_secondary_air_on_time_task` | 0x3194a + 0x31a24 + 0x316f8 |
| 0x0005c9ac / 0x0005c3c0 / 0x0005cdc4 / 0x0005cf7c | `ssv_diag_override` / `vdi_diag_override` / `vfad_diag_override` / `secondary_air_diag_override` | UDS actuator tests (d3xx state machine) |
| 0x00030b08 | `primary_secondary_fuel_split` | primary/secondary fuel split + split-flag computation; called from fuel task 0x20e40. `secondary_injectors_active_flag` is the SSV on-term (§2.1) |

### 9.2 RAM

| Address | Name | Meaning |
|---|---|---|
| 0xffffb2b0 | `ssv_diag_override_result` | SSV override output → PE7 |
| 0xffffb2b2 | `ssv_on_counter` | 0xbc on edge, decrements |
| 0xffffb2b4 | `ssv_coolant_hot_flag` | coolant ≥ 200 (clear 197) |
| 0xffffb2b5 | `ssv_was_enabled` | previous aa68 |
| 0xffffbecd / 0xffffbecc | `secondary_injectors_active_flag` / `secondary_split_gate_flag` | split flags from 0x30b08; the former is the SSV on-term (§2.1), the latter gates the fuel split and feeds open-loop logic 0x1f0c4/0x1fd48 |
| 0xffffbf36 / bf37 | `high_rpm_override_flag` / `secondary_allowed_rpm_flag` | rpm ≥ 6250 override flag / rpm ≥ coolant-based secondary-allowed threshold flag (0x30b08) |
| 0xffffc1c0 / 0xffffc1c4 | `vdi_command` / `vfad_command` | RPM-hysteresis commands |
| 0xffffa960 / a961 / a962 | `secondary_air_request_final` / `…_load_high` / `…_rpm_high` | sec-air request + gates |
| 0xffffbf6c | `secondary_air_pump_request` | pump PB2 + solenoid condition |
| 0xffffbf84 / bf88 / bf8a / bf8b | `apv_command_percent` / `…_dwell_counter` / `…_drive_counter` / `…_direction_flag` | APV command chain |
| 0xffffbf8d / bf8e / bf92 / bf98 / bf99 | `apv_target_state` / `_prev` / `apv_counter_92` / `apv_rpm_high_flag` / `apv_rpm_low_flag` | APV target logic |
| 0xffffa1c0 / a1c2 / a1c4 / a1c6 | `apv_pwm_forward_latched` / `apv_pwm_reverse_latched` / `apv_pwm_forward_ticks` / `apv_pwm_reverse_ticks` | APV PWM tick counts |
| 0xffffa1bc | `apv_drive_status` | 0..3 from PH12/13 |
| 0xffffcab0 | `apv_position_voltage` | feedback volts |
| 0xffff9ef0 | `adc6_raw_apv_position` | ADC6 raw (AN6) |

### 9.3 GPIO/peripheral registers and ROM data

PEDR_W 0xfffff754 (PE7=SSV, PE8=sec-air solenoid, PE10=VFAD), PDDR_W
0xfffff746 (PD5=VDI), PBDR_W 0xfffff738 (PB2=sec-air pump), PLDR_W 0xfffff75e
(PL5/PL8=APV PWM), PHDR_W 0xfffff72c (PH12/13=APV status), ADC6 0xfffff80c
(AN6=APV position); helper 0x4bbc; task table 0x4998 (task[10] @0x4a38 = 0x64f6,
task[11] @0x4a48 = 0x6584); ROM data 0x78bb2-0x78bc0 (APV constants); port
names from `regs_7055_350.csv`.

### 9.4 How to validate

- ROM integrity + instruction bytes: `python3 scripts/validate_export.py`.
- Any function: `decompiled/functions/<address>_*.c`; disassembly
  `decompiled/firmware_disassembly.asm`.
- Alias evidence: `source_review/accepted_function_aliases.tsv` /
  `accepted_ram_aliases.tsv` rows for basis `source_review_intake`.
- GPIO bit claims: literal pools of the functions in §9.1 (mov.w low16 +
  0xffff high, mov.l, mov #imm) — see [`reviews/intake_solenoids/README.md`](reviews/intake_solenoids/README.md) §7.
- Pins: `Sh7055h.pdf` Tables 1.2/1.3. Terminals: `hardware/pcm_connections.tsv`.

## 10. RPM-window patcher (VDI/SSV)

`Mazda_RX8_PCM_ReverseEngineering/Utilities/patch_intake_rpm_window.py` produces
patched copies of any stock ROM (all 10 located by unique body match) with the
VDI or SSV solenoid open only in `[--open-rpm, --close-rpm]` (default VDI
7000–8500). New on-condition `open <= rpm(0xffffb548) <= close`; UDS diag
override preserved; VDI output PD5 (pin 254, terminal 1W), SSV PE7 (pin 16,
terminal 1L). Stock ROMs are never modified — the patcher writes new
`<name>_<act>_<open>_<close>.bin` files and asserts input SHA-256 unchanged,
diff confined to the function's logic region + pool. Patched code
decode-verified word-by-word. Setpoints live in the cal area as a RomRaider table (descriptor 0x7fb90, data 0x7fba4: cell0=open, cell1=close float32 RPM; def added to RX8Defs_Copy rx8_defs.xml for 60E15120; emitted per-run as <output>.xml) — edit with RomRaider or a hex editor at 0x07FBA4 without re-patching. Static validation only; flash with `Rx8Man/`.
See [`Utilities/PATCHER_intake_rpm_window.md`](../../../utilities/scripts/patchers/PATCHER_intake_rpm_window.md).

## 11. Rev-limiter behavior patcher (see SPEC)

`Utilities/patch_limiter_behavior.py` (+[`PATCHER_limiter_behavior.md`](../../../utilities/scripts/patchers/PATCHER_limiter_behavior.md), RE notes in
[`reviews/limiter/README.md`](reviews/limiter/README.md)): repoints the 0xedc4 call site to a cave that runs the
stock limiter then rewrites the shared cut flags a444/a445 per mode —
stock/hard/soft (soft alternates rotors via a cal-block state cell), gating fuel
AND spark together (fuel via a430, spark via 0x12938 chain — Option A confirmed in
RE). Setpoints in a RomRaider table "Rev Limiter Behavior" (category Protection,
4 float cells: limit override ≤9300 clamp, mode, recovery band, hard margin; N3J1E
data 0x7f780, def added to RX8Defs_Copy). Locates 8/10 stock ROMs (60E32000 pair
SKIP). Static validation only; flash with Rx8Man.

## 12. Limits

FSM pinout cross-check ([mazda-rx-8-pcm-pinout-series-1.md](../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md)): colours resolved for all used terminals except 5L/5Z; wire colours — injectors 2M LG/R, 2J LG/B, 2G G/R, 2D L/B, 3A L/B ³, 3D W/G ³, all with a shared W/L +12V feed; SSV 1L L/Y, 1D L; AIR 1O G; VDI 1W L/B (confirmed); APV 3J L/R, 3G G/B ³, 3B R/G ³, 1S R/W; purge 2P R/Y *; 5Z unread. Applied to the decompiled code annotations. Still no chip-pin data in it, so the pin↔terminal hop stays board-level unresolved.

Static analysis only; no hardware execution. Package-pin → connector-terminal
is board routing (unresolved here, per [`hardware/README.md`](../../architecture/hardware/README.md)). SSV
position-switch input (1D) and purge solenoid (2P) GPIO not identified.
APV motor direction and PH12/13 meaning are candidates. `candidate_` names
are unproven hypotheses. ROM untouched.

---

## 13. Pinout cross-check + binary-level verification

- Wire colours are resolved for
  all used terminals except 5L/5Z — SSV 1L L/Y, VDI 1W L/B, APV 3J L/R (confirmed),
  1S R/W, 3B R/G ³, 3G G/B ³, purge 2P R/Y *, 5Z unread. Applied to
  `hardware/pcm_connections.tsv` (wire_colour), `hardware/firmware_annotations.tsv`
  and all `[WIRING REVIEW]` blocks in the synchronized views. Terminal→function
  unchanged; no chip-pin data, so the pin↔terminal hop stays board-level unresolved.
- Binary-level verification: [`reviews/intake_solenoids/README.md`](reviews/intake_solenoids/README.md) §8 —
  all instruction words, RAM aliases, GPIO reg/mask/helper literals, thunk targets,
  call edges and pinout quotes checked against the ROM (APV command constants
  are inline pool literals of 0x31f32).
- Rev-limiter patcher (§11; RE topology in [`reviews/limiter/README.md`](reviews/limiter/README.md)).
