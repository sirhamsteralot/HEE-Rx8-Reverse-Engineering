# Design: emulated OBD-II / UDS path ("as if it was in a real car")

Goal (ROADMAP Phase 1): the emulator exposes the same diagnostic interface a real
RX-8 PCM exposes on the OBD-II port, so standard tooling — RomRaider Logger, an
ELM327/J2534-style Python client, Rx8Man-class tools — can connect to the
*emulated* ECU unchanged and pull the same data it would pull from a car. This
gives us golden-log validation (emulator vs. real-car captures) and a safe bench
for the "fast RAM logging" patch.

## Physical path being modeled

- PCM CAN pins: **4S = CAN_L (G/B), 4V = CAN_H (L/W)** (pinout doc), twisted pair to
  cluster/ABS/EPS/keyless/TPMS/DLC.
- Diagnostic addressing (configurable in the profile): request **0x7E0**, response
  **0x7E8** (PCM), functional 0x7DF; bus speed configurable (typ. 500 kbit/s) —
  confirm against captures before hard-coding.
- Transport: **ISO-TP (ISO 15765-2)** over CAN — single frame + first/consecutive
  frames. UDS (ISO 14229) services the firmware implements (from the RX8Club
  thread + our dispatch analysis): 0x10 session, 0x22 ReadDataByPID (Mode 22 PIDs;
  PID 0x43 = engine load g/rev × 1/255, handler 0x56b8a in 60E15120, dispatch at
  0x5fa0c-area in 60E0FC00), 0x23 ReadMemoryByAddress (full-RAM/ROM dumps),
  0x27 security access (seed/key — bootloader magic; see thread §10), 0x34/0x36/0x37
  download, 0x09 Mode 9 (CVN — incremental hash, open question), 0x21/0x40 PID
  support lists.
- Firmware side: CAN RX → interrupt vector → `ref_resetOBDCAN_`/CAN handlers →
  UDS service dispatch (the 99-record, 12-byte dispatch table at **0x5f10c–0x5f5af**,
  `data/labels/60E15120_N3J1E/diagnostic_dispatch.tsv`) → PID handlers. The
  emulator does not reimplement UDS — it runs the ROM's own handlers; we only move
  bytes.

## Components (to implement under `utilities/scripts/emu/`)

1. **`can.py`** (upgrade the `can` peripheral stub): real CAN controller model —
   TX/RX mailboxes, ID filtering (config: `diag_req`/`diag_resp`/`functional`),
   RX full → raise the CAN RX interrupt vector (from profile/`Sh7055h.pdf` IVT);
   TX frames captured to a log (this is the "on the bus" observable).
2. **`isotp.py`**: ISO-TP reassembly/segmentation on top of CAN frames.
3. **`obd_port.py`**: virtual OBD-II port — a TCP server (localhost, configurable
   port) that speaks ISO-TP, so an unmodified client (RomRaider Logger, python
   `udsoncan`/`python-uds`, ELM327-style AT-over-ISO-TP adapter) connects as if to
   a car. Each client request → CAN RX frame(s) into the emulated PCM → firmware
   responds on 0x7E8 → CAN TX → ISO-TP → client. Optionally a PTY for
   serial-style tools.
4. **Profile config** (`peripherals` entry `type: "can"`): `{"baud": 500000,
   "diag_req": 2016, "diag_resp": 2024, "functional": 2015, "rx_vector": null}`
   (0x7E0/0x7E8/0x7DF decimal; rx_vector per Sh7055h.pdf — fill in).
5. **Logging**: every UDS request/response pair logged (service, DID/PID, payload,
   cycle) to `tests/fixtures/obd/` for golden comparison.

## Validation ("as if in a real car")

- Golden logs: real-car captures (e.g. the thread's `Data log - 2021-09-15 … .csv`
  attachment in `input/`) replayed as requests; emulator responses must match the
  real PCM's logged values for the same inputs.
- Same seed → same PID responses: script sensor inputs (profile `sensors:`), query
  Mode 22 PIDs, compare against `docs/investigations/60E15120_N3J1E/` reports (e.g.
  PID 0x43 = 0 when injectors off, else g/rev × 1/255).
- Dump parity: UDS 0x23 full dump of the emulated ROM/RAM must equal the loaded
  image (byte-for-byte) — catches bus/addressing bugs.
- RomRaider Logger can connect to the virtual port and log live from the emulator;
  compare its CSV against a real-car CSV for the same scripted drive cycle.

## Safety

The virtual port is read-oriented (0x22/0x23/0x09/0x21). Write services (0x2E/0x34/
0x36) stay disabled unless explicitly enabled per run — emulated flash writes are
out of scope until Phase 6 bench gating. No path from the emulator to real
hardware.
