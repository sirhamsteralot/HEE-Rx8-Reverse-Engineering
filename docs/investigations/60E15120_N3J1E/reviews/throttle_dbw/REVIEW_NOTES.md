# Throttle / DBW control — review notes

Method, in order:

1. ADC channel map: the `0x6884` sweep writes `ADDRnH` results to
   `0xffff9ee4 + 2n` (pool `0x6a1c`=0xffff9ee4, verified in ROM). The sweep and
   both raw→volts conversions run in task rec[17] (record `0x4aa0`, entry
   `0x60c8` `ref_getSensorStuff__` → `0x6884` → `0x94f0` → `0xb398`); the
   `0x199d4` sensor batch of task rec[9] consumes their output cells. Task
   rec[9] (record `0x4a20`, entry `0x64ba`) enters the pedal conversion body
   directly at `0x94fc` (pool `0x6564`), which is why the emulator run shows the
   conversion firing from the task entry.
   Channel identity was settled dynamically, not by guesswork: harness boot to
   the idle loop, then drive single channels and read the downstream cells.
   AN4 = 50000 → task `0x64ba` → `0x94fc` → `0x1150e` → `0x199d4` → `0x193c4`
   gives `0xffffa9b4` = 100.0 (pedal percent), with `0xffffa111` = 2 (AN5 below
   band); AN18 = 50000 → `0xb398` → `0x1b08e`/`0x1b14c` → `0x1b940` gives
   `0xffffa218` = 95.367 V, `0xffffad44` = 80.367, `0xffffad48` = 95.676
   (plate). So AN4/AN5 = APP, AN18/AN19 = TP — this also corrected the ADC line
   in `docs/learnings.md` and the `throttle_position_*_percent` aliases on
   `0xffffa9b4`/`0xffffa9b8` (they are pedal percents; the plate percent is
   `0xffffad48`).
2. Task wiring from the task table at `0x4990` (16-byte records, entry word at
   record + 8, read from ROM): rec[9] @`0x4a20` entry `0x64ba` → `0x1150e`
   (pool `0x656c`), which runs the sensor batch `0x199d4` (pool `0x116b8`) and
   the DBW control batch `0x22f86` (pool `0x116c8`); rec[18] @`0x4ab0` entry
   `0x64e8` → `0x11534` → torque batch `0x21b4c` (pool `0x116e4`); rec[13]
   @`0x4a60` entry `0x65b2` → `0x118d0` (pool `0x66d8`) → PWM batch `0x2253c`
   (pool `0x11a88`); rec[12] @`0x4a50` entry `0x6592` → `0xb308` (once-only
   TO7D enable, single pool reference `0x66cc`); rec[17] @`0x4aa0` entry
   `0x60c8` (ADC sweep + raw→volts).
3. Motor drive enumeration: every `P?DR_W`/`P?CR*_W` store and every ATU register
   write in the ROM was scanned. Boot starts all ATU channels (`TSTR1`/`TSTR2` =
   0xff, `TSTR3` = 0x01 at `0x4ef6`–`0x4efe`) and `PBCRL_W` = 0x4000 (TO7D on
   PB7) is written at `0x51de` in the init function entered at `0x51c8`; the only
   firmware-driven ATU compare register is `ATUII_BFR7D_W 0xfffff596` (writers
   `0xb270`, `0xb300`, `0xb346`), fed from duty q16 `0xffffa210` × period
   `0xffff9f50` = 32000 and entered only through `0x25198` with channel index 0.
   No direction GPIO / second leg found anywhere — recorded as a limit in the
   report §4.6. Relay: `0x3a0ec` drives PD7 = (`0xffffcfb6` == 1) and PE0 =
   (`0xffffcfb7` == 0) through the `0x4bbc` helper; dynamic check covers PE0 and
   PD7.
4. PID 0x1410: read the dispatch record at `0x5f394` from ROM
   (`14100200 fffc0000 00056f6c`), disassembled handler `0x56f6c`: reads
   `0xffffbe24` (pool `0x57018`), encoder `0x2490` (pool `0x57038`), step 8.0f
   (pool `0x57048`). `0xffffbe24` is written by `injector_pulse_time_arbitrate`
   `0x2fea8` in the fueling chain. Dynamic: harness call of `0x56f6c` with
   `0xffffbe24` = 80.0 stores u16 10 in the response buffer, 16.0 stores 2.
   Settled: injector pulse time; the upstream "Throttle Pedal Position" alias
   at 0x221410 is wrong for this ROM and was removed from the reviewed def.
   The remaining plate/pedal PIDs (0x0011, 0x093c, 0x0049, 0x004a, 0x0914,
   0x0915, 0x004c, 0x091a, 0x1154) were re-checked against the dispatch table:
   each quoted handler reads the cell the report names.
5. Limp: `0x1b940` sets `0xffffad44` = 20.0 only when `0xffffcc98` == 1 and
   `0xffffcc99` == 1 (verified dynamically); `0xffffcc98` selects the TP2
   branch (`0xffffad3c`).
6. Every pool word / constant / byte limit cited in the report and the label
   JSON evidence strings was re-read from the raw ROM:
   [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt), 154/154 PASS
   (checker `input/throttle_dbw_rawbin_reverify.py`, uncommitted scratch).
7. Per-channel and per-branch detail was taken from the instruction flow, not
   from the decompiled C: TP scale/base pairs (`0x6f3e4`/`0x6f3e8`,
   `0x6f3ec`/`0x6f3f0`), TP band vs fault word pairs (`0x6f3dc`–`0x6f3e2` vs
   `0x6c172`–`0x6c178`, debounce byte `0x6c17a`), the four demand branches of
   `0x193c4`, the learner counters (`0x6eeca`/`0x6eecc`), the six-branch
   `0x231f0` clamp, and the `fmov.s` store into `0xffffb410`.
