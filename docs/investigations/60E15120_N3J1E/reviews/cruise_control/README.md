# Cruise control follow-up review — evidence folder (60E15120_N3J1E)

Companion evidence for [`../../cruise_control_report.md`](../../cruise_control_report.md).
This folder resolves the three open questions the report's §9 used to carry:
the units of `0xffffbcf8`, the producer of the band selector `0xffffcf1c`,
and the downstream consumer of the plausibility timers `0xffffcf51`–`0xffffcf5b`.

## Contents

- `dynamic_validation.py` / `dynamic_validation_log.txt` — emulator run on the
  `60E15120_N3J1E` profile (boot 300k cycles), harness-calling the ROM's own
  functions. Proves: 0x4de1c writes `0xffffcf1c = float(gear 0xffffbc3d)` on
  this ROM (config byte ROM 0x7d07f = 0x00 disables the alternative
  switch-code band map compiled into the same body); the gear chain
  0x2c324 (rpm/vss ratio thresholds 33.841/40.158/52.001/71.887/110.741 rpm per
  km/h) → 0x2c3b2 (latch after >0xb counts, 0 in neutral 0xffffb53a) → 0x4de1c;
  `0xffffbcf8` is a 0–100 **percent** cruise output (0x4c896 enable flag
  `cf34 = cruise_on && bcf8 >= TP% 0xffffa9b4` = pedal override; 0x193c4
  `a9bc = min(max(a9b4, bcf8), limiter 0xffffc028)` in the same percent
  domain); the set speed in **km/h** is the learned readValue cell
  `0xffff866c` latched by 0x32614 from filtered vss `0xffffbfa0`
  (clamp [27, 200], floor 27.0 km/h; emulator: 80→80.0, 250→200.0, 10→27.0);
  `0xffffa9b4` tracks the AN4 (TP1) ADC channel as a 0–100 percent via
  0x6884→0x94f0→0x18f60→0x1933a→0x193c4 (learned zero/span in
  0xffff8068/0xffff8070), not vehicle speed.

## What was checked at binary level (rule 7)

- Literal-pool word scan of `firmware_disassembly.asm` + raw ROM: every
  `mov.w @(pool,pc)` / `mov.l @(pool,pc)` site for 0xffffcf1c (3 sites:
  0x2d658, 0x2d86c readers, **0x4de24 writer** in 0x4de1c), 0xffffcf51–0xffffcf5b
  (only inside the cruise cluster 0x4ca7e/0x4d4a6/0x4d700 — no external
  consumer), 0xffffbcf8 (7 sites: 0x1948a, 0x2d7ac, 0x2d864, 0x2df68 writer,
  0x2e42c, 0x2e55c, 0x4c898), 0xffffbc3d (6 sites incl. writer 0x2c3c0),
  0xffffbc3c (3 sites), 0xffffa9b4 (9 sites), 0xffff866c (10 sites incl.
  writer 0x32624), 0xffffbfa4 (13 sites).
- 0x4de1c body: pool 0x4dedc = 0xcf1c/0xbc3d, 0x4def4 = 0x7d07f (config
  byte read), 0x4def8 = 0x2500 (rx8_decode_u8_affine), 0x4defc–0x4df08 =
  3.0/4.0/5.0/6.0 band floats, ROM[0x7d07f] = 0x00.
- 0x4c828 switch decode pool words: 0x4c8fe = 0xbaed, 0x4c900 = 0xcf47, 0x4c902 = 0xcf48, 0x4c904 = 0xcf49, 0x4c906 = 0xcf4a, 0x4c908 = 0xcf4b, 0x4c90a = 0xcf4c.
- 0x2c3b2: pool words 0x2c3d8 = 0xbc3c, 0x2c3da = 0xb534, 0x2c3dc = 0xb53a, 0x2c3de = 0xbc3d; jsr 0x2460 via pool 0x2c56c.
- 0x2df62: pool 0x2e004 = 0xbcf8 (store), clamp args via pools
  0x2e040/0x2e044/0x2e048/0x2e04c/0x2e050 = 0.0/0.0/100.0… jsr 0x2e03c.
- 0x193c4: pool 0x194bc area = 0x414b3333 (12.7 span), clamp [0,100];
  ROM floats 0x6eeb8 = 6.341, 0x6eec0 = 0.0, 0x6eec4 = 3.488 (0x94f0 TP map),
  0x412db22d = 10.856 (learned zero, 0x1933a pool).
- Call sites: 0x4de1c ← jsr 0x2e5d2 (pool 0x2e748), 0x32614 ← jsr 0x2e620
  (pool 0x2e77c), 0x2d638 ← jsr 0x2e638 (pool 0x2e78c) in batch 0x2e5c6;
  0x4c896 ← jsr 0x2e6a4, 0x4d700 ← jsr 0x2e6d4, 0x4db22 ← jsr 0x2e6da in batch
  0x2e692; 0x2c324 ← jsr 0x19ad6, 0x2c3b2 ← jsr 0x19adc in 0x19aa0;
  0x6884 ← jsr 0x6108, 0x94f0 ← jsr 0x6186 (0x60c8); 0x18f44 ← jsr 0x19680,
  0x18f60/0x1933a/0x193c4 ← jsr 0x19a22/0x19a40/0x19a46 (0x199d4);
  0x228dc ← jsr 0x23058 (pool 0x23160).
- ROM 60E15120_N3J1E.bin SHA-256
  a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1 (untouched).

## Findings (labels)

