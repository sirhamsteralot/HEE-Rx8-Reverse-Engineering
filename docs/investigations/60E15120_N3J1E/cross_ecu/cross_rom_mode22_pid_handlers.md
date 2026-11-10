# Cross-ROM Mode 22 (ReadDataByIdentifier) PID handler map

ROADMAP group D, open bullet "Map Mode 22 PID handlers cross-ROM". Base ROM
`60E15120_N3J1E` (SHA-256 asserted against `data/labels/60E15120_N3J1E/input.json`):
dispatch table **0x5f10c** = 99 × 12-byte records
`{u16 pid, u8 response_len, u8 byte3, u16 availability_mask, u16 unk, u32 handler}`
(big-endian), scanned by dispatcher **0x5774c** (`diag22_find_and_dispatch_identifier`).
The dispatcher's literal pool word at **0x57848** holds the table address; the pool
word at **0x57854** points at the count byte stored immediately after the table
(`rom[table + count*12] == count`, self-consistent: 0x5f10c + 99*12 = 0x5f5b0, byte 99).
Record layout cross-checked against all 99 rows of
[`diagnostic_dispatch_named.tsv`](../../../../data/labels/60E15120_N3J1E/diagnostic_dispatch_named.tsv).

Method (`utilities/scripts/cross_rom_mode22_map.py`, run from the repo root): per
target ROM the table is located by direct byte-compare at 0x5f10c, else a generic
run-scan (≥30 stride-12 records with ascending u16 PID and in-range even handlers)
filtered by "u32(table_addr) occurs in the ROM" (pool reference); the record count is
the unique N with `rom[table + N*12] == N` and a u32 reference to that address. All
handler fields must be even addresses in the code region 0x40–0x6c000. Handlers map
back to the base ROM by identical address or via
[`cross_rom_function_matches.tsv`](../../../../data/labels/cross_rom_function_matches.tsv)
(unique exact bytes — every matched body is re-compared byte-for-byte from the raw
ROMs in the script, and asserted to equal the base handler of the *same* PID).
Labels are inherited from the base record of the same PID.

## Results — table location and record count per ROM

| ROM | table | records | table pool ref | count byte (ref) | sub-PID table (ref) | PID set |
|-----|------:|--------:|----------------|------------------|---------------------|---------|
| 60E15120_N3J1E.bin (base) | 0x5f10c | 99 | 0x57848 | 0x5f5b0=99 (0x57854) | 0x5f5b2 (0x57a4c) | base |
| 60E0E500.bin | 0x5e4e8 | 99 | 0x56c30 | 0x5e98c=99 (0x56c3c) | 0x5e98e (0x56e34) | = base |
| 60E0E700_N3YLEE.bin | 0x5e740 | 99 | 0x56e88 | 0x5ebe4=99 (0x56e94) | 0x5ebe6 (0x5708c) | = base |
| 60E0FB00.bin | 0x5d994 | 110 | 0x55cd4 | 0x5debc=110 (0x55e04) | 0x5debe (0x55f1c) | +11 |
| 60E0FC00.bin | 0x5d994 | 110 | 0x55cd4 | 0x5debc=110 (0x55e04) | 0x5debe (0x55f1c) | +11 |
| 60E1B900.bin | 0x5dc2c | 110 | 0x55f6c | 0x5e154=110 (0x5609c) | 0x5e156 (0x561b4) | +11 |
| 60E1C500_N3J6EB.bin | 0x5e7b8 | 99 | 0x56ef4 | 0x5ec5c=99 (0x56f00) | 0x5ec5e (0x570f8) | = base |
| 60E1D400.bin | 0x5fb48 | 99 | 0x58284 | 0x5ffec=99 (0x58290) | 0x5ffee (0x58488) | = base |
| 60E32000_N3M5E.bin | 0x651bc | 113 | 0x5d1ac | 0x65708=113 (0x5d1b8) | 0x6570a (0x5d3c8) | +14 |
| 60E32000_N3N5EB.bin | 0x64d0c | 110 | 0x5ccc4 | 0x65234=110 (0x5cdf4) | 0x65236 (0x5cf0c) | +11 |
| dumps/60E0G500_N3ZHEC.bin (60E0G500/N3ZHEC) | 0x5f8b0 | 99 | 0x57fec | 0x5fd54=99 (0x57ff8) | 0x5fd56 (0x581f0) | = base |

