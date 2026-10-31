# docs/

Documentation and investigations for the HEE reverse-engineering effort.

| Subfolder | Contents |
|---|---|
| `investigations/` | Dated writeups, one per question/subsystem, started from `TEMPLATE.md`. |
| `architecture/` | High-level maps: memory map, interrupt vectors, pinouts, CAN/UDS catalogs, clock tree. |
| `references/` | External datasheets, service-manual excerpts, forum threads, with URL + access date. |

## Rules

- Investigations are named `YYYY-MM-DD-<topic>.md` and must follow `TEMPLATE.md`:
  goal, method, findings, evidence, open questions.
- Reference external material by link (with access date) rather than committing large
  PDFs; commit only short excerpts where licensing allows.
- Keep a `docs/architecture/` page per major subsystem (ECU core, CAN gateway,
  immobilizer, etc.) and link to the detailed investigations from it.
