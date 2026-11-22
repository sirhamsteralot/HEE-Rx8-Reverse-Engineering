# Throttle / DBW control — review evidence (60E15120_N3J1E)

Evidence for
[`docs/subsystem-logic/throttle_dbw_control_report.md`](../../../../subsystem-logic/throttle_dbw_control_report.md)
and the label record
[`data/labels/60E15120_N3J1E/throttle_dbw_labels.json`](../../../../../data/labels/60E15120_N3J1E/throttle_dbw_labels.json).

## What was checked

- **ADC channel assignment**: the `0x6884` sweep latches `ADDRnH` into RAM at
  `0xffff9ee4 + 2n` (pool `0x6a1c`=0xffff9ee4) and runs in task rec[17] (entry
  `0x60c8`), together with the raw→volts conversions `0x94f0` (pedal) and
  `0xb398` (plate). AN4/AN5 (`0xffff9eec`/`0xffff9eee`) were proven to be the
  **pedal** (APP) channels and AN18/AN19 (`0xffff9f08`/`0xffff9f0a`) the
  **throttle plate** (TP) channels by dynamic discrimination in the SH-2E
  emulator: AN4 raw 50000 driven through task `0x64ba` (which enters the pedal
  conversion body at `0x94fc` and then runs `0x1150e` → `0x199d4`) ends as
  `accelerator_pedal_1_percent` `0xffffa9b4` = 100.0, while AN18 raw 50000
  through `0xb398` → `0x1b08e`/`0x1b14c` → `0x1b940` ends as plate position
  `0xffffad44` = 80.367 / percent `0xffffad48` = 95.676.
- **Motor drive**: the ATU pin-function select `PBCRL_W 0xfffff734` = 0x4000
  (TO7D on PB7, pools `0x52d8`/`0x52da`) is written at `0x51de` inside the init
  function entered at `0x51c8`; boot also starts every ATU channel. What is
  unique to the throttle motor is the compare register: every writer of
  `ATUII_BFR7D_W 0xfffff596` (`0xb270`, `0xb300`, `0xb346`) is inside
  `0xb2c0`/`0xb308`, and `0xb2c0` is called only from `0x25198` with channel
  index 0. No second motor leg or direction GPIO exists in firmware. The DBW
  power relay is the PE0 half of `0x3a0ec` (`PEDR_W 0xfffff754` bit 0x1, package
  pin 7) = (`0xffffcfb7` == 0); the same function drives PD7
  (`PDDR_W 0xfffff746` bit 0x80) = (`0xffffcfb6` == 1). Both exercised
  dynamically (`tests/test_throttle_dbw.py`).
