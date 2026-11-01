# 60E0G500 / N3ZHEC — full pipeline export + label propagation — 2026-10-31

ROADMAP group C item 6 ("label 60E0G500 via the pipeline") + group D item 1
(differential labeling). Base: `binaries/dumps/aron-N3ZHEC-2026-10-31.bin`
(stock fw `60E0G500`, cal `N3ZHEC`, 512 KiB, SHA-256
`a33f79a4f1c47007fd95a667ef8a8e14740eb8522c0b26a4fc1022db7fd85db2`, per
`binaries/manifest.csv`).

## What was done

1. **Ghidra headless export** (Ghidra 12.1.2 from `input/ghidra_12.1.2_PUBLIC`,
   JDK 21; project DB in `input/ghidra-work/ghidra_60e0g500`, not committed;
   recipe `input/ghidra-60e0g500-export.sh`, log `input/ghidra-60e0g500-export.log`):
   SetupTarget → RefineTarget → RecoverDispatch → ExportTarget, same SH-2E
   processor config as the base ROM. Outputs:
   - `reverse-engineered/decompiled/60E0G500_N3ZHEC/` (3,200 functions, 0
     failures, 144 warnings; `analysis_summary.json`, `function_index.tsv`,
     `callgraph.tsv`, `symbols.tsv`, `firmware_decompiled.c`, `functions/`)
   - `reverse-engineered/disassembly/60E0G500_N3ZHEC/` (disassembly +
     `decompiler_issues.tsv` + `non_instruction_ranges.tsv`)
   - `data/labels/60E0G500_N3ZHEC/` (`input.json` with SHA-256/provenance,
     `recovered_pointer_seeds.tsv`, `diagnostic_dispatch.tsv`)
2. **Binary-level verification** (mandatory, rule 7): all 166,294 disassembly
   instruction words re-read against the raw dump and asserted equal;
   covered-byte count 332,588 == `analysis_summary.json`; function file count
   == index rows (3,200).
3. **Label propagation by byte-match** (`utilities/scripts/cross_rom_match.py`):
   2,582 of 3,355 base-ROM functions match 60E0G500 uniquely; **262 accepted
   function aliases** propagate (see
   [cross_rom_differential_labeling.md](../60E15120_N3J1E/cross_ecu/cross_rom_differential_labeling.md)
   and `cross_ecu/cross_rom_function_aliases.tsv` row set
   `dumps/aron-N3ZHEC-2026-10-31.bin`). The 3 streetport tunes match the stock
   dump at the same 2,582 functions — code identical, cal-only diffs (consistent
   with [2026-10-31-streetport-diff.md](2026-10-31-streetport-diff.md), whose
   "function mapping pending disassembly" status is now resolved).

## Follow-ups (not done here)

- The 60E0G500 export's own review passes (knock/fueling/intake label
  application, readability, cleanup) are base-ROM scripts keyed to
  `60E15120_N3J1E` via `paths.py`; running them for 60E0G500 needs a
  ROM-parameterized `paths.py` (group D tooling).
- `decompiler_issues.tsv` (144 warnings) for 60E0G500 can be triaged with the
  same categories as the base ROM (`triage_export.py`, currently base-ROM-keyed).
- Mode 22 PID handlers cross-ROM: base 0x5f10c table; in 60E0FC00 the dispatch
  area moved (e.g. `uds_service_dispatch_table_scan` 0x68dac → 0x6769c); a
  per-ROM PID map is group D item 2.
