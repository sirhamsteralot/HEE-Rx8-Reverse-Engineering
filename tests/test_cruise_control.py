"""Cruise control: static binary-level checks for 0x4ca7e
cruise_speed_error_filter_stage (batch 0x2e692 in task[10] body 0x11744),
0x2d83c cruise_set_speed_adjust_integrator (batch 0x2e5c6 in slow task
0x11534), 0x4c828 cruise_switch_code_decode, 0x2df62 cruise_set_speed_apply.

Asserts call-site pool words + jsr addresses, the task-table entries, ROM bytes
for the 2-D/3-D descriptors and the 3.2f tolerance pools, and that the new
labels are present in function_index.tsv, symbols.tsv, the accepted TSVs and
the labels JSON. Run: python -m pytest tests/test_cruise_control.py
"""
import csv
import json
import os
import struct

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
ROM_PATH = os.path.join(
    ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Stock_ROMs", "60E15120_N3J1E.bin")
DEC = os.path.join(ROOT, "reverse-engineered", "decompiled", "60E15120_N3J1E")
DIS = os.path.join(ROOT, "reverse-engineered", "disassembly", "60E15120_N3J1E")
INV = os.path.join(ROOT, "docs", "investigations", "60E15120_N3J1E")
LAB = os.path.join(ROOT, "data", "labels", "60E15120_N3J1E")

ROM = open(ROM_PATH, "rb").read()
ASM = open(os.path.join(DIS, "firmware_disassembly.asm"), encoding="latin-1").read().splitlines()


def u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def asm_line(addr):
    for l in ASM:
        if l.startswith(f"{addr:08x} "):
            return l
    raise AssertionError(f"no disassembly line at 0x{addr:x}")


EXPECTED_FN = {
    "0004ca7e": "cruise_speed_error_filter_stage",
    "0002d83c": "cruise_set_speed_adjust_integrator",
    "0004c828": "cruise_switch_code_decode",
    "0002df62": "cruise_set_speed_apply",
}
EXPECTED_RAM = {
    "ffffbaed": "cruise_switch_code",
    "ffffbcf8": "cruise_set_speed",
    "ffffbd08": "cruise_set_speed_adjust",
    "ffffcef4": "cruise_filtered_speed_error",
    "ffffcee4": "cruise_speed_error_mean12",
}


def test_labels_in_artifacts():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""), delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert idx.get(addr) == name, f"{addr}: {idx.get(addr)!r} != {name!r}"
    syms = {r["address"]: r["name"] for r in
            csv.DictReader(open(os.path.join(DEC, "symbols.tsv"), newline="", encoding="utf-8",
                                errors="surrogateescape"), delimiter="\t")}
    for addr, alias in EXPECTED_RAM.items():
        assert syms.get(addr) == f"{alias}_{addr}", f"{addr}: {syms.get(addr)!r}"
    fn = {r["address"]: r["alias"] for r in
          csv.DictReader(open(os.path.join(INV, "source_review", "accepted_function_aliases.tsv"),
                              newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    ram = {r["address"]: r["alias"] for r in
           csv.DictReader(open(os.path.join(INV, "source_review", "accepted_ram_aliases.tsv"),
                               newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    data = json.load(open(os.path.join(LAB, "large_control_bodies_labels.json")))
    for addr, name in EXPECTED_FN.items():
        assert fn.get(addr) == name
        assert data["function_aliases"][addr]["alias"] == name
    for addr, alias in EXPECTED_RAM.items():
        assert ram.get(addr) == alias
        assert data["ram_aliases"][addr]["alias"] == alias
    # the labels JSON covers exactly this pass's rows overall (15 fn + 17 RAM);
    # each subsystem file checks its own subset against the artifacts
    assert len(data["function_aliases"]) == 15
    assert len(data["ram_aliases"]) == 17


def test_call_site_pool_words():
    # (pool_addr, expected_target, mov_addr): mov.l @(pool,pc),rN at mov_addr, jsr @rN at mov_addr+2
    for pool, target, mov in ((0x2E7DC, 0x4CA7E, 0x2E6C6), (0x2E790, 0x2D83C, 0x2E63C)):
        assert u32(pool) == target, hex(pool)
        assert f"@(0x{pool:x},pc)" in asm_line(mov).replace(" ", "")
        assert "jsr" in asm_line(mov + 2)


def test_task_table_entries():
    assert u32(0x4990 + 10 * 16 + 8) == 0x64F6   # task[10] -> 0x11744 (idle + cruise batch)
    assert u32(0x4990 + 18 * 16 + 8) == 0x64E8   # task[18] -> slow task 0x11534


def test_cruise_descriptors_and_pools():
    # 3.2f tolerance at 0x7d0c8/0x7d0cc via pointer pools 0x4ce14/0x4ce1c
    assert u32(0x7D0C8) == 0x404CCCCD and u32(0x7D0CC) == 0x404CCCCD
    assert u32(0x4CE14) == 0x7D0C8 and u32(0x4CE1C) == 0x7D0CC
    # 2-D descriptors: 0x6bbe0-0x6bc34 (min/max) and 0x6bc40-0x6bc70 (per-switch offsets)
    for d in list(range(0x6BBE0, 0x6BC34 + 1, 12)) + list(range(0x6BC40, 0x6BC70 + 1, 12)):
        n, typ, res, ax, data = struct.unpack(">HBBII", ROM[d:d + 12])
        assert 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000
    # 2-D band ramps 0x6a880-0x6a8b0 (n=31)
    for d in range(0x6A880, 0x6A8B0 + 1, 12):
        n, typ, res, ax, data = struct.unpack(">HBBII", ROM[d:d + 12])
        assert n == 31 and 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000
    # 3-D speed x band descriptors 0x6a8d0-0x6a920
    for d in range(0x6A8D0, 0x6A920 + 1, 20):
        nx, ny, ax, ay, data, typ = struct.unpack(">HHIIIB", ROM[d:d + 17])
        assert 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000
    nx, ny, ax, ay, data, typ = struct.unpack(">HHIIIB", ROM[0x6A8D0:0x6A8D0 + 17])
    assert (ax, ay) == (0x77198, 0x771C0)  # speed 20-200 km/h, band 2-6
