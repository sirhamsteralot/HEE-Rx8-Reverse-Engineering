#!/usr/bin/env python3
"""Virtual OBD-II port: a localhost TCP server speaking ISO-TP, bridging to the
emulated PCM's CAN bus — so RomRaider Logger / a Python UDS client / an
ELM327-style adapter can talk to the emulated ECU as if it was in a real car.

Design: docs/architecture/emulated-obd.md. The ROM runs its own CAN/UDS code;
this port only moves bytes through the modeled RCAN mailboxes (can.py):
- request: inject() into the 0x7e0 RX mailbox (RXPR/IRR set like hardware),
  then drive the ROM's own entry points from the profile's "uds" section
  (CAN RX poll -> UDS service entry -> task dispatcher) and collect the
  firmware's 0x7e8 responses from the CAN tx_log.
  Note: the OS tick timer is not yet modeled (ROADMAP E6), so instead of
  waiting for the scheduler we call the same entry functions the periodic
  task would call; the mailbox/UDS code executed is the ROM's own.

Usage (standalone):
    python obd_port.py --profile 60E15120_N3J1E --port 35000
Then connect a UDS client to localhost:35000 (ISO-TP), e.g.
    10 03            (extended diagnostic session)
    22 00 43         (Mode 22 identifier 0x0043 -> engine load, handler 0x56b8a)
"""
import argparse
import os
import socketserver
import sys
import threading

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import emu  # noqa: E402
import harness  # noqa: E402
import isotp  # noqa: E402
from can import CANController  # noqa: E402


def _num(v):
    return int(str(v), 0) if isinstance(v, str) else int(v)


class OBDPort:
    def __init__(self, prof, bus, cpu, host="127.0.0.1", port=35000, step_budget=20000):
        self.prof = prof
        self.bus = bus
        self.cpu = cpu
        self.host = host
        self.port = port
        self.step_budget = step_budget
        self.can = next((p for _, _, p in bus.peripherals if isinstance(p, CANController)), None)
        self.uds = {k: _num(v) for k, v in prof.get("uds", {}).items() if not k.startswith("_")}
        self.uds_log = []  # (cycle, direction, payload hex)
        self._srv = None
        self._thread = None

    def pump_uds(self):
        """Drive the ROM's CAN RX poll + UDS entry + task dispatcher once.
        Returns list of response payloads (bytes) the firmware transmitted."""
        uds = self.uds
        if not uds or self.can is None:
            return []
        if self.can.rx_frames:
            harness.call(self.bus, self.cpu, uds["can_rx_poll"], max_steps=300000)
        harness.call(self.bus, self.cpu, uds["uds_entry"], r_args=(uds["req_id"],), max_steps=300000)
        for _ in range(8):
            harness.call(self.bus, self.cpu, uds["task_dispatch"], r_args=(0xFFFF7638,),
                         max_steps=300000, stop_at=(uds.get("idle_pc", 0x3DAC),))
            if any(cid == uds.get("resp_id", 0x7E8) for _, cid, _ in self.can.tx_log):
                break
        resp = [d for _, cid, d in self.can.tx_log if cid == uds.get("resp_id", 0x7E8)]
        self.can.tx_log.clear()
        # reassemble ISO-TP frames into payloads
        out = []
        reasm = isotp.Reassembler()
        for d in resp:
            p = reasm.feed(d)
            if p:
                out.append(p)
        return out

    def handle_uds(self, payload):
        """One UDS request from the client -> CAN frames into the PCM -> response."""
        self.uds_log.append((self.bus.cycle, "req", payload.hex()))
        if self.can is None:
            return []
        for can_id, data in isotp.encode(payload, self.uds.get("req_id", 0x7E0)):
            self.can.inject(can_id, data)
        responses = self.pump_uds()
        for r in responses:
            self.uds_log.append((self.bus.cycle, "tx", r.hex()))
        return responses

    def start(self):
        outer = self

        class Handler(socketserver.StreamRequestHandler):
            def handle(self):
                reasm = isotp.Reassembler()
                while True:
                    chunk = self.rfile.read(4096)
                    if not chunk:
                        break
                    for i in range(0, len(chunk) - 7, 8):
                        payload = reasm.feed(chunk[i:i + 8])
                        if payload:
                            for resp in outer.handle_uds(payload):
                                for fid, fdata in isotp.encode(resp, outer.uds.get("resp_id", 0x7E8)):
                                    self.wfile.write(fdata + b"\x00")

        self._srv = socketserver.TCPServer((self.host, self.port), Handler)
        self._srv.allow_reuse_address = True
        self._thread = threading.Thread(target=self._srv.serve_forever, daemon=True)
        self._thread.start()
        return self._srv.server_address[1]

    def stop(self):
        if self._srv:
            self._srv.shutdown()


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--profile", required=True)
    ap.add_argument("--cycles", type=int, default=1000000)
    ap.add_argument("--port", type=int, default=35000)
    args = ap.parse_args(argv)
    path = args.profile if os.path.isfile(args.profile) else os.path.join(emu.PROFILES_DIR, args.profile + ".json")
    prof, bus, cpu = emu.build(path)
    port = OBDPort(prof, bus, cpu, port=args.port)
    actual = port.start()
    print(f"virtual OBD-II port on 127.0.0.1:{actual} (ISO-TP/UDS); running {args.cycles} cycles")
    emu.run(prof, bus, cpu, args.cycles)
    port.stop()


if __name__ == "__main__":
    main()
