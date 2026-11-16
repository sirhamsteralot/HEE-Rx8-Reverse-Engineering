# subsystem-logic/

Subsystem documentation: one `*_report.md` per firmware subsystem, describing
what the subsystem *does* (control logic, task structure, dispatch tables,
memory maps) in the human-first format of [`TEMPLATE.md`](TEMPLATE.md)
(AGENTS.md rule 8): plain-language introduction, step-by-step body, then
pseudocode, with the mandatory memory map, validation and limits in the proof
section at the end.

**Placement rule.** Subsystem logic is **assumed identical across the ROM
bins until proven otherwise**, so the reports here are written against the
reference ROM `60E15120_N3J1E` and state that assumption. Per-ROM differences
(address shifts, calibration-specific behavior) are documented in the per-ROM
folders [`docs/investigations/<rom-id>/`](../investigations/README.md) and
linked from the report's `**Related reports:**` line — never re-derived in the
shared report. Evidence (review folders, validation records) stays in
`docs/investigations/` next to the ROM it was taken from.

## Rules

- New subsystem report → this folder, from [`TEMPLATE.md`](TEMPLATE.md);
  cross-link related reports instead of duplicating their content.
- Reports state current findings only — the single changelog prose allowed is
  one changelog table at the very top of the document (date, what changed,
  version); git history records how they changed.
- Inputs are cited by SHA-256 (from `binaries/manifest.csv`); `0x` addresses
  are reference-ROM addresses unless a linked per-ROM document says otherwise.
- `docs/investigations/` remains the home of per-ROM evidence, labeling passes
  and ROM-specific findings — see
  [`docs/investigations/README.md`](../investigations/README.md).
