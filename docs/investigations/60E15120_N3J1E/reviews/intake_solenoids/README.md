# Targeted static review: intake solenoid actuation (SSV / VDI / VFAD / APV, secondary air)

Scope: the intake-manifold actuators of 60E15120_N3J1E (RX-8 PCM, SH7055F),
traced from control logic to GPIO register/bit to SH7055F package pin to
harness terminal, read from the canonical export (`decompiled/`), the raw ROM
(SHA-256 `a7cd953c…f264f1`, untouched), the supplied **SH7055F hardware manual
(`Sh7055h.pdf`, ADE 602-155B, Tables 1.2/1.3 pin assignments)** and
`hardware/pcm_connections.tsv`. Port register names from
`reference_project/RX8_6.rep/script_stuff/regs_7055_350.csv`.

Result: every intake actuator output is identified at GPIO-bit level, and the
GPIO→package-pin hop is now closed with the hardware manual. The last hop,
package pin → PCM connector terminal, is board routing and remains unresolved
in this workspace (as `hardware/README.md` already declares) — the terminal
column below comes from the wiring diagram and is **not** claimed to be
electrically traced to the chip pin.

## 1. Actuator → GPIO → package pin → terminal map

| Actuator | Control function | GPIO reg / bit | Port pin | SH7055F pkg pin | Harness terminal |
|---|---|---|---|---|---|
| SSV solenoid | 0x2178c `ssv_solenoid_control` | PEDR_W 0xfffff754, 0x80 | PE7 | **16** | 1L (B1-21) |
| VFAD solenoid | 0x3493c `vfad_solenoid_control` | PEDR_W, 0x400 | PE10 | **19** | 5Z (B1-15, high-power) |
| VDI solenoid | 0x34844 `vdi_solenoid_control` | PDDR_W 0xfffff746, 0x20 | PD5 | **254** (PD5/TIO1F alt) | 1W (B1-25) |
| Secondary air injection solenoid | 0x187b8 `secondary_air_solenoid_control` | PEDR_W, 0x100 | PE8 | **17** | 1O (B1-23) |
| Secondary air pump (relay/drive) | 0x316f8 `secondary_air_pump_control` | PBDR_W 0xfffff738, 0x4 | PB2 | **147** | (pump supply circuit) |
| APV motor forward | 0xa936 `apv_pwm_service` | PLDR_W 0xfffff75e, 0x0020 | PL5 | **221** | 3J/3G (B1-37 B/D) |
| APV motor reverse | 0xa936 | PLDR_W, 0x0100 | PL8 | **224** | 3J/3G (opposite polarity) |
| APV drive status inputs | 0xaac4 `apv_drive_status_sample` | PHDR_W 0xfffff72c, 0x1000/0x2000 | PH12/PH13 | **79 / 80** | (H-bridge status; candidate) |
| APV position feedback | 0x43a86 `apv_position_voltage_scale` | ADC6 reg 0xfffff80c → RAM 9ef0 | AN6 | **92** | 3B (B1-37 A; ref 1S, return 1U) |
| SSV position switch (input) | not identified this pass | — | — | — | 1D (B1-42) |

Package pins from `Sh7055h.pdf` Table 1.3: 7=PE0, 8=PE1, 9=PE2, 12=PE4,
14=PE5, 15=PE6, 16=PE7, 17=PE8, 19=PE10, 21=PE11, 79=PH12, 80=PH13,
147=PB2, 183=PJ7, 221=PL5, 224=PL8, 254=PD5, 92=AN6.
Related outputs seen in the same pass: cooling fan PE11 (pin 21) / PE4
(pin 12) via 0x2f1dc/0x2f188, immo light PE6/PE5 (pins 15/14) via 0x2556c,
PJ7 (pin 183) via 0x2e800 (fuel-pump relay candidate), PE0/PD7 via 0x3a0ec.

## 2. Control logic (per actuator)

All four solenoid controls run in the task 0x64f6 → 0x11744 chain
(periodic wrappers 0x21766 / 0x348ea / 0x34916 with interrupt mask 0x10);
each has a UDS diagnostic actuator override (0x5c9ac / 0x5c3c0 / 0x5cdc4 /
0x5cf7c, state machine on the diagnostic area 0xffffd3xx):

