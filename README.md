# HEE — Mazda RX-8 Reverse Engineering

Workspace for reverse engineering the Mazda RX-8 (Series 1) PCM/ECU — a Renesas
**SH-2E (SH7055F)**, big-endian, 512 KiB flash / 32 KiB RAM. No firmware source
exists; everything is derived from ROM binaries. Includes a working SH-2E
emulator.

**Plan:** see **[ROADMAP.md](ROADMAP.md)** — groups A–D (emulator,
calibration extraction, static labeling, cross-ROM propagation) are done; open
work starts at group E (reimplementation coverage), then F (toward hardware,
gated). There is a discrepancy register at the bottom of the
ROADMAP. **Rules for agents/humans:** **[AGENTS.md](AGENTS.md)**.

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
- And, as a source of occasional inspiration, the author's own sanity (status:
  questionable, but still running).

## Quick start

```sh
git clone <this repo> && cd HEE-Rx8-Reverse-Engineering
git lfs install && git submodule update --init --recursive   # git-lfs required (ROMs/PDFs are LFS)
python -m pytest tests/                                       # 61 tests, ~25s
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 1000000
python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E   # UI on http://127.0.0.1:8080/
python utilities/scripts/hash_binaries.py --check             # verify binaries/manifest.csv
```

To validate firmware against the real-car datalogs in the simulator (replay a
`data/logs/*.csv` as inputs, compare emulated outputs / UDS responses against the
log), see **[`docs/architecture/emulator-re-guide.md`](docs/architecture/emulator-re-guide.md)**.

Emulator profiles are per-ROM/market/model: `utilities/scripts/emu/profiles/*.json`
(ROM path + SHA-256 verified at load, memory map, SH7055 peripheral set, sensor map).
Existing: `60E15120_N3J1E`, `60E0FC00_N3Z2EU`, `60E0G500_N3ZHEC`, `60E1B900_N3ZBEH`.
To run a different `.bin`, add a profile — recipe in [`utilities/scripts/emu/profiles/README.md`](utilities/scripts/emu/profiles/README.md).
Cross-check emulator traces against Renesas' own Simulator Debugger (SH7055) on
Windows with `utilities/scripts/emu/compare_traces.py` — see [`utilities/scripts/emu/README.md`](utilities/scripts/emu/README.md).

**Agent tooling:** in-session agents call `python utilities/scripts/hee.py <tool> '<json>'`
directly (no MCP needed — see AGENTS.md); external agents use the MCP plugin in
`.vibe/plugins/hee-re/` (stdio server + `hee-reverse-engineering` skill).

## Goals

- Understand the structure, behavior, and algorithms of the HEE PCM firmware.
- Run the actual binaries in the SH-2E emulator and validate every static finding
  dynamically (golden traces, virtual OBD-II/UDS port, live sensor UI).
- Maintain annotated disassembly, decompiled views, and clean reimplementations.
- Maintain RomRaider/ECUFlash XML definitions that match the ROMs.
- Document findings so the work is reproducible, evidence-ranked, and reviewable.

## Non-goals / ground rules

- Work only on hardware and dumps you own or are authorized to analyze; check your
  local laws before distributing circumvention code.
- **Never modify a stock ROM, capture, or dump** — binaries are immutable inputs.
  Patches write *new* output files only, with input SHA-256 asserted unchanged.
- **Never flash modified firmware to a vehicle** without bench validation first
  (BOOT-mode bench work additionally needs a ~150 Hz square wave on CN400 pin 3 —
  see [`docs/references/rx8club-user-guide-thread.md`](docs/references/rx8club-user-guide-thread.md) §8).

## Repository layout

