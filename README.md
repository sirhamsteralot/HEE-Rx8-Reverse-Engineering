# HEE — Mazda RX-8 Reverse Engineering

Workspace for reverse engineering the Mazda RX-8 (Series 1) PCM/ECU — a Renesas
**SH-2E (SH7055F)**, big-endian, 512 KiB flash / 32 KiB RAM. No firmware source
exists; everything is derived from ROM binaries. Includes a working SH-2E
emulator.

**Plan & rules:** open work and the discrepancy register live in
**[ROADMAP.md](ROADMAP.md)**; working rules for agents and humans live in
**[AGENTS.md](AGENTS.md)**.

## Current state

ROADMAP groups A–D are done: a corpus-validated SH-2E emulator (boots the real
ROM, virtual OBD-II/UDS port, browser UI with datalog replay, Renesas
cross-check), a fully labeled static analysis of `60E15120_N3J1E` (subsystem
reports in [`docs/investigations/60E15120_N3J1E/`](docs/investigations/60E15120_N3J1E/README.md)),
cross-ROM label propagation, calibration extraction for all 14 dumped ROMs
([`data/maps/`](data/maps/README.md)), and RomRaider/ECUFlash definitions for
them ([`data/definitions/`](data/definitions/README.md)). Next: group E
(reimplementation coverage). Know-how: [`docs/learnings.md`](docs/learnings.md).

## Credits & acknowledgements

This workspace stands on community work — without the people below it would not
exist:

- **Rx8Man (rx8man)** — github.com/Rx8Man/Rx8Man (pinned in `submodules/Rx8Man`):
  the CAN/J2534 PCM read/flash tooling that made dumping and bench work possible.
- **equinox311 / equinox92 (equinox)** — github.com/equinox311/
  `Mazda_RX8_PCM_ReverseEngineering` (the 10 stock ROMs, RAM/EEPROM/IC captures,
  Ghidra archives, upstream patcher scripts — pinned in `submodules/`) and
  github.com/equinox311/RX8Defs (the upstream RomRaider/ECUFlash XML definitions —
  pinned in `submodules/RX8Defs`); also the driving force behind the RX8Club guide.
- **The RX8Club forum thread contributors ("equinox92 et al.")** — the "Open Source
  S1 RX-8 ECU Reverse Engineering, Data Logging, and Tuning — User's Guide" thread
  (extract in [`docs/references/rx8club-user-guide-thread.md`](docs/references/rx8club-user-guide-thread.md)): ROM↔cal-ID table,
  BOOT-mode CN400 pinout, UDS services, and the first public hypotheses for the
  engine-load math and the ignition-timing BTDC equation that this repo verified.
- **The RomRaider community** — the ECU editor/logger ecosystem the XML definitions
  plug into (romraider.com, github.com/RomRaider/RomRaider).
- **The Mazda RX-8 Discord community** — day-to-day Q&A, datalogs, and bench-test
  reports that keep this project grounded in real cars.
- **Renesas** — the SH7055S/SH-2E hardware and ISA manuals the emulator is built
  against.

## Quick start

```sh
git clone <this repo> && cd HEE-Rx8-Reverse-Engineering
git lfs install && git submodule update --init --recursive   # git-lfs required (ROMs/PDFs are LFS)
python -m pytest tests/                                       # full suite, ~30s
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 1000000
python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E   # UI on http://127.0.0.1:8080/
python utilities/scripts/hash_binaries.py --check             # verify binaries/manifest.csv
```

Emulator profiles are per-ROM/market/model in
`utilities/scripts/emu/profiles/` (ROM path + SHA-256 verified at load, memory
map, peripheral set, sensor map); to run a different `.bin`, add a profile —
recipe in [`utilities/scripts/emu/profiles/README.md`](utilities/scripts/emu/profiles/README.md).
To validate firmware against the real-car datalogs in the simulator (replay a
`data/logs/*.csv`, compare emulated outputs / UDS responses against the log),
see **[`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md)**.
Cross-check traces against the Renesas Simulator Debugger (SH7055) with
`utilities/scripts/emu/compare_traces.py`.

**Agent tooling:** in-session agents call
`python utilities/scripts/hee.py <tool> '<json>'` directly (details in AGENTS.md);
external agents use the MCP plugin in `.vibe/plugins/hee-re/`.

## Goals

- Understand the structure, behavior, and algorithms of the HEE PCM firmware.
- Run the actual binaries in the SH-2E emulator and validate every static finding
  dynamically (golden traces, virtual OBD-II/UDS port, live sensor UI).
- Maintain annotated disassembly, decompiled views, and clean reimplementations.
- Maintain RomRaider/ECUFlash XML definitions that match the ROMs.
- Document findings so the work is reproducible, evidence-ranked, and reviewable.

## Ground rules

- Work only on hardware and dumps you own or are authorized to analyze; check your
  local laws before distributing circumvention code.
- **Binaries are immutable inputs** — patches write *new* output files only, with
  the input SHA-256 asserted unchanged.
- **Never flash modified firmware to a vehicle** without bench validation first:
  validate in the emulator, then upload to a **bench ECU over the OBD port**
  (UDS 0x34/0x36/0x37). CN400 BOOT mode is recovery-only — it erases flash before
  any read and needs a ~150 Hz square wave on pin 3 — see
  [`docs/references/rx8club-user-guide-thread.md`](docs/references/rx8club-user-guide-thread.md) §8.

Full rules: [AGENTS.md](AGENTS.md).

## Repository layout

| Path | Purpose |
|---|---|
| `input/` | Raw intake drop zone (ROM dumps, zips, saved pages, cloned repos). **Never committed** — verified artifacts are promoted out with provenance. |
| `submodules/` | Read-only upstream repos: `RX8Defs` (XML defs), `Rx8Man` (flash tooling), `Mazda_RX8_PCM_ReverseEngineering` (10 stock ROMs, captures, Ghidra `.gar`). |
| `binaries/` | Immutable dumps of **our own acquisitions** + `manifest.csv` (recursive SHA-256 + provenance). |
| `reverse-engineered/` | `disassembly/` + `decompiled/` exports per ROM, `reimplementation/` (compilable C11 + host tests). |
| `docs/` | `investigations/` (subsystem reports + evidence), `architecture/` (memory map, design, hardware pinout, emulator guides), `references/`, `learnings.md`. |
| `data/` | `definitions/` (RomRaider/ECUFlash XML), `labels/`, `maps/` (extracted tables + scalars), `dtc/`, `logs/` (real-car datalogs), `tunes/`. |
| `utilities/` | `scripts/emu/` (emulator), `scripts/rx8-pcm-pipeline/` (Ghidra pipeline + validators), `scripts/patchers/`, `scripts/defs-merge/`, extraction scripts, `tools/ghidra/`. |
| `tests/` | pytest harnesses (emulator, corpus, golden traces, ISO-TP/CAN/OBD/UI). |

Details: repo map in [AGENTS.md](AGENTS.md) and the per-folder READMEs.

## Workflow & conventions

Work is delivered **branch + pull request** — never direct commits to `main`.
Every unit gets binary-level verification plus the pipeline validators before
review. Branch naming, commit style, the full task workflow, and the exact
verification commands are in [AGENTS.md](AGENTS.md).

Conventions: ISO dates, kebab-case filenames, `0x` addresses; memory map — ROM
`0x00000000–0x0007ffff`, RAM `0xffff6000–0xffffdfff`, volatile I/O
`0xffffe000–0xffffffff`; binary blobs go through Git LFS. Discrepancies are
documented, never silently resolved (ROADMAP register).
