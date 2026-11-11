"""Ignition timing chain: binary-level checks for the leading/trailing
timing-correction RAM cells promoted from the DSC CAN review pass.

For each of the 18 cells (0xffffa5e8..0xffffa784) asserts, against the raw ROM
and the disassembly: the literal-pool word (mov.w pools sign-extend to
0xffff...., mov.l pools carry the full word), the pool-load instruction, and the
store instruction that writes the cell. Also asserts the aliases + evidence are
present in ignition_timing_labels.json and accepted_ram_aliases.tsv, and the
producer function names in function_index.tsv.
Run: python -m pytest tests/test_ignition_timing.py
"""
import csv
import json
import os
import re
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


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


def u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def asm_line(addr):
    for l in ASM:
        if l.startswith(f"{addr:08x} "):
            return l
    raise AssertionError(f"no disassembly line at 0x{addr:x}")


# cell -> alias, writer, pool (addr, kind, word), pool-load instr, store instr (addr, bytes, text)
CELLS = {
    "ffffa5e8": ("leading_base_timing_final", "0x11f00",
                 (0x12010, "w", 0xA5E8), 0x11FDC, (0x11FE8, "f22a", "fmov.s fr2,@r2")),
    "ffffa5ec": ("trailing_base_timing_final", "0x1206c",
                 (0x1217C, "w", 0xA5EC), 0x12148, (0x12154, "f22a", "fmov.s fr2,@r2")),
    "ffffa5f0": ("leading_coolant_scaled_advance_term", "0x11f00",
                 (0x1200A, "w", 0xA5F0), 0x11F58, (0x11F60, "f12a", "fmov.s fr2,@r1")),
    "ffffa5f4": ("trailing_coolant_scaled_advance_term", "0x1206c",
                 (0x12176, "w", 0xA5F4), 0x120C4, (0x120CC, "f12a", "fmov.s fr2,@r1")),
    "ffffa644": ("cranking_timing_multiplier_leading", "0x123da",
                 (0x12548, "l", 0xFFFFA644), 0x12464, (0x1249C, "fe0a", "fmov.s fr0,@r14")),
    "ffffa654": ("cranking_timing_multiplier_trailing", "0x124d6",
                 (0x1256C, "l", 0xFFFFA654), 0x12508, (0x12582, "fe0a", "fmov.s fr0,@r14")),
    "ffffa64c": ("leading_min_advance_clamp", "0x12630",
                 (0x127B8, "l", 0xFFFFA64C), 0x126E8, (0x1270E, "fe0a", "fmov.s fr0,@r14")),
    "ffffa65c": ("trailing_min_advance_clamp", "0x12754",
                 (0x12868, "l", 0xFFFFA65C), 0x127F4, (0x1281A, "fe0a", "fmov.s fr0,@r14")),
    "ffffa660": ("leading_max_advance", "0x121fc",
                 (0x122F4, "l", 0xFFFFA660), 0x1229A, (0x1229C, "f20a", "fmov.s fr0,@r2")),
    "ffffa664": ("trailing_max_advance", "0x12300",
                 (0x12430, "l", 0xFFFFA664), 0x1239E, (0x123A0, "f20a", "fmov.s fr0,@r2")),
    "ffffa634": ("leading_timing_with_corrections", "0x123ba",
                 (0x12410, "w", 0xA634), 0x123C4, (0x123C8, "f32a", "fmov.s fr2,@r3")),
    "ffffa63c": ("trailing_timing_with_corrections", "0x123ca",
                 (0x1240C, "w", 0xA63C), 0x123D4, (0x123D8, "f32a", "fmov.s fr2,@r3")),
    "ffffa718": ("idle_leading_timing_error_correction", "0x135b4",
                 (0x136AA, "w", 0xA718), 0x13688, (0x1368A, "f3fa", "fmov.s fr15,@r3")),
    "ffffa71c": ("idle_trailing_timing_error_correction", "0x136e4",
                 (0x137DA, "w", 0xA71C), 0x137B8, (0x137BA, "f3fa", "fmov.s fr15,@r3")),
    "ffffa778": ("iat_timing_compensation_leading", "0x14090",
                 (0x140E2, "w", 0xA778), 0x14098, (0x140B8, "fe5a", "fmov.s fr5,@r14")),
    "ffffa77c": ("iat_timing_compensation_trailing", "0x14090",
                 (0x140EA, "w", 0xA77C), 0x140D8, (0x140DA, "f33a", "fmov.s fr3,@r3")),
    "ffffa780": ("idle_base_timing_leading", "0x14100",
                 (0x14158, "w", 0xA780), 0x1410A, (0x14120, "fe0a", "fmov.s fr0,@r14")),
    "ffffa784": ("idle_base_timing_trailing", "0x14100",
                 (0x1415E, "w", 0xA784), 0x1414A, (0x1414C, "f33a", "fmov.s fr3,@r3")),
}

