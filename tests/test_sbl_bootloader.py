"""Dynamic tests for the SBL (serial bootloader) block 0x0000-0x1fff and the
app->SBL handover, reference ROM 60E15120_N3J1E (profile 60E15120_N3J1E).

Covers the externally reviewed corrections to the SBL report:
- 0x1008 is NOT an erase guard: it reads the u16 pair at 0x7fb00/0x7fb02 (the
  app-CVN hole) and returns the counter value when value == ~complement (and
  value != 0xffff), else 0. With the stock hole (00 02 / FF FD) it returns 2.
- SBL 0xB1 (0x1d78) with payload 00 B2 00 does NOT erase anything (its only
  callees are 0x1008 and the response sender 0x11fa): it clears 0xffffdfb4,
  sets the download-armed latch 0xffffdfb3 = 1 and answers F1 00 B2. The SBL
  block has no flash-register access at all (no pool word in 0x1000-0x1ffb
  points at 0xffffe800+), so the staged code downloaded via 0x34/0x36 does the
  erase/programming.
- SBL 0x34 (0x1ad6): request is 34 <addr u32> 00 <field u24>, length 8; byte
  count = field - 0x7e000 (pool 0x1bec = 0xfff82000), must be > 0, a multiple
  of 0x400, and the staged end must stay below the request buffer 0xffffd3f0
  (caps count at 0x7000 from address 0); positive reply 74 04 01.
- SBL 0x36 (0x1c04): blocks must be exactly 0x400 bytes (else NRC 0x72); the
  marker scan starts at index 1 of the 0x1ff4 marker (matches "SBL_END"
  without the '*'); a marker-free final block gives NRC 0x72.
- SBL 0x11 (0x19ce): answers bare 51, then halts with the interrupt mask
  raised (0x1a44 bra-self, SR |= 0xf0); the unserviced WDT then sets OVF, and
  after a reset the warm path (magic 0x5aa5a55a @0xffffdffc + WDT overflow
  check at 0x4e0) re-enters the app at 0xd204 via 0x1298 -> 0x1038(0),
  NOT the cold loop 0x6c8 and NOT the SBL loop 0x1378.
- App side: the 0x56428 conditions gate (battery 8.0-16.5 V via ADC AN14,
  0x1008() < 100) passes with a real 12.5 V input; the app 0x27 key algorithm
  (0x5609e, 64-round shift-Feistel over seed||"MazdA" with the level key from
  ROM 0x5f089+3*level) is reproduced bit-exact in Python and accepted by the
  ROM's own verifier.

Emulator notes: the OS tick never fires (ROADMAP E6), so boot-task bodies that
normally initialize the diag/CAN state are called directly (0x67f10, 0x67d44,
0x55cae, 0x6744) before driving the SBL loop at 0x1378 the way trampoline
0x1090 does (SP = 0xffffdfa0, jmp 0x1378). SBL latches (0xffffdfb0/b1/b3/b4)
and the app session/unlock cells (0xffffd1cf/d1d0) are set via harness `ram=`
in the handler-level tests - documented input globals of the callee, not
faked sensor state; over CAN they are set by 10 85 / 27 02 (tested below).
"""
import os
import struct
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu"))

import emu  # noqa: E402
import harness  # noqa: E402
import isotp  # noqa: E402
from can import CANController  # noqa: E402
from peripherals import ADC  # noqa: E402

PROFILE = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu",
                       "profiles", "60E15120_N3J1E.json")
ROM = os.path.join(os.path.dirname(__file__), "..", "submodules",
                   "Mazda_RX8_PCM_ReverseEngineering", "Stock_ROMs", "60E15120_N3J1E.bin")

SBL_LOOP = 0x1378
SBL_SP = 0xFFFFDFA0
REQ_BUF = 0xFFFFD3F0  # the SBL's own request buffer (r13 in the 0x34 range check)


def boot():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    assert cpu.pc == 0x3DAC
    can = next(p for _, _, p in bus.peripherals if isinstance(p, CANController))
    return prof, bus, cpu, can


