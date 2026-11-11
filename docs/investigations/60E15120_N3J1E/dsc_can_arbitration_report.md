# DSC-related CAN arbitration report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/dsc_can_labels.json`; detailed evidence in
[`reviews/dsc_can_arbitration/README.md`](reviews/dsc_can_arbitration/README.md).

**Related reports:** CAN mailbox/descriptor layer in
[`can_mailbox_config_report.md`](can_mailbox_config_report.md) (0x212 RX
mailbox descriptor at ROM 0x4e21c/0x4e224); task[10] structure in
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md); DSC
timing derate consumer in the ignition report
([`ignition_timing_report.md`](ignition_timing_report.md) — 0x1815c
`dsc_timing_derate_select` reads 0xffffbbd8); the vehicle-not-moving flag feeds
the idle A/C clutch gate (0x165d6).

## 1. Executive summary

`ref_updateDSCRelatedCANStuff__` 0x2a2ae is a **15-call batch** under mask 0x10,
called from task[10] 0x11744, renamed `dsc_can_arbitration_batch` (inherited name
confirmed). It arbitrates the signals received from the DSC/ABS module over
**CAN ID 0x212**:

- RX path: `can212_rx_main` 0x2b29c copies the 0x212 mailbox (descriptor at ROM
  0x4e21c, buffer 0xffffbbc0, DLC 7) and unpacks it (`can212_rx_unpack` 0x2b7e2:
  payload bytes → 0xffffbbf2-bbf6, u16 status 0xffffbbde, mode byte 0xffffbbf6),
  with failure counters 0xffffbbee/0xffffbbf0 (timeout flag 0xffffbbd0 via
  0x2b7c4 when 0xffffbbf0 > 0x1e).
- The batch then computes: per-signal validity timers (`can212_rx_signal_validity`
  0x2b314, counters 0xffffbbe8/bbea/bbec reload 0x1f), max engine torque allowed
  (`engine_max_torque_allowed_calc` 0x2b3b8 → 0xffffbbd8, clamp [0, 512],
  consumed by 0x1815c `dsc_timing_derate_select`), desired-torque calc 0x2b496,
  the four DSC mode bits of 0xffffbbf6 (0x80/0x40/0x20/0x10 → 0xffffbbcb-ce,
  plus bit 0x08 of 0xffffbbde → 0xffffbbcf), rear wheelspeed average 0x2b046
  (from 0xffffbbac/bbae), vehicle-not-moving flag (`vehicle_moving_calc` 0x2b156
  → 0xffffbbb8, vspeed ≤ 4 km/h hyst 5), and LR/RR wheelspeed validity
  (0x2b17e/0x2b1aa → 0xffffbbb9/bbba).

## 1a. Plain-language summary

The stability-control module (DSC/ABS) sends the PCM one CAN message (ID 0x212)
with wheel speeds, a status word, a mode byte and a torque figure. Every cycle
the PCM checks that message is arriving and its signals are fresh, decodes the
DSC mode bits, works out the maximum engine torque it may allow while DSC is
active, and derives "vehicle moving" and per-wheel speed validity flags that the
rest of the engine control uses (idle A/C gating, timing derate).

## 2. How it works (condensed pseudocode)

```
# CAN 0x212 RX (mailbox descriptor ROM 0x4e21c -> buffer 0xffffbbc0, DLC 7)
can212_rx_main 0x2b29c:
  if can_rx_copy_mailbox_to_buffer(&desc@0x4e21c) == 0:
      0xe038(); can212_rx_unpack 0x2b7e2(); 0x2b816(); 0x2b8f4()
      0xffffbbee = 0; 0xffffbbf0 = 0
  else: bbee++ ; if (bbee & 3) == 0: bbf0++ ; bbc7++

can212_rx_unpack 0x2b7e2:  bbf2=bbc0; bbf3=bbc1; bbf4=bbc2; bbf5=bbc3
                          bbde = bbc4*0x100+bbc5;  bbf6 = bbc6 (mode byte)

# dsc_can_arbitration_batch 0x2a2ae (from task[10] 0x11744), mask 0x10, pool 0x2a3e0-0x2a4f4
can212_rx_signal_validity 0x2b314   # bbf2/3/4 != -1 -> bbe8/bbea/bbec = 0x1f else countdown
engine_max_torque_allowed_calc 0x2b3b8
                                        # bbd8 = clamp(bb20*decode_u8(bbc8)/100 - bcb8 - bcbc, 0, 512)
dsc_desired_torque_calc 0x2b496         # bbe0, filter bbf8 -> bbf7
dsc_mode_bit08_check 0x2b6a4            # bbcf = (bbde & 8) == 8
dsc_mode_bit80_check 0x2b6c2 / dsc_mode_bit40_check 0x2b754 / dsc_mode_bit20_check 0x2b788 /
dsc_mode_bit10_check 0x2b7a6   # bb cb/cc/cd/ce from bbf6 (call pools 0x2a478/0x2a47c/0x2a480/0x2a484 re-read this pass)
can212_timeout_flag 0x2b7c4             # bbd0 = 0x1e < bbf0
wheelspeed_rear_avg_calc 0x2b046        # avg of decode(bbac), decode(bbae)
vehicle_moving_calc 0x2b156             # bbb8 = vspeed <= 4 (hyst 5)
wheelspeed_lr/rr_validity 0x2b17e/0x2b1aa  # bbb9/bbba = raw==-1 || bbbe > 0x1e
```

