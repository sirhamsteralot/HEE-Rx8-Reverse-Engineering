# E2RAM non-volatile storage (learned values + DTC history) report — 60E15120_N3J1E

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/e2ram_nv_storage_labels.json`.

**Related reports:** E2RAM read/write layer `ref_getDataFromE2RAM` 0x3599c /
`ref_writeToE2RAMArea_INDEX_ADDR_LEN` 0x37ea4 (inherited `ref_` — unverified hypothesis)
and the knock-learn consumer 0x139c4 in
[`knock_control_report.md`](knock_control_report.md); DTC engine (set_fault thunk
0x5fd38, stored-flag table 0xffffd570) in
[`dtc_control_report.md`](dtc_control_report.md); OS boot/init ordering in
[`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md).

## 1. Executive summary

The PCM keeps a **28-u16 non-volatile block in the external E2RAM (EEPROM on the
PLDR/ISR port lines)**: magic 0xa55a, 26 payload u16 (learned values + packed DTC
history flags), and a checksum (sum of the first 27 u16) at +0x36. Two of the
seven large unlabeled bodies are its codec: **0x23844** (1,562 B) decodes the raw
stored block into working RAM (affine u16/u8 decodes + bit-unpack of the DTC flag
bytes), and **0x244bc** (1,408 B) encodes the live working RAM back into the
staging block (saturating affine encodes + packing the current fault bits).
Wrappers 0x2376c (load: decode + DTC replay via 0x23f4e) and 0x2377a (save:
collect + encode) are driven by 0x235c8/0x235f8 (load/verify after boot, from
0x1102a/0x114d0) and 0x236cc (save, from 0x1150e).

## 1a. Plain-language summary

Some things the PCM learns while driving (and the history of which fault codes
have occurred) are kept in a small external EEPROM so they survive key-off. At
startup the PCM reads that block, checks a magic number and a checksum, unpacks
it into RAM and re-registers the stored fault codes. Periodically (or on the save
trigger) it packs the current values and fault bits back, adds the magic and
checksum, and writes the block out again.

## 2. How it works (condensed pseudocode)

```
# block layout (28 u16 = 0x38 bytes): u16[0]=magic 0xa55a, u16[1..26]=payload, u16[27]@+0x36 = sum(u16[0..26])
# E2RAM primitives: 0xb99c read (waits PLDR_W bit 0x1000, ISR_W=0xf7, error -> 0xffffa320),
#                   0xb958 readback, 0xb886 write (u16-counted)

# load/verify (boot path 0x1102a -> 0x23740 -> 0x235c8; 0x114d0 -> 0x2374e -> 0x235f8)
0x235c8: 0xb99c(&0xffffb440, &0xffffb478, 0x1c); on ok -> 0x2376c else 0xffffb43c=1
0x235f8: 0xb958(&0xffffb478, 0x1c); check magic 0x5aa5 (byte-swapped) at 0xffffb478,
         checksum sum of 0x1b u16 vs word at +0x36; ok -> 0x2376c else 0xffffb43a=1
0x2376c (e2ram_load_decode_entry): 0x23844(); 0x23f4e()

# 0x23844 e2ram_block_decode: payload from 0xffffb47a
  b4b0/b4 = decode_u16_affine(raw 0xffffb47a/0x47c, step 0x3cfa0000 = 0.030517578125, pool 0x23918)
  b4c0/c4/c8 = decode_u16_affine(raw 0xffffb498/49a/49c, step 0x38a00000 = 7.62939453125e-05, pool 0x24004)
  b4b8 = decode_u8_affine(raw 0xffffb488, 0x3da00000 = 0.078125, pool 0x23938); b4bc = signed decode (0x3f480000 = 0.78125, pool 0x2393c, sign = bit7 of 0xffffb489)
  b4cc..b4db = raw bytes 0xffffb47e..0xffffb497
  flags b4ec..b51b = bit-unpack of 7 bytes 0xffffb48a..0xffffb490 via 0x24b00 (20-byte helper)
0x23f4e (e2ram_stored_dtc_replay): 38 calls 0x5fd38(id, 1|2) from flags b4ec..b51b

# save (0x1150e -> 0x23766 -> 0x236cc)
0x236cc: 0x2377a()                      # 0x242ae collect (18x ref_getFaultStatus__ 0x66a00) + 0x244bc encode
         mov.w 0xa55a -> 0xffffb440    # magic (pool 0x23734, at 0x236ec)
         checksum = sum 0x1b u16 -> +0x36 (loop 0x236f0-0x236fe)
         0xb886(0xffffb440, 0x1c)      # write 28 u16; success -> 0xffffb43b = 1

# 0x244bc e2ram_block_encode: b442/b444 = enc(b40c, 0x3cfa0000, pool 0x2452c); b446 = signed enc(b414);
#   b448 = enc(b594, 0x39a00000 = 0.00030517578125, pool 0x24684); b44a/b44c = enc(readValue_float of 0xffff807c/0xffff8084);
#   b44e = pedal volts 0xffffa9c4; rpm 0xffffb548 (step 0x3e480000 = 0.1953125, pool 0x24b40); fault bits -> b459..b45b
```

## 3. Key calibrated tables