def can_warmup(bus, cpu, can):
    """Boot-task bodies the missing OS tick never schedules (E6), then one CAN poll."""
    for f in (0x67F10, 0x67D44, 0x55CAE):
        harness.call(bus, cpu, f, max_steps=100000)
    cpu.pc = 0x3DAC
    for cid, data in isotp.encode(bytes([0x3E, 0x01]), 0x7E0):
        can.inject(cid, data)
    harness.call(bus, cpu, 0x11D88, max_steps=300000)
    cpu.pc = 0x3DAC
    can.tx_log.clear()


def enter_sbl_loop(prof, bus, cpu, can):
    can_warmup(bus, cpu, can)
    cpu.r[15] = SBL_SP
    cpu.pc = SBL_LOOP
    emu.run(prof, bus, cpu, 20000)
    assert 0x1000 <= cpu.pc < 0x2000


def tx_payloads(can):
    resp = [d for _, cid, d in can.tx_log if cid == 0x7E8]
    can.tx_log.clear()
    reasm = isotp.Reassembler()
    return [p for d in resp if (p := reasm.feed(d))]


def sbl_uds(prof, bus, cpu, can, payload, cycles=300000):
    for cid, data in isotp.encode(payload, 0x7E0):
        can.inject(cid, data)
    emu.run(prof, bus, cpu, cycles)
    return tx_payloads(can)


def b(bus, a):
    return bus.read8(a)


# --- point 1: 0x1008 is the CVN-hole pair check, not an erase guard ----------

def test_0x1008_returns_hole_counter_value():
    prof, bus, cpu, can = boot()
    r0, _, _ = harness.call(bus, cpu, 0x1008, max_steps=10000)
    # ROM 0x7fb00 = 00 02, 0x7fb02 = FF FD -> ~0xfffd == 0x0002 == value -> returns 2
    assert r0 == 2


def test_sbl_b1_arms_one_download_no_erase():
    prof, bus, cpu, can = boot()
    enter_sbl_loop(prof, bus, cpu, can)
    assert sbl_uds(prof, bus, cpu, can, bytes([0x10, 0x85])) == [bytes([0x50, 0x85])]
    assert sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x01])) == [bytes([0x67, 0x01, 0x55, 0xAA, 0x55])]
    assert b(bus, 0xFFFFDFB2) == 1  # seed flag set by 27 01
    assert sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x02, 0x4D, 0xAC, 0xCD])) == [bytes([0x67, 0x02])]
    assert b(bus, 0xFFFFDFB1) == 1          # unlock latch
    assert b(bus, 0xFFFFDFB2) == 0          # key attempt cleared the seed flag
    resp = sbl_uds(prof, bus, cpu, can, bytes([0xB1, 0x00, 0xB2, 0x00]))
    assert resp == [bytes([0xF1, 0x00, 0xB2])]
    assert b(bus, 0xFFFFDFB3) == 1          # one download armed
    assert b(bus, 0xFFFFDFB4) == 0          # transfer-active flag cleared
    # 0x3e sub 01 answers a bare 7E
    assert sbl_uds(prof, bus, cpu, can, bytes([0x3E, 0x01])) == [bytes([0x7E])]


# --- point 3: 0x34 / 0x36 handler details ------------------------------------

SBL_LATCHES = {0xFFFFDFB0: (1, 1), 0xFFFFDFB1: (1, 1), 0xFFFFDFB3: (1, 1)}


def call_0x34(bus, cpu, can, addr, field):
    req = bytes([0x34, 0x00, 0x00, 0x08]) + addr.to_bytes(4, "big") + b"\x00" + field.to_bytes(3, "big")
    for i, v in enumerate(req):
        bus.write8(REQ_BUF + i, v)
    harness.call(bus, cpu, 0x1AD6, r_args=(REQ_BUF,), max_steps=100000, ram=SBL_LATCHES)
    cpu.pc = 0x3DAC
    return tx_payloads(can)


