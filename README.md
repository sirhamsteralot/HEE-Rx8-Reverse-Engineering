# HEE — Mazda RX-8 Reverse Engineering

Central workspace for reverse engineering the Mazda RX-8 (Series 1) PCM/ECU —
a Renesas **SH-2E (SH7055F)**, big-endian, 512 KiB flash / 32 KiB RAM — referred to
here as the **HEE** target. No firmware source exists; everything is derived from
ROM binaries. Seeded on 2026-10-31 from a prior effort workspace
(`input/Tuning-merged`, promoted into the tracked folders below).

## Goals

- Understand the structure, behavior, and algorithms of the HEE PCM firmware.
- Maintain annotated disassembly, decompiled views, and clean reimplementations.
- Maintain RomRaider/ECUFlash XML definitions that match the ROMs.
- Document findings so the work is reproducible, evidence-ranked, and reviewable.

## Non-goals / ground rules

- Work only on hardware and dumps you own or are authorized to analyze; check your
  local laws before distributing circumvention code.
- **Never modify a stock ROM, capture, or dump** — binaries are immutable inputs.
  Patches are written to *new* output files only.
- **Never flash modified firmware to a vehicle** without bench validation first.

## Repository layout

| Path | Purpose |
|---|---|
| `input/` | Raw intake drop zone (bins, prior efforts, cloned repos). **Never committed.** |
| `submodules/` | Upstream repos as git submodules (`RX8Defs`, `Rx8Man`, `Mazda_RX8_PCM_ReverseEngineering`) — **read-only context only**, never worked in or committed from. Fetch with `git submodule update --init --recursive`. |
| `binaries/` | Immutable dumps: `stock-roms/`, `captures/`; `manifest.csv` = SHA-256 + provenance for every file. |
| `reverse-engineered/` | RE output. `disassembly/` (addressed asm per ROM, `archives/` = Ghidra `.gar` via LFS), `decompiled/<rom-id>/` (C export + named views + indexes), `reimplementation/` (compilable C + host tests). |
| `docs/` | `investigations/<rom-id>/` (subsystem reports, reviews, evidence, backups), `architecture/` (memory map, `hardware/` pinouts & wiring, `design/`), `references/` (PDFs, upstream links, prior-effort docs), `learnings.md` (session log). |
| `data/` | Machine-readable artifacts: `definitions/` (RomRaider/ECUFlash XML), `labels/<rom-id>/` (label/alias TSV+JSON, validation records). |
| `utilities/` | `scripts/` (`hash_binaries.py`, `rx8-pcm-pipeline/`, `patchers/`, `defs-merge/`), `tools/ghidra/` (Java headless scripts, SH-2E processor config). |
| `tests/` | Verification harnesses; host unit tests live beside the code in `reverse-engineered/reimplementation/`. |

Live Ghidra project databases (`.gpr/.rep`) and third-party tool installs (RomRaider,
Rx8Man, upstream RX8Defs clones) stay in `input/` — only `.gar` archives, exports, and
scripts are committed. See `docs/references/README.md`.

## Recommended workflow

Everything raw lands in `input/` first (uncommitted intake). Only verified artifacts
are promoted into the tracked folders.

1. **Acquire** — dump from your own unit (bench ECU preferred); place in `input/`,
   then promote to `binaries/` with a manifest row (`utilities/scripts/hash_binaries.py`).
2. **Document** — open/extend `docs/investigations/<rom-id>/` before deep diving.
3. **Disassemble/decompile** — Ghidra with the local SH-2E processor config
   (`utilities/tools/ghidra/processor/`); commit exports and `.gar` archives under
   `reverse-engineered/`, not project databases.
4. **Annotate with evidence discipline** — name things per the label ladder
   (`FUN_xxxxxxxx` unnamed, `ref_` inherited hypothesis, `CAL_` XML-derived,
   `tbl_` descriptor pointer, `inferred_` RAM derivation, `candidate_` unproven);
   never upgrade a label without new evidence; always tie symbols to addresses.
5. **Verify at the binary level** — re-check every label against the raw ROM /
   disassembly (literal pools, constants, descriptors, GPIO reg+mask), run the
   pipeline's `validate_export.py` / `validate_reports.py` from
   `utilities/scripts/rx8-pcm-pipeline/` (they expect the legacy workspace layout in
   `input/Tuning-merged`).
6. **Report** — subsystem writeups follow the 10-section format with mandatory
   function/RAM address tables (template: `docs/investigations/60E15120_N3J1E/knock_control_report.md`).
7. **Reimplement & test** — compilable C goes in `reverse-engineered/reimplementation/`
   with host tests (`cc -std=c11 -Wall -Wextra -Werror -ffp-contract=off …`).

## Conventions

- Dates ISO (`YYYY-MM-DD`); filenames `kebab-case` except **binary dumps keep their
  upstream names** (`<firmware-id>_<cal-id>.bin`, e.g. `60E15120_N3J1E.bin`) so they
  match the XML definitions; new acquisitions use `<source>-<version>-<date>.<ext>`.
- Addresses written `0x08001234`; ROM window `0x00000000–0x0007ffff`, RAM
  `0xffff6000–0xffffdfff`, volatile I/O `0xffffe000–0xffffffff`.
- Binary blobs (`.bin/.gar/.zip/.jar/.exe/.dll/.so/.pdf`…) go through Git LFS —
  see `.gitattributes`; `git-lfs` is required to clone/checkout them.
- Commit messages: short imperative subject, body explaining *why*.

## Status

Seeded 2026-10-31: 10 stock ROMs + 3 captures in `binaries/`, full prior analysis of
ROM `60E15120_N3J1E` (3,355 functions) under `reverse-engineered/` and
`docs/investigations/60E15120_N3J1E/`, XML definitions in `data/definitions/`,
pipeline + patcher scripts in `utilities/`. See `docs/learnings.md` for session
know-how (SH-2E encoding gotchas, pipeline pitfalls, patcher patterns).
