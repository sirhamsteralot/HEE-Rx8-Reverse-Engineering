"""Example new-DTC-trigger patcher (utilities/scripts/patchers/patch_new_dtc_trigger.py):
static invariants + emulator validation on the patched ROM (60E15120_N3J1E).

Static: input hash unchanged, diff confined to the hook pool word + 3 DTC-table
bytes + cave, stock values asserted before patching, cave decodes to the intended
SH-2E sequence. Dynamic: boot the patched ROM, fire the cave wrapper via
harness.call with rpm below/above the threshold, and prove the stored new DTC
(slot 0x79, arg 0x83, code P1F01) is emitted by the stock Mode-03-style path
(0x615c6 -> 0x667c8) and lights the MIL flag (0x5a130 -> 0xffffd286).

Run: python -m pytest tests/test_dtc_trigger_patcher.py
"""
import hashlib
import json
import os
import struct
import sys

import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EMU = os.path.join(ROOT, "utilities", "scripts", "emu")
PATCHERS = os.path.join(ROOT, "utilities", "scripts", "patchers")
sys.path.insert(0, EMU)
sys.path.insert(0, PATCHERS)

import emu  # noqa: E402
import harness  # noqa: E402
import patch_new_dtc_trigger as p  # noqa: E402

REF_ROM = os.path.join(ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
                       "Stock_ROMs", "60E15120_N3J1E.bin")
PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

SLOT, ARG = p.SLOT, p.ARG
CODE_ADDR = p.CODE_TBL + 2 * SLOT
EN1_ADDR, EN2_ADDR = p.EN1 + SLOT, p.EN2 + SLOT

DTC_RAM_INIT = 0x5FD6C
COLLECT_LIST = 0x615C6
BUILD_RESP = 0x667C8
COUNT = 0x61450
MIL = 0x5A130
RPM_RAM = p.RPM_RAM
EVAL_STATE = 0xFFFFD458
EVAL_CACHE = 0xFFFFD3C2
TRANSITION = 0xFFFFD4E4
STORED_FLAG = 0xFFFFD570
STATE_MIRROR = 0xFFFFD5FC
MASTER = 0xFFFF87B0
MIL_FLAG = 0xFFFFD286
BUF, OUT = 0xFFFFE900, 0xFFFFEA00


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return harness.bits(f32(x))


@pytest.fixture(scope="module")
def patched(tmp_path_factory):
    out_dir = tmp_path_factory.mktemp("patched")
    res = p.patch_rom(REF_ROM, out_dir=out_dir)
    assert res["status"] == "OK", res
    return res


