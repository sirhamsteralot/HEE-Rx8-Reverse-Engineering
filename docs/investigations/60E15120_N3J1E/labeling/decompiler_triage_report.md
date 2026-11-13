# Decompiler-warning triage + non-instruction-range classification report — 60E15120_N3J1E

Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — labels/triage only, no binary change). Static-analysis disclaimer: findings
come from the canonical export + disassembly + raw ROM bytes re-read by
`utilities/scripts/rx8-pcm-pipeline/triage_export.py` (ROM SHA-256 asserted against
`data/labels/60E15120_N3J1E/input.json` before any classification). No dynamic execution
was needed for this pass. Artifacts:
`reverse-engineered/{decompiled,disassembly}/60E15120_N3J1E/decompiler_issues_triaged.tsv`,
`…/non_instruction_ranges_classified.tsv`, `data/labels/60E15120_N3J1E/triage_export.json`.

**Related reports:** dispatch-table semantics cross-referenced with
[uds_mode22_dispatch_report.md](../uds_mode22_dispatch_report.md) (tables 0x5eb18/0x5eb40,
router 0x68dac); the scheduler warning with
[os_scheduler_can_ivt_report.md](../os_scheduler_can_ivt_report.md) (0x9630); export-cleanup
jump annotations with `refine_export_cleanup.py` (`data/labels/60E15120_N3J1E/export_cleanup.json`);
calibration-area descriptors with [calibration_extraction_report.md](calibration_extraction_report.md).

## 1. Executive summary

- All **154 decompiler-warning functions** (`decompiler_issues.tsv`) are now triaged into
  per-function verdicts in `decompiler_issues_triaged.tsv`: **151 benign, 3 actionable** —
  and all 3 actionable ones are resolved by this pass (2 record-dispatch tables recovered
  from ROM, 1 orphan 2-byte artifact proven unreferenced). No function needs a decompiler
  re-run; no label was upgraded on plausibility alone (label ladder, AGENTS.md rule 6).
- All **1,759 non-instruction ranges** (187,104 bytes = 35.7% of the ROM) are classified in
  `non_instruction_ranges_classified.tsv` by content **plus** referrer evidence from the
  disassembly's computed `@(0xEA,pc)` annotations: 1,695 ranges have pc-relative
  referrers (literal pools / tables reached by `mov.w`/`mov.l`/`mova`); 64 do not.
- **New find:** a 33-record keyed dispatch table at **0x5ea08** (34 × 8-byte records
  `{key:u8<<24, pad:3, handler:u32}`, terminator key 0x00 → default 0x54dce), scanned by
  **0x54d90** — a table the UDS pass did not cover (it starts at 0x5eb40). The second
  truncated jumptable, 0x55a7c `ref_OBDModeFunc_Unsure`, dispatches over the already-labeled
  0x5eb18 (5 × 8-byte, keys 0x02/0x04/0x06/0x08 + terminator → default 0x55aba); pool words
  0x54e34 → 0x5ea08 and 0x55c64 → 0x5eb18 verified as the only u32 references to those bases.
- **Orphan artifact:** 0x33b6 is a 2-byte "function" (`7638` = `add 0x38,r6`) followed by
  illegal word 0x0000; no u32 pointer, no branch target, no callgraph edge references it.
  The bytes 0x33b8–0x348f are a data block (classified `u32_table`, referenced by 0x31c's
  pool). `FUN_000033b6` stays address-only.

### 1a. Plain-language summary

The decompiler warned about 154 of the 3,355 functions. Almost all warnings are harmless
bookkeeping: dead code the decompiler deleted by itself (85), internal branch labels it
dislikes (42), and deliberate "spin forever" halt loops in the reset/main paths (15).
Three warnings hid real structure, and this pass dug them out of the raw ROM bytes:
two are searchable lookup tables of "which byte value → which handler routine" used by the
diagnostic (OBD/UDS) code, and one is a two-byte leftover that nothing calls — the bytes
after it are data, not code. Separately, the ROM is 35.7% "not instructions": jump tables,
pointer lists, float constants and strings that the CPU reads via PC-relative loads. Every
one of those 1,759 blobs is now classified with the instruction that references it, so
future passes can tell "literal pool" from "data table" at a glance.