def test_sbl_0x34_request_download_parsing():
    prof, bus, cpu, can = boot()
    # addr 0, field 0x7e400 -> count 0x400: positive 74 04 01, staged at 0xffff6000
    assert call_0x34(bus, cpu, can, 0, 0x7E400) == [bytes([0x74, 0x04, 0x01])]
    assert bus.read32(0xFFFFDFBC) == 0x400          # remaining count
    assert bus.read32(0xFFFFDFB8) == 0xFFFF6000     # staging base = 0xffff6000 + addr
    assert b(bus, 0xFFFFDFC5) == 1                   # marker scan index init = 1
    assert b(bus, 0xFFFFDFB3) == 0 and b(bus, 0xFFFFDFB4) == 1
    # count not a multiple of 0x400 -> NRC 0x31
    assert call_0x34(bus, cpu, can, 0, 0x7E401) == [bytes([0x7F, 0x34, 0x31])]
    # count cap from address 0: 0x7000 OK, 0x7400 exceeds the request buffer -> 0x31
    assert call_0x34(bus, cpu, can, 0, 0x85000) == [bytes([0x74, 0x04, 0x01])]
    assert call_0x34(bus, cpu, can, 0, 0x85400) == [bytes([0x7F, 0x34, 0x31])]


def test_sbl_0x36_transfer_data_block_rules():
    prof, bus, cpu, can = boot()
    call_0x34(bus, cpu, can, 0, 0x7E400)  # arm a 0x400 download
    latches = {**SBL_LATCHES, 0xFFFFDFB4: (1, 1)}
    # block size must be exactly 0x400
    req = bytes([0x36, 0x00]) + (0x100).to_bytes(2, "big") + bytes(0x100)
    for i, v in enumerate(req):
        bus.write8(REQ_BUF + i, v)
    harness.call(bus, cpu, 0x1C04, r_args=(REQ_BUF,), max_steps=200000, ram=latches)
    cpu.pc = 0x3DAC
    assert tx_payloads(can) == [bytes([0x7F, 0x36, 0x72])]
    # 0x400 block without the SBL_END marker, size exhausted -> NRC 0x72
    req = bytes([0x36, 0x00, 0x04, 0x00]) + bytes(0x400)
    for i, v in enumerate(req):
        bus.write8(REQ_BUF + i, v)
    harness.call(bus, cpu, 0x1C04, r_args=(REQ_BUF,), max_steps=200000, ram=latches)
    cpu.pc = 0x3DAC
    assert tx_payloads(can) == [bytes([0x7F, 0x36, 0x72])]
    assert b(bus, 0xFFFFDFB4) == 0


# --- Q1/Q2: 11 01 in the SBL halts; after reset the warm path re-enters the app

def test_sbl_0x11_halt_then_reset_warm_boots_app():
    prof, bus, cpu, can = boot()
    enter_sbl_loop(prof, bus, cpu, can)
    sbl_uds(prof, bus, cpu, can, bytes([0x10, 0x85]))
    sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x01]))
    sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x02, 0x4D, 0xAC, 0xCD]))
    assert sbl_uds(prof, bus, cpu, can, bytes([0x11, 0x01])) == [bytes([0x51])]
    assert cpu.pc == 0x1A44          # halt loop, interrupts masked
    assert cpu.sr & 0xF0
    emu.run(prof, bus, cpu, 400000)
    assert cpu.pc == 0x1A44          # still halted, WDT not serviced
    assert bus.read8(0xFFFFEC10) & 0x80  # WDT OVF set
    cpu.reset(bus.read32(0), bus.read32(4))   # hardware reset line
    trace = []
    emu.run(prof, bus, cpu, 300000, trace=trace)
    pcs = ["%08x" % p for p in trace]
    assert "000008b8" in pcs and "000004e0" in pcs
    assert "00001298" in pcs         # warm entry (magic @0xffffdffc + WDT OVF)
    assert "000006c8" not in pcs     # cold loop NOT taken
    assert "00001038" in pcs
    assert "0000d204" in pcs         # app re-entered
    assert "00001378" not in pcs     # SBL loop NOT re-entered


# --- point 2 (app side): conditions gate + bit-exact key algorithm ------------

def test_app_0x56428_conditions_gate_with_real_battery():
    prof, bus, cpu, can = boot()
    adc = next(p for _, _, p in bus.peripherals if isinstance(p, ADC))
    adc.channels["AN14"] = 0xA000  # 0xA000/65536*20 = 12.5 V via ADDR14H
    harness.call(bus, cpu, 0x6884, max_steps=100000)  # ADC sweep -> 0xffff9f00
    harness.call(bus, cpu, 0x7338, max_steps=100000)  # readECMVoltage -> 0xffff9f68
    harness.call(bus, cpu, 0x25600, max_steps=100000)  # seed 0xffffb590
    cpu.pc = 0x3DAC
    v = struct.unpack(">f", struct.pack(">I", bus.read32(0xFFFFB590)))[0]
    assert 8.0 <= v <= 16.5
    r0, _, _ = harness.call(bus, cpu, 0x56428, max_steps=100000)
    assert r0 == 0  # conditions OK: 0x1008() == 2 < 100 and battery in range


