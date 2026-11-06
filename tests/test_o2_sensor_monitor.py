"""O2 sensor (front HO2S) response monitor: static binary-level checks for
0x3fb9e o2_response_monitor_accumulate, 0x4128e o2_response_monitor_evaluate
(P0133 path: fault id 0x1c -> slot 0x1b -> code 0x0133), 0x3f924
o2_channel_filter_update (slow-task batch 0x38f3e).

Asserts call-site pool words + jsr addresses in the disassembly, ROM bytes for
the 3-D descriptors / 1e-5 tolerance / DTC chain, and that the new labels are
present in function_index.tsv, symbols.tsv, the accepted TSVs and the labels
JSON. Run: python -m pytest tests/test_o2_sensor_monitor.py
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


def u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


def asm_line(addr):
    for l in ASM:
        if l.startswith(f"{addr:08x} "):
            return l
    raise AssertionError(f"no disassembly line at 0x{addr:x}")


EXPECTED_FN = {
    "0003fb9e": "o2_response_monitor_accumulate",
    "0004128e": "o2_response_monitor_evaluate",
    "0003f924": "o2_channel_filter_update",
}
EXPECTED_RAM = {
    "ffffc6f0": "o2_monitor_ratio_ch0",
    "ffffc6f4": "o2_monitor_ratio_ch1",
    "ffffc780": "o2_monitor_ratio_ch2",
    "ffffc784": "o2_monitor_ratio_ch3",
    "ffffc701": "o2_monitor_fluctuation_detected",
    "ffffc708": "o2_channel_afr_fast",
    "ffffc710": "o2_channel_lambda_slow",
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
    assert u32(0x390B0) == 0x3FB9E
    assert "@(0x390b0,pc)" in asm_line(0x38F72).replace(" ", "")
    assert "jsr" in asm_line(0x38F74)
    # evaluate 0x4128e: pool loaded at 0x38f78, jsr at 0x38f7a
    m = re.search(r"@\(0x([0-9a-f]+),pc\)", asm_line(0x38F78))
    assert m and u32(int(m.group(1), 16)) == 0x4128E
    assert "jsr" in asm_line(0x38F7A)


def test_monitor_rom_anchors():
    # 3-D descriptor 0x6b66c (load x rpm)
    nx, ny, ax, ay, data, typ = struct.unpack(">HHIIIB", ROM[0x6B66C:0x6B66C + 17])
    assert (nx, ny, typ) == (9, 9, 0) and 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000
    assert (ax, ay, data) == (0x7AD48, 0x7AD6C, 0x7AD90)
    # threshold descriptors: 0x6b680/0x6b69c are 9x9 u16, 0x6b6b8/0x6b6d4 are 1x1 constants
    for d in (0x6B680, 0x6B69C):
        nx, ny, ax, ay, data, typ = struct.unpack(">HHIIIB", ROM[d:d + 17])
        assert (nx, ny, typ) == (9, 9, 8) and 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000
    assert struct.unpack(">HHIIIB", ROM[0x6B680:0x6B680 + 17])[2:5] == (0x7AE34, 0x7AE58, 0x7AE7C)
    for d in (0x6B6B8, 0x6B6D4):
        nx, ny, ax, ay, data, typ = struct.unpack(">HHIIIB", ROM[d:d + 17])
        assert (nx, ny, typ) == (1, 1, 8) and u16(data) == 0  # constant threshold (scaled: 0*mult-1.0)
    # tolerance float 1e-5 via mova pool 0x41220
    assert u32(0x41220) == 0x3727C5AC and "mova @(0x41220,pc)" in asm_line(0x41140)
    for a in (0x41156, 0x4116A, 0x4117E):
        assert "mova" in asm_line(a) and "0x41220" in asm_line(a)
    # fault chain: id 0x1c -> slot 0x1b -> code 0x0133 (P0133)
    assert u16(0x7DF42 + 2 * 0x1C) == 0x1B
    assert u16(0x7E560 + 2 * 0x1B) == 0x0133
