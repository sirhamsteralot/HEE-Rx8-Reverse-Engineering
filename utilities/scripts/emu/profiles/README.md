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
   are the same for all S1 PCMs: ROM 0x0-0x7ffff, **RAM 0xffff6000-0xffffe000**,
   I/O 0xffffe000-0xffffffff), peripherals (bases per `symbols.tsv` of that ROM —
   the canonical set is RCAN0 0xffffe400, RCAN1 0xffffe600, ATU-II 0xfffff400,
   SCI 0xfffff000, ADC 0xfffff800, WDT 0xffffec10, DMAC 0xffffecb0,
   SYSC 0xffffed00 (IPR/ICR/ISR; `nmi_level` = NMI pin high, boot polls ICR bit15
   at 0x8ea), GPIO 0xfffff700 (`inputs` for scripted input pins)), `sensors`,
   `replay_map`, `watch`, `uds` (ROM-specific OBD entry points; only labeled for
   60E15120 so far). The `can` entry takes `rx_vector` (CAN RX interrupt IVT
   offset, 0x378) so inject() raises it. No `io_read_overrides` needed anymore
   (E5 closed); add them only if a future ROM polls a ready-bit we have not
   modeled, and document which bit and why.
4. Run it:
   ```sh
   python utilities/scripts/emu/emu.py --profile 60E1B900_N3ZBEH --cycles 1000000
   python utilities/scripts/emu/debug.py --profile 60E1B900_N3ZBEH     # interactive
   python utilities/scripts/emu/ui.py --profile 60E1B900_N3ZBEH         # browser UI
   python utilities/scripts/hee.py hee_boot '{"profile": "60E1B900_N3ZBEH", "cycles": 1000000}'
   ```
   The ROM hash is verified at load. Sensors inject through the real hardware
   read paths (`via: "adc"` → ADDRn channel, `via: "atu2"` → crank input
   capture for rpm; `via: "override"` is the legacy placeholder path). The WDT
   overflow is OVF-flag-only — the firmware polls TCSR and calls its own service
   routine, so do NOT set `wdt.config.overflow_handler` (that direct jump
   clobbers r0-r4 mid-loop). Per-ROM addresses for the `uds` section differ —
   label them from that ROM's disassembly before using the OBD port.
5. If a run stops on an unknown opcode, the ROM uses an instruction outside the
   60E15120 corpus: regenerate the table for it with
   `python ../gen_opdec.py <its disassembly> opdec.py` (needs a Ghidra export first).

## Existing profiles

Stock / reference ROMs:

- `60E15120_N3J1E.json` — primary analysis target (USDM S1 6-port MT).
- `60E0FC00_N3Z2EU.json` — reference ROM (2004 US 6-port MT), byte-match seeding source.
- `60E0G500_N3ZHEC.json` — factory ROM (stock): own dump of the donor ECU (EU 6-port
  2004, fw 60E0G500 / cal N3ZHEC).
- `60E1B900_N3ZBEH.json` — 6-port US MT (added 2026-10-31 as the "run another bin" demo).
