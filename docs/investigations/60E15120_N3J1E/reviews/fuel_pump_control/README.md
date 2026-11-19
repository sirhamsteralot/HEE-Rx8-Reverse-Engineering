# Fuel pump control — review evidence (60E15120_N3J1E)

Evidence for [`docs/subsystem-logic/fuel_pump_control_report.md`](../../../../subsystem-logic/fuel_pump_control_report.md)
and the label record
[`data/labels/60E15120_N3J1E/fuel_pump_control_labels.json`](../../../../../data/labels/60E15120_N3J1E/fuel_pump_control_labels.json).

## What was checked

- Complete enumeration of every SH7055 port data-register write in the ROM
  (direct `P?DR_W` stores + all `ref_setRegister_REG_BIT_VAL` 0x4bbc call
  sites with constant reg/mask + pool-argument call scan over the raw
  disassembly), to prove the fuel pump relay drive is among the mapped bits
  and not a missed site.
- The pump relay drive path: `0x2fc00` (request flag `0xffffbdd8`) →
  `0x2f890` / `0x2f8ce` → PEDR_W bit 0x4 (PE2, pkg pin 9); speed-control
  candidate `0xffffbdbc` → PEDR_W bit 0x2 (PE1, pkg pin 8).
- Raw-bin re-verification of every cited pool/instruction/threshold:
  [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt) — 34/34 PASS
  (ROM SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`).
- Dynamic (SH-2E emulator, harness calls): PE2 follows `0xffffbdd8` (high at
  key-on/cranking/running, low at key-off); PE1 follows `0xffffbdbc`;
  PD7/PE0 follow `0xffffcfb6`/`0xffffcfb7`; PD7 high only while cranking via
  `0xffffd15c` (`0x532d0`); PJ7 follows `0xffffbd68` (A/C clutch) —
  `tests/test_fuel_pump_control_dynamic.py` (6/6).
- Static label tests: `tests/test_fuel_pump_control.py` (8/8).

## Correction

PJ7 (`0x2e800`/`0x2e840`, pkg pin 183) was previously noted as a "fuel-pump
relay candidate" in [`reviews/intake_solenoids/README.md`](../intake_solenoids/README.md).
It is the A/C clutch relay drive: `0xffffbd68` is computed by
`ref_calculateACClutchOn__` `0x2e89c` from `ac_clutch_on` `0xffffbd69` and rpm
(pools `0x2e968`/`0x2e96a`/`0x2e96c`, floats 600.0/7800.0 at ROM
`0x774c0`/`0x774c4`); harness candidate terminal 5AA. The correction has been
folded back into [`reviews/intake_solenoids/README.md`](../intake_solenoids/README.md).

## Open items

- Package-pin ↔ connector-terminal routing (PE2 pin 9 → 5P/5L etc.) is board
  routing, unresolved in this repo; the harness associations are candidates.
- Grace-counter periods (`0xffffbdda` < 0x1f, `0xffffbddc` < 0x3e, reset by
  `0x2fbf8`) are traced to cells/thresholds but not to task periods.
- Cross-ROM byte-matching of this chain not run yet.
- Inertia switch: no PCM input in the pinout; hardware-side in the pump feed.
- The SCI0 input expander and its consumers (oil pressure switch, etc.) are
  not covered here; tracked as a dedicated subsystem report in
  [`ROADMAP.md`](../../../../../../ROADMAP.md).
