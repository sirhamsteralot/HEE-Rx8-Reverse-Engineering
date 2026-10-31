# AGENTS.md — RX-8 PCM Reverse Engineering Workspace

Guidance for agents working in this workspace. This root folder is **not** a git
repository; it contains several independent repositories plus non-versioned
analysis output. Follow the section that matches the folder you are touching.

## What this workspace is

Reverse engineering of the Mazda RX-8 (Series 1) PCM/ECU — a Renesas SH-2E
(SH7055) big-endian CPU with 512 KiB flash / 32 KiB RAM — and the maintenance of
RomRaider ECU definitions for it. Deliverables are: analysis C exports, XML table
definitions, logger definitions, and a reflash tool. No firmware source exists;
everything is derived from ROM binaries.

## Layout

| Path | Contents | Git |
|---|---|---|
| `Mazda_RX8_PCM_ReverseEngineering/` | Stock ROM `.bin` dumps, data binaries, Ghidra `.gar` archives, utility scripts | Yes (equinox311) |
| `RX8Defs/` | RomRaider ECU + logger XML definitions (upstream) | Yes (equinox311), state matters — commits are referenced by hash in merge reports |
| `RX8Defs_Copy/` | Local working copy of RX8Defs used as merge input | — |
| `Rx8Man/` | PCM reflash tool (Tactrix); `RX8Man.exe` binary | Yes (Rx8Man) |
| `RomRaider/` | Installed RomRaider distribution (Java) | No |
| `reverse_engineered/60E15120_N3J1E/` | Full decompilation export, scripts, metadata, reviews | No — analysis output |
| `reverse_engineered/Defs/` | Merged/reviewed `rx8defs.xml` plus merge reports and validation | No — analysis output |

Each git repo has its own remote and history. Never commit in one repo on behalf
of another, and never restructure folders — scripts encode the workspace layout
by relative path (`rebuild.sh` expects `../..` to be this root).

## Session learnings

See [learnings.md](learnings.md) for the accumulated practical lessons of the
2026-10-29/30 sessions (verification method, SH-2E encoding gotchas, pipeline
pitfalls, patcher patterns, pinout handling, report format).

## Reference documents (workspace root) — use these during reverse engineering

PDFs at this root are **primary reference sources**; consult them before guessing
pin/register/terminal facts, and cite them by table/section in reports:

| File | What it is | Use it for | Trust caveats |
|---|---|---|---|
| `Sh7055h.pdf` | Renesas **SH7055F hardware manual** (ADE 602-155B) | Chip-level truth: register map, Tables 1.2/1.3 pin functions & package pin numbers, PFC/port control, ATU-II channel→pin mapping (TO8A–TO8P etc.) | Vendor document — authoritative for the silicon |
| `mazda-rx-8-pcm-pinout-series-1.pdf` | Series-1 PCM connector pinout compiled from the official Mazda FSM terminal table + `13Electrical.pdf` wiring colours | PCM connector terminal → signal/component mapping (e.g. injectors 2M/2J/2G/2D/3A/3D, solenoids 1L/1O/1W/5Z, APV 3B/3G/3J/1S/1U) and wire colours | Generated from the wiring book; **no chip-pin numbers** (package-pin ↔ terminal is board routing, unresolved here). Honour its own markers: unmarked colour = confirmed, `*` single-source, `†` conflict, `³` high-power only, `–` unread (v3: only 5L/5Z unread). Mirrored colour pairs not independently re-verified |
| `13Electrical.pdf` | Original RX-8 Electrical wiring book (copy-protected; diagrams are page images) | Underlying circuit diagrams behind the pinout | Text extraction yields mostly page headers — read via renders; treat as image source |

Rule: firmware dataflow comes from the ROM; physical pin/terminal associations from
these documents; the two meet only at the SH7055F package pin. Never assert a
package-pin ↔ connector-terminal link from the pinout alone — that is board
routing. When the pinout is updated (v2/v3…), re-diff it and propagate changes into
`hardware/pcm_connections.tsv`, `hardware/firmware_annotations.tsv` and the
`[WIRING REVIEW]` blocks in the synchronized views.

## Core rule: evidence discipline

This project's central convention. Interpretations are ranked and labeled, and
claims must never exceed their evidence.

- `FUN_xxxxxxxx` — unnamed routine, identified by address only.
- `ref_` — name inherited from the reference ROM's project (may be wrong, even
  misspelled; do not "fix" without new evidence).
- `CAL_` — label from XML annotations, **not** independently verified.
- `tbl_` — a lookup *descriptor* pointer, not raw cell storage.
- `inferred_` — RAM meaning derived from a table axis it feeds; weaker than a
  name backed by diagnostic dataflow.
