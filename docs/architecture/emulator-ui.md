# Design: emulator UI for live inputs (RPM, load, sensors, drive cycles)

ROADMAP Phase 1 extension. Goal: drive the emulated PCM interactively — set RPM,
load, MAF, coolant/IAT temps, throttle, O2/λ, knock, battery voltage etc. from a
browser, run/step the emulator, and watch outputs — plus replay real-car logs from
`data/logs/` as scripted input drives and compare against what the real car logged.

## Why a web UI

- Cross-platform (Windows dev machine included), zero dependencies: Python stdlib
  `http.server` + a static HTML/JS page, no framework.
- Same port family as the virtual OBD port (`docs/architecture/emulated-obd.md`),
  so one `emu.py --ui` serves both the UI and (later) the OBD TCP endpoint.

## Architecture

- `utilities/scripts/emu/ui.py` — UI server (stdlib only):
  - Serves `ui.html` (sliders/numeric inputs per sensor, run/step/reset buttons,
    cycle counter, PC, heartbeat count, MMIO write list, mini trace plot).
  - JSON API: `GET /api/state`, `POST /api/sensors` (set raw sensor values),
    `POST /api/run {cycles}`, `POST /api/step`, `POST /api/reset`,
    `GET /api/trace?last=N`, `POST /api/replay {log.csv, speed}`.
  - Runs the emulator on a background thread with a pause lock; sensor writes are
    applied atomically between instructions.
- **Sensor injection path:** the profile's `sensors` map names each input to the
  hardware path the firmware actually reads — ADC result registers (ADDRnH/L,
  e.g. 0xfffff806 AN3 = MAF, 0xfffff80c AN6 = APV, 0xfffff814 AN10 = knock,
  0xfffff848 AN28 = ECT, 0xfffff84a AN29 = IAT, 0xfffff808/0xa AN4/AN5 = TP) or
  the ATU-II crank input capture (ICR0AH/ICR10AH, for RPM). The UI writes raw
  values through the bus peripherals, so the ROM's own sensor-reading code
  produces the derived values (load, g/rev, etc.) — we never fake firmware state
  directly.
  - Profile form (E2): `sensors: { "maf": {"via": "adc",
    "channel": "AN3", "scale": 1000, ...}, "rpm": {"via": "atu2", ...}, ... }`
    (`via: "override"` is the legacy placeholder path).
  - Channel map per profile from the disassembly labels (`data/labels/`,
    `reviews/`); rpm channel = ATU-II input capture read by 0x77f0/0xcf96.
- **Drive-cycle replay:** `POST /api/replay` loads a `data/logs/*.csv`, maps its
  columns to sensor inputs (column-name → sensor map in the profile), and feeds
  values at the logged timestamps scaled by a speed factor; outputs (via OBD PIDs
  or MMIO log) are recorded to compare against the same columns of the original
  log — closing the "as if in a real car" loop.
- **Outputs view:** live MMIO log (GPIO actuator writes, ATU-II injector pulses),
  WDT heartbeats, plus OBD PID queries through the virtual OBD port.

## Done when

- `python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E --ui` opens the UI;
  set RPM + load + temps, press run — the emulated firmware reacts (heartbeat
  toggles, injector pulse writes appear) and Mode 22 PIDs via the OBD port reflect
  the inputs (PID 0x43 tracks load).
- Replay of a `data/logs/` CSV reproduces the logged PID values within tolerance;
  divergences recorded as investigation items.
- Cross-check: same inputs stepped in the Renesas Simulator Debugger (Windows)
  produce the same register/MMIO state (`compare_traces.py` for PC traces).

## Using it

1. `python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E` → open
   http://127.0.0.1:8080/.
2. **Sensors** panel: set RPM/MAF/temps/throttle/knock/APV, press *apply* — values
   go to the profile's `sensors` paths, now wired to the real hardware read paths
   (E2): `via: "adc"` writes the ADDRn channel the firmware's
   ADC sweep (0x6884) reads; `via: "atu2"` (rpm) drives the crank input capture
   into ICR0AH/ICR10AH.
3. **Watched emulated outputs** panel shows the profile `watch` list — e.g. the
   firmware-computed engine load at RAM 0xffffc0b4 (float32, per the fueling
   labels) and the PB15 heartbeat count — updating live as you run.
4. **Replay:** enter a `data/logs/rx8-666p/*.csv` path, press *load*, then
   *step replay* (or repeatedly): each row's columns are mapped via the profile
   `replay_map` (e.g. `Engine RPM(rpm)` → `rpm`), applied as sensor inputs, and the
   emulator runs `cycles_per_row` instructions. Progress shows as `replay row/of`
   in the header; heartbeats advancing = firmware alive and reacting.
   Verified: replaying `trackLog-2026-Oct-04_09-31-12.csv` drives rpm≈2237,
   load≈42% into the emulated ECU per row.
   Note: the watched engine-load/rpm RAM cells update only when the firmware's
   engine tasks run, which needs the OS tick timer (ROADMAP E6, still open) —
   the sensor *inputs* are on the real hardware paths (E2), but task scheduling
   is not yet autonomous in the emulator.

## Limits

Stdlib-only, single-user, localhost — this is a dev tool, not a product. No auth
needed on localhost; do not expose the port.
