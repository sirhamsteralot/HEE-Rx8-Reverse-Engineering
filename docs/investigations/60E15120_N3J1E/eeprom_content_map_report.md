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
| 0x20–0x63 | **learned-correction table**: 34 × (u8 value, u8 flag), per-index meaning in §3a | values −45.0…+1.5, flags 0x01/0x00 | bulk 0x20 len 0x44 by 0x27b8e / save 0x279d8 / erase 0x27d06; consumers 0x2711a/0x271b0/0x276ec/0x27808/0x28198 |
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
# learned-table cell index (0x2711a): cell = rpm_cell + 17*load_band
#    rpm_cell = lookup(rpm, tbl 0x6a694: 17 cells, RPM axis 0x755dc = 0,1125,...,8750, identity u16 data 0x75620)
#    load_band from engine_load vs 0.4/0.65/3.0 (pools 0x755a4/0x755a8/0x755ac): <0.4->0, <0.65->1, <3.0->2, else 3
#    cell RPM breakpoint = lookup(cell mod 17, tbl 0x6a6a0: axis 0x75644 = 0..16, data 0x75688 = 750..9000)
#    chip pair i (i<0x22) = cell i of both rotor banks: +v at value_pos[i], -v at value_neg[i], flag at flag_a[i]/flag_b[i]
#    apply 0x28198/0x28484: read value_pos[cell] (bank = DAT_ffffb660&1 == 0) or value_neg[cell], interpolate vs RPM (0x28484)
#    learn gate 0x271b0: flags of cell-1/cell/cell+1 + RPM within cell breakpoint (DAT_ffffb8f0) -> DAT_ffffb6c6
#    learn 0x276ec: |rpm - DAT_ffffb8f0| <= 100.0 (pool 0x755d0) -> live cell DAT_ffffb6cc[bank*0x44+cell] = DAT_ffffba2c, counter DAT_ffffb8f4++
#    persist 0x27808 (every 0xb ticks): counter > 0x1d -> copy live cell into value/flag cells (flag 1 on first learn)
#    flag mirror 0x27eec: flag[cell] -> flag[cell+0x11/+0x22/+0x33] for cells 0..2, both banks
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

The learned table's **axes** are descriptor tables in ROM (both type_code 0,
17 cells, ROM-verified at 0x6a694/0x6a6a0):

