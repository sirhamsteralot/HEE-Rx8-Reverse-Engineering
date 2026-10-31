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
  hardware path the firmware actually reads — ADC result registers (e.g.
  0xfffff80c AN6), port input registers, or (for derived signals like RPM) the RAM
  location / timer input the firmware uses. The UI writes raw values there via the
  bus, so the ROM's own sensor-reading code produces the derived values (load,
  g/rev, etc.) — we never fake firmware state directly.
  - Profile addition: `sensors: { "coolant_temp_raw": {"via": "adc", "channel": "AN0", "scale": ...}, "rpm_raw": {"via": "atu", "channel": "..."}, ... }`
  - Mapping table per profile filled from the disassembly labels (`data/labels/`),
    e.g. engine speed RAM 0xffffb594 (60E0FC00) etc.
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

## Limits

Stdlib-only, single-user, localhost — this is a dev tool, not a product. No auth
needed on localhost; do not expose the port.
