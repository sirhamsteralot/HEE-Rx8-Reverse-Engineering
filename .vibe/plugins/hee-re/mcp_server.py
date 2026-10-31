#!/usr/bin/env python3
"""MCP server (stdio, JSON-RPC 2.0 / NDJSON, stdlib only) exposing the HEE RX-8
RE tooling to agents as callable tools.

Tools (namespace heeRe):
  hee_rom_list, hee_rom_info, hee_manifest_check,
  hee_boot, hee_run, hee_state, hee_regs, hee_mem, hee_disasm,
  hee_break, hee_watch, hee_del_break, hee_continue, hee_step,
  hee_set_sensor, hee_replay_load, hee_replay_step,
  hee_labels (query data/labels), hee_disasm_rom (from the listing),
  hee_diff_roms (byte-diff two binaries, e.g. tuned vs stock)

Emulator sessions persist per profile inside this process.
"""
import hashlib
import json
import os
import struct
import subprocess
import sys

PLUGIN_ROOT = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(PLUGIN_ROOT, "..", "..", ".."))  # .vibe/plugins/hee-re -> repo root
EMU = os.path.join(REPO, "utilities", "scripts", "emu")
sys.path.insert(0, EMU)

import emu  # noqa: E402
import debugger  # noqa: E402
import ui as emu_ui  # noqa: E402
from opdec import OPMNEM  # noqa: E402

SESSIONS = {}  # profile name -> (prof, bus, cpu, dbg)


def get_session(profile):
    if profile not in SESSIONS:
        path = profile if os.path.isfile(profile) else os.path.join(EMU, "profiles", profile + ".json")
        prof, bus, cpu = emu.build(path)
        dbg = debugger.DebugSession(prof, bus, cpu)
        SESSIONS[profile] = (prof, bus, cpu, dbg)
    return SESSIONS[profile]


def rom_info(path):
    p = path if os.path.isabs(path) else os.path.join(REPO, path)
    d = open(p, "rb").read()
    return {
        "path": path, "size": len(d), "sha256": hashlib.sha256(d).hexdigest(),
        "firmware_id_at_0x2000": d[0x2000:0x2008].decode("ascii", "replace").strip(),
        "cal_id_at_0x6c046": d[0x6c046:0x6c04b].decode("ascii", "replace").strip(),
    }


def hee_labels(rom_id, query):
    """Look up labels: query an address (0x...) or a name substring."""
    base = os.path.join(REPO, "data", "labels", rom_id)
    out = []
    q = query.lower()
    for fn in ("integrated_names.json",):
        fp = os.path.join(base, fn)
        if os.path.isfile(fp):
            data = json.load(open(fp))
            for k, v in data.items():
                if q in k.lower() or q in str(v).lower():
                    out.append({k: v})
    for fn in os.listdir(base) if os.path.isdir(base) else []:
        if fn.endswith(".tsv"):
            for line in open(os.path.join(base, fn), encoding="utf-8", errors="replace"):
                if q in line.lower():
                    out.append(line.strip())
    return out[:50]


def hee_disasm_rom(rom_id, addr, n=8):
    asm = os.path.join(REPO, "reverse-engineered", "disassembly", rom_id, "firmware_disassembly.asm")
    a = int(str(addr), 0)
    out = []
    for line in open(asm, encoding="utf-8", errors="replace"):
        try:
            la = int(line[:8], 16)
        except ValueError:
            continue
        if a <= la < a + 2 * n:
            out.append(line.strip())
        if la >= a + 2 * n:
            break
    return out


def hee_diff_roms(path_a, path_b):
    da = open(os.path.join(REPO, path_a) if not os.path.isabs(path_a) else path_a, "rb").read()
    db = open(os.path.join(REPO, path_b) if not os.path.isabs(path_b) else path_b, "rb").read()
    if len(da) != len(db):
        return {"error": f"size mismatch {len(da)} vs {len(db)}"}
    diffs = [i for i in range(len(da)) if da[i] != db[i]]
    ranges = []
    for i in diffs:
        if ranges and i <= ranges[-1][1] + 1:
            ranges[-1][1] = i
        else:
            ranges.append([i, i])
    return {"bytes_differing": len(diffs), "ranges": [[hex(a), hex(b)] for a, b in ranges]}


