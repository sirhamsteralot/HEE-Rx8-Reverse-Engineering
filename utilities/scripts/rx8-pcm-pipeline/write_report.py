#!/usr/bin/env python3
from pathlib import Path
import json,csv
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
s=json.loads((base/'decompiled/analysis_summary.json').read_text())
v=json.loads((base/'metadata/validation.json').read_text())
i=json.loads((base/'metadata/input.json').read_text())
text=f'''# 60E15120_N3J1E.bin — reconstructed C

The export contains **{s['functions']:,} identified functions** decompiled from the target ROM.
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

## Start here

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
| Size | {i['size']:,} bytes |
| SHA-256 | `{i['sha256']}` |
| Firmware identifier at 0x2000 | `{i['firmware_id']}` |
| Bytes at calibration-ID address 0x6c046 | `{i['calibration_id']}` |
| Initial PC / stack pointer | `{i['initial_pc']}` / `{i['initial_sp']}` |
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
| Identified functions | {s['functions']:,} |
| Functions producing C | {s['decompiled']:,} |
| Decompiler failures | {s['failed']:,} |
| Functions with warning comments/messages | {s['with_warnings']:,} |
| Decoded instructions byte-checked against input | {v['instructions_byte_verified']:,} |
| Bytes classified as instructions | {s['instruction_bytes']:,} / 524,288 |

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
cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off \\
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
'''
(base/'README.md').write_text(text)
