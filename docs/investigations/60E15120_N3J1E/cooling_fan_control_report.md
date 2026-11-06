# Cooling fan control report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/fan_control_labels.json`; detailed
evidence in [`reviews/cooling_fan_control/README.md`](reviews/cooling_fan_control/README.md).

**Related reports:** actuator GPIO pattern and package pins in
[`intake_solenoids_report.md`](intake_solenoids_report.md) (same PEDR_W
convention); task structure in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md) (fan task
runs in the 0x117ac chain); wiring terminals 5X/5AD in
[`../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md`](../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md).

## 1. Executive summary

The cooling fan has **two relay outputs**, driven as a two-speed control:

- **Fan 1 (low speed)**: `fan_low_speed_cmd` 0xffffbda1, computed by
  `fan_low_speed_decision` 0x2f51a — coolant ≥ 97 °C (hysteresis 94 °C), or
  engine-off/A/C-related conditions, with DTC gates.
- **Fan 2 (high speed)**: `fan_high_speed_cmd` 0xffffbda2, computed by
  `fan_high_speed_decision` 0x2f65c — only when fan 1 has been on for more than
  0x5c counts (0xffffbda8) **and** an additional condition holds (coolant
  ≥ 101 °C, A/C on at hot coolant, high load at low speed, etc.).

Both commands are written to GPIO in `fan_output_gpio` 0x2f1dc:
`PEDR_W` 0xfffff754 **bit 0x800 = PE11 (package pin 21)** from fan 1 and
**bit 0x10 = PE4 (package pin 12)** from fan 2, each through the UDS
actuator-test override (0x5c724 DID 0x17c3 / 0x5c648 DID 0x17c4) and the
`ref_setRegister_REG_BIT_VAL` 0x4bbc helper under interrupt mask 0xe0. The
inherited `ref_setFanOutputGPIO` name is confirmed. The init-time writer
`ref_initFanControl_0002f188` (via thunk 0x2f260 from the boot fan-out 0x1102a)
writes the same two bits directly from the command cells without diag
arbitration — renamed `fan_output_gpio_init`. The fan task wrapper 0x2f266 is
called from 0x117ac.

Harness side (pinout v3): cooling fan relay on terminals **5X** (R/G) and **5AD**
(L/W). The package-pin ↔ connector-terminal hop is board routing and remains
unresolved, as everywhere else in this workspace.

## 1a. Plain-language summary

When the coolant gets hot (about 97 °C), the PCM turns on the first fan relay;
a second relay kicks in only if the engine stays hot under load, with the A/C on,
or at very high temperature (about 101 °C) after the first fan has run for a
while. Both relays are plain digital outputs on port E (PE11 and PE4), and both
can be forced on from the diagnostic actuator tests.

## 2. How it works (condensed pseudocode)

```
# fan_control_task 0x2f266 (called from 0x117ac, pool 0x11a04), mask 0x10
fan_low_speed_decision()     # 0x2f51a -> 0xffffbda1
fan_high_speed_decision()    # 0x2f65c -> 0xffffbda2 (+ counter 0xffffbda8)
fan_output_gpio()            # 0x2f1dc -> PEDR_W 0xfffff754 bits 0x800/0x10

# 0x2f51a: bdaa/bdab = coolant >= 97 / < 94 C hysteresis
bda1 = (bdaa || (bdab && b0cd)) || (aa68==0 && bda0 && !ccc6 && !a8ea && !bf8d)
       || bd68 || bd6a, gated by !d040 && !d0a8 && !(d264&&d269...) && !d263

# 0x2f65c: bdac = coolant >= 101 / < 98; bdb2 = c6ac >= 1.94 / < 1.84;
#          bdb3 = coolant >= 80 / < 77; bdb4 = vspeed >= 10 / < 8
bda8 = bda1 ? saturate_add(bda8,1) : 0
bda2 = (bda1 && bda8 > 0x5c && (bdac || (bd68 && bdb8) || (aa68==0 && bda0 &&
       !ccc6 && !a8ea && !bf8d) || bd6a || (bdb2==0 && bdb3 && !bdb4)))
       || c5e6 || (d264 && !d269), gated by !d263

# 0x2f1dc: PEDR_W 0xfffff754 bit 0x800 (PE11) = 0x5c724(bda1)   # DID 0x17c3
#          PEDR_W bit 0x10 (PE4)            = 0x5c648(bda2)   # DID 0x17c4
# 0x2f188 (init, via thunk 0x2f260 from 0x1102a): same bits from bda1/bda2 directly
```

## 3. Key calibrated data

No lookup tables in this subsystem — all thresholds are inline constants:
coolant 94/97 °C (fan 1), 98/101 °C and 77/80 °C (fan 2), load 1.84/1.94 on
0xffffc6ac, vehicle speed 8/10 km/h, high-speed delay counter threshold 0x5c
(92 counts) on 0xffffbda8.

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x2f266 | `fan_control_task` | high |
| 0x2f51a | `fan_low_speed_decision` | high |
| 0x2f65c | `fan_high_speed_decision` | high |
| 0x2f1dc | `fan_output_gpio` | high |
| 0x2f188 | `fan_output_gpio_init` | high |
| 0x2f260 | `candidate_fan_init_thunk` | medium |
| 0x5c724 | `candidate_fan1_diag_override` | medium |
| 0x5c648 | `candidate_fan2_diag_override` | medium |

RAM aliases: `fan_low_speed_cmd` 0xffffbda1, `fan_high_speed_cmd` 0xffffbda2,
`fan_low_speed_timer` 0xffffbda8.