def mazda_key(level, seed):
    """Python port of the app key network 0x5609e (ROM 0x5f084 = "MazdA")."""
    rom = open(ROM, "rb").read()
    i = level * 3
    key = [rom[0x5F08B + i], rom[0x5F08A + i], rom[0x5F089 + i]]
    blk = [seed[0], seed[1], seed[2], 0x4D, 0x61, 0x7A, 0x64, 0x41]
    for _ in range(0x40):
        out_b = blk[0] & 1
        for j in range(8):
            blk[j] >>= 1
            if j < 7 and (blk[j + 1] & 1):
                blk[j] |= 0x80
        out_k = key[0] & 1
        for j in range(3):
            key[j] >>= 1
            if j < 2 and (key[j + 1] & 1):
                key[j] |= 0x80
        if out_b != out_k:
            key[0] ^= 0x28
            key[1] ^= 0x90
            key[2] = (key[2] | 0x80) ^ 0x10
    k0 = ((key[1] & 0xF) << 4) | ((key[0] & 0xF0) >> 4)
    k1 = (key[1] & 0xF0) | ((key[2] & 0xF0) >> 4)
    k2 = (key[2] & 0xF) | ((key[0] & 0xF) << 4)
    return bytes([k0 & 0xFF, k1 & 0xFF, k2 & 0xFF])


def test_app_0x27_key_algorithm_bit_exact():
    prof, bus, cpu, can = boot()
    scratch = 0xFFFF7100
    for seed in (bytes([0xFF, 0xFF, 0xFF]), bytes([0x12, 0x34, 0x56]), bytes([0x00, 0x01, 0x80])):
        for j, s in enumerate(seed):
            bus.write8(scratch + j, s)
        key = mazda_key(1, seed)
        for j, k in enumerate(key):
            bus.write8(scratch + 16 + j, k)
        r0, _, _ = harness.call(bus, cpu, 0x5609E, r_args=(1, scratch, scratch + 16),
                                max_steps=100000)
        assert r0 == 0  # ROM's own verifier accepts the ported key
        cpu.pc = 0x3DAC


# --- on-car post-handover state: 0x1038(1) -> 0x16dc(1) presets the SBL latches
#
# Bench feedback (rx8tune/Fullburn Studio on-car session, 2026-11-18, N3YLEE
# family PCM - SBL block byte-identical to the reference ROM): straight after
# the app's B1 00 B2 00 handover the SBL answered 22 D1 00 with 85 (session
# latch already set, before any 10 85) and 27 01 with a ZERO seed (already
# unlocked), and 27 02 4D AC CD with 7F 27 22. Mechanism: the handover calls
# 0x1038 with param 1 (0x564d4, delay slot mov #1,r4 after jsr 0x1038, pool
# 0x564f2), and 0x1038 calls 0x16dc(param); 0x16dc clears latches
# 0xffffdfb0/b1/b2/b3/b4/b5 and, only when param == 1, sets 0xffffdfb0 = 1
# (session), 0xffffdfb1 = 1 (unlock), 0xffffdfb3 = 1 (download armed).
# 0x27 sub 01 then returns a zero seed when 0xffffdfb1 == 1 (0x18dc-0x18ec),
# else the fixed 55 AA 55 (0x1908-0x1914); 22 D1 00 returns the session latch
# value (0x1aa4-0x1ab6: 0x85 if 0xffffdfb0 == 1 else 0x81). Any other entry
# (0x1038(0) warm/erased-flash, 10 81 at 0x182c, the loop's periodic relock at
# 0x1428 when the 0x11cc counter reaches 0x5f6) runs 0x16dc(0) and arrives
# locked.