- Use "candidate" language for unproven findings (e.g. "alternator
  torque-estimate candidate"). Do not upgrade a candidate to a fact because it
  is plausible or repeated.
- Address suffixes are part of the name: two addresses may hold related but
  distinct quantities (e.g. two different coolant-temperature values).
- Distinguish physical pin associations from firmware dataflow from unverified
  board routing (see `reverse_engineered/60E15120_N3J1E/hardware/`).
- Known discrepancy kept deliberately: `60E15120_N3J1E.bin` contains `N3ZHE`
  at the calibration-ID address while the filename/XML say N3J1E. Do not resolve
  this by editing bytes.

## Never modify binaries

- Stock ROMs, data captures and EEPROM dumps are immutable inputs. Never patch,
  re-save, or "fix" bytes in a `.bin`.
- XML definitions are editor metadata, not firmware patches — but the same rule
  applies: no ROM addresses or bytes are ever changed by definition work.
- If a change seems to require touching a binary, stop and report instead.

## Decompiling a ROM / working with raw binaries

All decompilation work happens in `reverse_engineered/60E15120_N3J1E/`; the
scripts there are the workflow. Read the target's `README.md` and
`metadata/input.json` before starting.

### Prerequisites

- Ghidra 12.1.3 with `GHIDRA_HOME` set, JDK 21+ on PATH, Python 3, a C compiler.
- Install the local SH-2E processor config first: copy
  `processor/sh-2e.ldefs` and `processor/sh-2e.slaspec` into
  `$GHIDRA_HOME/Ghidra/Processors/SuperH/data/languages/` and compile with
  `support/sleigh` (this modifies the Ghidra installation, not this workspace).
  Import with `-processor SuperH:BE:32:SH-2E -cspec default`. Do not use SH-2A.
- The reference project (`reference_project/RX8_6`, ROM `60E0FC00.bin`) must be
  present and restored; its `script_stuff/` CSVs (`regs_7055_180.csv`,
  `ivt_7055.csv`) supply peripheral-register and interrupt-vector definitions.

### Binary facts to assume

- 512 KiB big-endian ROM at 0x00000000–0x0007ffff; RAM 0xffff6000–0xffffdfff;
  volatile I/O 0xffffe000–0xffffffff. Initial PC/SP are the first two 32-bit
  words of the ROM.
- Firmware ID string at 0x2000; calibration ID at 0x6c046.
- All instruction addressing is 2-byte aligned; validation enforces 2-byte
  instruction width.

### Full pipeline (`scripts/rebuild.sh NEW_PROJECT_NAME`)

Always pass a **new** project name; the script leaves the source ROM unchanged
and writes a fresh project plus regenerated export/metadata. Stages:

1. `ExportReference.java` — run against the reference project (read-only):
   dumps every reference function's body bytes to
   `metadata/reference_functions.tsv`.
2. `prepare_metadata.py` — reads `RX8Defs/RomRaider/rx8_defs.xml` for the
   matching ROM ID to produce `metadata/calibration_labels.tsv` (`CAL_` labels);
   byte-matches reference function bodies into the target ROM to produce
   `metadata/matched_functions.tsv`. A match must be unique in the ROM,
   even-aligned, and ≥12 bytes; reference `FUN_` names stay address-based,
   named reference functions become `ref_` names. Records the ROM's SHA-256,
   IDs and reset vectors in `metadata/input.json`.
3. Import + `SetupTarget.java` — creates the ROM/RAM/IO memory blocks with
   correct R/W/X and volatile flags, labels peripheral registers from the
   reference CSVs, applies calibration labels with "semantic annotation, not
   independently validated" comments, and processes **only the defined
   architectural vectors** (never scan reserved vector slots as pointers).
   Seeds matched functions with plate comments recording the match evidence.
4. `RefineTarget.java` — scans every 4-byte-aligned ROM word for pointers
   (0x400–0x6c000, even targets) whose target begins with an SH register-save
   prologue (`sts.l pr/mov.l` opcodes `0x4f22`, `0x2f06`); creates function
   candidates marked as heuristic boundaries in
   `metadata/recovered_pointer_seeds.tsv`. Also fixes the five verified
   float-helper prototypes (`rx8_first_order_filter`, etc.) from observed
   FPU register use.
5. `RecoverDispatch.java` — walks the 99-record, 12-byte dispatch table at
   0x5f10c–0x5f5af, creating handler functions; writes
   `metadata/diagnostic_dispatch.tsv`. The table's diagnostic purpose is
   inferred, not proven.
6. `AnnotateHardware.java` + `ExportTarget.java` — decompiles everything to
   `decompiled/`: per-function C files, `firmware_decompiled.c`,
   `firmware_disassembly.asm` (with instruction bytes),
   `function_index.tsv`, `callgraph.tsv`, `symbols.tsv`,
   `decompiler_issues.tsv`, `analysis_summary.json`.
7. Python annotation/refinement passes (`annotate_cross_ecu.py`,
   `name_lookup_variables.py`, `integrate_reviewed_names.py`,
   `refine_readability.py`, `refine_lookup_family.py`, …) and finally
   `validate_export.py` + `write_report.py`.

### Interactive work

For manual analysis, open `ghidra_project/RX8_SH2E.gpr` (after installing the
processor config). Remember the saved database does not contain the newest
review annotations — the C export is ahead of it. Any manual Ghidra findings
must be written back into `metadata/` TSVs or a review folder, not left only in
the database.

### Verification after any binary work

Run from `reverse_engineered/60E15120_N3J1E/`:

```sh
cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off \
  reconstructed/rx8_math.c reconstructed/test_rx8_math.c -lm -o /tmp/rx8_math_test
/tmp/rx8_math_test
python3 scripts/validate_export.py
```

`validate_export.py` re-checks the ROM hash, every exported instruction's bytes
and alignment against the untouched ROM, all reference matches, and
index/file linkage, then writes `metadata/validation.json`. Run it after any
change that touches the export, metadata or decompiled views.

### Binary-RE conventions

- Byte-match seeding is not proof of semantic identity: reference function
  bodies can omit delay-slot instructions or have imperfect boundaries. Treat
  seeded names as hypotheses; keep the plate comments that record evidence.
- Prologue-heuristic and dispatch-derived functions are candidates until
  individually inspected. Never delete the "heuristic boundary" markers.
- Bytes not decoded as instructions are tracked in
  `decompiled/non_instruction_ranges.tsv`; they are unclassified, not unused —
  vectors, tables, strings and padding live there, and possibly unidentified
  code.
- Record every new discovery (function seeds, RAM candidates, dispatch
  knowledge) in the matching `metadata/` or review folder with evidence and a
  `validation.json`, following the existing TSV formats.
- **Binary-level verification is mandatory for every review pass.** Labels
  assigned from the decompiled C must be re-checked against the raw ROM and
  the disassembly before a pass is claimed done: instruction bytes vs ROM,
  RAM aliases vs the reader function's literal pool (mov.w low16 + 0xffff
  high-half idiom, mov.l full32, mov #imm immediates, or base+offset for
  indexed arrays), constants vs pool/shared-pool literals (watch for
  decompiler constant folding — e.g. a hysteresis lower bound may be encoded
  as threshold minus an offset, not as its own literal), table descriptors
  re-parsed from ROM bytes, and GPIO/port claims vs the actual register
  address + mask + helper call in the disassembly. External pin tables (e.g.
  `Sh7055h.pdf`) must be quoted by table/line. Record the verification
  results (what was checked, what was corrected) in the review folder's
  `README`/`REVIEW_NOTES` and `validation.json`. Never let a label stand on
  the decompiled C alone.
