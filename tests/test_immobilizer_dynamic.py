#!/usr/bin/env python3
"""Dynamic validation of the immobilizer challenge/response in the SH-2E
emulator against the real ROM code of 60E15120_N3J1E.

Static basis: docs/subsystem-logic/immobilizer_report.md + record
data/labels/60E15120_N3J1E/immobilizer_labels.json. This test drives the ROM
functions directly via harness.py after boot:

- 0x38150 immo_can_rx_unpack + flags 0xffffc4bf/c4c0 (what 0x3811c does after
  a CAN 0x047 frame lands in mailbox 39) feed 0x355f0 immo_can_command_decode;
- 0x34ae2 immobilizer_main_state_dispatch runs the state machine
  (DAT_ffffc21d main state / DAT_ffffc21e command sub-state);
- 0x35738 immo_tx_frame_build fills 0xffffc1c8..c1d1, packed by 0x380c8 into
  the CAN 0x041 TX buffer 0xffffc4a8..c4af;
- 0xe2d4 fuel_cut_arbitration shows the immobilization effect: with the
  immo_authorized flag 0xffffc1d0 == 0 it sets DAT_ffffa430 = 0x0003 (both
  rotor banks fuel-cut).

Sequence verified: cmd 0x06/0x7f (seed request) -> TX 0x07 with the raw seed;
cmd 0x08 with the matching computed seed -> authorized (c224=0x7f, TX
0x81/0x7f); wrong word -> rejected (c224=0x81, c1d0=0, TX 0x01/0x81); cmd 0xc9
+ cmd 0x90 subs 1-4 with the computed tagged key words -> exchange completes
(TX 0xc6, back to state 0).

Run: python -m pytest tests/test_immobilizer_dynamic.py
"""
import os
import struct
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

# RAM cells (see data/labels/60E15120_N3J1E/immobilizer_labels.json)
ENGINE_RUN = 0xFFFFAA68
STOPPED = 0xFFFFB578
RPM = 0xFFFFB548
CANRX_BUF = 0xFFFFC4B0      # CAN 0x047 raw RX buffer (HCAN1 mb39)
RX_PENDING = 0xFFFFC4BF
TX_FRAME = 0xFFFFC1C8       # immo TX frame c1c8..c1d1
IMMO_OK = 0xFFFFC1D0
TX_VALID = 0xFFFFC1D1
SEED_EXPECTED = 0xFFFFC200  # c200
CHALLENGE_RX = 0xFFFFC204   # c204
SEED_RANDOM = 0xFFFFC208    # c208
T_A = 0xFFFFC20C
T_B = 0xFFFFC20E
T_C = 0xFFFFC210
T_D = 0xFFFFC212
T_E = 0xFFFFC214
T_F = 0xFFFFC216
ST_READY = 0xFFFFC21C
ST_MAIN = 0xFFFFC21D
ST_CMD = 0xFFFFC21E
FAIL_CTR = 0xFFFFC21F
KEY_IDX = 0xFFFFC220
REQ_SUB = 0xFFFFC221
ENGINE_OFF = 0xFFFFC222
STATUS = 0xFFFFC224
AUTH_LATCH = 0xFFFFC226
RPM_FLAG = 0xFFFFC228
TX_TRIG = 0xFFFFC229
REJECT = 0xFFFFC22A
READY_FLAG = 0xFFFFC22B
GOOD_LATCH = 0xFFFFC22F
KEY_COUNT = 0xFFFFC282
RX_KEY_WORD = 0xFFFFC1EC
EXP_KEY_WORDS = 0xFFFFC1F0
CAN041_TXBUF = 0xFFFFC4A8
FUEL_CUT = 0xFFFFA430

IMMO_MAIN = 0x34AE2
UNPACK = 0x38150
TX_PACK = 0x380C8
FUEL_CUT_ARB = 0xE2D4

# other fuel-cut inputs read by 0xe2d4, zeroed before the gate check
CUT_FLAGS = (0xFFFFA444, 0xFFFFA4A4, 0xFFFFA964, 0xFFFFC99C, 0xFFFFCC71,
             0xFFFFBC86, 0xFFFFCC72, 0xFFFFCA45, 0xFFFFCDBE, 0xFFFFCDBF,
             0xFFFFCDC0, 0xFFFFCDC1, 0xFFFFA445, 0xFFFFA4A5, 0xFFFFBC87,
             0xFFFFCC73)


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 1000000)
    return bus, cpu


def _wr_frame(bus, cpu, data8):
    for i, b in enumerate(data8):
        bus.write8(CANRX_BUF + i, b)
    harness.call(bus, cpu, UNPACK)
    bus.write8(RX_PENDING, 1)
    bus.write8(0xFFFFC4C0, 1)


def _step(bus, cpu):
    return harness.call(bus, cpu, IMMO_MAIN, max_steps=2000000)


def _prime(bus, cpu):
    bus.write8(ENGINE_RUN, 1)
    bus.write8(STOPPED, 0)
    bus.write32(RPM, struct.unpack(">I", struct.pack(">f", 0.0))[0])
    for a in (ST_READY, ST_MAIN, ST_CMD, FAIL_CTR, KEY_IDX, REQ_SUB,
              ENGINE_OFF, STATUS, AUTH_LATCH, RPM_FLAG, TX_TRIG, REJECT,
              READY_FLAG, GOOD_LATCH, IMMO_OK, TX_VALID):
        bus.write8(a, 0)
    bus.write16(T_A, 500)
    bus.write16(T_B, 500)
    bus.write16(T_C, 0xFA)
    bus.write16(T_D, 15000)
    bus.write16(T_E, 500)
    bus.write16(T_F, 0x2EE)
    bus.write8(KEY_COUNT, 2)