| Path | Purpose |
|---|---|
| `input/` | Raw intake drop zone (ROM dumps, zips, saved pages, cloned repos). **Never committed** — verified artifacts are promoted out with provenance. |
| `submodules/` | Upstream repos as read-only git submodules (`RX8Defs`, `Rx8Man`, `Mazda_RX8_PCM_ReverseEngineering` — the latter holds the 10 stock ROMs, captures, Ghidra `.gar`). Never worked in or committed from; pinned commits cited in docs. |
| `binaries/` | Immutable dumps of **our own acquisitions** (`dumps/`, e.g. the 60E0G500/N3ZHEC factory read), `manifest.csv` = recursive SHA-256 + provenance. Upstream ROMs are referenced via the submodule, not duplicated. |
| `reverse-engineered/` | `disassembly/<rom-id>/` (addressed asm), `decompiled/<rom-id>/` (C export, 3,355 function files, named views, indexes), `reimplementation/` (compilable C11 + host tests). |
| `docs/` | `investigations/<rom-id>/` (subsystem reports, reviews, evidence, backups), `architecture/` (memory map, `design/`, `hardware/` pinout + wiring, `emulated-obd.md`, `emulator-ui.md` designs), `references/` (SH7055F manual, wiring book = ground truth, pinout PDF-derived md, RX8Club thread extract + OCR + inline-def TSV, upstream links), `learnings.md`. |
| `data/` | `definitions/` (RomRaider/ECUFlash XML), `labels/<rom-id>/` (label/alias TSV+JSON, validation records), `maps/<rom-id>/` (extracted calibration: tables — manifest + index.tsv + per-table JSON/CSV via `extract_maps.py`; literal-pool scalars — scalars.json/tsv via `extract_scalars.py`), `logs/` (real-car CSV/VTLOG — golden fixtures), `tunes/` (`.vtune` containers + notes; context only). |
| `utilities/` | `scripts/emu/` (SH-2E emulator: CPU, bus, peripherals, profiles, ISO-TP, OBD port, UI), `scripts/rx8-pcm-pipeline/` (Ghidra pipeline), `scripts/patchers/`, `scripts/defs-merge/`, `scripts/extract_maps.py` + `diff_maps.py` (calibration table extraction + cross-ROM diff → `data/maps/`), `scripts/extract_scalars.py` (literal-pool scalar constants → `data/maps/<rom-id>/scalars.*` + `cross_rom_scalars.json`), `scripts/hash_binaries.py`; `tools/ghidra/` (Java scripts, SH-2E Sleigh config). |
| `tests/` | pytest suite: emulator unit tests, corpus validation vs. the real disassembly, golden boot trace, ISO-TP/CAN/OBD/UI. Host C tests live beside code in `reverse-engineered/reimplementation/`. |

## Recommended workflow

Everything raw lands in `input/` first (uncommitted intake); only verified artifacts
are promoted into the tracked folders.

Work is delivered **branch + pull request**: never commit directly to `main`. Start
each work unit with `git checkout -b <type>/<slug> main` (types: `feat/`,
`research/`, `docs/`, `fix/`) and open a PR against `main` when it's done and
verified — full rules in [`AGENTS.md`](AGENTS.md) §Branch & PR workflow.

1. **Acquire** — dump from your own unit (bench ECU preferred); drop in `input/`,
   promote to `binaries/` with a manifest row (`utilities/scripts/hash_binaries.py`).
2. **Run it** — add an emulator profile, boot it, and diff the trace against
   `tests/fixtures/` goldens or the Renesas debugger (`compare_traces.py`).
3. **Document** — open/extend `docs/investigations/<rom-id>/` before deep diving.
4. **Disassemble/decompile** — Ghidra with the local SH-2E processor config
   (`utilities/tools/ghidra/processor/`); commit exports, not `.gpr/.rep` databases.
5. **Annotate with evidence discipline** — label ladder `FUN_`/`ref_`/`CAL_`/`tbl_`/
   `inferred_`/`candidate_`; never upgrade without new evidence; always tie symbols
   to addresses (`0x08001234`).
6. **Verify at the binary level** — re-check labels against raw ROM/disassembly
   (literal pools, constants, descriptors, GPIO reg+mask), run the pipeline's
   `validate_export.py`/`validate_reports.py`.
7. **Report** — 10-section subsystem format with mandatory function/RAM address
   tables and a plain-language §1a (template: [`docs/investigations/60E15120_N3J1E/knock_control_report.md`](docs/investigations/60E15120_N3J1E/knock_control_report.md)).
8. **Reimplement & test** — compilable C in `reverse-engineered/reimplementation/`
   with host tests, cross-checked against the emulator.

## Conventions

- Dates ISO (`YYYY-MM-DD`); filenames `kebab-case`. Binaries: upstream names
  (`<fw-id>_<cal-id>.bin`) when referencing submodule ROMs; own acquisitions
  `<source>-<stem>-<date>.bin`.
- Addresses `0x08001234`; memory map: ROM `0x00000000–0x0007ffff`, RAM
  `0xffff6000–0xffffdfff`, volatile I/O `0xffffe000–0xffffffff`.
- Binary blobs (`.bin/.gar/.zip/.jar/.exe/.dll/.so/.pdf/.vtlog`) go through Git LFS
  (`.gitattributes`) — `git-lfs` is required to clone/checkout.
- Commit messages: short imperative subject, body explaining *why*; each work unit
  is delivered as a branch + PR against `main` ([`AGENTS.md`](AGENTS.md) §Branch &
  PR workflow), never as direct commits to `main`.
- Discrepancies are documented, never silently resolved (see ROADMAP register D1–D10).

## Status