TOOLS = [
    {"name": "hee_rom_list", "description": "List emulator profiles and known ROMs (submodule stock ROMs + binaries/dumps).",
     "inputSchema": {"type": "object", "properties": {}}},
    {"name": "hee_rom_info", "description": "Firmware ID (0x2000), cal ID (0x6c046), size, SHA-256 of a ROM file (repo-relative path).",
     "inputSchema": {"type": "object", "properties": {"path": {"type": "string"}}, "required": ["path"]}},
    {"name": "hee_manifest_check", "description": "Verify binaries/manifest.csv SHA-256s.",
     "inputSchema": {"type": "object", "properties": {}}},
    {"name": "hee_boot", "description": "Boot a profile (build emulator, verify ROM hash, run N cycles). Returns icount, final pc, mmio writes, heartbeats, stop reason.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "cycles": {"type": "integer", "default": 1000000}}, "required": ["profile"]}},
    {"name": "hee_run", "description": "Run more cycles on a booted profile.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "cycles": {"type": "integer", "default": 100000}}, "required": ["profile"]}},
    {"name": "hee_state", "description": "Emulator state: pc, icount, mmio writes, heartbeats, breakpoints, stopped reason.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}}, "required": ["profile"]}},
    {"name": "hee_regs", "description": "CPU registers (r0-r15, pc, pr, sr/T, FPU).",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}}, "required": ["profile"]}},
    {"name": "hee_mem", "description": "Read emulated memory (ROM/RAM/MMIO).",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "addr": {"type": "string"}, "n": {"type": "integer", "default": 4}, "size": {"type": "integer", "default": 4}}, "required": ["profile", "addr"]}},
    {"name": "hee_disasm", "description": "Disassemble at PC/address from the corpus table (same mnemonics as the Ghidra listing).",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "addr": {"type": "string"}, "n": {"type": "integer", "default": 8}}, "required": ["profile"]}},
    {"name": "hee_break", "description": "Set an execution breakpoint at an address.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "addr": {"type": "string"}}, "required": ["profile", "addr"]}},
    {"name": "hee_watch", "description": "Set a memory watchpoint (on: r/w/rw).",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "addr": {"type": "string"}, "on": {"type": "string", "default": "w"}, "size": {"type": "integer", "default": 4}}, "required": ["profile", "addr"]}},
    {"name": "hee_del_break", "description": "Delete breakpoint/watchpoint by index (see hee_state).",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "i": {"type": "integer"}}, "required": ["profile", "i"]}},
    {"name": "hee_continue", "description": "Continue until a breakpoint/watchpoint/UBC fires or the cycle budget ends.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "cycles": {"type": "integer", "default": 1000000}}, "required": ["profile"]}},
    {"name": "hee_step", "description": "Single-step n instructions.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "n": {"type": "integer", "default": 1}}, "required": ["profile"]}},
    {"name": "hee_set_sensor", "description": "Inject a sensor input (rpm, maf, coolant_temp, iat, throttle, knock, apv) into the emulation via the profile's hardware path (ADC ADDRn channel or ATU-II crank capture for rpm). engine_load is a watched OUTPUT (RAM 0xffffc0b4), not an input.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "name": {"type": "string"}, "value": {"type": "number"}}, "required": ["profile", "name", "value"]}},
    {"name": "hee_replay_load", "description": "Load a drive-cycle CSV (repo-relative, e.g. data/logs/rx8-666p/....csv) for replay.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}, "csv": {"type": "string"}, "speed": {"type": "number", "default": 1}}, "required": ["profile", "csv"]}},
    {"name": "hee_replay_step", "description": "Advance the replay one log row (applies sensors, runs cycles); returns watch values.",
     "inputSchema": {"type": "object", "properties": {"profile": {"type": "string"}}, "required": ["profile"]}},
    {"name": "hee_labels", "description": "Query RE labels for a ROM (address or name substring) from data/labels/<rom-id>/.",
     "inputSchema": {"type": "object", "properties": {"rom_id": {"type": "string"}, "query": {"type": "string"}}, "required": ["rom_id", "query"]}},
    {"name": "hee_disasm_rom", "description": "Disassemble a ROM address range from the committed listing (no emulation needed).",
     "inputSchema": {"type": "object", "properties": {"rom_id": {"type": "string"}, "addr": {"type": "string"}, "n": {"type": "integer", "default": 8}}, "required": ["rom_id", "addr"]}},
    {"name": "hee_diff_roms", "description": "Byte-diff two repo-relative ROM paths; returns differing ranges (e.g. tuned vs stock).",
     "inputSchema": {"type": "object", "properties": {"a": {"type": "string"}, "b": {"type": "string"}}, "required": ["a", "b"]}},
]


def call_tool(name, args):
    if name == "hee_rom_list":
        profs = sorted(f[:-5] for f in os.listdir(os.path.join(EMU, "profiles")) if f.endswith(".json") and f != "template.json")
        roms = sorted(os.listdir(os.path.join(REPO, "submodules", "Mazda_RX8_PCM_ReverseEngineering", "Stock_ROMs")))
        dumps = sorted(os.listdir(os.path.join(REPO, "binaries", "dumps"))) if os.path.isdir(os.path.join(REPO, "binaries", "dumps")) else []
        return {"profiles": profs, "stock_roms_submodule": roms, "own_dumps": dumps}
    if name == "hee_rom_info":
        return rom_info(args["path"])
    if name == "hee_manifest_check":
        r = subprocess.run([sys.executable, os.path.join(REPO, "utilities", "scripts", "hash_binaries.py"), "--check"],
                           capture_output=True, text=True)
        return {"returncode": r.returncode, "output": r.stdout.strip()}
    if name in ("hee_boot", "hee_run"):
        prof, bus, cpu, dbg = get_session(args["profile"])
        cycles = int(args.get("cycles", 1000000))
        stop = emu.run(prof, bus, cpu, cycles)
        return {"profile": prof["name"], "icount": cpu.icount, "pc": hex(cpu.pc),
                "mmio_writes": len(bus.mmio_log), "stop": stop,
                "heartbeats": sum(len(getattr(p, "heartbeats", [])) for _, _, p in bus.peripherals)}
    if name == "hee_state":
        prof, bus, cpu, dbg = get_session(args["profile"])
        return dbg.state() | {"watch": emu_ui.read_watch(bus, prof),
                              "heartbeats": sum(len(getattr(p, "heartbeats", [])) for _, _, p in bus.peripherals),
                              "mmio_writes": len(bus.mmio_log)}
    if name == "hee_regs":
        return get_session(args["profile"])[3].regs()
    if name == "hee_mem":
        prof, bus, cpu, dbg = get_session(args["profile"])
        return {"values": [hex(v) for v in dbg.mem(int(str(args["addr"]), 0), int(args.get("n", 4)), int(args.get("size", 4)))]}
    if name == "hee_disasm":
        prof, bus, cpu, dbg = get_session(args["profile"])
        addr = int(str(args.get("addr", hex(cpu.pc))), 0)
        return {"lines": dbg.disasm(addr, int(args.get("n", 8)))}
    if name == "hee_break":
        return {"i": get_session(args["profile"])[3].add_break(int(str(args["addr"]), 0), "exec")}
    if name == "hee_watch":
        dbg = get_session(args["profile"])[3]
        on = {"r": "read", "w": "write", "rw": "rw"}.get(args.get("on", "w"), "write")
        return {"i": dbg.add_break(int(str(args["addr"]), 0), "mem", int(args.get("size", 4)), on)}
    if name == "hee_del_break":
        get_session(args["profile"])[3].del_break(int(args["i"]))
        return {"ok": True}
    if name == "hee_continue":
        prof, bus, cpu, dbg = get_session(args["profile"])
        return {"reason": dbg.continue_(int(args.get("cycles", 1000000))), "pc": hex(cpu.pc)}
    if name == "hee_step":
        prof, bus, cpu, dbg = get_session(args["profile"])
        return {"reason": dbg.step(int(args.get("n", 1))), "pc": hex(cpu.pc)}
    if name == "hee_set_sensor":
        prof, bus, cpu, dbg = get_session(args["profile"])
        return {"ok": emu_ui.apply_sensor(bus, prof, args["name"], float(args["value"]))}
    if name == "hee_replay_load":
        prof, bus, cpu, dbg = get_session(args["profile"])
        csv_path = args["csv"] if os.path.isabs(args["csv"]) else os.path.join(REPO, args["csv"])
        s = emu_ui.EmuSession.__new__(emu_ui.EmuSession)
        s.prof, s.bus, s.cpu = prof, bus, cpu
        s.replay = None
        s.start_replay(csv_path, float(args.get("speed", 1)))
        SESSIONS[args["profile"]] = (prof, bus, cpu, dbg)
        session_replays[args["profile"]] = s
        return {"rows": len(s.replay["rows"])}
    if name == "hee_replay_step":
        prof, bus, cpu, dbg = get_session(args["profile"])
        s = session_replays.get(args["profile"])
        if not s:
            return {"error": "no replay loaded; call hee_replay_load first"}
        s.lock = __import__("threading").Lock()
        return s.replay_step()
    if name == "hee_labels":
        return {"matches": hee_labels(args["rom_id"], args["query"])}
    if name == "hee_disasm_rom":
        return {"lines": hee_disasm_rom(args["rom_id"], args["addr"], int(args.get("n", 8)))}
    if name == "hee_diff_roms":
        return hee_diff_roms(args["a"], args["b"])
    return {"error": f"unknown tool {name}"}


session_replays = {}


def rpc_result(req_id, result):
    return {"jsonrpc": "2.0", "id": req_id, "result": result}


def handle(msg):
    method = msg.get("method")
    if method == "initialize":
        return rpc_result(msg.get("id"), {
            "protocolVersion": "2024-11-05",
            "capabilities": {"tools": {}},
            "serverInfo": {"name": "hee-re", "version": "1.0.0"},
        })
    if method == "notifications/initialized":
        return None
    if method == "ping":
        return rpc_result(msg.get("id"), {})
    if method == "tools/list":
        return rpc_result(msg.get("id"), {"tools": TOOLS})
    if method == "tools/call":
        p = msg.get("params", {})
        try:
            result = call_tool(p.get("name"), p.get("arguments") or {})
            return rpc_result(msg.get("id"), {"content": [{"type": "text", "text": json.dumps(result, indent=2, default=str)}]})
        except Exception as e:
            return rpc_result(msg.get("id"), {"content": [{"type": "text", "text": f"error: {e}"}], "isError": True})
    return {"jsonrpc": "2.0", "id": msg.get("id"), "error": {"code": -32601, "message": f"method not found: {method}"}}


def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        try:
            msg = json.loads(line)
        except json.JSONDecodeError:
            continue
        resp = handle(msg)
        if resp is not None:
            sys.stdout.write(json.dumps(resp) + "\n")
            sys.stdout.flush()


if __name__ == "__main__":
    main()