- **SSV** (0x2178c): ON if diag override says so (becd), or
  `(engine-state aa68 == 0 && previous b2b5) && coolant < 197 C (hyst 200,
  b2b4) && counter b2b2 != 0` (b2b2 loaded 0xbc on the aa68==0 && b2b5 edge,
  else decremented). Result through 0x5c9ac → b2b0 → PE7.
- **VDI** (0x34844): ON = RPM ≥ 7250 (clear below 7062) → c1c0 → diag
  override 0x5c3c0 → PD5.
- **VFAD** (0x3493c): ON = RPM ≥ 5250 (clear below 5062) → c1c4 → 0x5cdc4 →
  PE10.
- **Secondary air solenoid** (0x187b8, task 0x6584 → 0x117ac): request =
  `(bf6c && load ≤ 0.8 (hyst 0.75) && RPM ≤ 4000 (hyst 3900)) || d26e`,
  then diag override 0x5cf7c → a960 → PE8. Pump output PB2 = bf6c
  (0x316f8 via 0x3174a). I.e. secondary air at low load / low RPM
  (catalyst warmup) — plus enrichment fuel from 0x31624
  `ref_calculateSecondaryAirPumpEnirchment` in the fueling chain.
- **APV** (0x31c20, task 0x64f6 → 0x11744): closed-loop position control —
  target/condition 0x31c6c (RPM ≥ 150/200 flag bf99, counter bf92 > 0x32,
  aa68; MAF a9ec / coolant a98c snapshots) → dwell counter bf88
  (0x31ece) → drive counter bf8a (0x31f0a) → staged command bf84
  (0x31f32: 0, or staged 100.0 / 12.5 float literals from 0x31f32's own pool, selected by bf88 against u16 band thresholds at ROM 0x78bb2-0x78bc0,
  RPM hyst 2800/3000) → signed percent 0x31bec (negate if bf8b, /100) →
  0xaa90 `apv_duty_split` (× period 96 at ROM 0x78bb6 → forward a1c4 /
  reverse a1c6 ticks) → 0xa936 `apv_pwm_service` software PWM on PL5/PL8
  with status sampled from PH12/PH13 (0xaac4 → a1bc). Position feedback:
  ADC6 raw 9ef0 → volts cab0 (0x43a86, ×5/65536) → range logic 0x43a9e.
  See also `reconstructed/rx8_apv.c` (host-tested reconstruction).

## 3. Labeling applied

- 26 functions + 26 RAM locations added to `source_review/accepted_*_aliases.tsv`
  via `scripts/review_intake_labels.py` (idempotent, wired into
  `scripts/rebuild.sh` after `review_fueling_labels.py`); integrated into all
  synchronized views; record in `metadata/intake_labels.json`; backup
  `backups/pre_intake_labels.zip`.
- Medium-confidence names carry the `candidate_` prefix in the views.

## 4. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256 verified, 3,355 function
  files, 168,592 instructions byte-verified, 1,833 reference matches.
- `scripts/verify_readability.py` / `verify_math_units.py` — pass.
- GPIO bit claims cross-checked against the disassembly (e.g. 0x2178c writes
  0xfffff754/0x80, 0x34844 writes 0xfffff746/0x20, 0x3493c writes
  0xfffff754/0x400, 0x187b8 writes 0xfffff754/0x100, 0x316f8 writes
  0xfffff738/0x4, 0xa936 writes 0xfffff75e/0x20+0x100, 0xaac4 reads
  0xfffff72c/0x1000+0x2000).
- Package pins from the supplied manual's Table 1.3 (quoted in §1).

## 5. FSM pinout cross-check

Terminal functions cross-checked against the FSM pinout ([`mazda-rx-8-pcm-pinout-series-1.md`](../../../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md)) (colours resolved for all used terminals except 5L/5Z; screenshots; unmarked = confirmed, * provisional, † conflict, ³ HP-only). Colours: 1D SSV switch L, 1L SSV L/Y, 1O AIR G, 1W VDI L/B, 3J APV (-) L/R (all confirmed); 1S APV power R/W, 3B APV angle R/G ³, 3G APV (+) G/B ³; 2P purge R/Y *; 5Z VFAD unread. Applied to the decompiled views via hardware/firmware_annotations.tsv + pcm_connections.tsv (wire_colour column). The pinout has no chip-pin numbers, so package-pin → terminal remains board routing. `hardware/pcm_connections.tsv` rows carry the FSM names.

## 6. Limits

- Package-pin → connector-terminal is board routing: NOT verified here; the
  terminal column is wiring-diagram data (`hardware/pcm_connections.tsv`),
  and the "candidate firmware GPIO" associations in
  `hardware/firmware_annotations.tsv` remain inferred at that hop.
