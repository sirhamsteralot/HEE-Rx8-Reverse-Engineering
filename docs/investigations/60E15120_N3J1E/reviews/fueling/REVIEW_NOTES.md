# Sceptical re-review addendum — fueling chain (2026-10-30)

Independent re-check of the riskiest claims in `README.md` against the ROM
disassembly, the float constants and the def files. Corrections: none needed;
confirmations and caveats below.

1. **PID 0x1410 conflict is real.** `RX8Defs/RomRaider/logger_rx8_defs.xml`
   lines ~168/175 both use address `0x221410`: PIDTEST4 "Injector Pulse
   Time" (x*8 us) and PIDTEST5 "Throttle Pedal Position" (x*0.3921568 %).
   The firmware handler 0x56f6c loads `DAT_ffffbe24` and encodes with
   `rx8_encode_u16_affine_saturate(x, 0x41000000, 0)`; 0x41000000 = **8.0**,
   matching the pulse-time us conversion. 0x2fea8 writes be24 = be28 (pulse
   arbitration). Conclusion: firmware side = injector pulse time in 8-us
   counts; the logger def has the duplicate entry and needs an upstream
   repair. Kept as `candidate_diag_injector_pulse_time` because of the
   conflict.
2. **Engine Load step.** Handler 0x56b8a encodes `engine_load_ffffc0b4` with
   0x3b808080 = **0.0039215684 = 1/255**, matching the logger expr
   `x*0.003921568`. Confirmed.
3. **Blend-weight decay constant.** 0x200c6 subtracts literal 0x3d888889 =
   **0.0666667** per call from b11c/b118 in the open-loop branch — matches the
   `rx8_max_float(b118 - 0.0667, 0.0)` in the C. Confirmed. The 1.0/0.0
   forcing branches and the c590/cca1/c644>1000/b1d0 gates read directly in
   the disassembly; which physical state "1.0" represents is inferred from
   consumers (0x1ee4a, 0x11f00/0x1206c), so b11c/b118 stay medium-confidence
   dataflow names.
4. **0x306e8 formula.** Re-read against the disassembly: bed0 = c0b4 *
   0.07196; bed4 = 3D tbl 0x6ac88; bf1c = 2D tbl DAT_0006ac38; bf14 sums the
   adder block and multiplies by ad ecc * bed4; beac = FUN_0005c024(bf14);
   beb0 = beac * bed0. The descriptor 0x6ac38 is **not** in
   `romraider_descriptor_matches.json` (neighbours 0x6ac4c/0x6ac60 match
   other defs), so `tbl_fuel_coolant_compensation_0006ac38` is labeled as a
   dataflow hypothesis, not a def-verified name. Corrected wording in README
   accordingly.
5. **Latency quantization.** 0x2ff78 divides the 3D latency lookups by 0.25
   (tbls 0x6aa64 'Injector Latency Secondary' -> ch0, 0x6aa80 'Primary' ->
   ch1/ch2 via 0x86f8). Def names corroborate; the /0.25 int conversion is
   from the C. Confirmed as far as static reading goes.
6. **Cold start enrichment is degenerate in this ROM.** 0x1ddfc stores 0.0
   into b0c4 in both cranking branches; running branch is max(b0c4 - 0.0, 0).
   Kept as `candidate_cold_start_enrichment` (medium) — the def-side
   "First Start Oil Injection Timer" etc. are separate.
7. **Pipeline caveat discovered and fixed this pass:**
   `name_lookup_variables.py` regenerates `named/lookup_aliases.tsv` from raw
   `DAT_` tokens and must only run on a fresh export (it is placed before the
   integrator in `rebuild.sh` for that reason). Running it manually on the
   already-integrated export wiped the generated rows; they were restored
   from `backups/pre_fueling_labels.zip` and the curated merge re-applied
   (486 rows + header). Also fixed a duplicate-header artifact in the three
   `source_review/accepted_*.tsv` files and made
   `scripts/review_fueling_labels.py` read with the header consumed
   (matching `review_knock_loop_labels.py`).
