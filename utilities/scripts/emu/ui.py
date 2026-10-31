#!/usr/bin/env python3
"""Interactive UI for the HEE emulator: localhost browser page to set sensor
inputs (RPM, load, MAF, temps, ...), run/step/reset the emulation, watch MMIO
writes + WDT heartbeats, and replay drive-cycle logs from data/logs/.

Design: docs/architecture/emulator-ui.md. Sensors are injected through the
hardware paths the firmware reads (ADC channels / IO read overrides per the
profile's `sensors` map) — never by poking firmware RAM.

Usage:
    python utilities/scripts/emu/ui.py --profile 60E15120_N3J1E [--port 8080]
Then open http://127.0.0.1:8080/
"""
import argparse
import csv
import json
import os
import sys
import threading
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import emu  # noqa: E402

REPO_ROOT = emu.REPO_ROOT
HERE = os.path.dirname(os.path.abspath(__file__))


def apply_sensor(bus, prof, name, value):
    """Inject one sensor value through its hardware path (profile `sensors`)."""
    s = prof.get("sensors", {}).get(name)
    if not s or not isinstance(s, dict):
        return False
    via = s.get("via")
    scale = float(s.get("scale", 1))
    raw = int(round(value * scale))
    if via == "override":
        # legacy placeholder path (E2): raw read-override register
        bus.read_overrides[int(str(s["addr"]), 0)] = raw & 0xFFFFFFFF
        s["value"] = value
    elif via == "adc":
        # real ADC read path: scripted ADDRnH/L result register (E2)
        for _, _, p in bus.peripherals:
            if type(p).__name__ == "ADC":
                p.channels[s["channel"]] = raw & 0xFFFF
                s["value"] = value
                return True
    elif via == "atu2":
        # real ATU-II read path: crank input capture ICR0AH/ICR10AH (E2)
        for _, _, p in bus.peripherals:
            if type(p).__name__ == "ATU2" and hasattr(p, "set_rpm"):
                p.set_rpm(float(value))
                s["value"] = value
                return True
    return True


def read_watch(bus, prof):
    """Decode the profile `watch` list: emulated outputs visible in the UI."""
    import struct
    out = {}
    for w in prof.get("watch", []):
        if w.get("source") == "heartbeats":
            out[w["name"]] = sum(len(getattr(p, "heartbeats", [])) for _, _, p in bus.peripherals)
            continue
        addr = int(str(w["addr"]), 0)
        size = int(str(w.get("size", 4)), 0)
        fmt = w.get("format", "u32")
        raw = bus.read32(addr) if size == 4 else bus.read16(addr)
        if fmt == "float32":
            out[w["name"]] = struct.unpack("<f", struct.pack("<I", raw))[0]
        else:
            out[w["name"]] = raw
    return out


class EmuSession:
    """Runs the emulator on a background thread; API calls pause it."""

    def __init__(self, profile_path):
        self.prof, self.bus, self.cpu = emu.build(profile_path)
        self.lock = threading.Lock()
        self.running = False
        self.stop_flag = False
        self.replay = None  # (rows, idx, cycles_per_row)

    def run_cycles(self, n):
        with self.lock:
            emu.run(self.prof, self.bus, self.cpu, n)

    def state(self):
        with self.lock:
            hb = sum(len(getattr(p, "heartbeats", [])) for _, _, p in self.bus.peripherals)
            sensors = {k: (v.get("value") if isinstance(v, dict) else v)
                       for k, v in self.prof.get("sensors", {}).items() if not k.startswith("_")}
            replay = None
            if self.replay:
                replay = {"row": self.replay["idx"], "of": len(self.replay["rows"])}
            return {
                "profile": self.prof["name"],
                "icount": self.cpu.icount,
                "pc": self.cpu.pc,
                "mmio_writes": len(self.bus.mmio_log),
                "heartbeats": hb,
                "sensors": sensors,
                "watch": read_watch(self.bus, self.prof),
                "replay": replay,
                "running": self.running,
            }

    def set_sensor(self, name, value):
        with self.lock:
            return apply_sensor(self.bus, self.prof, name, value)

    def reset(self):
        with self.lock:
            self.prof, self.bus, self.cpu = emu.build(self._path)

    def start_replay(self, csv_path, speed=1.0):
        rows = list(csv.DictReader(open(csv_path, encoding="utf-8", errors="replace")))
        cmap = self.prof.get("replay_map", {})
        self.replay = {"rows": rows, "idx": 0, "cmap": cmap, "speed": speed,
                       "cycles_per_row": int(2000 * speed)}

    def replay_step(self):
        with self.lock:
            r = self.replay
            if not r or r["idx"] >= len(r["rows"]):
                return None
            row = r["rows"][r["idx"]]
            for col, sensor in r["cmap"].items():
                if col in row and row[col] not in ("", None):
                    try:
                        apply_sensor(self.bus, self.prof, sensor, float(row[col]))
                    except ValueError:
                        pass
            r["idx"] += 1
            emu.run(self.prof, self.bus, self.cpu, r["cycles_per_row"])
            return {"row": r["idx"], "of": len(r["rows"]), "pc": self.cpu.pc,
                    "watch": read_watch(self.bus, self.prof), "sensors": {
                        k: (v.get("value") if isinstance(v, dict) else v)
                        for k, v in self.prof.get("sensors", {}).items() if not k.startswith("_")}}


