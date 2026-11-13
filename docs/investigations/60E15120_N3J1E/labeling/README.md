# labeling/ — the labeling and export-meta investigations (60E15120_N3J1E)

Everything in this folder is an investigation whose purpose was to **label
things** — name functions, RAM cells, lookup tables, calibration descriptors and
RomRaider editor entries — or to clean up the decompiled export itself. The
subsystem & logic descriptions live one level up, at the
[`60E15120_N3J1E/`](../README.md) root (`*_report.md` + `reviews/`).

## Labeling passes (evidence folders)

- [`cross_ecu/`](cross_ecu/README.md) — Denso/RX8Defs cross-ECU correlations:
  cross-ROM byte-match function aliases, RomRaider descriptor/logger matches,
  RAM candidates, and the cross-ROM differential-labeling and Mode 22 PID
  handler maps (all 14 ROMs).
- [`source_review/`](source_review/README.md) — additional source review:
  accepted function/RAM/lookup aliases (`accepted_*.tsv`) with confidence and
  per-row evidence.
- [`math_units/`](math_units/README.md) — math-helper renames and unit/scale
  annotations for constant-encoding calls.
- [`lookup_family/`](lookup_family/README.md) — axis-search/interpolation
  family reconstruction (register outputs, typed variants).
- [`readability/`](readability/README.md) — signature/local/structure/symbolic-
  constant reconstruction pass over the export, plus the unresolved
  lookup-call audit.
- [`comment_merge/`](comment_merge/README.md) — merge/reduce of the stacked
  review comment blocks across per-function files and both monoliths.
- [`defs-merge/`](defs-merge/README.md) — RX8Defs/RomRaider editor-definition
  merge, relabeling and upstream-splice records.
- [`rx8defs-analysis/`](rx8defs-analysis/README.md) — 60E15120 definition
  extension: verified table addresses/dimensions and `(inferred)` axis labels.

## Labeling / export-meta reports

- [`calibration_extraction_report.md`](calibration_extraction_report.md) —
  descriptor scan + cross-ROM diff behind `data/maps/` (table labeling at scale).
- [`decompiler_triage_report.md`](decompiler_triage_report.md) — decompiler-
  warning triage and non-instruction-range classification of the export.
- [`thunk_audit_report.md`](thunk_audit_report.md) — thunk/trampoline audit
  (which unnamed functions are pure jumps).
- [`free_resources_report.md`](free_resources_report.md) — corpus-wide free
  flash / free RAM scan (patch-planning resource map, not a subsystem).
- [`live_tuning_feasibility_report.md`](live_tuning_feasibility_report.md) —
  live-tuning feasibility study (patch + tooling; not a subsystem).

## Labeling review notes

- [`reviews/`](reviews/) — prove-or-demote passes over `candidate_*` and
  low-confidence labels, and the double-check of the large-control-body reports.
