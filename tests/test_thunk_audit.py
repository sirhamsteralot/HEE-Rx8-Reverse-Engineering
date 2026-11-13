"""Thunk audit verification (60E15120_N3J1E): all 53 thunk-named rows.

Static, ROM-byte level: every thunk body is re-decoded from the raw ROM
(big-endian SH-2E), its jump target resolved from the bra displacement or the
PC-relative literal pool, and compared against the labels actually applied in
the artifacts (accepted_function_aliases.tsv, thunk_audit_labels.json,
function_index.tsv). The one register-indirect case 0x35d36 is proven by
tracing r14 in its sole caller 0x35a8c.

Dynamic, in the SH-2E emulator: the CAN RX interrupt path is traced through the
pool-jmp thunk 0x5e78 into can_rx_isr_handler 0x9c86, and 0x35d36 is called with
r14 = 0x00037ea4 exactly as caller 0x35a8c sets it, showing it reaches
e2ram_shadow_byte_write 0x37ea4 and writes the shadow data+complement cells.

Run: python -m pytest tests/test_thunk_audit.py
"""
import csv
import json
import os
import re
import struct
import sys

import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EMU = os.path.join(ROOT, "utilities", "scripts", "emu")
sys.path.insert(0, EMU)

import emu  # noqa: E402
import harness  # noqa: E402
from can import CANController  # noqa: E402

ROM = os.path.join(ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
                   "Stock_ROMs", "60E15120_N3J1E.bin")
ROM2 = os.path.join(ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
                    "Stock_ROMs", "60E0FC00.bin")
DEC = os.path.join(ROOT, "reverse-engineered", "decompiled", "60E15120_N3J1E")
INV = os.path.join(ROOT, "docs", "investigations", "60E15120_N3J1E")
LABELS = os.path.join(ROOT, "data", "labels", "60E15120_N3J1E")
PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")
IDLE = 0x3DAC

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"

rom = open(ROM, "rb").read()
rom2 = open(ROM2, "rb").read()


def rows(p):
    return list(csv.DictReader(open(p, newline="", encoding="utf-8",
                                    errors="surrogateescape"), delimiter="\t"))


def u16(a):
    return struct.unpack(">H", rom[a:a + 2])[0]


def u32(a):
    return struct.unpack(">I", rom[a:a + 4])[0]


def sgn12(w):
    return w - 0x1000 if w & 0x800 else w


THUNKS = [(int(r["address"], 16), r["name"], int(r["body_bytes"]))
          for r in rows(os.path.join(INV, "rx8defs-analysis", "function_labels.tsv"))
          if "thunk" in r["name"].lower()]
INDEX = {r["address"]: r["name"]
         for r in rows(os.path.join(DEC, "function_index.tsv"))}
ACCEPTED = {r["address"]: r for r in rows(os.path.join(
    INV, "source_review", "accepted_function_aliases.tsv"))}
RECORD = json.load(open(os.path.join(LABELS, "thunk_audit_labels.json")))
BY_ADDR = {f["address"]: f for f in RECORD["functions"]}