def test_seed_request_then_matching_challenge_authorizes(booted):
    bus, cpu = booted
    _prime(bus, cpu)

    # keyless module requests the seed: cmd 0x06, data0 0x7f
    _wr_frame(bus, cpu, [0x06, 0x7F, 0, 0, 0, 0, 0, 0])
    _step(bus, cpu)
    assert bus.read8(ST_CMD) == 1 and bus.read8(REQ_SUB) == 2
    # same cycle dispatched state 0 -> wait-for-key -> seed path
    assert bus.read8(ST_MAIN) == 2
    seed = bus.read32(SEED_EXPECTED)
    assert seed != 0
    # TX frame: cmd 0x07 with the raw random seed, big-endian
    assert bus.read8(TX_FRAME) == 0x07
    assert bus.read8(TX_VALID) == 1
    raw = bus.read32(SEED_RANDOM)
    assert bytes(bus.read8(TX_FRAME + i) for i in range(1, 5)) == struct.pack(">I", raw)
    # immo OK flag set while 2 keys are registered
    assert bus.read8(IMMO_OK) == 1

    # TX pack copies the frame into the CAN 0x041 buffer
    harness.call(bus, cpu, TX_PACK)
    txbuf = bytes(bus.read8(CAN041_TXBUF + i) for i in range(8))
    assert txbuf[0] == 0x07 and txbuf[1:5] == struct.pack(">I", raw)

    # keyless module answers cmd 0x08 with the matching computed seed
    _wr_frame(bus, cpu, [0x08] + list(struct.pack(">I", seed)) + [0, 0, 0])
    _step(bus, cpu)
    assert bus.read32(CHALLENGE_RX) == seed
    assert bus.read8(STATUS) == 0x7F
    assert bus.read8(ST_MAIN) == 3          # authorized state
    assert bus.read8(IMMO_OK) == 1
    assert bus.read8(REJECT) == 0
    assert bus.read8(TX_FRAME) == 0x81       # verdict frame, status OK
    assert bus.read8(TX_FRAME + 1) == 0x7F


def test_wrong_challenge_is_rejected(booted):
    bus, cpu = booted
    _prime(bus, cpu)
    _wr_frame(bus, cpu, [0x06, 0x7F, 0, 0, 0, 0, 0, 0])
    _step(bus, cpu)
    assert bus.read8(ST_MAIN) == 2
    # wrong challenge word
    _wr_frame(bus, cpu, [0x08, 0xDE, 0xAD, 0xBE, 0xEF, 0, 0, 0])
    _step(bus, cpu)
    assert bus.read32(CHALLENGE_RX) == 0xDEADBEEF
    assert bus.read8(STATUS) == 0x81
    assert bus.read8(ST_MAIN) == 4          # rejected state
    assert bus.read8(IMMO_OK) == 0
    assert bus.read8(REJECT) == 1
    assert bus.read8(TX_FRAME) == 0x01       # verdict frame, status NG
    assert bus.read8(TX_FRAME + 1) == 0x81


def test_key_word_exchange_completes(booted):
    bus, cpu = booted
    _prime(bus, cpu)
    # begin key exchange
    _wr_frame(bus, cpu, [0xC9, 0, 0, 0, 0, 0, 0, 0])
    _step(bus, cpu)
    assert bus.read8(ST_CMD) == 3
    assert bus.read8(ST_MAIN) == 1
    assert bus.read8(KEY_IDX) == 1
    expected = [bus.read32(EXP_KEY_WORDS + 4 * i) for i in range(4)]
    # each expected word carries its tag in the top byte (1..4)
    assert [w >> 24 for w in expected] == [1, 2, 3, 4]
    # PCM transmits computed key word #c220 (cmd 0x09)
    assert bus.read8(TX_FRAME) == 0x09
    assert bus.read8(TX_FRAME + 1) == 1
    harness.call(bus, cpu, TX_PACK)
    txbuf = bytes(bus.read8(CAN041_TXBUF + i) for i in range(8))
    assert txbuf[1:5] == struct.pack(">I", expected[0])

    for sub in (1, 2, 3, 4):
        w = expected[sub - 1]
        _wr_frame(bus, cpu, [0x90] + list(struct.pack(">I", w)) + [0, 0, 0])
        _step(bus, cpu)
        assert bus.read32(RX_KEY_WORD) == w
    # after the 4th matching word the exchange completes: back to state 0, TX 0xc6
    assert bus.read8(ST_MAIN) == 0
    assert bus.read8(TX_FRAME) == 0xC6
    assert bus.read8(REJECT) == 0


def test_immo_ok_flag_gates_fuel_cut(booted):
    bus, cpu = booted
    for a in CUT_FLAGS:
        bus.write8(a, 0)
    bus.write8(IMMO_OK, 1)
    harness.call(bus, cpu, FUEL_CUT_ARB)
    assert bus.read16(FUEL_CUT) == 0x0000
    bus.write8(IMMO_OK, 0)
    harness.call(bus, cpu, FUEL_CUT_ARB)
    assert bus.read16(FUEL_CUT) == 0x0003  # both rotor banks cut
