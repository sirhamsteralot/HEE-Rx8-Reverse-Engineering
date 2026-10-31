# Emulator profiles

One JSON profile per ROM / market / model variant. The emulator core (`../emu.py`)
is profile-driven: same code runs different bins with different peripherals.

## Adding a profile (running a different .bin)

1. Put the bin somewhere referenceable: own dumps → `binaries/dumps/<source>-<stem>-<date>.bin`
   (+ manifest row via `python utilities/scripts/hash_binaries.py`); upstream ROMs
   → reference `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/<file>.bin`
   directly (don't duplicate).
2. Hash it: `sha256sum <bin>` (or read `binaries/manifest.csv`).
3. Copy `template.json` to `<ROM-ID>_<CAL-ID>.json` (e.g. `60E1B900_N3ZBEH.json`;
   read fw ID at 0x2000 and cal ID at 0x6c046 from the bin) and fill `rom.path`,
   `rom.sha256`, `rom.size`, `market`/`model`/`variant` (ports, transmission, DSC,
   RKE, immobilizer — these drive the peripheral set), memory map (SH7055 defaults
   are the same for all S1 PCMs), peripherals (bases per `docs/references/Sh7055h.pdf`,
   cross-check `symbols.tsv` of that ROM), `sensors`, `replay_map`, `watch`, and
   `memory.io_read_overrides` for any hardware-ready poll bits the boot needs.
4. Run it:
   ```sh
   python utilities/scripts/emu/emu.py --profile 60E1B900_N3ZBEH --cycles 1000000
   python utilities/scripts/emu/debug.py --profile 60E1B900_N3ZBEH     # interactive
   python utilities/scripts/emu/ui.py --profile 60E1B900_N3ZBEH         # browser UI
   python utilities/scripts/hee.py hee_boot '{"profile": "60E1B900_N3ZBEH", "cycles": 1000000}'
   ```
   The ROM hash is verified at load. Per-ROM addresses (e.g. the WDT handler) differ —
   set `wdt.config.overflow_handler` from that ROM's labels/disassembly.
5. If a run stops on an unknown opcode, the ROM uses an instruction outside the
   60E15120 corpus: regenerate the table for it with
   `python ../gen_opdec.py <its disassembly> opdec.py` (needs a Ghidra export first).

## Existing profiles

- `60E15120_N3J1E.json` — primary analysis target (USDM S1 6-port MT).
- `60E0FC00_N3Z2EU.json` — reference ROM (2004 US 6-port MT), byte-match seeding source.
- `60E0G500_N3ZHEC.json` — own dump, Aron's ECU (EU 6-port 2004); streetport-tuned
  variants in `binaries/dumps/` share its base.
- `60E1B900_N3ZBEH.json` — added 2026-10-31 to demonstrate running another bin.
- `60E0G500_N3ZHEC_streetport_{5500,9500,10000}max.json` — the user-tuned streetport
  bins from `binaries/dumps/` (fw 60E0G500). Run e.g.:
  `python ../emu.py --profile 60E0G500_N3ZHEC_streetport_5500max --cycles 1000000`
  — boots clean; read the tuned rev-limit cal in-emulation at 0x6d54c
  (stock 9000.0 vs 5500.0/9500.0/10000.0 rpm). Tuning-validation targets, not for
  flashing.

## Existing profiles

- `60E15120_N3J1E.json` — primary analysis target (USDM S1 6-port MT).
- `60E0FC00_N3Z2EU.json` — reference ROM (2004 US 6-port MT), byte-match seeding source.
