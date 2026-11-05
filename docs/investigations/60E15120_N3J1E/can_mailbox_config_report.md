# CAN mailbox configuration verify report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/c8_large_bodies_labels.json` (ROADMAP
C item 8).

**Related reports:** HCAN register map and boot CAN init in
[`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md) (HCAN0 at
0xffffe400; UDS mailboxes 14/15); UDS/CAN dispatch in
[`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md); the descriptor
blocks (0x4e01c etc.) are the same record format as the UDS descriptor tables
documented there.

## 1. Executive summary

**0x2a4f8** (1,218 B — ROADMAP C item 8) is the **HCAN mailbox-configuration
compare**: given a channel (0 = HCAN0 @0xffffe400, 1 = HCAN1 @0xffffe600) and a
desired descriptor array (16 × 16-byte records for HCAN0, 6 for HCAN1), it
rebuilds the expected MBCR/MBIMR words and compares them plus BCR, IMR, LAFM and
every per-mailbox MC control/data byte against the live registers, returning
nonzero if anything differs. `ref_canSetup` 0xd9f4 calls it (jsr @r13 at 0xda3e
and 0xda4e; pool 0xdb20 = 0x2a4f8) in a ≤2-iteration retry loop around
`ref_CANControllerSetup`, with descriptor blocks 0x4e01c/0x4e11c (HCAN0, 16
records) and 0x4e21c (HCAN1, 6 records); if it still mismatches after the second
try, the error flag 0xffffa410 is set.

## 1a. Plain-language summary

Setting up a CAN controller means programming ~16 mailboxes with IDs, directions
and buffers. The firmware keeps the desired mailbox layout in ROM tables; after
(Re)initializing the HCAN hardware it re-reads the actual registers and checks
them against that layout with 0x2a4f8. If anything didn't stick, it retries once
and otherwise raises a CAN-setup error flag.

## 2. How it works (condensed pseudocode)

```
# ref_canSetup 0xd9f4:
for 0xffffa40e in 0..1:
    ref_CANControllerSetup(0, 0x4e01c or 0x4e11c (if 0xffffb534==1), 0x10)
    c1 = hcan_mailbox_config_compare(0, block)     # jsr @r13 at 0xda3e
    ref_CANControllerSetup(1, 0x4e21c, 6)
    c2 = hcan_mailbox_config_compare(1, block)     # jsr @r13 at 0xda4e
    if c1 == 0 && c2 == 0: break
if 0xffffa40e > 1: 0xffffa410 = 1                   # setup error flag

# 0x2a4f8 hcan_mailbox_config_compare(channel, recs):
mismatch = (BCR != 0x83e)                            # HCAN0_BCR_W 0xffffe402 / HCAN1_BCR_W 0xffffe602
for each 16-byte record r (16 or 6):
    mb = r[5] & 0xf
    MBCR |= 1 << ((mb + 8) & 0xf);  expected MBIMR from last record
    MC[1] = r[6] (control byte) at base + 0x20 + 8*mb  # HCAN0_MC0[1]_B 0xffffe420
    if r[7] == 0 (standard): MC[5] = id << 5; MC[6] = id >> 3
    else (extended): MC[5] = (id>>0x12 & 7)*0x20 + (id>>0x10 & 3) + r[7]*8; MC[6] = id>>0x15; MC[7] = r[0]; MC[8] = id>>8
compare MBCR (HCAN0_MBCR_W 0xffffe404), MBIMR (HCAN0_MBIMR_W 0xffffe414),
        IMR == 0xfcfe (HCAN0_IMR_W 0xffffe416), LAFMH/LAFML != 0 (0xffffe41e/0xffffe41c)
return mismatch
```

## 3. Key calibrated tables

Not calibration — ROM descriptor blocks (mailbox config):

| Address | Content |
|---|---|
| 0x4e01c | HCAN0 desired mailbox records, 16 × 16 B (first record: id 0x201, mailbox 1, ctrl 0x08, buffer 0xffffbaf4) |
| 0x4e11c | alternate HCAN0 set used when RAM 0xffffb534 == 1 |
| 0x4e21c | HCAN1 desired mailbox records, 6 × 16 B |

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x2a4f8 | `hcan_mailbox_config_compare` | high |

Evidence: `source_review/accepted_function_aliases.tsv`,
`data/labels/60E15120_N3J1E/c8_large_bodies_labels.json`.

## 5. Corrections made in this pass

None — previously unlabeled `FUN_0002a4f8`.

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0002a4f8_*.c` (renamed)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_function_aliases.tsv`
- `data/labels/60E15120_N3J1E/c8_large_bodies_labels.json`

## 7. Validation

- Binary-level: pool 0xdb20 = 0x2a4f8; jsr @r13 at 0xda3e/0xda4e inside
  ref_canSetup 0xd9f4; counts 0x10/6 passed as r4/r5 (0xda… mov #0x10 / #0x6);
  register symbols HCAN0_BCR_W 0xffffe402 … HCAN1_LAFMH_W 0xffffe61e all in
  `symbols.tsv`; first descriptor record bytes at 0x4e01c read from ROM
  (0000 0201 00 01 08 00 ffffbaf4 0100 0000). Scripted checks 62/62 PASS.
- `validate_reports.py` / `verify_claims.py` / `validate_export.py`;
  `tests/test_c8_large_bodies.py`.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0002a4f8 | `hcan_mailbox_config_compare` | desired-vs-live HCAN mailbox compare |
| 0x0000d9f4 | `ref_canSetup` | retry loop caller (inherited name) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0xdb20 | pool word = 0x2a4f8 |
| 0x4e01c / 0x4e11c / 0x4e21c | HCAN0 / alt-HCAN0 / HCAN1 mailbox descriptor blocks |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffa40e | `DAT_ffffa40e` | setup retry counter |
| 0xffffa410 | `DAT_ffffa410` | CAN setup error flag (set when retries exhausted) |
| 0xffffb534 | `DAT_ffffb534` | selects alternate HCAN0 descriptor block |

Peripheral window (0xffffe400+ HCAN0, 0xffffe600+ HCAN1): BCR/MBCR/MBIMR/IMR/
LAFM/MC bytes as listed in §2, all symbol-named in `symbols.tsv`.

## 9. Limits

- Static analysis only. The exact meaning of each 16-byte record field beyond
  {id, mailbox, control, ide, buffer} follows the compare code in 0x2a4f8; record
  bytes at +12..+15 were not attributed.
- Whether ref_canSetup runs once at boot or also on CAN error recovery was not
  traced beyond its callers (0xdade/0xdcc0/0x2a1a0 per callgraph).
