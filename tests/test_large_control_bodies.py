"""Identify and label the seven large unlabeled control bodies.

Static binary-level checks for the labels applied in this pass:
  0x3fb9e o2_response_monitor_accumulate   (slow-task batch 0x38f3e)
  0x4128e o2_response_monitor_evaluate     (P0133 path: id 0x1c -> slot 0x1b)
  0x4ca7e cruise_speed_error_filter_stage   (batch 0x2e692 in task[10] 0x11744)
  0x2d83c cruise_set_speed_adjust_integrator (batch 0x2e5c6 in slow task 0x11534)
  0x23844 e2ram_block_decode                (load entry 0x2376c)
  0x244bc e2ram_block_encode                (save entry 0x2377a)
  0x1506c idle_target_rpm_calculate         (idle task 0x167c0 <- 0x11744)
  0x2a4f8 hcan_mailbox_config_compare       (ref_canSetup 0xd9f4)

Asserts: (a) call-site pool words + jsr addresses in the disassembly, (b) ROM
bytes for descriptors / literals / DTC chain / task table, (c) the new labels
are present in function_index.tsv, symbols.tsv and the accepted TSVs, and the
labels-pass JSON covers exactly the new TSV rows (mirrors verify_claims.py).

Run: python -m pytest tests/test_large_control_bodies.py
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
    "0004ca7e": "cruise_speed_error_filter_stage",
    "0002d83c": "cruise_set_speed_adjust_integrator",
    "00023844": "e2ram_block_decode",
    "000244bc": "e2ram_block_encode",
    "0001506c": "idle_target_rpm_calculate",
    "0002a4f8": "hcan_mailbox_config_compare",
    "0002376c": "e2ram_load_decode_entry",
    "0002377a": "e2ram_save_encode_entry",
    "00023f4e": "e2ram_stored_dtc_replay",
    "000242ae": "e2ram_fault_status_collect",
    "0004c828": "cruise_switch_code_decode",
    "0002df62": "cruise_set_speed_apply",
}
EXPECTED_RAM = {
    "ffffc6f0": "o2_monitor_ratio_ch0",
    "ffffc6f4": "o2_monitor_ratio_ch1",
    "ffffc780": "o2_monitor_ratio_ch2",
    "ffffc784": "o2_monitor_ratio_ch3",
    "ffffc701": "o2_monitor_fluctuation_detected",
    "ffffc708": "o2_channel_afr_fast",
    "ffffc710": "o2_channel_lambda_slow",
    "ffffb440": "e2ram_staging_block",
    "ffffb478": "e2ram_read_staging",
    "ffffb47a": "e2ram_payload_raw",
    "ffffb4ec": "stored_dtc_flag_bits",
    "ffffa7f4": "idle_target_rpm",
    "ffffbd08": "cruise_set_speed_adjust",
    "ffffbcf8": "cruise_set_speed",
    "ffffbaed": "cruise_switch_code",
    "ffffcef4": "cruise_filtered_speed_error",
    "ffffcee4": "cruise_speed_error_mean12",
}


def test_labels_in_function_index():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""), delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert idx.get(addr) == name, f"{addr}: {idx.get(addr)!r} != {name!r}"


def test_ram_aliases_in_symbols():
    syms = {r["address"]: r["name"] for r in
            csv.DictReader(open(os.path.join(DEC, "symbols.tsv"), newline="", encoding="utf-8",
                                errors="surrogateescape"), delimiter="\t")}
    for addr, alias in EXPECTED_RAM.items():
        assert syms.get(addr) == f"{alias}_{addr}", f"{addr}: {syms.get(addr)!r}"


def test_accepted_tsv_rows():
    fn = {r["address"]: r["alias"] for r in
          csv.DictReader(open(os.path.join(INV, "source_review", "accepted_function_aliases.tsv"),
                              newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    ram = {r["address"]: r["alias"] for r in
           csv.DictReader(open(os.path.join(INV, "source_review", "accepted_ram_aliases.tsv"),
                               newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    for addr, name in EXPECTED_FN.items():
        assert fn.get(addr) == name
    for addr, alias in EXPECTED_RAM.items():
        assert ram.get(addr) == alias


def test_labels_json_covers_tsv_rows():
    data = json.load(open(os.path.join(LAB, "large_control_bodies_labels.json")))
    for addr, entry in data["function_aliases"].items():
        assert addr in EXPECTED_FN and EXPECTED_FN[addr] == entry["alias"]
    for addr, entry in data["ram_aliases"].items():
        assert addr in EXPECTED_RAM and EXPECTED_RAM[addr] == entry["alias"]
    assert len(data["function_aliases"]) == len(EXPECTED_FN)
    assert len(data["ram_aliases"]) == len(EXPECTED_RAM)


def test_call_site_pool_words():
    # (pool_addr, expected_target, mov_addr): mov.l @(pool,pc),rN at mov_addr, jsr @rN at mov_addr+2
    for pool, target, mov in ((0x390B0, 0x3FB9E, 0x38F72), (0x2E7DC, 0x4CA7E, 0x2E6C6),
                              (0x2E790, 0x2D83C, 0x2E63C), (0x237BC, 0x23844, 0x2376E),
                              (0x237C8, 0x244BC, 0x23796), (0x168AC, 0x1506C, 0x167FA)):
        assert u32(pool) == target, hex(pool)
        assert f"@ (0x{pool:x},pc)" in asm_line(mov).replace(" ", "") or f"@(0x{pool:x},pc)" in asm_line(mov)
        assert "jsr" in asm_line(mov + 2)
    # direct jsr @r2 / @r13 sites
    assert "jsr" in asm_line(0x38F74)
    assert u32(0xDB20) == 0x2A4F8 and "jsr" in asm_line(0xDA3E) and "jsr" in asm_line(0xDA4E)


def test_task_table_entries():
    assert u32(0x4990 + 10 * 16 + 8) == 0x64F6   # task[10] -> 0x11744 (idle + cruise batch)
    assert u32(0x4990 + 18 * 16 + 8) == 0x64E8   # task[18] -> slow task 0x11534


def test_o2_monitor_rom_anchors():
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


def test_idle_and_cruise_descriptors():
    for d in (0x6935C, 0x69370, 0x693D4, 0x693E8, 0x693FC, 0x69410):
        n, typ, res, ax, data = struct.unpack(">HBBII", ROM[d:d + 12])
        assert 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000 and typ in (0, 4, 8, 12, 16)
    # cruise 2-D descriptors (0x6a880-0x6a8b0, 0x6bc40-0x6bc70) and 3-D (0x6a8d0-0x6a920)
    for d in list(range(0x6A880, 0x6A8B0 + 1, 12)) + list(range(0x6BC40, 0x6BC70 + 1, 12)):
        n, typ, res, ax, data = struct.unpack(">HBBII", ROM[d:d + 12])
        assert 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000
    for d in range(0x6A8D0, 0x6A920 + 1, 20):
        nx, ny, ax, ay, data, typ = struct.unpack(">HHIIIB", ROM[d:d + 17])
        assert 0x6C000 <= ax < 0x80000 and 0x6C000 <= data < 0x80000


def test_hcan_compare_anchors():
    rec = ROM[0x4E01C:0x4E01C + 16]
    assert rec[:4] == struct.pack(">I", 0x201)      # first mailbox id 0x201
    # register symbols exist with these addresses
    syms = open(os.path.join(DEC, "symbols.tsv"), encoding="utf-8", errors="surrogateescape").read()
    for addr, name in (("ffffe402", "HCAN0_BCR_W"), ("ffffe602", "HCAN1_BCR_W"),
                       ("ffffe414", "HCAN0_MBIMR_W"), ("ffffe416", "HCAN0_IMR_W"),
                       ("ffffe41e", "HCAN0_LAFMH_W"), ("ffffe61e", "HCAN1_LAFMH_W"),
                       ("ffffe420", "HCAN0_MC0[1]_B")):
        assert f"{addr}\t{name}\t" in syms
