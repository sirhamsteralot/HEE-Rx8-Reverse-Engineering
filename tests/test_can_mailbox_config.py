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
    # setup / error-recovery chain around ref_canSetup 0xd9f4
    "0000dade": "can_error_full_reset",
    "0002a248": "can_error_supervision_step",
    "00009ac4": "hcan_bus_off_flag",
}
EXPECTED_RAM = {
    "ffffbaf4": "can201_tx_payload",
    "ffffbafc": "can201_encoded_rpm",
    "ffffbb00": "can201_encoded_vehicle_speed",
    "ffffbb04": "can201_prepared_engine_rpm",
    "ffffbb08": "can201_previous_engine_rpm",
    "ffffa409": "can_error_recovery_active",
    "ffffa40a": "can_error_latch",
    "ffffa40c": "can_error_retry_counter",
    "ffffa40e": "can_setup_retry_counter",
    "ffffa40f": "can_error_poll_counter",
    "ffffa410": "can_setup_error_flag",
}


# aliases already integrated into the export index by earlier pipeline runs
EXPECTED_FN_INDEX = {
    "0002a4f8": "hcan_mailbox_config_compare",
    "00029340": "can201_prepare_rpm_with_conditional_filter",
    "00029236": "can201_encode_rpm_u16",
    "0002927c": "can201_encode_vehicle_speed_u16",
    "000291dc": "can201_pack_and_queue_payload",
    "00028eb8": "can216_unpack_mixed_width_fields",
}


def test_labels_in_artifacts():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv"), newline=""), delimiter="\t")}
    for addr, name in EXPECTED_FN_INDEX.items():
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
                       ("ffffe420", "HCAN0_MC0[1]_B"),
                       ("ffffe401", "HCAN0_GSR_B"), ("ffffe404", "HCAN0_MBCR_W")):
        assert f"{addr}\t{name}\t" in syms


def u16(a):
    return struct.unpack(">H", ROM[a:a + 2])[0]


DESCRIPTOR_BLOCKS = [(0x4E01C, 16), (0x4E11C, 16), (0x4E21C, 6), (0x4DF1C, 1)]


def test_descriptor_record_layout():
    """Every 16-byte descriptor record in all ROM blocks: +0..+3 id, +4 MBCR
    bit in {0,1}, +5 mailbox, +6 MC control/DLC, +7 IDE in {0,1}, +8..+11 RAM
    buffer pointer 0xffff...., +12 MBIMR bit in {0,1}, +13..+15 zero."""
    for base, count in DESCRIPTOR_BLOCKS:
        for i in range(count):
            rec = ROM[base + i * 16: base + i * 16 + 16]
            assert rec[4] in (0, 1)                       # MBCR direction bit
            assert rec[7] in (0, 1)                       # IDE flag
            assert 0xFFFF0000 <= u32(base + i * 16 + 8) <= 0xFFFFFFFF
            assert rec[12] in (0, 1)                      # MBIMR interrupt-mask bit
            assert rec[13:16] == b"\x00\x00\x00"          # reserved
    # observed MBIMR bits: HCAN0 mailboxes 1-12 disabled, 13-15 (0x7df/0x7e0/0x7e8) enabled
    assert all(ROM[0x4E01C + i * 16 + 12] == 1 for i in range(13))
    assert [ROM[0x4E01C + i * 16 + 12] for i in (13, 14, 15)] == [0, 0, 0]
    # AT (0x4e01c) vs default (0x4e11c) differ only in records 3/4 direction bit (+4)
    for i in range(16):
        a, b = ROM[0x4E01C + i * 16:0x4E01C + i * 16 + 16], ROM[0x4E11C + i * 16:0x4E11C + i * 16 + 16]
        if i in (3, 4):
            assert a[4] == 0 and b[4] == 1 and a[:4] + a[5:] == b[:4] + b[5:]
        else:
            assert a == b