8. **knock_loop_labels.json side effect:** `review_knock_loop_labels_apply.py`
   records *all* current rows of the accepted TSVs, so after this pass its
   `ram_aliases` count grew from 84 to 245 (it now includes the fueling
   rows). The knock review document itself is unchanged and still accurate
   for its date.
9. No ROM bytes, def XML or address values were modified; all changes are
   names/comments in the export views and metadata.

## 10. Binary-level verification pass (2026-10-30, second pass)

Every label was re-checked against the raw ROM (`60E15120_N3J1E.bin`) and
`decompiled/firmware_disassembly.asm`, independently of the decompiler:

- **Instruction bytes**: all 168,592 disassembly words re-read from the ROM —
  0 mismatches.
- **All 150 RAM aliases**: the claimed reader function's literal pool
  (mov.w low16 with `mov #-1` high-half idiom, or mov.l full32) contains the
  address directly or as base+offset for indexed arrays: latency stride 4
  from `0xffffa094` (mirrors at +0xc), zero offsets stride 4 from `0xffffa0ac`,
  channel struct base `0xffffa004` with fuel request +0xc, start angle +0x10,
  flags +0x13/+0x14, stride 0x18 computed by shifts (0x8a76-0x8a88). 0 failures.
- **All 39 function aliases**: present in `function_index.tsv` under the expected
  name (medium confidence -> `candidate_` prefix). 0 failures.
- **Constants**: 0.07196 at shared pool 0x78170 (referenced by 0x306e8);
  decay 0.0667 = 0x3d889a02 at 0x7132c/0x71330 (referenced by 0x200c6 — note the
  exact bits are 0x3d889a02, not 0x3d888889); 0.6345 at 0x7a088; MAF scale
  5/65536 = 0x38a00000 in 0x7438's pool; 1/255 = 0x3b808080 at 0x55824 (PID 0x0043);
  8.0 = 0x41000000 for PID 0x1410; 2500/1700 present in 0x18cfe's pool (1100.0 in
  the shared pool); 60.0/0.6345 multiply to the folded 38.07 in 0x314d0 (no 38.07
  literal exists — verified as `fmul` 60.0*0.6345 then `fdiv`, 0x314ee-0x314f4).
- **MAF fault thresholds** live in the calibration area as u16s: 0x6c102 = 0xfae1,
  0x6c104 = 0xac0, loaded by 0x7438 via pointers 0x6c102/0x6c104; disasm
  `cmp/gt`/`cmp/ge` semantics give raw > 0xfae1 -> fault 1, raw < 0xac0 -> fault 2
  (the C's `< 0xfae2` boundary is the integer-equivalent). Label wording kept.
- **Descriptors**: 21 table descriptors re-parsed from raw ROM bytes
  (2D `>HBBII`, 3D `>HHIIIB`) — counts, axis pointers, data pointers and type
  codes all match `cross_ecu/romraider_descriptor_matches.json`. 0x6ac38 parses
  as a valid 2D descriptor (n=9, typ=8, axis 0x7844c, data 0x78470) but has no
  def name — candidate label stands.
- **Diagnostic dispatch**: records at 0x5f10c re-read from ROM — PID 0x0034 ->
  0x56b22, 0x0043 -> 0x56b8a, 0x0044 -> 0x56b9e, 0x1410 -> 0x56f6c, 0x1746 ->
  0x5707a all byte-identical to `metadata/diagnostic_dispatch.tsv`.
- **Task table**: ROM 0x4998 records re-read — task[5]=0x65f6, task[6]=0x661e,
  task[10]=0x64f6, task[11]=0x6584 as documented.

**Correction found by this pass:** 0x8a68's pulse is
`(latency + fuel_request) >> 4` — the four `shar` at 0x8a96-0x8a9e apply to the
sum, not just the request (C precedence confirms). Evidence text in
`accepted_function_aliases.tsv`, `accepted_ram_aliases.tsv`,
`scripts/review_fueling_labels.py`, `metadata/fueling_labels.json` and both
docs updated accordingly. No address or name changes.
