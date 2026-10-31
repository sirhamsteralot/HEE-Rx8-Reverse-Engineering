# 60E15120_N3J1E.bin — reconstructed C

The export contains **3,355 identified functions** decompiled from the target ROM.
This is reverse-engineering analysis C, **not the original source or a buildable
replacement ROM**. Five small routines have also been rewritten as compilable C.

## Wiring-assisted extension

See [the series-1 wiring review](hardware/README.md) for 35 documented component
connections, 16 firmware annotations and three additional compilable APV-candidate
helpers. Physical pin associations remain explicitly distinguished from firmware
dataflow and unverified board routing.

## Denso and RomRaider extension

See [the cross-ECU and RX8Defs review](cross_ecu/README.md) for descriptor matches,
diagnostic/RAM candidates and assembly corrections. This extension annotates the
C export; the saved Ghidra database has not received these new annotations.

See also [the additional source review](source_review/README.md) for G-ROM,
diagnostic and CAN findings added on 2026-09-09.

## Integrated reviewed names

The canonical `decompiled/firmware_decompiled.c` and individual C files now include
all accepted review aliases and explicitly marked lookup-axis candidates. The function
index and call graph use the updated names. Historical filenames and provenance
comments retain original identifiers. `named/firmware_named.c` is a synchronized copy.
The saved Ghidra database is unchanged. A pre-integration backup is retained at
`backups/pre_name_integration.zip`; the complete rename map is in
`metadata/integrated_names.json`.

See [math helpers and unit conversions](math_units/README.md) for the latest
helper naming and scale/offset annotations integrated into the canonical C.

See [signature, local, structure and constant reconstruction](readability/README.md)
for the latest readability pass and unresolved lookup-call audit.

See [the axis-search/interpolation family reconstruction](lookup_family/README.md)
for recovered register outputs, typed variants and per-function analysis records.

## Export cleanup — 2026-10-29

`scripts/refine_export_cleanup.py` post-processes the export without touching
the saved Ghidra database or the ROM:

- 19 function names that were each shared by two addresses (38 functions,
  inherited `ref_` names and thunks) now carry address suffixes, removing the
  duplicate C definitions. Call sites, callgraph, symbols and the named view
  were updated. The one caller with two same-named thunk calls (0x61092) was
  resolved from its jsr constant loads.
- The two `UNRECOVERED_JUMPTABLE` trampolines (0x40, 0x1090) are documented as
  register-indirect tail jumps; the parameter is renamed `indirect_target`.
- Two "Could not recover jumptable" sites were recovered from ROM data:
  0x43e6 (32-case `shar` variable-shift dispatch, index bytes at 0x43a8) and
  0x44f6 (32-case `shlr` dispatch, index bytes at 0x44c0). Five other
  indirect-jump sites received mechanism annotations; unresolved bounds are
  stated explicitly.
- `decompiled/decompiler_issues.tsv` records the observed warning categories
  per function instead of the generic pointer text.

Evidence and rename map: `metadata/export_cleanup.json`; pre-change backup in
`backups/pre_cleanup.zip`.

## Knock control and loop-mode labeling — 2026-10-29

`scripts/review_knock_loop_labels.py`, `scripts/merge_reviewed_lookup_aliases.py`
and `scripts/review_knock_loop_labels_apply.py` (wired into `scripts/rebuild.sh`,
idempotent) label the knock-control and loop-mode chain end to end:

- 39 functions, 84 RAM locations and 15 lookup tables named from static
  evidence; 6 medium-confidence functions carry the `candidate_` prefix.
- Two inherited misnomers corrected: `ref_setClosedLoopBool` (0x1ee30) is
  `set_open_loop_flag` and `ref_enableDisableCruiseControl__` (0xc116) is
  `reset_knock_state_on_mode_change`.
- Polarity correction: 0xffffb12a/0xffffb12c are the **open**-loop flag
  (1 = open loop), established from the OBD PID 0x0003 handler and the
  0x1c13c/0x1ee4a logic.
- Export bug fixed: 0x13bd2 `knock_retard_clamp` now returns the
  `rx8_clamp_float` result (SH fr0) instead of discarding it as `void`.
