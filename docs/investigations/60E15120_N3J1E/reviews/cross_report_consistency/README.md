# Cross-report consistency audit (docs-wide)

**Date:** 2026-11-05 · **Scope:** all tracked Markdown under `docs/`, `README.md`,
`ROADMAP.md`, plus the source-review label TSV.
**Reference ROM:** `60E15120_N3J1E.bin`, SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`
(pinned submodule copy).

Trigger: the cross-reference pass ([PR #28]) made every mentioned `.md` file a
link; this audit walked that link graph and cross-checked the *facts* the
reports share. Method (three scans, all re-runnable from this folder's notes):

1. **Range/size arithmetic** — every `0xA–0xB` claim with a nearby size in the
   same sentence was re-computed (`B−A+1`). 2 violations found (below).
2. **Anchor cross-document comparison** — ~60 anchor facts (hashes, addresses,
   byte ranges, counts: VBR, cave, CVN hole, SBL gap, free-flash/RAM windows,
   cal starts, table counts, task/OS/checksum functions, seed/key, …) were
   grepped across all docs and every occurrence compared by hand.
3. **Binary verification** (AGENTS.md rule 7) — every suspected mismatch was
   re-checked against the raw ROM bytes and/or the committed disassembly
   (`hee_disasm_rom`), not against another report's prose.

## Findings and fixes applied

### 1. SBL erased-run end address (`live_tuning_feasibility_report.md`)

- **Claim (§1, §3 cave table, §8 checklist):** SBL-region all-0xFF run
  `0xb0e–0xfff`, 1,234 B — internally inconsistent: the same report's §10
  quoted the correct `0xb0e–0xfdf (1,234 B; …)`.
- **Binary:** `0xb0e–0xfdf` is all `0xFF` (verifiable span 1,234 B);
  `0xfe0–0xfff` is a 32-B non-erased block (identical bytes in all 11 ROMs per
  [flash-memory-layout.md](../../../../architecture/flash-memory-layout.md) §3).
  `0xb0e–0xfff` spans 1,266 B, so the claim failed the arithmetic scan twice.
- **Fix:** all three occurrences corrected to `0xb0e–0xfdf`, with the adjacent
  32-B block noted. ([free_resources_report.md](../../free_resources_report.md)
  §7 already documented this mismatch; its verification table quotes the old
  claim and is left as the historical record — a pointer to this audit was
  added there.)

### 2. IVT trampoline range/size/count (os_scheduler + deep dive + learnings + design doc)

- **Claims:** trampolines `(0x28c0-0x30d0)`
  ([os_scheduler_can_ivt_report.md](../../os_scheduler_can_ivt_report.md) §1 —
  internally contradicted by its own §2, which cites CAN RX "trampoline 0x31c0");
  `0x2710–0x31f0`, "14-byte trampoline", "every trampoline's first pool word =
  0x3238", "117 real-trampoline vectors (vec 64–230)"
  ([os_scheduling_deep_dive_report.md](../../os_scheduling_deep_dive_report.md)
  §2/§5/§8/§9; [learnings.md](../../../../learnings.md) "OS scheduling deep
  dive"; [design README](../../../../architecture/design/README.md) §4).
- **Binary:** every used interrupt vector (offsets `0x100–0x39c` = vec 64–231
  in the reports' own window) points at an identical 16-byte trampoline
  (8 words: `mov.l r0,@-r15; mov.l @(pool,pc),r0; sts.l pr,@-r15; jsr @r0;
  mov.l r1,@-r15; mov.l @(pool,pc),r1; jmp @r1; lds r0,pr`) followed by an
  8-byte pool `{handler, 0x3238}` — the *second* pool word (the `jsr` target) is
  the ctx-save `0x3238`, not the first. Strict pattern match over all
  `0x7fc50+off` slots: **119 vectors**, targets spanning **0x2710–0x3220**
  (first `0x2710`, last `0x3220`). The two highest were missed by the reports'
  `0x31f0` upper bound: slot `0x7ffd0` (vec 224) → trampoline `0x3220` →
  handler `0x5ec8`, and slot `0x7ffec` (vec 231) → trampoline `0x3208` →
  handler `0x5ef4`.
- **Handler classification (binary-ded):** `0x5ec8` =
  `mov.w @(0x5f02,pc),r4` (loads SR mask 0x00e0 literal) + `bra 0x5348` →
  fatal-trap class, so the fatal count is **99** (98 + this one). `0x5ef4`
  ORs a bit into a peripheral word and dispatches through `0x9c9c`
  (`jmp @r2` via pool literal `0x9c9c`, itself an indirect dispatcher) — its
  fatal-vs-real classification is **pending** (open question below). Hence
  119 = 99 fatal + 19 real + 1 pending.
- **Fixes:** range corrected to `0x2710–0x3220` and size to "16-byte code +
  8-byte pool" in all five documents; "first pool word" corrected to "second
  pool word (the `jsr` target)"; counts 117→119 (vec 64–231), 98→99 fatal,
  with the pending `0x5ef4` handler recorded everywhere the split is quoted
  (incl. `source_review/accepted_function_aliases.tsv` row
  `00005348 fatal_interrupt_trap`).

## Checks that came back consistent (no action)

- Reference-ROM SHA-256 prefixes and full hashes across all headers.
- VBR `0x7fc50` set at `0xd206`; CVN coverage `0x2000–0x7ffff` minus hole
  `0x7fb00–0x7fb7f` (engine `0x5a3f4`); code cave `0x7fb8c–0x7fc4f` (196 B).
- Free-RAM window `0xffff8000–0xffff92ff` (4,864 B), static-free 3,852 B,
  largest contiguous `0xffff8109–0xffff8547` (1,087 B) — all documents agree.
- Per-ROM free-flash totals (899 B–21,956 B), cal-start families
  (`0x6c000`/`0x6d000`/`0x71000`), per-ROM table counts (587/450/137 etc.),
  descriptor array `0x68ef8–0x6bc70`.
- fw-ID/cal-ID strings (`0x2000`, `0x6c000`, `0x6c043`, `0x6c046`),
  ROM corpus count (10 upstream + own dump = 11 unique).
- Task table: binary re-dump confirms base `0x4990`, `{param, stack, entry,
  mask}` 16-byte records, rec[0].entry `0x4998`, terminator `0x4ac0`
  (learnings' corrected layout). Documents using "task table 0x4998" mean
  rec[0].entry and say so where it matters — left as-is (wording, not fact).
- Idle loop `0x3dac`; os functions `0x3e10/0x3c2a/0x375c/0x3db0`; UDS `0x680a0`;
  seed/key `0x55f5e/0x5609e/0x5f084`; engine-speed RAM `0xffffb548` and the
  0.25 RPM/count scaling; 3,355 exported functions; 98-stub/fatal-trap
  semantics for reserved vec 0–63 (`0x53a0+` stubs → `0x5348`).
- DTC `0x60478` (reportable-gate) vs UDS dispatch row `0x5f478`: different
  functions, not a conflict (verified in both reports' context).

## Open questions

- **`0x5ef4` (vec 231) classification:** clears a peripheral flag then
  dispatches via `0x9c9c` (indirect jump through a code pointer table). Whether
  its chain ends in the fatal trap or serves an unmodeled interrupt source is
  not verified; recorded as pending wherever the 99/19/1 split is quoted.

## Files changed by this audit

- `docs/investigations/60E15120_N3J1E/live_tuning_feasibility_report.md`
  (SBL-run end: 3 occurrences)
- `docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md`
  (trampoline range §1; unused/fatal vector counts §9)
- `docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md`
  (range+size §2, §5 memory map, §8 counts, §9 vector-count note)
- `docs/learnings.md` (trampoline parsing gotcha: size/range/count/classification)
- `docs/architecture/design/README.md` (§4 diagram text: 99 of 119)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_function_aliases.tsv`
  (`0x5348` evidence note counts)
- `docs/investigations/60E15120_N3J1E/free_resources_report.md` (§7 pointer to
  this audit)
- this folder (`README.md`, `validation.json`)

## Validation

- ROM re-read in every binary check above; ROM hash matches
  `binaries/manifest.csv` conventions (submodule pinned copy, never modified).
- `python utilities/scripts/rx8-pcm-pipeline/validate_reports.py` — PASS after
  edits (report memory-map addresses re-checked against index/TSVs/ROM).
- Disassembly via `python utilities/scripts/hee.py hee_disasm_rom '{"rom_id":
  "60E15120_N3J1E","addr":"0x31f0","n":8}'` (and `0x2710`, `0x31c0`, `0x3208`,
  `0x3220`, `0x5ec8`, `0x5ef4`, `0x53c6`, `0x9c9c`).
- `hash_binaries.py --check` — OK (no binary touched).

[PR #28]: https://github.com/sirhamsteralot/HEE-Rx8-Reverse-Engineering/pull/28
