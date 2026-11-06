"""E2RAM non-volatile storage codec: static binary-level checks for 0x23844
e2ram_block_decode (load entry 0x2376c), 0x244bc e2ram_block_encode (save entry
0x2377a), 0x23f4e e2ram_stored_dtc_replay, 0x242ae e2ram_fault_status_collect.

Asserts call-site pool words + jsr addresses, ROM bytes for the magic/checksum/
write pools, the load-side magic compare, the codec affine-step float pools,
and that the new labels are present in function_index.tsv, symbols.tsv, the
accepted TSVs and the labels JSON.
Run: python -m pytest tests/test_e2ram_nv_storage.py
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


def asm_line(addr):
    for l in ASM:
        if l.startswith(f"{addr:08x} "):
            return l
    raise AssertionError(f"no disassembly line at 0x{addr:x}")


EXPECTED_FN = {
    "00023844": "e2ram_block_decode",
    "000244bc": "e2ram_block_encode",
    "0002376c": "e2ram_load_decode_entry",
    "0002377a": "e2ram_save_encode_entry",
    "00023f4e": "e2ram_stored_dtc_replay",
    "000242ae": "e2ram_fault_status_collect",
}
EXPECTED_RAM = {
    "ffffb440": "e2ram_staging_block",
    "ffffb478": "e2ram_read_staging",
    "ffffb47a": "e2ram_payload_raw",
    "ffffb4ec": "stored_dtc_flag_bits",
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
    data = json.load(open(os.path.join(LAB, "e2ram_nv_storage_labels.json")))
    for addr, name in EXPECTED_FN.items():
        assert fn.get(addr) == name
        assert data["function_aliases"][addr]["alias"] == name
    for addr, alias in EXPECTED_RAM.items():
        assert ram.get(addr) == alias
        assert data["ram_aliases"][addr]["alias"] == alias
    # the per-body labels JSON covers exactly this subsystem's rows
    assert len(data["function_aliases"]) == 6
    assert len(data["ram_aliases"]) == 4


def test_call_site_pool_words():
    # (pool_addr, expected_target, mov_addr): mov.l @(pool,pc),rN at mov_addr, jsr @rN at mov_addr+2
    for pool, target, mov in ((0x237BC, 0x23844, 0x2376E), (0x237C8, 0x244BC, 0x23796)):
        assert u32(pool) == target, hex(pool)
        assert f"@(0x{pool:x},pc)" in asm_line(mov).replace(" ", "")
        assert "jsr" in asm_line(mov + 2)


def test_e2ram_block_rom_anchors():
    assert u32(0x23734) & 0xFFFF == 0xA55A          # magic written at 0x236ec
    assert u32(0x23738) == 0xB886                   # E2RAM write call in 0x236cc
    assert u32(0x2372C) == 0x2377A                  # save encode entry
    assert u16(0x23726) == 0xB440                   # staging base 0xffffb440
    assert u16(0x236AC) == 0x5AA5                   # load-side magic compare (0x235f8)
    # checksum loop 0x236f0-0x236fe sums 0x1b u16 (r6 = 0x1b set at 0x236de)
    assert "0x1b" in asm_line(0x236DE) and "jsr" in asm_line(0x2370A)
    # codec affine-step floats in literal pools (mova sites -> pool words)
    for mov, pool, word in ((0x2385A, 0x23918, 0x3CFA0000), (0x23F10, 0x24004, 0x38A00000),
                            (0x2389C, 0x23938, 0x3DA00000), (0x238B0, 0x2393C, 0x3F480000),
                            (0x244C0, 0x2452C, 0x3CFA0000), (0x24554, 0x24684, 0x39A00000),
                            (0x24AD8, 0x24B3C, 0x3B800000), (0x24AEC, 0x24B40, 0x3E480000)):
        assert u32(pool) == word, hex(pool)
        assert f"0x{pool:x}" in asm_line(mov).replace(" ", "")
