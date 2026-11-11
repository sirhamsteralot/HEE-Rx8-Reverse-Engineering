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
    # follow-up pass (reviews/cruise_control/): gear/band chain, set-speed
    # latch, TP% calc, control-law output, enable flag, plausibility stages
    "0004de1c": "gear_float_band_producer",
    "0002c324": "candidate_gear_from_ratio",
    "0002c3b2": "gear_latch_confirm",
    "00032614": "cruise_set_speed_latch",
    "000193c4": "throttle_percent_and_demand_calc",
    "0002d638": "cruise_control_output_law",
    "0004c896": "cruise_enable_pedal_override",
    "0004d700": "cruise_switch_plausibility_timers",
    "0004db22": "cruise_plausibility_stage",
}
EXPECTED_RAM = {
    "ffffbaed": "cruise_switch_code",
    "ffffbcf8": "cruise_output_percent",
    "ffffbd08": "cruise_output_integrator",
    "ffffcef4": "cruise_filtered_speed_error",
    "ffffcee4": "cruise_speed_error_mean12",
    "ffffbd00": "cruise_control_law_output",
    "ffffcf1c": "current_gear_float",
    "ffffbc3d": "current_gear",
    "ffffbc3c": "candidate_gear",
    "ffffa9b4": "throttle_position_1_percent",
    "ffffa9b8": "throttle_position_2_percent",
    "ffff866c": "cruise_set_speed_kmh",
    "ffffbfa4": "cruise_target_speed_kmh",
    "ffffcf34": "cruise_enable_flag",
}
# RAM cells whose export symbol (symbols.tsv) still carries the pre-correction
# name; the corrected alias lives in the label TSV/JSON and the export symbol is
# renamed by the next re-runnable pipeline pass (integrate_reviewed_names.py).
EXPORT_SYMBOL_PENDING = {"ffffbcf8", "ffffbd08"}


