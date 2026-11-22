# Fuel pump control — review evidence (60E15120_N3J1E)

Evidence for [`docs/subsystem-logic/fuel_pump_control_report.md`](../../../../subsystem-logic/fuel_pump_control_report.md)
and the label record
[`data/labels/60E15120_N3J1E/fuel_pump_control_labels.json`](../../../../../data/labels/60E15120_N3J1E/fuel_pump_control_labels.json).

## What was checked

- Complete enumeration of every SH7055 port data-register write in the ROM
  (direct `P?DR_W` stores + all `ref_setRegister_REG_BIT_VAL` 0x4bbc call sites
  with constant reg/mask + pool-argument call scan over the raw disassembly), to
  prove the fuel pump relay drive is among the mapped bits and not a missed
  site.
- The pump relay drive path: request flag `0xffffbdd8` (`0x2fc00`, primed by
  `0x2f948` from the start-up sequence `FUN_0001102a`) → `0x2f890` / `0x2f8ce` →
  PEDR_W bit 0x4 (PE2, pkg pin 9); speed-control candidate `0xffffbdbc`
  (`0x2fb20`) → PEDR_W bit 0x2 (PE1, pkg pin 8).
- The demand chain feeding the speed request: `0x2f9d0` (filtered fuel-volume
  demand `0xffffbdc0`), `0x2f9fc` (2D-166 keyed on barometric pressure →
  `0xffffbdd0`, 2D-167/168 keyed on battery voltage → `0xffffbdc4`, selected
  against the 200/190 × margins), `0x2fb20` (3.5 hysteresis on `0xffffbdd5`, the
  `0xffffbdd4` hold counter and the inert `ROM[0x775bd]` third term).
- The second-stage grace evaluation `0x2fcac` behind the SR-masked wrapper
  `0x2f98c`, reached from `0x11b80`; `0x2fbf8` disabling the run-on term.
- Caller inventory by whole-ROM literal-pool scan: `0x2f948` ← `FUN_0001102a`
  (pool `0x11308`), whose own single reference is the init pool `0x628c`;
  `0x2f95c` ← the fueling-task worker `0x117ac` (pool `0x11a08`); `0x2f98c` ←
  `0x11b80` (pool `0x11d20`).
- Raw-bin re-verification of every cited pool word, instruction word, ROM
  threshold and peripheral symbol:
  [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt) — 134/134 PASS, produced
  by
  [`utilities/scripts/rx8-pcm-pipeline/verify_fuel_pump_chain.py`](../../../../../utilities/scripts/rx8-pcm-pipeline/verify_fuel_pump_chain.py)
  (ROM SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`).
- Static label tests: `tests/test_fuel_pump_control.py` (11 tests) — function
  index membership, pool/instruction words, ROM thresholds, the
  `intake-air`/`baro`/`battery` axis split, the hold-counter branch, the
  u16-vs-u8 widths, TSV mirroring, and a regeneration test that re-runs the
  verifier and compares the committed log.
- Dynamic (SH-2E emulator, harness calls): `0x2f890` sets/clears PE2 from
  `0xffffbdd8`, `0x2f8ce` sets PE2 through the gate and PE1 from
  `0xffffbdbc`, `0x2fc00` produces `0xffffbdd8` from the key-on/counter terms —
  `tests/test_fuel_pump_control_dynamic.py` (3 tests). The neighbouring
  PD7/PE0/PJ7 drives exercised in the same runs are out of scope for the report
  and covered by [`tests/test_starting_cranking.py`](../../../../../tests/test_starting_cranking.py),
  [`tests/test_throttle_dbw.py`](../../../../../tests/test_throttle_dbw.py) and
  [`tests/test_ac_compressor_clutch.py`](../../../../../tests/test_ac_compressor_clutch.py)
  (see the report §4.6).

## Correction folded into other documents

PJ7 (`0x2e800`/`0x2e840`, pkg pin 183) was noted as a "fuel-pump relay
candidate" in
[`reviews/intake_solenoids/README.md`](../intake_solenoids/README.md). It is the
A/C clutch relay drive: `0xffffbd68` is computed by `ref_calculateACClutchOn__`
`0x2e89c` from `ac_clutch_on` `0xffffbd69` and rpm thresholds (pools
`0x2e968`/`0x2e96a`/`0x2e96c`, floats 600.0/7800.0 at ROM `0x774c0`/`0x774c4`,
hysteresis −200 and −500 constants); harness candidate terminal 5AA. The
correction is folded back into
[`reviews/intake_solenoids/README.md`](../intake_solenoids/README.md).

## Limits

- Package-pin ↔ connector-terminal routing (PE2 pin 9 → 5P/5L etc.) is board
  routing, unresolved in this repo; the harness associations are candidates.
- Grace-counter periods are traced to cells and ROM thresholds but not to task
  periods, so the counters are stated in calls, not milliseconds.
- The `0x2fb20` third term is inert in this bin (ROM byte `0x775bd` = 0x01) and
  the `0x2f9fc` tail block is unreachable (ROM byte `0x775bc` = 0x00); neither
  alternative path is exercised anywhere.
- `0xffffbdbc` has two further readers (`0x2aa46`, `0x49308`) that are not part
  of this chain and are not analyzed.
- Cross-ROM byte-matching of this chain has not been run; the shared-logic
  assumption stands until proven otherwise.
- The inertia switch has no PCM input in the pinout; it sits hardware-side in
  the pump feed.
- The SCI0 input expander consumers are a separate subsystem; the entries traced
  here while following the port banks are listed in the report §4.6.
