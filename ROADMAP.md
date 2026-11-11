# ROADMAP — HEE RX-8 PCM reverse engineering

Plan for reverse engineering and labeling the Mazda RX-8 (Series 1) PCM firmware
(Renesas SH7055 / SH-2E, big-endian, 512 KiB flash, 32 KiB RAM).

**How to read this file.** §Open work
lists what remains, in suggested pickup order; the discrepancy register at the
bottom tracks every known unknown (E = emulator, D = data/docs) — closing one
requires new evidence + a note in the relevant investigation doc, never a silent
resolve. Tags are stable so cross-references from other docs keep resolving: phases
P1–P6, work groups A–F with item numbers, register IDs (E/D). Closed items are
**pruned from this file** — their full records (evidence, closure plans) live in
this file's git history; an item's number is never reused. Group ↔ phase
map: A = P3 (calibration extraction), B = P1 residual (emulator fidelity), C = P2
residual (static labeling & gap closure), D = P2/P5 (cross-ROM propagation), E = P4
(reimplementation), F = P6 (toward hardware).

Groups A, B and D are complete. Group C (static labeling & gap closure) is
**reopened**: open items 14, 16–19, 21 — pick up 14 next (item 13 closed
2026-11-11: the `[ADDITIONAL SOURCE REVIEW]` comment sweep was applied to the
accepted TSVs, the per-subsystem labels JSONs and the subsystem report memory
maps; full record in this file's git history). The
audit snapshot: 3,355 functions in the 60E15120_N3J1E export, 931 named +
2,424 `FUN_` (function_index.tsv figures of 2026-11-11,
`reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv`).

## Open work — pick up here

Groups are in suggested pickup order. Each item lists scope, what it unblocks,
and where artifacts live.

### C. Static labeling & gap closure (P2 residual) — REOPENED (items 14, 16–19, 21)

- **C item 14 (open)** — sweep all decompiled function definitions and their
  header comments for merge/reduce/apply opportunities. Every file under
  `reverse-engineered/decompiled/60E15120_N3J1E/functions/` now stacks several
  comment blocks (`[ADDITIONAL SOURCE REVIEW]`, `[CROSS-ECU / RX8DEFS REVIEW]`,
  `[READABILITY RECONSTRUCTION]`, `[ROM address: ...]`), and the same bodies
  appear in the monolithic
  [`firmware_decompiled.c`](reverse-engineered/decompiled/60E15120_N3J1E/firmware_decompiled.c)
  and [`named/firmware_named.c`](reverse-engineered/decompiled/60E15120_N3J1E/named/firmware_named.c)
  — with C item 13 landing more review comments, some statements are now
  duplicated across blocks. Go through all of them: merge or drop redundant
  comment lines, apply the ones that belong in the canonical export (via the
  re-runnable pipeline passes, not hand edits), and keep the per-function files
  and the two monoliths in sync. Any rename/relabel still needs rule-7
  binary-level verification; run the pipeline validators + `python -m pytest
  tests/` after the pass.
- **C item 16 (open)** — apply all of today's findings to the decompiled C
  code itself. Today's passes (the DSC CAN arbitration labeling, merged as
  PR #55, and the idle speed control labeling, merged as PR #51) produced new
  function aliases, RAM aliases and review comments, but the decompiled artifacts still
  need a fresh pipeline run so they carry them: re-run the annotation +
  `integrate_reviewed_names.py` passes from `rebuild.sh` so every file under
  `reverse-engineered/decompiled/60E15120_N3J1E/functions/`, the monolithic
  [`firmware_decompiled.c`](reverse-engineered/decompiled/60E15120_N3J1E/firmware_decompiled.c)
  and [`named/firmware_named.c`](reverse-engineered/decompiled/60E15120_N3J1E/named/firmware_named.c)
  reflect the new names/comments (distinct from C item 13, which applies the
  comments to the label TSVs/JSON + reports, and C item 14, which
  merges/reduces the comment blocks themselves). Re-verify at the binary level
  per AGENTS.md rule 7 and run the pipeline validators + `python -m pytest
  tests/`; keep the passes re-runnable (rule 6c) rather than hand-editing the
  export.
- **C item 17 (open)** — update and review all existing documentation with the
  new insights. Today's passes (DSC CAN arbitration and idle speed control,
  both merged; plus the 311 `[ADDITIONAL SOURCE REVIEW]` comment
  sets) changed labels and cross-subsystem links — e.g. 0xffffbbb8
  `vehicle_not_moving` is now known to feed the idle A/C clutch gate 0x165d6,
  and `engine_max_torque_allowed` 0xffffbbd8 feeds the DSC timing derate
  0x1815c in the ignition report. Go through
  [docs/investigations/60E15120_N3J1E/](docs/investigations/60E15120_N3J1E/)
  (the README index, every existing `*_report.md`'s **Related reports:** line
  and §9 Limits/open questions), [`docs/learnings.md`](docs/learnings.md), and
  this ROADMAP's cross-references: add the new links, refresh stale statements
  that the new evidence supersedes, and fix any broken `.md` links (rule 8:
  cross-reference everywhere, never leave a bare code span). Factual changes
  must land in all artifacts at once (rule 11). Validate afterwards with
  `validate_reports.py` + `verify_claims.py` and a link + non-empty-size check
  on every touched doc. Sequencing: do this after C items 13–16 so the docs
  reflect the applied labels, not just the raw comments.
