# Calibration extraction at scale — descriptor scan + cross-ROM diff

**ROM:** 60E15120_N3J1E.bin, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`
(plus all 10 stock ROMs + the own 60E0G500 factory dump). Static analysis of ROM bytes only;
no firmware was modified.

**Related reports:** the extracted tables in `data/maps/` back the §3 table lists of [load & fuelling](load_fueling_report.md), [fueling control](fueling_control_report.md), [ignition timing](ignition_timing_report.md), [knock control](knock_control_report.md), [intake solenoids](intake_solenoids_report.md); ROM/cal ID strings backing this report's cal-ID claims are mapped to Mode 22 PIDs in [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md) (fw id 0x2000, `N3J1E_1W.Z05` 0x6c000, `SW-N3ZHEB000.HEX` 0x6c043/0x6c046 — ROADMAP D1).

## 1. Executive summary

Built `utilities/scripts/extract_maps.py`, a scanner that finds every Denso
lookup-table descriptor in the ROM and dumps all tables + axes to `data/maps/`.
On 60E15120_N3J1E it finds **587 tables** (450 2D + 137 3D), of which **478 match
the RX8Defs XML definitions** (all of them, 0 missing, 0 type mismatches) and
**109 are previously unnamed**. Cross-ROM diff (`diff_maps.py`) matches tables
across all 10 stock ROMs by structure and reports per-cell differences.

### 1a. Plain-language summary

The PCM stores its tuning data as "tables" — grids of numbers indexed by sensor
values (e.g. ignition timing vs RPM and load). Each table has a small "descriptor"
header that says how big the table is, where its axis labels and data live, and
what type of numbers it stores. This pass scans the ROM for every descriptor,
reads out every table, and saves them as JSON/CSV files in `data/maps/`. It also
compares the same table across different ROMs to see what changed. Think of it as
exporting the entire calibration spreadsheet from the ECU, table by table.

## 2. How it works (pseudocode)

```
cal_start = block_of_first('Copr.DENSO' above 0x60000)   # 0x6c000/0x6d000/0x71000
for addr in [cal_start-0x8000, cal_start) step 4:
    try 3D: nx,ny in [1,256], type in {0,4,8,12,16}, pad==0,
            ax/ay/data in [cal_start, 0x80000), bounds OK  -> candidate
    try 2D: res==0, type in {0,4,8,12,16}, axis/data in cal region -> candidate
# overlap resolution: sort by addr, walk with next_free cursor (base span 12/20)
for each surviving descriptor:
    axis  = read_f32(addr=axis_ptr,  count=n)          # axes always float32
    data  = read_typed(addr=data_ptr, count=n*ny?, type)  # per type code size
    emit  data/maps/<rom>/tables/tbl_<desc>.{json,csv} + index.tsv row
