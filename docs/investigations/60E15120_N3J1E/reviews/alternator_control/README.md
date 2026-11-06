# Targeted static review: alternator / charging control

Scope: the inherited `ref_alternator*` areas of 60E15120_N3J1E (RX-8 PCM,
SH7055F), read from the canonical export (`decompiled/`), the disassembly and
the raw ROM (SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, untouched).
Root report: [`../../alternator_control_report.md`](../../alternator_control_report.md);
record: `data/labels/60E15120_N3J1E/alternator_labels.json`.

## 1. The three batch bodies (inherited names verified)

All three are mask-0x10 batch wrappers (`sh_raise_interrupt_mask_return_previous`
0x3920 with r4=0x10, tail jmp to `ref_setSR` 0x3934). Pool words read from ROM:

- 0x267c6 `alternator_control_main_batch` (caller 0x114d0, callgraph):
  0x26888=0x3920, 0x2688c=0x25a22, 0x26890=0x25a3c, 0x26894=0x25a68,
  0x26898=0x25b36, 0x2689c=0x25ba4, 0x268a0=0x2616e, 0x268a4=0x26624,
  0x268a8=0x25710, 0x268ac=0x545bc, 0x268b0=0x3934.
- 0x2680e `alternator_monitor_batch` (caller task[10] 0x11744):
  0x268b4=0x257b4, 0x268b8=0x2590a, 0x268bc=0x25aa0, 0x268c0=0x2635c,
  0x268c4=0x264f0, 0x268c8=0x26760, 0x268cc=0x54590, 0x268d0=0x545a6.
- 0x26868 `alternator_pid_task` (caller task[14] 0x11adc `charging_control_batch`):
  0x268d8=0x25c6c only.

## 2. Control path (0x267c6 batch)

- 0x25a68: `0xffffb598 = rpm * 2.08` (f32 @0x74990); flag 0xffffb613 =
  b598 >= 859.0 (pool 0x74994).
- 0x25a3c: 0xffffb612 = b654 >= 18.471 (0x74978/0x74988) || b658 >= 15.938
  (0x7497c/0x7498c).
- 0x25ba4: battery temp model 0xffffb5c4 = IAT + max((coolant-93)*0.43, 0)
  (0x749b0/0x749b4) + filter(tbl 0x6a524(vspeed), factor 2e-5, clamp [-7.2, 4.4]);
  66.25 when 0xffffc5db.
- 0x2616e: error 0xffffb5c8 = clamp(b59c - b65c, ±2.5) (2.5 @0x2623c), delta
  0xffffb5cc; target field 0xffffb5a0 = tbl 0x6a54c(b598) when b613; ramp
  (rpm-b600)/(b604-b600) clamp [0.1,1] with b600/b604 = 406.25/700.0
  (0x749ec/0x749e4; AT-in-neutral 406.25 when b534==1 && b53a==0) → 0xffffb5d0;
  integral 0xffffb5d4 = clamp(b5c8*10, -125, 4.8828), accumulator 0xffffb5d8.
- 0x26624: duty 0xffffb5f0 = 3.75 (@0x26734) or 3-D 0x6a5c4(b598, b5e0);
  filter 0.1244 (0x74a40) → 0xffffb5f4; 0xffffb5f8 = clamp((b5f4 - prev*0.9672
  (0x74a44))/0x3d065950, 0, 3.75); percent 0xffffb620 = clamp(tbl 0x6a560(b5f8),
  0, 100) when b5e0 out of band and b612==0; 0xffffb5ac = 0x5c800(b620).
- 0x25710: `0xffff9f48 = mul_s32_shift16_saturate((clamp(b5ac,0,100)/100)*65536,
  period@0xffff9f44)`. Disasm: pool 0x2578c = 0xffff9f44, 0x25780 = f32 100.0, 0x25788 = f32 65536.0;
  `mov.w @r5,r5` reads period (0x2573c), `mov.w r0,@(0x4,r2)` stores duty (0x2574a).

## 3. Output hardware path — ATU-II channel 5B