Evidence: `source_review/accepted_function_aliases.tsv` /
`accepted_ram_aliases.tsv`, `data/labels/60E15120_N3J1E/fan_control_labels.json`.

## 5. Corrections made in this pass

- `ref_initFanControl` exists at two addresses: 0x2f188 (the real init-time
  output writer, renamed `fan_output_gpio_init`) and 0x2f260 (a 4-byte thunk to
  it). The ROADMAP-listed 0x2f188 hypothesis is confirmed; the output writer
  proper is `ref_setFanOutputGPIO` 0x2f1dc → `fan_output_gpio`.
- Fan outputs are **PEDR_W bits, not a dedicated peripheral**: PE11 (pin 21) =
  fan 1, PE4 (pin 12) = fan 2 — matching the pinout's two cooling-fan relay
  terminals 5X/5AD.

## 6. Files

- `utilities/scripts/rx8-pcm-pipeline/review_fan_control_labels.py` (wired into
  `rebuild.sh` after the other review scripts; idempotent)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/fan_control_labels.json`
- `reverse-engineered/decompiled/60E15120_N3J1E/` (symbols renamed in place)
- `docs/investigations/60E15120_N3J1E/reviews/cooling_fan_control/README.md`,
  `reviews/cooling_fan_control/validation.json`

## 7. Validation

- Binary-level: pool words of 0x2f1dc (0x2f240=0xe0 mask, 0x2f242=0xf754 PEDR_W
  low16, 0x2f244=0xbda1, 0x2f246=0x800 PE11 mask, 0x2f248=0xbda2, 0x2f24c=0x2054,
  0x2f250=0x4bbc, 0x2f254=0x2064, 0x2f258=0x5c724, 0x2f25c=0x5c648; the PE4 mask 0x10
  is mov #0x10 at 0x2f222, not a pool word) and 0x2f266 (0x2f29c=0x2f51a,
  0x2f2a0=0x2f65c, 0x2f2a4=0x2f1dc) read from ROM inside classified pools
  0x2f240-0x2f25f / 0x2f290-0x2f2ab; `PEDR_W` 0xfffff754 from symbols.tsv; PE4/PE11
  package pins 12/21 from Sh7055h.pdf Table 1.3 (as used by the intake pass);
  caller edges 0x117ac → 0x2f266 (pool 0x11a04) and 0x1102a → 0x2f260.
- `validate_export.py` (ROM SHA-256 + 168,592 instruction bytes + 1,833 exact
  reference matches), `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py`, `validate_reports.py` — all PASS;
  `data/labels/60E15120_N3J1E/{validation,claim_validation,report_validation}.json`.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0002f266 | `fan_control_task` | fan task wrapper (from 0x117ac) |
| 0x0002f51a | `fan_low_speed_decision` | fan 1 command → 0xffffbda1 |
| 0x0002f65c | `fan_high_speed_decision` | fan 2 command → 0xffffbda2 |
| 0x0002f1dc | `fan_output_gpio` | PEDR_W bits 0x800/0x10 via diag overrides |
| 0x0002f188 | `fan_output_gpio_init` | init-time output writer |
| 0x0002f260 | `candidate_fan_init_thunk` | thunk → 0x2f188 (from 0x1102a) |
| 0x0005c724 / 0x0005c648 | `candidate_fan1_diag_override` / `candidate_fan2_diag_override` | UDS DID 0x17c3 / 0x17c4 |
| 0x000117ac / 0x0001102a | `FUN_000117ac` / `FUN_0001102a` | fan task caller / init fan-out |
| 0x00004bbc / 0x00002054 / 0x00002064 | `ref_setRegister_REG_BIT_VAL` / `ref_setSR_PARAM` / `FUN_00002064` | GPIO helper / mask helpers |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x2f240-0x2f25f | shared pool of 0x2f188/0x2f1dc (PEDR_W, masks 0x800/0x10, cells, helpers) |
| 0x2f290-0x2f2ab | 0x2f266 pool (0x2f29c=0x2f51a, 0x2f2a0=0x2f65c, 0x2f2a4=0x2f1dc) |
| 0x11a04 | pool word in 0x117ac = 0x2f266 |
| `PEDR_W` 0xfffff754 | port E data register (symbols.tsv); PE11 = pkg pin 21, PE4 = pkg pin 12 |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffbda1 | `fan_low_speed_cmd` | fan 1 relay command → PE11 |
| 0xffffbda2 | `fan_high_speed_cmd` | fan 2 relay command → PE4 |
| 0xffffbda8 | `fan_low_speed_timer` | fan-1-on counter, high-speed gate > 0x5c |
| 0xffffbdaa / 0xffffbdab / 0xffffbdac | `DAT_ffffbdaa` … | coolant hysteresis flags (94/97, 98/101 °C) |

## 9. Limits

- Static analysis only; no emulator run of the fan task in this pass.
- The meaning of the individual gate flags (0xffffbda0, 0xffffbd68/0xffffbd6a,
  0xffffccc6, 0xffffa8ea, 0xffffc5e6, 0xffffd263/0xffffd264/0xffffd269,
  0xffffd040/0xffffd0a8) is not traced to producers here.
- Package-pin ↔ connector-terminal (PE11/PE4 ↔ 5X/5AD) is board routing,
  unresolved (D2).
- `candidate_` labels are hypotheses.

## 10. Related subsystems

Actuator/GPIO conventions and pin table in
[`intake_solenoids_report.md`](intake_solenoids_report.md); UDS actuator-test
arbitration pattern in [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md);
task scheduling in [`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md);
A/C switch input (0xffffbdb8) feeds the fan-2 condition — see
[`alternator_control_report.md`](alternator_control_report.md) for that flag's
producer.
