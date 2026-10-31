#!/usr/bin/env python3
"""Interactive debugger CLI for the HEE emulator.

    python utilities/scripts/emu/debug.py --profile 60E15120_N3J1E [--cycles 1000000]

Commands: b <addr> (exec bp) | w <addr> [r|w|rw] (watchpoint) | del <i> | c (continue)
          s [n] (step) | regs | m <addr> [n] | x <addr> [n] (disasm) | state | q
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import emu  # noqa: E402
from debugger import DebugSession  # noqa: E402


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--profile", required=True)
    ap.add_argument("--cycles", type=int, default=10_000_000, help="budget per continue")
    ap.add_argument("--boot", type=int, default=200_000, help="instructions to run before dropping into the prompt")
    args = ap.parse_args(argv)
    path = args.profile if os.path.isfile(args.profile) else os.path.join(emu.PROFILES_DIR, args.profile + ".json")
    prof, bus, cpu = emu.build(path)
    dbg = DebugSession(prof, bus, cpu)
    print(f"booting {prof['name']} for {args.boot} instructions...")
    emu.run(prof, bus, cpu, args.boot)
    print(f"pc=0x{cpu.pc:08x} icount={cpu.icount}. '?' for help.")
    while True:
        try:
            line = input("emu> ").strip()
        except (EOFError, KeyboardInterrupt):
            print()
            break
        if not line:
            continue
        parts = line.split()
        cmd = parts[0]
        try:
            if cmd in ("q", "quit"):
                break
            elif cmd == "?":
                print(__doc__)
            elif cmd == "b":
                i = dbg.add_break(int(parts[1], 0), "exec")
                print(f"bp#{i} at 0x{int(parts[1],0):08x}")
            elif cmd == "w":
                on = parts[2] if len(parts) > 2 else "w"
                on = {"r": "read", "w": "write", "rw": "rw"}.get(on, "write")
                i = dbg.add_break(int(parts[1], 0), "mem", 4, on)
                print(f"watch#{i} on 0x{int(parts[1],0):08x} ({on})")
            elif cmd == "del":
                dbg.del_break(int(parts[1]))
                print("deleted")
            elif cmd == "c":
                print(dbg.continue_(args.cycles), f"pc=0x{cpu.pc:08x}")
            elif cmd == "s":
                n = int(parts[1]) if len(parts) > 1 else 1
                print(dbg.step(n), f"pc=0x{cpu.pc:08x}")
            elif cmd == "regs":
                r = dbg.regs()
                print(" ".join(f"r{i}=0x{r[f'r{i}']:08x}" for i in range(16)))
                print(f"pc=0x{r['pc']:08x} pr=0x{r['pr']:08x} T={r['T']} sr=0x{r['sr']:08x}")
            elif cmd == "m":
                addr = int(parts[1], 0)
                n = int(parts[2]) if len(parts) > 2 else 4
                print([hex(v) for v in dbg.mem(addr, n)])
            elif cmd == "x":
                addr = int(parts[1], 0)
                n = int(parts[2]) if len(parts) > 2 else 8
                print("\n".join(dbg.disasm(addr, n)))
            elif cmd == "state":
                print(dbg.state())
            else:
                print("unknown command; '?' for help")
        except (IndexError, ValueError) as e:
            print(f"error: {e}")


if __name__ == "__main__":
    main()
