# patch_intake_rpm_window.py — RX-8 S1 PCM intake-valve RPM-window patcher

Patches a stock PCM ROM so the **VDI** (default) or **SSV** solenoid is energised
only inside an RPM window, e.g. VDI open at 7000 rpm and closed again above
8500 rpm:

```sh
python3 Utilities/patch_intake_rpm_window.py Stock_ROMs/60E15120_N3J1E.bin \
    --actuator vdi --open-rpm 7000 --close-rpm 8500 --out patched/
# or every stock ROM at once:
python3 Utilities/patch_intake_rpm_window.py Stock_ROMs/ --actuator vdi
# SSV instead:
python3 Utilities/patch_intake_rpm_window.py Stock_ROMs/60E15120_N3J1E.bin --actuator ssv
```

Output: `<romname>_<actuator>_<open>_<close>.bin` (new file) plus a JSON patch
report (`--report`) with input/output SHA-256, the located function offset, the
changed byte span and old/new words.

## Semantics

- New on-condition: `open_rpm <= engine_speed_rpm (0xffffb548) <= close_rpm`
  (closed when rpm > close_rpm or rpm < open_rpm; float compare, upper edge
  inclusive). Stock VDI logic was "on at rpm >= 7250 (hyst 7062), never closes";
  stock SSV was coolant/counter based.
- The UDS diagnostic actuator override is preserved (VDI: 0x5c3c0 via c1c0;
  SSV: 0x5c9ac via becd).
- VDI output: PD5 / PDDR_W 0xfffff746 bit 0x20 (SH7055F pin 254, terminal 1W).
  SSV output: PE7 / PEDR_W 0xfffff754 bit 0x80 (pin 16, terminal 1L).

## RomRaider-editable setpoints (cal table)

By default the patcher writes the open/close setpoints into the calibration
area as a proper 2-cell 2D float table, so they can be edited later with
RomRaider or any binary editor:

- descriptor at **0x7fb90**, axis at **0x7fb9c** (cells 0.0/1.0), data at
  **0x7fba4** (cell0 = open rpm, cell1 = close rpm, float32) — inside a 0xFF
  free run present in all stock ROMs (verified all-0xFF before writing; if not
  free, the patcher picks another free cal-area run and reports it).
- The patched code reads the two cells directly from the data address (pool
  word in the function holds the absolute address).
- Each run also writes `<output>.xml` with the ready-to-paste RomRaider
  definition; the table is also added to `RX8Defs_Copy/RomRaider/rx8_defs.xml`
  (base def in RX8Base + `storageaddress="0x07FBA4"` in the 60E15120 rom block),
  so RomRaider shows "VDI RPM Window (open/close)" under category
  "Intake Valves". The descriptor was verified to be found by the same
  data-pointer scan used for the project's 478 def matches
  (`scripts/correlate_rx8defs.py` logic: `>HBBII`, n=2, type 0 = float32).
- Edit later: RomRaider table view, or any hex editor at 0x07FBA4 (float32
  cell0=open, 0x07FBA8 cell1=close). No re-patching needed.
- `--cal-base 0xADDR` overrides the descriptor address; `--pool-floats`... (removed:
  cal table is the default and only mode in this version).

## Safety / evidence rules (workspace AGENTS.md)

- Stock `.bin` files are **never modified**: the patcher reads the input
  read-only, asserts its SHA-256 is unchanged afterwards, writes only a new
  output file, and asserts the output differs from the input only inside the
  located function's patched span.
- The target function is found by an exact byte match of its body in the
  reference ROM 60E15120_N3J1E (all 10 stock ROMs contain it; ROM-internal pool
  pointers are relocated by the found delta). A ROM without a unique match is
  skipped with `SKIP`.
- Only words inside the function's logic region + its own literal pool are
  changed; prologue and the GPIO-write tail are kept byte-identical.
- Instruction encodings (SH-2E BE) were verified against
  `reverse_engineered/60E15120_N3J1E/decompiled/firmware_disassembly.asm`
  (mov.l/mov.w/mova PC-relative EA math, fmov.s, fcmp/gt, bt/s, bra, mov #imm).
  The patched region was decode-verified word-by-word on the reference ROM.
- Flash the result with the project's reflash tool (`Rx8Man/`). **Not tested on
  hardware** — validation here is static only (byte-level + decode). Behavior
  on a real PCM is unverified.
