# HEE — Mazda RX-8 Reverse Engineering

Workspace for reverse engineering the Mazda RX-8 (Series 1) PCM/ECU — a Renesas
**SH-2E (SH7055F)**, big-endian, 512 KiB flash / 32 KiB RAM. No firmware source
exists; everything is derived from ROM binaries. Seeded 2026-10-31 from a prior
effort workspace and community material, now with a working SH-2E emulator.

**Plan:** see **[ROADMAP.md](ROADMAP.md)** — Phase 1 (simulation suite) is implemented;
there is a fidelity-limits register at the bottom. **Rules for agents/humans:**
**[AGENTS.md](AGENTS.md)**.

## Quick start

```sh
git clone <this repo> && cd HEE-Rx8-Reverse-Engineering
git lfs install && git submodule update --init --recursive   # git-lfs required (ROMs/PDFs are LFS)
python -m pytest tests/                                       # 24 tests, ~8s
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 1000000
python utilities/scripts/emu/emu.py --profile 60E0G500_N3ZHEC_streetport_5500max --cycles 1000000  # tuned bin
python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E   # UI on http://127.0.0.1:8080/
python utilities/scripts/hash_binaries.py --check             # verify binaries/manifest.csv
```

Emulator profiles are per-ROM/market/model: `utilities/scripts/emu/profiles/*.json`
(ROM path + SHA-256 verified at load, memory map, SH7055 peripheral set, sensor map).
Existing: `60E15120_N3J1E`, `60E0FC00_N3Z2EU`, `60E0G500_N3ZHEC` (stock, not tuned — own
dump of Aron's ECU), `60E1B900_N3ZBEH`, and the tuned `60E0G500_N3ZHEC_streetport_*`.
To run a different `.bin`, add a profile — recipe in `utilities/scripts/emu/profiles/README.md`.
Cross-check emulator traces against Renesas' own Simulator Debugger (SH7055) on
Windows with `utilities/scripts/emu/compare_traces.py` — see `utilities/scripts/emu/README.md`.

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
  see `docs/references/rx8club-user-guide-thread.md` §8).

## Repository layout

| Path | Purpose |
|---|---|
| `input/` | Raw intake drop zone (zips, saved pages, prior efforts). **Never committed** — verified artifacts are promoted out with provenance. |
| `submodules/` | Upstream repos as read-only git submodules (`RX8Defs`, `Rx8Man`, `Mazda_RX8_PCM_ReverseEngineering` — the latter holds the 10 stock ROMs, captures, Ghidra `.gar`). Never worked in or committed from; pinned commits cited in docs. |
| `binaries/` | Immutable dumps of **our own acquisitions** (`dumps/`, e.g. Aron's 60E0G500 stock + 3 tuned streetport ROMs), `manifest.csv` = recursive SHA-256 + provenance (tuned ROMs flagged). Upstream ROMs are referenced via the submodule, not duplicated. |
| `reverse-engineered/` | `disassembly/<rom-id>/` (addressed asm), `decompiled/<rom-id>/` (C export, 3,355 function files, named views, indexes), `reimplementation/` (compilable C11 + host tests). |
| `docs/` | `investigations/<rom-id>/` (subsystem reports, reviews, evidence, backups; incl. `60E0G500_N3ZHEC/` streetport diff), `architecture/` (memory map, `design/`, `hardware/` pinout + wiring, `emulated-obd.md`, `emulator-ui.md` designs), `references/` (SH7055F manual, wiring book = ground truth, pinout PDF-derived md, RX8Club thread extract + OCR + inline-def TSV, upstream links), `learnings.md`. |
| `data/` | `definitions/` (RomRaider/ECUFlash XML), `labels/<rom-id>/` (label/alias TSV+JSON, validation records), `logs/` (real-car CSV/VTLOG — golden fixtures), `tunes/` (`.vtune` containers + notes; context only). |
| `utilities/` | `scripts/emu/` (SH-2E emulator: CPU, bus, peripherals, profiles, ISO-TP, OBD port, UI), `scripts/rx8-pcm-pipeline/` (Ghidra pipeline), `scripts/patchers/`, `scripts/defs-merge/`, `scripts/hash_binaries.py`; `tools/ghidra/` (Java scripts, SH-2E Sleigh config). |
| `tests/` | pytest suite: emulator unit tests, corpus validation vs. the real disassembly, golden boot trace, ISO-TP/CAN/OBD/UI. Host C tests live beside code in `reverse-engineered/reimplementation/`. |

## Recommended workflow

Everything raw lands in `input/` first (uncommitted intake); only verified artifacts
are promoted into the tracked folders.

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
   tables (template: `docs/investigations/60E15120_N3J1E/knock_control_report.md`).
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
- Commit messages: short imperative subject, body explaining *why*.
- Discrepancies are documented, never silently resolved (see ROADMAP register D1–D10).

## Status (2026-10-31)

- **Emulator (ROADMAP Phase 1): implemented, fidelity-hardened 2026-10-31.**
  Corpus-validated SH-2E core (9,902 opcodes, 100% of the 168k-instruction
  disassembly); boot of `60E15120_N3J1E` passes CAN init and reaches the main
  idle loop (0x3dac) clean; golden 200k PC trace byte-exact (`compare_traces.py`
  self-check MATCH; Renesas Simulator Debugger diff still pending — tool not
  installed here). Peripherals at their symbols.tsv bases with real behavior:
  RCAN0 mailbox model at 0xffffe400 (W1C pending regs, MCR/GSR handshake,
  inject→RXPR, TXPR→tx_log), ADC ADDRn channels with ADST→ADF handshake,
  ATU-II at 0xfffff400 (ch10B tick, crank input capture), DMAC, WDT (OVF flag +
  firmware poll), ROM read-only. Sensor inputs are wired to the real ADC/ATU
  read paths (E2 closed); the virtual OBD-II port drives the ROM's own CAN/UDS
  entry points (E4). `harness.py` + `tests/test_phase1_dynamic.py` dynamically
  reproduce static findings in the emulator (math helpers vs the reimplementation,
  knock clamp 0x13bd2 = [-10,0]°, injector map 0xd7d4→ATU-II 8A-8F). Debugger
  (breakpoints/watchpoints/UBC), browser UI with drive-cycle replay, agent
  tooling (`hee.py` + MCP plugin). 34/34 tests.
- **Analysis:** full static export + labeled subsystems (knock, fueling, intake,
  load) for `60E15120_N3J1E`; streetport-vs-stock diff done for 60E0G500
  (cal-only; rev limiter float32 at 0x6d54c: 9000→5500/9500/10000).
- **Data:** 4 own ROM dumps, 10 stock ROMs via submodule, real-car logs in
  `data/logs/`, XML definitions in `data/definitions/`.
- See `docs/learnings.md` for session know-how and ROADMAP.md for what's next.
