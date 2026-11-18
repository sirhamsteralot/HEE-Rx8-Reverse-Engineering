# Fuel pump control — review notes

Method, in order:

1. Enumerated all GPIO output sites: direct `P?DR_W` stores in the decompiled
   export (121 accesses), all `ref_setRegister_REG_BIT_VAL` (0x4bbc) call sites
   with constant reg/mask in the per-function files, and a raw-disassembly scan
   of every `jsr`/`bsr` whose r4-r7 hold a `0xfffff7xx` (or low-half `0xf7xx`)
   pool value. Result: the only dynamically driven, previously unlabeled
   output bits are PD7/PE0 (`0x3a0ec`), PE1/PE2 (`0x2f8ce`/`0x2f890`) and the
   PD4 PWM (catalyst-temp tables — purge-class, not a relay).
2. SH7055F pkg pins from `docs/references/Sh7055h.pdf` Table 1.3: PE0=7,
   PE1=8, PE2=9, PJ7=183, PD7=256, PD5=254, PB2=147.
3. Harness terminals still needing drivers (pinout v3): 4C DBW relay,
   4M fuel pump speed, 5A starter, 5P/5L fuel pump relay, 5AA A/C relay.
4. Dynamic discrimination in the SH-2E emulator (harness calls of the flag
   producers + output drives under key-on / cranking / running / stall /
   key-off scenarios):
   - PE2 follows `0xffffbdd8` = key-on flag `0xffffaa68` && grace counters
     (high at key-on, cranking, running; low at key-off) → fuel pump relay
     (5P/5L candidate). Computed in `0x2fc00` (fueling task `0x117ac` via
     `0x2f95c`), forced by `0x2fbf0` from main task `0x1102a` via `0x2f948`;
     driven by `0x2f890` (direct) and `0x2f8ce` (diag-gated via `0x5c204`).
   - PE1 follows `0xffffbdbc` (`0x2fb20`): fuel-demand threshold term or
     injectors-off while key-on → fuel pump speed control (4M candidate).
   - PD7 high only while cranking (`0xffffd15c` from `0x532d0`: vspeed≈0,
     cranking `0xffffaa62`, engine_running `0xffffa428`, E2-shadow
     `0xffff86e8` < 0xea; chain `0x4ed3c`→`0x4ef86`→`0x3a0ec`) → starter relay
     (5A candidate). PE0 (`0xffffcfb7` inverted) mostly high → DBW relay
     (4C candidate).
   - PJ7 follows `0xffffbd68` from `ref_calculateACClutchOn__` `0x2e89c` → A/C
     relay (5AA). Corrects the earlier "fuel-pump candidate" note.
5. Oil pressure switch (terminal 2E candidate) is an expander input, not a
   direct pin: `0x2bafc` reads SCI0 expander channel 1 bit 0x80 (light,
   debounce vs ROM `0x775b8`=0x10 → `0xffffbc0c`); `0x2bb74` reads channel 2
   bit 0 (gauge → `0xffffbc14` → CAN via `0x28c52`). Neither feeds the pump
   relay chain — hardware backup only.
6. Inertia switch: no PCM input pin exists for it in the pinout; it sits in the
   fuel pump feed circuit hardware-side. Not a firmware condition.

Binary-level verification: [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt)
(38/38 pool/instruction/threshold checks against the raw ROM, SHA-256 pinned);
label-level checks in `tests/test_fuel_pump_control.py` (9/9) and dynamic
drive checks in `tests/test_fuel_pump_control_dynamic.py` (6/6).

Limits: chip-pin → connector-terminal routing is board-level unresolved
(candidates only); grace-counter periods not pinned to task periods; cross-ROM
matching not run for this chain; only `60E15120_N3J1E` investigated.