| Descriptor | Axis ptr | Axis content | Data ptr | Data content | Used by |
|---|---|---|---|---|---|
| 0x6a694 (tbl 2D #332) | 0x755dc | RPM thresholds 0, 1125, 1750, …, 8750 (17 f32) | 0x75620 | identity u16 0..16 | 0x2711a cell index |
| 0x6a6a0 (tbl 2D #333) | 0x75644 | cell index 0..16 (17 f32) | 0x75688 | RPM breakpoints 750, 1500, …, 9000 (17 f32) | 0x271b0 / 0x28198 |

Load bands (0x2711a, float pools 0x755a4/0x755a8/0x755ac): load < 0.4 →
band 0; 0.4–0.65 → band 1; 0.65–3.0 → band 2; ≥ 3.0 → band 3.

### 3a. Learned-table per-index semantics (chip 0x20–0x63)

Chip pair *i* (value byte 0x20+2i, flag byte 0x21+2i) is learned-table
**cell `i = rpm_cell + 17 × load_band`** for **both rotor banks** at once:
load 0x27b8e decodes the pair into `+v` at `0xffff8108+8i` (even sector
parity, `DAT_ffffb660&1==0`) and `−v` at `0xffff8328+8i` (odd parity), and the
flag into both `0xffff8548+2i` and `0xffff85d0+2i`. Cells 0–33 (load bands
0–1) are the only ones persisted to the chip (save 0x279d8, 0x22 iterations);
cells 34–67 (load bands 2–3) exist only in the RAM arrays. The learned
quantity is `DAT_ffffba2c` computed by 0x28198 in the per-tick fuel/load
update 0x287aa — a sector-speed-ring deviation term
(`(DAT_ffffb668 − (DAT_ffffb680−DAT_ffffb668)/6) − DAT_ffffb664`, ring
0xffffa390–0xffffa3ac) — stored per cell by 0x276ec when
|RPM − cell breakpoint| ≤ 100, and persisted to the RAM table by 0x27808
once the cell counter exceeds 0x1d.

**Where the stored calibrations hook in — misfire detection.** The learned
cell value is the per-cell *baseline* subtracted from the instantaneous
deviation before thresholding, and the residual drives the misfire DTC path
(all links ROM-verified: asm call sites + literal pools + DTC slot bytes):

```
learned cell (chip pair i ↔ 0xffff8108+8i / 0xffff8328+8i)
  → 0x28198/0x28484 read + RPM-interpolate → DAT_ffffba64 / 0xffffba68 (per rotor bank)
  → DAT_ffffba30 = DAT_ffffba2c (deviation) − learned          # residual
  → 0x2837c filters → DAT_ffffba34 / 0xffffba38 when cell learned (0xffffb6c6)
  → DAT_ffffba40 = max(0, ·)                                   # excess deviation
  → armed by 0x27fb4 / 0x28022 → per-rotor event flags 0xffffba24/25 (+ba26/27)
  → 0x447e2 clears/bumps when above RPM thresholds (0xffffcb8c/cb90 =
     lookups tbl 0x6b9f4/0x6ba00, 12 cells, axis 780–8500 rpm; 0x44a78)
    0x4489c same vs load limits (0xffffcb94/cb98 = Load Limit A/B,
     tbl 0x6ba0c/0x6ba18; 0x44a9e)
  → 0x26a42/0x26b34 bump per-rotor counters 0xffffb688–0xffffb68e (0xffffb694 tick flag)
  → 0x44436 sustained window (0xffffcb60/cb62)
  → 0x445ba evaluates → bsr 0x44724 (asm 0x446ea)
  → 0x44724 calls dtc_set_fault_xdefault (pool 0x447ac = 0x5fd3c) slot 1,
    rotor bits in r6 → DTC slot table 0x7e560 slots 0/1 = 0x0300 (P0300, both
    rotors), prefix table 0x7e55a = P0300/P0301/P0302
```

So the 34 pairs are the **learned misfire/roughness baseline per
(RPM cell × load band × rotor sign)**, consumed by the misfire monitor that
sets P0300/P0301/P0302 (see the open misfire-detection backlog item; the DTC
side is covered in [`dtc_control_report.md`](dtc_control_report.md)). The
**knock learned retard is not one
of these 34 pairs**: it lives in the separate 8-byte E2-window cell
0xffff8038 (consumer `knock_retard_learn_to_eeprom` 0x139c4, see
[`knock_control_report.md`](knock_control_report.md)), as do the idle-trim
cells 0xffff8040/0x8048 and the LTFT slots 0xffff80c4/0x80e4 — those window
cells are not chip-backed (the window is validated/reset by 0x3e020, not
loaded from the chip).

| Pair | Chip | Cell | RPM cell (breakpoint) | Load band | RX8 dump value (flag) |
|---|---|---|---|---|---|
| 0 | 0x20–0x21 | 0 | 0 (750 rpm) | 0 (< 0.4) | +1.5 (0x01) |
| 1 | 0x22–0x23 | 1 | 1 (1500) | 0 | +1.0 (0x01) |
| 2 | 0x24–0x25 | 2 | 2 (2000) | 0 | 0.0 (0x01) |
| 3 | 0x26–0x27 | 3 | 3 (2500) | 0 | −1.5 (0x01) |
| 4 | 0x28–0x29 | 4 | 4 (3000) | 0 | −4.0 (0x01) |
| 5 | 0x2a–0x2b | 5 | 5 (3500) | 0 | −5.0 (0x01) |
| 6 | 0x2c–0x2d | 6 | 6 (4000) | 0 | −6.5 (0x01) |
| 7 | 0x2e–0x2f | 7 | 7 (4500) | 0 | −10.0 (0x01) |
| 8 | 0x30–0x31 | 8 | 8 (5000) | 0 | −11.5 (0x01) |
| 9 | 0x32–0x33 | 9 | 9 (5500) | 0 | −16.5 (0x01) |
| 10 | 0x34–0x35 | 10 | 10 (6000) | 0 | −18.5 (0x01) |
| 11–16 | 0x36–0x41 | 11–16 | 11–16 (6500–9000) | 0 | 0.0 (0x00) |
| 17 | 0x42–0x43 | 17 | 0 (750) | 1 (0.4–0.65) | +1.5 (0x01) |
| 18 | 0x44–0x45 | 18 | 1 (1500) | 1 | +1.0 (0x01) |
| 19 | 0x46–0x47 | 19 | 2 (2000) | 1 | +1.0 (0x01) |
| 20 | 0x48–0x49 | 20 | 3 (2500) | 1 | −2.0 (0x01) |
| 21 | 0x4a–0x4b | 21 | 4 (3000) | 1 | −5.0 (0x01) |
| 22 | 0x4c–0x4d | 22 | 5 (3500) | 1 | −6.0 (0x01) |
| 23 | 0x4e–0x4f | 23 | 6 (4000) | 1 | −7.0 (0x01) |
| 24 | 0x50–0x51 | 24 | 7 (4500) | 1 | −10.5 (0x01) |
| 25 | 0x52–0x53 | 25 | 8 (5000) | 1 | −11.5 (0x01) |
| 26 | 0x54–0x55 | 26 | 9 (5500) | 1 | −16.0 (0x01) |
| 27 | 0x56–0x57 | 27 | 10 (6000) | 1 | −18.0 (0x01) |
| 28 | 0x58–0x59 | 28 | 11 (6500) | 1 | −23.0 (0x01) |
| 29 | 0x5a–0x5b | 29 | 12 (7000) | 1 | −25.5 (0x01) |
| 30 | 0x5c–0x5d | 30 | 13 (7500) | 1 | −33.5 (0x01) |
| 31 | 0x5e–0x5f | 31 | 14 (8000) | 1 | −45.0 (0x01) |
| 32–33 | 0x60–0x63 | 32–33 | 15–16 (8500–9000) | 1 | 0.0 (0x00) |

The SE3P dump has all 34 pairs erased (`ff 00`). RX8-vs-SE3P diff offsets in
this region: 0x20–0x5f (values), 0x60/0x62 (pair 32/33 value bytes) — i.e. the
whole table is per-ECU learned data.

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
| 0x27024 / 0x270aa | `e2ram_learned_table_clear` / `e2ram_learned_table_validate` | high |
| 0x2711a | `e2ram_learned_table_cell_index` | high |
| 0x271b0 | `e2ram_learned_table_learn_gate` | high |
| 0x276ec | `e2ram_learned_table_cell_learn` | high |
| 0x27808 | `e2ram_learned_table_ram_persist` | high |
| 0x27eec | `e2ram_learned_table_flag_mirror` | medium |
| 0x28198 / 0x28484 | `e2ram_learned_table_apply` / `e2ram_learned_table_cell_read` | high |
| 0x2837c | `e2ram_learned_table_correction_filter` | medium |
| RAM 0xffffb6c4 | `e2ram_learned_table_cell_index` | high |
| RAM 0xffffb660 | `sector_parity_bank` | high |
| RAM 0xffffb6cc / 0xffffb8f4 | `e2ram_learned_table_live_value` / `e2ram_learned_table_live_counter` | high |
| RAM 0xffffba2c | `e2ram_learned_correction_value` | high |
| 0x2842c | `misfire_deviation_delay_line` | high |
| 0x27fb4 / 0x28022 | `misfire_event_arm` / `misfire_event_arm_secondary` | high |
| 0x26a42 / 0x26b34 | `misfire_event_count` / `misfire_counter_bump` | high |
| 0x447e2 / 0x4489c | `misfire_threshold_check_rpm` / `misfire_threshold_check_load` | high |
| 0x44a78 / 0x44a9e | `misfire_threshold_rpm_lookup` / `misfire_threshold_load_lookup` | high |
| 0x44436 | `misfire_sustained_window` | high |
| 0x445ba / 0x44724 | `misfire_dtc_evaluate` / `misfire_dtc_set` | high |
| RAM 0xffffba30 / ba40 / ba24 / ba26 | `misfire_residual` / `misfire_excess_deviation` / `misfire_event_flag_a` / `misfire_event_flag_b` | high |
| RAM 0xffffb688–b68e / b694 | per-rotor misfire counters / tick flag | high |
| RAM 0xffffcb8c–cb98 / cb60 | misfire thresholds (RPM / load-limit lookups) / sustained counters | high |
| chip 0x20–0x63 per pair | `learned_table_pairs` in the labels JSON | high |

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
- Learned-table per-index semantics re-checked against the raw ROM/disassembly
  this session: cell-index function 0x2711a (tbl 0x6a694 pool 0x2716c; load
  thresholds 0.4/0.65/3.0 at float pools 0x755a4/0x755a8/0x755ac; band offsets
  0x11/0x22/0x33; dest DAT_ffffb6c4 pool 0x27152); axis descriptors 0x6a694
  (axis_count 17, axis 0x755dc = RPM 0..8750, data 0x75620 = identity u16) and
  0x6a6a0 (axis 0x75644 = 0..16, data 0x75688 = 750..9000 RPM) dumped from ROM
  bytes; array base pools 0x27154/0x27158/0x27270/0x27934/0x27938/0x27b44/
  0x27b48/0x27c78/0x27c7c/0x27fa4/0x27fa8/0x282b8/0x2850c all = 0xffff8108 /
  0xffff8548 as expected; bank strides u16 pools 0x27d3e = 0x0220,
  0x27d40 = 0x0088, 0x284f6 = 0x0220; loop bounds `mov #0x22` (load/save),
  `mov #0x44` x2 banks (0x27808/0x27024), `mov #0x11`/`mov #0x3`/`mov #0x2`
  (0x27eec), tick 0xb on DAT_ffffba04 (pool 0x2791c); ±100.0 RPM gate pool
  0x755d0, filter k=0.031 pool 0x755d4 (0x276ec); callgraph: only
  0x27b8e/0x279d8/0x27d06 touch chip shadow bytes 0x20–0x63, and the UDS 0x3B
  write table (0x5f6dd) targets only 0x64/0x68/0x6a/0x6c/0x6e/0x78/0x7a/0x80/
  0xa0/0xff — so the 34 pairs are written exclusively by the firmware's
  save/erase path. Both dumps re-diffed: 0x20–0x63 differs (RX8 learned,
  SE3P erased `ff 00`), per-pair decode in §3a.
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
| 0x00027024 / 0x000270aa | `e2ram_learned_table_clear` / `e2ram_learned_table_validate` | clear / checksum-validate 2 banks × 0x44 cells |
| 0x0002711a | `e2ram_learned_table_cell_index` | cell = rpm_cell + 17×load_band → 0xffffb6c4 (tbl 0x6a694, loads 0.4/0.65/3.0) |
| 0x000271b0 | `e2ram_learned_table_learn_gate` | cell RPM breakpoint (tbl 0x6a6a0) + neighbour flags → 0xffffb6c6 |
| 0x000276ec | `e2ram_learned_table_cell_learn` | ±100 rpm gate → live cell 0xffffb6cc / counter 0xffffb8f4 |
| 0x00027808 | `e2ram_learned_table_ram_persist` | every 0xb ticks: counter > 0x1d → value/flag cells; calls 0x27eec |
| 0x00027eec | `e2ram_learned_table_flag_mirror` | flag[cell] → flag[cell+0x11/+0x22/+0x33], cells 0..2 |
| 0x00028198 / 0x00028484 | `e2ram_learned_table_apply` / `e2ram_learned_table_cell_read` | read + RPM-interpolate learned value per rotor bank; DAT_ffffba2c |
| 0x0002837c | `e2ram_learned_table_correction_filter` | filter DAT_ffffba30 → 0xffffba34/0x38, max(0,·) → 0xffffba40 |
| 0x000287aa | `FUN_000287aa` | per-tick fuel/load update; calls the whole 0x27xxx cluster |
| 0x002842c | `misfire_deviation_delay_line` | deviation delay line 0xffffba58/54/50 from 0xffffba4c |
| 0x0027fb4 / 0x00028022 | `misfire_event_arm` / `misfire_event_arm_secondary` | set per-rotor event flags 0xffffba24/25, 0xffffba26/27 |
| 0x00026a42 / 0x00026b34 | `misfire_event_count` / `misfire_counter_bump` | bump per-rotor counters 0xffffb688–0xffffb68e, tick flag 0xffffb694 |
| 0x000447e2 / 0x0004489c | `misfire_threshold_check_rpm` / `misfire_threshold_check_load` | clear/bump on RPM thresholds (0xffffcb8c/cb90) / load limits (0xffffcb94/cb98) |
| 0x00044a78 / 0x00044a9e | `misfire_threshold_rpm_lookup` / `misfire_threshold_load_lookup` | tbl 0x6b9f4/0x6ba00 / Load Limit A/B tbl 0x6ba0c/0x6ba18 |
| 0x00044436 | `misfire_sustained_window` | sustained counters 0xffffcb60/cb62 |
| 0x000445ba / 0x00044724 | `misfire_dtc_evaluate` / `misfire_dtc_set` | bsr 0x44724 (asm 0x446ea) → `dtc_set_fault_xdefault` pool 0x447ac = 0x5fd3c, slot 1 → P0300/P0301/P0302 (0x7e560/0x7e55a) |
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
| 0xffff8108+8i | `e2ram_learned_table_value_pos` | +value per chip pair i (0x27b8e); cell = rpm_cell + 17×load_band, bank 0 of 2 (bank stride 0x220) |
| 0xffff8328+8i | `e2ram_learned_table_value_neg` | −value per chip pair i (0x27b8e); bank 1 (parity 1) of the value array |
| 0xffff8548+2i | `e2ram_learned_table_flag_a` | flag byte per chip pair i (bank stride 0x88) |
| 0xffff85d0+2i | `e2ram_learned_table_flag_b` | second flag array (bank 1) |
| 0xffffb6c4 | `e2ram_learned_table_cell_index` | current cell = rpm_cell + 17×load_band (0x2711a) |
| 0xffffb660 | `sector_parity_bank` | ATUII sector index; &1 = rotor bank select |
| 0xffffb6cc[bank*0x44+cell] | `e2ram_learned_table_live_value` | live learned floats (0x276ec → 0x27808) |
| 0xffffb8f4[bank*0x44+cell] | `e2ram_learned_table_live_counter` | learn counters; > 0x1d persists (0x27808) |
| 0xffffba2c | `e2ram_learned_correction_value` | sector-speed deviation (raw misfire term) from the 0x287aa tick (0x28198) |
| 0xffffba30 / 0xffffba40 | `misfire_residual` / `misfire_excess_deviation` | deviation − learned cell; max(0, filtered) excess (0x28198/0x2837c) |
| 0xffffba24+ / 0xffffba26+ | `misfire_event_flag_a` / `_b` | per-rotor event flags (0x27fb4/0x28022, checked by 0x447e2/0x4489c) |
| 0xffffb688–0xffffb68e, 0xffffb694 | per-rotor counters / tick flag | 0x26a42/0x26b34 |
| 0xffffcb8c/cb90, 0xffffcb94/cb98 | `misfire_threshold_rpm_a` / `misfire_threshold_load_a` | RPM lookups tbl 0x6b9f4/0x6ba00; Load Limit A/B 0x6ba0c/0x6ba18 (0x44a78/0x44a9e) |
| 0xffffcb60/cb62 | `misfire_sustained_counter_a` | sustained window counters (0x44436) |
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
- The learned table's 34 pairs are pinned per index in §3a: cell =
  rpm_cell (0..16, breakpoints 750–9000 rpm) + 17 × load_band (bands 0–1
  persisted; bands 2–3 RAM-only), shared by both rotor banks with +/− sign.
  They hook into the **misfire monitor** (see §3a chain): the learned value
  is the roughness baseline subtracted from the sector-speed deviation
  DAT_ffffba2c, and persistent excess sets P0300/P0301/P0302 via
  0x445ba → 0x44724 → `dtc_set_fault_xdefault` (slot table 0x7e560). The
  physical unit of the ring values (6666666/ATUII period) is not converted
  here — that belongs to the open misfire-detection backlog item. The knock
  learned retard is the separate window cell 0xffff8038, not one of these
  pairs — see [`knock_control_report.md`](knock_control_report.md).
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
