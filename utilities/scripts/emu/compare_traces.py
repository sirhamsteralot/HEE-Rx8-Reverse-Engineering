#!/usr/bin/env python3
"""Diff two execution traces (ours vs Renesas Simulator Debugger export, or any
two golden traces). Each line may contain one hex address; lines starting with
'#' are ignored. Reports the first divergence.

Usage:
    python compare_traces.py trace_a.txt trace_b.txt [--max N]

Our emulator writes traces via: emu.py --profile X --trace out.txt
(lines: "<n> 0x<pc>" plus "# mmio ..." comment lines).
Renesas Simulator Debugger: load the same ROM at 0x0 for SH7055, run the same
number of instructions, export the PC trace (e.g. via its trace window / script)
to a text file with one hex address per line, then diff.
"""
import argparse
import re
import sys

HEX = re.compile(r"0x[0-9a-fA-F]+")


def load(path):
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
