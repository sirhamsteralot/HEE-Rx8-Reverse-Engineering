# docs/

Documentation, investigations, architecture maps, and references.

| Path | Contents |
|---|---|
| `investigations/` | One folder per ROM ID (e.g. `60E15120_N3J1E/`): subsystem `*_report.md` files, `reviews/`, `backups/`, evidence folders (`cross_ecu/`, `source_review/`, `math_units/`, `lookup_family/`, `readability/`, `defs-merge/`, `rx8defs-analysis/`), README. See [`investigations/README.md`](investigations/README.md). |
| `architecture/` | `hardware/` (pinout, `pcm_connections.tsv`, wiring review, provenance), `design/` (firmware design doc + graph stats), plus memory maps. |
| `references/` | Reference PDFs with trust notes, upstream repository links. See [`references/README.md`](references/README.md). |
| [`learnings.md`](learnings.md) | Session log: SH-2E encoding facts, pipeline pitfalls, patcher patterns, report format lessons. Read before starting analysis. |

## Rules

- Investigations are organized per ROM (`docs/investigations/<rom-id>/`); within a
  ROM, follow the per-folder READMEs. New ROMs get a new folder.
- Subsystem reports follow the 10-section format with mandatory function/RAM address
  tables and a plain-language §1a after the executive summary (template:
  [`investigations/60E15120_N3J1E/knock_control_report.md`](investigations/60E15120_N3J1E/knock_control_report.md); style example §1a:
  `ignition_timing_report.md`).
- Reference external material by link + access date; commit PDFs only in
  `references/` with a trust note; quote them by table/section in reports.
- Keep [`learnings.md`](learnings.md) updated with artifact-backed lessons.
