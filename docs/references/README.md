# references/

External reference material and provenance for third-party sources.

## PDFs (primary reference sources — cite by table/section in reports)

| File | What it is | Use it for | Trust caveats |
|---|---|---|---|
| `Sh7055h.pdf` | Renesas **SH7055F hardware manual** (ADE 602-155B) | Chip-level truth: register map, Tables 1.2/1.3 pin functions & package pin numbers, PFC/port control, ATU-II channel→pin mapping | Vendor document — authoritative for the silicon |
| `13Electrical.pdf` | Original RX-8 electrical wiring book (copy-protected; pages are images) — **ground truth for the RX-8 electrical systems** | Underlying circuit diagrams; source for all derived pinout/colour data | Text extraction yields mostly headers — read via renders; treat as image source |

Derived from `13Electrical.pdf` (regenerate + re-diff, don't edit in place): the
Series-1 PCM connector pinout now lives as text at
[`../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md`](../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md) (the earlier v3 PDF was
removed). It has **no chip-pin numbers** — package-pin ↔ connector-terminal is board
routing, unresolved. Honour its markers: unmarked = confirmed, `*` single-source,
`†` conflict, `³` high-power only, `–` unread.

Rule: firmware dataflow comes from the ROM; physical pin/terminal associations from
these documents; the two meet only at the SH7055F package pin. Never assert a
package-pin ↔ connector-terminal link from the pinout alone.

## Received 2026-11-03 (kept uncommitted in `input/`, vetted by use)

- `input/4EngineControl.pdf` — Mazda RX-8 workshop manual **"RX8 – Engine
  Diagnostics & Control"** (PDF created 2003-11-21; copy-protected like the others).
  Its **DTC TABLE** section is the official RX-8 fault-code list; parsed (pdftotext
  -layout + column slicing) to the tracked
  [`../../data/dtc/mazda_dtc_table.tsv`](../../data/dtc/mazda_dtc_table.tsv) and merged
  into [`../../data/dtc/pcodes.tsv`](../../data/dtc/pcodes.tsv) — used for the def
  DTC labels since 2026-11-03. Cite it as "RX8 Engine Diagnostics & Control (2003),
  DTC TABLE". Evidence + cross-checks:
  [`../investigations/60E15120_N3J1E/dtc_control_report.md`](../investigations/60E15120_N3J1E/dtc_control_report.md) §5b.
  The PDF itself stays in `input/` (AGENTS.md rule 4); the parsed TSV is the
  committable artifact.

## Upstream repositories (git submodules — read-only context)

Tracked as submodules under `submodules/` (see `.gitmodules`); fetch with
`git submodule update --init --recursive`. Never edit or commit inside them —
cite files by path + upstream commit hash instead. These are the canonical home
for their content; our repo references them rather than duplicating files:

- `submodules/Mazda_RX8_PCM_ReverseEngineering` — github.com/equinox311/Mazda_RX8_PCM_ReverseEngineering,
  pinned at `492193ba8548869b91915be55133d85ab7a8722a`:
  `Stock_ROMs/` (10 stock ROMs — referenced from `binaries/README.md`),
  `Data_binaries/` (RAM/EEPROM/IC captures), `Ghidra_Archives/` (`.gar`),
  `Utilities/` (upstream patcher scripts)
- `submodules/RX8Defs` — pinned at `1b3aea274b1edc3cc57ed78a6d3f19b9e870abfc`:
  upstream RomRaider/ECUFlash XML definitions. Our `data/definitions/` copies were
  taken from specific upstream commits (cited in
  `docs/investigations/60E15120_N3J1E/defs-merge/`) and may differ from the pinned
  HEAD — that is intentional.
- `submodules/RX8Defs` — github.com/equinox311/RX8Defs: upstream RomRaider ECU +
  logger XML definitions, referenced in place (no promoted copies since the 2026-11-01
  D8 dedupe; the one differing snapshot kept is `data/definitions/romraider/upstream-rx8defs/rx8_defs.xml`
  @ upstream `ff5ab4f`, the 60E15120 merge base — see [`../../data/definitions/README.md`](../../data/definitions/README.md));
  commit hashes are cited as merge provenance — never rewrite that history
- `submodules/Rx8Man` — github.com/Rx8Man/Rx8Man, pinned at
  `50f905bc271e918a00ce0eda96e6414c220886e5`: PCM reflash tool for Tactrix
  (never flash without bench validation)

Related but not submoduled (not git repos in the intake, URL only):

- RomRaider (Java) — https://www.romraider.com/ / github.com/RomRaider/RomRaider
- Renesas SH-2E/SH7055S hardware manual:
  https://www.renesas.com/en/document/mah/sh-2e-sh7055s-hardware-manual
- Renesas **SH-2E software (ISA) manual** (opcode encodings — the reference for the
  emulator): mirror https://evoecu.logic.net/mirror/cpudocs/sh7055f/rej09b0316_sh_2esm.pdf
  (canonical via renesas.com); see also `utilities/scripts/emu/README.md` on why we
  don't use QEMU/Unicorn (SH-4 only / no SH) and use a custom exact core instead.

## Community material

- [`rx8club-user-guide-thread.md`](rx8club-user-guide-thread.md) — curated extraction from the RX8Club "Open Source
  S1 RX-8 ECU RE / Data Logging / Tuning — User's Guide" thread (raw saved pages in
  `input/`): ROM↔cal-ID table, BOOT-mode CN400 pinout, UDS dump/flash services
  (0x10/0x23/0x27/0x34/0x36/0x37), security-key notes, checksum/CVN open question,
  concrete RAM/code addresses for 60E0FC00 (cross-checked), engine-load (g/rev) math,
  ignition-timing BTDC equation + OL-fueling chain hypotheses (§9), immo/seed-key
  notes (§10), `rx8club-inline-defs.tsv` (inline XML table addresses for
  cross-checking `data/definitions/`), and §12 + `rx8club-ocr/` (OCR of the pages 2–3
  screenshots: `getMode22EngineLoad` / PID 0x43 = g/rev × 1/255 with injectors-off → 0,
  Mode 22 dispatch at 0x5fa0c in 60E0FC00, RomRaider table inventories for 60E0FC00 and
  G-ROM FlexFuel, ignition 2D tables in deg BTDC over load g/rev × RPM).
  Forum claims are `candidate_` until verified against our ROMs.

## Prior-effort workspace docs

- [`prior-effort-agents.md`](prior-effort-agents.md) — the previous workspace's AGENTS.md, preserved for
  provenance; its rules are distilled into this repo's root `AGENTS.md`.
- [`../learnings.md`](../learnings.md) — the previous sessions' know-how log.