## 2. Method / pseudocode

```
triage_export.py (run: python utilities/scripts/rx8-pcm-pipeline/triage_export.py)
 1. assert sha256(ROM) == metadata/input.json.sha256            # binary-level anchor
 2. scan firmware_disassembly.asm once:
      ea_refs[EA]  += (instr_addr, mnemonic)   for each @(0xEA,pc)   # computed EAs
      branch_targets |= {0x........}           for each bra/bt/bf/bsr operand
 3. for each non_instruction_range [start,end]:
      refs = ea_refs with EA in range
      class = first match: vector_table (start==0), zero/ff pad,
            ascii_string (printable>=0.6, run>=12, NUL/space present),
            ptr_pool_code/data/ram (all u32 in region), offset_table (u32<0x10000),
            float_pool (>=90% sane f32), cal_descriptor (>=0x6c000, >HBBII header),
            then by referrers: word_literal_pool (mov.w only), mixed_pool, u32_table/u16_data
      containing_function = bisect over function_index body spans
      -> non_instruction_ranges_classified.tsv (both decompiled/ and disassembly/)
 4. for each decompiler_issues row:
      verdict from issue category + per-address evidence:
        infinite_loop_block -> check body for self-branch (bra to itself) / rts
        jumptable_truncated  -> dump the 8-byte-record table from ROM via its pool word
        bad_instruction_data -> ROM-wide u32 scan + branch-target scan for references
        overlapping_symbol_labels -> count inner labels from symbols.tsv
      -> decompiler_issues_triaged.tsv; summary -> data/labels/60E15120_N3J1E/triage_export.json
```

## 3. Tables

### 3a. Non-instruction-range classification (1,759 ranges, 187,104 bytes)

| class | ranges | meaning |
|-------|-------:|---------|
| mixed_pool | 802 | per-function literal pool: mov.w literals + mov.l pointers interleaved, both referenced |
| u32_table | 696 | u32 content not matching a pointer/float/descriptor shape; referenced tables and pools |
| ptr_pool_code | 150 | all u32 targets inside code 0x40–0x68e3f (call/jump pointer tables) |
| word_literal_pool | 28 | referenced by mov.w only (sign-extended 16-bit literals) |
| u32_data | 27 | u32 content, no pc-relative referrer (reached via computed pointer) |
| u16_data | 19 | 16-bit content, no pc-relative referrer |
| ff_pad | 16 | erased-flash padding (all 0xff) |
| ptr_pool_ram | 11 | all u32 targets in RAM 0xffff6000–0xffffdfff |
| float_pool | 6 | ≥90% sane float32 (e.g. 0x25520 = −1.0207e-06) |
| ascii_string | 2 | 0x1ff2 firmware banner (`SBL_END…60E15120…Copr.DENSO2000S`), 0x3b04 Hitachi OS copyright V2.1A |
| vector_table | 1 | 0x0–0x3f: 16 IVT entries (12 code ptrs, SP 0xffffdfa0 ×2, 0xffffffff ×2) |
| zero_pad | 1 | 0x3cb0 |

1,695 of 1,759 ranges have ≥1 pc-relative referrer; the 64 without are data blocks
reached through pointer pools (e.g. the 84,254-byte block at 0x6a5c8, referenced only
via pool word 0x54e34-style indirection) or pure padding.

### 3b. Decompiler-issue verdicts (154 functions)

