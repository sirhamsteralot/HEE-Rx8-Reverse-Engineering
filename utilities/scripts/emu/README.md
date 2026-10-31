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
- `can.py` — CAN controller: RX injection + TX capture (`inject`, `tx_log`).
- `isotp.py` — ISO-TP encode/reassemble (unit-tested).
- `obd_port.py` — virtual OBD-II/UDS TCP port (design: `docs/architecture/emulated-obd.md`).
- `ui.py` + `ui.html` — interactive UI (design: `docs/architecture/emulator-ui.md`):
  `python ui.py --profile 60E15120_N3J1E` → http://127.0.0.1:8080/ — sensor inputs,
  run/step/reset, MMIO + heartbeat views, drive-cycle replay from `data/logs/`.
- `profiles/` — one JSON per ROM/market/model (see `profiles/README.md`).

## Running

```sh
python utilities/scripts/emu/emu.py --list-profiles
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 100000 --trace /tmp/boot.trace
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --ui   # planned: browser UI for sensor inputs + drive-cycle replay (design: docs/architecture/emulator-ui.md)
```

Planned additions (ROADMAP Phase 1): virtual OBD-II/UDS port
(`docs/architecture/emulated-obd.md`) and the interactive UI
(`docs/architecture/emulator-ui.md`).

## Tests

`python -m pytest tests/test_emu.py` — profile/ROM-hash validation, bus routing,
hand-assembled CPU program, WDT overflow/service, PB15 heartbeat logging, and a
boot smoke test on the real ROM.

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

## Limits (honest)

- CPU implements only the observed opcode subset; boot stops at the first
  unimplemented instruction (reported, not mis-executed).
- Host float math does not model SH-2E FPU rounding/exception modes.
- Peripheral register bases marked `_note` need refinement from `Sh7055h.pdf`.
