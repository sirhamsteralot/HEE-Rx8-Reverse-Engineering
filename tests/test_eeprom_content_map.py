"""93C56 EEPROM (IC420) content map: static binary-level checks for the
60E15120_N3J1E content map (eeprom_content_map_report.md).

Asserts the upstream 256-B dump facts (VIN, tire revs, markers, immo key
area, learned table, erased ranges) and the ROM-side evidence (magic pools,
call pools, boot-param table of 0x3599c, immo word reads in 0x375c0, learned
table affine pools, mirror-window literal reference count), plus the labels
JSON contents.
Run: python -m pytest tests/test_eeprom_content_map.py
"""
import glob
import json
import os
import re
import struct

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
ROM_PATH = os.path.join(
    ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Stock_ROMs", "60E15120_N3J1E.bin")
RX8_PATH = os.path.join(
    ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Data_binaries", "RX8_93c56_ECU_IC420_Read.bin")
SE3_PATH = os.path.join(
    ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Data_binaries", "se3p_ecm_eeprom.bin")
DEC = os.path.join(ROOT, "reverse-engineered", "decompiled", "60E15120_N3J1E")
DIS = os.path.join(ROOT, "reverse-engineered", "disassembly", "60E15120_N3J1E")
LAB = os.path.join(ROOT, "data", "labels", "60E15120_N3J1E",
                   "eeprom_content_labels.json")

ROM = open(ROM_PATH, "rb").read()
RX8 = open(RX8_PATH, "rb").read()
SE3 = open(SE3_PATH, "rb").read()
ASM = open(os.path.join(DIS, "firmware_disassembly.asm"), encoding="latin-1").read().splitlines()


def u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


def test_rom_and_dump_hashes():
    import hashlib
    assert len(ROM) == 0x80000
    assert hashlib.sha256(ROM).hexdigest() == (
        "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1")
    assert len(RX8) == 256 and len(SE3) == 256
    assert hashlib.sha256(RX8).hexdigest() == (
        "64b13ddf353a06976729114179204f56b7a2869ea891f3f9d9400a2a56d205e3")
    assert hashlib.sha256(SE3).hexdigest() == (
        "d7f4bb0a289f086610d8a9aafac58f6329b96c5be96ec75f7aef7418cf77c264")


def test_dump_header_and_markers():
    assert RX8[0:2] == b"\x5a\xff" and SE3[0:2] == b"\x5a\xff"
    assert RX8[0x95] == 0x2A and SE3[0x95] == 0x2A          # tire-size marker '*'
    assert RX8[0xff] == 0x30 and SE3[0xff] == 0x30          # fixed tail marker
    assert RX8[0xfe] == 0xFF and SE3[0xfe] == 0xFF
    # no 28-u16 block magic a55a/5aa5 inside the IC420 image
    for d in (RX8, SE3):
        assert not any(d[i:i + 2] in (b"\xa5\x5a", b"\x5a\xa5") for i in range(254))


def test_dump_vin_and_tire_fields():
    assert RX8[0x80:0x91] == b"JM1FE173940102548"
    assert SE3[0x80:0x8A] == b"SE3P104621"
    assert struct.unpack(">H", RX8[0x9A:0x9C])[0] == 0x030D   # 781 rev/mile
    assert struct.unpack(">H", SE3[0x9A:0x9C])[0] == 0x030D
    assert RX8[0x9F] == 0xFE and SE3[0x9F] == 0xFF


def test_dump_id_string_and_erased_ranges():
    assert RX8[0x64:0x67] == b"13H" and RX8[0x68] == ord("6") and RX8[0x6A:0x6D] == b"020"
    assert SE3[0x64:0x67] == b"13H" and SE3[0x6A:0x6D] == b"0A0"
    assert all(b == 0xFF for b in RX8[0xA0:0xFC])
    assert all(b == 0xFF for b in SE3[0xA0:0xFC])


def test_dump_per_ecu_diff_regions():
    diff = [i for i in range(256) if RX8[i] != SE3[i]]
    # key 0x02-0x09, immo code 0x16-0x19, learned table 0x20-0x63, id char 0x6b,
    # VIN 0x80-0x90, config 0x9f, tail 0xfc-0xfd
    for lo, hi in ((0x02, 0x0A), (0x16, 0x1A), (0x20, 0x64), (0x80, 0x91), (0xFC, 0xFE)):
        assert any(lo <= i < hi for i in diff)
    assert 0x9F in diff
    # param/config bytes 0x0a-0x15 and 0x1a-0x1f identical across dumps
    for i in list(range(0x0A, 0x16)) + list(range(0x1A, 0x20)):
        assert RX8[i] == SE3[i], hex(i)


def test_learned_table_decode():
    for i in range(0x22):
        raw, flag = RX8[0x20 + 2 * i], RX8[0x21 + 2 * i]
        value = -63.0 + raw * 0.5
        assert -63.0 <= value <= 64.5
        assert flag in (0x00, 0x01)
    assert -63.0 + RX8[0x20] * 0.5 == 1.5
    assert -63.0 + RX8[0x5E] * 0.5 == -45.0
    # SE3P learned table erased (ff 00 pairs)
    assert all(SE3[0x20 + 2 * i] == 0xFF for i in range(0x22))


def test_mirror_magic_pools_and_calls():
    assert u16(0xD4EA) == 0x55AA          # magic written by 0xd408
    assert u32(0xD4F4) == 0x0000AA55      # magic written/checked by 0xd44c/0xd408
    assert u32(0xD4F0) == 0xFFFF8000      # mirror base
    assert u32(0xD4EC) == 0xFFFFA3FB      # status flag
    assert u32(0x6288) == 0x0000D44C      # ref_mainInit__ 0x61a8 calls 0xd44c
    assert u32(0x63E8) == 0x0000D408      # 0x6372 calls 0xd408
    assert u32(0x63DC) == 0x00011492      # 0x9f4c -> 0x6360 -> 0x11492
    assert u32(0x11674) == 0x0003E020 and u32(0x11678) == 0x0000D2E8


def test_boot_param_table_0x3599c():
    # 19 e2ram_cached_byte_read calls: parse mov #idx,r4 / mov #len,r6 / pool r5
    params = []
    idx = ln = None
    for l in ASM:
        if not (0x3599C <= int(l[0:8], 16) <= 0x35A3E):
            continue
        m4 = re.search(r"mov #0x([0-9a-f]+),r4", l)
        m6 = re.search(r"mov #0x([0-9a-f]+),r6", l)
        mp = re.search(r"mov\.[wl] @\((0x[0-9a-f]+),pc\),r5", l)
        if m4:
            idx = int(m4.group(1), 16)
        if m6:
            ln = int(m6.group(1), 16)
        if mp:
            pool = int(mp.group(1), 16)
            dest = u32(pool) if "mov.l" in l else (u16(pool) | 0xFFFF0000)
            params.append((idx, dest, ln))
    assert len(params) == 19
    dests = [p[1] for p in params]
    assert dests[0] == 0xFFFFC268 and dests[1] == 0xFFFFC26C and dests[2] == 0xFFFFC270
    assert all(0xFFFFC268 <= d <= 0xFFFFC282 or 0xFFFFC1D2 <= d <= 0xFFFFC1D4 for d in dests)
    idxs = [p[0] for p in params[1:]]
    assert idxs == [0, 2, 6, 0xA, 0xC, 0xD, 0xE, 0xF, 0x10, 0x16, 0x18, 0x12, 0x13, 0x14, 0x1A, 0x1B, 0x1C, 0x1D]


def test_immo_key_reads_0x375c0():
    src = open(os.path.join(DEC, "functions", "000375c0_FUN_000375c0.c"),
               encoding="latin-1").read()
    words = set(re.findall(r"e2ram_read_word\((0x[0-9a-f]+)\)", src))
    assert words == {"0x6010000", "0x6020000", "0x6030000", "0x6040000",
                     "0x6050000", "0x60b0000", "0x60c0000"}


def test_learned_table_affine_pools():
    assert u32(0x27C80) == 0xC27C0000     # -63.0 offset
    assert u32(0x27C84) == 0x3F000000     # 0.5 units/count
    assert struct.unpack(">f", ROM[0x27C80:0x27C84])[0] == -63.0
    assert struct.unpack(">f", ROM[0x27C84:0x27C88])[0] == 0.5


def test_cached_byte_read_index_uses():
    allf = ""
    for fn in glob.glob(os.path.join(DEC, "functions", "*.c")):
        allf += open(fn, encoding="latin-1").read()
    uses = set(re.findall(r"e2ram_cached_byte_read\((0x[0-9a-f]+|\d+)", allf))
    flat = uses
    for expect in ("0x80", "0x95", "0x9a", "0x9f", "0x6e", "0x68", "0x6a", "0x6c", "0x78", "0x7a", "100"):
        assert expect in flat, expect


def test_mirror_window_literal_refs():
    pat = re.compile(r"^([0-9a-f]{8})\s+[0-9a-f]{4}\s+mov\.[wl] @\((0x[0-9a-f]+),pc\),r\d+")
    offs = set()
    n = 0
    for line in ASM:
        m = pat.match(line)
        if not m:
            continue
        pool = int(m.group(2), 16)
        if "mov.l" in line:
            v = u32(pool)
            if 0xFFFF8000 <= v <= 0xFFFF80FF:
                n += 1
                offs.add(v - 0xFFFF8000)
        else:
            v = u16(pool)
            if 0x8000 <= v <= 0x80FF:
                n += 1
                offs.add(v - 0x8000)
    assert n == 241
    for off in (0x00, 0x38, 0x40, 0x48, 0x68, 0x7C, 0x80 + 0x2C, 0xC4, 0xEC, 0xFC):
        assert off in offs, hex(off)


def test_labels_json_present():
    d = json.load(open(LAB, encoding="utf-8"))
    offs = d["eeprom_offsets"]
    assert "JM1FE173940102548" in offs["0x80-0x90"]["evidence"]
    assert offs["0x9a-0x9b"]["alias"] == "eeprom_tire_revolutions_per_mile"
    assert offs["0x02-0x09"]["alias"] == "eeprom_immobilizer_secret_key"
    assert offs["0x20-0x63"]["alias"] == "e2ram_learned_correction_table"
    fa = d["function_aliases"]
    assert fa["000375c0"]["alias"] == "e2ram_immo_key_read"
    assert fa["00027b8e"]["alias"] == "e2ram_learned_table_load"
    assert fa["000279d8"]["alias"] == "e2ram_learned_table_save"
    assert fa["0000d408"]["alias"] == "eeprom_mirror_magic_check"
    assert d["ram_aliases"]["ffff8000"]["alias"] == "eeprom_mirror_magic"
    assert d["ram_aliases"]["ffff8108"]["alias"] == "e2ram_learned_table_value_pos"
    assert d["rom_unchanged"] is True
    # the accepted TSVs carry the same rows (pipeline source of truth)
    fn_rows = open(os.path.join(
        ROOT, "docs/investigations/60E15120_N3J1E/labeling/source_review",
        "accepted_function_aliases.tsv"), encoding="utf-8").read()
    assert "000375c0\te2ram_immo_key_read" in fn_rows
    assert "0000d408\teeprom_mirror_magic_check" in fn_rows
    ram_rows = open(os.path.join(
        ROOT, "docs/investigations/60E15120_N3J1E/labeling/source_review",
        "accepted_ram_aliases.tsv"), encoding="utf-8").read()
    assert "ffff8000\teeprom_mirror_magic" in ram_rows
    # and the export index carries the aliases
    idx = open(os.path.join(DEC, "function_index.tsv"), encoding="latin-1").read()
    assert "000375c0\te2ram_immo_key_read" in idx
    assert "00027b8e\te2ram_learned_table_load" in idx
    assert "0000d408\teeprom_mirror_magic_check" in idx


def f32(a):
    return struct.unpack(">f", ROM[a:a + 4])[0]


# --- learned-table per-index semantics (chip 0x20-0x63), binary-level ---

# RX8 dump decode, pair i -> (value, flag) with value = -63 + raw*0.5
RX8_LEARNED = [
    (1.5, 1), (1.0, 1), (0.0, 1), (-1.5, 1), (-4.0, 1), (-5.0, 1), (-6.5, 1),
    (-10.0, 1), (-11.5, 1), (-16.5, 1), (-18.5, 1),
    (0.0, 0), (0.0, 0), (0.0, 0), (0.0, 0), (0.0, 0), (0.0, 0),
    (1.5, 1), (1.0, 1), (1.0, 1), (-2.0, 1), (-5.0, 1), (-6.0, 1), (-7.0, 1),
    (-10.5, 1), (-11.5, 1), (-16.0, 1), (-18.0, 1), (-23.0, 1), (-25.5, 1),
    (-33.5, 1), (-45.0, 1), (0.0, 0), (0.0, 0),
]


def test_learned_table_pair_decode_and_diff():
    assert len(RX8_LEARNED) == 0x22
    for i, (val, flag) in enumerate(RX8_LEARNED):
        raw, fl = RX8[0x20 + 2 * i], RX8[0x21 + 2 * i]
        assert -63.0 + raw * 0.5 == val, i
        assert fl == flag, i
        # SE3P learned table fully erased
        assert SE3[0x20 + 2 * i] == 0xFF and SE3[0x21 + 2 * i] == 0x00, i
    # the 0x20-0x63 region is per-ECU learned data (differs RX8 vs SE3P on
    # every value byte 0x20..0x62 even and every differing flag byte; the
    # zero-flag bytes 0x37,0x39,...,0x41,0x61,0x63 match SE3P's 0x00)
    diffs = [i for i in range(0x20, 0x64) if RX8[i] != SE3[i]]
    assert diffs == list(range(0x20, 0x37)) + list(range(0x38, 0x42, 2)) + \
        list(range(0x42, 0x60)) + [0x60, 0x62]


def test_learned_table_cell_index_pools():
    # 0x2711a: cell = rpm_cell + 17*load_band
    assert u32(0x2716C) == 0x0006A694          # tbl 2D #332 descriptor
    assert u32(0x2724C) == 0x00002460           # rx8_add_u16_saturate
    assert abs(f32(0x755A4) - 0.4) < 1e-6 and abs(f32(0x755A8) - 0.65) < 1e-6
    assert f32(0x755AC) == 3.0
    # descriptor geometry: 17 cells, type 0
    assert u16(0x6A694) == 17 and ROM[0x6A696] == 0
    assert u32(0x6A698) == 0x000755DC and u32(0x6A69C) == 0x00075620
    assert u16(0x6A6A0) == 17 and ROM[0x6A6A2] == 0
    assert u32(0x6A6A4) == 0x00075644 and u32(0x6A6A8) == 0x00075688
    # axis/data content (ROM-verified arrays)
    assert [f32(0x755DC + 4 * i) for i in range(17)] == [
        0.0, 1125.0, 1750.0, 2250.0, 2750.0, 3250.0, 3750.0, 4250.0, 4750.0,
        5250.0, 5750.0, 6250.0, 6750.0, 7250.0, 7750.0, 8250.0, 8750.0]
    assert [u16(0x75620 + 2 * i) for i in range(17)] == list(range(17))
    assert [f32(0x75644 + 4 * i) for i in range(17)] == [float(i) for i in range(17)]
    assert [f32(0x75688 + 4 * i) for i in range(17)] == [
        750.0, 1500.0, 2000.0, 2500.0, 3000.0, 3500.0, 4000.0, 4500.0, 5000.0,
        5500.0, 6000.0, 6500.0, 7000.0, 7500.0, 8000.0, 8500.0, 9000.0]


def test_learned_table_array_base_pools():
    # value_pos 0xffff8108 / flag_a 0xffff8548 pool locations
    for a in (0x27154, 0x27938, 0x27B48, 0x27C78, 0x27FA4, 0x282B8, 0x2850C):
        assert u32(a) == 0xFFFF8108, hex(a)
    for a in (0x27158, 0x27270, 0x27934, 0x27B44, 0x27C7C, 0x27FA8):
        assert u32(a) == 0xFFFF8548, hex(a)
    # bank strides: value_neg = +0x220, flag_b = +0x88
    assert u16(0x27D3E) == 0x0220 and u16(0x27D40) == 0x0088 and u16(0x284F6) == 0x0220


def test_learned_table_learn_gate_pools():
    # 0x276ec: live arrays + RPM gate + filter constant
    assert u32(0x277F0) == 0xFFFFB8F4          # counter array
    assert u32(0x277F8) == 0xFFFFB6CC          # live value array
    assert f32(0x755D0) == 100.0               # |rpm - breakpoint| gate
    assert abs(f32(0x755D4) - 0.031) < 1e-9    # first-order filter k
    assert u32(0x277FC) == 0x3727C5AC          # eps 1e-5
    # 0x27808 persist: tick + bases + writers
    assert u32(0x2791C) == 0xFFFFBA04          # tick counter (init 0xb)
    assert u32(0x27928) == 0xFFFFB8F4 and u32(0x2792C) == 0xFFFFB6CC
    assert u32(0x27934) == 0xFFFF8548 and u32(0x27938) == 0xFFFF8108
    assert u32(0x27940) == 0x0003DB54          # rx8_first_order_filter
    assert u32(0x27944) == 0x0003DCD0 and u32(0x27948) == 0x0003DC70
    assert u16(0x27A20) == 0x0007              # flag-mirror bitmask for cells 0..2
    assert u32(0x27A24) == 0x000043C8          # shift fn


def test_labels_json_learned_pairs():
    d = json.load(open(LAB, encoding="utf-8"))
    pairs = d["learned_table_pairs"]["pairs"]
    assert len(pairs) == 34
    assert pairs[0]["chip"] == "0x20-0x21" and pairs[0]["rpm_cell"] == 0
    assert pairs[0]["rpm_breakpoint"] == 750 and pairs[0]["load_band"] == 0
    assert pairs[17]["chip"] == "0x42-0x43" and pairs[17]["load_band"] == 1
    assert pairs[33]["rpm_breakpoint"] == 9000 and pairs[33]["load_band"] == 1
    fa = d["function_aliases"]
    for addr, alias in (("0002711a", "e2ram_learned_table_cell_index"),
                        ("000271b0", "e2ram_learned_table_learn_gate"),
                        ("000276ec", "e2ram_learned_table_cell_learn"),
                        ("00027808", "e2ram_learned_table_ram_persist"),
                        ("00027eec", "e2ram_learned_table_flag_mirror"),
                        ("00028198", "e2ram_learned_table_apply"),
                        ("00028484", "e2ram_learned_table_cell_read"),
                        ("00027024", "e2ram_learned_table_clear"),
                        ("000270aa", "e2ram_learned_table_validate"),
                        ("0002837c", "e2ram_learned_table_correction_filter")):
        assert fa[addr]["alias"] == alias, addr
    ra = d["ram_aliases"]
    assert ra["ffffb6c4"]["alias"] == "e2ram_learned_table_cell_index"
    assert ra["ffffb660"]["alias"] == "sector_parity_bank"
    assert ra["ffffb6cc"]["alias"] == "e2ram_learned_table_live_value"
    assert ra["ffffb8f4"]["alias"] == "e2ram_learned_table_live_counter"
    assert ra["ffffba2c"]["alias"] == "e2ram_learned_correction_value"
    # TSV rows exist for the new labels (pipeline source of truth)
    fn_rows = open(os.path.join(
        ROOT, "docs/investigations/60E15120_N3J1E/labeling/source_review",
        "accepted_function_aliases.tsv"), encoding="utf-8").read()
    assert "0002711a\te2ram_learned_table_cell_index" in fn_rows
    assert "00027808\te2ram_learned_table_ram_persist" in fn_rows
    ram_rows = open(os.path.join(
        ROOT, "docs/investigations/60E15120_N3J1E/labeling/source_review",
        "accepted_ram_aliases.tsv"), encoding="utf-8").read()
    assert "ffffb6c4\te2ram_learned_table_cell_index" in ram_rows
    assert "ffffb660\tsector_parity_bank" in ram_rows


def test_learned_table_hooks_to_misfire_dtc():
    # DTC slot table 0x7e560: slots 0/1 = P0300 (both rotors); prefixes 0x7e55a
    assert u16(0x7E560) == 0x0300 and u16(0x7E562) == 0x0300
    assert [u16(0x7E55A + 2 * i) for i in range(4)] == [0x300, 0x301, 0x302, 0x300]
    # 0x44724 (misfire DTC set) calls dtc_set_fault_xdefault via pool 0x447ac
    assert u32(0x447AC) == 0x0005FD3C and u32(0x44D54) == 0x0005FD3C
    # 0x445ba tail-calls 0x44724 (bsr at 0x446ea)
    assert any(l.startswith("000446ea") and "bsr 0x00044724" in l for l in ASM)
    # threshold tables: 12-cell RPM axes 780..8500 (0x6b9f4), Load Limit A/B
    for d in (0x6B9F4, 0x6BA00, 0x6BA0C, 0x6BA18):
        assert u16(d) == 12 and ROM[d + 2] == 0
    assert f32(0x7C43C) == 780.0 and f32(0x7C43C + 4 * 11) == 8500.0
    # labels JSON carries the misfire hook-up aliases
    d = json.load(open(LAB, encoding="utf-8"))
    fa = d["function_aliases"]
    assert fa["00044724"]["alias"] == "misfire_dtc_set"
    assert fa["000445ba"]["alias"] == "misfire_dtc_evaluate"
    assert fa["000447e2"]["alias"] == "misfire_threshold_check_rpm"
    ra = d["ram_aliases"]
    assert ra["ffffba40"]["alias"] == "misfire_excess_deviation"
    assert ra["ffffba24"]["alias"] == "misfire_event_flag_a"
    assert "P0300" in ra["ffffba2c"]["evidence"]