- **C item 18 (open)** — update the ECU definitions in
  [data/definitions/](data/definitions/) from the new investigations. The
  recent passes (DSC CAN arbitration, idle speed control, alternator control,
  the ignition timing chain) confirmed or refined table/scalar semantics and
  descriptor meanings that the RomRaider XML defs should reflect — e.g. new or
  corrected table descriptions for the CAN 0x212-derived signals, idle
  target/air tables and alternator drag-torque tables, and any scalar
  meanings pinned by the source-review comments. Use the re-runnable defs
  passes (`extend_defs_all_roms.py` per-ROM regeneration + `relabel_merged_def.py`
  splice, per AGENTS.md rule 6c): keep `<description>` a short user-facing
  what-the-table-does sentence with no addresses/provenance/pass markers
  (rule 6b), and record provenance in
  `data/labels/60E15120_N3J1E/defs_table_labels.json`. Sequencing: after C
  items 13/16 so the defs pick up verified labels, and re-run the defs-merge
  checks + pipeline validators afterwards.
- **C item 19 (open)** — audit **all** "thunk"-named functions, not just one:
  53 rows in
  [rx8defs-analysis/function_labels.tsv](docs/investigations/60E15120_N3J1E/rx8defs-analysis/function_labels.tsv)
  carry a `thunk` name — 51 generic `thunk_FUN_xxxxx` indirect-call stubs
  plus 0x35d36 `ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN` and 0x5fd3c
  `ref_updateFaultStatusTHUNKNoR6_`. Determine what "thunk" means upstream:
  the bodies are bare register-indirect calls (e.g. 0x35d36 is
  `(*unaff_r14)()`, 14 bytes, exact-byte match to 60E0FC00 0x36456), so the
  name may just be a "not sure what this calls" marker, not a semantic label.
  For each, trace the indirect register at its call site(s) against the raw
  ROM (start with 0x35d36, called only from the write dispatcher 0x35a8c via
  dispatch pools 0x35b70–0x35b84, and 0x5fd3c from the fault-status path),
  resolve the real target where possible, then keep or demote each label per
  rule 6 (never keep a plausible name): rename pure uncertainty markers to
  `candidate_*` indirect-call labels and record the evidence in the relevant
  report + label TSV/JSON. The 0x35d36 case currently carries our
  `e2ram_write_thunk` (medium) label from the E2RAM device-layer pass
  (merged as PR #54;
  [e2ram_device_layer_report.md](docs/investigations/60E15120_N3J1E/e2ram_device_layer_report.md)
  §9 Limits) — decide whether the target is `e2ram_shadow_byte_write`
  0x37ea4 or a device-write path.