| verdict | count | meaning / action |
|---------|------:|------------------|
| benign_dead_code_removed | 85 | `unreachable_ram_block_removed` — Ghidra dead-block elimination; callgraph unchanged |
| benign_internal_labels | 42 | `overlapping_symbol_labels` — LAB_/DAT_/PTR_ labels inside the body are branch targets / inline pools |
| benign_halt_spin | 14 | `infinite_loop_block` with a `bra self` spin + normal `rts` path (reset/idle/fatal-halt idiom; e.g. 0xd8, 0xd21e `ref_main__`, 0x563de) |
| already_annotated | 5 | indirect-jump sites carrying [EXPORT CLEANUP] notes (0x40, 0x1090, 0x375c, 0x420c, 0x4218) |
| benign_decompiler_artifact | 2 | `decompiler_restart_space` / `heritage_after_dead_removal` (0x1ba20, 0x228dc, 0x5609e) |
| resolved_record_dispatch | 2 | 0x54d90 → table 0x5ea08 (33 records), 0x55a7c → table 0x5eb18 (4 records); see §3c |
| benign_infinite_loop | 1 | no-rts unconditional loop (reset path) |
| orphan_artifact_unreferenced | 1 | 0x33b6 — see §3d |
| recovered_case_table | 1 | 0x43c8 — byte-indexed case table recovered in export cleanup |
| benign_known_function | 1 | 0x9630 `os_schedule_task_event` — type-propagation warning only |

### 3c. Recovered record-dispatch tables (the actionable jumptables)

Both dispatchers share one code pattern (linear search, stride ×8 via `shll2`+`shll`,
key byte at record+0 compared to the incoming byte, target `u32` at record+4, first
key==0 record carries the default target):

| dispatcher | pool word | table base | records | keys | default |
|------------|-----------|-----------:|--------:|------|---------|
| 0x54d90 (callers 0x54be8, thunk 0x54d24, 0x54d28) | 0x54e34 = 0x0005ea08 | 0x5ea08 | 33 + terminator | 0x01,0x03–0x07,0x0c–0x13,0x15,0x1c,0x1f,0x21,0x2e–0x31,0x33,0x34,0x3c,0x42–0x45,0x47,0x49,0x4a,0x4c | 0x54dce |
| 0x55a7c `ref_OBDModeFunc_Unsure` (called via thunk at 0x6666c inside 0x665cc) | 0x55c64 = 0x0005eb18 | 0x5eb18 | 4 + terminator | 0x02,0x04,0x06,0x08 | 0x55aba |

Record format `{key:u8<<24, handler:u32}` matches the 8-byte tables already labeled in
[uds_mode22_dispatch_report.md](../uds_mode22_dispatch_report.md) §3 (0x5eb18 "caseD_22..26");
0x5eb40 right after it is the 29 × 12-byte UDS service table. The 0x5ea08 key space
(single-byte service/mode-like IDs 0x01–0x4c) is consistent with a diagnostic-mode
dispatch feeding 0x54d90's callers — semantics remain a `candidate_`-level hypothesis,
not upgraded here.

### 3d. Orphan artifact 0x33b6

Body = 2 bytes `7638` (`add 0x38,r6`); next word 0x0000 is illegal on SH-2E. ROM-wide u32
scan: no pointer to 0x33b6; branch-target scan: no branch to 0x33b6; callgraph: 0 callers.
0x33b8–0x348f is a 216-byte data block referenced by 0x31c's literal pool. Verdict: artifact;
`FUN_000033b6` kept address-only per the label ladder.

## 4. Labeling applied

None. This pass adds triage verdicts and classifications only; it does not rename symbols.
The two recovered tables (0x5ea08, 0x5eb18) are documented here and in
`data/labels/60E15120_N3J1E/triage_export.json` (`recovered_record_tables`); promoting
0x5ea08 to a `tbl_` label belongs to the UDS/OBD subsystem pass, not to triage.

## 5. Corrections

