# Extracted DTC (diagnostic trouble code) tables per ROM

New folder proposed with the DTC deep dive (2026-11): the per-ROM DTC engine
tables extracted from the ROM binaries at binary level, plus the audit of the
RomRaider defs' `DTC xxxx Enable/Disable #N` tables against them.

## Files

- `<rom-id>.tsv` — one row per DTC **slot** (0x00..0x8b, 140 slots in all
  inspected ROMs): the OBD DTC code (big-endian u16 from the code table), the
  three enable/disable calibration bytes, the def-side `#1` code bound to that
  slot (if any) and whether it matches, and the absolute addresses of the code
  and enable#1 bytes.
- `defs_audit.tsv` — per ROM and per def suffix (#1/#2/#3): number of def
  entries, how many mismatch the ROM code at their slot, how many fall outside
  the slot range, and examples. Audited against
  `data/definitions/romraider/per-rom/*.xml`.

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

## Provenance

- ROMs: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/*.bin`
  (60E15120_N3J1E SHA-256 a7cd953c…f264f1) and our own
  `binaries/dumps/60E0G500_N3ZHEC.bin` (see `binaries/manifest.csv`).
- Defs: `data/definitions/romraider/per-rom/*.xml` (reviewed per-ROM copies).
- Extraction script: `docs/investigations/60E15120_N3J1E/reviews/dtc_control/`
  (see `REVIEW_NOTES.md`); report:
  `docs/investigations/60E15120_N3J1E/dtc_control_report.md`.
