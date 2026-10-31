# emu/ — SH-2E emulator (ROADMAP Phase 1)

Config-driven emulator for running RX-8 PCM ROM images and validating findings
dynamically. Python 3, stdlib only.

## Layout

- `emu.py` — CLI runner: `--profile NAME [--cycles N] [--trace FILE]`, `--list-profiles`.
- `profile.py` — profile loading + ROM SHA-256 verification.
- `bus.py` — ROM/RAM/IO regions, MMIO dispatch, MMIO write log.
- `sh2e.py` — hand-written SH-2E CPU core (exact subset; unknown opcodes stop the
  run loudly — see `docs/learnings.md` for the encodings). FPU subset included.
- `peripherals.py` — SH7055 stubs: WDT (TCSR/TCNT/RSTCSR, overflow → vector,
  keyed 0xA5 writes, PB15 heartbeat logging), GPIO, ADC (scripted sensors),
  ATU-II, SCI, CAN, generic register file.
- `profiles/` — one JSON per ROM/market/model (see `profiles/README.md`).

## Running

```sh
python utilities/scripts/emu/emu.py --list-profiles
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 100000 --trace /tmp/boot.trace
```

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
  core, but is Windows-only, GUI/license-bound — usable as a *cross-check oracle*
  on a dev machine, not as a scriptable CI harness. SH-2E ISA manual:
  https://evoecu.logic.net/mirror/cpudocs/sh7055f/rej09b0316_sh_2esm.pdf (mirror;
  canonical: renesas.com SH-2E software manual) — add to references if downloaded.
- So we keep the custom core: exact observed-opcode subset, loud stop on anything
  unknown. Risk = our own bugs, mitigated by golden traces, disassembly byte
  cross-checks, `tests/test_emu.py`, and optional differential runs vs the Renesas
  simulator on the common subset.

## Limits (honest)

- CPU implements only the observed opcode subset; boot stops at the first
  unimplemented instruction (reported, not mis-executed).
- Host float math does not model SH-2E FPU rounding/exception modes.
- Peripheral register bases marked `_note` need refinement from `Sh7055h.pdf`.
