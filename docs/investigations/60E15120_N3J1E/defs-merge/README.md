# RX8 definition merge and source review — 2026-09-30

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

Dated comments were added to these four individual function files, the combined
C export, and the named C view. Executable C tokens and canonical function names
are unchanged; suggested names and confidence live in `function_findings.json`.
A backup is in `../60E15120_N3J1E/backups/pre_defs_20260930.zip`.

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

## Follow-up passes after the merge

- **2026-11-01 — DTC enable/disable address repair** (entry 83 in
  `definition_repairs.json`): per-ROM `DTC xxxx Enable/Disable #N` storageaddresses
  rebuilt from each ROM's own DTC layout (`repair_dtc_tables()` in
  `utilities/scripts/defs-merge/extend_defs_all_roms.py`); evidence in
  [`../dtc_control_report.md`](../dtc_control_report.md) §5 and
  [`../reviews/dtc_control/`](../reviews/dtc_control/README.md).
- **2026-11-02 — relabel/regroup pass**: [`relabel_2026-11-02.md`](relabel_2026-11-02.md)
  (ROADMAP D item 5).
- **2026-11-03 — DTC P-code labels** (entry 84 in `definition_repairs.json`, ROADMAP
  D item 6): `DTC 0420 …` → `DTC P0420 …` (standard 5-char OBD code; old `C167` →
  `U0167`) in all active blocks of the merged def via
  `utilities/scripts/defs-merge/relabel_dtc_names.py` (surgical splice, idempotent;
  pass log `dtc_pcode_labels_2026-11-03.json`) and in all per-ROM defs at generation.
  SAE J2012 mapping `data/dtc/pcodes.tsv` cross-checked against the Mazda workshop
  manual `input/4EngineControl.pdf` (DTC TABLE → `data/dtc/mazda_dtc_table.tsv`);
  Mazda wording preferred in descriptions. Evidence:
  [`../dtc_control_report.md`](../dtc_control_report.md) §5b; tests
  `tests/test_dtc_pcode_labels.py`.
