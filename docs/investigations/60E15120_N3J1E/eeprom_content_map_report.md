# 93C56 EEPROM (IC420) full content map — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes, plus the two upstream 256-byte EEPROM dumps
(never modified). No hardware execution was performed. Labels recorded in
`data/labels/60E15120_N3J1E/eeprom_content_labels.json`; detailed evidence in
[`reviews/eeprom_content_map/`](reviews/eeprom_content_map/README.md) (incl.
[`annotated_dumps.txt`](reviews/eeprom_content_map/annotated_dumps.txt)).

**Related reports:** device protocol + RAM shadow layer in
[`e2ram_device_layer_report.md`](e2ram_device_layer_report.md); the 28-u16
learned/DTC-history block on the separate PLDR/ISR interface in
[`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md); memory-map context
in [`docs/architecture/flash-memory-layout.md`](../../architecture/flash-memory-layout.md)
§2/§5; knock-learn consumer in [`knock_control_report.md`](knock_control_report.md);
idle-trim cells in [`idle_control_report.md`](idle_control_report.md); UDS/Mode 22
window in [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md);
free-window scan in [`labeling/free_resources_report.md`](labeling/free_resources_report.md) §10.

## 1. Executive summary

The external **93C56 serial EEPROM (IC420, 256 B = 128 u16 words)** is fully
mapped now. It is talked to over **SCI4** (registers 0xfffff022–0xfffff025)
with chip-select on `PFDR_W` 0xfffff74e bit 0x400 and a busy input on
`PBDR_W` 0xfffff738 bit 0x800; device word *w* is addressed as the frame
`0x6000000 + w*0x10000`, so **chip byte *i* = high byte of word *i*/2 when *i*
is even**. Firmware never memory-maps the chip: reads go through a 256-byte
RAM shadow cache at `0xffffc28e` (+ complement `0xffffc38e`) via
`e2ram_cached_byte_read` 0x37ef0 / `e2ram_bulk_read_into_shadow` 0x37cd8.

The 256 bytes break down as:

| Offset | Content | RX8 dump value | Firmware evidence |
|---|---|---|---|
| 0x00–0x01 | device marker word | `5a ff` (both dumps) | boot param index 0, len 4 → 0xffffc26c (0x3599c) |
| 0x02–0x09 | **immobilizer secret key** (8 B, per-ECU) | `d3 d7 1a ef 41 3d 15 00` | words 0x6010000–0x6040000 in 0x375c0 |
| 0x0a–0x0b | immo status word | `01 ff` | word 0x6050000 in 0x375c0 |
| 0x0c–0x15 | config/param bytes | `00 ff 40 ff 33 ff 08 00 00 ff` | param indices 0xc–0x14 (0x3599c / 0x35a8c) |
| 0x16–0x19 | **immobilizer code/ID** (per-ECU) | `8d fd 47 da` | words 0x60b0000/0x60c0000 in 0x375c0 |
| 0x1a–0x1f | param block tail | `00 00 00 00 02 ff` | indices 0x1a–0x1e (0x3599c); bulk boot read 0x35956 |
| 0x20–0x63 | **learned-correction table**: 34 × (u8 value, u8 flag) | values −45.0…+1.5, flags 0x01/0x00 | bulk 0x20 len 0x44 by 0x27b8e / save 0x279d8 |
| 0x64–0x6d | **ECU ID string** (7 ASCII chars at 0x64-66, 0x68, 0x6a-6b, 0x6c) | `13H 6 020` | 0x55b18 (`ref_getCalID`), 0x5e664, UDS 0x5b644 |
| 0x6e–0x76 | 9-byte field (UDS-served) | erased | 0x5b704 reads 0x6e len 9 |
| 0x78–0x79 | 2-byte field | `ff 00` | written by 0x5e8a4 (shadow write 0x78) |
| 0x7a–0x7b | 2-byte field | `ff ff` | bulk 0x7a,2 in 0x4b5b6 → 0xffffce30 |
| 0x80–0x90 | **VIN** (17 ASCII) | `JM1FE173940102548` | upper half 0x80–0xff served as UDS dump by 0x5b5d4 |
| 0x95 | tire-size marker `*` | `2a` | 0x543e4: `*` → default tire size |
| 0x9a–0x9b | **tire revolutions per mile** u16 | `03 0d` = 781 | 0x5de74 (`ref_getTireSize`) reads 0x9a len 2 |
| 0x9f | config bits | `fe` (SE3P: `ff`) | bit0 read by 0x5e748 |
| 0xa0–0xfb | erased reserve | all `ff` | bulk-covered by 0x5b482 (0x64, len 0x9c) |
| 0xfc–0xfd | per-ECU tail u16 | `ff 0c` | no ROM ref this pass (candidate serial/checksum) |
| 0xfe–0xff | erased + fixed marker | `ff 30` | `0x30` in both dumps |

The RAM side has **three** structures, previously conflated: (a) the chip
shadow `0xffffc28e`/`0xffffc38e` (indexed like the chip), (b) the boot param
block `0xffffc268–0xffffc282` (decoded chip 0x00–0x1e), and (c) the
**E2/diag window `0xffff8000–0xffff92ff`** whose first 256 B
(`0xffff8000–0xffff80ff`) carry the firmware-written `0xaa55`→`0x55aa` magic
(0xd44c/0xd408) and 8-byte checksummed learned-value cells (float + 2× u16
checksum `~(lo16+hi16)`), 241 pc-relative references in the disassembly.

### 1a. Plain-language summary

The PCM has a tiny 256-byte memory chip bolted next to it that remembers
things across key-off. Reading its dump, the first bytes are a marker and an
8-byte secret key plus a code that the immobilizer checks at startup; the next
few bytes are configuration; a block of 34 small number pairs holds learned
corrections the engine has accumulated (each pair is one number plus a flag
saying whether it has been learned); further down sits a 7-character ID string
of the ECU itself; at offset 0x80 the car's 17-character VIN; near the end the
tire size setting (a `*` means "standard tire", otherwise a revolutions-per-
mile number) and a few config bits. Almost everything from 0xa0 to 0xfb is
blank. Separately, in RAM, the firmware keeps a checksummed copy area starting
at 0xffff8000 (with a 0x55aa magic) where individual learned values — knock
retard, idle trim, pedal zero — live while driving.

## 2. How it works (condensed pseudocode)

```
# chip access (SCI4 + CS/busy); word w = frame 0x6000000 + w*0x10000; chip byte i = word i>>1, even i = high byte
shadow[256] @0xffffc28e, complement[256] @0xffffc38e   # valid when data[i] == ~comp[i]
e2ram_cached_byte_read(i, &dst, len)   # 0x37ef0: shadow hit -> copy; else 0xbdfa(0x6000000+((i>>1)&0xff)*0x10000), refresh shadow
e2ram_bulk_read_into_shadow(start,len) # 0x37cd8: per-word device reads into shadow (boot: 0x35956 -> (0,0x20); 0x27b8e -> (0x20,0x44); 0x5b482 -> (0x64,0x9c))
e2ram_shadow_byte_write(i, src, len)   # 0x37ea4: shadow[i]=b, comp[i]=~b; flush via FUN_000378dc(start,len,mode) -> state machine 0x379e4 (cmd 0x4c00000 + read-back)

# boot: param block 0xffffc268-0xffffc282 <- chip 0x00-0x1e (0x3599c, 19 fields, indices 1,0,2,6,0xa,0xc,0xd,0xe,0xf,0x10(2B),0x16(2B),0x18,0x12,0x13,0x14,0x1a,0x1b,0x1c,0x1d)
# immo: 0x375c0 reads chip words 0x601..0x604 (key 0x02-0x09), 0x60b/0x60c (code 0x16-0x19), 0x605 (status 0x0a-0x0b), erased-pattern -> flags 0xffffc1d5-d8
# learned table: 0x27b8e: bulk(0x20,0x44); for i in 0..0x21: pair = chip[0x20+2i], chip[0x21+2i]
#    value = -63.0 + pair[0]*0.5  (pools 0x27c80=0xc27c0000, 0x27c84=0x3f000000)
#    -> float cells 0xffff8108+8i (+value) and 0xffff8328+8i (-value); flag (0xff->0) -> 0xffff8548+2i, 0xffff85d0+2i
#    save 0x279d8: reverse encode rx8_encode_u8_affine_saturate -> shadow_byte_write(0x20+2i) -> flush 0x378dc(0x20,0x44,3)
#    erase 0x27d06: at engine stop, 0x14 counts -> write (0.0, flag 0) pairs
# ID string: 0x55b18 builds 16-char ID = cal string + chip[0x64..0x66] + chip[0x68] + chip[0x6a..0x6b] + chip[0x6c]  (RX8: "13H6020")
# VIN/upper half: 0x5b5d4 dumps chip 0x80-0xff (128 B) as a UDS response; VIN = 0x80-0x90 (17 ASCII)
# tire: 0x543e4 checks chip[0x95]=='*' (default size); 0x5de74 reads u16 at 0x9a (tire revs/mile)
# RAM window 0xffff8000-0xffff80ff: magic 0xaa55 written by 0xd44c (mainInit 0x61a8), checked/rewritten 0x55aa by 0xd408 (via 0x6372 <- 0x60c8)
#   cells are 8 B: float32 at +0, u16 cksum at +4 and +6 = ~(lo16+hi16 of value) (0x3dc22/0x3dcd0)
```

## 3. Key calibrated data

None — the EEPROM holds fixed-format fields, not descriptor tables. The only
scaling constants are the learned-table affine pair `0x3f000000` = 0.5 and
`0xc27c0000` = −63.0 (pools 0x27c80/0x27c84, ROM-verified) giving
`value = −63 + raw*0.5` (range −63.0…+64.5, 0.5 steps), and the tire-revs
u16 read raw at 0x9a.

## 4. Labeling applied

New labels in `data/labels/60E15120_N3J1E/eeprom_content_labels.json`
(`eeprom_offsets`, `function_aliases`, `ram_aliases`):

| Address / offset | New label | Confidence |
|---|---|---|
| chip 0x02–0x09 | `eeprom_immobilizer_secret_key` | high |
| chip 0x16–0x19 | `eeprom_immobilizer_code_id` | medium |
| chip 0x20–0x63 | `e2ram_learned_correction_table` | high |
| chip 0x64–0x6d | `eeprom_ecu_id_string` | high |
| chip 0x80–0x90 | `eeprom_vin` | high |
| chip 0x95 | `eeprom_tire_size_marker` | high |
| chip 0x9a–0x9b | `eeprom_tire_revolutions_per_mile` | high |
| chip 0x9f | `eeprom_config_bits` | medium |
| 0x375c0 | `e2ram_immo_key_read` | high |
| 0x27b8e | `e2ram_learned_table_load` | high |
| 0x279d8 | `e2ram_learned_table_save` | high |
| 0x27d06 | `candidate_e2ram_learned_table_erase` | medium |
| 0x5b5d4 | `e2ram_upper_half_uds_dump` | high |
| 0x5e664 | `e2ram_ecu_id_read` | high |
| 0x5b704 | `e2ram_field_6e_uds_dump` | high |
| 0x543e4 | `e2ram_tire_size_marker_check` | high |
| 0x5de74 | `e2ram_tire_revs_read` | high |
| 0x5e748 | `e2ram_config_bit_9f_read` | medium |
| 0x5b482 | `e2ram_tail_bulk_read` | high |
| 0xd408 / 0xd44c | `eeprom_mirror_magic_check` / `eeprom_mirror_magic_init` | high |
| RAM 0xffff8000 | `eeprom_mirror_magic` | high |

## 5. Corrections made in this pass

- The `0x55aa`/`0xaa55` magic at RAM `0xffff8000` is **firmware-written**, not
  read from the chip: the chip's first word is `0x5aff` in both upstream
  dumps. 0xd44c (called from `ref_mainInit__` 0x61a8) writes `0xaa55`; 0xd408
  (called from 0x6372 ← `ref_getSensorStuff__` 0x60c8) checks for `0xaa55`,
  runs the validate fan-out 0x11492 → 0x3e020, and rewrites `0x55aa`.
- `ref_grablast28ByteFromE2` 0x5b5d4 does **not** grab "the last 28 bytes":
  it reads chip **0x80 len 0x80 (128 B)** and returns all of it as a UDS
  response (the VIN lives at the start of that range).
- The 28-u16 block of [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md)
  (magic `0xa55a`, PLDR/ISR bit-bang) does **not** appear anywhere in the 256-B
  IC420 dumps (byte scan for `a5 5a`/`5a a5`: no hits) — it is a separate
  device/interface, resolving the open question in the device-layer report §9
  at the data level (board routing still unresolved).
- The RAM window `0xffff8000–0xffff80ff` is not a byte-raw chip mirror: chip
  access goes through the shadow at `0xffffc28e`; the window holds
  checksummed cells written via the `ref_updateMemoryAtAddress_*` helpers.

## 6. Files

- `docs/investigations/60E15120_N3J1E/eeprom_content_map_report.md` (this report)
- `docs/investigations/60E15120_N3J1E/reviews/eeprom_content_map/README.md`,
  `annotated_dumps.txt`, `validation.json`
- `data/labels/60E15120_N3J1E/eeprom_content_labels.json`
- `utilities/scripts/decode_eeprom.py` — decodes any 256-B 93C56 dump into
  this map (`python utilities/scripts/decode_eeprom.py <dump.bin> [--json]
  [--compare other.bin]`); tests `tests/test_decode_eeprom.py`
- `tests/test_eeprom_content_map.py`
- Read-only inputs: `submodules/Mazda_RX8_PCM_ReverseEngineering/Data_binaries/RX8_93c56_ECU_IC420_Read.bin`
  (SHA-256 `64b13ddf…d205e3`), `…/se3p_ecm_eeprom.bin` (`d7f4bb0a…77c264`),
  ROM `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`

## 7. Validation

- All dump facts re-checked byte-level against both 256-B dumps (31 scripted
  checks, 30 PASS; the one "FAIL" was the test's own expectation list, the
  first boot-param index register is caller-provided — see §2): VIN bytes,
  tire-revs u16, `*` marker, ID-string chars, erased ranges, tail bytes,
  RX8-vs-SE3P diff offset list.
- All ROM facts re-checked against the raw ROM/disassembly this session:
  magic pools 0xd4ea = 0x55aa / 0xd4f4 = 0x0000aa55 / 0xd4f0 = 0xffff8000 /
  0xd4ec = 0xffffa3fb; call pools 0x6288 = 0xd44c, 0x63e8 = 0xd408,
  0x63dc = 0x11492, 0x11674 = 0x3e020; boot-param table of 0x3599c (19 calls,
  indices/dests/lens parsed from the disassembly); immo word reads in 0x375c0;
  affine pools 0x27c80 = 0xc27c0000 (−63.0), 0x27c84 = 0x3f000000 (0.5);
  241 pc-relative literal references into 0xffff8000–0xffff80ff (instruction
  scan). Script output: `reviews/eeprom_content_map/` + `tests/test_eeprom_content_map.py`.
- Emulator idle boot of 60E15120_N3J1E (2M cycles) leaves 0xffff8000–0xffff80ff
  zero — consistent with the mirror being magic/cell based and not bulk-filled
  at idle (free-resources report §10: the window is never written at idle).
- `validate_export.py`, `validate_reports.py`, `verify_claims.py`,
  `verify_readability.py`, `verify_math_units.py` — run from repo root, results
  in `reviews/eeprom_content_map/validation.json`; `python -m pytest tests/` —
  see validation.json.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x000375c0 | `e2ram_immo_key_read` | immo key/code/status words 0x6010000–0x6050000, 0x60b/0x60c |
| 0x00027b8e | `e2ram_learned_table_load` | chip 0x20–0x63 → RAM cells 0xffff8108/8328/8548/85d0 |
| 0x000279d8 | `e2ram_learned_table_save` | RAM cells → shadow 0x20+ → flush 0x378dc(0x20,0x44,3) |
| 0x00027d06 | `candidate_e2ram_learned_table_erase` | key-off erase of the learned table |
| 0x0003599c | `e2ram_boot_param_read` | 19 boot params chip 0x00–0x1e → 0xffffc268–0xffffc282 |
| 0x00035956 | `ref_loadDatafromE2intoRAM_` | bulk chip 0x00–0x1f → shadow |
| 0x00035a8c | `candidate_e2ram_param_write_dispatch` | param id → (index, src, len) shadow writes |
| 0x00037ef0 / 0x00037ea4 / 0x00037cd8 | `e2ram_cached_byte_read` / `e2ram_shadow_byte_write` / `e2ram_bulk_read_into_shadow` | indexed chip access via shadow |
| 0x000378dc | `e2ram_flush_request` | shadow→chip flush setup (start/len/mode cells 0xffffc48e-0xffffc4a1) |
| 0x000379e4 | `candidate_e2ram_verify_state_machine` | flush state machine + read-back verify (cmd 0x4c00000) |
| 0x0005b5d4 | `e2ram_upper_half_uds_dump` | chip 0x80–0xff → UDS response |
| 0x00055b18 | `ref_getCalID` | 16-char cal/hw ID from EEPROM 0x64–0x6c |
| 0x0005e664 | `e2ram_ecu_id_read` | chip 0x64/0x68/0x6a/0x6c → 0xffffd394–0xffffd39b |
| 0x0005b704 | `e2ram_field_6e_uds_dump` | chip 0x6e (9 B) → UDS response |
| 0x000543e4 | `e2ram_tire_size_marker_check` | chip 0x95 == '*' → default tire size |
| 0x0005de74 | `e2ram_tire_revs_read` | chip 0x9a (u16) → `tire_revolutions_per_mile_ffffd380` |
| 0x0005e748 | `e2ram_config_bit_9f_read` | chip 0x9f bit0 → 0xffffd39c |
| 0x0005b482 | `e2ram_tail_bulk_read` | bulk chip 0x64–0xff → shadow |
| 0x0004b5b6 | `FUN_0004b5b6` | bulk chip 0x7a,2 → 0xffffce30; cell 0xffff8060 |
| 0x0005e8a4 | `FUN_0005e8a4` | writes chip 0x78 (2 B) from 0xffffd3a8 |
| 0x0000d408 / 0x0000d44c | `eeprom_mirror_magic_check` / `eeprom_mirror_magic_init` | 0x55aa/0xaa55 handshake at 0xffff8000 |
| 0x00011492 / 0x000113b8 | `FUN_00011492` / `FUN_000113b8` | validate / init fan-outs (via 0x9f4c/0x9f52 → 0x6360/0x6366) |
| 0x0003e020 | `FUN_0003e020` | window validate (0xffff8704 == 0xaa55 → defaults fan-out) |
| 0x0003dc22 / 0x0003dcd0 | `ref_readValue_float_DEFAULTVAL_ADDRESS` / `ref_updateMemoryAtAddress_float_VAL_ADDR` | 8-byte checksummed cell read/write |
| 0x0000bdfa / 0x0000be30 | `e2ram_read_word` / `e2ram_send_command2` | SCI4 device frames |
| 0x0000be5e / 0x0000be8c | `candidate_e2ram_send_command4_a` / `candidate_e2ram_send_command4_b` | SCI4 4-byte command frames |

### 8.2 Chip map (93C56 byte offsets) — see §1 table; annotated hex in `reviews/eeprom_content_map/annotated_dumps.txt`

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffff8000 | `eeprom_mirror_magic` | 0xaa55/0x55aa handshake word of the E2 window |
| 0xffff8000–0xffff80ff | E2/diag window | checksummed cells (241 literal refs); e.g. 0x8038 knock learn, 0x8040/0x8048 idle trim, 0x8068 pedal zero, 0x807c/0x8084/0x8094 E2 params, 0x80c4/0x80e4 LTFT |
| 0xffff8108+8i | `e2ram_learned_table_value_pos` | +value per chip pair i (0x27b8e) |
| 0xffff8328+8i | `e2ram_learned_table_value_neg` | −value per chip pair i (0x27b8e) |
| 0xffff8548+2i | `e2ram_learned_table_flag_a` | flag byte per chip pair i |
| 0xffff85d0+2i | `e2ram_learned_table_flag_b` | second flag array |
| 0xffffc268–0xffffc282 | `e2ram_param_block` | decoded chip 0x00–0x1e |
| 0xffffc28e / 0xffffc38e | `e2ram_shadow_data` / `e2ram_shadow_complement` | chip byte shadow + complement |
| 0xffffc1d3–0xffffc1d8 | immo/validate flags | set by 0x3599c dests and 0x375c0 |
| 0xffffd394–0xffffd39c | `DAT_ffffd394`… | ECU ID / config reads (0x5e664, 0x5e748) |
| 0xffffd380 / 0xffffd382 | `tire_revolutions_per_mile_ffffd380` | tire revs from chip 0x9a |

## 9. Limits

- Static analysis + upstream dumps only; no emulator model of the 93C56 exists,
  so chip traffic was not executed (idle boot leaves the RAM window zero,
  consistent with §7).
- The two dumps are single samples: RX8 (IC420 from an RX-8) and a Mazda 3
  (SE3P) cross-reference; per-ECU fields (key 0x02–0x09, code 0x16–0x19, VIN,
  tail 0xfc–0xfd, config bit 0x9f) differ between them, everything else matches.
- Chip 0xfc–0xfd (per-ECU tail u16) and 0x6e–0x76 / 0x70–0x7f have no ROM
  consumer found this pass (0x6e is UDS-served raw); marked candidate/low.
- The meaning of individual config bytes 0x0c–0x15 is only known via the param
  block indices, not their semantics per byte.
- The learned table's 34 pairs map to the 0x27xxx correction-apply cluster
  (2 rotor banks × 17 cells suggested by the 0x27024 clear pattern); per-cell
  axis (RPM/load) attribution is not done here — see
  [`knock_control_report.md`](knock_control_report.md) for the knock side.
- Whether the PLDR/ISR 28-u16 device is a second chip or a second interface of
  IC420 is a board-routing question, unresolved (data shows it is not inside
  the 256-B IC420 image).
- The RAM window cells' individual semantics come from the subsystem reports
  cited in §1; cells without a cited consumer stay `candidate_`.

## 10. Related subsystems

[`e2ram_device_layer_report.md`](e2ram_device_layer_report.md) (SCI4 protocol +
shadow), [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) (28-u16
PLDR/ISR block), [`knock_control_report.md`](knock_control_report.md) (0xffff8038
learn), [`idle_control_report.md`](idle_control_report.md) (0xffff8040/8048),
[`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md) (E2 window
PIDs), [`labeling/free_resources_report.md`](labeling/free_resources_report.md)
§10 (idle-free window), [`docs/architecture/flash-memory-layout.md`](../../architecture/flash-memory-layout.md)
§2/§5 (memory map, now linked to this map).
