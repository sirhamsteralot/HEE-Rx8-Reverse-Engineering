"""Test compare_traces.py's Renesas SH-simulator Trace-window TSV loader.

Run: python -m pytest tests/test_compare_traces_renesas.py
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu"))

import compare_traces as ct


def test_renesas_tsv_loader(tmp_path):
    f = tmp_path / "fake_renesas.trace"


    # build a fake Renesas TSV trace: newest-first, pipelined rows
    # 3 instructions: 0x100 (MOV), 0x102 (NOP), 0x104 (BRA back to 0x100)
    hdr = "PTR\tCycle\tAddress\tPipeline\tInstruction\t\t\t\t\r\n"
    rows = []
    cyc = 1000
    for rep in range(3):
        for addr, instr in [(0x100, 'MOV R1,R2'), (0x102, 'NOP'), (0x104, 'BRA 0x100')]:
            # pipeline rows: F (no instr), then FDEM...E (with instr)
            rows.append((cyc, addr, 'F       ', ''))
            rows.append((cyc + 1, addr, 'FDEMMMMW', instr))
            cyc += 2
    # write newest-first (reverse)
    lines = [hdr]
    for i in range(len(rows) - 1, -1, -1):
        c, a, p, ins = rows[i]
        lines.append(f'{-i}\t{c:010d}\t{a:08X}\t{p}\t{ins}\t\t\t\t\r\n')
    open(f, 'w').write(''.join(lines))
    pcs = ct.load(str(f))
    expected = [0x100, 0x102, 0x104] * 3
    assert pcs == expected, f'{[hex(p) for p in pcs]} != {[hex(p) for p in expected]}'
    print('Renesas TSV loader OK:', [hex(p) for p in pcs])