- **Raw-bin re-verification** of every cited pool word, dispatch record, task
  record, float constant and byte limit:
  [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt) — 154/154 PASS
  (ROM SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`);
  the checker is `input/throttle_dbw_rawbin_reverify.py` (uncommitted scratch,
  as for the other subsystem reviews).
- **Logger PID 0x1410 settlement**: dispatch record `0x5f394` (bytes
  `14100200 fffc0000 00056f6c`, record 54 of the 86-record table at `0x5f10c`,
  stride 12) → handler `0x56f6c` reads float `0xffffbe24`
  (injector pulse time, `0x2fea8`) with step 8.0f (pool `0x57048`) via encoder
  `0x2490`. Dynamic: 80.0 → u16 10, 16.0 → u16 2. The upstream logger def's
  "Throttle Pedal Position" alias at 0x221410 does not match this ROM — upstream
  lists two parameters at that one address (PIDTEST4 "Injector Pulse Time",
  conversion x*8 µs, which matches the ROM's step 8.0f, and PIDTEST5 "Throttle
  Pedal Position", x*0.392 %); PIDTEST5 is the wrong duplicate. The
  reviewed def keeps only "Injector Pulse Time"
  (`data/definitions/romraider/reviewed-rx8defs-copy/logger_60E15120_reviewed.xml`),
  and the design doc §5.8 note is settled. Plate = PIDs 0x0011/0x093c, pedal =
  PIDs 0x0049/0x004a (also 0x0914/0x0915), target plate = 0x004c/0x091a, raw
  plate = 0x1154 — every quoted PID/handler pair re-checked in the dispatch
  table.
- **Dynamic emulator tests** (harness calls of the ROM's own functions):
  `tests/test_throttle_dbw.py` — 19 passed (static TSV/index/symbols/ROM-byte
  checks + the dynamic runs above + limp `cc98`=1/`cc99`=1 → `0xffffad44` =
  20.0 + PE0/PD7 relay drive + `0xffffb410` float type).
- Fold-back of the new names into the decompiled export was done by the
  targeted apply script
  (`utilities/scripts/rx8-pcm-pipeline/review_throttle_dbw_labels_apply.py`,
  idempotent, wired into `rebuild.sh`); the stale `FUN_…` memory-map rows that
  the rename invalidated in `dtc_authoring_report.md`, `dtc_control_report.md`
  and `e2ram_nv_storage_report.md` were updated to the new index names in the
  same change.

## Corrections folded back in the same change

- `0xffffa9b4`/`0xffffa9b8`: `throttle_position_{1,2}_percent` →
  `accelerator_pedal_{1,2}_percent` (they are the pedal APP percent, not the
  plate). Updated in the TSVs, `cruise_control_labels.json`,
  `uds_dispatch_labels.json`, `cruise_control_report.md`,
  `reviews/cruise_control/README.md` and the ADC channel line in
  [`docs/learnings.md`](../../../../learnings.md).
- `0xffffad5e`: `inferred_pedal_volts_ffffad5e` →
  `inferred_throttle_sensor_2_volts_ffffad5e` (it latches AN19 = plate TP2).
- Pedal conversion wiring: `0x94f0`/`0xb398` belong to task rec[17] (entry
  `0x60c8`), not to the `0x199d4` sensor batch; task rec[9] enters the pedal
  body at `0x94fc`. The pedal percent/demand batch consumes `0xffffa108`/
  `0xffffa10c`/`0xffffa218`/`0xffffa21c`.
- `0xffffb410` is a **float** in `0xffffb424`'s units; `0x5ccb4` is the PID
  0x091a export with a 1/512 requantization round-trip, not a percent→counts
  conversion.
- Gear-flag map select is a priority chain (`0xffffb2cc` → `0x6a458`,
  `0xffffb2cd` → `0x6a474`, `0xffffb2ce` → `0x6a490`, otherwise `0x6a4ac`), and
  `0x24b44` stores `0xffffb534` = 1 when ROM `0x74924` is 0x00 (this bin), so
  the range/state branch of `0x2c15a` is the one taken on the reference ROM.
- `PBCRL_W` = 0x4000 is written by the init function at `0x51c8` (`0x51de`), not
  by `0xb308`; `0xb23c` leaves channel 7D running at 0 % duty on a 1-count
  period.
- The relay driver `0x3a0ec` drives two outputs (PD7 from `0xffffcfb6`, PE0 from
  `0xffffcfb7`), and both polarity senses are recorded in the report §2.9.

## Open items

- Alias names that do not match the traced operands are unchanged (cross-pass
  churn): `tp_correlation_fault_check` and the `tp_correlation_*`/
  `tp_plausibility_*` cells monitor the two pedal channels and permit shutdown;
  `learned_pedal_value_calc`/`candidate_learned_pedal_value` carry plate- and
  servo-side operands.
- Roughly 60 cells cited in report §2 have no accepted RAM alias yet; they are
  listed by address at the end of report §4.1.
- Throttle-motor phase pins (terminals 1B/1C): not firmware-identified (see
  above); the H-bridge drive side is board routing. Package-pin ↔
  connector-terminal routing in general is unresolved in this repo.
- The duty-loop feedback `0xffffaa78` is the labeled AN11/AN23 differential
  pair ratio: `0xaee8` `adc_pair_correlation_fault_compute` computes
  |ΔAN23|·7.6294e-5 / |Δ(AN23−AN11)/200| − 16.25 → `0xffffa1d8`
  (`adc_pair_ratio_raw`), filtered → `0xffffa1d4` (`adc_pair_ratio_filtered`),
  copied to `0xffffaa78` by `0x1ac00`, which also uses it for the lambda band
  flag `0xffffaa80`. Firmware-level identity is thus settled (a filtered pair,
  as suspected); only the pin-level identity of AN11/AN23 (which physical
  sensors) is unresolved — board routing.
- `0xffffb4b0`/`0xffffb4b4` are written only at boot by the E2RAM decode
  `0x23844`, not per cycle.
- Cross-ROM byte-matching of this chain not run yet (shared-logic assumption
  stands).
