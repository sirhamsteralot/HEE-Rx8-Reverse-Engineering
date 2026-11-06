# E2RAM device layer report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/e2ram_device_labels.json`; detailed
evidence in [`reviews/e2ram_device_layer/README.md`](reviews/e2ram_device_layer/README.md).

**Related reports:** the 28-u16 learned-values/DTC-history block codec on top of
this layer in [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) (its own
low-level primitives 0xb886/0xb958/0xb99c on the PLDR/ISR lines); knock-learn
consumer 0x139c4 in [`knock_control_report.md`](knock_control_report.md); idle
trim cells 0xffff8040/8048 in [`idle_control_report.md`](idle_control_report.md).

## 1. Executive summary

The external **E2RAM is a serial (SPI-style) EEPROM wired to SCI4** with a
chip-select on `PFDR_W` 0xfffff74e bit 0x400 and a busy/status input on
`PBDR_W` 0xfffff738 bit 0x800. Device addresses are 24-bit frames of the form
`0x06xxxxxx` (base 0x6000000, page in bits 16-23), sent as command frames over
SCI4: 2-byte frames via 0xbe30, 4-byte frames via 0xbe5e/0xbe8c, word reads via
0xbdfa (send address, clock in a u16 with 0xc02c).

On top of the device protocol sits a **parameter layer with a RAM shadow cache**:

- shadow: `e2ram_shadow_data` 0xffffc28e[256] + complement `e2ram_shadow_complement`
  0xffffc38e[256] (a byte is valid when `data[i] == ~comp[i]`);
- `e2ram_cached_byte_read` 0x37ef0(index, &dest, len): returns shadow bytes when
  valid, otherwise reads the containing u16 word from the device (address
  0x6000000 + ((index>>1)&0xff)*0x10000; even index = high byte, big-endian) and
  refreshes the shadow;
- `e2ram_shadow_byte_write` 0x37ea4(index, src, len): writes data+complement into
  the shadow (under mask 0x10) — callers 0x279d8, 0x27d06, 0x35a8c, 0x4b668,
  0x5d9d8, 0x5e8a4;
- `e2ram_bulk_read_into_shadow` 0x37cd8 (inherited `ref_E2IntoRAM_`): fills the
  shadow for a byte range by reading each u16 page once (callers 0x27b8e,
  0x35956, 0x4b5b6, 0x5b482);
- `e2ram_boot_param_read` 0x3599c (inherited `ref_getDataFromE2RAM`): at boot
  (0x349e4 ← 0x1102a) reads 19 indexed fields into the parameter block
  0xffffc268-0xffffc282 via 0x37ef0;
- `candidate_e2ram_param_write_dispatch` 0x35a8c maps a param id to
  (index, source cell, len) shadow writes.

## 1a. Plain-language summary

Besides the main learned-values block, the PCM keeps a small set of indexed
parameters in the external EEPROM. The firmware never talks to the chip
directly for these: it keeps a copy in RAM together with a complement copy so it
can tell "cached" from "stale". Reads usually hit the cache; a stale byte
triggers a two-byte read from the chip. Writes update the cache immediately and
are flushed to the chip by the state machine 0x379e4, which also issues the
write-enable-style command 0x4c00000 and verifies by read-back.

## 2. How it works (condensed pseudocode)

```
# device protocol (SCI4 + CS on PFDR_W bit 0x400, busy on PBDR_W bit 0x800)
e2ram_cs_port_setup()      # 0xbf3a: PLIR_W &= ~0x200, PBCRH_W config, PBDR_W 0x400=0, PFDR_W 0x400=1
sci4_send_bytes(buf, n)    # 0xbfa0: SCI_SCR4_B 0xfffff022 TE on, TDR4 0xfffff023 per byte, SSR4 0xfffff024 handshake
sci4_read_u16()            # 0xc02c: SCI_SCR4_B TE|RE, dummy TDR4, read 2x SCI_RDR4_B 0xfffff025
 e2ram_busy_status_read()  # 0xbed8: pulse PFDR_W 0x400, read PBDR_W 0xfffff738 bit 0x800 -> (v & 0x800)==0
e2ram_send_command2(cmd)   # 0xbe30: CS up, sci4_send(cmd, 2), CS down     (e.g. 0x4c00000 from 0x379e4)
e2ram_send_command4_a/b(c) # 0xbe5e / 0xbe8c: CS up, sci4_send(cmd, 4), CS down
e2ram_read_word(addr)      # 0xbdfa: CS up, sci4_send(addr, 2), sci4_read_u16(), CS down

# parameter layer
e2ram_boot_param_read()    # 0x3599c: 19x 0x37ef0(idx, &0xffffc268.., len)   (boot: 0x349e4 <- 0x1102a)
e2ram_cached_byte_read(i,&d,len)  # 0x37ef0: shadow 0xffffc28e[i] vs ~0xffffc38e[i];
                          #   stale -> 0xbed8 + 0xbdfa(0x6000000 + ((i>>1)&0xff)*0x10000), even i = high byte
e2ram_shadow_byte_write(i,src,len) # 0x37ea4: 0xffffc28e[i]=b, 0xffffc38e[i]=~b (mask 0x10)
e2ram_bulk_read_into_shadow(start,len) # 0x37cd8: per u16 page p: 0xbdfa(0x6000000+p*0x10000)
                          #   -> 0xffffc28e[2p]=hi, 0xffffc28f[2p]=lo, complements at 0xffffc38e/f
e2ram_verify_state_machine()  # 0x379e4: states over 0xffffc49c; 0xbe30(0x4c00000); read-back 0xbdfa vs 0xffffc49a
```

