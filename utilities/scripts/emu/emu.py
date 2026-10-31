#!/usr/bin/env python3
"""HEE SH-2E emulator runner — config-driven, per-ROM/market profiles.

Usage:
    python utilities/scripts/emu/emu.py --profile 60E15120_N3J1E [--cycles N] [--trace FILE]
    python utilities/scripts/emu/emu.py --list-profiles

Loads the profile (verifying the ROM SHA-256), builds the bus + peripherals,
runs the CPU from the reset vector, and prints a summary (instructions executed,
stop reason, MMIO write count, watchdog heartbeats). With --trace, writes one
`cycle pc` line per executed instruction plus the MMIO log, for golden-trace
comparison in tests/.
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from bus import Bus
from peripherals import TYPES
from profile import load_profile, list_profiles, ProfileError
from sh2e import SH2E, UnknownOpcode


def _periph_cls(p):
    if p["type"] == "can":
        from can import CANController
        return CANController
    return TYPES[p["type"]]

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))
PROFILES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "profiles")


def build(profile_path):
    prof = load_profile(profile_path, REPO_ROOT)
    with open(prof["rom"]["_abs_path"], "rb") as f:
        rom_bytes = f.read()
    bus = Bus(prof["memory"], rom_bytes)
    for p in prof["peripherals"]:
        cls = _periph_cls(p)
        bus.add_peripheral(p["base"], p["size"], cls(p["base"], p["size"], p.get("config", {})))
    cpu = SH2E(bus)
    bus.cpu = cpu
    mm = prof["memory"]
    rom_start = mm["rom"][0]
    pc = cpu.r32(rom_start + prof.get("reset", {}).get("pc_from_vector", 0))
    sp = cpu.r32(rom_start + prof.get("reset", {}).get("sp_from_vector", 4))
    cpu.reset(pc, sp)
    return prof, bus, cpu


def run(prof, bus, cpu, cycles, trace=None):
    if trace is not None:
        cpu.trace = trace
    stop = None
    try:
        for _ in range(cycles):
            bus.pc = cpu.pc
            cpu.step()
            bus.tick(1)
    except UnknownOpcode as e:
        stop = f"unknown opcode 0x{e.opcode:04x} at 0x{e.pc:08x} (opcode subset limit)"
    return stop or f"cycle limit {cycles} reached"


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--profile", help="profile name (profiles/<name>.json) or path")
    ap.add_argument("--list-profiles", action="store_true")
    ap.add_argument("--cycles", type=int, default=100000)
    ap.add_argument("--trace", help="write execution trace (cycle pc + MMIO log) to this file")
    args = ap.parse_args(argv)

    if args.list_profiles:
        for p in list_profiles(PROFILES_DIR):
            print(os.path.basename(p))
        return 0
    if not args.profile:
        ap.error("--profile is required (or use --list-profiles)")

    path = args.profile if os.path.isfile(args.profile) else os.path.join(PROFILES_DIR, args.profile + ".json")
    try:
        prof, bus, cpu = build(path)
    except ProfileError as e:
        print(f"profile error: {e}", file=sys.stderr)
        return 2

    trace = [] if args.trace else None
    stop = run(prof, bus, cpu, args.cycles, trace)

    heartbeats = 0
    for _, _, p in bus.peripherals:
        if hasattr(p, "heartbeats"):
            heartbeats += len(p.heartbeats)

    print(f"profile:    {prof['name']} ({prof.get('market', '?')} {prof.get('model', '?')}, "
          f"variant {prof.get('variant', {})})")
    print(f"rom:        {prof['rom']['path']} ({prof['rom']['_size']} bytes, sha256 ok)")
    print(f"reset:      pc=0x{cpu.pr if False else 0:08x} -> ran {cpu.icount} instructions")
    print(f"stop:       {stop}")
    print(f"final pc:   0x{cpu.pc:08x}")
    print(f"mmio writes logged: {len(bus.mmio_log)}")
    print(f"wdt heartbeats (PB15 toggles): {heartbeats}")

    if args.trace:
        with open(args.trace, "w", encoding="utf-8") as f:
            for i, pc in enumerate(trace):
                f.write(f"{i} 0x{pc:08x}\n")
            f.write("# mmio log: cycle pc addr value size\n")
            for c, pc, addr, val, size in bus.mmio_log:
                f.write(f"# mmio {c} 0x{pc:08x} 0x{addr:08x} 0x{val:08x} {size}\n")
        print(f"trace:      {args.trace} ({len(trace)} instructions)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
