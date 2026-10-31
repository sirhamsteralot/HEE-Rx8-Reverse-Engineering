# emu/ — SH-2E emulator (ROADMAP Phase 1 — implemented 2026-10-31)

Config-driven emulator for running RX-8 PCM ROM images and validating findings
dynamically. Python 3, stdlib only. **Status: full boot of 60E15120_N3J1E runs
clean (50M+ instructions, no unknown opcodes), WDT heartbeat (PB15) live,
golden 200k-instruction PC trace reproduces byte-exact in tests.**

## Layout

- `emu.py` — CLI runner: `--profile NAME [--cycles N] [--trace FILE]`, `--list-profiles`.
- `profile.py` — profile loading + ROM SHA-256 verification (hex or decimal numbers).
- `bus.py` — ROM/RAM/IO regions, MMIO dispatch, MMIO write log, `io_read_overrides`.
- `sh2e.py` — hand-written SH-2E CPU core. Dispatch table `opdec.py` is
  **generated from the real disassembly** by `gen_opdec.py` and validated
  instruction-by-instruction (`tests/test_decode_corpus.py`, 168k instructions,
  100% coverage); unknown opcodes raise and stop the run loudly.
- `opdec.py` / `gen_opdec.py` — generated opcode→mnemonic table + generator.
- `peripherals.py` — SH7055 stubs: WDT (TCSR/TCNT/RSTCSR, keyed 0xA5 writes,
  overflow → handler/vector, PB15 heartbeat logging), GPIO, ADC (scripted
  sensors), ATU-II, SCI, generic register file.