## 3. Key calibrated data

None — fixed device addressing (base 0x6000000, page<<16) and command 0x4c00000
(pool 0x37bd4 in 0x379e4), both verified in ROM.

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x3599c | `e2ram_boot_param_read` | high |
| 0x37ef0 | `e2ram_cached_byte_read` | high |
| 0x37ea4 | `e2ram_shadow_byte_write` | high |
| 0x37cd8 | `e2ram_bulk_read_into_shadow` | high |
| 0xbdfa | `e2ram_read_word` | high |
| 0xbe30 | `e2ram_send_command2` | high |
| 0xbfa0 | `sci4_send_bytes` | high |
| 0xc02c | `sci4_read_u16` | high |
| 0xbf3a | `e2ram_cs_port_setup` | high |
| 0xbed8 | `e2ram_busy_status_read` | high |
| 0x35d36 | `candidate_e2ram_write_thunk` | medium |
| 0x35a8c | `candidate_e2ram_param_write_dispatch` | medium |
| 0x379e4 | `candidate_e2ram_verify_state_machine` | medium |
| 0xbe5e / 0xbe8c | `candidate_e2ram_send_command4_a` / `_b` | medium |

RAM aliases: `e2ram_shadow_data` 0xffffc28e, `e2ram_shadow_complement`
0xffffc38e, `e2ram_param_block` 0xffffc268.

Evidence: `source_review/accepted_function_aliases.tsv` /
`accepted_ram_aliases.tsv`, `data/labels/60E15120_N3J1E/e2ram_device_labels.json`.

## 5. Corrections made in this pass

- The decompiled C calls the register at 0xfffff74e "PLDR_W"; `symbols.tsv` names
  it **`PFDR_W`** (PLDR_W is 0xfffff75e). All evidence here uses PFDR_W — the
  E2RAM chip-select is PFDR_W bit 0x400, the busy input is PBDR_W 0xfffff738
  bit 0x800.
- `ref_getDataFromE2RAM` 0x3599c and `ref_writeToE2RAMArea_INDEX_ADDR_LEN`
  0x37ea4 confirmed: boot param read and shadow write respectively; the actual
  device traffic goes through 0xbdfa/0xbe30/0xbe5e/0xbe8c on SCI4, not through a
  memory-mapped window (the 0x6000000 value is a device address frame, not a
  CPU address).

## 6. Files

