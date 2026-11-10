"""Set-fault thunk cluster verification (60E15120_N3J1E): 0x5fd38 / 0x5fd3c / 0x5fd4a.

Static: the three bodies are direct tail-call trampolines / a plain setter (ROM
bytes + pool words + callgraph counts + renamed export labels). Dynamic: the
0x5fd38 trampoline behaves identically to calling dtc_set_fault 0x5fe20 with
x=0, and 0x5fd4a sets/clears the eval-enable flag 0xffffd688.

Run: python -m pytest tests/test_dtc_set_fault_thunk.py
"""
import csv
import os
import struct
import sys

import pytest

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EMU = os.path.join(ROOT, "utilities", "scripts", "emu")
sys.path.insert(0, EMU)

import emu  # noqa: E402
import harness  # noqa: E402

ROM = os.path.join(ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
                   "Stock_ROMs", "60E15120_N3J1E.bin")
DEC = os.path.join(ROOT, "reverse-engineered", "decompiled", "60E15120_N3J1E")
PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

THUNK_X0, THUNK_XDEF, SET_EVAL, SET_FAULT = 0x5FD38, 0x5FD3C, 0x5FD4A, 0x5FE20
EVAL_STATE, EVAL_CACHE = 0xFFFFD458, 0xFFFFD3C2
EVAL_ENABLE = 0xFFFFD688
ARG, SLOT = 0x83, 0x79

rom = open(ROM, "rb").read()


def u16(a):
    return struct.unpack(">H", rom[a:a + 2])[0]


def u32(a):
    return struct.unpack(">I", rom[a:a + 4])[0]


def test_thunk_bodies_are_direct_trampolines():
    # 0x5fd38: bra 0x5fe20 ; delay mov #0,r6  -> dtc_set_fault(arg, mode, 0)
    assert u16(0x5FD38) == 0xA072 and u16(0x5FD3A) == 0xE600
    # 0x5fd3c: extu.w r6,r3 ; tst ; bf/s ; mov.l pool(0x5fe0c)=0xffff -> r6 ; bra 0x5fe20
    assert u16(0x5FD3C) == 0x636D and u16(0x5FD3E) == 0x2338
    assert u16(0x5FD44) & 0xFF00 == 0xD600 and u32(0x5FE0C) == 0x0000FFFF
    assert u16(0x5FD46) == 0xA06B
    # 0x5fd4a: setter writing 1/0 to pool 0x5fe10 = 0xffffd688 (dtc_eval_enable)
    assert u16(0x5FD4C) & 0xFF00 == 0xD500 and u32(0x5FE10) == 0xFFFFD688
    assert u16(0x5FD68) == 0x000B  # rts
    # dtc_set_fault 0x5fe20 is called only by the two trampolines
    cg = list(csv.DictReader(open(os.path.join(DEC, "callgraph.tsv")), delimiter="\t"))
    callers = [r["caller"] for r in cg if r["callee"] == "0005fe20"]
    assert sorted(callers) == ["0005fd38", "0005fd3c"]
    counts = {t: sum(1 for r in cg if r["callee"] == t)
              for t in ("0005fd38", "0005fd3c", "0005fd4a")}
    assert counts == {"0005fd38": 71, "0005fd3c": 2, "0005fd4a": 2}


def test_export_labels_promoted():
    idx = {r["address"]: r["name"] for r in
           csv.DictReader(open(os.path.join(DEC, "function_index.tsv")), delimiter="\t")}
    assert idx["0005fd38"] == "dtc_set_fault_x0"
    assert idx["0005fd3c"] == "dtc_set_fault_xdefault"
    assert idx["0005fd4a"] == "dtc_set_eval_enable"


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    harness.call(bus, cpu, 0x5FD6C, max_steps=300000)      # DTC RAM init, as boot does
    for a in (0xFFFFD1C5, 0xFFFFD25A, 0xFFFFD25D, 0xFFFFD958):
        bus.write8(a, 0)
    bus.write16(0xFFFFD3B4, 0)
    return bus, cpu


def test_trampoline_equals_set_fault_with_x0(booted):
    bus, cpu = booted
    bus.write8(EVAL_STATE + SLOT, 0)
    bus.write8(EVAL_CACHE + ARG, 0)
    harness.call(bus, cpu, THUNK_X0, r_args=(ARG, 1), max_steps=200000)
    assert bus.read8(EVAL_STATE + SLOT) == 1      # engine acknowledged the set
    assert bus.read8(EVAL_CACHE + ARG) == 1
    bus.write8(EVAL_STATE + SLOT, 0)
    bus.write8(EVAL_CACHE + ARG, 0)
    harness.call(bus, cpu, SET_FAULT, r_args=(ARG, 1, 0), max_steps=200000)
    assert bus.read8(EVAL_STATE + SLOT) == 1      # identical effect via direct call
    assert bus.read8(EVAL_CACHE + ARG) == 1


def test_eval_enable_setter(booted):
    bus, cpu = booted
    harness.call(bus, cpu, SET_EVAL, r_args=(1,), max_steps=50000)
    assert bus.read8(EVAL_ENABLE) == 1
    harness.call(bus, cpu, SET_EVAL, r_args=(0,), max_steps=50000)
    assert bus.read8(EVAL_ENABLE) == 0
    harness.call(bus, cpu, SET_EVAL, r_args=(1,), max_steps=50000)   # leave enabled
    assert bus.read8(EVAL_ENABLE) == 1