def test_labels_in_artifacts():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""), delimiter="\t")}
    # function_index.tsv carries only the 4 originally renamed bodies; the
    # follow-up functions still show FUN_ there until the next pipeline pass
    # (their accepted aliases live in the TSV + labels JSON, asserted below)
    for addr, name in list(EXPECTED_FN.items())[:4]:
        assert idx.get(addr) == name, f"{addr}: {idx.get(addr)!r} != {name!r}"
    syms = {r["address"]: r["name"] for r in
            csv.DictReader(open(os.path.join(DEC, "symbols.tsv"), newline="", encoding="utf-8",
                                errors="surrogateescape"), delimiter="\t")}
    # symbols.tsv only carries the 5 originally labeled cells (the 2 corrected
    # ones still show the old export name until the pipeline re-run; the new
    # cells are DAT_ there) - label source of truth is the TSV + JSON below
    for addr, alias in list(EXPECTED_RAM.items())[:5]:
        if addr not in EXPORT_SYMBOL_PENDING:
            assert syms.get(addr) == f"{alias}_{addr}", f"{addr}: {syms.get(addr)!r}"
    fn = {r["address"]: r["alias"] for r in
          csv.DictReader(open(os.path.join(INV, "source_review", "accepted_function_aliases.tsv"),
                              newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    ram = {r["address"]: r["alias"] for r in
           csv.DictReader(open(os.path.join(INV, "source_review", "accepted_ram_aliases.tsv"),
                               newline="", encoding="utf-8", errors="surrogateescape"), delimiter="\t")}
    data = json.load(open(os.path.join(LAB, "cruise_control_labels.json")))
    for addr, name in EXPECTED_FN.items():
        assert fn.get(addr) == name
        assert data["function_aliases"][addr]["alias"] == name
    for addr, alias in EXPECTED_RAM.items():
        assert ram.get(addr) == alias
        assert data["ram_aliases"][addr]["alias"] == alias
    # the per-body labels JSON covers exactly this subsystem's rows
    assert len(data["function_aliases"]) == len(EXPECTED_FN)
    assert len(data["ram_aliases"]) == len(EXPECTED_RAM)


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


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


def test_followup_binary_anchors():
    """Binary-level anchors for the follow-up findings (reviews/cruise_control/):
    0x4de1c gear->cf1c producer, gear-ratio thresholds, TP% constants,
    0x2df62 percent clamp, switch decode pools."""
    # 0x4de1c: store pool word cf1c + gear byte bc3d, config byte, decode fn,
    # band floats 3.0..6.0; ROM config byte 0x7d07f = 0 disables switch-code map
    assert u32(0x4DEDC) == 0xCF1CBC3D          # pools: cf1c (store), bc3d (read)
    assert u32(0x4DEF4) == 0x0007D07F           # config byte address
    assert ROM[0x7D07F] == 0x00
    assert u32(0x4DEF8) == 0x00002500           # rx8_decode_u8_affine
    assert u32(0x4DEFC) == 0x40400000 and u32(0x4DF08) == 0x40C00000  # 3.0 / 6.0
    # 0x4c828 switch decode: baed -> cf47..cf4c
    for i, off in enumerate(range(0x4C900, 0x4C90C, 2)):
        assert u16(off) == 0xCF47 + i
    assert u16(0x4C8FE) == 0xBAED
    # 0x2c3b2 gear latch pools: bc3c / b534 / b53a / bc3d
    for off, v in ((0x2C3D8, 0xBC3C), (0x2C3DA, 0xB534), (0x2C3DC, 0xB53A), (0x2C3DE, 0xBC3D)):
        assert u16(off) == v
    # 0x2c324 gear-ratio thresholds (rpm per km/h): 110.741, 71.887, 52.001, 40.158, 33.841
    ratios = [struct.unpack(">f", ROM[a:a + 4])[0] for a in range(0x758B8, 0x758CC, 4)]
    assert [round(r, 3) for r in ratios] == [110.741, 71.887, 52.001, 40.158, 33.841]
    # 0x2df62 percent-output clamp: store pool bcf8; clamp bounds via ptr pools
    # 0x2e048 -> ROM 0x767e4 = 100.0, 0x2e04c -> ROM 0x767e0 = 0.0
    assert u16(0x2E004) == 0xBCF8
    assert u32(0x2E048) == 0x767E4 and u32(0x767E4) == 0x42C80000   # 100.0
    assert u32(0x2E04C) == 0x767E0 and u32(0x767E0) == 0x00000000    # 0.0
    # TP% chain constants: 6.341 scale (0x94f0 ROM refs), 12.7 span, 10.856 learned zero
    assert u32(0x6EEB8) == 0x40CAE979 and u32(0x6EEC0) == 0x00000000
    assert u32(0x6EF18) == 0x414B3333           # 12.7
    assert u32(0x6EF00) == 0x412DB22D           # 10.856
    # call-site pools for the follow-up functions
    for pool, target, mov in (
        (0x2E748, 0x4DE1C, 0x2E5D0),   # 0x4de1c <- batch 0x2e5c6
        (0x2E77C, 0x32614, 0x2E61E),   # 0x32614 <- batch 0x2e5c6
        (0x2E78C, 0x2D638, 0x2E636),   # 0x2d638 <- batch 0x2e5c6
        (0x2E7C8, 0x4C896, 0x2E6A2),   # 0x4c896 <- batch 0x2e692
        (0x2E7E4, 0x4D700, 0x2E6D2),   # 0x4d700 <- batch 0x2e692
        (0x2E7E8, 0x4DB22, 0x2E6D8),   # 0x4db22 <- batch 0x2e692
        (0x19C84, 0x2C324, 0x19AD4),   # 0x2c324 <- 0x19aa0
        (0x19C88, 0x2C3B2, 0x19ADA),   # 0x2c3b2 <- 0x19aa0
    ):
        assert u32(pool) == target, hex(pool)
        assert f"@(0x{pool:x},pc)" in asm_line(mov).replace(" ", "")
        assert "jsr" in asm_line(mov + 2)
