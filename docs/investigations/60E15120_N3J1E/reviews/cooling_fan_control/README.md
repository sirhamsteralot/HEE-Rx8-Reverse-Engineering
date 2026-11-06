# Targeted static review: cooling fan control

Scope: the inherited `ref_initFanControl` / `ref_setFanOutputGPIO` areas of
60E15120_N3J1E (RX-8 PCM, SH7055F), read from the canonical export
(`decompiled/`), the disassembly and the raw ROM (SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, untouched).
Root report: [`../../cooling_fan_control_report.md`](../../cooling_fan_control_report.md);
record: `data/labels/60E15120_N3J1E/fan_control_labels.json`.

## 1. Chain and call edges

- Fan task wrapper 0x2f266, called from 0x117ac via pool word 0x11a04 (load at
  0x11826). Pool 0x2f29c=0x2f51a, 0x2f2a0=0x2f65c, 0x2f2a4=0x2f1dc (classified
  ptr_pool_code 0x2f290-0x2f2ab): decision bodies then output.
- Init path: boot fan-out 0x1102a → thunk 0x2f260 → 0x2f188 (callgraph
  0x1102a -> 0x2f260, 0x2f260 -> 0x2f188).

## 2. Output GPIO (both writers share pool 0x2f240-0x2f25f, classified u32_table)

ROM words: 0x2f240=0xf754 (PEDR_W low16 → 0xfffff754), 0x2f242=0x800 (PE11 mask),
0x2f244=0xbda1, 0x2f246=0x10 (PE4 mask), 0x2f248=0xbda2, 0x2f24c=0x2054
(ref_setSR_PARAM), 0x2f250=0x4bbc (ref_setRegister_REG_BIT_VAL), 0x2f254=0x2064,
0x2f258=0x5c724, 0x2f25c=0x5c648.

- 0x2f1dc `fan_output_gpio`: PE11 = 0x5c724(bda1), PE4 = 0x5c648(bda2), each under
  mask 0xe0 (jsr 0x2054, then 0x4bbc with r4=reg, r5=mask, r6=value, then 0x2064).
- 0x2f188 `fan_output_gpio_init`: same reg/masks, values read straight from
  bda1/bda2 (mov.b @r3 at 0x2f1a2, cmp/eq 0x1, movt r6; jsr 0x4bbc at 0x2f1aa).
- `PEDR_W` at symbols.tsv 0xfffff754; package pins from Sh7055h.pdf Table 1.3:
  PE4 = pin 12, PE11 = pin 21. Harness terminals 5X (R/G) / 5AD (L/W) =
  "Electrical fan control / cooling fan relay" (pinout v3). Chip-pin↔terminal
  remains board routing (unresolved).

## 3. Decision logic

- 0x2f51a `fan_low_speed_decision` → 0xffffbda1: coolant hysteresis 94/97 °C
  (bdaa/bdab); on-condition = hot coolant, or engine stopped (0xffffaa68==0)
  with 0xffffbda0 && !0xffffccc6 && !0xffffa8ea && !0xffffbf8d (APV), or
  0xffffbd68/0xffffbd6a; DTC/fault gates 0xffffd040, 0xffffd0a8, 0xffffd264,
  0xffffd269, 0xffffd263.
- 0x2f65c `fan_high_speed_decision` → 0xffffbda2: needs bda1==1 and counter
  0xffffbda8 > 0x5c; extra conditions: coolant ≥101 °C (hyst 98, bdac), or
  (bd68 && A/C switch 0xffffbdb8), or the engine-off term, or bd6a, or
  (load 0xffffc6ac < 1.94 (hyst 1.84, bdb2) && coolant ≥ 80 °C (hyst 77, bdb3)
  && vspeed < 10 km/h (hyst 8, bdb4)); plus 0xffffc5e6 || (d264 && !d269);
  gated by !d263. Counter bda8 saturating-increments while bda1.

## 4. Diag overrides

- 0x5c724: UDS actuator test DID 0x17c3 (mask 0xc0 on 0xffffd36c, state
  0xffffd319/0xffffd323, output cell 0xffffd345) — fan 1.
- 0x5c648: DID 0x17c4 — fan 2. Both feed 0x2f1dc.

## 5. Validation

See `validation.json` in this folder: `validate_export.py` (ROM SHA-256, 168,592
instruction bytes, 1,833 exact reference matches), `verify_claims.py`,
`verify_readability.py`, `verify_math_units.py`, `validate_reports.py` — all PASS;
`python -m pytest tests/` 134 passed. Labels applied by
`review_fan_control_labels.py` + `annotate_source_review.py` +
`integrate_reviewed_names.py` (8 function rows, 3 RAM rows; 10 export files
renamed; 3,355 function bodies verified intact).
