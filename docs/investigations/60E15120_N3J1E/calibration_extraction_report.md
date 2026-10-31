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

## 2. Descriptor format (verified at the binary level)

Big-endian, corroborated by the lookup code at 0x2068/0x20dc and the dispatch
tables at 0x2098/0x210c:

| Variant | Size | Format | Fields |
|---|---|---|---|
| 2D base | 12 B | `>HBBII` | n:u16, type:u8, reserved:u8, axis_ptr:u32, data_ptr:u32 |
| 2D scaled | 20 B | base + 2×f32 | + multiplier, offset |
| 3D base | 20 B | `>HHIIIB`+3 pad | nx:u16, ny:u16, ax:u32, ay:u32, data:u32, type:u8 |
| 3D scaled | 28 B | base + 2×f32 | + multiplier, offset |

Type codes → handler (symbols.tsv): **0**=float32(4B), **4**=uint8(1B),
**8**=uint16(2B), **12**=int8(1B), **16**=int16(2B). Axes are always float32.

## 3. Scan strategy

1. **Auto-detect cal region start** via the `Copr.DENSO` header string
   (0x6c000 for most ROMs, 0x6d000 for 60E0FB00/60E0FC00/60E1B900, 0x71000 for
   60E32000) — different ROM generations have different code/cal boundaries.
2. **Scan** [cal_start−0x8000, cal_start) at 4-byte alignment for valid 2D/3D
   descriptor patterns (valid count, type code, reserved=0, pointers into cal
   region, bounds-checked).
3. **Resolve overlaps**: descriptors are packed consecutively; if one candidate
   starts inside another's span it's a false positive (dropped 1 in N3J1E).
4. **Extract**: read axis (f32) + data values per type code.

## 4. Results per ROM

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

Type distribution (N3J1E): uint8=264, uint16=175, float32=148 (no int8/int16
in this ROM).

## 5. Validation

- **All 478 RX8Defs-matched descriptors** for 60E15120_N3J1E found by the
  scanner (0 missing, 0 type mismatches vs `cross_ecu/romraider_descriptor_matches.json`).
- **109 additional unnamed tables** discovered beyond the XML-named set.
- **Data spot-check**: 20 tables re-read from raw ROM bytes — all values match.
- **All axes monotonic** across all 587 tables (strong false-positive filter).
- **6 new tests** in `tests/test_extract_maps.py`; full suite 44/44 pass.

## 6. Cross-ROM diff (`diff_maps.py`)

Tables matched across ROMs by (dimension, counts, type_code, axis values).
60E15120_N3J1E has 305 unique table shapes. Per-ROM vs reference:

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

60E0FC00 and 60E1B900 are nearly identical to 60E0FB00 (same match/diff counts).
60E32000 is a different generation (fewer structural matches). Structural
matching is a heuristic — some same-shape tables with different semantics pair
up (hence huge float32 "max diff" values in the report); treat those as
candidates, not confirmed semantic matches.

## 7. Streetport diff mapped to descriptors

Comparing Aron's stock N3ZHEC vs the 3 streetport tunes at the table level:

- **5500max**: 15 tables differ (all data cells, 0 axis changes)
- **9500max / 10000max**: 17 tables differ (same 15 + 2 extra: 0x06a548, 0x06a580)

Differing descriptors: 0x069a54, 0x069a68, 0x069a7c, 0x069ab8, 0x069acc,
0x069af4 (2D u16, 1 cell each), 0x069e4c (2D f32, 48 cells), 0x06a4d8 (3D u8
21×19, 212 cells), 0x06a548 / 0x06a580 (3D u8 21×19, 9500+10000 only), 0x06b0b0
(3D u16 18×20, 337 cells), 0x06b264 (3D f32 19×17, 55 cells), 0x06b278 (3D f32
19×4, 14 cells), 0x06b744 (2D f32, 3 cells), 0x06bd94 (2D f32, 10 cells),
0x06be20 (2D f32, 1 cell), 0x06bf28 (3D f32 9×9, 1 cell).

The rev limiter float32 at **0x6d54c** (9000→5500/9500/10000 from the earlier
raw diff) is a **standalone scalar**, not inside any table's data span —
confirmed by checking all descriptor data ranges.

## 8. Files

- `utilities/scripts/extract_maps.py` — scanner + extractor
- `utilities/scripts/diff_maps.py` — cross-ROM diff
- `data/maps/<rom-id>/` — per-ROM output (manifest.json, index.tsv, tables/*.json + *.csv)
- `data/maps/cross_rom_diff.json` — cross-ROM diff report
- `data/maps/README.md` — format docs + regeneration recipe
- `tests/test_extract_maps.py` — 6 tests

## 9. Limits

- Scaled vs base descriptor variants are not reliably distinguished in packed
  arrays (the 8 trailing bytes can look like the next descriptor); the `scaled`
  flag in the JSON is heuristic. ScoobyRom cross-reference would resolve this.
- Structural cross-ROM matching can pair same-shape/different-meaning tables.
  Use the axis values + surrounding code references to confirm semantic identity.
- Type codes 12/16 (int8/int16) not present in 60E15120_N3J1E but the handlers
  exist (0x256c/0x2598); may appear in other ROMs.
- D5 (g/rev vs VolEf) not yet settled numerically — needs mapping PID 0x43
  handler output to a specific extracted table (next step).
