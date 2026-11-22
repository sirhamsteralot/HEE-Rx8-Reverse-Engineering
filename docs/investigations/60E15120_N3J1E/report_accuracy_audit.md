# Report accuracy audit — status and applied corrections

Binary-level re-derivation of the subsystem reports against
`submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`) and
`reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm`.

Every report was checked against the binary when it was written, and the
pipeline validators re-check ROM hashes, instruction bytes, report sections and
prose claim shapes on every run
([`validate_export.py`](../../../utilities/scripts/rx8-pcm-pipeline/validate_export.py),
[`validate_reports.py`](../../../utilities/scripts/rx8-pcm-pipeline/validate_reports.py),
[`verify_claims.py`](../../../utilities/scripts/rx8-pcm-pipeline/verify_claims.py)).
Those checks do not re-derive *numbers*: a branch polarity, an access width, a
threshold or a caller attribution can be wrong while every validator stays green.
The audit below re-derives them claim by claim — read the disassembly, resolve
the literal pool, check the compare operands and the access instruction — and
records the mismatch together with the instruction address that settles it.

Continuation is tracked as a ROADMAP item; see
[`ROADMAP.md`](../../../ROADMAP.md) (open work, C group).

## Status

| Report | Home | State |
|--------|------|-------|
| [`fuel_pump_control_report.md`](../../subsystem-logic/fuel_pump_control_report.md) | subsystem-logic | **audited, corrections applied** (12 findings, 12 corrected) |
| [`alternator_control_report.md`](../../subsystem-logic/alternator_control_report.md) | subsystem-logic | **audited, corrections applied** (9 findings: 8 corrected, 1 refuted) |
| [`immobilizer_report.md`](../../subsystem-logic/immobilizer_report.md) | subsystem-logic | **audited, corrections applied** (12 findings, 12 corrected) |
| [`knock_control_report.md`](../../subsystem-logic/knock_control_report.md) | subsystem-logic | **audited, corrections applied** (9 findings, 9 corrected) |
| [`sbl_bootloader_report.md`](../../subsystem-logic/sbl_bootloader_report.md) | subsystem-logic | **audited, corrections applied** (7 findings, 7 corrected) |
| [`throttle_dbw_control_report.md`](../../subsystem-logic/throttle_dbw_control_report.md) | subsystem-logic | **audited, corrections applied** (12 findings, 12 corrected) |
| the 20 reports still at the `docs/investigations/60E15120_N3J1E/` root | investigations | not audited |

## Method

For one report: read it, list every claim that names an address, constant,
pool word, branch condition, access width, caller or table, then re-derive each
one from the disassembly and the raw ROM bytes, resolve the pool operand of the
`mov.l`/`mov.w @(disp,pc)` that loads it, and record the instruction address
that proves or refutes the claim. Nothing is applied to a report, its label
record or its review notes before that re-check (AGENTS.md rule 7), and once a
correction is applied the proof addresses move into the report's §4.3 and the
subsystem's `reviews/` folder.

Two machine checks carry the numeric load where a report has many of them: the
per-subsystem verifier under `utilities/scripts/rx8-pcm-pipeline/`
(`verify_fuel_pump_chain.py` is the pattern) re-reads every cited pool,
instruction word and ROM threshold and writes its log into the subsystem's
`reviews/` folder, with a pytest that re-runs it and compares the committed log.

## Applied findings — subsystem-logic reports

Every finding of this audit is applied: the report sentence, the label record and
the review notes state the corrected fact, and each report's §4.3 *Corrections*
carries the instruction addresses that prove it. The working evidence stays in the
matching `reviews/` folder, which is also where a claim is re-checked from.

| Report | Findings | Where the corrections are recorded |
|--------|----------|------------------------------------|
| [`alternator_control_report.md`](../../subsystem-logic/alternator_control_report.md) | 9 — 8 corrected, 1 refuted | report §4.3, [`reviews/alternator_control/README.md`](reviews/alternator_control/README.md) |
| [`immobilizer_report.md`](../../subsystem-logic/immobilizer_report.md) | 12 corrected | report §4.3, [`reviews/immobilizer/README.md`](reviews/immobilizer/README.md), [`REVIEW_NOTES.md`](reviews/immobilizer/REVIEW_NOTES.md) |
| [`knock_control_report.md`](../../subsystem-logic/knock_control_report.md) | 9 corrected | report §4.3, [`reviews/knock_control/README.md`](reviews/knock_control/README.md), [`REVIEW_NOTES.md`](reviews/knock_control/REVIEW_NOTES.md) |
| [`sbl_bootloader_report.md`](../../subsystem-logic/sbl_bootloader_report.md) | 7 corrected | report §4.3, [`reviews/sbl_bootloader/README.md`](reviews/sbl_bootloader/README.md) |
| [`fuel_pump_control_report.md`](../../subsystem-logic/fuel_pump_control_report.md) | 12 corrected | report §4.3, [`reviews/fuel_pump_control/README.md`](reviews/fuel_pump_control/README.md), [`REVIEW_NOTES.md`](reviews/fuel_pump_control/REVIEW_NOTES.md) |
| [`throttle_dbw_control_report.md`](../../subsystem-logic/throttle_dbw_control_report.md) | 12 corrected | report §4.3, [`reviews/throttle_dbw/README.md`](reviews/throttle_dbw/README.md), [`REVIEW_NOTES.md`](reviews/throttle_dbw/REVIEW_NOTES.md) |

The alternator report's submodule-path finding is **refuted**: the report header and
`alternator_labels.json` already read
`submodules/Mazda_RX8_PCM_ReverseEngineering/`, and `git ls-files submodules` lists
the directory under that name.

Statements the audit found under-specified rather than wrong — an unestablished
tick rate, a candidate flag name, a table cell encoding, an untraced on-car edge —
sit in each report's §4.6 *Limits* with their key `0x` addresses, so the open
question stays attached to the subsystem it belongs to.

## Reports not yet audited

The 20 reports still at the `docs/investigations/60E15120_N3J1E/` root are
migrated into [`docs/subsystem-logic/`](../../subsystem-logic/README.md) by the
C group's migration items; they are audited **after** their migration so each
subsystem is re-derived once, in its final shape. All six reports in
[`docs/subsystem-logic/`](../../subsystem-logic/README.md) are audited and
carry their corrections. The 20 root reports are the remaining queue; each is
audited in its own branch once its migration is merged, so every subsystem is
re-derived once, in its final shape.
