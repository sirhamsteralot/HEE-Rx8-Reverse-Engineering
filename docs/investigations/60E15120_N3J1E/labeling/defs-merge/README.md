# RX8 definition merge and source review

`rx8defs.xml` combines RX8Defs at **ff5ab4f** with the local analysis in
RX8Defs_Copy (based on **944062e**). The ten most recent commits were reviewed;
`validation.json` lists them and records input hashes. Neither input repository
nor the ROM binary was modified. This is a RomRaider editor definition, not a
firmware patch. The existing reviewed logger remains in RX8Defs_Copy.

## Result

- All 478 locally annotated tables and 103 inferred axis labels were retained.
- Seven upstream target-table renames were correlated by data address, descriptor,
  axes and callers. New DTC mappings and the 60E32000 immobilizer definition are
  retained from upstream; their meanings are not validated against 60E15120.
- Six target tables received dimension corrections (seven dimension fields),
  including Alternator Duty Cycle Max: 7 to 11 points, and Table 3D - 76: 6×7
  to 10×8. Each correction requires a unique ROM data/axis-pointer match.
- 62 target storage types were corrected: 36 byte definitions actually use float
  interpolation; 26 use raw uint16 interpolation. Direct lookup wrappers and
  descriptor dispatch establish the storage. Float cells were checked for finite
  values. Existing display conversions were retained.
- 124 older descriptions were clarified: a zero descriptor byte means float only
  in the scaled dispatcher. Raw wrappers select their own storage independently.
  Some records remain unresolved where a direct call was not recovered.
- The missing Alternator Diagnostic Voltage Delta to DC template was recovered
  locally from descriptor 0x6a560: 13 uint16 points, multiplier approximately 0.01.
- Eleven missing DTC inheritance templates were supplied as local byte settings.
  The two upstream DTC 0300 #1 addresses, 0x7e678 and 0x7e679, retain distinct
  editor names. Their actual DTC identity remains unconfirmed.

These are **82 recorded target definition repairs**, with all 637 target entries
retained. No addresses or ROM bytes were changed. Other ROM blocks and the common
base remain byte-for-byte upstream; repairs for this ROM were not generalized.

## What the source teaches

**0x22a14 — throttle-request filter candidate.** Five renamed throttle tables
are indexed by a saved engine-speed value, including indirect descriptor
selection missed by the earlier direct-call inventory. The selected maximum
feeds a 2.0 hysteresis; increasing-factor candidates combine with a coolant
correction. A clamped coefficient drives the first-order filter and its output
is bounded. The filter mechanics are confirmed; individual gear flags and the
upstream increase/decrease descriptions are not independently established.

**0x1ce6c — fueling correction / enrichment-floor candidate.** Descriptor
0x69918 is a seven-point RPM lookup, enabled by RAM 0xffffb128 and stored to
0xffffb00c. This supports the new context but this routine does not itself
perform a minimum operation on the result. Calling the entire function an
“enrichment minimum” routine would overstate the evidence.

**0x2ce18 — alternator torque-estimate candidate.** The speed-indexed table at
0x6a790 is multiplied by a ratio, with a near-zero denominator guard, and stored
to 0xffffbcc4. This fits the new maximum-torque interpretation; neither Nm nor
the physical meanings of numerator and denominator are proven.

**0x618f8 — diagnostic byte-policy candidate.** Indexed reads at 0x7e704 branch
on zero/one, with related reads in four other functions. This confirms a policy
array, not the individual SAE DTC assignments in the upstream #1 bank.

These four individual function files, the combined
C export, and the named C view carry dated review comments. Executable C tokens and canonical function names
are unchanged; suggested names and confidence live in `function_findings.json`.
A backup is in `../../60E15120_N3J1E/backups/pre_defs_20260930.zip`.

## Verification and open findings

- XML parses. All 478 local changes merge without axis-label conflicts.
- 462 of 494 target lookup entries have matching descriptor geometry and supported
  storage types after repair. **32 remain open**: nine unmatched descriptors and
  23 without a sufficiently resolved storage path. This is structural validation,
  not confirmation of every table's physical meaning or scaling.
