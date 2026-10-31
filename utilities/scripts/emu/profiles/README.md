# Emulator profiles

One JSON profile per ROM / market / model variant. The emulator core (`../emu.py`)
is profile-driven: same code runs different bins with different peripherals.

## Adding a profile

1. Copy `template.json` to `<ROM-ID>_<CAL-ID>.json` (kebab/uppercase as the ROM
   filename, e.g. `60E1B900_N3ZBEH.json`).
2. Fill `rom.path` (relative to repo root — stock ROMs live in
   `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/`; own dumps go in
   `binaries/`), `rom.sha256` (from `binaries/manifest.csv` or `sha256sum`), `size`.
3. Set `market` / `model` / `variant` (engine_ports 4|6, transmission MT|AT,
   dsc, rke, immobilizer) — these document which peripherals and pins the car has.
4. Adjust `peripherals`: enable/disable or resize instances. Register bases per
   `docs/references/Sh7055h.pdf`; cross-check addresses against
   `reverse-engineered/decompiled/<rom-id>/symbols.tsv` (e.g. WDT TCSR/TCNT/RSTCSR
   = 0xffffec10/11/12, PBDR = 0xfffff738).
5. Fill `sensors` with scripted input values (ADC channels, GPIO inputs).
6. Validate: `python ../emu.py --profile <name> --cycles 1000` must load without
   profile errors (ROM hash is verified automatically).

## Existing profiles

- `60E15120_N3J1E.json` — primary analysis target (USDM S1 6-port MT).
- `60E0FC00_N3Z2EU.json` — reference ROM (2004 US 6-port MT), byte-match seeding source.
