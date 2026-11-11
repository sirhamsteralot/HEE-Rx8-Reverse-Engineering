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
0x5fd38, stored-flag table `dtc_ram_flag_table_ffffd570` 0xffffd570) in
[`dtc_control_report.md`](dtc_control_report.md); the end-to-end "how to author a
new DTC" map (which args persist via this block, save trigger 0x64ba → 0x1150e) in
[`dtc_authoring_report.md`](dtc_authoring_report.md); OS boot/init ordering in
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
#   b448 = enc(b594, 0x39a00000 = 0.00030517578125, pool 0x24684); b44a/b44c = enc(readValue_float of `inferred_ram_807c_ffff807c` 0xffff807c/0xffff8084);
#   b44e = pedal volts `inferred_pedal_volts_ffffa9c4` 0xffffa9c4; rpm 0xffffb548 (step 0x3e480000 = 0.1953125, pool 0x24b40); fault bits -> b459..b45b
```

### 2a. Payload u16 map (encode side, staging base 0xffffb440; u16[i] at 0xffffb440+2i)

Every payload cell written by 0x244bc, traced to its working-RAM source and that
source's producer (all pool words re-verified in the disassembly/ROM this pass):

| u16 | Cell | Encode statement | Source cell | Source producer (verified) | Meaning |
|---|---|---|---|---|---|
| 0 | 0xffffb440 | magic 0xa55a (0x236cc, pool 0x23734) | — | — | block magic |
| 1 | 0xffffb442 | enc(0xffffb40c, step 0.030517578125) | `DAT_ffffb40c` | 0x231f0 (clamp of pedal-derived candidates, cap 111.0, special 99.0; pool 0x232fa at 0x232c2, writes 0x233b0/0x233c2/0x233d2) | learned pedal/throttle value (`candidate_learned_pedal_value`) |
| 2 | 0xffffb444 | = b442 | — | — | duplicate of u16[1] |
| 3 | 0xffffb446 | signed enc(0xffffb414, 0.030517578125) | `DAT_ffffb414` | 0x23558: b414 = b410 − b428 (0.0 when 0xffffccc9 set; pool 0x23590) | pedal position delta per update (`throttle_pedal_position_delta`) |
| 4 | 0xffffb448 | enc(0xffffb594, step 0.00030517578125) | `DAT_ffffb594` | 0x2563c `ref_filterBatteryVoltage`: filter(b590, b594, 0.5); seeded from ADC cell 0xffff9f68 by 0x25600 | filtered battery voltage (`filtered_battery_voltage`) |
| 5 | 0xffffb44a | enc(readValue_float 0xffff807c, default 15.0) | `inferred_ram_807c_ffff807c` | E2/diag RAM window; Mode 22 PID 0x1169 source (handler 0x56efc) | E2 parameter (PID 0x1169), default 15.0 |
| 6 | 0xffffb44c | enc(readValue_float 0xffff8084, default 15.0) | `DAT_ffff8084` | E2/diag RAM window | E2 parameter, default 15.0 |
| 7 | 0xffffb44e | raw = 0xffffa9c4 | `inferred_pedal_volts_ffffa9c4` | pedal volts (PID 0x0049 `diag22_pid0049_ram_a9c4_pedal`) | pedal position volts |
| 8–11 | 0xffffb450–0xffffb456 | raw = 0xffffb51e/b520/b522/b524 | `DAT_ffffb51e`… | no writer anywhere in ROM (full pool scan) — constant 0 | reserved (zero) |
| 12 | 0xffffb458 | raw byte = 0xffffcc91 | `DAT_ffffcc91` | written by 0x18aea/0x470d0/0x47cce; read by `candidate_idle_learn_condition` 0x160ce | idle-learn flag (`candidate_idle_learn_flag`) |
| 13–17 | 0xffffb459–0xffffb45d | bit-packed flags | 0xffffaa68/ccc1/bced/ccc9, readValue_8bit 0xffff80a0/8762/80a2, 0xffffad60/ad62/ad61/ad63, 0xffffb4dc–b4eb, 0xffffb51c, 0xffffb2cf/b2d0, 0xffffb422, 0xffffc030, 0xffffccc7/ccbd/ccbc/ccc8 | 0x242ae `e2ram_fault_status_collect` fills 0xffffb4dc–0xffffb4eb from 18× `ref_getFaultStatus__` 0x66a00 and 0xffffb51c; the rest are live monitor/status flags | packed DTC/monitor history + live status bits (replayed by 0x23f4e into 0xffffb4ec–0xffffb51b) |
| 18 | 0xffffb45e | enc(readValue_float 0xffff8094, default 20.0) | `DAT_ffff8094` | E2/diag RAM window | E2 parameter, default 20.0 |
| 19 | 0xffffb460 | enc(0xffffb38c, step 0.030517578125) | `DAT_ffffb38c` | 0x22a14: min(0xffffb2c4, …) or 5.0; consumed as pedal base by 0x21a80/0x233ec (`inferred_throttle_position_ffffb2d4 = idle_air_required + b38c`) | throttle-plate base position (`candidate_throttle_base_position`) |
| 20 | 0xffffb462 | enc(readValue_float 0xffff8068, default 0x412db22d = 10.856, step 0.00390625) | `DAT_ffff8068` | E2/diag RAM window | E2 parameter, default 10.856 |
| 21 | 0xffffb464 | enc(0xffffb548, step 0.1953125) | `engine_speed_rpm_ffffb548` | rpm producer (load/fueling chain) | engine rpm at save |
| 22–26 | 0xffffb466–0xffffb474 | never written by 0x244bc | — | no references in ROM | reserved / retained staging bytes |
| 27 | 0xffffb476 | checksum = sum(u16[0..26]) | — | 0x236cc loop 0x236f0–0x236fe | checksum |

### 2b. Save cadence / trigger (caller of 0x1150e traced to the OS)

0x1150e has exactly one caller in the whole ROM (pool word 0x0001150e exists
only at 0x656c): the task[9] body `knock_sensor_fault_task` 0x64ba calls it
unconditionally (`mov.l @(0x656c,pc),r3` at 0x64d4, `jsr @r3` at 0x64d6; task
table rec[9].entry = 0x64ba at ROM 0x4a28). 0x1150e tail-calls the save thunk
0x23766 (`mov.l @(0x116cc,pc),r2` = 0x23766 at 0x1152e, `jmp @r2` at 0x11530),
which jumps to 0x236cc (pool 0x237b8 at 0x23766), which unconditionally encodes
(via 0x2377a → 0x242ae + 0x244bc), writes the magic + checksum and issues the
28-u16 E2RAM write 0xb886. So the block is rewritten on **every task[9] run** —
not on a wall-clock timer and not only at key-off. Task[9] is woken by the
thunk 0x9f96 (`os_wake_posted_task(9)`, `mov #0x9,r4` at 0x9f9c; pool 0xa1f4 =
0x3854), which is dispatch-table entry 0xd890 of the rotating wake dispatcher
0xa522 (pointer table 0xd888 = wake thunks for tasks 7/8/9/18/10–16, selected by
byte table 0xd8f0 against counter 0xffffa1a0; task 9 fires when bit1 of
0xffffa1a0 is the lowest set bit). 0xa522 runs on every 2nd call of 0x5cee
(gate `0xffffa1a2 & 1`; 0x5cee clears CMCSR1_W bit 0x80 and tail-jumps via pool
0x5d64 = 0xa522 at 0x5cf8). 0x5cee is the **CMCSR1 refresh-timer ISR**: IVT
vector 192 (slot at ROM 0x7ff50) → trampoline 0x2f20 → `jmp` pool 0x2f30 =
0x5cee at 0x2f2c — the only caller of 0x5cee in ROM (see
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md) §5).
So the save cadence is a rotating slot of the CMCSR1 refresh ticks: roughly
every 8th tick (every 4th 0xa522 call, every 2nd tick per 0xa522 run). The
learned values saved (0xffffb40c/0xffffb414/0xffffb38c) are updated in the
same 0x1150e pass by 0x22f86 → 0x22a14/0x231f0/0x23558 (callgraph-verified edges
0x22f86→0x22a14/0x231f0/0x23558, and 0x1150e→0x22f86).

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
`e2ram_payload_raw` (0xffffb47a), `stored_dtc_flag_bits` (0xffffb4ec), plus the
payload-source cells attributed in §2a: `candidate_learned_pedal_value`
(0xffffb40c), `throttle_pedal_position_delta` (0xffffb414),
`filtered_battery_voltage` (0xffffb594), `candidate_idle_learn_flag`
(0xffffcc91), `candidate_throttle_base_position` (0xffffb38c), and
`e2ram_payload_reserved` (0xffffb466–0xffffb474, 0xffffb51e–0xffffb524 — no
writer references in ROM). Evidence in
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
- Binary-level, save chain + payload sources (§2a/§2b): pool words 0x656c =
  0x1150e (jsr at 0x64d6 in 0x64ba), 0x116cc = 0x23766 (jmp at 0x11530 in
  0x1150e), 0x237b8 = 0x236cc (jmp at 0x23768 in 0x23766), task table 0x4a28 =
  0x64ba, IVT slot 0x7ff50 = 0x2f20 (vec 192), pool 0x2f30 = 0x5cee (jmp at
  0x2f2c in trampoline 0x2f20), 0x5d64 = 0xa522 (jmp at 0x5cf8 in 0x5cee),
  0xd890 = 0x9f96 (dispatch table entry), `mov #0x9,r4` at 0x9f9c, pool 0xa1f4
  = 0x3854, 0x232fa = 0xb40c (writes at 0x233b0/0x233c2/0x233d2 in 0x231f0),
  0x23590 = 0xb414 (pool 0x23590, instr 0x2355c); whole-ROM scan: pool word 0x0001150e occurs only
  at 0x656c, pool word 0x00005cee only at 0x2f30, and
  0xffffb466–0xffffb474 / 0xffffb51e–0xffffb524 have no writer
  references. Covered by `tests/test_e2ram_nv_storage.py`.
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
| 0x000064ba | `knock_sensor_fault_task` | task[9] body (rec[9].entry @ ROM 0x4a28); sole caller of 0x1150e (jsr pool 0x656c at 0x64d4) |
| 0x0001150e | `FUN_0001150e` | task[9] sub-batch; tail-jmp 0x23766 (pool 0x116cc at 0x1152e) = the save |
| 0x00009f96 / 0x0000a522 / 0x00005cee | `FUN_00009f96` / `FUN_0000a522` / `FUN_00005cee` | wake task 9 (`mov #0x9,r4` at 0x9f9c; dispatch entry 0xd890) ← rotating dispatcher 0xa522 (byte table 0xd8f0, ptr table 0xd888) ← CMCSR1 ISR 0x5cee (pool 0x5d64 at 0x5cf8) |
| 0x00002f20 | IVT trampoline vec 192 | `jmp` pool 0x2f30 = 0x5cee at 0x2f2c; IVT slot ROM 0x7ff50 = 0x2f20 |
| 0x00022f86 / 0x00022a14 / 0x000231f0 / 0x00023558 | `FUN_00022f86` / `FUN_00022a14` / `FUN_000231f0` / `FUN_00023558` | same 0x1150e pass updates learned values 0xffffb38c/0xffffb40c/0xffffb414 before the save |
| 0x0002563c / 0x00025600 | `ref_filterBatteryVoltage` / `FUN_00025600` | writers of `filtered_battery_voltage` 0xffffb594 |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0x237bc / 0x237c8 | pool words = 0x23844 / 0x244bc |
| 0x23726 / 0x23734 / 0x23738 / 0x2372c / 0x23728 | pool words: 0xb440 (base), 0xa55a (magic), 0xb886 (write), 0x2377a, 0xb43b (ok flag) |
| 0x656c / 0x116cc / 0x237b8 | pool words = 0x1150e / 0x23766 / 0x236cc (save chain 0x64ba→0x1150e→0x23766→0x236cc) |
| 0x4a28 | task table rec[9].entry = 0x64ba |
| 0x2f30 / 0x5d64 / 0xd890 / 0xa1f4 / 0x7ff50 | pool/IVT words = 0x5cee / 0xa522 / 0x9f96 / 0x3854 / 0x2f20 (wake chain: IVT vec 192 → 0x2f20 → 0x5cee → 0xa522 → 0x9f96) |
| 0x232fa / 0x23590 | pool words = 0xb40c / 0xb414 (encode source cells in 0x231f0/0x23558) |

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
| 0xffffb40c | `candidate_learned_pedal_value` | learned pedal/throttle value (writer 0x231f0); payload u16[1]/[2] |
| 0xffffb414 | `throttle_pedal_position_delta` | b410 − b428 per update (writer 0x23558); payload u16[3] |
| 0xffffb594 | `filtered_battery_voltage` | k=0.5 filter of 0xffffb590 (0x2563c); payload u16[4] |
| 0xffffb38c | `candidate_throttle_base_position` | throttle-plate base (writer 0x22a14); payload u16[19] |
| 0xffffcc91 | `candidate_idle_learn_flag` | read by `candidate_idle_learn_condition` 0x160ce; payload byte at 0xffffb458 |
| 0xffffb466–0xffffb474 / 0xffffb51e–0xffffb524 | `e2ram_payload_reserved` | no writer references in ROM; copied as zero / retained |

## 9. Limits

- Static analysis only. Every payload u16 is now attributed to its encode
  source (§2a); the physical meaning of `candidate_learned_pedal_value`
  (0xffffb40c) and `candidate_throttle_base_position` (0xffffb38c) is inferred
  from their producers/consumers (0x231f0 clamp of pedal-derived candidates read
  back by the monitors 0x1b6fc/0x46404; 0x22a14 min with the torque-derived
  throttle position 0xffffb2c4, consumed as the pedal base in 0x21a80/0x233ec)
  and stays at `candidate_` per the label ladder. The readValue cells
  0xffff807c/8084/8094/8068 are the E2/diag RAM window (0xffff8000–0xffff92ff);
  0xffff807c is exposed as Mode 22 PID 0x1169.
- Save cadence/trigger is resolved (§2b): every task[9] run, woken in rotation
  from the fueling chain via 0x5cee → 0xa522 → 0x9f96; the exact wall-clock
  period is engine-speed dependent (crank-angle synchronous OS) and was not
  measured dynamically.
- The E2RAM device protocol (PLDR_W/ISR_W bit-banging in 0xb99c/0xb886) is
  described only at the level needed here; the deeper layer is covered by 0x3599c/0x37ea4.