- Ghidra C is a reading aid: `undefined*`, `CONCAT`/`SUB`/`ABS` macros and
  register-derived parameters are not valid high-level C. When reconstructing
  compilable C (see `reconstructed/`), verify register-level semantics against
  the disassembly, keep it C11/strict-warning clean, and write host-side tests
  — while acknowledging host tests do not validate SH floating-point
  rounding/exception behavior.

## Working with the decompilation export

Root: `reverse_engineered/60E15120_N3J1E/` — start from its `README.md` and the
per-folder READMEs (`named/`, `cross_ecu/`, `source_review/`, `math_units/`,
`readability/`, `lookup_family/`, `hardware/`).

Key facts:

- Architecture: SuperH SH-2E (SH-2 + FPU), big-endian, **not** SH-2A. Ghidra's
  stock SH-2A definition over-accepts instructions; use the local
  `processor/` configuration. Project to open: `RX8_SH2E` (the older
  `RX8_N3J1E` SH-2A project is superseded).
- Canonical outputs: `decompiled/firmware_decompiled.c` (integrated names),
  `named/firmware_named.c` (synchronized readable copy), per-function files in
  `decompiled/functions/`, indexes in `decompiled/*.tsv`.
- If you rename functions or globals, update **all** synchronized views and the
  rename map `metadata/integrated_names.json`. Historical filenames and
  provenance comments keep original identifiers.
- The saved Ghidra database (`ghidra_project/`) lags behind review annotations;
  C files carry the newest names. Don't assume the `.gpr` reflects them.
- Before a large integration pass, keep a pre-change backup under `backups/`
  (precedent: `backups/pre_name_integration.zip`). Every review folder has a
  `validation.json`; run the matching verifier before claiming a pass.

## Working with RomRaider definitions

- Upstream: `RX8Defs/` (RomRaider XML: `rx8_defs.xml`, `logger_rx8_defs.xml`,
  plus `ECUFlash/` definitions). `RX8Defs_Copy/` is the local merge input.
