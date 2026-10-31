# Using the SH-2E emulator + real-car datalogs for reverse-engineering work

Guide for agents (and humans) who want to **test firmware behavior in the
simulator against existing datalogs** — i.e. feed a real car's logged inputs into
the emulated PCM, run it, and compare the emulated outputs (RAM watchpoints,
MMIO writes, UDS responses) against what the real car logged. Everything here
runs offline; no hardware is touched.

Status 2026-10-31: implemented and tested (38/38 in `python -m pytest tests/`).
Companion docs: [`emulator-ui.md`](emulator-ui.md) (browser UI), [`emulated-obd.md`](emulated-obd.md) (virtual OBD
port), `utilities/scripts/emu/README.md` (core), ROADMAP.md (limits E1–E7).

## 1. Where things live

| Piece | Path |
|---|---|
| Emulator core (CPU/bus/peripherals) | `utilities/scripts/emu/` (`emu.py`, `sh2e.py`, `bus.py`, `peripherals.py`, `can.py`, `isotp.py`, `obd_port.py`, `debugger.py`, `debug.py`, `ui.py`, `harness.py`) |
| Per-ROM profiles (ROM hash + memory map + peripherals + sensors + replay_map + watch + uds) | `utilities/scripts/emu/profiles/*.json` |
| Real-car datalogs (golden inputs) | `data/logs/rx8-666p/*.csv` (OBD PIDs: RPM, load %, ECT, IAT, MAF g/s, AFR, throttle %, timing), `data/logs/nr666p/*.csv` (VersaTuner: absolute load, λ, ECT, RPM, leading/trailing timing advance, IAT, **knock retard**, LTFT/STFT) |
| Static evidence to validate | `reverse-engineered/decompiled/<rom-id>/`, `data/labels/<rom-id>/`, `docs/investigations/<rom-id>/` (10-section reports incl. §1a) |
| Golden emulator outputs | `tests/fixtures/` (boot trace; add `obd/` for UDS golden logs) |
| Findings go to | `docs/investigations/<rom-id>/` (report + evidence; never edit `binaries/` or `submodules/`) |

Primary ROM: `60E15120_N3J1E` (profile `60E15120_N3J1E`). Other profiles exist
(60E0FC00, 60E0G500 + streetport variants, 60E1B900). Note: 60E1B900 uses an
opcode outside the 60E15120 corpus (stops at 0x957a @ 0x10ae) — regenerate
`opdec.py` from that ROM's disassembly first (`gen_opdec.py`, see
`profiles/README.md` step 5).

## 2. Quick start (command line)

```sh
cd <repo root>
python utilities/scripts/emu/emu.py --list-profiles
python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --cycles 1000000 --trace /tmp/boot.trace
python utilities/scripts/emu/debug.py --profile 60E15120_N3J1E        # REPL: b/w/del/c/s/regs/m/x/state
python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E             # http://127.0.0.1:8080/
python utilities/scripts/emu/obd_port.py --profile 60E15120_N3J1E --port 35000  # ISO-TP/UDS TCP
```

Boot of `60E15120_N3J1E` passes CAN init and parks in the main idle loop
(pc = 0x3dac); the WDT is serviced by the firmware's own poll path (keyed 0xa53c
writes to TCSR 0xffffec10) and PB15 heartbeats are logged. A healthy boot prints
`cycle limit N reached`, `mmio_writes` > 200, heartbeats > 0.

One-shot agent tools (no MCP needed in-session): `python utilities/scripts/hee.py
--list` — `hee_boot`, `hee_run`, `hee_state`, `hee_regs`, `hee_mem`, `hee_disasm`,
`hee_break`/`hee_watch`/`hee_continue`/`hee_step`, `hee_set_sensor`,
`hee_replay_load`/`hee_replay_step`, `hee_labels`, `hee_disasm_rom`,
`hee_diff_roms`. Example:
`python utilities/scripts/hee.py hee_boot '{"profile": "60E15120_N3J1E", "cycles": 300000}'`

## 3. Feeding inputs (sensors + datalogs)

Sensor inputs go through the **real hardware read paths** (E2), never by poking
firmware RAM:

