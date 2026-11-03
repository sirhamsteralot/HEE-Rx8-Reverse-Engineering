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
  frames (ROM frame-type dispatch 0x6842c: SF/FF/CF/FC → 0x68548/0x6859e/0x6872c/0x68764).
  UDS (ISO 14229) services the firmware implements, all mapped in the service dispatch
  table at **0x5eb40** (29 × 12-byte records, router 0x68dac): 0x10 session, 0x11 reset,
  0x14 clear DTC, 0x21/0x22 read data, 0x23 ReadMemoryByAddress (full-RAM/ROM dumps),
  0x27 security access (seed/key — bootloader magic; see thread §10), 0x28/0x2f/0x31/0x85,
  0x34/0x36/0x37 download, 0x3e tester present, OBD modes 0x01–0x09 (0x09 Mode 9 = CVN —
  incremental hash, open question D3). Mode 22 PIDs dispatch through the **99-record,
  12-byte table at 0x5f10c–0x5f5af** (router 0x5774c; e.g. PID 0x43 = engine load g/rev
  × 1/255, handler 0x56b8a `diag22_pid0043_engine_load_g_rev`; cross-ROM: 0x5fa0c-area
  in 60E0FC00). Full labeling:
  [`docs/investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md`](../investigations/60E15120_N3J1E/uds_mode22_dispatch_report.md),
  `data/labels/60E15120_N3J1E/diagnostic_dispatch_named.tsv` + `uds_service_dispatch.tsv`.
- Firmware side: CAN RX → interrupt vector → `ref_resetOBDCAN_`/CAN handlers →
  UDS entry 0x680a0 → service router 0x68dac → service handler (0x22 → 0x567e8 → PID
  dispatch 0x5774c → PID handlers). The
  emulator does not reimplement UDS — it runs the ROM's own handlers; we only move
  bytes.

## Components (under `utilities/scripts/emu/`)

1. **`can.py`** — RCAN (HCAN0) mailbox model at 0xffffe400 per `symbols.tsv`:
   TX/RX mailboxes 0-15 (MC at +0x20, MD at +0xb0), W1C pending regs
   (RXPR/RFPR/TXACK/ABACK/UMSR/IRR), MCR bit0 ↔ GSR bit3 reset handshake,
   mailbox bitmask `1 << ((mb+8)&0xf)` (ROM table 0xd914), standard ID stored in
   MC[4..5] low-byte-first, DLC in MC[0]. `inject(can_id, data)` loads the matching
   RX mailbox and sets RXPR/IRR like hardware; a TXPR write transmits the mailbox
   payload into `tx_log` (the "on the bus" observable) and sets TXACK. Config:
   `diag_req`/`diag_resp` (0x7E0/0x7E8), `rx_irq_bit`.
2. **`isotp.py`** — ISO-TP reassembly/segmentation (unit-tested).
3. **`obd_port.py`** — virtual OBD-II port: TCP server (localhost, configurable
   port) speaking ISO-TP, so an unmodified client connects as if to a car.
   Requests → CAN RX into mailbox 14 (0x7E0); then the ROM's own entry points run
   (profile `uds` section): CAN RX poll `FUN_00011d88` moves the frame into the
   UDS RX buffer 0xffffddc8, UDS entry `FUN_000680a0(0x7e0)` schedules the service,
   dispatcher `FUN_00003c2a` runs tasks; 0x7E8 responses are collected from
   `tx_log` and sent back over ISO-TP. Caveat: the OS tick timer is not yet
   modeled (ROADMAP E6), so instead of waiting for the scheduler the port calls
   those entry functions directly — the mailbox/UDS code executed is the ROM's own.
4. **Profile config** — `peripherals` entry `type: "can"` plus a top-level `uds`
   section with the ROM-specific entry points (labeled for 60E15120_N3J1E in
   `profiles/60E15120_N3J1E.json`; label the equivalents per ROM before using the
   port with another bin).
5. **Logging** — every UDS request/response pair is in `OBDPort.uds_log`
   (cycle, direction, payload hex).

Verified by `tests/test_phase1_dynamic.py::test_rcan_rx_tx_through_rom_driver`,
`test_mode22_dispatch_pid_0043` and `test_phase1.py::test_obd_port_uds_log`: inject
`02 10 03` on 0x7E0 → RXPR 0x40 → poller fills 0xffffddc8 and clears RXPR;
`ref_txCAN_EventBased(0x99b0, desc 0x4e00c)` transmits `06 50 03 …` on 0x7E8 into
tx_log; Mode 22 identifier 0x0043 dispatches to handler 0x56b8a (PID 0x43).
Additionally covered by `test_mode22_dispatch_table_payloads` (exact
response bytes for 8 PIDs), `test_mode22_dispatch_full_sweep` (all 99 PIDs: r0 ==
rlen+3, NRC 0x31 mask rejection) and `test_uds_service_router_routes` (15 services
routed through 0x68dac).

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