- Earlier ad-hoc classification attempts in-session mislabeled the 0x3f8–0x41b pool as
  "vector table" (it is 0x31c's word-literal pool; the IVT is only 0x0–0x3f) and caught
  pointer blocks / the 0x4414 shar-sled as "ascii_string". Final heuristics fixed both
  (see §2); the committed TSV is the corrected one.
- The UDS report's coverage boundary is now precise: its tables start at 0x5eb18/0x5eb40;
  0x5ea08 (33 records) was outside that pass and is documented here for the first time.

## 6. Files

- `utilities/scripts/rx8-pcm-pipeline/triage_export.py` — the triage (new, this pass).
- `reverse-engineered/decompiled/60E15120_N3J1E/non_instruction_ranges_classified.tsv` +
  `reverse-engineered/disassembly/60E15120_N3J1E/non_instruction_ranges_classified.tsv`
  (1,759 rows + header; raw `non_instruction_ranges.tsv` untouched).
- `reverse-engineered/decompiled/60E15120_N3J1E/decompiler_issues_triaged.tsv` +
  `reverse-engineered/disassembly/60E15120_N3J1E/decompiler_issues_triaged.tsv`
  (154 rows + header; raw `decompiler_issues.tsv` untouched).
- `data/labels/60E15120_N3J1E/triage_export.json` — summary, class/verdict counts,
  recovered tables, orphan evidence.
- This report.

## 7. Validation

- ROM SHA-256 asserted inside the script against `data/labels/60E15120_N3J1E/input.json`
  before any classification (`a7cd953c…264f1`); every ROM byte quoted here was re-read
  from the raw dump by the script (pool words 0x54e34/0x55c64, both record tables, the
  0x33b6 body/next-word, the 0x33b6 reference scan, class sample hex).
- `python utilities/scripts/rx8-pcm-pipeline/validate_export.py` — passes (3,355 function
  files, 168,592 instruction words byte-verified, 1,833 exact reference matches).
- `python utilities/scripts/rx8-pcm-pipeline/validate_reports.py` — passes incl. this
  report (sections, ROM hash, memory-map addresses vs `function_index.tsv`).
- Row counts asserted by the script: 1,759 range rows, 154 issue rows; verdict counts sum
  to 154.
- Not done: no Ghidra re-export (not needed — no warning requires a re-decompile), no
  dynamic emulator run (static triage only; the dispatchers 0x54d90/0x55a7c are candidates
  for a later `harness.py` sweep alongside the 0x5eb40 router check).

## 8. Memory map

### Functions

| address | name | body bytes | role |
|---------|------|-----------:|------|
| 0x00054d90 | FUN_00054d90 | 1204 | record-dispatch scan over table 0x5ea08 (pool word 0x54e34) |
| 0x00055a7c | ref_OBDModeFunc_Unsure | 236 | record-dispatch scan over table 0x5eb18 (pool word 0x55c64) |
| 0x000033b6 | FUN_000033b6 | 2 | orphan artifact (`add 0x38,r6` + illegal 0x0000), unreferenced |
| 0x00009630 | os_schedule_task_event | 110 | OS scheduler; type-propagation warning only |
| 0x0000031c | service_wdt_overflow_and_toggle_pb15 | — | WDT service routine; owns the word-literal pool at 0x3f8 |

### Data

| address | content |
|---------|---------|
| 0x0005ea08 | 34 × 8-byte records `{key:u8<<24, handler:u32}` (33 keyed + 0x00 terminator → 0x54dce) |
| 0x0005eb18 | 5 × 8-byte records (keys 0x02/0x04/0x06/0x08 + terminator → 0x55aba); already labeled in the UDS report |
| 0x00054e34 | pool word = 0x0005ea08 (only u32 ref to the table base) |
| 0x00055c64 | pool word = 0x0005eb18 (only u32 ref to the table base) |
| 0x00033b8–0x0000348f | 216-byte data block after the 0x33b6 artifact |
| 0x00001ff2 | firmware banner string (DENSO/Hitachi) |
| 0x00003b04 | Hitachi OS copyright string |

## 9. Limits

- Range classes are content+referrer heuristics, not proof of semantics: `mixed_pool` /
  `u32_table` split is by referrer mnemonics, and 64 ranges have no pc-relative referrer
  (reached via computed pointers) — their class is content-only.
- The 0x5ea08 table's key semantics (diagnostic mode vs service byte) is a hypothesis
  (`candidate_` level); closing it needs the caller analysis of 0x54be8/0x54d24/0x54d28,
  e.g. a dynamic sweep via `harness.py`.
- Verdicts for the 85 dead-code removals rely on Ghidra's CFG plus unchanged callgraph;
  individual removed blocks were not re-derived instruction-by-instruction (spot-checked
  representatives: 0x183a0 ×17, 0x4de1c ×14, 0x1506c ×8).
- 0x33b6's origin (why Ghidra made a function there) is unexplained; it is documented as
  an unreferenced artifact, not resolved to a cause.