def test_handleException_param_sets_sbl_latches():
    prof, bus, cpu, can = boot()
    latches = [0xFFFFDFB0, 0xFFFFDFB1, 0xFFFFDFB2, 0xFFFFDFB3, 0xFFFFDFB4, 0xFFFFDFB5]
    dirty = {a: (1, 1) for a in latches}
    harness.call(bus, cpu, 0x16DC, r_args=(0,), max_steps=10000, ram=dirty)
    assert all(b(bus, a) == 0 for a in latches)      # param 0: all six cleared
    harness.call(bus, cpu, 0x16DC, r_args=(1,), max_steps=10000, ram=dirty)
    assert b(bus, 0xFFFFDFB0) == 1                    # session latch set
    assert b(bus, 0xFFFFDFB1) == 1                    # unlock latch set
    assert b(bus, 0xFFFFDFB3) == 1                    # download armed
    assert b(bus, 0xFFFFDFB2) == 0                    # seed flag stays clear
    assert b(bus, 0xFFFFDFB4) == 0 and b(bus, 0xFFFFDFB5) == 0


def test_sbl_loop_after_app_handover_matches_on_car_trace():
    prof, bus, cpu, can = boot()
    can_warmup(bus, cpu, can)
    # exactly what 0x1038(1) does before jumping to the loop (0x1046 -> 0x16dc)
    harness.call(bus, cpu, 0x16DC, r_args=(1,), max_steps=10000)
    cpu.r[15] = SBL_SP
    cpu.pc = SBL_LOOP
    emu.run(prof, bus, cpu, 20000)
    assert 0x1000 <= cpu.pc < 0x2000
    # on-car: 22 D1 00 -> 62 D1 00 85 (latch already set, before any 10 85)
    assert sbl_uds(prof, bus, cpu, can, bytes([0x22, 0xD1, 0x00])) == [bytes([0x62, 0xD1, 0x00, 0x85])]
    assert sbl_uds(prof, bus, cpu, can, bytes([0x10, 0x85])) == [bytes([0x50, 0x85])]
    # on-car: 27 01 -> 67 01 00 00 00 (unlock latch set -> zero seed, not 55 AA 55)
    assert sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x01])) == [bytes([0x67, 0x01, 0x00, 0x00, 0x00])]
    assert b(bus, 0xFFFFDFB2) == 0                    # seed request cleared the seed flag
    # on-car: 27 02 4D AC CD -> 7F 27 22 (no seed outstanding)
    assert sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x02, 0x4D, 0xAC, 0xCD])) == [bytes([0x7F, 0x27, 0x22])]
    # 10 81 relocks (0x17f0 -> 0x16dc(0) at 0x182c): latches cleared, DID reports 81
    assert sbl_uds(prof, bus, cpu, can, bytes([0x10, 0x81])) == [bytes([0x50, 0x81])]
    assert b(bus, 0xFFFFDFB0) == 0 and b(bus, 0xFFFFDFB1) == 0 and b(bus, 0xFFFFDFB3) == 0
    assert sbl_uds(prof, bus, cpu, can, bytes([0x22, 0xD1, 0x00])) == [bytes([0x62, 0xD1, 0x00, 0x81])]
    # with the unlock latch clear again, 27 01 offers the fixed seed 55 AA 55
    sbl_uds(prof, bus, cpu, can, bytes([0x10, 0x85]))
    assert sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x01])) == [bytes([0x67, 0x01, 0x55, 0xAA, 0x55])]


# --- relock semantics at the loop tail (0x141a-0x1450) -----------------------
#
# The u16 at 0xffffdfa0 is an inactivity counter: 0x11cc increments it once per
# loop pass (while WDT OVF is clear) and 0x11c4 zeroes it at loop entry (0x137a),
# on every successfully reassembled frame (0x13c8 single frame, 0x13e4 first
# frame, 0x140a every consecutive frame) and after every service dispatch
# (0x1544). Tail: if r12 == 0 (no multi-frame ISO-TP in progress) and the
# counter >= 0x5f6 (pool 0x143a) -> 0x16dc(0) relock (all six latches cleared);
# if r12 != 0 and the counter >= 0x2e (0x1382) -> only 0x11c4 + r12 = 0, i.e.
# the in-progress multi-frame transfer aborts (inter-frame timeout), the latches
# survive. So the relock is an inactivity timeout, not a fixed lifetime:
# tester-present traffic keeps the latches. Measured in the emulator: ~256
# cycles per idle pass, relock at 0x5f6 passes ~ 390k cycles, transfer abort at
# 0x2e passes ~ 12k cycles.