- `0xffffbcf8` was mislabeled `cruise_set_speed`: it is the cruise **output
  demand in percent** (`cruise_output_percent`, clamp [0,100] in 0x2df62).
  The set speed in km/h is `0xffff866c` (`cruise_set_speed_kmh`); the cruise
  target is `0xffffbfa4` (`cruise_target_speed_kmh`); the integrator
  `0xffffbd08` is `cruise_output_integrator`.
- `0xffffa9b4`/`0xffffa9b8` are TP1/TP2 percents (`throttle_position_1_percent` /
  `throttle_position_2_percent`), previously described in cruise evidence as
  "vehicle speed" — corrected here and in
  `data/labels/60E15120_N3J1E/cruise_control_labels.json`.
- `0xffffcf1c` = `current_gear_float` (bands 2.0–6.0 in the 0x2d83c/0x2d638
  tables are gears 2–6); producer 0x4de1c (`gear_float_band_producer`).
- `0xffffcf51`–`0xffffcf5b` are per-switch countdown timers inside 0x4d700
  (`cruise_switch_plausibility_timers`); their expiry clears the latches
  0xffffcf3a/3c/3e/40, staged by 0x4db22 (`cruise_plausibility_stage`) into
  0xffffcf35–38 (vss < 300 gate) and consumed by 0x4ca7e's reload of
  0xffffcf50/53/56/59 — the chain is fully contained in batch 0x2e692. The
  actuator-side law is the slow-task batch 0x2e5c6: 0x32614 (set speed km/h →
  0xffff866c, target → 0xffffbfa4) → 0x2d638 `cruise_control_output_law`
  (bd00, clamp ±100) → 0x2d83c integrator (bd08) → 0x2df62 (bcf8 = clamp(bd00+bd08,
  0, 100)) → 0x193c4 (a9bc = min(max(TP%, bcf8), limiter)) → 0x228dc
  (pedal→throttle-plate 3-D maps on a9bc × rpm → 0xffffb398, clamp 84).

The decompiled-export symbol `cruise_set_speed_ffffbcf8` (from
`integrated_names.json`) still carries the old name; renaming the export symbol
rides with the next re-runnable pipeline pass (annotation +
`integrate_reviewed_names.py`), not hand-edited here.

## Independent re-verification against the raw binary

Re-checked after the fact with a from-scratch SH-2E pc-relative pool scanner
decoding `mov.w`/`mov.l @(disp,pc)` straight from the raw ROM bytes (not the
committed listing): the reference sets match exactly — 0xffffcf1c has 3 sites
(0x2d658/0x2d86c readers, 0x4de24 writer), 0xffffcf51–0x5b only inside
0x4ca7e–0x4db22 (cruise cluster), 0xffffbcf8 7 sites (0x1948a, 0x2d7ac,
0x2d864, 0x2df68 writer, 0x2e42c, 0x2e55c, 0x4c898 — none in the 0x5xxxx
diag-handler range, so no Mode 22 PID reads it), 0xffffbc3d 6 sites,
0xffffbc3c 3, 0xffffa9b4 9, 0xffff866c 10, 0xffffbfa4 13, 0xffffa9bc 15
(incl. 0x228ea in `ref_calculateThrottlePedalPositionMapBased`). Key bodies
decoded word-by-word from ROM: 0x4de1c (store pool 0x4dedc = 0xcf1c, cfg read
pool 0x4def4 = 0x7d07f with ROM[0x7d07f] = 0x00, `tst`/`bf/s` at 0x4de2c-0x4de2e
so the gear path runs when the cfg byte is 0, jsr pool 0x4def8 = 0x2500,
band floats 0x4defc–0x4df08 = 3.0/4.0/5.0/6.0); 0x2df62 (r14 = pool 0x2e004 =
0xbcf8, `fadd` of bd00+bd08 at 0x2dfbe, clamp jsr 0x2404 with bounds via ptr
pools 0x2e048→0x767e4 = 100.0 and 0x2e04c→0x767e0 = 0.0, store 0x2dfcc);
0x4c896 (cf18 = bcf8 copy at 0x4c89a-0x4c89c, `fcmp/gt` at 0x4c8b0 + `bf/s`
0x4c8b2 → cf34 = 1 only when bcf8 >= a9b4); 0x32614 (write pool 0x32662 =
0x866c); 0x193c4 (pools 0x194c8 = 0xbcf8/0xc028 for the demand mix, 0x194d0 =
100.0, 0x194d4 → 0x6ef18 = 12.7 span); 0x2c3b2 (pools 0x2c3d8/0x2c3de =
0xbc3c/0xbc3d, 0x2c3dc = 0xb53a, gear constants `mov #1..6` at 0x2c410–0x2c498);
0x94f0 (const 0x38a00000 = 7.6294e-05 at pool 0x9610, ROM tables 0x6eeb0/
0x6eeb4 via pools 0x9618/0x961c; coef 0x6eeb8 = 6.341, base 0x6eec0 = 0.0,
0x6eec4 = 3.488); 0x1933a (learned cells 0x8068/0x8070, default 0x412db22d =
10.856 at 0x6ef00); 0x6884 sweep (ADDR base 0xfffff800, RAM dest base
0xffff9ee4 → ADDR4H 0xfffff808 lands at 0xffff9eec); call-site pools
0x2e748/0x2e77c/0x2e78c/0x2e7c8/0x2e7e4/0x2e7e8/0x19c84/0x19c88/0x23160/0x19c30
all match their targets; gear-ratio thresholds 110.741/71.887/52.001/40.158/
33.841 at ROM 0x758b8–0x758c8. ROM SHA-256 re-verified
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`.
