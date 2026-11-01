# 60E0G500 / N3ZHEC — full pipeline export + label propagation — 2026-10-31

ROADMAP group C item 6 ("label 60E0G500 via the pipeline") + group D item 1
(differential labeling). Base: `binaries/dumps/60E0G500_N3ZHEC.bin`
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
   `dumps/60E0G500_N3ZHEC.bin`).

## Follow-ups (not done here)

- The 60E0G500 export's own review passes (knock/fueling/intake label
  application, readability, cleanup) are base-ROM scripts keyed to
  `60E15120_N3J1E` via `paths.py`; running them for 60E0G500 needs a
  ROM-parameterized `paths.py` (group D tooling).
- `decompiler_issues.tsv` (144 warnings) for 60E0G500 can be triaged with the
  same categories as the base ROM (`triage_export.py`, currently base-ROM-keyed).
- Mode 22 PID handlers cross-ROM: base 0x5f10c table; in 60E0FC00 the dispatch
  area moved (e.g. `uds_service_dispatch_table_scan` 0x68dac → 0x6769c); a
  per-ROM PID map is group D item 2. **DONE 2026-11-01** — see the update below.

## Update 2026-11-01 — group D items 2 and 3

- **D item 2 (Mode 22 cross-ROM map, DONE):** the Mode 22 dispatch table was
  located in all 14 ROMs; this dump's table is at **0x5f8b0** (99 records, pool
  ref 0x57fec, count byte 0x5fd54), dispatcher **0x57ef0**, sub-PID table
  0x5fd56. All 99 PID→handler rows for this dump byte-match base handlers and
  were dynamically verified (99/99-PID sweep through the ROM's own dispatcher).
  Full report: [cross_rom_mode22_pid_handlers.md](../60E15120_N3J1E/cross_ecu/cross_rom_mode22_pid_handlers.md);
  data: `data/labels/cross_rom_mode22_pid_handlers.tsv` + per-ROM TSVs in
  `data/labels/cross_rom/mode22/`.
- **D item 3 (labels applied to this export, DONE):**
  `utilities/scripts/apply_cross_rom_labels.py` applied **236 renames** here
  (262 byte-match aliases, 28 non-function-start targets skipped, plus the
  table labels `tbl_diag22_dispatch_records_0005f8b0` /
  `tbl_diag22_subpid_supported_bits_0005fd56`): `function_index.tsv`,
  `callgraph.tsv`, `symbols.tsv`, `functions/*.c`, `firmware_decompiled.c`, plus
  the synchronized `named/` view (`firmware_named.c`, `lookup_aliases.tsv`,
  `validation.json`). Provenance:
  `data/labels/60E0G500_N3ZHEC/cross_rom_renames_applied.tsv`; pre-change backup
  (LFS) at `backups/pre_crossrom_names.zip`. The export header's ROM name was
  corrected (it said 60E15120_N3J1E). Audited byte-exact against the backup
  (19/19 checks): only identifiers changed; comments/strings untouched; ROM
  SHA-256 unchanged.