## 3. Key calibrated data

No lookup tables — fixed affine decodes verified in ROM: wheelspeed u16 decode
step 0x3c23d70a / offset 0xc2c80000 (in 0x2b046), torque u8 decode step
0x3ec99326 (in 0x2b3b8/0x2b496); validity windows 0x1f (signal timers), 0x1e
(timeout/staleness), vspeed 4/5 km/h, torque clamp [0, 512] Nm-ish.

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x2a2ae | `dsc_can_arbitration_batch` | high |
| 0x2b29c | `can212_rx_main` | high |
| 0x2b7e2 | `can212_rx_unpack` | high |
| 0x2b314 | `can212_rx_signal_validity` | high |
| 0x2b3b8 | `engine_max_torque_allowed_calc` | high |
| 0x2b156 | `vehicle_moving_calc` | high |
| 0x2b17e / 0x2b1aa | `wheelspeed_lr_validity` / `wheelspeed_rr_validity` | high |
| 0x2b816 | `candidate_can212_torque_extract` | medium |
| 0x2b496 | `candidate_dsc_desired_torque_calc` | medium |
| 0x2b6a4 | `candidate_dsc_mode_bit08_check` | medium |
| 0x2b6c2 / 0x2b754 / 0x2b788 / 0x2b7a6 | `dsc_mode_bit80_check` / `dsc_mode_bit40_check` / `dsc_mode_bit20_check` / `dsc_mode_bit10_check` | medium |
| 0x2b7c4 | `candidate_can212_timeout_flag` | medium |
| 0x2b046 | `candidate_wheelspeed_rear_avg_calc` | medium |
| 0x2b1d6 | `candidate_can4b0_wheelspeed_extract` | medium |

RAM aliases: `dsc_mode_byte` 0xffffbbf6, `wheelspeed_lr_raw` 0xffffbbac,
`wheelspeed_rr_raw` 0xffffbbae, `engine_max_torque_allowed` 0xffffbbd8,
`vehicle_not_moving` 0xffffbbb8, `wheelspeed_lr_invalid` 0xffffbbb9,
`wheelspeed_rr_invalid` 0xffffbbba, `can212_timeout_counter` 0xffffbbf0,
`can212_status_word` 0xffffbbde, `can212_torque_signal` 0xffffbbc8.

Evidence: `source_review/accepted_function_aliases.tsv` /
`accepted_ram_aliases.tsv`, `data/labels/60E15120_N3J1E/dsc_can_labels.json`.

## 5. Corrections made in this pass

- `ref_updateDSCRelatedCANStuff__` 0x2a2ae confirmed as the DSC/CAN signal
  arbitration batch (not a TX function): its 13 callees all process the 0x212 RX
  signals and derived flags; renamed `dsc_can_arbitration_batch`.
- The 0x212 mailbox descriptor was pinned at ROM 0x4e21c/0x4e224 (ID 0x212, DLC 7,
  buffer 0xffffbbc0) — the RX landing zone for the DSC module message.

## 6. Files