Every ROM also has exactly one function whose 20-byte prologue matches the base
dispatcher 0x5774c and whose literal pool contains the table address (e.g. 60E0FC00
dispatcher 0x55c14, 60E0G500 dump dispatcher 0x57ef0) — the pool reference is the
diag22 scanner's, not a coincidental data word. The sub-PID table (count byte + 2,
36 × 6-byte records `{u16 pid, u8 supported_bit, u8 sub, u16 mask}`) is pool-referenced
in all 11 ROMs and carries the identical 36-PID list as the base (0x5f5b2).

Full per-ROM detail incl. SHA-256, count-pool refs and extra/missing PID lists:
[`cross_rom_mode22_summary.json`](../../../../data/labels/cross_rom_mode22_summary.json).

Two firmware families plus one outlier:

- **Family A** (60E0E500, 60E0E700, 60E15120, 60E1C500, 60E1D400, 60E0G500 dump):
  identical 99-PID set as the base ROM (0 extra, 0 missing).
- **Family B** (60E0FB00, 60E0FC00, 60E1B900, 60E32000_N3N5EB): 110 records, all 99
  base PIDs present **plus 11 extra**: 0x0001, 0x0041, 0x17f4, 0x17f5, 0x17f7, 0x17f8,
  0x17f9, 0x17fa, 0xd100, 0xe6f2, 0xe6f3 (availability mask 0xfffe vs base 0xfffc).
- **60E32000_N3M5E**: 113 records, same 11 extras plus 0x172e, 0x1730, 0x173b.

Note correcting the ROADMAP pointer: "0x5fa0c-area in 60E0FC00" — 0x5fa0c is the
PID 0x0043 *record* address in the 60E0G500 dump's table (0x5f8b0 + 29×12); the
60E0FC00 Mode 22 table is at **0x5d994** (pool ref 0x55cd4; dispatcher at 0x55c14,
unique prologue match of base 0x5774c).

## Handler mapping (1,147 record rows in `cross_rom_mode22_pid_handlers.tsv`)

| map_method | meaning | count |
|---|---|---|
| base | 60E15120 self | 99 |
| byte_match | handler body unique-exact-matches a base function, re-verified from raw bytes, asserted == base handler of the same PID | 793 |
| pid_match | handler address not byte-matched, but the PID exists in base with the same response_len → semantic label inherited, address link NOT asserted | 494 |
| unmapped | PID not present in base ROM (family-B/N3M5E extras) — address only, FUN_-level | 58 |

- Family A: 98/99 byte_match + 1 pid_match (PID 0xc116 DTC state-machine thunk — its
  body pool moved in every non-base family-A ROM, so no byte match; PID+len match).
- Family B: 99 pid_match + 11 unmapped per ROM. The diag block moved wholesale in
  these ROMs, so handler bodies contain pc-relative pool words that differ and do
  not unique-match (consistent with the lower function-match counts for
  60E0FB00/60E0FC00/60E1B900 in
  [cross_rom_differential_labeling.md](cross_rom_differential_labeling.md)).
- 60E32000_N3M5E: 9 byte_match + 90 pid_match + 14 unmapped.
- A masked-opcode similarity match for the family-B handlers was prototyped and
  **rejected as evidence** (short handlers false-positive at distance 0); it is not
  used anywhere in the artifacts.

## Dynamic validation (emulator)

Booted profile `60E0G500_N3ZHEC` (dump table 0x5f8b0, dispatcher 0x57ef0 — prologue
byte-match of base 0x5774c; this ROM's diag RAM cells differ, pool-verified: PID
cell 0xffffd226, response-code 0xffffd224, permission mask 0xffffd3f0) and drove
the ROM's own dispatcher per PID with `stop_at=(mapped handler,)`:

- **Full sweep: all 99/99 PIDs** land exactly on the mapped handler address from
  `cross_rom_mode22_pid_handlers.tsv`, and a second run per PID returns
  r0 = response_len + 3 (e.g. 0x0043 → **0x5732e**, r0 = 5; 0xe611 → **0x57d00**,
  r0 = 27).
