#!/usr/bin/env python3
"""Virtual OBD-II port: a localhost TCP server speaking ISO-TP, bridging to the
emulated PCM's CAN bus — so RomRaider Logger / a Python UDS client / an
ELM327-style adapter can talk to the emulated ECU as if it was in a real car.

Design: docs/architecture/emulated-obd.md. The ROM runs its own UDS handlers
(dispatch table 0x5f10c); this port only moves bytes.

Usage (inside emu.py --ui or standalone):
    python obd_port.py --profile 60E15120_N3J1E --port 35000
Then: connect a UDS client to localhost:35000 (ISO-TP), send e.g.
    10 03            (extended diagnostic session)
    22 22 43         (Mode 22 PID 0x43 -> engine load)
"""
import argparse
import os
import socket
import socketserver
import sys
import threading

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import emu  # noqa: E402
import isotp  # noqa: E402
from can import CANController  # noqa: E402


class OBDPort:
    def __init__(self, prof, bus, cpu, host="127.0.0.1", port=35000, step_budget=20000):
        self.prof = prof
        self.bus = bus
        self.cpu = cpu
        self.host = host
        self.port = port
        self.step_budget = step_budget  # cycles run per UDS request
        self.can = next((p for _, _, p in bus.peripherals if isinstance(p, CANController)), None)
        self.uds_log = []  # (cycle, direction, payload hex)
        self._srv = None
        self._thread = None

    def handle_uds(self, payload):
        """One UDS request from the client -> CAN frames into the PCM."""
        self.uds_log.append((self.bus.cycle, "req", payload.hex()))
        for can_id, data in isotp.encode(payload, self.can.diag_req):
            self.can.inject(can_id, data)

    def start(self):
        outer = self

        class Handler(socketserver.StreamRequestHandler):
            def handle(self):
                reasm = isotp.Reassembler()
                while True:
                    chunk = self.rfile.read(4096)
                    if not chunk:
                        break
                    # client sends raw ISO-TP frames back-to-back; split per CAN frame (8 bytes)
                    for i in range(0, len(chunk) - 7, 8):
                        payload = reasm.feed(chunk[i:i + 8])
                        if payload:
                            outer.handle_uds(payload)
                            # let the firmware chew on the request, then return any response frames
                            emu.run(outer.prof, outer.bus, outer.cpu, outer.step_budget)
                            resp = [d for _, cid, d in outer.can.tx_log if cid == outer.can.diag_resp]
                            outer.can.tx_log.clear()
                            if resp:
                                reasm_r = isotp.Reassembler()
                                # reassemble multi-frame responses into one payload
                                payload_out = b"".join(d[1:] for d in resp)  # simplified: single-frame path
                                for fid, fdata in isotp.encode(payload_out, outer.can.diag_resp):
                                    self.wfile.write(fdata + b"\x00")
                            outer.uds_log.append((outer.bus.cycle, "tx", b"".join(resp).hex()))

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