- The target has no remaining duplicate local names or missing local inheritance
  keys. **311 upstream inheritance findings remain in the common base/other ROM
  blocks**, including duplicate names and unresolved templates. Other variants
  are preserved, not certified for editing.
- Scaling comparisons are diagnostic: firmware scale and display scale can differ
  intentionally (AFR, time units, etc.). Some old generic conversions even have
  zero multipliers. They are recorded in `target_table_audit.json`, not silently
  replaced with firmware units. A `descriptor_verified` status does not certify
  the display conversion or physical units.
- Original ROM SHA-256, 3,355 function files, 168,592 instructions and 1,833 exact
  reference matches pass the existing export validator. Changed individual
  bodies remain synchronized with the combined C. A pre-existing mismatch for
  function 0x71ea was confirmed in the pre-change backup and was not altered.
- The local RomRaider parser supports per-ROM type/dimension overrides and
  descriptions. No GUI load or vehicle test was performed.
- The existing N3J1E XML identification versus N3ZHE binary calibration-ID mismatch
  remains unresolved. Firmware ID 60E15120 matches.

## Reproduction and evidence

Run from any directory:

```sh
python3 /home/yannick/Documents/Tuning/reverse_engineered/Defs/merge_review.py
python3 /home/yannick/Documents/Tuning/reverse_engineered/Defs/annotate_source.py
```

(This repo's live copy of the merger is
[`utilities/scripts/defs-merge/merge_review.py`](../../../../../utilities/scripts/defs-merge/merge_review.py).
The merger's review comments (`[RX8DEFS …]` markers) are baked into the
promoted export and re-derivable from `function_findings.json` above.)

The merger intentionally fails on unexpected local structural changes. Its
current inputs are the two local repositories and existing target source/ROM.
The generated `validation.json` pins their hashes and commits.

- `upstream_changes.json`: semantic table changes across the ten-commit window.
- `merge_log.json`: retained local annotations and rename decisions.
- `definition_repairs.json`: every target correction and its evidence.
- `target_table_audit.json`: per-table descriptor, storage, scale and caller checks.
- `renamed_table_evidence.json`: seven renamed tables and source references.
- `annotation_corrections.json`: old storage-annotation clarifications.
- `inheritance_issues.json`: unresolved common-base and other-variant issues.
- `function_findings.json`: new source interpretations, confidence and limitations.

## Follow-up work after the merge

- **DTC enable/disable address repair** (entry 83 in
  `definition_repairs.json`): per-ROM `DTC xxxx Enable/Disable #N` storageaddresses
  rebuilt from each ROM's own DTC layout (`repair_dtc_tables()` in
  `utilities/scripts/defs-merge/extend_defs_all_roms.py`); evidence in
  [`../dtc_control_report.md`](../../dtc_control_report.md) §5 and
  [`../reviews/dtc_control/`](../../reviews/dtc_control/README.md).
- **Relabel/regroup pass** (ROADMAP D item 5): pass log
  [`relabel_2026-11-02.json`](relabel_2026-11-02.json).
- **DTC P-code labels** (entry 84 in `definition_repairs.json`, ROADMAP
  D item 6): the standard 5-char OBD code (`DTC P0420 …`; slot code `0xC167` decodes
  to `U0167`) in all active blocks of the merged def via
  `utilities/scripts/defs-merge/relabel_dtc_names.py` (surgical splice, idempotent;
  pass log `dtc_pcode_labels_2026-11-03.json`) and in all per-ROM defs at generation.
  SAE J2012 mapping `data/dtc/pcodes.tsv` cross-checked against the Mazda workshop
  manual `input/4EngineControl.pdf` (DTC TABLE → `data/dtc/mazda_dtc_table.tsv`);
  Mazda wording preferred in descriptions. Evidence:
  [`../dtc_control_report.md`](../../dtc_control_report.md) §5b; tests
  `tests/test_dtc_pcode_labels.py`.
