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
linked from the report's proof-section related-reports list (§4.7) — never
re-derived in the shared report. Evidence (review folders, validation records) stays in
`docs/investigations/` next to the ROM it was taken from.

## Rules

- New subsystem report → this folder, from [`TEMPLATE.md`](TEMPLATE.md);
  cross-link related reports instead of duplicating their content.
- One report per subsystem, full stop. ROADMAP items are work units, not report
  boundaries: if part of a subsystem's behavior is executed by another
  subsystem's code (e.g. the boot handover runs in the SBL block), it is a
  section of that subsystem's report here — decide by where the code lives,
  never open a second report for the same subsystem.
- Reports state current findings only — the single changelog prose allowed is
  one changelog table at the very top of the document (date, what changed,
  version); git history records how they changed. Reports are factual
  design/operation documents: no "findings" wording, no Q&A-style phrasing,
  no meta commentary about the document's own layout, and no template
  scaffolding lines in the final document.
- Inputs are cited by SHA-256 (from `binaries/manifest.csv`); `0x` addresses
  are reference-ROM addresses unless a linked per-ROM document says otherwise.
- The applicable-ROMs table lists only ROMs actually investigated for the
  subsystem (the reference ROM always present) — never assert shared logic for
  an uninvestigated ROM; the shared-logic assumption lives in the header text.
- Subsystems that touch hardware get a hardware setup diagram (ASCII or
  mermaid) with the relevant peripherals, terminals and signals, distinguishing
  traced pin routing from firmware-level paths.
- Every report carries a structured overview diagram (ASCII or mermaid) near
  the start of its body: the subsystem's components and execution order — which
  tasks/batches run what, and in what order.
- Scope discipline: neighboring items mapped while tracing (other outputs on
  the same port bank, inputs read by the same expander, …) do not get body
  sections, memory-map rows or label entries in the report. Record them in
  §4.6 Limits with their key `0x` addresses, add a ROADMAP item for the
  subsystem they actually belong to if none exists, and cross-link it.
  Corrections to other documents go in §4.3 and are folded back into the
  source document in the same change.
- `docs/investigations/` remains the home of per-ROM evidence, labeling passes
  and ROM-specific findings — see
  [`docs/investigations/README.md`](../investigations/README.md).