# producer function names in function_index.tsv (0x12754 not yet renamed)
EXPECTED_FN = {
    "00011f00": "leading_base_timing_calc",
    "0001206c": "trailing_base_timing_calc",
    "000121fc": "leading_final_timing_clamp_output",
    "00012300": "trailing_final_timing_clamp_output",
    "000123ba": "leading_timing_add_corrections",
    "000123ca": "trailing_timing_add_corrections",
    "000123da": "leading_timing_cranking_blend",
    "000124d6": "trailing_timing_cranking_blend",
    "00012630": "min_advance_clamp_select",
    "00014090": "iat_timing_compensation_on_throttle",
    "00014100": "idle_base_timing_select",
    "000135b4": "idle_leading_timing_error_correction",
    "000136e4": "idle_trailing_timing_error_correction",
}


def test_rom_intact():
    import hashlib
    assert len(ROM) == 0x80000
    assert hashlib.sha256(ROM).hexdigest() == (
        "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1")


def test_pool_words_and_load_instructions():
    for addr, (alias, writer, (pool, kind, word), load, store) in CELLS.items():
        got = u16(pool) if kind == "w" else u32(pool)
        assert got == word, f"{addr}: pool 0x{pool:x} = 0x{got:08x} != 0x{word:08x}"
        ln = asm_line(load)
        m = re.search(r"mov\.[wl] @\(0x([0-9a-f]+),pc\),r\d+", ln)
        assert m and int(m.group(1), 16) == pool, f"{addr}: load line {ln!r}"
        assert f"0x{pool:x}" in ln, f"{addr}: {ln!r}"


def test_store_instructions():
    for addr, (alias, writer, pool, load, (saddr, sbytes, stext)) in CELLS.items():
        assert ROM[saddr:saddr + 2].hex() == sbytes, f"{addr}: ROM[0x{saddr:x}] bytes"
        ln = asm_line(saddr)
        assert sbytes in ln, f"{addr}: {ln!r}"
        assert stext.lstrip("_") in ln, f"{addr}: {ln!r} vs {stext!r}"
        # store uses a plain @rN base (the register loaded from the pool above)
        assert re.search(r",@r\d+$", ln), f"{addr}: {ln!r}"


def test_labels_in_artifacts():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""),
                          delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert idx.get(addr) == name, f"{addr}: {idx.get(addr)!r} != {name!r}"
    ram = {r["address"]: r for r in
           csv.DictReader(open(os.path.join(INV, "source_review", "accepted_ram_aliases.tsv"),
                               newline="", encoding="utf-8", errors="surrogateescape"),
                          delimiter="\t")}
    data = json.load(open(os.path.join(LAB, "ignition_timing_labels.json")))
    for addr, (alias, writer, pool, load, store) in CELLS.items():
        row = ram.get(addr)
        assert row is not None, f"{addr} missing from accepted_ram_aliases.tsv"
        assert row["alias"] == alias, f"{addr}: TSV alias {row['alias']!r}"
        assert row["evidence"].strip(), f"{addr}: TSV evidence empty"
        assert f"0x{store[0]:x}" in row["evidence"], f"{addr}: TSV evidence lacks store 0x{store[0]:x}"
        entry = data["ram_aliases"].get(addr)
        assert entry is not None, f"{addr} missing from ignition_timing_labels.json"
        assert entry["alias"] == alias, f"{addr}: JSON alias {entry['alias']!r}"
        assert entry.get("evidence", "").strip(), f"{addr}: JSON evidence empty"
        assert f"0x{store[0]:x}" in entry["evidence"], f"{addr}: JSON evidence lacks store 0x{store[0]:x}"