- `utilities/scripts/rx8-pcm-pipeline/review_e2ram_labels.py` (wired into
  `rebuild.sh`; idempotent)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram}_aliases.tsv`
- `data/labels/60E15120_N3J1E/e2ram_device_labels.json`
- `reverse-engineered/decompiled/60E15120_N3J1E/` (symbols renamed in place)
- `docs/investigations/60E15120_N3J1E/reviews/e2ram_device_layer/README.md`,
  `reviews/e2ram_device_layer/validation.json`

## 7. Validation

- Binary-level: call counts re-counted in the disassembly (0x3599c: 19 calls to
  0x37ef0; 0x37ef0: 3 calls; 0x37ea4: 2; 0x37cd8: 5; 0xbdfa: 6; 0xbe30: 5;
  0x35a8c: 30); pool words read from ROM (0x37f84 = 0x6000000 device base,
  0x37f7c/0x37f80 = shadow pair, 0x35a48 = 0x37ef0, 0x37bd4 = 0x4c00000,
  0xbecc/0xbed4/0xbed0 = 0x2054/0x4bbc/0x2064 helpers); register names from
  symbols.tsv (SCI_SCR4_B 0xfffff022, SCI_TDR4_B 0xfffff023, SCI_SSR4_B
  0xfffff024, SCI_RDR4_B 0xfffff025, PFDR_W 0xfffff74e, PBDR_W 0xfffff738,
  PBCRH_W 0xfffff732, PLIR_W 0xfffff75c); caller edges from callgraph.
- `validate_export.py` (ROM SHA-256 + 168,592 instruction bytes + 1,833 exact
  reference matches), `verify_claims.py`, `verify_readability.py`,
  `verify_math_units.py`, `validate_reports.py` — all PASS.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0003599c | `e2ram_boot_param_read` | 19-field boot param read → 0xffffc268.. |
| 0x00037ef0 | `e2ram_cached_byte_read` | shadow check + device read fallback |
| 0x00037ea4 | `e2ram_shadow_byte_write` | shadow data+complement write |
| 0x00037cd8 | `e2ram_bulk_read_into_shadow` | page-wise device→shadow fill |
| 0x00035a8c | `candidate_e2ram_param_write_dispatch` | id → (index, src, len) writes |
| 0x00035d36 | `candidate_e2ram_write_thunk` | thunk |
| 0x000379e4 | `candidate_e2ram_verify_state_machine` | cmd 0x4c00000 + read-back verify |
| 0x0000bdfa | `e2ram_read_word` | send addr, clock in u16 |
| 0x0000be30 | `e2ram_send_command2` | 2-byte command frame |
| 0x0000be5e / 0x0000be8c | `candidate_e2ram_send_command4_a` / `_b` | 4-byte command frames |
| 0x0000bfa0 / 0x0000c02c | `sci4_send_bytes` / `sci4_read_u16` | SCI4 TX/RX primitives |
| 0x0000bf3a / 0x0000bed8 | `e2ram_cs_port_setup` / `e2ram_busy_status_read` | CS/port setup, busy input |
| 0x000349e4 / 0x00038082 | `ref_ImmoSomethingOrOther__` / `FUN_00038082` | callers of 0x3599c / 0x379e4 |

### 8.2 Data and entry points (ROM / I/O)

| Address | Content |
|---|---|
| 0x35a48-0x35a88 | 0x3599c pool (0x35a48 = 0x37ef0, dest cells 0xffffc268..) |
| 0x37f6c-0x37f8c | 0x37ef0/0x37ea4/0x37cd8 shared pool (0x3920/0x3934 masks, 0xffffc28e/0xffffc38e, 0x6000000, 0xbed8, 0xbdfa) |
| 0xbecc-0xbed4 | 0xbdfa/0xbe30 helper pool (0x2054/0x4bbc/0x2064) |
| 0x37bd4 | 0x379e4 pool word = 0x4c00000 (command) |
| SCI4: `SCI_SCR4_B` 0xfffff022, `SCI_TDR4_B` 0xfffff023, `SCI_SSR4_B` 0xfffff024, `SCI_RDR4_B` 0xfffff025 | E2RAM serial port registers |
| `PFDR_W` 0xfffff74e bit 0x400, `PBDR_W` 0xfffff738 bit 0x800, `PBCRH_W` 0xfffff732, `PLIR_W` 0xfffff75c | CS / busy / port config |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffc28e | `e2ram_shadow_data` | E2RAM byte shadow cache |
| 0xffffc38e | `e2ram_shadow_complement` | complement cache (validity check) |
| 0xffffc268 | `e2ram_param_block` | boot parameter block (0xffffc268-0xffffc282) |
| 0xffffc492 / 0xffffc494 | `DAT_ffffc492` / `DAT_ffffc494` | bulk-read page counters (0x37cd8) |
| 0xffffc49c / 0xffffc498 / 0xffffc49a | `DAT_ffffc49c` … | verify state machine state/addr/expected |

## 9. Limits

- Static analysis only; no emulator run of the E2RAM traffic in this pass.
- The shadow→device flush path is only partially traced (0x379e4 issues command
  0x4c00000 and read-back verifies; the exact write-data frame construction in
  0xbe5e/0xbe8c callers is not fully decoded).
- The relationship between this indexed parameter area and the 28-u16 block of
  [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) (separate low-level
  primitives 0xb886/0xb958/0xb99c on other port lines) is not reconciled here —
  possibly two different chips or two different interfaces; flagged as open.
- Package-pin ↔ connector-terminal for the SCI4/CS/busy lines is board routing
  (unresolved).
- `candidate_` labels are hypotheses.

## 10. Related subsystems

Learned-values block codec: [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md);
knock-learn storage consumer 0x139c4: [`knock_control_report.md`](knock_control_report.md);
idle trim cells 0xffff8040/8048: [`idle_control_report.md`](idle_control_report.md);
DTC stored-flag replay 0x23f4e: [`dtc_control_report.md`](dtc_control_report.md).