def test_static_invariants(patched):
    stock = open(REF_ROM, "rb").read()
    out_path = patched["output"]
    out = open(out_path, "rb").read()
    assert hashlib.sha256(stock).hexdigest() == p.REF_SHA256          # input untouched
    assert hashlib.sha256(out).hexdigest() == patched["output_sha256"]
    assert len(out) == len(stock)
    diff = {i for i in range(len(stock)) if stock[i] != out[i]}
    cave = int(patched["cave"], 16)
    allowed = (set(range(int(patched["hook_pool_word"], 16), int(patched["hook_pool_word"], 16) + 4))
               | set(range(CODE_ADDR, CODE_ADDR + 2)) | {EN1_ADDR, EN2_ADDR}
               | set(range(cave, cave + patched["cave_len"])))
    assert diff <= allowed
    # table patches landed
    assert struct.unpack(">H", out[CODE_ADDR:CODE_ADDR + 2])[0] == 0x1F01
    assert out[EN1_ADDR] == 1 and out[EN2_ADDR] == 1
    # hook pool word now points at the cave; cave area was free flash before
    assert struct.unpack(">I", out[int(patched["hook_pool_word"], 16):][:4])[0] == cave
    assert all(b == 0xff for b in stock[cave:cave + patched["cave_len"]])
    # cave decodes to the intended SH-2E sequence (layout-tolerant checks)
    blob = out[cave:cave + patched["cave_len"]]
    w = [struct.unpack(">H", blob[2 * i:2 * i + 2])[0] for i in range(patched["cave_len"] // 2)]
    assert w.count(0x400B) == 2                # jsr @r0: stock fn, then set-fault
    assert 0xF015 in w                         # fcmp/gt fr1,fr0 -> T = rpm > threshold
    assert any((x & 0xFF00) == 0x8F00 for x in w)   # bf/s SKIP
    assert 0xE501 in w and 0xE600 in w         # mov #1,r5 ; mov #0,r6 (mode 1, x=0)
    assert 0x000B in w                         # rts
    # pool + trailing threshold data
    assert struct.pack(">IIII", 0x3809A, 0x5FD38, 0xFFFFB548, 0x83) in blob
    thr_bits = struct.pack(">I", harness.bits(f32(8000.0)))
    assert thr_bits in blob


def test_skips_non_reference_rom(tmp_path):
    bad = tmp_path / "bad.bin"
    bad.write_bytes(b"\x00" * 0x1000)
    res = p.patch_rom(bad, out_dir=tmp_path)
    assert res["status"] == "SKIP"


@pytest.fixture(scope="module")
def booted_patched(patched, tmp_path_factory):
    prof = json.load(open(PROFILE))
    prof["rom"]["path"] = os.path.abspath(patched["output"])
    prof["rom"]["sha256"] = patched["output_sha256"]
    tmp = tmp_path_factory.mktemp("prof")
    prof_path = tmp / "patched.json"
    prof_path.write_text(json.dumps(prof))
    p_, bus, cpu = emu.build(str(prof_path))
    emu.run(p_, bus, cpu, 300000)
    harness.call(bus, cpu, DTC_RAM_INIT, max_steps=300000)   # as boot task does
    for a in (0xFFFFD1C5, 0xFFFFD25A, 0xFFFFD25D, 0xFFFFD958):
        bus.write8(a, 0)
    bus.write16(0xFFFFD3B4, 0)
    return bus, cpu, int(patched["cave"], 16)


def test_trigger_below_threshold_does_nothing(booted_patched):
    bus, cpu, cave = booted_patched
    bus.write32(RPM_RAM, bits(3000.0))
    bus.write8(EVAL_STATE + SLOT, 0)
    harness.call(bus, cpu, cave, max_steps=200000)
    assert bus.read8(EVAL_STATE + SLOT) == 0        # set-fault not called
    assert bus.read8(EVAL_CACHE + ARG) == 0


def test_trigger_over_threshold_raises_dtc(booted_patched):
    bus, cpu, cave = booted_patched
    bus.write32(RPM_RAM, bits(9000.0))
    bus.write8(EVAL_STATE + SLOT, 0)
    bus.write8(EVAL_CACHE + ARG, 0)
    harness.call(bus, cpu, cave, max_steps=200000)
    # 0x5fd38(0x83, 1) ran: eval state written for slot 0x79, cache for arg 0x83
    assert bus.read8(EVAL_STATE + SLOT) == 1
    assert bus.read8(EVAL_CACHE + ARG) == 1


def test_stored_new_dtc_readout_and_mil(booted_patched):
    bus, cpu, _ = booted_patched
    # plant the stored state as the OS event handler 0x61092 would (master entry + flags)
    bus.write16(MASTER + 16, SLOT)               # entry 1 (entry 0 is the skipped index cell)
    bus.write8(MASTER + 6 + 16, 0x80)            # state 0x80 = stored
    bus.write8(STORED_FLAG + SLOT, 1)
    bus.write8(STATE_MIRROR + SLOT, 0x70)
    bus.write16(0xFFFFD3C0, 0x1F01)
    bus.write8(0xFFFFD1C5, 0)
    n, _, _ = harness.call(bus, cpu, COLLECT_LIST, r_args=(0x80, 2, BUF), max_steps=200000)
    slots = [bus.read16(BUF + 2 * i) for i in range(n & 0xFFFF)]
    assert SLOT in slots                         # enable#2=1 keeps it visible
    r0, _, _ = harness.call(bus, cpu, BUILD_RESP, r_args=(3, OUT, BUF, n & 0xFFFF), max_steps=200000)
    codes = [bus.read16(OUT + 2 * i) for i in range(r0 & 0xFF)]
    assert 0x1F01 in codes                       # new code emitted from 0x7e560+2*0x79
    cnt, _, _ = harness.call(bus, cpu, COUNT, r_args=(0x80, 1), max_steps=100000)
    assert cnt & 0xFFFF >= 1                     # enable#1=1 -> counts toward MIL
    harness.call(bus, cpu, MIL, max_steps=100000)
    assert bus.read8(MIL_FLAG) == 1