- **C item 21 (open)** — consistency audit of **all** label artifacts applied
  to date. The ignition-timing follow-up (C item 12, closed — record in this
  file's git history) found the same cell promoted in one artifact but not the
  other, evidence-less stub rows, and a reader column naming the consumer
  instead of the producer. Sweep every alias applied so far and fix the same
  classes of defect everywhere (counts measured on current main + this
  branch from the artifacts themselves):
  - [accepted_ram_aliases.tsv](docs/investigations/60E15120_N3J1E/source_review/accepted_ram_aliases.tsv):
    470 rows, 22 still with an empty evidence column;
    [accepted_lookup_aliases.tsv](docs/investigations/60E15120_N3J1E/source_review/accepted_lookup_aliases.tsv):
    48 rows, 26 empty (`accepted_function_aliases.tsv` is clean: 504/504).
  - TSV → labels-JSON direction (verify_claims.py only checks JSON → TSV):
    10 RAM rows (`ffff87b0`, `ffff8900`, `ffffd286`, `ffffd3c0`, `ffffd3c2`,
    `ffffd458`, `ffffd4e4`, `ffffd5fc`, `ffffd688`, `ffffd930`) and 3 function
    rows (`0005fd38`, `0005fd3c`, `0005fd4a`) are in the accepted TSVs but in no
    per-subsystem labels JSON under
    [data/labels/60E15120_N3J1E/](data/labels/60E15120_N3J1E/).
  - JSON side: 293 unique RAM addresses and 33 function addresses across the
    labels JSONs carry an empty/missing `evidence` field.
  - reader/writer columns: where the column is meant to name the producer,
    check it does (e.g. 0xffffa5e8 is written by 0x11f00 and read by 0x123da).
  For each finding: re-verify against the raw ROM/disassembly (AGENTS.md
  rule 7), then fill the evidence / add the missing counterpart / correct the
  column in **all** artifacts at once (rule 11), update the subsystem
  report's memory map if a name changes, and extend the per-subsystem test.
  Deliver per subsystem (rule 11); run the pipeline validators +
  `python -m pytest tests/` after each batch. Overlaps discrepancy D12 (the
  4-field-row parser failure in `annotate_source_review.py`) — fix the rows,
  not the parser, in this item. symbols.tsv currently covers all 470 RAM TSV
  rows; keep it that way.
### E. Reimplementation coverage (P4)

- **E item 1 (open)** — grow `reverse-engineered/reimplementation/` per labeled
  subsystem with host tests **and** emulator cross-checks (`harness.py` +
  `tests/test_phase1_dynamic.py` pattern). Implemented so far: `rx8_math`, `rx8_apv`,
  `rx8_knock` — knock-retard state machine 0x13a60/0x13b40 +
  `rx8_add_u8_saturate` 0x2478, host tests plus
  `tests/test_knock_retard_dynamic.py` emulator cross-checks.
  Remaining subsystems: fueling chain, load model, ignition timing, intake
  solenoids, limiter.

### F. Toward hardware (P6) — GATED

No vehicle flashing without bench validation (AGENTS.md rule 10). Preferred bench
path: upload the patched blob to a **bench ECU over the OBD port** via UDS 0x34
RequestDownload / 0x36 TransferData / 0x37 RequestTransferExit (ISO-TP on CAN
0x7E0/0x7E8, after 0x10 session + 0x27 security unlock) — the same route
Rx8Man-class tools use on a car. CN400 **BOOT mode is recovery-only** (it erases
flash before any read), not the test path.

- **F item 1 (open)** — pre-validate patchers (`utilities/scripts/patchers/`) in
  the emulator first — including the "fast RAM logging" patch via the virtual
  OBD port — then bench-ECU OBD upload.
- **F item 2 (open)** — recovery only: BOOT-mode via CN400 needs ~150 Hz square
  wave on pin 3 (thread §8; verify **D9** pinout conflict against `Sh7055h.pdf`
  first).
- **F item 3 (study done, implementation open)** — live-tuning feasibility:
  stock ROM already supports live logging (Mode 22 PIDs + UDS 0x23 after 0x27
  unlock); live *writes* need a patch (no 0x2E; app 0x34/0x36/0x37 are stubs) —
  RAM-shadow of hot cal tables (idle-free window 0xffff8000–0xffff92ff 4,864 B on
  all 11 ROMs; 3,852 B static-free after removing code-referenced cells, largest
  contiguous 1,087 B at 0xffff8109–0xffff8547) + write service in a code cave
  (per-ROM app free flash 899 B–21,956 B; 196 B cave 0x7fb8c–0x7fc4f on all ROMs)
  + PC tool over CAN/ISO-TP (J2534 on car, emulator TCP port in dev).
  See [live_tuning_feasibility_report.md](docs/investigations/60E15120_N3J1E/live_tuning_feasibility_report.md)
  + [free_resources_report.md](docs/investigations/60E15120_N3J1E/free_resources_report.md).
- **F item 4 (open)** — reconcile the OBD upload path with our static finding that
  the app's 0x34/0x36/0x37 handlers (0x5d7bc/0x5d834/0x5d874 on 60E15120_N3J1E) are
  NRC stubs and real flashing code lives in the SBL BOOT (0x1ad6/0x1c04/0x1d30/
  0x1d78): check session/security gating of the app handlers and whether an
  unlocked app 0x34 hands off to the SBL over OBD. Bench-ECU OBD upload is the
  accepted working path; the ROM-side mechanism is still open.

---

## Discrepancy register

### Emulator fidelity (E-items)

| ID | Status | What |
|----|--------|------|
| E4 | partial | RCAN mailbox model done for diag path + CAN RX interrupt fires on inject (IVT 0x378 → CAN poll 0x11d88 + scheduler 0x9630); full mailbox/interrupt fidelity open |
| E6 | partial (still open) | CAN RX (0x378) autonomous; wake 0x3db0 fires when CMI10B tick delivered; UDS entry 0x680a0 gated by vehicle latch word 0xffff9ec8 bit0; OS tick arming (task[8]→0x7778) circular without first scheduler pass → response TX still via profile `uds` entry points; pending-interrupt delivery on ldc/rte. The deep dive ([os_scheduling_deep_dive_report.md](docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md)) maps the full scheduler model and reproduces the post→queue→dequeue→handler→taskEnd→dispatch chain in the emulator; the ISR-exit context switch (0x32f4) still does not fire autonomously from idle (preemption needs class > ctrl[0] unsigned, ctrl[0]=0xff at boot) — that is the remaining E6 gap |
| E8 | open | opdec.OPMNEM keyed on full 16-bit words from the 60E15120 corpus (9,902 entries); family-B ROMs use operand encodings absent from it (e.g. 0xda29 `mov.l @(0x29*4,pc),r10` in 60E0FC00 dispatcher 0x55c14) → UnknownOpcode; family-B profiles boot but diag dispatch is not dynamically executable until the opcode table is widened. See [cross_rom_mode22_pid_handlers.md](docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md) |
| E9 | open | emulator `sh2e.py` `_op_mull`/`_op_mulsw`/`_op_muluw` write the product to the operand register `r[t[1]]` instead of MACL (Sh7055h.pdf: MULU.W Rm,Rn → MACL, registers unchanged). Consequence: firmware RMW idioms `mulu.w` + `sts macl` (e.g. HCAN MBCR/MBIMR setup at 0x9d58-0x9d82 and compare at 0x2a596/0x2a5a2) compute 0 in-emulator, so HCAN mailbox direction/interrupt-mask registers cannot be dynamically validated until fixed. Evidence + workaround run in [can_mailbox_config_report.md](docs/investigations/60E15120_N3J1E/can_mailbox_config_report.md) §7/§9 |

### Data / docs discrepancies (D-items)

| ID | Status | What |
|----|--------|------|
| D1 | documented | N3ZHE-vs-N3J1E cal ID — both strings coexist in-ROM: fw id `60E15120` at 0x2000, `N3J1E_1W.Z05` at 0x6c000, `SW-N3ZHEB000.HEX` at 0x6c043/0x6c046, `15120 ` at 0x6c05c; PIDs 0xe611/0xe21b-0xe21e/0xff40-0xff43 return them ([uds_mode22_dispatch_report.md](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md)) |
| D2 | open | package-pin ↔ connector-terminal is board routing unless traced; pinout markers needed |
| D7 | open | 60E1B800 dual N3* strings |
| D9 | open | BOOT CN400 pinout conflict — verify against Sh7055h.pdf before bench |
| D12 | open | `annotate_source_review.py` fails on clean main too: 38 pre-existing 4-field rows in `docs/investigations/60E15120_N3J1E/source_review/accepted_ram_aliases.tsv` (row count verified on main and on the PR #33 head). Noted in PR #33 and deliberately left as-is there (no drive-by fix, AGENTS.md rule 9); fixing the parser/rows is its own work unit |

The tables above are summaries; the full per-item records (locations, impact,
closure plans) live in this file's git history.
Summary rules: [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md) and `docs/references/`.
Discrepancies are **documented, never silently resolved** — closing one needs new
evidence (ROM bytes, manual table, bench trace, Renesas diff) + a note in the
investigation doc.

---

## Standing rules for every phase

Evidence label ladder (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`), binary
immutability, mandatory binary-level verification + pipeline validators after any
pass, 10-section subsystem reports with memory maps, one subsystem per work unit
delivered as a branch + PR against `main` ([`AGENTS.md`](AGENTS.md) §Branch & PR
workflow) with one logical change per commit, `hash_binaries.py --check` after
touching `binaries/`, emulator changes get a Renesas differential run. See
[`AGENTS.md`](AGENTS.md) and [`docs/learnings.md`](docs/learnings.md).
