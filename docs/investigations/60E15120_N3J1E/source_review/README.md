# Additional source review — 2026-09-09

**Integration update:** These names and review comments are now included in
`decompiled/firmware_decompiled.c` and individual function files. Earlier statements
below about a separate named view or unchanged raw C describe the pre-integration
state. The saved Ghidra database remains unchanged. See `metadata/integrated_names.json`.

This pass adds **11 reviewed function annotations and 11 RAM aliases** to the exported C. Some clarify existing inherited names rather than identify previously unknown routines. Names describe observed behavior; they are not recovered factory symbols. The ROM and saved Ghidra database are unchanged.

## Supported additions

| Address | Interpretation | Evidence |
|---|---|---|
| 0x57a0c | Append a big-endian 16-bit diagnostic value | G-ROM mapping plus explicit two-byte serialization |
| 0x57a2e | Append an 8-bit diagnostic value | G-ROM mapping plus one-byte append |
| 0x57858 | Build service-0x22 positive-response header | Emits 0x62 and the requested identifier |
| 0x5774c | Search and dispatch a diagnostic identifier | Searches 99 twelve-byte records and checks a mask before calling a handler |
| 0x567e8 | Accept a two-byte diagnostic identifier | Request dataflow; some raw phase/ABI details remain uncertain |
| 0x29340 | Prepare RPM for CAN, with conditional filtering | Reads known engine RPM; stores prepared and previous values |
| 0x29236 | Encode CAN RPM | Quarter-RPM quantization; invalid sentinel 0xffff |
| 0x2927c | Encode CAN vehicle speed | Known speed input, offset/scaling, and payload packing |
| 0x291dc | Pack and queue CAN 0x201 | ROM descriptor confirms ID, length and buffer |
| 0x28eb8 | Unpack CAN 0x216 mixed-width fields | Exact reference match and relocated pointer operands |
| 0x71ea | Wait for SCI receive-data-full | Renesas register description corroborates bit 0x40 |

[Function aliases](accepted_function_aliases.tsv) and [RAM aliases](accepted_ram_aliases.tsv) carry per-entry evidence. RAM additions include diagnostic identifier 0xffffd1ea; prepared RPM 0xffffbb04; previous RPM 0xffffbb08; encoded RPM 0xffffbafc; encoded speed 0xffffbb00; and CAN payload 0xffffbaf4.

The CAN descriptor at 0x4df1c contains big-endian ID 0x201, length 8 and pointer 0xffffbaf4. Its remaining metadata bytes are not assigned universal meanings. RPM occupies payload bytes 0–1; speed occupies bytes 4–5. The speed encoder uses `(speed + 100) / 0.01`, rounded and capped at 40000; faults use 0xffff. RPM uses 0.25 RPM/count and caps normal values at 0xfffe. These are conclusions from this ROM, not copied DBC conversions.

## Sources examined and their limits

