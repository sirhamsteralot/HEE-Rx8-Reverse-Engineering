# RX8Club thread extract — "Open Source S1 RX-8 ECU Reverse Engineering, Data Logging, and Tuning — User's Guide"

- **Source:** https://www.rx8club.com/series-i-engine-tuning-forum-63/open-source-s1-rx-8-ecu-reverse-engineering-data-logging-tuning-users-guide-276137/
  (pages 1–9, incl. `/page2/` … `/page9/`), by equinox92 et al.
- **Saved raw:** `input/Open Source S1 RX-8 ECU … - Page N - RX8Club.com.htm` (+ `_files/` assets) — uncommitted intake, do not reference from tracked code.
- **Accessed / extracted:** 2026-10-31. This file is a curated extraction; claims below are
  forum posts — treat as `candidate_` until verified against our ROMs/disassembly.

## What we can use

### 1. Toolchain map (corroborates our submodules/definitions)

- RomRaider ECU editor + logger need `rx8_defs.xml` / `logger_rx8_defs.xml`
  → we hold upstream/reviewed/merged copies in `data/definitions/romraider/`;
  upstream repo = `submodules/RX8Defs`.
- Ghidra archives of the USDM 6-port ROM → `submodules/Mazda_RX8_PCM_ReverseEngineering/Ghidra_Archives/`
  (the `.gar` files we previously held; now referenced via the pinned submodule).
- Rx8Man (CAN/J2534 flash read/write) → `submodules/Rx8Man`.
- Launch-control / flex-fuel patcher lives in the upstream repo's `Utilities/`
  (our local versions in `utilities/scripts/patchers/`).

### 2. ROM ID ↔ calibration ID table (forum-claimed)

| ROM | Cal ID | Notes |
|---|---|---|
| 60E0FB00 | N3Z2ET | 2004 US 6-port MT |
| 60E0FC00 | N3Z2EU | 2004 US 6-port MT (reference ROM in our pipeline) |
| 60E1A300 | N3K1ES | 2005 JDM 4-port MT |
| 60E1A500 | N3K1EU | 2004 JDM 4-port |
| — | N3H3EV | 2004 JDM 6-port |
| 60E1B900 | N3ZBEH | 6-port US MT |
| 60E1D300 | N3J1EL | 6-port MT |
| 60E1D400 | N3J1EM | 6-port MT |
| 60E1B800 | (two N3* strings seen) | 2005 US 6-port MT, unsupported by tools |
| — | N3ZHEC | EU 6-port 2004 (with per-table addresses below) |

Note: our `60E15120_N3J1E.bin` contains `N3ZHE` at 0x6c046 (documented discrepancy — do not "fix").

### 3. Reading/writing the ECU (bench + protocol facts)

- **Watchdog (BOOT mode):** CN400 **pin 3 (WDT)** must receive a ~150 Hz, 50% DC,
  5 V square wave, otherwise the MCU keeps commanding reset. One poster proposed a
  variant pinout (pin 3 WDT / **pin 6 FWE** / **pin 8 MD1**) — conflicting; treat as
  `candidate_` and verify against `Sh7055h.pdf` + board before wiring anything.
  See §8 below for why the watchdog matters to us beyond bench work.

- **CAN flash via J2534/Tactrix** with Rx8Man; size-check only, wrong ROM can brick —
  bench ECU first (matches our safety rules).
- **BOOT mode** (recovery) via the 13-pin **CN400** header on the back of the ECU:
  - Pin 3 WDT: ~150 Hz 50% DC square wave (else MCU self-resets)
  - Pin 5 FWE: 5 V via 1k–10k pull-up
  - Pin 7 MD1: GND via 1k–10k pull-down (other mode pins already correct)
  - Pin 8/9: TX/RX to USB-serial (1k inline)
  - Tool: Renesas Flash Development Toolkit, device "7055" flash kernel.
  - **BOOT mode erases flash before any read** (anti-dump) → recovery-only; never for dumps.
- **UDS over OBD-II** (for dumping without BOOT): 0x10 diagnostic session → 0x27
  security access (seed/key) → **0x23 ReadMemoryByAddress** to dump memory;
  upload via 0x34 RequestDownload / 0x36 TransferData / 0x37 exit (0x35 mentioned too).
  Security keys: default `MazdA` + mazdaEdit key are hard-coded in Rx8Man;
  VersaTuner key is license-hashed (one poster cracked one license — not shared publicly).