cross-ROM: key = (dim, counts, type, rounded axes) -> match across ROMs -> diff cells
```

## 3. Key calibrated tables (descriptor format)

Big-endian, corroborated by lookup code at 0x2068/0x20dc and dispatch tables
0x2098/0x210c:

| Variant | Size | Format | Fields |
|---|---|---|---|
| 2D base | 12 B | `>HBBII` | n:u16, type:u8, reserved:u8, axis_ptr:u32, data_ptr:u32 |
| 2D scaled | 20 B | base + 2×f32 | + multiplier, offset |
| 3D base | 20 B | `>HHIIIB`+3 pad | nx:u16, ny:u16, ax:u32, ay:u32, data:u32, type:u8 |
| 3D scaled | 28 B | base + 2×f32 | + multiplier, offset |

Type codes → handler (symbols.tsv): **0**=float32(4B), **4**=uint8(1B),
**8**=uint16(2B), **12**=int8(1B), **16**=int16(2B).

## 4. Labeling applied

- 587 `tbl_<desc-addr>` labels created implicitly via `data/maps/60E15120_N3J1E/index.tsv`
  (descriptor address → dimension, count, type, axis/data addresses).
- 478 of these cross-reference the existing RX8Defs `CAL_` names in
  `cross_ecu/romraider_descriptor_matches.json` (0 missing, 0 type mismatches).
- 109 previously unnamed tables now have stable addresses + extracted values.

## 5. Corrections made in this pass

- Cal-region start is **not always 0x6c000**: auto-detect via `Copr.DENSO`
  (0x6d000 for 60E0FB00/60E0FC00/60E1B900, 0x71000 for 60E32000). A fixed
  0x6c000 assumption silently missed entire descriptor arrays.
- Overlap resolution needed: packed descriptors produce false candidates at
  interior offsets (1 dropped in N3J1E). Use base span (12/20 B), not scaled.
- The `scaled` flag heuristic is unreliable in packed arrays — do not use it
  for span calculation.
- Rev limiter at 0x6d54c is a **standalone scalar**, not inside any table's data
  span (verified by checking all descriptor data ranges).

## 6. Results per ROM

| ROM | cal start | 2D | 3D | total | non-monotonic |
|---|---|---|---|---|---|
| 60E0E500 | 0x6c000 | 389 | 119 | 508 | 0 |
| 60E0E700_N3YLEE | 0x6c000 | 391 | 119 | 510 | 0 |
| 60E0FB00 | 0x6d000 | 386 | 117 | 503 | 0 |
| 60E0FC00 | 0x6d000 | 386 | 117 | 503 | 0 |
| 60E15120_N3J1E | 0x6c000 | 450 | 137 | 587 | 0 |
| 60E1B900 | 0x6d000 | 386 | 117 | 503 | 0 |
| 60E1C500_N3J6EB | 0x6c000 | 389 | 119 | 508 | 0 |
| 60E1D400 | 0x6c000 | 370 | 124 | 494 | 0 |
| 60E32000_N3M5E | 0x71000 | 293 | 88 | 381 | 0 |
| 60E32000_N3N5EB | 0x71000 | 354 | 108 | 462 | 0 |
| 60E0G500_N3ZHEC (own dump) | 0x6c000 | 404 | 129 | 533 | 0 |

Type distribution (N3J1E): uint8=264, uint16=175, float32=148 (no int8/int16).

### 6a. Scalar constants — literal-pool float32s (2026-11-02)

Descriptor tables are not the whole calibration surface: single float32
constants live in shared literal pools and are referenced by literal pointers
(e.g. 0x30830 → 0x78170). `utilities/scripts/extract_scalars.py` locates 14
binary-verified seeds by exact big-endian bit pattern and writes
`data/maps/<rom-id>/scalars.{json,tsv}` plus `data/maps/cross_rom_scalars.json`.
On the reference ROM 60E15120_N3J1E the script asserts every documented
address (e.g. **fuel_load_scale 0.07196 = 0x3d935fc4 @0x78170** — the scalar
the whole fuel-volume request scales by, `fuel_load_scale_ffffbed0`; load cell
scale 0.6345 = 0x3f226e98 @0x7a088). All 13 seeds are present in all 11 ROMs
except `injector_flow_secondary_cc_min` (475.93), which 60E0E700_N3YLEE
replaces with 608.0/626.224 at 0x76ccc-0x76cd0 — different secondary injectors
on that market ROM. Seeds + evidence come from the
[load & fuelling review validation](reviews/load_fueling_model/validation.json);
tests in `tests/test_extract_scalars.py`.
- **Negative result (2026-11-02)**: no stored scalar equals λ = 0.942188
  (f32 0x3f71333c ±2 ULP, any alignment, absent from all 11 ROMs; Q15 would be
  30875.6 — non-integer; u8 scalings give x = 14.8 — non-integer; no extracted
  table cell/axis in [0.9419, 0.9424] in any ROM). The base AFR/lambda reference
  in firmware is λ = 1.0 implicit (diag Q15 /32768); WOT λ ≈ 0.942 is emergent
  from the Open Loop Target tables (u8, λ = 1 − x/256; nearest cell x=15 →
  λ 0.94140625) plus trim — see real-car logs `data/logs/nr666p/` (measured
  λ 0.942 / AFR 13.85 at WOT; 13.85/14.7 = 0.942177). Nearest stored float
  cells: 0.9418 in `tbl_069950` ("Table 2D - 308", all ROMs) and 13.85 AFR
  cells in `tbl_06fe28` (60E32000_N3N5EB only, λ = 0.94218).
- VersaTuner's "Air Fuel Ratio Base" ("base air fuel ratio used to calculate
  injection duration") is a **map**, not a scalar — its ROM counterparts are
  already extracted: `tbl_06ac88` "Fuel Injection - Engine Load Compensation"
  (u16, λ = 0.75 + x/65536, RPM×load 18×20, data 0x785f4 — the base multiplier
  `bed4` in the 0x306e8 fuel-volume calc) and the `tbl_069e9c` "Open Loop
  Target" 3D map (u8, λ = 1 − x/256, load×RPM 21×19). Closest cells to
  λ 0.942188: `tbl_069e9c` x=15 → 0.94140625 (AFR 13.84); `tbl_06ac88` raw 12616
  → 0.94250 @ 6000 rpm / load 1.0. 0.942188 itself matches the OBD reporting
  resolution (PID 0x06 = (λ−1)·100 → −5.78) and the WOT log values (λ 0.942 /
  AFR 13.85), i.e. a measured λ, not a stored constant.
- The single-value "base AFR" **is** a scalar: stoich **14.7** = f32 0x416b3333,
  one occurrence per ROM (0x3e7ec in N3J1E), referenced by `mova` @0x3e6ec in
  FUN_0003e560 and used as `diag_afr_word_a × fVar4 × 14.7` in the
  fuel-correction/catalyst model (feeds `fuel_correction_sum_ffffc644`, PID
  0x3c) — i.e. it converts the λ-domain fueling into AFR units. Seeded as
  `stoich_afr` in extract_scalars.py (2026-11-02). Per-operating-point AFR is
  the maps above, not this scalar.
- **Flex-fuel cross-check (2026-11-02)**: all 11 available ROMs are non-flex —
  each has exactly one 14.7 literal (0x416b3333) referenced by exactly one
  `mova` 0x100 B before it (N3J1E: mova @0x3e6ec → 0x3e7ec in FUN_0003e560;
  per-ROM lit/mova: 60E0E500 0x3f314/0x3f214, 60E0E700 0x3f56c/0x3f46c,
  60E0FB00+60E0FC00 0x3ed88/0x3ec88, 60E1B900 0x3f020/0x3ef20, 60E1C500
  0x3f5d8/0x3f4d8, 60E1D400 0x3f9d4/0x3f8d4, 60E32000_N3M5E 0x41a60/0x41960,
  60E32000_N3N5EB 0x40f9c/0x40e9c, 60E0G500_N3ZHEC 0x3f73c/0x3f63c). The
  G-ROM_FLEX def (no binary in this repo) replaces this constant with
  "Table 2D - Stoich Fuel Ratio" @0x6C444 (12 floats, stored 1/AFR, displayed
  AFR = 1/x, Y axis = Ethanol Content % @0x6C414) — in N3J1E that address range
  is tbl_068f94's data, so the flex table does not exist here (already flagged
  as unresolved G-ROM_FLEX inheritance in defs-merge/inheritance_issues.json).
  => A flex-fuel patch hooks exactly this site: swap the 14.7 literal load for a
  lookup into the stoich table indexed by ethanol content (logger PID 0x0555,
  uint16 %). No ethanol-indexed 1/AFR table exists in any of the 11 ROMs (scanned).

### Cross-ROM diff (vs 60E15120_N3J1E, 305 unique shapes)

| ROM | matched | unmatched ref | tables w/ diffs | diff cells |
|---|---|---|---|---|
| 60E0E500 | 245 | 60 | 39 | 1305 |
| 60E0E700_N3YLEE | 231 | 74 | 72 | 3207 |
| 60E0FB00 | 229 | 76 | 47 | 1409 |
| 60E0FC00 | 229 | 76 | 47 | 1408 |
| 60E1B900 | 229 | 76 | 47 | 1408 |
| 60E1C500_N3J6EB | 261 | 44 | 18 | 518 |
| 60E1D400 | 253 | 52 | 15 | 425 |
| 60E32000_N3M5E | 95 | 210 | 33 | 734 |
| 60E32000_N3N5EB | 138 | 167 | 56 | 1153 |

60E0FC00 and 60E1B900 are nearly identical to 60E0FB00. 60E32000 is a different
generation (fewer structural matches).

## 7. Files

- `utilities/scripts/extract_maps.py` — scanner + extractor
- `utilities/scripts/diff_maps.py` — cross-ROM diff
- `utilities/scripts/extract_scalars.py` — literal-pool scalar extractor (2026-11-02, see section 6a)
- `data/maps/<rom-id>/` — per-ROM output (manifest.json, index.tsv, tables/*.json + *.csv, scalars.json + scalars.tsv)
- `data/maps/cross_rom_diff.json` — cross-ROM diff report
- `data/maps/cross_rom_scalars.json` — cross-ROM scalar address report
- [data/maps README](../../../data/maps/README.md) — format docs + regeneration recipe
- `tests/test_extract_maps.py` — 6 tests; `tests/test_extract_scalars.py` — 5 tests (2026-11-02)

## 8. Validation

- **All 478 RX8Defs-matched descriptors** for 60E15120_N3J1E found by the
  scanner (0 missing, 0 type mismatches vs `cross_ecu/romraider_descriptor_matches.json`).
- **109 additional unnamed tables** discovered beyond the XML-named set.
- **Data spot-check**: 20 tables re-read from raw ROM bytes — all values match.
- **All axes monotonic** across all 587 tables (strong false-positive filter).
- **6 new tests** in `tests/test_extract_maps.py`; full suite 44/44 pass.
- **Scalars (2026-11-02)**: 14 seed float32 patterns found in all 11 ROMs;
  reference-ROM addresses asserted by `extract_scalars.py` and
  `tests/test_extract_scalars.py` (5 tests, pass).
- `validate_reports.py` PASS; `hash_binaries.py --check` OK.

## 9. Memory map for validation

Descriptor array (60E15120_N3J1E): **0x68ef8–0x6bc70** (587 descriptors,
packed at 12/20/28 B). Axis data: **0x6c1a4–0x7dd3c**. Table data:
**0x6c1e4–0x7dd60**. Cal header at **0x6c000** (`N3J1E` / `N3ZHE` strings,
`Copr.DENSO` at 0x6c039). Lookup dispatch tables: 2D **0x2098**, 3D **0x210c**.
Lookup entry points: `lookup_2d_descriptor_scaled` **0x2068** (174 callers),
`lookup_3d_descriptor_scaled` **0x20dc** (60 callers). Type handlers:
0x253c/0x2598/0x256c/0x25c8/0x25f4 (3D), 0x2678/0x2690/0x26b0/0x26d0/0x26f4 (2D axis).

Cross-ROM cal starts: 0x6c000 (60E0E500, 60E0E700, 60E15120, 60E1C500, 60E1D400,
60E0G500_N3ZHEC own dump), 0x6d000 (60E0FB00, 60E0FC00, 60E1B900), 0x71000 (60E32000 ×2).

## 10. Limits

- Scaled vs base descriptor variants are not reliably distinguished in packed
  arrays; the `scaled` flag in the JSON is heuristic. ScoobyRom cross-reference
  would resolve this.
- Structural cross-ROM matching can pair same-shape/different-meaning tables.
  Use axis values + surrounding code references to confirm semantic identity.
- Type codes 12/16 (int8/int16) not present in 60E15120_N3J1E but the handlers
  exist (0x256c/0x2598); may appear in other ROMs.
- D5 (g/rev vs VolEf) handler side settled 2026-10-31: PID 0x43 handler 0x56b8a
  (`diag22_pid0043_engine_load_g_rev`) encodes `engine_load_ffffc0b4` × 1/255
  (dynamically verified in the emulator); still needed: trace that RAM cell's
  writers to a specific extracted table in `data/maps/` and compare numerically
  (ROADMAP group C).
