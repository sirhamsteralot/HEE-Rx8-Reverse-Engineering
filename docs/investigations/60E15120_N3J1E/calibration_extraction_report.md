# Calibration extraction at scale — descriptor scan + cross-ROM diff

**ROM:** 60E15120_N3J1E.bin, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`
(plus all 10 stock ROMs + 4 own 60E0G500 dumps). Static analysis of ROM bytes only;
no firmware was modified.

## 1. Executive summary

Built `utilities/scripts/extract_maps.py`, a scanner that finds every Denso
lookup-table descriptor in the ROM and dumps all tables + axes to `data/maps/`.
On 60E15120_N3J1E it finds **587 tables** (450 2D + 137 3D), of which **478 match
the RX8Defs XML definitions** (all of them, 0 missing, 0 type mismatches) and
**109 are previously unnamed**. Cross-ROM diff (`diff_maps.py`) matches tables
across all 10 stock ROMs by structure and reports per-cell differences. The
streetport tuned ROMs differ from stock in 15–17 named tables.

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
- Streetport diff mapped to named descriptors: 15–17 tables (see §6).

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
| Aron N3ZHEC stock | 0x6c000 | 404 | 129 | 533 | 0 |
| Aron N3ZHEC streetport ×3 | 0x6c000 | 404 | 129 | 533 | 0 |

Type distribution (N3J1E): uint8=264, uint16=175, float32=148 (no int8/int16).

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

### Streetport diff mapped to descriptors (Aron N3ZHEC stock vs tunes)

- **5500max**: 15 tables differ; **9500/10000max**: 17 (extra: 0x06a548, 0x06a580).
- Differing descriptors: 0x069a54, 0x069a68, 0x069a7c, 0x069ab8, 0x069acc,
  0x069af4 (2D u16), 0x069e4c (2D f32, 48 cells), 0x06a4d8 (3D u8 21×19, 212),
  0x06a548 / 0x06a580 (3D u8 21×19, 9500+10000 only), 0x06b0b0 (3D u16 18×20,
  337), 0x06b264 (3D f32 19×17, 55), 0x06b278 (3D f32 19×4, 14), 0x06b744 (2D
  f32, 3), 0x06bd94 (2D f32, 10), 0x06be20 (2D f32, 1), 0x06bf28 (3D f32 9×9, 1).

## 7. Files

- `utilities/scripts/extract_maps.py` — scanner + extractor
- `utilities/scripts/diff_maps.py` — cross-ROM diff
- `data/maps/<rom-id>/` — per-ROM output (manifest.json, index.tsv, tables/*.json + *.csv)
- `data/maps/cross_rom_diff.json` — cross-ROM diff report
- `data/maps/README.md` — format docs + regeneration recipe
- `tests/test_extract_maps.py` — 6 tests

## 8. Validation

- **All 478 RX8Defs-matched descriptors** for 60E15120_N3J1E found by the
  scanner (0 missing, 0 type mismatches vs `cross_ecu/romraider_descriptor_matches.json`).
- **109 additional unnamed tables** discovered beyond the XML-named set.
- **Data spot-check**: 20 tables re-read from raw ROM bytes — all values match.
- **All axes monotonic** across all 587 tables (strong false-positive filter).
- **6 new tests** in `tests/test_extract_maps.py`; full suite 44/44 pass.
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
Aron N3ZHEC), 0x6d000 (60E0FB00, 60E0FC00, 60E1B900), 0x71000 (60E32000 ×2).

## 10. Limits

- Scaled vs base descriptor variants are not reliably distinguished in packed
  arrays; the `scaled` flag in the JSON is heuristic. ScoobyRom cross-reference
  would resolve this.
- Structural cross-ROM matching can pair same-shape/different-meaning tables.
  Use axis values + surrounding code references to confirm semantic identity.
- Type codes 12/16 (int8/int16) not present in 60E15120_N3J1E but the handlers
  exist (0x256c/0x2598); may appear in other ROMs.
- D5 (g/rev vs VolEf) not yet settled — needs PID 0x43 handler 0x56b8a traced
  to a specific extracted table (ROADMAP group C).
