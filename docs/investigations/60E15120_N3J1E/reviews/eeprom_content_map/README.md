# Review evidence — 93C56 EEPROM content map (60E15120_N3J1E)

Companion to [`../../eeprom_content_map_report.md`](../../eeprom_content_map_report.md).
Labels: `data/labels/60E15120_N3J1E/eeprom_content_labels.json`.
Re-runnable checks: `tests/test_eeprom_content_map.py`.

## Artifacts

- `annotated_dumps.txt` — both upstream 256-B dumps
  (`submodules/Mazda_RX8_PCM_ReverseEngineering/Data_binaries/RX8_93c56_ECU_IC420_Read.bin`
  SHA-256 `64b13ddf353a06976729114179204f56b7a2869ea891f3f9d9400a2a56d205e3`;
  `se3p_ecm_eeprom.bin` SHA-256 `d7f4bb0a289f086610d8a9aafac58f6329b96c5be96ec75f7aef7418cf77c264`)
  hex + ASCII with per-region annotations.
- `validation.json` — validator/pytest results for this pass.
- Decoder: `utilities/scripts/decode_eeprom.py` turns any 256-B dump into the
  annotated map (text or `--json`, optional `--compare`); covered by
  `tests/test_decode_eeprom.py`.

## What was checked (binary level, this session)

1. Dump facts (re-read from the raw dump files): 256 B each; word0 `5a ff` in
   both; RX8 VIN `JM1FE173940102548` at 0x80–0x90 (SE3P `SE3P104621` + spaces);
   0x95 = `2a` (`*`) in both; tire revs u16 `0x030d` = 781 at 0x9a in both;
   ID-string chars `13H`/`6`/`020` (RX8) vs `13H`/`6`/`0A0` (SE3P) at
   0x64–0x6c; 0x9f = `fe` (RX8) / `ff` (SE3P); 0xa0–0xfb all `ff` in both;
   tail 0xfc–0xfd differ per ECU, 0xfe = `ff`, 0xff = `30` in both; no `a5 5a`
   / `5a a5` anywhere in either dump (so the 28-u16 PLDR/ISR block magic
   `0xa55a` is NOT inside the IC420 image).
2. RX8-vs-SE3P diff offsets: 0x02–0x09, 0x16–0x19, 0x20–0x5f (learned table,
   incl. 0x37/0x39/… odd flag bytes), 0x60, 0x62, 0x6b, 0x80–0x90 (VIN),
   0x9f, 0xfc, 0xfd — i.e. key, immo code, learned table, ID char 0x6b, VIN,
   config bit, tail.
3. ROM pool/disassembly facts (re-read from the raw ROM +
   `firmware_disassembly.asm`): magic pools 0xd4ea = 0x55aa, 0xd4f4 =
   0x0000aa55, 0xd4f0 = 0xffff8000, 0xd4ec = 0xffffa3fb; call pools 0x6288 =
   0xd44c (in `ref_mainInit__` 0x61a8), 0x63e8 = 0xd408 (in 0x6372),
   0x63dc = 0x11492, 0x11674 = 0x3e020, 0x11678 = 0xd2e8; boot-param table of
   `e2ram_boot_param_read` 0x3599c = 19 `e2ram_cached_byte_read` calls with
   indices 1,0,2,6,0xa,0xc,0xd,0xe,0xf,0x10(len 2),0x16(len 2),0x18,0x12,0x13,
   0x14,0x1a,0x1b,0x1c,0x1d → dests 0xffffc268–0xffffc282 (+0xffffc1d2-d4);
   immo reads in 0x375c0 = device words 0x6010000, 0x6020000, 0x6030000,
   0x6040000, 0x6050000, 0x60b0000, 0x60c0000; learned-table affine pools
   0x27c80 = 0xc27c0000 (−63.0), 0x27c84 = 0x3f000000 (0.5); 0x27b8e bulk
   (0x20,0x44) + 0x22-iteration decode loop; 0x279d8 reverse + flush
   0x378dc(0x20,0x44,3); 0x5b5d4 = read(0x80, buf, 0x80) + UDS response 0x80;
   0x55b18 reads 0x64/3, 0x68/1, 0x6a/2, 0x6c/1; 0x543e4 reads 0x95 vs `*`;
   0x5de74 reads 0x9a len 2; 0x5b704 reads 0x6e len 9; 0x5b482 bulk
   (100, 0x9c); 0x35956 bulk (0, 0x20); 0x5e8a4 writes 0x78; 0x4b5b6 bulk
   (0x7a, 2).
4. RAM-window reference scan: 241 pc-relative `mov.w`/`mov.l` literals land in
   0xffff8000–0xffff80ff (38 distinct offsets: 0x00,0x01,0x04,0x2c,0x2d,0x30,
   0x38,0x40,0x48,0x50,0x52,0x54,0x58,0x5a,0x5c,0x5e,0x60,0x68,0x70,0x78,
   0x7c,0x84,0x8c,0x94,0x9c,0x9e,0xa0,0xa2,0xa4,0xac,0xb4,0xbc,0xc4,0xe4,
   0xec,0xf4,0xfc), parsed from instruction operands only (raw u32 scans pick
   up cal-region false positives, e.g. 0x7ab7a).
5. Emulator idle boot (profile 60E15120_N3J1E, 2M cycles, pc parks at 0x3dac):
   0xffff8000–0xffff80ff remains zero — the window is not bulk-filled at idle,
   matching the free-resources report §10 idle-free scan.

## Learned-table decode of the RX8 dump (value = −63 + raw*0.5)

```
pair @0x20..0x63 (34 pairs): (raw, flag) -> value
 0: (81,01)->+1.5   1: (80,01)->+1.0   2: (7e,01)->0.0    3: (7b,01)->-1.5
 4: (76,01)->-4.0   5: (74,01)->-5.0   6: (71,01)->-6.5   7: (6a,01)->-10.0
 8: (67,01)->-11.5  9: (5d,01)->-16.5 10: (59,01)->-18.5 11-16: (7e,00)->0.0 flag 0
17: (81,01)->+1.5  18: (80,01)->+1.0  19: (80,01)->+1.0  20: (7a,01)->-2.0
21: (74,01)->-5.0  22: (72,01)->-6.0  23: (70,01)->-7.0  24: (69,01)->-10.5
25: (67,01)->-11.5 26: (5e,01)->-16.0 27: (5a,01)->-18.0 28: (50,01)->-23.0
29: (4b,01)->-25.5 30: (3b,01)->-33.5 31: (24,01)->-45.0 32-33: (7e,00)->0.0 flag 0
```

## Open questions carried to the report §9

- chip 0xfc–0xfd per-ECU tail u16: no ROM consumer found (candidate serial).
- chip 0x6e–0x76 (9 B) and 0x70–0x7f: served raw / written via specific paths,
  semantics open.
- PLDR/ISR 28-u16 device vs IC420: separate device at the data level; board
  routing unresolved.