- Knock retard signs settled: the retard is negative, clamped to [-10, 0] deg;
  attack (attack-condition flag set) is -1.0 deg/cycle, slow recovery +0.35 deg
  per 62 counts.
- Finding: knock control applies in open loop as well as closed loop — the
  knock chain never reads the loop-mode flags.

Full write-up: `reviews/knock_control/README.md`; rename map and fix evidence:
`metadata/knock_loop_labels.json`; design update: `design/README.md` section 5.7;
pre-change backup: `backups/pre_knock_loop_labels.zip`.


## Fueling chain labeling — 2026-10-30

`scripts/review_fueling_labels.py` (wired into `scripts/rebuild.sh`, idempotent)
labels the fueling chain end to end: 39 functions, 150 RAM locations, 1 lookup
table. Covers MAF→load→air charge→fuel volume→per-rotation amounts→pulse
arbitration→ATU-II injector outputs, OL/CL target selection, warmup/changeover/
tip-in enrichments, fuel cut / rev limit, and diag PIDs 0x0034/0x0043/0x0044/0x1410.
Resolves the knock-pass open item on blend weights b11c/b118 (producer 0x200c6).
Injector channel map verified against the ROM (table 0xd7d4, wrappers 0x59a4-0x59ea,
rotor blocks ROM 0x4e2c8) and `Sh7055h.pdf`: ch0/3/1/4/2/5 → ATU-II 8A/8B/8C/8D/8E/8F →
TO8A-F → SH7055F pkg pins 195/197/198/199/200/201. Full write-up:
`fueling_control_report.md` + `reviews/fueling/` (incl. `injector_pin_mapping.md`).
Backup: `backups/pre_fueling_labels.zip`; record: `metadata/fueling_labels.json`.

## Intake solenoid actuation — 2026-10-30

`scripts/review_intake_labels.py` labels SSV/VDI/VFAD/APV/secondary-air actuation
(26 functions, 26 RAM): GPIO bits verified in the disassembly, package pins from
the supplied SH7055F manual (`Sh7055h.pdf`, Tables 1.2/1.3): SSV PE7=pin 16 (1L),
VFAD PE10=19 (5Z), VDI PD5=254 (1W), sec-air solenoid PE8=17 (1O), pump PB2=147,
APV PWM PL5/PL8=221/224 (3J/3G), status PH12/13=79/80, position AN6=92 (3B).
Write-up: `intake_solenoids_report.md` + `reviews/intake_solenoids/`.
Backup: `backups/pre_intake_labels.zip`; record: `metadata/intake_labels.json`.

## Hardware pinout cross-checks — 2026-10-30

`hardware/pcm_connections.tsv` gained a `wire_colour` column and FSM terminal names
from the supplied `mazda-rx-8-pcm-pinout-series-1.pdf` (v3: colours resolved for all
used terminals except 5L/5Z; injectors share a W/L +12V feed, PCM pins are
ground-side). `hardware/firmware_annotations.tsv` and the `[WIRING REVIEW]` blocks in
all synchronized views carry the same facts. The package-pin ↔ connector-terminal
hop remains board routing (unresolved; the pinout has no chip-pin data).

## Binary-level verification + report validation — 2026-10-30

Every label was re-checked against the raw ROM and disassembly (literal pools,
constants, descriptors, GPIO regs/masks, dispatch records) — see the
"binary-level verification" sections in `reviews/*/README.md` and
`reviews/fueling/REVIEW_NOTES.md` §10. `scripts/validate_reports.py` (wired into
`rebuild.sh`) verifies every root `*_report.md`: required sections, ROM hash, every
function/RAM address in the memory maps against the index/TSVs/ROM. Record:
`metadata/report_validation.json`. AGENTS.md now mandates both steps.

## Patchers (new files, stock ROMs untouched) — 2026-10-30

