# Throttle / DBW control — review notes

Method, in order:

1. ADC channel map: the `0x6884` sweep writes `ADDRnH` results to
   `0xffff9ee4 + 2n` (pool `0x6a1c`=0xffff9ee4, verified in ROM). Channel
   identity was settled dynamically, not by guesswork: harness boot to the idle
   loop, then drive single channels and read the downstream cells.
   AN4 = 50000 → task `0x64ba` → `0x1150e` → `0x199d4` → `0x193c4` gives
   `0xffffa9b4` = 100.0 (pedal percent); AN18 = 50000 → `0xb398` →
   `0x1b08e`/`0x1b14c` → `0x1b940` gives `0xffffa218` = 95.367 V,
   `0xffffad44` = 80.367, `0xffffad48` = 95.676 (plate). So AN4/AN5 = APP,
   AN18/AN19 = TP — this also corrected the ADC line in `docs/learnings.md`
   and the `throttle_position_*_percent` aliases on `0xffffa9b4`/`0xffffa9b8`
   (they are pedal percents; the plate percent is `0xffffad48`).
2. Task wiring from the task table at `0x4990` (16-byte records, read from
   ROM): rec[9] @`0x4a20` entry `0x64ba` → `0x1150e` (pool `0x656c`), which
   runs the sensor batch `0x199d4` (pool `0x116b8`) and the DBW control batch
   `0x22f86` (pool `0x116c8`); rec[18] @`0x4ab0` entry `0x64e8` → `0x11534` →
   torque batch `0x21b4c`; rec[13] @`0x4a60` entry `0x65b2` → `0x118d0` (pool
   `0x66d8`) → PWM batch `0x2253c` (pool `0x11a88`); rec[12] @`0x4a50` entry
   `0x6592` → `0xb308` (once-only TO7D enable).
3. Motor drive enumeration: scanned every `P?DR_W`/`P?CR*_W` store and every
   ATU register write in the ROM. Running config: TO7D only (PBCRL_W = 0x4000
   at `0x51de`; BFR7D `0xfffff596` written by `0xb2c0` from duty q16
   `0xffffa210` × period `0xffff9f50` = 32000). No direction GPIO / second leg
   found anywhere — recorded as a limit in the report §4.6. PE0 relay:
   `0x3a0ec` (already labeled), dynamic PE0 = (cfb7 == 0).
4. PID 0x1410: read the dispatch record at `0x5f394` from ROM
   (`14100200 fffc0000 00056f6c`), disassembled handler `0x56f6c`: reads
   `0xffffbe24` (pool `0x57018`), encoder `0x2490` (pool `0x57038`), step 8.0f
   (pool `0x57048`). `0xffffbe24` is written by `injector_pulse_time_arbitrate`
   `0x2fea8` in the fueling chain. Dynamic: harness call of `0x56f6c` with
   `0xffffbe24` = 80.0 stores u16 10 in the response buffer, 16.0 stores 2.
   Settled: injector pulse time; the upstream "Throttle Pedal Position" alias
   at 0x221410 is wrong for this ROM and was removed from the reviewed def.
5. Limp: `0x1b940` sets `0xffffad44` = 20.0 only when `0xffffcc98` == 1 and
   `0xffffcc99` == 1 (verified dynamically); `0xffffcc98` selects the TP2
   branch (`0xffffad3c`).
6. Every pool word / constant cited in the label JSON evidence strings was
   re-read from the raw ROM: [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt),
   87/87 PASS.