- SSV position-switch input (1D) and purge-solenoid (2P) GPIO were not
  identified in this pass (open).
- APV motor direction (which of PL5/PL8 is "open") and the PH12/13 status
  meaning are candidates; mechanical direction unverified.
- Static analysis only; no hardware execution. `candidate_` names are
  hypotheses. ROM untouched.

## 7. Sources

Canonical export + disassembly + raw ROM; `Sh7055h.pdf` (supplied SH7055F
hardware manual, pin tables); `regs_7055_350.csv` register map;
`hardware/pcm_connections.tsv` + `hardware/firmware_annotations.tsv` (wiring);
`reconstructed/rx8_apv.c`; design doc `design/README.md` §5.9.

## 8. Binary-level verification (sceptical re-check vs raw ROM)

Every label in this pass was re-checked against `60E15120_N3J1E.bin` and the
disassembly, not the decompiled C:

- All 168,592 instruction words re-read from ROM — 0 mismatches.
- All 26 intake RAM aliases: reader literal pools contain the address (direct
  or base+offset) — 0 failures. All 26 function aliases match
  `function_index.tsv` (medium → `candidate_`) — 0 failures.
- GPIO claims: each control function's pool/disasm contains the DR register
  (low16 0xf754/0xf746/0xf738/0xf75e/0xf72c + 0xffff high half), the mask
  (0x80 / 0x400 / 0x100 as pool literals, 0x20 / 0x4 as `mov #imm`, PL8's 0x100
  at pool 0xa9d0), and the helper 0x4bbc — all confirmed.
- Thunks 0x21760/0x348e4/0x34910: `mov.l @(disp,pc),r3; jmp @r3` with pool
  targets 0x2178c/0x34844/0x3493c confirmed from ROM.
- Call edges used (0x64f6→0x11744→wrappers/APV, 0x6584→0x117ac→sec-air/evap,
  0x3174a→0x316f8): callee addresses present in caller pools; task[10] entry
  0x64f6 re-read from ROM 0x4a38.
- Package pins re-quoted from `Sh7055h.pdf` Table 1.3: 16=PE7, 17=PE8, 19=PE10,
  79=PH12, 80=PH13, 92=AN6, 147=PB2, 221=PL5, 224=PL8, 254=PD5 — all match.
- Constants: 200.0 in 0x2178c's pool (197.0 in shared pool 0x77fd0/0x77ff0);
  7250.0 in 0x34844's pool; APV period u16 at ROM 0x78bb6 = 96 confirmed
  (referenced by 0xaa90's pool); 0xbc in shared pools.
- **Correction found by this pass:** the APV command levels 100.0
  (0x42c80000) / 12.5 (0x41480000) are inline float literals in 0x31f32's own
  pool, not at ROM 0x78bb8/0x78bbe — those hold the u16 counter band
  thresholds (0x32/0x59/…). Evidence text fixed in the TSVs, script, record
  and all docs. Also noted: hysteresis lower bounds (7062/5062/3900/2800) are
  decompiler-folded forms of threshold-minus-offset (e.g. 7250−188=7062; the
  binary holds 7250.0 and 188.0), so those exact literals do not exist in ROM.
- No ROM/def/wiring bytes changed; docs and evidence strings only.

## 9. RPM-window patcher (VDI/SSV)

`Mazda_RX8_PCM_ReverseEngineering/Utilities/patch_intake_rpm_window.py`
(+ `PATCHER_intake_rpm_window.md`) patches a stock ROM so the VDI or SSV
solenoid is open only inside an RPM window (default VDI 7000–8500 rpm):
`--actuator vdi|ssv --open-rpm 7000 --close-rpm 8500`. It locates the control
function by exact body byte-match (unique in all 10 stock ROMs), rewrites only
the function's logic region + its own literal pool (VDI: rel 0x08–0x2e of the
function at 0x34844 in N3J1E; SSV: rel 0x10–0xa2 of 0x2178c), keeps the
diag-override + GPIO-write tails, relocates ROM pool pointers by the found
delta, and writes a NEW output file — stock inputs are read-only and their
SHA-256 is asserted unchanged. Verified: patched region decode-checked
word-by-word, diff confined to the patched span, all 10 ROMs locate uniquely.
Static validation only — not tested on hardware; flash via `Rx8Man/`.