- Reviewed merge output: `reverse_engineered/Defs/` with
  `merge_review.py`, repair records and `validation.json`.
- Definition edits must cite evidence: unique ROM data/axis-pointer match for
  dimension corrections, descriptor dispatch/wrapper calls for storage-type
  corrections. Repairs target one ROM; do not generalize them to other
  calibration blocks.
- A zero descriptor byte means float only in the scaled dispatcher; raw
  wrappers choose their own storage independently.
- Definitions from upstream (DTC mappings, immobilizer) may be retained without
  being validated against this ROM — say so, don't silently treat them as
  verified.

## Claims and reports

- Reports record inputs by hash and upstream commits by hash. When producing new
  merge/review reports, record the exact input state (file SHA-256, commit).
- Validation proves what it lists, nothing more: byte checks, matches and
  linkage — not semantic equivalence, correct function boundaries, or behavior
  on real hardware. Never write "verified working" beyond what a validation
  artifact actually covers.
- Decompiler output limits still apply: unknown calling conventions, hardware
  register side effects, interrupt state, indirect dispatch. A clean
  decompilation is not a correctness certificate.
- New findings go in the appropriate review folder with a `README.md` update and
  a `validation.json`, following the existing per-folder structure.
- **Subsystem report format (template: `knock_control_report.md`).** Every
  subsystem review (knock, fueling, intake, …) must produce a root-level
  `<subsystem>_report.md` in the knock report's exact structure, so reports
  stay checkable:
  1. header (date, target ROM + SHA-256, static-analysis-only disclaimer);
  2. executive summary with the headline finding;
  3. "How it works" condensed **pseudocode** of the whole chain;
  4. key calibrated tables / ROM constants table;
  5. labeling applied (counts, pipeline script, record json, backup);
  6. corrections made in the pass (incl. binary-verification corrections);
  7. files table;
  8. validation (which scripts, what they prove);
  9. **memory map for validation** — function address table (address, name,
     role), core RAM address table (address, name, meaning), ROM data/tables/
     entry points, and a "how to validate" pointer (disasm file, function
     files, alias TSVs). Addresses are mandatory — a report without the
     function/RAM address tables is incomplete;
  10. limits (candidate names, unresolved items, no-execution caveat).
  The detailed evidence lives in `reviews/<subsystem>/README.md` (+ a
  sceptical `REVIEW_NOTES.md` addendum and `validation.json`); the root report
  is the condensed, address-complete summary.

## Validation and verification with extreme scepticism

Repeatable, mandatory end-of-pass sequence (run from
`reverse_engineered/60E15120_N3J1E/`):

1. `python3 scripts/validate_export.py` — ROM SHA-256, every exported
   instruction byte, reference matches, index/file linkage.
2. `python3 scripts/verify_readability.py` and `python3 scripts/verify_math_units.py`.
3. `python3 scripts/validate_reports.py` — parses every root-level
   `*_report.md` and verifies, against the export and the raw ROM: required
   report sections (knock template), the quoted ROM hash, every function-table
   address against `function_index.tsv` (with the `candidate_` prefix rule),
   every RAM-table address against `accepted_ram_aliases.tsv` /
   `integrated_names.json`, every address inside the correct memory window
   (ROM / RAM 0xffff6000-0xffffdfff / volatile I/O 0xffffe000+), and ROM data
   claims of the form `0xADDR = VALUE` re-read from the ROM. Writes
   `metadata/report_validation.json`; exits non-zero on any failure.
4. Binary-level label verification (per the Binary-RE conventions bullet):
   re-check RAM aliases against reader literal pools and constants against
   pool/shared-pool literals in the disassembly, remembering the SH-2E idioms
   (mov.w low16 + 0xffff high half, mov.l full32, mov #imm, base+offset for
   indexed arrays) and decompiler constant folding (hysteresis bounds may be
   threshold-minus-offset). Record what was checked and what was corrected in
   the review folder's README/REVIEW_NOTES and validation.json.

Scepticism rules: never let a label or report claim stand on the decompiled C
alone — route it back to the ROM bytes/disassembly; treat `ref_` names as
inherited hypotheses and `candidate_` names as unproven; quote external
documents (e.g. `Sh7055h.pdf`) by table/section; distinguish firmware
dataflow from physical pin routing; keep package-pin → connector-terminal as
board-level unresolved unless a trace proves it.

## Git and publishing

- Pushes to any of the GitHub remotes are shared-state actions: get explicit
  user approval first, once per branch.
- Never rewrite history in `RX8Defs/` — its commit hashes are cited as merge
  provenance in reports.
- Binary blobs (ROMs, `.gar` archives, `.zip`, `.exe`) are intentional parts of
  these repos; do not add them to gitignore or attempt to strip them.