None — the block is raw encoded values with fixed affine steps, not descriptor
tables. Literal-pool floats referenced from the codec (ROM-verified):
0x3cfa0000 = 0.030517578125 (pools 0x23918/0x2452c/0x2467c/0x24b30),
0x38a00000 = 7.62939453125e-05 (pool 0x24004), 0x3da00000 = 0.078125 (0x23938),
0x3f480000 = 0.78125 (0x2393c), 0x39a00000 = 0.00030517578125 (0x24684),
0x3b800000 = 0.00390625 (0x24b3c), 0x3e480000 = 0.1953125 (0x24b40).

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x23844 | `e2ram_block_decode` | high |
| 0x244bc | `e2ram_block_encode` | high |
| 0x2376c | `e2ram_load_decode_entry` | high |
| 0x2377a | `e2ram_save_encode_entry` | high |
| 0x23f4e | `e2ram_stored_dtc_replay` | high |
| 0x242ae | `e2ram_fault_status_collect` | high |

RAM aliases: `e2ram_staging_block` (0xffffb440), `e2ram_read_staging` (0xffffb478),
`e2ram_payload_raw` (0xffffb47a), `stored_dtc_flag_bits` (0xffffb4ec). Evidence in
`source_review/accepted_{function,ram}_aliases.tsv` and
`data/labels/60E15120_N3J1E/e2ram_nv_storage_labels.json`.

## 5. Corrections made in this pass

None — previously unlabeled. The knock-learn EEPROM path (0x139c4) uses the same
E2RAM layer per the knock report; this pass documents the shared block codec.

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/00023844_*.c`,
  `000244bc_*.c`, `0002376c_*.c`, `0002377a_*.c`, `00023f4e_*.c`, `000242ae_*.c`
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/e2ram_nv_storage_labels.json`

## 7. Validation

- Binary-level (disassembly of 0x236cc): magic write `mov.w` via pool 0x23734
  (u32 = 0x0000a55a) at 0x236ec to 0xffffb440 (r14 from `mov.w` pool 0x23726 =
  0xb440 sign-extended at 0x236e4); checksum loop 0x236f0–0x236fe sums 0x1b
  (r6) u16 into r7, stored at +0x36 (r0=0x36, 0x23708); write via jsr pool 0x23738
  = 0xb886 with r5 = 0x1c; jsr pool 0x2372c = 0x2377a; flag write 0xffffb43b
  (pool 0x23728 word 0xb43b). Load-side magic 0x5aa5 and checksum in 0x235f8;
  call sites pool 0x237bc (0x23844) / 0x237c8 (0x244bc). Scripted checks 62/62 PASS.
- `validate_reports.py` / `verify_claims.py` / `validate_export.py`; `tests/test_e2ram_nv_storage.py`.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x00023844 | `e2ram_block_decode` | raw block → working RAM |
| 0x000244bc | `e2ram_block_encode` | working RAM → staging block |
| 0x0002376c | `e2ram_load_decode_entry` | decode + DTC replay |
| 0x0002377a | `e2ram_save_encode_entry` | collect + encode |
| 0x00023f4e | `e2ram_stored_dtc_replay` | 38 set_fault calls from stored flags |
| 0x000242ae | `e2ram_fault_status_collect` | 18× `ref_getFaultStatus__` 0x66a00 |
| 0x000235c8 / 0x000235f8 / 0x000236cc | `FUN_000235c8` / `FUN_000235f8` / `FUN_000236cc` | load / verify / save drivers |
| 0x00023740 / 0x0002374e / 0x00023766 | `FUN_00023740` / `FUN_0002374e` / `FUN_00023766` | callers from boot/init (0x1102a/0x114d0/0x1150e) |
| 0x0000b99c / 0x0000b958 / 0x0000b886 | `FUN_0000b99c` / `FUN_0000b958` / `FUN_0000b886` | E2RAM read / readback / write primitives |
| 0x00024b00 | `FUN_00024b00` | 20-byte bit-unpack helper |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x237bc / 0x237c8 | pool words = 0x23844 / 0x244bc |
| 0x23726 / 0x23734 / 0x23738 / 0x2372c / 0x23728 | pool words: 0xb440 (base), 0xa55a (magic), 0xb886 (write), 0x2377a, 0xb43b (ok flag) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffb440 | `e2ram_staging_block` | 28-u16 block: magic, payload, checksum @+0x36 |
| 0xffffb478 | `e2ram_read_staging` | read landing buffer (magic checked as 0x5aa5) |
| 0xffffb47a | `e2ram_payload_raw` | decode source bytes |
| 0xffffb4ec–0xffffb51b | `stored_dtc_flag_bits` | unpacked DTC history flags |
| 0xffffb4b0–0xffffb4c8 | `DAT_ffffb4b0`–`DAT_ffffb4c8` | decoded learned values |
| 0xffffb43a / … / 0xffffb43e | `DAT_ffffb43a` … `DAT_ffffb43e` | verify-invalid / saved-ok / load-fail / magic-bad / checksum-bad |
| 0xffffa320 | `DAT_ffffa320` | E2RAM hardware error flag (0xb99c) |

## 9. Limits

- Static analysis only. Which learned value each payload u16 holds is only
  partially known (rpm 0xffffb548 step 0.1953125, pedal volts 0xffffa9c4, two
  readValue floats, plus the DTC flag bytes); the remaining cells are not
  individually attributed in this pass.
- The E2RAM device protocol (PLDR_W/ISR_W bit-banging in 0xb99c/0xb886) is
  described only at the level needed here; the deeper layer is covered by 0x3599c/0x37ea4.
- Save cadence/trigger (who calls 0x1150e) was not traced beyond the callgraph.