**G-ROM:** [RX8_FlexFuel](https://github.com/equinox311/RX8_FlexFuel), especially `RomAddresses.s`, `vars.h` and `pid_handler.h`, supplies OEM hooks, declarations and a diagnostic-record structure for reference ROM 60E0FC00. Three previously unnamed helpers were matched with only PC-relative literal displacement differences, then checked against target behavior. Its seven logger identifiers previously absent from our stock dispatch are explicitly present in the patch's extended PID list. Its `can216rx_byteN` names are misleading for original unpacked values: our routine stores three words and two bytes, not eight consecutive raw bytes. No general RAM offset was applied. Other engine-variable mappings remain unresolved. This is the same author's work as our reference archive, not an independent second implementation.

**Renesas:** [SH7055 On-Chip I/O application note](https://www.renesas.com/en/document/apn/sh7055-chip-io-volume-application-note), section 2.20, printed pages 111–115, confirms synchronous SCI setup and RDRF mask 0x40. Its sample itself waits without a timeout. This strengthens the peripheral interpretation but weakens any claim that the mere existence of such a loop establishes a defect. Transfer frequency cannot be inferred from its example without verifying our clock configuration.

**Factory diagnosis:** [Mazda Engine Diagnostics & Control](https://mazdarotaryclub.com/rx-8_onlinemanual/4EngineControl.pdf), PDF page 77, describes P0118 as high coolant-sensor input above 4.8 V while running, with PCM terminal associations. This gives a threshold and operating-condition pattern to search for; no unique routine was established from it in this pass. A threshold alone is too weak to rename a function. This manual complements the supplied wiring PDF; exact variant applicability remains provisional.

**CAN research:** [rnd-ash RX-8 notes](https://github.com/rnd-ash/rx8-reverse-engineering) were inspected at the recorded commit. The example DBC explicitly leaves RPM conversion unresolved, and its message-number notation must not be silently treated as verified hexadecimal identifiers. No scaling was imported from it. The [rusEFI RX-8 page](https://github.com/rusefi/rusefi/wiki/Mazda-RX8-2004) provided a lead toward RPM/speed traffic; ROM encoding and descriptor bytes are the actual evidence for the additions above.

**Related ROMs:** The existing local 60E0FC00 function export was compared again with target function boundaries while ignoring only the displacement byte of PC-relative word/long loads. This yielded **105 additional structural candidates**. They have not been bulk-renamed: short shared code shapes, unresolved literals and semantic differences can produce misleading matches. The three diagnostic matches were manually reviewed. Other stock versions present locally were inventoried but not exhaustively cross-decompiled in this pass; no new online Ghidra archive was imported.

## Reproducibility and validation

- [Source provenance](validation.json) records repository commits and file hashes.
- `scripts/correlate_flex_source.py PATH_TO_RX8_FlexFuel` reproduces candidate correlations using the local reference and target ROMs. A unique target shape is candidate evidence only; the algorithm does not establish bidirectional uniqueness or equivalent literal values.
- [Structural candidates](normalized_function_candidates.json), [function correlations](flex_function_expanded_candidates.json) and [RAM candidates](flex_ram_expanded_candidates.json) retain unsuccessful and unreviewed results. They are separate from accepted aliases.
- `scripts/annotate_source_review.py` reapplies accepted comments to individual and combined C exports after regeneration. Existing function identities are retained. Ghidra import has not been performed.

The original export validator still checks all 3,355 function files and 168,592 instruction encodings against the ROM. These checks establish artifact consistency, not equivalence to original C or proof of the reported reset cause.

## 2026-10-31 pass — UDS/Mode-22 dispatch labeling

Appended 175 function aliases and 63 RAM aliases (see `accepted_function_aliases.tsv` /
`accepted_ram_aliases.tsv`; machine-readable record in
`data/labels/60E15120_N3J1E/uds_dispatch_labels.json`). Binary-level checks: all 99 Mode 22
records (0x5f10c), 36 sub-PID records (0x5f5b2) and 29 service records (0x5eb40) re-read
from the ROM and asserted byte-exact; every handler asserted to be a code entry. Applied
with `integrate_reviewed_names.py` (3,355 function bodies re-verified). Dynamic check:
`tests/test_phase1_dynamic.py::test_mode22_dispatch_table_payloads` (ROM's own 0x5774c
dispatch, exact 0x62-header response bytes + NRC 0x31 mask rejection). Report:
`docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md`. Validators
`validate_export` / `validate_reports` / `verify_readability` / `verify_math_units` PASS;
`pytest tests/` 59/59.

## 2026-10-31 verification pass — UDS/Mode-22 labels re-checked with extreme caution

Re-verified all labels from the dispatch pass against the RAW DISASSEMBLY and the emulator
(checker: `input/work/verify_labels.py`, report: `input/work/verify_report.txt`):
99/99 PID + 29/29 service + 36/36 sub records byte-exact vs ROM; every handler's call
targets resolved through the literal pool (0 unknown); 63/63 RAM aliases confirmed as
(sign-extended mov.w) literals in the claimed reader after fixing one reader column
(0xffffad5c: 0x555f8 -> 0x5553e); encode float constants confirmed in the literal pools;
full dynamic sweep of all 99 PIDs through ROM 0x5774c (r0 == rlen+3, ring length, NRC 0x31
mask rejection on all 14 restricted records) and dynamic service routing through 0x68dac
(session-bit mask `record[8] & (1 << DAT_ffffde20[0])` confirmed; unknown service -> r0=1).
Durable tests added: `test_mode22_dispatch_full_sweep`, `test_uds_service_router_routes`.
Result: no function label changed; `pytest tests/` 61/61; validators PASS.