- **Negatives: 5/5 non-table PIDs** (0x0008, 0x0009, 0x1234, 0xffff, 0xe612) take
  the NRC 0x31 path (r0 = 3) and return without reaching any handler.

The extracted table→handler map is exactly what the firmware executes.

## New emulator finding (register candidate E8)

`opdec.OPMNEM` is a full-16-bit-word table generated from the 60E15120 corpus
(9,902 entries). Family-B ROMs contain operand encodings absent from that corpus —
verified instance: 60E0FC00 dispatcher 0x55c14 executes `0xda29`
(`mov.l @(0x29*4,pc),r10`, pool word 0x55cd0) at 0x55c28 → `UnknownOpcode`
(0xda29 occurs nowhere in the base ROM bytes). Quantified over the code region
0x40–0x6c000: 467 (60E0FB00/60E0FC00), 499 (60E1B900), 888 (60E32000_N3N5EB), 767
(60E32000_N3M5E) distinct `mov.l @(disp,pc)` words missing from OPMNEM (upper bound —
the count includes pool/data words, not only instructions). Family-B profiles boot
to the idle loop (0x3dac) because the boot path avoids those encodings, but the diag
dispatcher cannot be executed dynamically until the opcode table covers them
(masked decode or a wider corpus). Recorded as open E8 in the ROADMAP register; no
emulator change made here.

## Limits

- `pid_match` rows inherit the base PID's semantic label/alias because PID +
  response_len + record format match; the handler *address* equality with the base
  handler is not asserted for these rows (`base_handler_address` empty).
- Family-B extra PIDs (0x0001, 0x0041, 0x17f4–0x17fa subset, 0x172e/0x1730/0x173b,
  0xd100, 0xe6f2, 0xe6f3) have no base-ROM counterpart — addresses recorded,
  unlabeled (FUN_-level), per the label ladder.
- Sub-PID supported-bit table at `count_byte + 2` in every ROM (base 0x5f5b2);
  verified pool-referenced in all 11 ROMs with the identical 36-PID list — contents
  not re-analyzed record-by-record cross-ROM.

## Applied to the decompiled export (D item 3)

`utilities/scripts/apply_cross_rom_labels.py` propagated the names into
`reverse-engineered/decompiled/60E0G500_N3ZHEC/`: 236 renames (262 byte-match
aliases, 28 skipped as non-function-starts, + the two table labels
`tbl_diag22_dispatch_records_0005f8b0` / `tbl_diag22_subpid_supported_bits_0005fd56`),
rewriting `function_index.tsv` / `callgraph.tsv` / `symbols.tsv` / `functions/*.c` /
`firmware_decompiled.c` and emitting the synchronized `named/` view
(`firmware_named.c`, `lookup_aliases.tsv`, `validation.json`). Handler 0x57e66
(PID 0xc116, pid_match) is a mid-function address with no C identifier — recorded
as `diag22_pidc116_dtc_state_machine` in
`data/labels/60E0G500_N3ZHEC/cross_rom_renames_applied.tsv` only. Per-ROM Mode 22
TSVs for all 11 ROMs: `data/labels/cross_rom/mode22/`. Pre-change export backup:
`docs/investigations/60E0G500_N3ZHEC/backups/pre_crossrom_names.zip` (LFS).
Checks: ROM SHA-256 unchanged, all function bodies intact in the canonical C,
renamed definitions present, names unique/valid/non-colliding, comments untouched.

## Artifacts

- `utilities/scripts/cross_rom_mode22_map.py` — locator + mapper (asserts: base
  SHA-256, 99/99 named-TSV cross-check, unique table candidate + pool ref, unique
  self-consistent count, handlers in code range, byte_match re-compare + same-PID
  assertion, response_len equality for pid_match).
- `data/labels/cross_rom_mode22_pid_handlers.tsv` — 1,444 rows (rom × record).
- `data/labels/cross_rom_mode22_summary.json` — per-ROM locations, pool refs, PID
  diffs, mapping stats, SHA-256.

Related: [uds_mode22_dispatch_report.md](../uds_mode22_dispatch_report.md) (base-ROM
table semantics, dispatcher 0x5774c),
[cross_rom_differential_labeling.md](cross_rom_differential_labeling.md) (function
byte-matches used here).