- **Mode 9 / 0x09 CVN** (Calibration Verification Number): claimed to be a hash
  (possibly CRC16) over the whole binary, computed **incrementally in sections**
  between interrupts. Emissions testers check it.

### 4. Checksum status (conflicting forum claims — open question for us)

- "The module doesn't REALLY use checksums; RX8Man fixes them up" vs. CVN-hash claims;
  an older thread's bit patterns were not found in the stock ROMs.
- **Actionable:** locate the checksum/CVN routine in our disassembly
  (`reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm`) and settle it.

### 5. Concrete addresses from the launch-control patcher (ROM 60E0FC00)

- Engine speed RAM: `0xffffb594`; vehicle-moving RAM: `0xffffbbec` (RAM usage varies per ROM).
- Rev limit function `0xeefe`, rev-limit cal `0x6da4c`, RPM signal pointer `0xef5a`,
  fuel-cut function pointer (listed in patcher output).
- DTC display chars: 140-word (2-byte) array in RAM.
- **Cross-check done 2026-10-31 against `submodules/.../Stock_ROMs/60E0FC00.bin`:**
  bytes at `0xef5a` contain `b594` (low half of `0xffffb594`) — consistent;
  `0x6da4c`/`0xeefe` hold plausible cal/code bytes; `0x2000` = `"60E0FC00"` firmware ID — matches our convention.

### 6. Engine-load semantics (relevant to fueling/load investigations)

- Control load = **MAF (g/s) × rpm / 60 → g/rev**, clipped at 5.0 (software safety).
- Per-rotor-charge scaling **× 0.6345** → g/combustion-event, used by every load-axis
  map and the torque model.
- OBD **% load** is separate (freeze frame / monitors). Mode 22 **PID 0x43** reports
  g/rev (returns 0 when injectors off); some Mode 22 PIDs return two values per request.
- Logger-def scalings were taken from the Mode 22 transmit functions (fixed-point
  conversions), not invented.

### 7. Inline RomRaider XML in the thread

~95 `<table … storageaddress="0x…">` entries posted inline (e.g. radiator-fan tables
`0x7793c`–`0x7798c`, lambda limits `0x7016c`/`0x70170`, CL fuel-correction tables
`0x70b9c`… for N3ZHEC and others). Use as a **cross-check source** against
`data/definitions/`; do not copy wholesale.

### 8. Watchdog — relevant to us in three ways

1. **Bench BOOT-mode flashing (ROADMAP Phase 6):** external ~150 Hz square wave on
   CN400 pin 3 is mandatory or the MCU self-resets (thread §3).
2. **Normal operation — the firmware services the SH7055 internal WDT.** Already
   labeled in our export (`reverse-engineered/decompiled/60E15120_N3J1E/`):
   - `0x31c service_wdt_overflow_and_toggle_pb15` — on TCSR status bit `0x80`
     (overflow), writes keyed value `0xa53c` to TCSR (SH WDT write key `0xA5`),
     then toggles **PBDR bit 15** — an external-watchdog heartbeat idiom
     (`behavior_verified_role_candidate`; external chip/pin routing unverified).
   - `0x572` / `0x1364 ref_resetWatchdog_`, `0x5b0 ref_checkWatchdogTimer_OVRCOUNT`,
     `0x11cc service_wdt_overflow_toggle_pb15_and_count`,
     `0x5024` / `0x5032 ref_writeWatchdog_disable_`.
   - Registers (symbols.tsv): **WDT_TCSR `0xffffec10`, WDT_TCNT `0xffffec11`,
     WDT_RSTCSR `0xffffec12`** — matches the SH7055F manual (`Sh7055h.pdf`).
3. **Emulator (ROADMAP Phase 1):** the simulation must model the WDT — TCSR overflow
   bit, TCNT counting, reset via the WDT vector if not serviced in time; and log the
   **PB15 heartbeat toggles** as a trace observable ("firmware alive" signal) for
   golden-trace validation.

## Actionable items this feeds

- ROADMAP Phase 2: find the incremental checksum/CVN routine (item 4); map UDS
  service handlers (0x10/0x23/0x27/0x34/0x36) — relate to our dispatch table at 0x5f10c.
- New utility potential: Python UDS dump/flash reference implementation (0x23/0x34/0x36/0x37).
- Cross-ROM RAM map: engine-speed/vehicle-moving addresses differ per ROM — extend
  `data/labels/` per ROM.
- Verify load-calc claims (item 6) against our fueling report
  (`docs/investigations/60E15120_N3J1E/fueling_control_report.md`).
