"""Idle target RPM calculation: static binary-level checks for 0x1506c
idle_target_rpm_calculate (idle task ref_updateIdleControl__ 0x167c0 <- task[10]
body 0x11744; task table rec[10] entry 0x64f6 at ROM 0x4a38).

Asserts the call-site pool word + jsr, ROM bytes for the six 2-D descriptors and
the base table values/axis (1700 rpm @ -40 C .. 810 rpm @ 80 C), and that the new
label is present in function_index.tsv, symbols.tsv, the accepted TSVs and the
labels JSON. Run: python -m pytest tests/test_idle_target_control.py
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


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


def f32(a):
    return struct.unpack(">f", ROM[a:a + 4])[0]


def asm_line(addr):
    for l in ASM:
        if l.startswith(f"{addr:08x} "):
            return l
    raise AssertionError(f"no disassembly line at 0x{addr:x}")


EXPECTED_FN = {"0001506c": "idle_target_rpm_calculate"}
EXPECTED_RAM = {"ffffa7f4": "idle_target_rpm"}


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


def test_call_site_pool_word():
    # mov.l @(0x168ac,pc),r3 at 0x167fa; jsr @r3 at 0x167fc; pool = 0x1506c
    assert u32(0x168AC) == 0x1506C
    assert "@(0x168ac,pc)" in asm_line(0x167FA).replace(" ", "")
    assert "jsr" in asm_line(0x167FC)
    # task table rec[10].entry = 0x64f6 (thunk -> task[10] body 0x11744)
    assert u32(0x4990 + 10 * 16 + 8) == 0x64F6


def test_idle_descriptors():
    for d in (0x6935C, 0x69370, 0x693D4, 0x693E8, 0x693FC, 0x69410):
        n, typ, res, ax, data = struct.unpack(">HBBII", ROM[d:d + 12])
        assert 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000 and typ in (0, 4, 8, 12, 16)
    # base Idle Target table 0x69370: n=7, coolant -40..80 C axis @0x6dcf4, u16 rpm @0x6dd10
    n, typ, res, ax, data = struct.unpack(">HBBII", ROM[0x69370:0x69370 + 12])
    assert (n, ax, data) == (7, 0x6DCF4, 0x6DD10)
    assert f32(0x6DCF4) == -40.0 and f32(0x6DCF4 + 6 * 4) == 80.0
    assert u16(0x6DD10) == 1700 and u16(0x6DD10 + 6 * 2) == 810
    # filter-factor table 0x6935c: n=11, type 8
    n, typ, res, ax, data = struct.unpack(">HBBII", ROM[0x6935C:0x6935C + 12])
    assert (n, typ, ax, data) == (11, 8, 0x6DCB0, 0x6DCDC)
