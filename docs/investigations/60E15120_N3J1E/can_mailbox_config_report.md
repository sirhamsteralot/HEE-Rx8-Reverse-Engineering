# CAN mailbox configuration verify report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export, the
disassembly and the raw ROM bytes. No hardware execution was performed. Labels
recorded in `data/labels/60E15120_N3J1E/can_mailbox_config_labels.json`.

**Related reports:** HCAN register map and boot CAN init in
[`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md) (HCAN0 at
0xffffe400; UDS mailboxes 14/15); UDS/CAN dispatch in
[`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md); the descriptor
blocks (0x4e01c etc.) are the same record format as the UDS descriptor tables
documented there; the CAN 0x212 RX mailbox inside the 0x4e21c HCAN1 block is
unpacked by [`dsc_can_arbitration_report.md`](dsc_can_arbitration_report.md).

## 1. Executive summary

**0x2a4f8** (1,218 B) is the **HCAN mailbox-configuration
compare**: given a channel (0 = HCAN0 @0xffffe400, 1 = HCAN1 @0xffffe600) and a
desired descriptor array (16 × 16-byte records for HCAN0, 6 for HCAN1), it
rebuilds the expected MBCR/MBIMR words and compares them plus BCR, IMR, LAFM and
every per-mailbox MC control/data byte against the live registers, returning
nonzero if anything differs. `ref_canSetup` 0xd9f4 calls it (jsr @r13 at 0xda3e
and 0xda4e; pool 0xdb20 = 0x2a4f8) in a ≤2-iteration retry loop around
`ref_CANControllerSetup` 0x9744, with descriptor blocks 0x4e01c/0x4e11c (HCAN0,
16 records, selected by `automatic_transmission` 0xffffb534) and 0x4e21c
(HCAN1, 6 records); if it still mismatches after the second try, the error flag
0xffffa410 is set.

The full 16-byte descriptor record layout is now attributed (writer chain
0x9744 → 0xcacc → 0x9d24, compare loop 0x2a56e–0x2a5be, ROM bytes of all three
blocks; see §3). `ref_canSetup` is **not boot-only**: it runs once at key-on
init via `ref_canInitVals` 0x2a1a0 (init chain 0x61a8 → 0x1102a
→ 0x2a1a0, jsr at 0x2a1a4, pool 0x2a3e0 = 0xd9f4), and again from the runtime
CAN supervision (OS task 7 0x63f0 → 0x114b0 → `can_error_supervision_step`
0x2a248 → `ref_checkCANsomethingKeyOnBased` 0xdcc0) when a HCAN bus-off/error
condition is detected — re-running the full mailbox setup once per error
episode (guard 0xffffa40c == 0, bsr 0xd9f4 at 0xdd86) and a full CAN reset
(`can_error_full_reset` 0xdade, bsr at 0xdda8) after the error persists ≥ 1000
polls.

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
    # block select: automatic_transmission 0xffffb534 == 1 -> 0x4e01c (pool 0xdb14),
    #                 else -> 0x4e11c (pool 0xdb18); cmp/eq #1 at 0xda22
    ref_CANControllerSetup(0, block, 0x10)         # jsr @r12 at 0xda2c/0xda38 (pool 0xdb1c = 0x9744)
    c1 = hcan_mailbox_config_compare(0, block)     # jsr @r13 at 0xda3e
    ref_CANControllerSetup(1, 0x4e21c, 6)          # pool 0xdb24 = 0x4e21c; jsr at 0xda48
    c2 = hcan_mailbox_config_compare(1, 0x4e21c)   # jsr @r13 at 0xda4e
    if c1 == 0 && c2 == 0: break
if 0xffffa40e > 1: 0xffffa410 = 1                   # setup error flag