- `can.py` - RCAN (HCAN0) mailbox model at 0xffffe400 per symbols.tsv: W1C pending
  regs (RXPR/RFPR/TXACK/ABACK/UMSR/IRR), MCR bit0 <-> GSR bit3 reset handshake,
  `inject(can_id, data)` loads the matching RX mailbox, sets RXPR/IRR **and raises
  the CAN RX interrupt** (config `rx_vector`, 0x378 - the handler that runs the
  ROM's CAN RX poll 0x11d88 + OS scheduler 0x9630), so a plain `emu.run` moves
  injected frames into the UDS buffer autonomously. A TXPR write transmits the
  mailbox payload into `tx_log` (UDS responses on 0x7e8).
- `peripherals.py` also has `SYSC` (0xffffed00: IPR/ICR/ISR; ICR bit15 = NMI pin
  level, boot polls it at 0x8ea) and GPIO `inputs` (scripted input pins, e.g.
  PFDR bit0).
- `harness.py` - direct ROM-function call harness (SH-2E ABI: r4-r7 / fr4-fr7
  args, r0/fr0 return) used by `tests/test_phase1_dynamic.py` to execute the
  ROM's own functions for dynamic validation.
- `isotp.py` - ISO-TP encode/reassemble (unit-tested).
- `obd_port.py` - virtual OBD-II/UDS TCP port (design: `docs/architecture/emulated-obd.md`):
  requests are injected into the 0x7e0 mailbox, then the ROM's own entry points
  (profile `uds` section: CAN RX poll 0x11d88, UDS entry 0x680a0, dispatcher
  0x3c2a) run and 0x7e8 responses are collected from `tx_log`.
  `python ui.py --profile 60E15120_N3J1E` → http://127.0.0.1:8080/ — sensor inputs,
  run/step/reset, MMIO + heartbeat views, drive-cycle replay from `data/logs/`,
  and a debugger panel (`/api/debug`: break/watch/continue/step/regs/mem/disasm).
- `debugger.py` + `debug.py` — debugger core + CLI:
  `python debug.py --profile 60E15120_N3J1E` → REPL with `b/w/del/c/s/regs/m/x/state`.
  Execution breakpoints, memory read/write watchpoints, single-step, register and
  memory dumps, and disassembly at PC printed from the corpus table (same mnemonics
  as the Ghidra listing). The SH7055 **UBC** (hardware break controller) is modeled
  as a peripheral (`peripherals.UBC`): program BARA/BAMRA/BRCR and PC matches raise
  a hardware break, like the original MCU.
- `profiles/` — one JSON per ROM/market/model (see `profiles/README.md`).

## Running

```sh
python utilities/scripts/emu/emu.py --list-profiles
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 100000 --trace /tmp/boot.trace
python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E        # browser UI on http://127.0.0.1:8080/
python utilities/scripts/emu/obd_port.py --profile 60E15120_N3J1E --port 35000  # virtual OBD-II/UDS (ISO-TP over TCP)
python utilities/scripts/emu/debug.py --profile 60E15120_N3J1E      # debugger REPL
```

Both the virtual OBD-II/UDS port (`docs/architecture/emulated-obd.md`) and the
interactive UI (`docs/architecture/emulator-ui.md`) are implemented (ROADMAP
Phase 1). Dynamic validation of static findings runs through `harness.py` —
see `tests/test_phase1_dynamic.py`.

## Tests

`python -m pytest tests/test_emu.py` — profile/ROM-hash validation, bus routing,
hand-assembled CPU program, WDT overflow/service, PB15 heartbeat logging, and a
boot smoke test on the real ROM. `python -m pytest tests/test_phase1_dynamic.py`
- dynamic reproduction of static findings (math helpers vs the reimplementation,
knock clamp 0x13bd2, injector map 0xd7d4 -> ATU-II 8A-8F, ADC read path, RCAN
RX/TX through the ROM's own driver, Mode 22 dispatch).

## Why not QEMU/Unicorn (checked 2026-10-31)

- **QEMU** `target/sh4` models only the SH-4 family (SH7750/7751R/7785…); there is
  no SH-2E/SH7055 CPU model and no SH7055 SoC — the ATU-II/PFC/WDT/RCAN peripherals
  would need a custom machine model anyway. SH-4 over-accepts instructions SH-2E
  lacks and has a different (banked) FPU — the same trap as Ghidra's stock SH-2A.
- **Unicorn 2** has no SuperH support at all (v1 had SH-4 only).
- **Renesas Simulator Debugger for SuperH (HEW/e² studio)** does support the SH7055
  core. It is Windows-only and GUI/license-bound, so it is **not** our CI harness —
  but on a Windows dev machine it is our **cross-check oracle** (see workflow below).
  SH-2E ISA manual:
  https://evoecu.logic.net/mirror/cpudocs/sh7055f/rej09b0316_sh_2esm.pdf (mirror;
  canonical: renesas.com SH-2E software manual) — add to references if downloaded.
- So we keep the custom core: exact observed-opcode subset, loud stop on anything
  unknown. Risk = our own bugs, mitigated by golden traces, disassembly byte
  cross-checks, `tests/test_emu.py`, and differential runs vs the Renesas
  simulator.

## Cross-check workflow with the Renesas Simulator Debugger (Windows)

Standing step whenever the emulator core (`sh2e.py`/`bus.py`/`peripherals.py`)
changes or a new opcode is implemented:

1. Here (any OS): `python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E
   --cycles N --trace /tmp/our.trace` and `python -m pytest tests/test_emu.py`.
2. On the Windows machine: open the Renesas Simulator Debugger (HEW or e² studio
   simulator, SuperH family, device **SH7055**), load the **same ROM** at 0x00000000
   (from `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/`), set the same
   starting conditions (reset vector), run **N instructions**, export the PC trace
   to `/tmp/renesas.trace` (one hex address per line).
3. Diff: `python utilities/scripts/emu/compare_traces.py /tmp/our.trace
   /tmp/renesas.trace` — must report MATCH for the compared prefix; investigate any
   divergence before claiming the opcode correct. Compare MMIO writes / PB15
   heartbeats from the `# mmio` log against the debugger's peripheral register
   views.
4. Record the result (date, N, tool version, MATCH/divergence) in the investigation
   doc for the change. A trace that only we produce is not validated.

Status 2026-10-31: the Renesas Simulator Debugger (HEW/e² studio) is **not
installed on the current Windows machine**, so no external diff has been run yet.
In the meantime `compare_traces.py /tmp/our.trace tests/fixtures/boot-60E15120_N3J1E-200k.trace`
reports MATCH (200k steps) — the golden trace was regenerated 2026-10-31 with the
corrected peripheral models and validates self-reproducibility only. Run the
Renesas diff before claiming external validation (ROADMAP Phase 1 open item).

## Limits (honest)

Full list with closure plans in **ROADMAP.md -> "Fidelity limits & known
discrepancies"** (items E1-E7). Summary (updated 2026-10-31):

- CPU implements the corpus-validated opcode subset; boot stops at the first
  unimplemented instruction (reported, not mis-executed). `interrupt()` honors
  VBR and pushes SR/PC per the SH-2E manual (6.1.3); FPU `fdiv` follows IEEE
  (x/0 = inf, 0/0 = NaN); `fmov.s` handles @rN+/@-rN/@(disp,rN)/@(r0,rN);
  `sts`/`lds` cover fpscr/fpul.
- Host float math does not model SH-2E FPU rounding/exception modes (E1).
- Peripheral bases are now from `symbols.tsv` (RCAN0 0xffffe400, RCAN1
  0xffffe600, ATU-II 0xfffff400, SCI 0xfffff000, ADC 0xfffff800, WDT 0xffffec10,
  DMAC 0xffffecb0, GPIO 0xfffff700); the ROM region is read-only (CPU stores to
  flash are ignored, counted in `bus.rom_writes_blocked`). Sensor inputs are
  wired to the real ADC ADDRn channels / ATU-II crank capture (E2 input side
  closed). Remaining: WDT IVT vector slot (E3 - the firmware polls TCSR and
  calls its service routine 0x31c itself), full RCAN fidelity beyond the diag
  path; the guessed `io_read_overrides` are gone (E5 closed - the 0xffffed18
  entry was the NMI pin level, now SYSC). Timers: ATU-II ch10B tick (CMI10B ->
  0x2c8) and the CAN RX interrupt (0x378 on inject) fire and run the scheduler /
  CAN poll autonomously; the OS task context switch (0x3db0 wake via ref_setSR on
  ISR exit) is still not triggered (E6 remainder), so UDS *response* TX is
  driven via the profile `uds` entry points. `div1`/rotcl edge cases are
  approximations and "cycles" are not cycle-accurate time (E7).
