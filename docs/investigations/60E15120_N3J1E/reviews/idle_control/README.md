# Targeted static review: idle speed control (task[10] batch 0x167c0)

Scope: the idle-speed-control subsystem of 60E15120_N3J1E (RX-8 PCM, SH7055F),
read from the canonical export (`decompiled/`), the disassembly and the raw ROM
(SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). Root report: [`../../idle_control_report.md`](../../idle_control_report.md);
record: `data/labels/60E15120_N3J1E/idle_control_labels.json`.

## 1. The batch body 0x167c0 (renamed `idle_control_calc_batch`)

Disassembly 0x167c0–0x1686e (174 bytes): 27 `jsr` + 1 tail `jmp` = a 28-call
batch. First `jsr` at 0x167c6 targets pool 0x16888 = 0x3920
`sh_raise_interrupt_mask_return_previous` with `mov #0x10,r4` at 0x167c8. The 26
callee pool words 0x1688c–0x168f0 (classified mixed_pool 0x1687a–0x168ff) read
from ROM:

```
0x1688c=0x148a4  0x16890=0x16748  0x16894=0x16358  0x16898=0x16900  0x1689c=0x148c4
0x168a0=0x15f5c  0x168a4=0x14944  0x168a8=0x14baa  0x168ac=0x1506c  0x168b0=0x14d10
0x168b4=0x14f6c  0x168b8=0x16432  0x168bc=0x165d6  0x168c0=0x16672  0x168c4=0x15ffc
0x168c8=0x1617e  0x168cc=0x15fa0  0x168d0=0x15a40  0x168d4=0x16380  0x168d8=0x16720
0x168dc=0x3337c  0x168e0=0x3354e  0x168e4=0x34650  0x168e8=0x34814  0x168ec=0x15a9a
0x168f0=0x216f8
```

Tail: `mov.l @r15+,r4` (0x16866) then `jmp @r3` (0x1686a) via pool 0x168f4 =
0x3934 `ref_setSR` (delay slot restores PR). Pools 0x168f8/0x168fc (0x15f74/
0x15f8e, trim-reset/validate helpers) sit after the `jmp` and are unreachable.
Caller: task[10] body 0x11744 `jsr`s 0x167c0; task table base 0x4990, rec[10].entry
at ROM 0x4a38 = 0x64f6, thunk 0x64f6 → 0x11744. The callee set (idle air terms,
target 0x1506c, feedback 0x15a9a, trim learn 0x1617e/0x15fa0, stall/learn flags,
plus the VDI wrapper 0x34814) confirms the inherited `ref_updateIdleControl__`
hypothesis; renamed to `idle_control_calc_batch`.

## 2. Target encode 0x5ca94 (renamed `idle_target_encode_u16`) — closes the open output-path question

Sole caller is 0x1506c (callgraph), which stores the returned u16 into
0xffffa7ac. Disassembly: reads diag state 0xffffd319 (pool 0x5cb44); when 0,
compares active DID 0xffffd314 (pool 0x5cb54) with word 0x96e at pool 0x5cb42 and
checks mask 0xc0 (word at 0x5cb3e) against 0xffffd36c via the dispatch record
0x5f728/0x5f734. Encode path: `mova @(0x5cb64,pc)` loads f32 0x3e800000 = 0.25
(ROM 0x5cb64), `jsr` 0x2490 (`rx8_encode_u16_affine_saturate`, pool 0x5cb68) with
fr4 = target, fr5 = 0.25, fr6 = 0; result u16 stored to 0xffffd34d (base
0xffffd335 + 0x18). Decode path: `jsr` via pool 0x5cc8c = 0x24c0
(`rx8_decode_u16_affine`) on the override cell when active. 0xffffa7ac is the
Mode 22 PID 0x096e source: dispatch record 0x5f328 → handler 0x56e22
(`candidate_diag22_pid096e_ram_a7ac_quarter`, DAT_ffffa7ac*0.25, dynamically
verified in the diag pass). Conclusion: 0x5ca94 quantizes the target for the
diagnostic readout; it does not drive an actuator register.

## 3. Feedback and output

- 0x15a9a `idle_air_feedback_calc` (938 B): rpm 0xffffb548 vs quantized target
  0xffffa7ac → flag 0xffffa844 (312.0 floor at pool 0x6df44); air/rev terms
  `a834*a7ac/rpm`; tables 0x6947c/0x69490/0x694b8 (rpm), 0x69440/0x69454 (coolant),
  0x694a4 (cranking); constants pool 0x6df48=29.1969, 0x6df54=0.5, 0x6df58=0.892,
  0x6df5c=0.15, 0x6df60=2.72, shared 0x7a088=0.6345; writes 0xffffa850…0xffffa838.
