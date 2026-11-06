"""CAN mailbox configuration compare: static binary-level checks for 0x2a4f8
hcan_mailbox_config_compare (called from ref_canSetup 0xd9f4 in its retry loop).

Asserts the call-site pool word + jsr @r13 sites, the first descriptor record
bytes at 0x4e01c, the HCAN register symbols, and that the new label is present
in function_index.tsv, the accepted TSVs and the labels JSON.
Run: python -m pytest tests/test_can_mailbox_config.py
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
    "0002a4f8": "hcan_mailbox_config_compare",
    # CAN 0x201 TX chain + CAN 0x216 RX unpack (descriptor 0x4df1c, buffer 0xffffbaf4)
    "00029340": "can201_prepare_rpm_with_conditional_filter",
    "00029236": "can201_encode_rpm_u16",
    "0002927c": "can201_encode_vehicle_speed_u16",
    "000291dc": "can201_pack_and_queue_payload",
    "00028eb8": "can216_unpack_mixed_width_fields",
}
EXPECTED_RAM = {
    "ffffbaf4": "can201_tx_payload",
    "ffffbafc": "can201_encoded_rpm",
    "ffffbb00": "can201_encoded_vehicle_speed",
    "ffffbb04": "can201_prepared_engine_rpm",
    "ffffbb08": "can201_previous_engine_rpm",
}


def test_labels_in_artifacts():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""), delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert idx.get(addr) == name, f"{addr}: {idx.get(addr)!r} != {name!r}"
    fn = {r["address"]: r["alias"] for r in
          csv.DictReader(open(os.path.join(INV, "source_review", "accepted_function_aliases.tsv"),
                              newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    data = json.load(open(os.path.join(LAB, "can_mailbox_config_labels.json")))
    for addr, name in EXPECTED_FN.items():
        assert fn.get(addr) == name
        assert data["function_aliases"][addr]["alias"] == name
    ram = {r["address"]: r["alias"] for r in
           csv.DictReader(open(os.path.join(INV, "source_review", "accepted_ram_aliases.tsv"),
                               newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    for addr, name in EXPECTED_RAM.items():
        assert ram.get(addr) == name
        assert data["ram_aliases"][addr]["alias"] == name
    # the per-body labels JSON covers exactly this subsystem's rows
    assert len(data["function_aliases"]) == len(EXPECTED_FN)
    assert len(data["ram_aliases"]) == len(EXPECTED_RAM)


def test_call_site_pool_word():
    # pool 0xdb20 = 0x2a4f8; jsr @r13 at 0xda3e and 0xda4e inside ref_canSetup 0xd9f4
    assert u32(0xDB20) == 0x2A4F8
    assert "jsr" in asm_line(0xDA3E) and "jsr" in asm_line(0xDA4E)


def test_hcan_compare_anchors():
    rec = ROM[0x4E01C:0x4E01C + 16]
    assert rec[:4] == struct.pack(">I", 0x201)      # first mailbox id 0x201
    assert rec == bytes.fromhex("0000020100010800ffffbaf401000000")
    # register symbols exist with these addresses
    syms = open(os.path.join(DEC, "symbols.tsv"), encoding="utf-8", errors="surrogateescape").read()
    for addr, name in (("ffffe402", "HCAN0_BCR_W"), ("ffffe602", "HCAN1_BCR_W"),
                       ("ffffe414", "HCAN0_MBIMR_W"), ("ffffe416", "HCAN0_IMR_W"),
                       ("ffffe41e", "HCAN0_LAFMH_W"), ("ffffe61e", "HCAN1_LAFMH_W"),
                       ("ffffe420", "HCAN0_MC0[1]_B")):
        assert f"{addr}\t{name}\t" in syms
