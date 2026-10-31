# HEE — Mazda RX-8 Reverse Engineering

This repository is the central workspace for the reverse-engineering effort on the
Mazda RX-8 target referred to as **HEE** (ECU / control-module firmware and related
artifacts). It holds the original binaries, the reverse-engineered code, supporting
documentation and investigations, and the utilities used along the way.

## Goals

- Understand the structure, behavior, and algorithms of the HEE firmware.
- Produce annotated disassembly and readable decompiled/reimplemented code.
- Document findings so the work is reproducible and reviewable by others.
- Build utilities that let us analyze, verify, and (eventually) re-flash safely.

## Non-goals / ground rules

- Work only on hardware and dumps you own or are authorized to analyze.
- Reverse engineering for interoperability and repair on personally owned devices is
  generally lawful in many jurisdictions, but laws vary — check yours before
  distributing circumvention code.
- **Never flash modified firmware to a vehicle** unless it has been validated on a
  bench setup first. A bad flash can brick an ECU or damage an engine.

## Repository layout

| Path | Purpose |
|---|---|
| `input/` | Raw intake drop zone: incoming bins, prior efforts, cloned third-party repos, sources. **Never committed** — verified artifacts are promoted out of it. |
| `binaries/` | Original dumps/firmware images, with a SHA-256 provenance manifest. |
| `reverse-engineered/` | All RE output: annotated disassembly, decompiler output, and clean reimplementations. |
| `reverse-engineered/disassembly/` | Disassembler exports and annotated assembly (Ghidra/IDA/Binja projects live here or are referenced). |
| `reverse-engineered/decompiled/` | Decompiler output, kept close to the original but cleaned up. |
| `reverse-engineered/reimplementation/` | Clean-room rewritten source that can be built and tested independently. |
| `docs/` | Documentation: dated investigations, architecture maps, external references. |
| `docs/investigations/` | One writeup per subsystem/question, using `TEMPLATE.md`. |
| `docs/architecture/` | Memory maps, pinouts, CAN/UDS message catalogs, timing diagrams. |
| `docs/references/` | External datasheets, PDFs, links, and notes on where they came from. |
| `data/` | Machine-readable extracted artifacts: fuel/ignition maps, DTC tables, string tables, checksum parameters. |
| `utilities/` | Scripts and tool configs used to acquire, hash, parse, and verify. |
| `tests/` | Harnesses that compare reimplemented behavior against observed original behavior. |

## Recommended workflow

Everything raw lands in `input/` first (uncommitted intake). Only verified artifacts
are promoted into the tracked folders below.

1. **Acquire** — dump the binary from your own unit (bench ECU preferred over in-car).
2. **Preserve** — drop it in `binaries/`, record provenance, and regenerate
   `binaries/manifest.csv` with `utilities/scripts/hash_binaries.py`.
3. **Document** — open an investigation in `docs/investigations/` before deep diving.
4. **Disassemble** — load into your disassembler of choice; export annotated work to
   `reverse-engineered/disassembly/`.
5. **Annotate** — name functions/variables, apply structures; always reference the
   original address (e.g. `sub_08001234`) in comments and docs.
6. **Reimplement** — write clean code in `reverse-engineered/reimplementation/`.
7. **Verify** — add or extend tests in `tests/` proving the reimplementation matches
   observed behavior.
8. **Summarize** — close out the investigation doc with findings and open questions.

## Tooling suggestions

- Disassembler: Ghidra (free), IDA Pro, or Binary Ninja.
- Hex inspection: ImHex or HxD.
- Mazda-specific: research Forscan / MazdaEdit communities for UDS routines and
  memory layouts; record any useful knowledge in `docs/references/`.
- Scripts: Python 3 for parsing utilities in `utilities/scripts/`.

## Conventions

- Dates in filenames and docs use ISO format (`YYYY-MM-DD`).
- Filenames are `kebab-case`; addresses are written as `0x08001234`.
- Large binaries (>5 MB) should go through Git LFS — see `.gitattributes` — or stay
  out of the repo with only their SHA-256 in `binaries/manifest.csv`.
- Every investigation doc must state: goal, method, findings, evidence, open questions.
- Commit messages: short imperative subject, body explaining *why* when non-obvious.

## Status

Project initialized 2026-10-31. No binaries or findings yet — see
`docs/investigations/` for the first writeups as they land.