- 0x25674 `alternator_pwm_channel_init`: 0xffff9f44 = 1000 (period), 0xffff9f48 =
  0 (duty); `ATUII_GR5B_W` 0xfffff4e4 = `ATUII_TCNT5_W` 0xfffff4e0 + 1;
  `ATUII_TIOR5A_B` 0xfffff4eb = (b & 0x8f) | 0x10; `ATUII_TSR3_W` 0xfffff480 =
  0xf7ff; TIER3 |= 0x800. Register names from symbols.tsv.
- 0x57c6 `alternator_pwm_service`: splits duty 0xffff9f48 vs period 0xffff9f44
  into compare windows (0x7e margin) 0xffff9f46/0xffff9f4a, then
  `ATUII_GR5B_W` = TCNT5 + compare, TIOR5A output config toggled 0x10/0x20;
  invoked via pool word 0x2b88 = 0x57c6 (load at 0x2b82) from the ch5B compare
  interrupt path. Package-pin ↔ terminal for TIO5B is board routing (unresolved).

## 4. Monitor path (0x2680e batch) and DTCs

- Confirmation timers 0x257b4/0x2590a/0x2635c reload 0x138 under fault conditions
  and count down otherwise; counters b638/b63a/b63c/b63e/b640/b642 saturate while
  engine running and volts >= 10 (b645/b646/b647 from 9/10 V thresholds).
  Voltage thresholds from literal area 0x74978-0x74a44: 18.471, 15.938, 16.973,
  10.938, 8.486699 (0x74a1c). 0x25aa0: coolant 55/60 °C → b648, hot-engine timer
  b60c = 100. 0x2635c sets 0xffffb5b2 when b60e == 0.
- 0x26760: 0xffffb5b4 = 1 when b613==0 || b5b0 || b5b1 || b5b2 || c5db. The flag is
  read only by 0x28c78 (packs into CAN status word 0xffffbab2 bit 0x40, pool 0x28d70
  at 0x28cfe) and the Mode 22 PID 0x0968 handler 0x57138 (pool 0x5717e) — no lamp
  GPIO is driven from it in this pass.
- DTC raises 0x545bc/0x54590/0x545a6 call 0x5fd38(slot, status): slot→code_id via
  u16 table 0x7df42 + slot*2, code_id→code via u16 table 0x7e560 + code_id*2
  (SAE J2012 decode per the DTC report). Slots: 0x7b → code_id 0x71 → 0x2502 =
  **P2502** charging system voltage problem; 0x7c → 0x72 → 0x2503 = **P2503**
  voltage low; 0x7d → 0x73 → 0x2504 = **P2504** voltage high.
- 0x264f0/0x2633e: electrical-load quantity 0xffffb5e0 filtered into 0xffffb5a4
  (factor 0.035335), thresholded 40/30 → 0xffffb5b3 (feeds idle control); b5a4/b5a0
  ratio used by 0x2ce18 for drag torque 0xffffbcc4 = tbl 0x6a790(b598) × b5a4/b5a0.

## 5. Voltage target (0x26868 → 0x25c6c)

0x25c6c selects 0xffffb61c: 14.2 V default (pool 0x749c8) when c6ac<=0 && b64c;
tbl 0x6a5b0(battery temp) + clamp(b59c ± 0.2 hysteresis) in cold mode;
tbl 0x6a59c + min(b59c+0.2, b624) in another mode; then
0xffffb59c = 0x5cba4(b61c). Coolant/IAT 145/150 °C flags b64a/b64b/b64c.
0x5cba4 and 0x5c800 are diag-override-aware u16 encoders (DID 0x97c / 0x16e8,
cells 0xffffd34f / 0xffffd347, steps 0x3a000000 / 0x3b480000) — same pattern as
0x5ca94; they publish target/duty to Mode 22, they do not drive hardware.

## 6. Validation

See `validation.json` in this folder: `validate_export.py` (ROM SHA-256, 168,592
instruction bytes, 1,833 exact reference matches), `verify_claims.py`,
`verify_readability.py`, `verify_math_units.py`, `validate_reports.py` — all PASS;
`python -m pytest tests/` 134 passed. Labels applied by
`review_alternator_labels.py` + `annotate_source_review.py` +
`integrate_reviewed_names.py` (25 function rows, 10 RAM rows; 36 export files
renamed; 3,355 function bodies verified intact).