- `via: "adc", channel: "ANx"` → the ADC peripheral's ADDRnH/L result register
  (what the firmware's sweep `ref_sensorADCRead` 0x6884 reads). Profile channels:
  AN3=MAF, AN4/AN5=TP1/TP2, AN6=APV, AN10=knock sensor, AN28=ECT, AN29=IAT.
  Raw = `value * scale` (16-bit ADC counts).
- `via: "atu2"` (rpm) → the ATU-II crank input capture: `ATU2.set_rpm(rpm)`
  drives a virtual crank wheel whose edges land in ICR0AH (0xfffff434) /
  ICR10AH (0xfffff6d0), the registers the firmware's crank path reads.
- `via: "override"` is the legacy placeholder path — do not use for new work.

```python
# in-session (run_typescript) or via hee.py hee_set_sensor:
import sys; sys.path.insert(0, 'utilities/scripts/emu')
import emu, ui
prof, bus, cpu = emu.build('utilities/scripts/emu/profiles/60E15120_N3J1E.json')
emu.run(prof, bus, cpu, 300000)                      # boot to idle
ui.apply_sensor(bus, prof, 'rpm', 3000)              # ATU-II crank
ui.apply_sensor(bus, prof, 'maf', 42.0)              # ADC AN3
ui.apply_sensor(bus, prof, 'coolant_temp', 90)       # ADC AN28
emu.run(prof, bus, cpu, 100000)
```

**Datalog replay** (drive-cycle input): the profile's `replay_map` maps CSV
column names to sensors (`Engine RPM(rpm)`→rpm, `Mass Air Flow Rate(g/s)`→maf,
`Engine Coolant Temperature(°C)`→coolant_temp, `Intake Air Temperature(°C)`→iat,
`Relative Throttle Position(%)`→throttle). Extend it for other logs, e.g. nr666p:
`"Engine RPM": "rpm"`, `"Engine coolant temperature (°C)": "coolant_temp"`, etc.

```python
# replay a real log row by row, sampling outputs per row:
s = ui.EmuSession('utilities/scripts/emu/profiles/60E15120_N3J1E.json')
emu.run(s.prof, s.bus, s.cpu, 300000)
s.start_replay('data/logs/rx8-666p/trackLog-2026-Oct-04_09-31-12.csv', speed=1)
for _ in range(500):
    r = s.replay_step()          # applies that row's sensors, runs cycles_per_row
    print(r['row'], r['watch'])  # watch: engine_load_g_rev (RAM 0xffffc0b4), rpm RAM 0xffff9f80, heartbeats
```

or via CLI: `hee_replay_load {"profile": "60E15120_N3J1E", "csv": "data/logs/rx8-666p/trackLog-2026-Oct-04_09-31-12.csv"}`
then `hee_replay_step {"profile": ...}` per row (returns watch values). In the UI:
*Replay* panel, same CSV path. Each row runs `cycles_per_row` (2000 × speed)
instructions.

## 4. Reading outputs (what to compare against the datalog)

- **Watch RAM cells** (profile `watch`, float32): engine load g/rev
  `0xffffc0b4` (fueling labels), engine speed raw `0xffff9f80` (ISR 0x803e) and
  `0xffffb548`, knock retard `0xffffa734` (knock report), final leading/trailing
  timing `0xffffa630`/`0xffffa638`, injector requests `0xffffa010`[ch*0x18].
  Add entries to the profile `watch` list as you label more outputs.
- **MMIO log** (`bus.mmio_log`): injector pulse writes to ATU-II DCNT8A-P
  (0xfffff640-0x65e) per channel map ROM 0xd7d4, PB15 heartbeat writes
  (0xfffff738), WDT service writes (0xffffec10).
- **Virtual OBD port** (`obd_port.py`, localhost ISO-TP): send UDS requests and
  read the firmware's answers — the same interface RomRaider Logger uses on a
  car. E.g. `10 03` (extended session), `22 00 43` (Mode 22 PID 0x43 = engine
  load g/rev × 1/255, handler 0x56b8a, dispatch table 0x5f10c). The port drives
  the ROM's own entry points (profile `uds` section: CAN RX poll 0x11d88, UDS
  entry 0x680a0, dispatcher 0x3c2a) because the OS tick is not yet modeled (E6).
  Log request/response pairs to `tests/fixtures/obd/` for golden comparison.
  Since 2026-10-31 the RX side is fully autonomous: `can.inject(0x7e0, frame)`
  raises the CAN RX interrupt (IVT offset 0x378), and a plain `emu.run` runs the
  ROM's CAN RX poll (0x11d88) + scheduler (0x9630), moving the frame into the UDS
  buffer 0xffffddc8 with no manual entry-point calls (see
  `test_can_rx_interrupt_autonomous`). The response TX still goes through the
  profile `uds` entry points (E6 remainder).

## 5. Function-level dynamic tests (harness.py)