- 0x216f8 `idle_air_output_clamp` (70 B): pool 0x21740-0x2175c words 0x21744=0x6a218,
  0x21748=0x6a240, 0x21750=0xffffb2a8, 0x21754=0x6a22c, 0x21758=0xffffb2ac,
  0x2175c=0x2404; `0xffffb2a4 = clamp(tbl 0x6a218(a838), tbl 0x6a240(coolant), tbl 0x6a22c(coolant))`.
  Descriptors parsed: 0x6a218 n=21 type 4 axis 0x732dc data 0x73330;
  0x6a22c n=13 axis 0x73348 data 0x7337c; 0x6a240 n=13 axis 0x7338c data 0x733c0.
- Output path: 0xffffb2a4 is read via mov.w pool words 0x1ba80 (0x1b988 in 0x1b940),
  0x21742 (0x21730, 0x216f8 itself), 0x21b10 (0x21a88 in 0x21a80
  `ref_throttlePlatePosToTorqueOutput_`), 0x23450 (0x23402), 0x29ec6 (0x29e08),
  0x4863c (0x4857c), 0x6b786. The 0x21a80 reader is the electronic-throttle
  position→torque chain; the throttle body actuator is on PCM terminals 1B/1C
  (drive-by-wire), so no separate IAC valve register exists. Package-pin↔terminal
  routing remains board-level and unresolved.

## 4. Trim learn (E2RAM-backed cells)

- 0x1617e `candidate_idle_trim_integrator`: mov.w pools 0x16260/0x16262 =
  0x8040/0x8048 (sign-extended to 0xffff8040/0xffff8048); reads via 0x3dcd0/0x3dc22
  (`ref_readValue_float_DEFAULTVAL_ADDRESS`), nudges ±1e-5 toward sign of
  0xffffa7a8 when learn flag 0xffffa890 (pool 0x16264) is set, clamps ±0.12,
  writes back via `ref_updateMemoryAtAddress_float`; 0xffffb534/0xffffb53c
  (pools 0x16266/0x16268) select AT vs MT cell.
- 0x15fa0 `candidate_idle_trim_load`: 0xffffa88c = read(0xffff8040) if b534==1 else
  read(0xffff8048) (addresses as -0x7fc0/-0x7fb8 sign-extended).
- 0x15ffc `candidate_idle_learn_condition`: 0xffffa890 from counters
  0xffffa892/a894 (reload 0x138) plus coolant≥80 / IAT≥60 / |a7ac−0xffffb550|>37 /
  0xffffb2f0>35 / 0xffffcc91 gates.
- 0x14f6c `candidate_idle_trim_ramp`: 0xffffa7c0 ramped −0.00087 (pool 0x6dabc)
  toward 3-D floor tbl 0x69424(coolant, baro).

## 5. Select-flag producers (were "inferred, not proven")

| Flag | Producer | Evidence |
|---|---|---|
| 0xffffb534 | `ref_getAutoTransCal__` 0x24b44 | body is `DAT_ffffb534 = 1` (store at 0x24b58 via pool 0x24b5e); 0x24b8c clears b53c/b53e/b540 when b534==1 → AT flag |
| 0xffffbdb8 | `ref_getACSwitchStatus` 0x2f868 | store at 0x2f882 via pool 0x2f888: `(0xffff9ecd & 4) == 0` → A/C switch input; cell already carried the inferred PID-0x1102 alias (kept) |
| 0xffffbd69 | 0x2e9a4 | set 1/0 by a gating chain (running timer 0xffffa424, injectors-off 0xffffa42c, rpm<7800, coolant<118, flags bd72/bd73/bd76/bd92/bd96/bd97/bd98/0xffffc5e6); adjacent to `ref_calculateACClutchOn__` 0x2e89c → A/C clutch-on |
| 0xffffb5b3 | 0x264f0 | store at 0x265ce via pool 0x265f0: set when filtered 0xffffb5e0 ≥ 40.0, clear < 30.0; 0xffffb5a4 = filter(b5e0, b5a4, 0.035335) in 0x2633e; b5a4/b5a0 ratio used in alternator domain (0x2ce18) → high-load flag, physical meaning deferred to the alternator report |
| 0xffffb53c | 0x24b8c (partial) | cleared in the AT branch; MT producer not traced in this pass |

## 6. Validation

See `validation.json` in this folder: `validate_export.py` (ROM SHA-256,
168,592 instruction bytes, 1,833 exact reference matches), `verify_claims.py`,
`verify_readability.py`, `verify_math_units.py`, `validate_reports.py` — all PASS
after the pass. Labels applied by `review_idle_control_labels.py` + `annotate_source_review.py`
+ `integrate_reviewed_names.py` (26 function rows, 6 RAM rows; 72 export files
renamed; 3,355 function bodies verified intact).