- `utilities/scripts/rx8-pcm-pipeline/review_dsc_can_labels.py` (wired into
  `rebuild.sh`; idempotent)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/dsc_can_labels.json`
- `reverse-engineered/decompiled/60E15120_N3J1E/` (symbols renamed in place)
- `docs/investigations/60E15120_N3J1E/reviews/dsc_can_arbitration/README.md`,
  `reviews/dsc_can_arbitration/validation.json`

## 7. Validation

- Binary-level: 0x2a2ae call count re-counted in the disassembly (15 jsr+bsr+jmp);
  pool 0x2a3e0-0x2a4f4 words read from ROM and resolved to the 13 callees +
  0x3920/0x3934; mailbox descriptor bytes at ROM 0x4e21c read (ID 0x212, ctrl
  byte 0x07 at 0x4e222 = DLC 7, buffer 0xffffbbc0); 0x2b29c call count 8; reader pool-scan for 0xffffbbd8 (0x1827c →
  0x1815c `dsc_timing_derate_select`, 0x18024 → 0x17f20) and 0xffffbbb8
  (0x166ee → 0x165d6).
- `validate_export.py` (ROM SHA-256 + 168,592 instruction bytes + 1,833 exact
  reference matches), `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py`, `validate_reports.py` — all PASS.
- Follow-up claims-verification pass: every machine-checkable claim re-run
  (`verify_claims.py` / `validate_reports.py` PASS) and every binary-level claim
  re-read from the raw ROM and disassembly (see
  [`reviews/dsc_can_arbitration/validation.json`](reviews/dsc_can_arbitration/validation.json)
  `claim_verification`). Two errors found and fixed in all artifacts: the 0x212
  descriptor is DLC 7 (ctrl byte 0x07 at ROM 0x4e222), not 8, and the 0x2a2ae pool
  holds 13 callees (14 `jsr` + 1 tail `jmp` = 15 calls), not 12.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0002a2ae | `dsc_can_arbitration_batch` | 15-call batch from task[10] |
| 0x0002b29c | `can212_rx_main` | 0x212 mailbox copy + unpack chain |
| 0x0002b7e2 | `can212_rx_unpack` | payload → 0xffffbbf2-bbf6/bbde |
| 0x0002b314 | `can212_rx_signal_validity` | validity timers bbe8/bbea/bbec |
| 0x0002b3b8 | `engine_max_torque_allowed_calc` | → 0xffffbbd8 |
| 0x0002b156 | `vehicle_moving_calc` | → 0xffffbbb8 |
| 0x0002b17e / 0x0002b1aa | `wheelspeed_lr_validity` / `wheelspeed_rr_validity` | → 0xffffbbb9/bbba |
| 0x0002b496 / 0x0002b6a4 | `candidate_dsc_desired_torque_calc` / `candidate_dsc_mode_bit08_check` | torque calc / mode bit 0x08 |
| 0x0002b6c2-0x0002b7a6 | `dsc_mode_bit80_check`–`dsc_mode_bit10_check` (0x2b6c2/0x2b754/0x2b788/0x2b7a6) | mode bits → 0xffffbbcb-ce |
| 0x0002b7c4 / 0x0002b046 | `candidate_can212_timeout_flag` / `candidate_wheelspeed_rear_avg_calc` | timeout flag / avg |
| 0x0002b816 / 0x0002b1d6 | `candidate_can212_torque_extract` / `candidate_can4b0_wheelspeed_extract` | payload extracts |
| 0x00011744 / 0x0001815c | `FUN_00011744` / `dsc_timing_derate_select` | batch caller / 0xffffbbd8 consumer |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x2a3e0-0x2a4f4 | 0x2a2ae pool (0x2a448=0x3920, 0x2a454=0x3934, 0x2a468-0x2a498 = 13 callees) |
| 0x4e21c / 0x4e224 | CAN 0x212 RX mailbox descriptor record (ID 0x212, ctrl 0x07 = DLC 7, buffer 0xffffbbc0) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffbbc0-0xffffbbc7 | `DAT_ffffbbc0` … | CAN 0x212 RX payload buffer |
| 0xffffbbf6 | `dsc_mode_byte` | DSC mode byte (bits → 0xffffbbcb-ce) |
| 0xffffbbac / 0xffffbbae | `wheelspeed_lr_raw` / `wheelspeed_rr_raw` | raw wheelspeeds |
| 0xffffbbd8 | `engine_max_torque_allowed` | torque limit [0,512] → 0x1815c |
| 0xffffbbb8 | `vehicle_not_moving` | vspeed ≤ 4 km/h flag |
| 0xffffbbb9 / 0xffffbbba | `wheelspeed_lr_invalid` / `wheelspeed_rr_invalid` | validity flags |
| 0xffffbbf0 | `can212_timeout_counter` | RX failure counter (flag at 0xffffbbd0) |
| 0xffffbbde | `can212_status_word` | u16 status from payload bytes 4-5 |
| 0xffffbbc8 | `can212_torque_signal` | torque byte (affine step 0x3ec99326) |

## 9. Limits

- Static analysis only; no emulator CAN-inject run of the 0x212 path in this pass.
- Which CAN module originates 0x212 (DSC/ABS unit) is inferred from content
  (wheelspeeds/mode/torque), not from a wiring trace.
- The exact physical meaning of each mode bit (0x80/0x40/0x20/0x10/0x08) is
  decoded only as "mode byte bits" — the bit semantics are not pinned.
- The TX side of the DSC arbitration (what the PCM sends back) is covered by the
  CAN mailbox report, not here.

## 10. Related subsystems

CAN mailbox model: [`can_mailbox_config_report.md`](can_mailbox_config_report.md);
task[10] scheduling: [`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md);
DSC timing derate consuming 0xffffbbd8: [`ignition_timing_report.md`](ignition_timing_report.md);
idle A/C clutch gate consuming 0xffffbbb8: idle control report.