def classify(addr, blen):
    """Return (cls, target, pool) decoded from raw ROM words."""
    w = [u16(addr + 2 * i) for i in range(blen // 2)]
    if blen == 4 and (w[0] & 0xF000) == 0xA000:
        return "bra", addr + 4 + sgn12(w[0] & 0xFFF) * 2, None, w
    if blen == 6 and (w[0] & 0xFF00) == 0xD300 and w[1] == 0x432B and w[2] == 0x0009:
        pool = ((addr + 4) & ~3) + (w[0] & 0xFF) * 4
        return "pool_jmp", u32(pool), pool, w
    if w[0] == 0x4E0B:
        return "jsr_reg", None, None, w
    return "other", None, None, w


def test_rom_unchanged():
    import hashlib
    assert hashlib.sha256(rom).hexdigest() == ROM_SHA256


def test_all_53_thunk_rows_covered_by_label_record():
    assert len(THUNKS) == 53
    assert set(BY_ADDR) == {"%08x" % a for a, _, _ in THUNKS}


def test_bodies_and_targets_resolve_from_raw_rom():
    classes = {"bra": 0, "pool_jmp": 0, "jsr_reg": 0, "other": 0}
    for addr, name, blen in THUNKS:
        cls, target, pool, w = classify(addr, blen)
        classes[cls] += 1
        rec = BY_ADDR["%08x" % addr]
        assert rec["cls"] == cls, (hex(addr), cls, rec["cls"])
        if cls in ("bra", "pool_jmp"):
            assert target == int(rec["target"], 16), hex(addr)
            assert 0 <= target < len(rom)
            # target must be a real function entry
            assert "%08x" % target in INDEX, hex(addr)
    assert classes == {"bra": 14, "pool_jmp": 37, "jsr_reg": 1, "other": 1}


def test_jsr_thunk_0x35d36_targets_e2ram_shadow_byte_write():
    # body: jsr @r14 ; nop ; lds.l pr ; pop r12 ; pop r13 ; rts ; pop r14
    assert [u16(0x35D36 + 2 * i) for i in range(7)] == \
        [0x4E0B, 0x0009, 0x4F26, 0x6CF6, 0x6DF6, 0x000B, 0x6EF6]
    # sole caller 0x35a8c loads r14 exactly once, at 0x35a94, from pool 0x35b74
    assert u16(0x35A94) == 0xDE37
    assert ((0x35A94 + 4) & ~3) + 0x37 * 4 == 0x35B74
    assert u32(0x35B74) == 0x37EA4
    disasm = open(os.path.join(ROOT, "reverse-engineered", "disassembly",
                               "60E15120_N3J1E", "firmware_disassembly.asm"),
                  encoding="utf-8", errors="surrogateescape").read().splitlines()
    start = next(i for i, ln in enumerate(disasm) if re.match(r"^00035a8c\s", ln))
    end = next(i for i, ln in enumerate(disasm) if re.match(r"^00035d36\s", ln))
    r14_writes = [ln for ln in disasm[start:end]
                  if re.search(r",r14\s*$", ln) and "mov.l r14,@-r15" not in ln]
    assert r14_writes == ["00035a94  de37  mov.l @(0x35b74,pc),r14"]
    # 14 dispatch arms branch to the trampoline
    arms = [ln for ln in disasm[start:end] if ln.rstrip().endswith("bra 0x00035d36")]
    assert len(arms) == 14
    # cross-ROM: byte-exact with 60E0FC00 0x36456
    assert rom[0x35D36:0x35D44] == rom2[0x36456:0x36464]
    # applied label
    assert INDEX["00035d36"] == "e2ram_shadow_byte_write_trampoline"
    assert INDEX["00037ea4"] == "e2ram_shadow_byte_write"
    assert ACCEPTED["00035d36"]["alias"] == "e2ram_shadow_byte_write_trampoline"
    assert ACCEPTED["00035d36"]["confidence"] == "high"


def test_applied_labels_match_artifacts():
    for addr, name, blen in THUNKS:
        a = "%08x" % addr
        rec = BY_ADDR[a]
        if rec.get("kept"):
            continue
        # TSV row exists with the alias the export index now carries
        assert a in ACCEPTED, a
        expected = ACCEPTED[a]["alias"]
        assert INDEX[a] == expected, (a, INDEX[a], expected)
        assert ACCEPTED[a]["confidence"] == "high"
    # kept rows still carry their earlier high aliases
    assert INDEX["0005fd3c"] == "dtc_set_fault_xdefault"
    assert INDEX["000576c2"] == "diag22_pidc116_dtc_state_machine"


def test_no_thunk_names_left_in_export_index():
    leftover = [a for a, _, _ in THUNKS
                if "thunk" in INDEX["%08x" % a].lower()]
    assert leftover == []


def test_jump_to_aliases_encode_proven_targets():
    for addr, name, blen in THUNKS:
        a = "%08x" % addr
        rec = BY_ADDR[a]
        if rec.get("kept") or rec["cls"] == "jsr_reg":
            continue
        new = INDEX[a]
        assert new.startswith("jump_to_"), (a, new)
        tgt = int(rec["target"], 16)
        tname = INDEX["%08x" % tgt]
        if tname.startswith("FUN_"):
            assert new == "jump_to_" + tname
        elif not tname.startswith("jump_to_"):
            assert new == "jump_to_" + tname
        else:
            assert new == "jump_to_0x%08x" % tgt  # thunk-to-thunk chain


# --- dynamic validation in the SH-2E emulator --------------------------------

@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    assert cpu.pc == IDLE
    return prof, bus, cpu


def run_traced(bus, cpu, entry, max_steps=400000, pre=None):
    """harness.call-style run that records every executed PC.

    pre: optional fn(bus, cpu) to set up registers/stack before the run.
    Returns (trace_list, final_pc).
    """
    trace = []
    cpu.trace = trace
    cpu.r[15] = harness.STACK
    cpu.pr = harness.SENTINEL
    if pre:
        pre(bus, cpu)
    cpu.pc = entry
    steps = 0
    while cpu.pc != harness.SENTINEL and steps < max_steps:
        bus.pc = cpu.pc
        cpu.step()
        bus.tick(1)
        steps += 1
    cpu.trace = None
    assert cpu.pc == harness.SENTINEL, "did not return (pc=0x%08x)" % cpu.pc
    return trace, cpu.pc


def ordered_subseq(trace, seq):
    """True if `seq` appears in `trace` in order (not necessarily adjacent)."""
    it = iter(trace)
    return all(any(pc == want for pc in it) for want in seq)


def test_dynamic_can_rx_ivt_goes_through_pool_jmp_thunk_0x5e78(booted):
    """Inject a 0x7e0 frame; the CAN RX IVT (0x378) runs trampoline 0x31c0 ->
    pool-jmp thunk 0x5e78 (jump_to_can_rx_isr_handler) -> 0x9c86, and the frame
    lands in the UDS RX buffer 0xffffddc8."""
    prof, bus, cpu = booted
    can = next(p for _, _, p in bus.peripherals if isinstance(p, CANController))
    can.inject(0x7E0, bytes([0x02, 0x10, 0x03, 0x55, 0, 0, 0, 0]))
    assert can.read(0x0E, 2) & 0x40  # RXPR mb14 pending
    trace = []
    cpu.trace = trace
    emu.run(prof, bus, cpu, 20000)
    cpu.trace = None
    assert ordered_subseq(trace, [0x31C0, 0x5E78, 0x9C86]), \
        "IVT path did not go 0x31c0 -> 0x5e78 -> 0x9c86"
    assert bus.read32(0xFFFFDDC8).to_bytes(4, "big") == bytes.fromhex("02100355")
    assert not (can.read(0x0E, 2) & 0x40)
    assert cpu.pc == IDLE


def test_dynamic_0x35d36_trampoline_calls_0x37ea4_shadow_write(booted):
    """Call 0x35d36 with r14 = 0x00037ea4 exactly as its sole caller 0x35a8c
    sets it (pool 0x35b74). The trampoline must reach e2ram_shadow_byte_write
    0x37ea4 and write shadow data + complement at 0xffffc28e/0xffffc38e."""
    _, bus, cpu = booted
    src = 0xFFFFC268  # e2ram_param_block, used as the src buffer here
    payload = [0x11, 0x22, 0x33, 0x44]
    for i, b in enumerate(payload):
        bus.write8(src + i, b)

    def pre(bus, cpu):
        cpu.r[14] = 0x37EA4          # r14 target from pool 0x35b74
        cpu.r[4] = 0                 # index
        cpu.r[5] = src               # src address
        cpu.r[6] = len(payload)      # len
        # 0x35d36's epilogue pops pr from [r15] after the jsr frame is popped:
        # with r15 = STACK the lds.l @r15+,pr reads mem[STACK] -> SENTINEL.
        bus.write32(harness.STACK, harness.SENTINEL)

    trace, _ = run_traced(bus, cpu, 0x35D36, max_steps=100000, pre=pre)
    assert ordered_subseq(trace, [0x35D36, 0x37EA4]), "0x35d36 did not reach 0x37ea4"
    for i, b in enumerate(payload):
        assert bus.read8(0xFFFFC28E + i) == b          # shadow data
        assert bus.read8(0xFFFFC38E + i) == (~b) & 0xFF  # shadow complement