def debug_api(session, body):
    """Debugger actions for the UI: break/watch/continue/step/regs/mem/disasm/state."""
    import debugger
    if not hasattr(session, "dbg"):
        session.dbg = debugger.DebugSession(session.prof, session.bus, session.cpu)
    dbg = session.dbg
    act = body.get("action")
    if act == "break":
        return {"i": dbg.add_break(int(str(body["addr"]), 0), "exec")}
    if act == "watch":
        return {"i": dbg.add_break(int(str(body["addr"]), 0), "mem", int(str(body.get("size", 4)), 0),
                                   {"r": "read", "w": "write"}.get(body.get("on", "w"), "rw"))}
    if act == "del":
        dbg.del_break(int(body["i"]))
        return {"ok": True}
    if act == "continue":
        return {"reason": dbg.continue_(int(body.get("cycles", 100000))), "state": dbg.state()}
    if act == "step":
        return {"reason": dbg.step(int(body.get("n", 1))), "state": dbg.state()}
    if act == "regs":
        return dbg.regs()
    if act == "mem":
        return {"values": [hex(v) for v in dbg.mem(int(str(body["addr"]), 0), int(body.get("n", 4)))]}
    if act == "disasm":
        return {"lines": dbg.disasm(int(str(body["addr"]), 0), int(body.get("n", 8)))}
    if act == "state":
        return dbg.state()
    return {"error": "unknown action"}


def make_server(session, port):
    class H(BaseHTTPRequestHandler):
        def _json(self, obj, code=200):
            body = json.dumps(obj).encode()
            self.send_response(code)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)

        def log_message(self, *a):
            pass

        def do_GET(self):
            if self.path == "/" or self.path == "/ui.html":
                body = open(os.path.join(HERE, "ui.html"), "rb").read()
                self.send_response(200)
                self.send_header("Content-Type", "text/html")
                self.send_header("Content-Length", str(len(body)))
                self.end_headers()
                self.wfile.write(body)
            elif self.path == "/api/state":
                self._json(session.state())
            elif self.path.startswith("/api/trace"):
                n = 200
                self._json({"trace": [hex(p) for p in (session.cpu.trace or [])[-n:]]})
            else:
                self._json({"error": "not found"}, 404)

        def do_POST(self):
            length = int(self.headers.get("Content-Length", 0))
            body = json.loads(self.rfile.read(length) or b"{}")
            if self.path == "/api/run":
                session.run_cycles(int(body.get("cycles", 1000)))
                self._json(session.state())
            elif self.path == "/api/reset":
                session._path = session_path
                session.reset()
                self._json(session.state())
            elif self.path == "/api/sensors":
                ok = all(session.set_sensor(k, float(v)) for k, v in body.items())
                self._json({"ok": ok, "state": session.state()})
            elif self.path == "/api/replay":
                csv_path = body.get("csv")
                if not os.path.isabs(csv_path):
                    csv_path = os.path.join(REPO_ROOT, csv_path)
                session.start_replay(csv_path, float(body.get("speed", 1)))
                self._json({"ok": True, "rows": len(session.replay["rows"])})
            elif self.path == "/api/replay_step":
                self._json(session.replay_step())
            elif self.path == "/api/debug":
                self._json(debug_api(session, body))
            else:
                self._json({"error": "not found"}, 404)

    srv = ThreadingHTTPServer(("127.0.0.1", port), H)
    return srv


def main(argv=None):
    global session_path
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--profile", required=True)
    ap.add_argument("--port", type=int, default=8080)
    args = ap.parse_args(argv)
    session_path = args.profile if os.path.isfile(args.profile) else os.path.join(emu.PROFILES_DIR, args.profile + ".json")
    session = EmuSession(session_path)
    srv = make_server(session, args.port)
    print(f"UI on http://127.0.0.1:{args.port}/  (profile {session.prof['name']})")
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
