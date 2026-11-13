# Thunk audit report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — asserted by the review script). All findings are from static analysis
of the raw ROM bytes, the disassembly and the canonical export. No hardware
execution was performed. Full per-row evidence:
[`data/labels/60E15120_N3J1E/thunk_audit_labels.json`](../../../../data/labels/60E15120_N3J1E/thunk_audit_labels.json)
and [`reviews/thunk_audit/README.md`](../reviews/thunk_audit/README.md).

**Related reports:** E2RAM write path (the 0x35d36 trampoline's target):
[`e2ram_device_layer_report.md`](../e2ram_device_layer_report.md); DTC set-fault
trampolines 0x5fd38/0x5fd3c/0x5fd4a: [`dtc_control_report.md`](../dtc_control_report.md)
and `data/labels/60E15120_N3J1E/dtc_thunk_labels.json`; IVT trampoline family
0x28c0–0x30d0 (same single-jump shape, kept as `FUN_` vector entries):
[`os_scheduling` labels](../../../../data/labels/60E15120_N3J1E/os_scheduling_labels.json);
upstream name provenance:
[`rx8defs-analysis/function_labels.tsv`](rx8defs-analysis/function_labels.tsv).

## 1. Executive summary

The export's label analysis carried **53 rows with a `thunk` name**. The audit
re-decoded every body from the raw ROM (big-endian SH-2E words, no trust in the
disassembler text) and traced every call site. Result:

- **51 of 53 are Ghidra auto-named single-jump functions** — 14 × 4-byte
  `bra <target>` and 37 × 6-byte `mov.l @(pool,pc),r3; jmp @r3; nop`. For all of
  them the jump target is fixed and ROM-proven (bra displacement, resp. the
  PC-relative literal pool read as a big-endian u32). "thunk" here is Ghidra's
  mechanical name for "function that is just a jump to another function" — it
  carries **no** "we don't know what this calls" meaning.
- **0x35d36** (`ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN` upstream) is the only
  true register-indirect stub (`jsr @r14`, 14 bytes). Its sole caller 0x35a8c
  loads r14 exactly once — at 0x35a94 from pool 0x35b74, which holds
  0x00037ea4 (`e2ram_shadow_byte_write`) — before all 14 dispatch arms
  `bra 0x35d36`. The target is therefore proven, not guessed: 0x35d36 is a
  tail-call trampoline to `e2ram_shadow_byte_write`, promoted from
  `candidate_e2ram_write_thunk` (medium) to `e2ram_shadow_byte_write_trampoline`
  (high). Its 14 bytes are byte-identical to 60E0FC00 0x36456.
- **0x5fd3c** (`ref_updateFaultStatusTHUNKNoR6_` upstream) is a conditional
  tail-jump to `dtc_set_fault` 0x5fe20, already resolved as
  `dtc_set_fault_xdefault` (high) by the DTC thunk-cluster pass; kept.

The 50 generic thunks without an existing label were renamed `jump_to_<target>`
(target alias when named, else the target's `FUN_` name, else the target address
for the three thunk-to-thunk chains 0x9f4c/0x9f52/0x9f58). No label was kept on plausibility;
every rename is backed by ROM bytes recorded in the label TSV/JSON.

## 1a. Plain-language summary

A "thunk" in this export is just a tiny detour: a function whose whole body is
"go somewhere else". The decompiler named those automatically
(`thunk_FUN_…`). This audit checked each detour against the actual ROM bytes
and found where every one of them really goes. One of them (0x35d36) looked
mysterious because it calls through a register — but its only caller fills
that register with a fixed address (the E2RAM shadow-write function 0x37ea4),
so even that one is fully resolved. Nothing here is an unknown call anymore.

## 2. How it works (condensed pseudocode)

```c
// Class A — 4-byte bra thunk (14 rows), e.g. 0x4e06:
//   word 0xaff2 = bra 0x4dee ; delay slot 0x0009 (nop)
void thunk_0x4e06(...) { goto FUN_00004dee; }          // target = addr+4+sgn12(disp)*2

// Class B — 6-byte pool-jmp thunk (37 rows), e.g. 0x6360:
//   word 0xd31e = mov.l @(0x63dc,pc),r3 ; 0x432b = jmp @r3 ; 0x0009 nop
void thunk_0x6360(...) { goto *(u32*)(pool); }          // pool = (addr+4 & ~3) + (w&0xff)*4
//   pool 0x63dc holds 0x00011492 (big-endian) -> FUN_00011492

// Class C — register-indirect trampoline (1 row), 0x35d36:
//   4e0b 0009 4f26 6cf6 6df6 000b 6ef6
//   jsr @r14 ; nop ; lds.l @r15+,pr ; pop r12 ; pop r13 ; rts ; pop r14
void trampoline_0x35d36(...) {                       // sole caller 0x35a8c:
    // 0x35a94: mov.l @(0x35b74,pc),r14  // pool 0x35b74 holds 0x00037ea4, loaded ONCE
    // 14 dispatch arms then: bra 0x35d36
    call 0x37ea4 /* e2ram_shadow_byte_write */ (...); // jsr @r14
    /* epilogue pops the frame 0x35a8c pushed -> tail call */
}

// Class D — conditional tail-jump (1 row), 0x5fd3c (kept: dtc_set_fault_xdefault):
//   extu.w r6,r3 ; tst r3,r3 ; bf/s skip ; mov.l @(0x5fe0c,pc),r6 // pool holds 0x0000ffff
//   bra 0x5fe20  // dtc_set_fault, with x defaulted to 0xffff when caller passed r6==0
```

## 3. Key tables / classes

| Class | Count | Body shape | Target proven from |
|---|---|---|---|
| bra | 14 | `bra target` + delay nop | bra displacement (word at entry) |
| pool_jmp | 37 | `mov.l @(pool,pc),r3; jmp @r3; nop` | big-endian u32 at pool |
| jsr_reg | 1 | `jsr @r14` + frame pops | sole caller's r14 load (pool 0x35b74) |
| other (conditional tail-jump) | 1 | 0x5fd3c, kept as `dtc_set_fault_xdefault` | bra 0x5fe20 + pool 0x5fe0c |

Named targets reached through thunks: 0x9c86 `can_rx_isr_handler` (via 0x5e78,
0x5eee — the CAN RX IVT path, dynamically exercised per the OS-scheduling
labels), 0xaee8 `adc_pair_correlation_fault_compute` (via 0xad2a), 0x37358
`dtc_state_machine_step` (via 0x576c2, kept as `diag22_pidc116_dtc_state_machine`).
All other targets are still-unnamed `FUN_` functions; the thunk labels name the
target without claiming semantics for it.

## 4. Labeling applied

- 50 generic thunks → `jump_to_<target>` (high): target = accepted alias when
  the target is named, else its `FUN_xxxxxxxx` index name, else `0x`+address
  (thunk-to-thunk chains 0x9f4c→0x6360, 0x9f52→0x6366, 0x9f58→0x636c).
- 0x35d36 → `e2ram_shadow_byte_write_trampoline` (high), replacing
  `e2ram_write_thunk` (medium) in `accepted_function_aliases.tsv`,
  `e2ram_device_labels.json` and `candidate_promotions.json`
  (moved to `promoted_to_high`).
- Kept unchanged: 0x5fd3c `dtc_set_fault_xdefault`, 0x576c2
  `diag22_pidc116_dtc_state_machine` (both already high from earlier passes).
- Applied to the export (function_index.tsv, callgraph.tsv, symbols.tsv,
  `functions/*.c`, `firmware_decompiled.c`, `named/firmware_named.c`,
  `integrated_names.json`) via the standard name-integration step; the review
  script `utilities/scripts/rx8-pcm-pipeline/review_thunk_audit_labels.py`
  re-derives and re-asserts every row from the ROM on each run (idempotent).

## 5. Corrections made in this pass

- `ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN` (0x35d36) was a misnomer for an
  "unknown indirect call"; the real `ref_writeToE2RAMArea_INDEX_ADDR_LEN`
  target is 0x37ea4 `e2ram_shadow_byte_write`, and 0x35d36 is a proven
  trampoline to it. Label promoted from `candidate_` (medium) to high.
- `ref_updateFaultStatusTHUNKNoR6_` (0x5fd3c) was already corrected to
  `dtc_set_fault_xdefault` by the DTC thunk-cluster pass — cross-checked here,
  not duplicated.
- Fixed three legacy non-UTF-8 bytes (cp1252 0x97 em-dash) in
  `source_review/accepted_function_aliases.tsv` (rows 0x13ecc, 0x12e60) and
  `source_review/accepted_lookup_aliases.tsv` (row 0x69208); they made
  `annotate_source_review.py` / `integrate_reviewed_names.py` crash on read.
  Rows fixed, parsers untouched (same class of defect as the known
  source-review parser discrepancy — left for the consistency-audit item).

## 6. Files

- `utilities/scripts/rx8-pcm-pipeline/review_thunk_audit_labels.py` — new
  idempotent audit/label script (wired into `rebuild.sh` after
  `review_candidate_promotions.py`).
- `utilities/scripts/rx8-pcm-pipeline/review_e2ram_labels.py` — 0x35d36 entry
  updated to the promoted label so rebuilds stay conflict-free.
- `docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_function_aliases.tsv`
  — 50 rows appended, 1 replaced (0x35d36).
- `data/labels/60E15120_N3J1E/thunk_audit_labels.json` — all 53 records with
  per-row ROM evidence; `e2ram_device_labels.json`,
  `candidate_promotions.json`, `source_review/validation.json` updated.
- Export artifacts renamed via name integration (see §4).
- `tests/test_thunk_audit.py` — standalone pytest re-checking all 53 bodies,
  pool/bra targets, the 0x35d36 r14 trace and the TSV/JSON/export consistency.
- This report + `../reviews/thunk_audit/README.md`.

## 7. Validation

- `review_thunk_audit_labels.py` asserts on every run: ROM SHA-256 unchanged;
  all 53 bodies word-exact; bra/pool target decode; 0x35d36's r14 written
  exactly once in 0x35a8c (at 0x35a94) with pool 0x35b74 holding 0x00037ea4;
  14 dispatch arms `bra 0x35d36`; byte-exact match of the 14 bytes with
  60E0FC00 0x36456. Re-run twice: second run adds/replaces 0 rows (idempotent).
- `python -m pytest tests/test_thunk_audit.py` — 9 passed, including dynamic
  emulator validation: the CAN RX interrupt (IVT 0x378) is traced
  0x31c0 → 0x5e78 → 0x9c86 with the injected 0x7e0 frame landing in the UDS RX
  buffer 0xffffddc8 (proves the pool-jmp class dynamically), and 0x35d36
  called with r14 = 0x00037ea4 exactly as caller 0x35a8c sets it is traced
  0x35d36 → 0x37ea4 and writes the shadow data+complement cells
  0xffffc28e/0xffffc38e (proves the jsr_reg trampoline dynamically). See
  `../reviews/thunk_audit/README.md` for the recorded output.
- Pipeline validators `validate_export.py`, `validate_reports.py`,
  `verify_claims.py` run from the repo root — clean (recorded in
  `../reviews/thunk_audit/README.md`).
- Binary-level rule: every label above cites ROM words/pools re-read this pass,
  not decompiled C alone.

## 8. Memory map for validation

### 8.1 Functions (ROM addresses) — all 53 audited thunk rows

| ROM address | New label | Class | Proven target |
|---|---|---|---|
| 0x00004e06 | `jump_to_FUN_00004dee` | bra | 0x00004dee (`FUN_00004dee`) |
| 0x00005e78 | `jump_to_can_rx_isr_handler` | pool_jmp | 0x00009c86 (`can_rx_isr_handler`) |
| 0x00005eee | `jump_to_can_rx_isr_handler` | pool_jmp | 0x00009c86 (`can_rx_isr_handler`) |
| 0x00006360 | `jump_to_FUN_00011492` | pool_jmp | 0x00011492 (`FUN_00011492`) |
| 0x00006366 | `jump_to_FUN_000113b8` | pool_jmp | 0x000113b8 (`FUN_000113b8`) |
| 0x0000636c | `jump_to_FUN_0000abfa` | pool_jmp | 0x0000abfa (`FUN_0000abfa`) |
| 0x000084c2 | `jump_to_FUN_00008b4c` | bra | 0x00008b4c (`FUN_00008b4c`) |
| 0x00009f4c | `jump_to_0x00006360` | pool_jmp | 0x00006360 (`0x00006360`) |
| 0x00009f52 | `jump_to_0x00006366` | pool_jmp | 0x00006366 (`0x00006366`) |
| 0x00009f58 | `jump_to_0x0000636c` | pool_jmp | 0x0000636c (`0x0000636c`) |
| 0x0000ad2a | `jump_to_adc_pair_correlation_fault_compute` | bra | 0x0000aee8 (`adc_pair_correlation_fault_compute`) |
| 0x0001038a | `jump_to_FUN_00010fa8` | pool_jmp | 0x00010fa8 (`FUN_00010fa8`) |
| 0x000146b6 | `jump_to_FUN_00013814` | pool_jmp | 0x00013814 (`FUN_00013814`) |
| 0x000146bc | `jump_to_FUN_0001381e` | pool_jmp | 0x0001381e (`FUN_0001381e`) |
| 0x0001686e | `jump_to_FUN_00015f74` | pool_jmp | 0x00015f74 (`FUN_00015f74`) |
| 0x00016874 | `jump_to_FUN_00015f8e` | pool_jmp | 0x00015f8e (`FUN_00015f8e`) |
| 0x00019e3c | `jump_to_FUN_0003ec3c` | pool_jmp | 0x0003ec3c (`FUN_0003ec3c`) |
| 0x00021b84 | `jump_to_FUN_0002508c` | pool_jmp | 0x0002508c (`FUN_0002508c`) |
| 0x00022248 | `jump_to_FUN_00025438` | pool_jmp | 0x00025438 (`FUN_00025438`) |
| 0x00022f80 | `jump_to_FUN_000486a0` | pool_jmp | 0x000486a0 (`FUN_000486a0`) |
| 0x00023766 | `jump_to_FUN_000236cc` | pool_jmp | 0x000236cc (`FUN_000236cc`) |
| 0x000253b2 | `jump_to_FUN_0002529e` | pool_jmp | 0x0002529e (`FUN_0002529e`) |
| 0x00025408 | `jump_to_FUN_000252a6` | pool_jmp | 0x000252a6 (`FUN_000252a6`) |
| 0x00028992 | `jump_to_FUN_000270aa` | pool_jmp | 0x000270aa (`FUN_000270aa`) |
| 0x00029070 | `jump_to_FUN_00029134` | bra | 0x00029134 (`FUN_00029134`) |
| 0x0002a3d4 | `jump_to_FUN_00028db0` | pool_jmp | 0x00028db0 (`FUN_00028db0`) |
| 0x0002a3da | `jump_to_FUN_00028db8` | pool_jmp | 0x00028db8 (`FUN_00028db8`) |
| 0x0002afec | `jump_to_FUN_0002b220` | bra | 0x0002b220 (`FUN_0002b220`) |
| 0x0002b298 | `jump_to_FUN_0002b8f4` | bra | 0x0002b8f4 (`FUN_0002b8f4`) |
| 0x0002b954 | `jump_to_FUN_0002b988` | bra | 0x0002b988 (`FUN_0002b988`) |
| 0x0002f11c | `jump_to_FUN_0002e800` | pool_jmp | 0x0002e800 (`FUN_0002e800`) |
| 0x00032d20 | `jump_to_FUN_00032d96` | bra | 0x00032d96 (`FUN_00032d96`) |
| 0x00034a28 | `jump_to_FUN_00034a64` | pool_jmp | 0x00034a64 (`FUN_00034a64`) |
| 0x00034a2e | `jump_to_FUN_00034a6c` | pool_jmp | 0x00034a6c (`FUN_00034a6c`) |
| 0x00035d36 | `e2ram_shadow_byte_write_trampoline` | jsr_reg | 0x00037ea4 (`e2ram_shadow_byte_write`) |
| 0x0003807c | `jump_to_FUN_00037fda` | pool_jmp | 0x00037fda (`FUN_00037fda`) |
| 0x00038118 | `jump_to_FUN_00038194` | bra | 0x00038194 (`FUN_00038194`) |
| 0x0003eb6c | `jump_to_FUN_0003e300` | pool_jmp | 0x0003e300 (`FUN_0003e300`) |
| 0x000490f8 | `jump_to_FUN_00049112` | bra | 0x00049112 (`FUN_00049112`) |
| 0x0004bd44 | `jump_to_FUN_0004bda2` | bra | 0x0004bda2 (`FUN_0004bda2`) |
| 0x00054d24 | `jump_to_FUN_00054d90` | bra | 0x00054d90 (`FUN_00054d90`) |
| 0x000565e4 | `jump_to_FUN_00056786` | bra | 0x00056786 (`FUN_00056786`) |
| 0x000576c2 | `diag22_pidc116_dtc_state_machine` | pool_jmp | 0x00037358 (`dtc_state_machine_step`) |
| 0x0005fd3c | `dtc_set_fault_xdefault` | other | — |
| 0x0005fd92 | `jump_to_FUN_000601b2` | bra | 0x000601b2 (`FUN_000601b2`) |
| 0x00064004 | `jump_to_FUN_00060c7a` | pool_jmp | 0x00060c7a (`FUN_00060c7a`) |
| 0x00064912 | `jump_to_FUN_00060c7a` | pool_jmp | 0x00060c7a (`FUN_00060c7a`) |
| 0x00068d64 | `jump_to_FUN_00054a00` | pool_jmp | 0x00054a00 (`FUN_00054a00`) |
| 0x00068d6a | `jump_to_FUN_00054b2c` | pool_jmp | 0x00054b2c (`FUN_00054b2c`) |
| 0x00068d70 | `jump_to_FUN_00054a36` | pool_jmp | 0x00054a36 (`FUN_00054a36`) |
| 0x00068d76 | `jump_to_FUN_00054aa0` | pool_jmp | 0x00054aa0 (`FUN_00054aa0`) |
| 0x00068d7c | `jump_to_FUN_00054b62` | pool_jmp | 0x00054b62 (`FUN_00054b62`) |
| 0x00068d82 | `jump_to_FUN_00054b98` | pool_jmp | 0x00054b98 (`FUN_00054b98`) |

### 8.2 Literal pools and key addresses (ROM)

| Address | Content | Meaning |
|---|---|---|
| 0x35b74 | 0x00037ea4 | r14 target loaded at 0x35a94 in caller 0x35a8c = `e2ram_shadow_byte_write` |
| 0x35b70–0x35b84 | 0xffffc268–0xffffc282 cells | dispatch src-cell pools (classified mixed pool 0x35b66–0x35b87) |
| 0x5fe0c | 0x0000ffff | x-default for the 0x5fd3c trampoline |
| per-thunk pool | see §8.1 target column | each pool_jmp's PC-relative literal (big-endian u32) |

### 8.3 How to validate

Re-run `python3 utilities/scripts/rx8-pcm-pipeline/review_thunk_audit_labels.py`
(any cwd; paths resolve via `paths.py`) — it re-reads the ROM and asserts every
row. `python -m pytest tests/test_thunk_audit.py` re-checks bodies, targets and
artifact consistency without the pipeline.

## 9. Limits

- Dynamic validation covers representative members of each class (0x5e78 via
  the CAN RX IVT, 0x35d36 via a direct harness call), not all 53 trampolines;
  the remaining classes are proven statically from the ROM bytes.
- 47 of 53 targets are still-unnamed `FUN_` functions; the audit proves the
  jump target, not the target's semantics.
- Cross-ROM propagation not done: only 0x35d36 was byte-matched against a second
  ROM (60E0FC00 0x36456); per-ROM thunk addresses/pools may differ.
- The IVT trampoline family 0x28c0–0x30d0 has the same single-jump shape but is
  left as `FUN_` vector entries (deliberately out of scope here).

## 10. Related subsystems

E2RAM device layer: [`e2ram_device_layer_report.md`](../e2ram_device_layer_report.md);
E2RAM NV storage: [`e2ram_nv_storage_report.md`](../e2ram_nv_storage_report.md);
DTC control (0x5fd3c trampoline family): [`dtc_control_report.md`](../dtc_control_report.md);
OS/scheduling (IVT trampolines, CAN RX path through 0x5e78):
[`os_scheduling_labels.json`](../../../../data/labels/60E15120_N3J1E/os_scheduling_labels.json);
upstream label provenance:
[`rx8defs-analysis/function_labels.tsv`](rx8defs-analysis/function_labels.tsv),
[`rx8defs-analysis/README.md`](rx8defs-analysis/README.md).