def test_sbl_relock_is_inactivity_timeout():
    prof, bus, cpu, can = boot()
    can_warmup(bus, cpu, can)
    harness.call(bus, cpu, 0x16DC, r_args=(1,), max_steps=10000)
    cpu.r[15] = SBL_SP
    cpu.pc = SBL_LOOP
    emu.run(prof, bus, cpu, 20000)
    assert 0x1000 <= cpu.pc < 0x2000
    # tester present every 100k cycles (~390 passes < 0x5f6): no relock in 1M cycles
    for _ in range(10):
        assert sbl_uds(prof, bus, cpu, can, bytes([0x3E, 0x01]), cycles=100000) == [bytes([0x7E])]
        assert b(bus, 0xFFFFDFB0) == 1
    assert bus.read16(0xFFFFDFA0) < 0x5F6      # counter was reset by the 3E frames
    # now go idle: the relock fires once the counter passes 0x5f6 (~390k cycles)
    total = 0
    while b(bus, 0xFFFFDFB0) != 0 and total < 1000000:
        emu.run(prof, bus, cpu, 20000)
        total += 20000
    assert b(bus, 0xFFFFDFB0) == 0 and b(bus, 0xFFFFDFB1) == 0 and b(bus, 0xFFFFDFB3) == 0
    assert bus.read16(0xFFFFDFA0) >= 0x5F6
    assert 300000 <= total <= 500000            # ~0x5f6 passes x ~256 cycles/pass
    # locked again: 22 D1 00 reports 81 and 27 01 offers the fixed seed again
    assert sbl_uds(prof, bus, cpu, can, bytes([0x22, 0xD1, 0x00])) == [bytes([0x62, 0xD1, 0x00, 0x81])]
    sbl_uds(prof, bus, cpu, can, bytes([0x10, 0x85]))
    assert sbl_uds(prof, bus, cpu, can, bytes([0x27, 0x01])) == [bytes([0x67, 0x01, 0x55, 0xAA, 0x55])]


def test_sbl_multiframe_interframe_timeout_aborts_transfer_only():
    prof, bus, cpu, can = boot()
    can_warmup(bus, cpu, can)
    harness.call(bus, cpu, 0x16DC, r_args=(1,), max_steps=10000)
    cpu.r[15] = SBL_SP
    cpu.pc = SBL_LOOP
    emu.run(prof, bus, cpu, 20000)
    block = bytes([0x36, 0x00]) + (0x20).to_bytes(2, "big") + bytes(0x20)
    frames = isotp.encode(block, 0x7E0)
    # first frame only -> r12 = 1 (multi-frame reception in progress)
    for cid, data in frames:
        if data[0] >> 4 == 1:
            can.inject(cid, data)
    emu.run(prof, bus, cpu, 5000)
    assert cpu.r[12] & 0xFF == 1
    # no consecutive frame within 0x2e passes (~12k cycles): transfer aborts,
    # counter reset, latches NOT cleared
    emu.run(prof, bus, cpu, 20000)
    assert cpu.r[12] & 0xFF == 0
    assert bus.read16(0xFFFFDFA0) < 0x5F6
    assert b(bus, 0xFFFFDFB0) == 1 and b(bus, 0xFFFFDFB1) == 1 and b(bus, 0xFFFFDFB3) == 1
    # consecutive frames DO reset the counter: arm a download, then send the
    # whole block with frames every 5k cycles (~20 passes < 0x2e) -> the transfer
    # survives past 0x2e total passes and the 0x36 handler answers
    # (NRC 0x72: block is not 0x400 bytes)
    req = bytes([0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x04, 0x00])  # addr 0, field 0x7e400
    # multi-frame request: inject frames spaced (the mb holds one frame at a time)
    for cid, data in isotp.encode(req, 0x7E0):
        can.inject(cid, data)
        emu.run(prof, bus, cpu, 5000)
    assert tx_payloads(can) == [bytes([0x74, 0x04, 0x01])]
    for cid, data in frames:
        can.inject(cid, data)
        emu.run(prof, bus, cpu, 5000)
    assert tx_payloads(can) == [bytes([0x7F, 0x36, 0x72])]
