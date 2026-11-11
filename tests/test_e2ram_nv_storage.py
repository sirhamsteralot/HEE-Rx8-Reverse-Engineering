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
# payload-source cells attributed in the report's §2a (TSV + labels JSON only;
# not renamed in symbols.tsv — that is a pipeline pass, not this one)
EXPECTED_RAM_SRC = {
    "ffffb40c": "candidate_learned_pedal_value",
    "ffffb414": "throttle_pedal_position_delta",
    "ffffb594": "filtered_battery_voltage",
    "ffffb38c": "candidate_throttle_base_position",
    "ffffcc91": "candidate_idle_learn_flag",
    "ffffb466": "e2ram_payload_reserved",
    "ffffb51e": "e2ram_payload_reserved",
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
    for addr, alias in EXPECTED_RAM_SRC.items():
        assert ram.get(addr) == alias, f"TSV missing {addr}"
        assert data["ram_aliases"][addr]["alias"] == alias, f"JSON missing {addr}"
    # the per-body labels JSON covers exactly this subsystem's rows
    assert len(data["function_aliases"]) == 6
    assert len(data["ram_aliases"]) == len(EXPECTED_RAM) + len(EXPECTED_RAM_SRC)


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


def test_save_trigger_chain():
    # task table rec[9].entry (ROM 0x4990 + 9*16 + 8 = 0x4a28) = task[9] body 0x64ba
    assert u32(0x4A28) == 0x64BA
    # 0x64ba calls 0x1150e unconditionally: mov.l pool 0x656c at 0x64d4, jsr at 0x64d6
    assert u32(0x656C) == 0x1150E
    assert "0x656c" in asm_line(0x64D4).replace(" ", "") and "jsr" in asm_line(0x64D6)
    # 0x1150e tail-jumps to the save thunk 0x23766: pool 0x116cc at 0x1152e, jmp at 0x11530
    assert u32(0x116CC) == 0x23766
    assert "0x116cc" in asm_line(0x1152E).replace(" ", "") and "jmp" in asm_line(0x11530)
    # 0x23766 jumps to the save driver 0x236cc: pool 0x237b8 at 0x23766
    assert u32(0x237B8) == 0x236CC and "jmp" in asm_line(0x23768)
    # 0x1150e is referenced by exactly one pool word in the whole ROM (0x656c)
    import re
    assert [m.start() for m in re.finditer(re.escape(struct.pack(">I", 0x1150E)), ROM)] == [0x656C]


def test_save_wake_chain():
    # CMCSR1 refresh-timer ISR: IVT vec 192 slot (ROM 0x7ff50) -> trampoline 0x2f20
    assert u32(0x7FF50) == 0x2F20
    # trampoline 0x2f20 tail-jumps to 0x5cee: pool 0x2f30 at 0x2f2a, jmp at 0x2f2c
    assert u32(0x2F30) == 0x5CEE
    assert "0x2f30" in asm_line(0x2F2A).replace(" ", "") and "jmp" in asm_line(0x2F2C)
    # 0x5cee is referenced by exactly one pool word in the whole ROM (0x2f30)
    import re
    assert [m.start() for m in re.finditer(re.escape(struct.pack(">I", 0x5CEE)), ROM)] == [0x2F30]
    # 0x5cee tail-jumps to the rotating dispatcher 0xa522: pool 0x5d64 at 0x5cf8
    assert u32(0x5D64) == 0xA522 and "jmp" in asm_line(0x5CFA)
    # dispatch table entry 0xd890 = wake thunk 0x9f96; it calls os_wake_posted_task(9)
    assert u32(0xD890) == 0x9F96
    assert u32(0xA1F4) == 0x3854          # os_wake_posted_task
    assert "0x9" in asm_line(0x9F9C)      # mov #0x9,r4 (task id 9) in the delay slot


def test_payload_source_pools():
    # encode source cells in their producers (report §2a)
    assert u16(0x232FA) == 0xB40C and "fmov.s" in asm_line(0x233B0)   # 0x231f0 writes b40c
    assert u16(0x23590) == 0xB414 and "0x23590" in asm_line(0x2355C).replace(" ", "")  # 0x23558 source b414
    # reserved payload cells have no writer references: the only pool references
    # to 0xffffb51e/0xffffb520/0xffffb522/0xffffb524 are the encode reads
    for val, pools in ((0xFFFFB51E, (0x24690,)), (0xFFFFB520, (0x24694,)),
                       (0xFFFFB522, (0x24698,)), (0xFFFFB524, (0x2469C,))):
        import re
        hits = [m.start() for m in re.finditer(re.escape(struct.pack(">I", val)), ROM)]
        assert hits == list(pools), (hex(val), [hex(h) for h in hits])