# ref_CANControllerSetup 0x9744(ch, recs, count): per record (loop 0x97d8-0x97fc):
#   r4=r[5] (mailbox), r5=r[4], r6=r[6], r7=r[7], stack: r[0..3] (id), r[12]
#   -> ref_setCANRegisters 0xcacc (pool 0x9878) -> ref_initializeCANRegisters 0x9d24 (pool 0xcbe8)
# ref_initializeCANRegisters 0x9d24(mb, r4, ctrl, ide, id, r12, &MBCR, &MBIMR, &MD0, &MC):
bit = 1 << ((mb + 8) & 0xf)                         # mailbox mb -> register bit (mb+8)&0xf
MBCR = (MBCR & ~bit) | (r[4]  * bit)                # 0x9d58-0x9d6c; MBCR = 0xffffe404/0xffffe604
MBIMR = (MBIMR & ~bit) | (r[12] * bit)              # 0x9d6e-0x9d82; MBIMR = 0xffffe414/0xffffe614
MC[mb][0] = r[6]                                    # 0x9d84; MC base 0xffffe420/0xffffe620 (pools 0xcbc2/0xcbc8)
if ide == 0 (standard): MC[mb][4] = id<<5 | ide<<3; MC[mb][5] = id>>3
else (extended):        MC[mb][4..7] = 29-bit id split + ide
# (buffer pointer r[8..11] is NOT used by the setup path; it feeds the TX/RX data paths)

# 0x2a4f8 hcan_mailbox_config_compare(channel, recs):
mismatch = (BCR != 0x803e)                           # HCAN0_BCR_W 0xffffe402 / HCAN1_BCR_W 0xffffe602 (pool 0x2a5f0 = 0x0000803e; confirmed by emulator: setup writes 0x803e)
mbcr_acc = 0x100; mbimr_acc = 0xffff                  # pools 0x2a5e8 / 0x2a5f4 (bit 8 of MBCR is reserved-always-1)
for each 16-byte record r (16 or 6):                # loop 0x2a56e-0x2a5be
    mb = r[5] & 0xf; bit = 1 << ((mb + 8) & 0xf)
    mbcr_acc  = (mbcr_acc  & ~bit) | (r[4]  * bit)  # mov.b @(0x4,r9)  at 0x2a596
    mbimr_acc = (mbimr_acc & ~bit) | (r[12] * bit)  # mov.b @(0xc,r9)  at 0x2a5a2
    MC[mb][0] must equal r[6] (control byte)        # HCAN0_MC0[1]_B 0xffffe420 + 8*mb
    if r[7] == 0 (standard): MC[mb][4] == id<<5|r[7]<<3; MC[mb][5] == id>>3
    else (extended): MC[mb][4..7] == 29-bit id split
compare MBCR (HCAN0_MBCR_W 0xffffe404, pool 0x2a5ea), MBIMR (HCAN0_MBIMR_W 0xffffe414,
        pool 0x2a5ec), IMR == 0xfcfe (HCAN0_IMR_W 0xffffe416), LAFMH/LAFML == 0
        (0xffffe41e/0xffffe41c)
return mismatch
```

## 3. Key calibrated tables

Not calibration — ROM descriptor blocks (mailbox config). All bytes re-read
from the raw ROM this pass; the field layout below was verified against the
writer chain (0x9744 → 0xcacc → 0x9d24) and the compare loop (0x2a56e–0x2a5be):

**16-byte mailbox descriptor record layout** (base of each block):

| Offset | Field | Consumed by |
|---|---|---|
| +0..+3 | u32 BE CAN identifier | MC[mb][4..7] ID split (0x9d84–0x9de2) |
| +4 | MBCR direction bit for this mailbox (0 = transmit, 1 = receive; Sh7055h.pdf 16.2.4) | MBCR bit (mb+8)&0xf (0x9d58–0x9d6c) |
| +5 | mailbox number (≥ 0x20 selects HCAN1; low nibble indexes MC) | MC offset, bit position (0xcacc `cmp/ge #0x20`) |
| +6 | MC control byte (DLC + flags) | MC[mb][0] (0x9d84) |
| +7 | IDE flag (0 = standard 11-bit, 1 = extended 29-bit) | ID split branch (0x9d88) |
| +8..+11 | u32 RAM data-buffer pointer (e.g. 0xffffbaf4) | TX/RX data paths, not the setup path |
| +12 | MBIMR interrupt-mask bit (0 = mailbox interrupt enabled, 1 = disabled; Sh7055h.pdf 16.2.12) | MBIMR bit (mb+8)&0xf (0x9d6e–0x9d82) |
| +13..+15 | reserved, zero in all ROM blocks | — |

