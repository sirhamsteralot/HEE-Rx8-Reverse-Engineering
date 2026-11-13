# Extracted DTC (diagnostic trouble code) tables per ROM

Per-ROM DTC engine tables extracted from the ROM binaries at binary level, plus
the audit of the RomRaider defs' `DTC xxxx Enable/Disable #N` tables against
them.

## Files

- `<rom-id>.tsv` — one row per DTC **slot** (0x00..0x8b, 140 slots in all
  inspected ROMs): the OBD DTC code (big-endian u16 from the code table), its
  standard 5-char form (`obd_code` column, e.g. `P0420`), the three
  enable/disable calibration bytes, the def-side `#1` code bound to that
  slot (if any) and whether it matches, and the absolute addresses of the code
  and enable#1 bytes.
- `defs_audit.tsv` — per ROM and per def suffix (#1/#2/#3): number of def
  entries, how many mismatch the ROM code at their slot, how many fall outside
  the slot range, and examples. Audited against
  `data/definitions/romraider/per-rom/*.xml`.
- `pcodes.tsv` — the 4-hex ROM code → standard 5-char OBD code mapping for every
  code used by any ROM (136 codes, incl. the P0301/P0302 rotor-misfire prefix
  codes held at 0x7e55a), with class (P0/P2 generic, P1 manufacturer-specific,
  U0 generic), the **Mazda workshop-manual condition** (`mazda_manual_description`,
  preferred in def descriptions — vehicle-specific wording, e.g. P0335 = eccentric
  shaft position sensor, P2004 = APV stuck open) and the **SAE J2012** description.
  Sources: Mazda manual `input/4EngineControl.pdf` ("RX8 – Engine Diagnostics &
  Control", 2003, DTC TABLE section — parsed to `mazda_dtc_table.tsv`);
  `tekseport/obd2-codes` `obd2-codes.csv` @ `ddadc77e` + `foerbsnavi/OBDex`
  `data/generic/*_enriched.yaml` @ `3f03bb0` (cross-checked).
  Decode rule (SAE J2012 / ISO 15031-6; the ROM stores the two mode-03 response
  bytes as BE u16): byte0 bits 7-6 → letter (P/C/B/U), bits 5-4 → second digit
  (0/2 SAE-generic, 1/3 manufacturer), low 12 bits → last 3 hex digits. So
  `0420` → **P0420**, `2504` → P2504, `1260` → P1260 (manufacturer-specific, no
  SAE text), and `C167` → **U0167** (network — 0xC0>>6 = U, not chassis).
  Implemented in
  `utilities/scripts/defs-merge/dtc_names.py`.
- `mazda_dtc_table.tsv` — the DTC TABLE of `input/4EngineControl.pdf` parsed to
  `obd_code, mazda_manual_condition` (118 codes). The 2003 manual predates some
  J2012 codes the ROMs carry (P0116, P0134, P0137, P0351-0354, P0411, P0444,
  P0445, P050A, P2009, P2010, P2016, P2067, P2068, P2102, P2103 — those keep
  their SAE text only); P0301/P0302 appear in the manual but in the ROM live in
  the 0x7e55a prefix table, not the slot table. Note U0167: SAE generic says
  immobilizer module, the Mazda manual says keyless control module — Mazda's
  assignment wins for the RX-8.

## ROM layout (verified at byte level; 60E15120_N3J1E addresses shown)

| Table | 60E15120_N3J1E | Content |
|---|---|---|
| misfire special prefix | 0x7e55a | BE u16 P0300, P0301, P0302 (prepended by mode 03 builder) |
| DTC code table | 0x7e560 + 2*slot | BE u16 OBD code per slot; 0xffff = unused slot |
| enable/disable #1 | 0x7e678 + slot | u8 cal byte, 1 = DTC evaluated/reported (filter arg 1) |
| enable/disable #2 | 0x7e704 + slot | u8 cal byte (filter arg 2; used by Mode 03 stored-DTC list) |
| enable/disable #3 | 0x7e790 + slot | u8 **bitmask** of reporting features (faultEnableStatus2 masks 0x02/0x04/0x08/0x10/0x20) |
| DTC type | 0x7e32a + slot | u8 0/1/2/3 — selects the confirmation/aging state machine |
| id→slot map | 0x7df42 + 2*id | BE u16 slot for each internal fault id |
| confirmation mask | 0x7e81c + 2*slot | BE u16 mask (faultConfirmationSomething_) |
| status/availability mask | 0x7e934 + 4*slot | BE u32; low16 ANDed with RAM 0xffffd930, high16 with FUN_00066a58() mask (getFaultStatus 0x66a00) |
| related-DTC/type nibbles | 0x7e06c + 4*slot | 4-byte records used by FUN_0005ff5a |

RAM (volatile) counterparts: master 21-entry table 0xffff87b0 (0x10 B/entry:
u16 slot at +0, state byte at +6), stored-flag table 0xffffd570[0x8c],
state array 0xffffd5fc[0x8c], eval-state 0xffffd458[0x8c],
transition state 0xffffd4e4[0x8c], first-stored code 0xffffd3c0, MIL flag
0xffffd286, DTC-eval-enable 0xffffd688.

DTC state-byte encoding observed in scanners 0x61450/0x615c6:
0x00 inactive; 0x01..0x3f active/pending ("0x60" query); 0x40..0x7f (0x50
query); 0x80..0xbf stored/MIL ("0x80-bit" query); 0xc0/0xc1 confirmed
variants; FUN_00061800 maps master state 1..0x3f → 0x60 and 0x80..0xbf → 0x70
for the 0xffffd5fc mirror array.

## Defs status

The `def_match` column and `defs_audit.tsv` reflect the **repaired** per-ROM defs
(`repair_dtc_tables()` in `utilities/scripts/defs-merge/extend_defs_all_roms.py`):
0 mismatches across all ROMs for #1/#2/#3. (A pre-repair audit — with the wrong
blocks for 60E0E700/60E1B900/60E32000_N3M5E/60E0FB00/60E1D400 — is preserved in
`docs/investigations/60E15120_N3J1E/reviews/dtc_control/defs_audit_detail.json`.)

The def tables are also **P-code labeled**: every
`DTC xxxx Enable/Disable #N` entry in the per-ROM defs and in all active blocks
of `rx8defs-merged-60E15120.xml` is named with the standard 5-char OBD code
(`DTC P0420 Enable/Disable #1`, `DTC U0167 ...`; P0300's two slots get
`[additional site 0x...]` suffixes). Rename tooling:
`utilities/scripts/defs-merge/relabel_dtc_names.py` (merged def, surgical) +
`repair_dtc_tables()` at per-ROM generation time (names + short rule-6b
descriptions); stats in
`docs/investigations/60E15120_N3J1E/labeling/defs-merge/dtc_pcode_labels_2026-11-03.json`.
Audit: 0 mismatches (`defs_audit.tsv`;
the audit compares decoded u16 codes, so both naming forms audit identically).
Tests: `tests/test_dtc_pcode_labels.py`. See
[dtc_control_report.md §5b](../../docs/investigations/60E15120_N3J1E/dtc_control_report.md).

## Provenance

- ROMs: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/*.bin`
  (60E15120_N3J1E SHA-256 a7cd953c…f264f1) and our own
  `binaries/dumps/60E0G500_N3ZHEC.bin` (see `binaries/manifest.csv`).
- Defs: `data/definitions/romraider/per-rom/*.xml` (reviewed per-ROM copies).
- Extraction script: `docs/investigations/60E15120_N3J1E/reviews/dtc_control/`
  (see `REVIEW_NOTES.md`); report:
  `docs/investigations/60E15120_N3J1E/dtc_control_report.md`.