- **Emulator (ROADMAP Phase 1): implemented and fidelity-hardened.**
  Corpus-validated SH-2E core (9,902 opcodes, 100% of the 168k-instruction
  disassembly); boot of `60E15120_N3J1E` passes CAN init and reaches the main
  idle loop (0x3dac) clean; golden 200k PC trace byte-exact (`compare_traces.py`
  self-check MATCH; Renesas SH-2E Simulator Debugger cross-check:
  NMI-loop segment MATCH 20000/20000, full-boot-from-reset MATCH 147/147 then a
  peripheral-pin divergence (see `utilities/scripts/emu/README.md` §cross-check).
  Peripherals at their symbols.tsv bases with real behavior:
  RCAN0 mailbox model at 0xffffe400 (W1C pending regs, MCR/GSR handshake,
  inject→RXPR, TXPR→tx_log), ADC ADDRn channels with ADST→ADF handshake,
  ATU-II at 0xfffff400 (ch10B tick, crank input capture), DMAC, WDT (OVF flag +
  firmware poll), ROM read-only. Sensor inputs are wired to the real ADC/ATU
  read paths (E2 closed); E3 (WDT IVT slot 0x358) and E5 (NMI pin, SYSC model)
  closed; CAN RX interrupt (IVT 0x378) fires on inject so a plain run moves 0x7e0
  frames into the UDS buffer autonomously (E6 partial); the virtual OBD-II port
  drives the ROM's own CAN/UDS entry points for the response side (E4). `harness.py` + `tests/test_phase1_dynamic.py` dynamically
  reproduce static findings in the emulator (math helpers vs the reimplementation,
  knock clamp 0x13bd2 = [-10,0]°, injector map 0xd7d4→ATU-II 8A-8F). Debugger
  (breakpoints/watchpoints/UBC), browser UI with drive-cycle replay, agent
  tooling (`hee.py` + MCP plugin). 61/61 tests.
- **Labeling:** the emulator-driven OS-scheduler pass resolved 27 functions + 16 RAM
  cells + 9 tables (OS scheduler, IVT at VBR 0x7fc50, CAN/UDS transport, ADC/crank)
  into the decompiled views —
  [`docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md`](docs/investigations/60E15120_N3J1E/os_scheduler_can_ivt_report.md).
- **UDS/Mode-22 dispatch labeling (ROADMAP group C item 1):** all 99
  Mode 22 PID records (table 0x5f10c) and all 29 UDS service records (table 0x5eb40)
  carry semantic names, plus the sub-PID table 0x5f5b2, the service router
  0x68dac and the ISO-TP frame dispatcher 0x6842c — 177 functions + 63 RAM cells +
  3 tables renamed; verified against the raw disassembly and by a full dynamic
  sweep in the emulator (all 99 PIDs through the ROM's own 0x5774c; 15 services
  routed through 0x68dac) —
  [`docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md`](docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md).
- **Ignition timing:** the Phase 2 labeling pass verified the thread §9
  BTDC equation in the emulator (blend 0x123da/0x124d6, clamp 0x121fc/0x12300),
  labeled 15 functions + 22 RAM + 17 tables, with the min-advance constants
  (-25.0/-58.5 deg) re-verified at the binary level —
  [`docs/investigations/60E15120_N3J1E/ignition_timing_report.md`](docs/investigations/60E15120_N3J1E/ignition_timing_report.md) (all subsystem
  reports carry a plain-language §1a per AGENTS.md rule 8).
- **Pipeline:** `utilities/scripts/rx8-pcm-pipeline/` resolves paths via
  `paths.py` to this repo layout; validators
  (`validate_export`, `validate_reports`, `verify_readability`, `verify_math_units`)
  run from the repo root and PASS.
- **Analysis:** full static export + labeled subsystems (knock, fueling, intake,
  load) for `60E15120_N3J1E`.
- **Calibration extraction (ROADMAP P3):**
  `extract_maps.py` scans every ROM for Denso descriptors and dumps all tables
  to `data/maps/` — 587 tables on 60E15120_N3J1E (all 478 RX8Defs-matched + 109
  unnamed), 381–587 across all 10 stock ROMs + 1 own dump, 0 non-monotonic
  axes. Cross-ROM structural diff via `diff_maps.py`. Report:
  [`docs/investigations/60E15120_N3J1E/calibration_extraction_report.md`](docs/investigations/60E15120_N3J1E/calibration_extraction_report.md).  Scalar constants in shared literal pools (not descriptor tables — e.g. the
  base fuel scalar 0.07196 @0x78170 → `fuel_load_scale_ffffbed0`) are extracted
  separately by `extract_scalars.py` into `data/maps/<rom-id>/scalars.*`
  + `data/maps/cross_rom_scalars.json` — report §6a.
- **Data:** 1 own ROM dump (60E0G500/N3ZHEC factory), 10 stock ROMs via submodule, real-car logs in
  `data/logs/`, XML definitions in `data/definitions/`, extracted calibration
  tables and scalar constants in `data/maps/` (14 ROMs + cross-ROM diffs).
- See [`docs/learnings.md`](docs/learnings.md) for session know-how and ROADMAP.md for what's next.
