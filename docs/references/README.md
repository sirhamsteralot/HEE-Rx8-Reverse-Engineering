# references/

External reference material and provenance for third-party sources.

## PDFs (primary reference sources — cite by table/section in reports)

| File | What it is | Use it for | Trust caveats |
|---|---|---|---|
| `Sh7055h.pdf` | Renesas **SH7055F hardware manual** (ADE 602-155B) | Chip-level truth: register map, Tables 1.2/1.3 pin functions & package pin numbers, PFC/port control, ATU-II channel→pin mapping | Vendor document — authoritative for the silicon |
| `13Electrical.pdf` | Original RX-8 electrical wiring book (copy-protected; pages are images) — **ground truth for the RX-8 electrical systems** | Underlying circuit diagrams; source for all derived pinout/colour data | Text extraction yields mostly headers — read via renders; treat as image source |
| `renesis_i_rotary_engine_fundamentals.pdf` | Mazda **"Renesis Rotary Engine Fundamentals"** training guide (©2003 Mazda Motor of America, 75 pp) | Engine-architecture background for the 13B-MSP: rotor/gas-seal/oil-seal geometry, four strokes, Renesis design characteristics (side intake, side exhaust) — context for the load, fueling, ignition and knock models | Vendor training material — authoritative for the Renesis design; not a service or calibration spec |
| `Mazda_RX8_TSB-01-015-08.pdf` | Mazda North American Operations **TSB 01-015/08 "Engine cranks no start"** (2004–2008 RX-8, last issued 2008-12-26, 16 pp) | Official symptom context for short cold runs: flooded spark plugs / carbon-locked apex seals, purge-by-cranking procedure, OEM plugs (leading NGK RE7C-L heat range 7, trailing NGK RE9B-T heat range 9) — backdrop for cranking fuel/timing and flood-clear behavior | Dealer service bulletin — describes symptom + mechanical fix; any PCM flood-clear/cranking strategy is our own ROM finding, not from this document |
| `Effect of leading and trailing spark plugs on combustion fuel consumption and exhaust emissions.pdf` | Peer-reviewed paper (Ö. Cihan & O. A. Kutlar, *Arabian Journal for Science and Engineering*, 2021, DOI [10.1007/s13369-021-05456-3](https://doi.org/10.1007/s13369-021-05456-3)) on leading vs trailing plug effects in a Wankel engine | Mechanism background for why the ROM runs separate leading/trailing ignition timing and fueling (see [`../investigations/60E15120_N3J1E/ignition_timing_report.md`](../investigations/60E15120_N3J1E/ignition_timing_report.md)) | Single lab study on a Wankel test engine, not the RX-8 — background for mechanisms only, never a source of calibration values |
| `timingchart.pdf` | Aftermarket rotary ignition "Timing Recommendations" chart (1971–1992 12A/13B, carb-era, incl. street/bridge/peripheral porting) | Historical context for leading/trailing advance-spread thinking | Carb-era 12A/13B chart — predates the Renesis 13B-MSP; never use its advance numbers for RX-8 calibration |
| `mazda-rx-8-s-dias-intake-system-deep-research-report.pdf` | Generated "deep research" synthesis (8 pp, received 2026-11-13, SHA-256 `06cd24d85f81edc4932eb36f56e697793cffc0b6cb3f1b46557a7fdeaded803f`) of the RX-8 S-DAIS/S-DIAS intake system: SSV/APV/VFAD/VDI control logic cross-checked against this repo's firmware evidence, the FSM, and the RX8Club S-DIAS thread | Orientation on the four intake actuators and on community-vs-firmware discrepancies; its firmware anchors point at [`../investigations/60E15120_N3J1E/intake_solenoids_report.md`](../investigations/60E15120_N3J1E/intake_solenoids_report.md) | AI-generated secondary synthesis — never primary evidence. Runner-length figures are single-source RX8Club measurements, uncorroborated by any Mazda document. Where its firmware reading differs from the ROM-verified intake report, the report + ROM govern |
| `Engine_Acoustic_Tuning_Rotary_Intake_Design.pdf` | 21-page technical research report (research checked 2026-11-13, SHA-256 `f1f4bfb8e5ab4e679ffece0a14c10685fcb9dd72e749a98c836495c14c6b5638`) on acoustic tuning of rotary intakes: runner length vs pressure-wave phase, cross-rotor waves, intake temperature as density + wave-speed input, 1-D unsteady-gas modelling, test methods; source list pp. 20–21 | Background for why S-DIAS stages port count and effective runner length (VDI/VFAD findings in the [intake solenoids report](../investigations/60E15120_N3J1E/intake_solenoids_report.md)) and for modelling the manifold geometry | Mixes published results with derived calculation examples on an assumed 654 cm³/chamber two-rotor — by its own statement "not tested dimensions for your RX-8"; several listed sources were reviewed as abstracts only; never a source of calibration values |

Derived from `13Electrical.pdf` (regenerate + re-diff, don't edit in place): the
Series-1 PCM connector pinout lives as text at
[`../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md`](../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md). It has **no chip-pin numbers** — package-pin ↔ connector-terminal is board
routing, unresolved. Honour its markers: unmarked = confirmed, `*` single-source,
`†` conflict, `³` high-power only, `–` unread.

Rule: firmware dataflow comes from the ROM; physical pin/terminal associations from
these documents; the two meet only at the SH7055F package pin. Never assert a
package-pin ↔ connector-terminal link from the pinout alone.

## Workshop manual (kept uncommitted in `input/`, vetted by use)

- The **full RX-8 workshop-manual set** (sections `0Owners` … `13bmsp`, incl.
  `3EngineDetails.pdf` and `4EngineControl.pdf`) is available uncommitted in
  `input/Proton Drive Download - 2026-11-13.zip`. The zip's `13Electrical.pdf`
  (SHA-256 `c2acd5e528b6af329ec1f4efa437815ef4cc90374c2d36c6cdd144059fccb8df`, 148 pp,
  opens without a password) is a different container copy of the same book as the
  tracked `13Electrical.pdf` above (SHA-256
  `8d17e05f4df497dda09c559050c94b43f06574f4bc1d7bfa4db3b168a85d7379`, copy-protected) —
  the tracked copy remains the reference; do not duplicate. The zip's
  `4EngineControl.pdf` is byte-identical to `input/4EngineControl.pdf`
  (SHA-256 `527b22b1b1b28e24f0529de1d3dc020548e1e55be1a8070ff304558555901415`).
- `input/4EngineControl.pdf` — Mazda RX-8 workshop manual **"RX8 – Engine
  Diagnostics & Control"** (PDF created 2003-11-21; copy-protected like the others).
  Its **DTC TABLE** section is the official RX-8 fault-code list; parsed (pdftotext
  -layout + column slicing) to the tracked
  [`../../data/dtc/mazda_dtc_table.tsv`](../../data/dtc/mazda_dtc_table.tsv) and merged
  into [`../../data/dtc/pcodes.tsv`](../../data/dtc/pcodes.tsv) — the source for the def
  DTC labels. Cite it as "RX8 Engine Diagnostics & Control (2003),
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
  pinned at `b243b355002f591f97631708af081d89e935b6c9`:
  `Stock_ROMs/` (10 stock ROMs — referenced from [`binaries/README.md`](../../binaries/README.md)),
  `Data_binaries/` (RAM/EEPROM/IC captures), `Ghidra_Archives/` (`.gar`),
  `Utilities/` (upstream patcher scripts)
- `submodules/RX8Defs` — github.com/equinox311/RX8Defs, pinned at
  `39d98a0a87faa1ea3225f7122a1ac2b9d620ff9f`: upstream RomRaider/ECUFlash ECU +
  logger XML definitions, referenced in place — no promoted copies (rule 4b);
  the one differing snapshot is `data/definitions/romraider/upstream-rx8defs/rx8_defs.xml`
  @ upstream `ff5ab4f`, the 60E15120 merge base — see
  [`../../data/definitions/README.md`](../../data/definitions/README.md);
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
  (canonical via renesas.com); see also [`utilities/scripts/emu/README.md`](../../utilities/scripts/emu/README.md) on why we
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
- The `Forum Threads/Open Source S1 RX-8 ECU Reverse Engineering, Data Logging
  and Tuning.md` inside `input/Proton Drive Download - 2026-11-13.zip` is a
  **0-byte placeholder** — nothing to extract; the thread is the one curated
  above. Also reviewed from that zip and deliberately left uncommitted in
  `input/` (no PCM-relevant content): `MILKY SUBSTANCE ON OIL LEVEL GAUGE
  (DIPSTICK).pdf` (TSB 01-050/06, coolant-in-oil — mechanical),
  `RR Engine Teardown RX8Club Pages 1-8/9-17/18-19.pdf` (image-only forum
  printouts — engine teardown photos), `67112 RX8 Front Bumper
  Replacement.pdf` (Racing Beat bodywork instructions).