| Address | Content |
|---|---|
| 0x4e01c | HCAN0 desired mailbox records, 16 × 16 B, used when `automatic_transmission` 0xffffb534 == 1 (pool 0xdb14; cmp/eq #1 at 0xda22). First record: id 0x201, mailbox 1, ctrl 0x08, buffer 0xffffbaf4 |
| 0x4e11c | alternate HCAN0 set (16 × 16 B) used when 0xffffb534 != 1 (pool 0xdb18). Differs from 0x4e01c only in records 3/4 (id 0x231, mailbox 4): direction bit +4 = 1 (receive) here, 0 (transmit) in 0x4e01c |
| 0x4e21c | HCAN1 desired mailbox records, 6 × 16 B (mailboxes 33–39) |
| 0x4df1c | CAN 0x201 TX descriptor, same record format |

Observed values: byte +12 = 1 (interrupt disabled) for HCAN0 mailboxes 1–12 and
all six HCAN1 mailboxes; 0 (interrupt enabled) for HCAN0 mailboxes 13/14/15
(ids 0x7df/0x7e0/0x7e8 — the diagnostic mailboxes, matching the IVT 0x378 RX
interrupt path). Byte +4 = 1 (receive) for HCAN0 mailboxes 12 (0x4b1), 13
(0x7df), 14 (0x7e0), mailbox 4 (0x231) only in the 0x4e11c variant, and all
HCAN1 mailboxes; 0 (transmit) elsewhere, e.g. mailbox 1 (0x201) and mailbox 15
(0x7e8). Resulting live registers after one setup pass (emulator, see §7):
HCAN0 MBCR 0x0170 (AT block) / 0x1170 (MT block), MBIMR 0xff1f, HCAN1 MBCR
0xf600, MBIMR 0xf600, both BCR 0x803e, both IMR 0xfcfe.

## 4. Labeling applied

| Address | New label | Confidence |
|---|---|---|
| 0x2a4f8 | `hcan_mailbox_config_compare` | high |
| 0x0000dade | `can_error_full_reset` | high |
| 0x0002a248 | `can_error_supervision_step` | high |
| 0x00009ac4 | `hcan_bus_off_flag` | high |

RAM: 0xffffa409 `can_error_recovery_active`, 0xffffa40a `can_error_latch`,
0xffffa40c `can_error_retry_counter`, 0xffffa40e `can_setup_retry_counter`,
0xffffa40f `can_error_poll_counter`, 0xffffa410 `can_setup_error_flag`
(all uint8 except 0xffffa40c uint16).

Evidence: `source_review/accepted_function_aliases.tsv` +
`source_review/accepted_ram_aliases.tsv`,
`data/labels/60E15120_N3J1E/can_mailbox_config_labels.json`.

## 5. Corrections made in this pass

- The previous §3 said 0x4e11c was the alternate HCAN0 set for
  `automatic_transmission` == 1 — backwards. The disassembly (cmp/eq #1 at
  0xda22, pools 0xdb14 = 0x4e01c / 0xdb18 = 0x4e11c) shows **0x4e01c is the
  AT variant, 0x4e11c the default (MT) variant**; they differ only in the
  direction bit (+4) of the two 0x231 records (mailbox 4).
- The previous §2 pseudocode said "MBCR |= 1 << ((mb+8)&0xf)" and "expected
  MBIMR from last record". The compare loop actually accumulates
  `MBCR = (MBCR & ~bit) | (r[4] * bit)` and `MBIMR = (MBIMR & ~bit) |
  (r[12] * bit)` from **every** record (0x2a596 / 0x2a5a2), so record byte +4
  is the MBCR bit value and byte +12 the MBIMR bit value — both now attributed
  (§3).
- Earlier pass: previously unlabeled `FUN_0002a4f8`.

## 6. Files

- `reverse-engineered/decompiled/60E15120_N3J1E/functions/0002a4f8_*.c`
  (symbol renamed in place; filename keeps the `FUN_` prefix)
- New aliases 0x0000dade `can_error_full_reset`, 0x0002a248
  `can_error_supervision_step`, 0x00009ac4 `hcan_bus_off_flag` plus the six
  0xffffa40x RAM aliases integrated into the export (function_index.tsv,
  callgraph.tsv, symbols.tsv, per-function `.c`, `firmware_decompiled.c`,
  `named/firmware_named.c`) with the same comment-preserving transform the
  `integrate_reviewed_names.py` pass uses, scoped to these rows; filenames
  keep their prefixes
- `docs/investigations/60E15120_N3J1E/source_review/accepted_function_aliases.tsv`
  + `accepted_ram_aliases.tsv`
- `data/labels/60E15120_N3J1E/can_mailbox_config_labels.json`
- `tests/test_can_mailbox_config.py`, `tests/test_can_mailbox_config_dynamic.py`

## 7. Validation

- Binary-level (this pass): descriptor record bytes of all three blocks read
  from ROM (0x4e01c / 0x4e11c 16 × 16 B, 0x4e21c 6 × 16 B, 0x4df1c 1 × 16 B);
  writer chain anchors — 0x9744 loop reads at 0x97d8–0x97f0 (r4=r[5], r5=r[4],
  r6=r[6], r7=r[7], stack r[0..3]=id, r[12]), jsr pool 0x9878 = 0xcacc; 0xcacc
  channel split `cmp/ge #0x20` at 0xcad6 with HCAN0 pools 0xcbc2 = 0xe420 /
  0xcbc4 = 0xe4b0 / 0xcbc6 = 0xe414 (MBIMR) and MBCR = 0xe420-0x1c = 0xe404,
  HCAN1 pools 0xcbc8 = 0xe620 / 0xcbcc = 0xe614, jsr pool 0xcbe8 = 0x9d24;
  0x9d24 RMW writes: MBCR at 0x9d6c, MBIMR at 0x9d82, MC[mb][0] = r6 at 0x9d84;
  compare loop 0x2a56e–0x2a5be accumulates r[4] (0x2a596) into MBCR and r[12]
  (0x2a5a2) into MBIMR, compare pools 0x2a5ea = 0xe404 / 0x2a5ec = 0xe414,
  BCR expect pool 0x2a5f0 = 0x0000803e. Caller chain pools: 0x2a3e0 = 0xd9f4
  (jsr at 0x2a1a4), 0x11350 = 0x2a1a0 (jsr at 0x111a0), 0x628c = 0x1102a (jsr at
  0x61e2), 0x6528 = 0x114b0 (jsr at 0x6414), 0x11680 = 0x2a248 (jsr at 0x114b8),
  0x2a44c = 0xdcc0 (jsr at 0x2a252), task-table record 7 at 0x4a08 = 0x63f0;
  error-branch anchors in 0xdcc0: bsr 0xd9f4 at 0xdd86, bsr 0xdade at 0xdda8,
  pools 0xddc2 = 0xa40a, 0xddc4 = 0xa409, 0xddc6 = 0x3e8 (1000), 0xddd0 =
  0xffffa40c, 0xddd4 = 0x9ac4, 0xddd8 = 0x2460, engine-running gate pools
  0xddbc = 0xaa68 / 0xddbe = 0xb578; bsr 0xd9f4 at 0xdae0 in 0xdade. Block-select
  pools in 0xd9f4: 0xdb0e = 0xb534, 0xdb10 = 0xffffa40e, 0xdb14 = 0x4e01c,
  0xdb18 = 0x4e11c, 0xdb1c = 0x9744, 0xdb20 = 0x2a4f8, 0xdb24 = 0x4e21c.
  Register symbols HCAN0_BCR_W 0xffffe402 … HCAN1_LAFMH_W 0xffffe61e and
  HCAN0_GSR_B 0xffffe401 / HCAN1_GSR_B 0xffffe601 all in `symbols.tsv`.
  GSR bit0 = bus-off, GSR bit1 = error warning (TEC/REC ≥ 96), MBCR bit
  0 = transmit / 1 = receive, MBIMR bit 0 = interrupt enabled / 1 = disabled —
  Sh7055h.pdf §16.2.2/16.2.4/16.2.12.
- Emulator (harness call of 0xd9f4 after boot, both `automatic_transmission`
  values): live registers match the values computed from the ROM record bytes
  — AT=1: HCAN0 MBCR 0x0170; AT=0: HCAN0 MBCR 0x1170; both: HCAN0 MBIMR 0xff1f,
  HCAN1 MBCR 0xf600, HCAN1 MBIMR 0xf600, BCR 0x803e, IMR 0xfcfe; MC[mb1]
  0xffffe428 = 08 00 00 00 20 40 21 00 (ctrl 0x08, id 0x201 split). Caveat:
  the emulator's MULU.W/MULS.W/MUL.L write the product to the operand register
  instead of MACL (Sh7055h.pdf: product → MACL), which zeroes the MBCR/MBIMR
  RMW results in-emulator; the run above used a corrected in-memory mulu patch,
  the repo emulator is unchanged (tracked as a new discrepancy). The MC/BCR/IMR
  writes do not use mulu and validate with the unmodified emulator.
- `validate_reports.py` / `verify_claims.py` / `validate_export.py`;
  `tests/test_can_mailbox_config.py` + `tests/test_can_mailbox_config_dynamic.py`.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x0002a4f8 | `hcan_mailbox_config_compare` | desired-vs-live HCAN mailbox compare |
| 0x0000d9f4 | `ref_canSetup` | setup + compare retry loop (inherited name); runs at key-on init and on CAN error recovery |
| 0x00009744 | `ref_CANControllerSetup` | programs one HCAN channel from a descriptor block (inherited name) |
| 0x0000cacc | `ref_setCANRegisters` | per-record register writer dispatcher (inherited name) |
| 0x00009d24 | `ref_initializeCANRegisters` | writes MBCR/MBIMR bit + MC bytes for one mailbox (inherited name) |
| 0x0002a1a0 | `ref_canInitVals` | key-on init: calls `ref_canSetup` first (jsr at 0x2a1a4) (inherited name) |
| 0x0001102a | `FUN_0001102a` | main-init chain body calling 0x2a1a0 (jsr at 0x111a0) |
| 0x000061a8 | `ref_mainInit__` | main init entry calling 0x1102a (jsr at 0x61e2) (inherited name) |
| 0x000063f0 | `ref_interruptSetup___` | OS task 7 entry (task table 0x4990 record 7 at 0x4a08) (inherited name) |
| 0x000114b0 | `FUN_000114b0` | task-7 body calling 0x2a248 (jsr at 0x114b8) |
| 0x0002a248 | `can_error_supervision_step` | interrupt-masked CAN supervision step calling 0xdcc0 |
| 0x0000dcc0 | `ref_checkCANsomethingKeyOnBased` | bus-off/error detection + recovery (inherited name) |
| 0x00009ac4 | `hcan_bus_off_flag` | HCANx GSR bit0 (bus-off) test |
| 0x00009b08 | `ref_getHCANSomething` | HCANx GSR bit1 (error warning) test (inherited name) |
| 0x0000dade | `can_error_full_reset` | full CAN reset: `ref_canSetup` + `ref_resetCANTimers` 0xda94 |
| 0x00029340 | `can201_prepare_rpm_with_conditional_filter` | filtered engine RPM 0xffffbb04 (prev 0xffffbb08) from 0xffffb548 |
| 0x00029236 | `can201_encode_rpm_u16` | RPM -> 0xffffbafc, 0.25 RPM/count, cap 0xfffe, 0xffff fault |
| 0x0002927c | `can201_encode_vehicle_speed_u16` | speed -> 0xffffbb00, (v+100)/0.01, cap 40000, 0xffff fault |
| 0x000291dc | `can201_pack_and_queue_payload` | packs 8 B into 0xffffbaf4, queues via 0x99b0 |
| 0x00028eb8 | `can216_unpack_mixed_width_fields` | CAN 0x216 RX: 3 u16 + 2 u8 from 0xffffbab8 into `can216_unpacked_field_0..4` 0xffffbad4/bad6/bad8/bada/badc (pool 0x28fce re-read) |

### 8.2 Data and entry points (ROM)

| Address | Content |
|---|---|
| 0xdb20 | pool word = 0x2a4f8 |
| 0xdb0e / 0xdb10 / 0xdb14 / 0xdb18 / 0xdb1c / 0xdb24 | pool words 0xb534 / 0xffffa40e / 0x4e01c / 0x4e11c / 0x9744 / 0x4e21c (ref_canSetup) |
| 0x2a3e0 / 0x11350 / 0x628c | pool words 0xd9f4 / 0x2a1a0 / 0x1102a (init call chain) |
| 0x6528 / 0x11680 / 0x2a44c | pool words 0x114b0 / 0x2a248 / 0xdcc0 (supervision chain) |
| 0x4a08 | task-table record 7 entry word = 0x63f0 |
| 0xddc2 / 0xddc4 / 0xddc6 / 0xddd0 / 0xddd4 / 0xddd8 | pool words 0xa40a / 0xa409 / 0x3e8 / 0xffffa40c / 0x9ac4 / 0x2460 (0xdcc0) |
| 0x4e01c / 0x4e11c / 0x4e21c | HCAN0 (AT) / HCAN0 (default) / HCAN1 mailbox descriptor blocks, 16-byte records per §3 |
| 0x4df1c | CAN 0x201 TX descriptor: `0000 0201 0001 0800 ffffbaf4 0100 0000` (BE id 0x201, len 8, buffer 0xffffbaf4) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffffa409 | `can_error_recovery_active` | set in the 0xdcc0 bus-off/error branch |
| 0xffffa40a | `can_error_latch` | set after > 100 consecutive error-warning polls |
| 0xffffa40c | `can_error_retry_counter` | error-poll counter; setup re-run while 0, full reset at ≥ 1000 |
| 0xffffa40e | `can_setup_retry_counter` | setup retry counter |
| 0xffffa40f | `can_error_poll_counter` | saturating error-warning poll counter (cap 0xff) |
| 0xffffa410 | `can_setup_error_flag` | CAN setup error flag (set when retries exhausted) |
| 0xffffb534 | `automatic_transmission` | selects HCAN0 descriptor block (0x4e01c if == 1, else 0x4e11c) |
| 0xffffbaf4 | `can201_tx_payload` | 8-byte CAN 0x201 TX buffer (descriptor 0x4df1c) |
| 0xffffbafc | `can201_encoded_rpm` | encoded RPM u16 (payload +0/+1) |
| 0xffffbb00 | `can201_encoded_vehicle_speed` | encoded speed u16 (payload +4/+5) |
| 0xffffbb04 / 0xffffbb08 | `can201_prepared_engine_rpm` / `can201_previous_engine_rpm` | filtered / previous RPM floats |

CAN 0x201/0x216 function + RAM aliases recorded in
[`data/labels/60E15120_N3J1E/can_mailbox_config_labels.json`](../../../data/labels/60E15120_N3J1E/can_mailbox_config_labels.json)
and `source_review/accepted_*.tsv`; all literal pools re-read from ROM bytes.

Peripheral window (0xffffe400+ HCAN0, 0xffffe600+ HCAN1): BCR/MBCR/MBIMR/IMR/
LAFM/MC bytes as listed in §2, all symbol-named in `symbols.tsv`.

## 9. Limits

- Record bytes +12..+15 are now attributed (§3): +12 is the MBIMR interrupt-mask
  bit, +13..+15 are zero in every ROM block (reserved). The buffer pointer at
  +8..+11 is consumed by the TX queue / RX dispatch paths (e.g. 0x99b0 for
  0x201), not by the setup/compare chain traced here.
- `ref_canSetup` 0xd9f4 runs at key-on init (0x61a8 → 0x1102a → 0x2a1a0 → jsr
  0x2a1a4) **and** on CAN error recovery: the OS task-7 supervision chain
  (0x63f0 → 0x114b0 → 0x2a248 → 0xdcc0) re-runs it via bsr 0xdd86 when a HCAN
  bus-off (GSR bit0, 0x9ac4) or the error latch 0xffffa40a is active with the
  engine running, once per episode (guard 0xffffa40c == 0), and calls
  `can_error_full_reset` 0xdade (bsr 0xdda8) after ≥ 1000 error polls.
- Static analysis plus harness-call emulator runs; no full-boot emulator trace
  of the task dispatch (the emulator's task-switch gap, see the OS scheduling
  report). The emulator's MULU.W/MULS.W/MUL.L operand-vs-MACL modeling zeroes
  the MBCR/MBIMR RMW results in-emulator (hardware puts the product in MACL);
  the §7 register check therefore used a corrected in-memory mulu patch —
  tracked as a new emulator discrepancy.
- The polarity of MBCR/MBIMR bits is from Sh7055h.pdf; which physical IDs are
  RX vs TX per variant is as stored in the blocks (§3 observed values), not
  cross-checked against a bus trace.