- **Defs update from the subsystem investigations** (idle target/air, alternator
  control, DSC CAN arbitration, ignition timing): 47 new curated table labels
  in [`data/labels/60E15120_N3J1E/defs_table_labels.json`](../../../../../data/labels/60E15120_N3J1E/defs_table_labels.json)
  (built by `utilities/scripts/defs-merge/build_table_labels.py`) — idle target
  RPM variants/filter, idle air output/feedback/correction/A-C tables, the
  alternator field-drive/duty/voltage-target/drag-torque tables, and the CAN
  0x212-derived DSC Mode C max-throttle table (descriptor 0x6a150, gated by the
  0x212 mode bit 0x40 → 0xffffbbcc in 0x218c4) — applied to the merged 60E15120
  block by `relabel_merged_def.py` (renamed=47, added=0, pass log
  [`relabel_2026-11-02.json`](relabel_2026-11-02.json)) and propagated to every
  per-ROM def by `extend_defs_all_roms.py` via the cross-ROM structural match.
  The 12 remaining verified literal-pool scalars are now also exposed as 1-cell
  `Scalar - …` entries in every per-ROM def (14 total; `SCALAR_ENTRIES` in
  `extend_defs_all_roms.py`), with per-scalar provenance in the
  `scalar_entries` section of `defs_table_labels.json`. Binary-level re-check
  (descriptor re-parse 47/47, scalar f32 re-decode 18/18, DSC mode-C pool chain)
  recorded in [`validation.json`](validation.json)
  `defs_update_from_investigations`; checks: `tests/test_defs_relabel.py`,
  `tests/test_extract_scalars.py`, full pytest suite and the pipeline validators
  all green.
- **Upstream RX8Defs sync splice** (`d95b0be` DTC switch rework + `39d98a0`
  immobilizer patch addresses): applied to all three local def files (merged
  def, reviewed copy, upstream snapshot) by
  [`utilities/scripts/defs-merge/splice_upstream_dtc_immo.py`](../../../../../utilities/scripts/defs-merge/splice_upstream_dtc_immo.py)
  (surgical expat line-span splice, idempotent; pass log
  [`upstream_splice_39d98a0.json`](upstream_splice_39d98a0.json)), so every XML
  under `data/definitions` carries the same DTC categories/form. The pass
  re-verifies the immo start pattern and the switch "off" blob against the ROM
  bytes (0x34b10 / 0x34f5c on 60E15120_N3J1E) on every run. Local DTC names are
  kept (P-code in the merged def, legacy 4-hex in the other two files); bare
  block-level DTC overrides stay bare and inherit the new Switch form from
  RX8Base. `repair_dtc_tables()` in `extend_defs_all_roms.py`
  emits the same Switch form (Enabled=01/Disabled=00, categories
  "DTC - MIL Illuminate" / "DTC - OBD Report" / "DTC - Unknown") for every
  per-ROM def. Sync record:
  [`../rx8defs-analysis/upstream-sync-validation.md`](../rx8defs-analysis/upstream-sync-validation.md);
  tests `tests/test_defs_upstream_sync.py` (all XMLs under `data/definitions`
  checked for the new form + ROM-verified immo addresses). The same splice pass
  also applies the remaining `39d98a0` category rename
  (`Fuel Target (Closed Loop)` → `Fuel Injection - Closed Loop`) to every table
  that explicitly carries the old category, folded in together with the
  `defs_table_labels.json` label-map category update (9 entries);
  `relabel.py` re-applies the label-map category on re-run, so the per-ROM defs
  regroup accordingly and `tests/test_defs_relabel.py` needs no rename alias.
  Table names are not renamed in our reviewed files (the upstream
  `Table 3D - UNKNOWN_CL` → `Closed Loop Fueling Base` rename is
  cross-referenced in
  [`../../fueling_control_report.md`](../../fueling_control_report.md) §10.7
  instead).
