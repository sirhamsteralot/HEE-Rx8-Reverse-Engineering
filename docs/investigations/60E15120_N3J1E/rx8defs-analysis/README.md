# 60E15120 definition extension — 2026-09-18

Updated `RomRaider/rx8_defs.xml` in place for target 60E15120:

- 478 existing calibration tables now document their verified descriptor address, storage type, dimensions and known referencing functions.
- 103 previously generic axis labels now have names inferred from explicit lookup inputs. They carry `(inferred)`; this does not establish raw/filtered/requested distinctions.
- Existing top-level table names are retained because they are inheritance keys. Addresses, scaling, dimensions, switch data and all other ROM blocks are unchanged.

The target block retains its existing secondary N3J1E identification even though the examined binary contains N3ZHE at the secondary location. This review does not resolve that identification mismatch. The common base definitions are not generalized from one ROM.

## Reviewed logger

Use `RomRaider/logger_60E15120_reviewed.xml` as an alternative logger definition for this stock ROM. It is not an automatically ROM-selected profile and has not been validated on a connected ECU. Select the appropriate definition explicitly; do not merge it blindly with the original MAZDA protocol definition.

It contains 14 parameters: 12 existing single-value entries matched to the recovered diagnostic dispatch, a control-module-voltage candidate (0x0042, 16-bit, approximately 0.001 V/count), and identifier 0x1410 as a raw 16-bit value. The latter is deliberately not named injector pulse time or throttle percentage because those existing interpretations conflict. Composite four-byte AFR output and unmatched/custom flex-fuel entries are excluded from this stock-focused companion. The original `logger_rx8_defs.xml` is unchanged.

IDs are unique in the companion, response widths follow dispatch records, copied description mistakes were removed and inverted display ranges corrected. Semantic names carried from community definitions remain interpretations pending live validation.

## Non-calibration labels

Editor tables cannot represent arbitrary functions or RAM symbols. Those findings are supplied alongside the XML:

- `function_labels.tsv`: current canonical function names and addresses.
- `table_and_ram_labels.tsv`: lookup descriptor and RAM aliases with inference evidence.
- `lookup_function_evidence.json`: register ABI and interpolation-family analysis.
- `rx8_analysis_types.h`: recovered structures and symbolic constants, for analysis tools rather than import as RomRaider tables.
- `recovered_symbols.json`: additional review-source records; historical proposals are retained with provenance and may be superseded by the current function index.

`table_changes.json` gives per-table edits. `validation.json` records XML parsing and unchanged calibration structure checks. RomRaider's local TableScaleUnmarshaller was inspected: descriptions are supported and nested axes are selected by axis type before applying overrides. An actual RomRaider GUI load/live logging test has not been performed.

`definitions_before_review.zip` preserves both original XML files. The generation script is `reverse_engineered/60E15120_N3J1E/scripts/extend_definitions.py` in the original workspace. It refuses repeated application to an already-extended XML; restore a backup before regenerating. (A copy of that script formerly lived in this repo at `utilities/scripts/rx8-pcm-pipeline/extend_definitions.py`; it was removed on 2026-11-03 as dead — its legacy `RX8Defs/` write path does not resolve in this repo's promoted layout, and the defs flow is now owned by [`utilities/scripts/defs-merge/`](../../../../utilities/scripts/defs-merge/). The outputs it produced are preserved here and in `data/definitions/`.)