To execute one ROM function directly and check its result (the Phase 1
"dynamic reproduction" pattern — see `tests/test_phase1_dynamic.py`):

```python
import sys; sys.path.insert(0, 'utilities/scripts/emu')
import emu, harness
prof, bus, cpu = emu.build('utilities/scripts/emu/profiles/60E15120_N3J1E.json')
emu.run(prof, bus, cpu, 300000)                    # boot first (RAM/IVT set up)
# SH-2E ABI: int args r4-r7, float args fr4-fr7, return r0 / fr0
r0, fr0, steps = harness.call(bus, cpu, 0x13BD2, fr_args=(-15.0,),
                              ram={0xFFFFB548: (4, harness.bits(3000.0))})  # knock_retard_clamp
assert fr0 == -10.0                                # clamped to [-10, 0] deg
```

Worked examples already in `tests/test_phase1_dynamic.py`: math helpers
0x23b0/0x23dc/0x23e4/0x23f4/0x2404 vs the `rx8_math.c` reimplementation; knock
clamp 0x13bd2; injector map 0x8a68(ch) → DCNT8x/GR1x vs ROM 0xd7d4; ADC sweep
0x6884; RCAN RX/TX through the ROM's own driver; Mode 22 dispatch 0x5774c.
Note the dispatcher (0x3c2a) never rts — use `stop_at=(0x3DAC,)`.

## 6. Tracing, debugging, diffing

- `--trace FILE` writes `cycle pc` per instruction; diff two traces with
  `python utilities/scripts/emu/compare_traces.py a b [--max N]` (reports first
  divergence). Golden boot trace: `tests/fixtures/boot-60E15120_N3J1E-200k.trace`
  (regenerated 2026-10-31; self-check MATCH). **Renesas Simulator Debugger
  cross-check is still pending** — the licensed tool isn't installed on the
  current machine; when available, follow `utilities/scripts/emu/README.md`
  §cross-check workflow and record the result in the investigation doc.
- Debugger: breakpoints/watchpoints (read+write), single-step, regs/mem/disasm
  (`debug.py` REPL or UI `/api/debug`); the SH7055 UBC is modeled
  (`peripherals.UBC`) for hardware-style breaks.

## 7. The golden-log validation loop (emulator vs real car)

1. Pick a log (`data/logs/rx8-666p/...` or `data/logs/nr666p/...`); extend the
   profile `replay_map` for its columns (inputs only: rpm, maf, temps, throttle).
2. Add the outputs you want to check to the profile `watch` list (e.g. knock
   retard 0xffffa734, timing 0xffffa630/0xffffa638, load 0xffffc0b4).
3. Replay row by row (§3), record `(row, watch values)` per row.
4. Compare against the same row's columns in the CSV (e.g. nr666p `Knock retard
   (°)` vs watch `knock_retard_ffffa734`; `Engine Load(Absolute)(%)` vs load).
5. Record matches/divergences with addresses + cycle counts in
   `docs/investigations/<rom-id>/` (10-section report format incl. §1a); put golden emulator
   outputs under `tests/fixtures/`.

Known gap to keep in mind: the OS tick timer is modeled (CMI10B) but task
contexts still need it (E6), so at idle the engine tasks don't run autonomously —
use `harness.call` on the task/function entry points (§5) to drive specific paths
deterministically, and note this in findings.

## 8. Rules (from AGENTS.md — always apply)

- Binaries are immutable (`hash_binaries.py --check` after touching `binaries/`);
  never edit `submodules/`; `input/` stays uncommitted.
- Evidence ladder for labels (`FUN_`/`ref_`/`CAL_`/`tbl_`/`inferred_`/`candidate_`);
  tie every symbol to its ROM address; binary-level verification before claiming a
  pass; never write "verified working" beyond what a validation artifact covers.
- Sensor inputs go through hardware paths only; don't poke firmware RAM to fake
  state (harness `ram=` is for setting a callee's documented input globals, and say
  so in the test).
- Discrepancies are documented, never silently resolved (ROADMAP register).
- Emulator limits E1–E7 are in ROADMAP.md / `utilities/scripts/emu/README.md` —
  read them before claiming fidelity (host-double FPU, cycles ≠ real time, etc.).
- Pipeline validators run from the repo root (paths resolve via
  `utilities/scripts/rx8-pcm-pipeline/paths.py`): `validate_export.py`,
  `validate_reports.py`, `verify_readability.py`, `verify_math_units.py` —
  all PASS as of 2026-10-31.
