#!/usr/bin/env python3
"""Diff two execution traces (ours vs Renesas Simulator Debugger export, or any
two golden traces). Reports the first divergence.

Plain trace format: one hex address per line; lines starting with '#' ignored.

Renesas SH simulator Trace-window export (TSV whose header starts with 'PTR'):
columns PTR, Cycle, Address, Pipeline, Instruction, ... The buffer is written
newest-first with pipelined rows, so we keep execute-stage rows (Pipeline
contains 'E') that carry an instruction, sort by Cycle, and use the Address
column as the architectural PC sequence.

Usage:
    python compare_traces.py trace_a.txt trace_b.txt [--max N]

Our emulator writes traces via: emu.py --profile X --trace out.txt
(lines: "<n> 0x<pc>" plus "# mmio ..." comment lines).
"""
import argparse
import re
import sys

HEX = re.compile(r"0x[0-9a-fA-F]+")


def load(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        first = f.readline()
    if first.lstrip().startswith("PTR"):
        rows = []
        with open(path, encoding="utf-8", errors="replace") as f:
            f.readline()
            for line in f:
                parts = line.rstrip("\r\n").split("\t")
                if len(parts) >= 5 and parts[4].strip() and "E" in parts[3]:
                    try:
                        rows.append((int(parts[1]), int(parts[2], 16)))
                    except ValueError:
                        pass
        rows.sort(key=lambda r: r[0])
        return [addr for _, addr in rows]
    pcs = []
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            if line.lstrip().startswith("#"):
                continue
            m = HEX.search(line)
            if m:
                pcs.append(int(m.group(0), 16))
    return pcs


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("a")
    ap.add_argument("b")
    ap.add_argument("--max", type=int, default=0, help="compare at most N entries")
    args = ap.parse_args(argv)
    a, b = load(args.a), load(args.b)
    n = min(len(a), len(b), args.max or min(len(a), len(b)))
    for i in range(n):
        if a[i] != b[i]:
            print(f"DIVERGENCE at step {i}: A=0x{a[i]:08x} B=0x{b[i]:08x} "
                  f"(A {len(a)} entries, B {len(b)} entries)")
            return 1
    print(f"MATCH: {n} steps identical (A {len(a)} entries, B {len(b)} entries)")
    return 0 if len(a) == len(b) else 2


if __name__ == "__main__":
    sys.exit(main())