`Mazda_RX8_PCM_ReverseEngineering/Utilities/`:
`patch_intake_rpm_window.py` (VDI/SSV RPM-window, RomRaider cal table) and
`patch_limiter_behavior.py` (rev-limiter stock/hard/soft modes, cal table "Rev
Limiter Behavior"), each writing NEW output .bin + JSON report + XML def, with
input SHA-256 asserted unchanged and decode-verified patches. Defs added to
`RX8Defs_Copy/RomRaider/rx8_defs.xml`. Static validation only — not hardware-tested;
flash with `Rx8Man/`. Docs: `Utilities/PATCHER_*.md`, `reviews/limiter/README.md`.

## Ignition timing labeling — 2026-10-31

Phase 2 ignition-timing pass: thread §9 final-BTDC equation verified/corrected against
the disassembly and confirmed bit-exact in the emulator; 15 functions, 22 RAM cells,
17 tables labeled (`ignition_timing_report.md`,
`data/labels/60E15120_N3J1E/ignition_timing_labels.json`, backup
`backups/pre_ignition_timing_labels.zip`).

## OS scheduler / CAN / IVT labeling — 2026-10-31

Emulator-driven labeling pass (Phase 1 fidelity work): 27 functions, 16 RAM locations,
9 tables named from dynamically verified behavior (IVT at VBR 0x7fc50, CAN RX interrupt
IVT 0x378, OS scheduler 0x3e10/0x3c2a/0x375c/0x3db0, UDS entry 0x680a0, ADC sweep 0x6884,
crank ISR 0x803e, NMI poll 0x8ea...). Write-up: `os_scheduler_can_ivt_report.md`;
labels: `data/labels/60E15120_N3J1E/os_scheduler_can_ivt_labels.json` + `source_review/accepted_*.tsv`;
backup: `backups/pre_os_scheduler_can_ivt_labels.zip`. ROM untouched.

## Start here

- [Firmware design document](design/README.md)
- Subsystem reports: [knock](knock_control_report.md), [fueling](fueling_control_report.md), [intake solenoids](intake_solenoids_report.md), [OS scheduler / interrupt / CAN-UDS transport](os_scheduler_can_ivt_report.md), [ignition timing](ignition_timing_report.md), [calibration extraction](calibration_extraction_report.md) — each with a full memory map and a plain-language §1a (standard per AGENTS.md rule 8); reviews in `reviews/` — architecture, boot flow, scheduler, task table and subsystem call map
- [Named C view with lookup descriptor and RAM aliases](named/firmware_named.c) — [naming evidence](named/README.md)
- [Combined C listing](decompiled/firmware_decompiled.c)
- [Function index: addresses, names, status, individual files](decompiled/function_index.tsv)
- [Readable, compilable math helpers](reconstructed/rx8_math.c)
- [Addressed disassembly with instruction bytes](decompiled/firmware_disassembly.asm)
- [Functions requiring decompiler review](decompiled/decompiler_issues.tsv)
- [Call graph](decompiled/callgraph.tsv) and [symbols](decompiled/symbols.tsv)
- [Ghidra project](ghidra_project/RX8_SH2E.gpr), requiring the [local processor configuration](processor/README.md)

## Input and architecture

| Item | Evidence |
|---|---|
| File | `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin` |
| Size | 524,288 bytes |
| SHA-256 | `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1` |
| Firmware identifier at 0x2000 | `60E15120` |
| Bytes at calibration-ID address 0x6c046 | `N3ZHE` |
| Initial PC / stack pointer | `0x8b8` / `0xffffdfa0` |
| CPU evidence | Local RX8Defs selects SH7055; big-endian reset vectors and SH/FPU instructions agree |
| Analysis map | ROM 0x00000000–0x0007ffff; RAM 0xffff6000–0xffffdfff; volatile I/O 0xffffe000–0xffffffff |

The filename and XML secondary identifier say N3J1E, but the binary contains N3ZHE
at the XML-specified address. No bytes were changed to resolve this discrepancy.
The firmware ID 60E15120 itself matches. Exact silicon revision and calibration
provenance were not established from this dump alone.

Renesas documents this processor family as SH-2E with 512 KiB flash and 32 KiB
RAM: [hardware manual](https://www.renesas.com/en/document/mah/sh-2e-sh7055s-hardware-manual).
The final analysis uses Ghidra 12.1.3 with the supplied SH-2+FPU configuration.
The earlier RX8_N3J1E project in the local folder used SH-2A and is superseded;
use **RX8_SH2E**. The downloadable bundle excludes the superseded project.

## Recovery and naming

1. Exported function-body bytes from the existing related `60E0FC00.bin` Ghidra project.
2. Located 1,833 unique exact byte matches in this target ROM, using them as entry seeds.
   These are matches to the reference's defined bodies, which can omit delay-slot
   instructions or have imperfect boundaries; they are not proof of complete semantic identity.
3. Followed reset/interrupt vectors and analyzed reachable code.
4. Recovered additional candidates from ROM pointers with register-save prologues,
   then a 99-record, 12-byte dispatch table at 0x5f10c–0x5f5af. Its diagnostic role
   is inferred. Candidate addresses and evidence are recorded in `metadata/`.
5. Applied 1,250 calibration labels from the local 60E15120 XML definition and
   peripheral labels from the reference project's SH7055 register map.
6. Corrected the five floating-point helper prototypes after inspecting register
   usage, then regenerated all C using the narrower processor decoder.

`ref_` names are inherited interpretations from the related project, including
its tentative names and spelling mistakes. `FUN_` names identify unnamed routines
by address. `CAL_` labels identify XML annotations, not independently verified
calibration meanings. The five `rx8_` math helper names reflect manual inspection.
No arbitrary transfer of related-ROM RAM variable names or function signatures
was performed. Assembly, source addresses and match metadata remain available for review.

## Results and validation

| Measure | Result |
|---|---:|
| Identified functions | 3,355 |
| Functions producing C | 3,355 |
| Decompiler failures | 0 |
| Functions with warning comments/messages | 154 |
| Decoded instructions byte-checked against input | 168,592 |
| Bytes classified as instructions | 337,184 / 524,288 |

Instruction-byte coverage is **not** a percentage of code recovered: the ROM
also contains vectors, constants, lookup tables, strings and padding, and some
unidentified code may remain. `non_instruction_ranges.tsv` lists everything not
currently decoded as instructions; it does not classify those ranges as unused.

Validation checked the original hash, every exported instruction's bytes and
2-byte alignment/width, every exact reference match, all function-file/index
links and summary counts. It does not prove that every decoded instruction is
code, that all function boundaries are correct, or that the C is semantically
equivalent to execution on the ECU.

The five routines in `reconstructed/rx8_math.c` compile cleanly with C11 and strict
warnings. Their tests cover filter endpoints, non-finite previous state, threshold
boundaries, clamps, NaNs and signed zero. Run from this directory:

```sh
cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off \
  reconstructed/rx8_math.c reconstructed/test_rx8_math.c -lm -o /tmp/rx8_math_test
/tmp/rx8_math_test
python3 scripts/validate_export.py
```

## Limits of the C output

Ghidra's C dialect contains `undefined*` types, `DAT_` globals, register-derived
parameters, unresolved indirect calls and macros such as `CONCAT`, `SUB` and
`ABS`. It is intended to be read alongside the disassembly. In particular,
some apparent casts express register bit reinterpretation rather than valid
high-level numeric conversion. The first-order filter's raw `(uint)arg1` exponent
check is one example; the manually reconstructed version uses `memcpy` instead.

Unknown calling conventions, hardware register side effects, interrupt state,
RAM-resident routines, indirect dispatch and non-returning code still need
individual review. A warning-free decompilation is not a correctness certificate.
No hardware/emulator execution, complete semantic equivalence test, original
compiler reconstruction, linker layout reconstruction or ROM rebuild was performed.
The host math tests do not validate SH floating-point rounding/exception modes.

## Reproduction and provenance

All analysis scripts are in `scripts/`. `rebuild.sh NEW_PROJECT_NAME` uses Ghidra
12.1.3 (`GHIDRA_HOME`) and a JDK 21+ on PATH. It expects the original workspace
layout, source ROM, XML definitions and restored reference project to remain
available. It writes a new project and regenerates the export/metadata, leaving
the source ROM unchanged. It installs the included processor configuration into
the chosen Ghidra installation, so that directory must be writable.

The reference project came from the existing local RX-8 reverse-engineering
materials; its program is a different ROM. Register/vector definitions are read
from its `script_stuff` directory. Calibration annotations come from
`RX8Defs/RomRaider/rx8_defs.xml`. These upstream materials retain their own terms.
Ghidra binaries and the original ROM are not bundled in the export archive.