def test_setup_writer_chain_anchors():
    # ref_CANControllerSetup 0x9744 record loop: arg loads + jsr pool 0x9878 = 0xcacc
    assert "mov.b @(0xc,r14),r0" in asm_line(0x97D8)   # record byte +12 -> stack arg
    assert "mov.l @r14,r3" in asm_line(0x97DE)          # record word0 (id) -> stack arg
    assert "mov.b @(0x4,r14),r0" in asm_line(0x97EA)    # record byte +4 -> r5 (MBCR bit)
    assert "mov.b @(0x5,r14),r0" in asm_line(0x97EE)    # record byte +5 -> r4 (mailbox)
    assert u32(0x9878) == 0xCACC
    # ref_setCANRegisters 0xcacc: channel split + register pools + jsr 0x9d24
    assert "cmp/ge" in asm_line(0xCAD6) and "#0x20" in asm_line(0xCACE)
    assert u16(0xCBC2) == 0xE420 and u16(0xCBC6) == 0xE414 and u16(0xCBC4) == 0xE4B0
    assert u16(0xCBC8) == 0xE620 and u16(0xCBCC) == 0xE614
    assert u32(0xCBE8) == 0x9D24
    # ref_initializeCANRegisters 0x9d24: MBCR RMW write, MBIMR RMW write, MC[mb][0] = ctrl
    assert asm_line(0x9D6C).endswith("mov.w r2,@r1")    # MBCR write
    assert asm_line(0x9D82).endswith("mov.w r3,@r1")    # MBIMR write
    assert "mov.b r6,@r13" in asm_line(0x9D84)         # MC[mb][0] = ctrl (byte +6)
    # compare loop 0x2a4f8: accumulates record byte +4 into MBCR, byte +12 into MBIMR
    assert "mov.b @(0x4,r9),r0" in asm_line(0x2A596)
    assert "mov.b @(0xc,r9),r0" in asm_line(0x2A5A2)
    assert u16(0x2A5EA) == 0xE404 and u16(0x2A5EC) == 0xE414   # MBCR/MBIMR compare addrs
    assert u32(0x2A5F0) == 0x0000803E                       # BCR expect


def test_can_setup_callers_boot_and_recovery():
    # block select in ref_canSetup 0xd9f4: 0xffffb534==1 -> 0x4e01c, else 0x4e11c
    assert u16(0xDB0E) == 0xB534 and u32(0xDB14) == 0x4E01C and u32(0xDB18) == 0x4E11C
    assert u32(0xDB1C) == 0x9744 and u32(0xDB20) == 0x2A4F8 and u32(0xDB24) == 0x4E21C
    assert u32(0xDB10) == 0xFFFFA40E                        # retry counter cell
    # boot/key-on init chain: 0x61a8 -> 0x1102a -> 0x2a1a0 -> ref_canSetup
    assert u32(0x628C) == 0x1102A and "jsr" in asm_line(0x61E4)
    assert u32(0x11350) == 0x2A1A0 and "jsr" in asm_line(0x111A2)
    assert u32(0x2A3E0) == 0xD9F4 and "jsr" in asm_line(0x2A1A4)
    # runtime supervision chain: OS task 7 (0x63f0) -> 0x114b0 -> 0x2a248 -> 0xdcc0
    assert u32(0x4A08) == 0x63F0                            # task table record 7 entry
    assert u32(0x6528) == 0x114B0 and "jsr" in asm_line(0x6414)
    assert u32(0x11680) == 0x2A248 and "jsr" in asm_line(0x114BA)
    assert u32(0x2A44C) == 0xDCC0 and "jsr" in asm_line(0x2A254)
    # error-recovery calls of ref_canSetup: bsr at 0xdd86 (0xdcc0) and 0xdae0 (0xdade)
    assert "bsr 0x0000d9f4" in asm_line(0xDD86)
    assert "bsr 0x0000d9f4" in asm_line(0xDAE0)
    assert "bsr 0x0000dade" in asm_line(0xDDA8)
    # 0xdcc0 error-branch anchors: cells + thresholds + GSR-bit0 helper
    assert u16(0xDDC2) == 0xA40A and u16(0xDDC4) == 0xA409 and u16(0xDDC6) == 0x3E8
    assert u32(0xDDD0) == 0xFFFFA40C and u32(0xDDD4) == 0x9AC4 and u32(0xDDD8) == 0x2460
    assert u16(0xDDBC) == 0xAA68 and u16(0xDDBE) == 0xB578
    # FUN_00009ac4 0x9ac4 tests HCAN GSR bit0 (bus-off)
    assert "HCAN0_GSR_B" in open(os.path.join(DEC, "functions", "00009ac4_FUN_00009ac4.c"),
                                 encoding="utf-8", errors="surrogateescape").read()
