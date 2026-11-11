"""CAN mailbox configuration compare: emulator validation of 0x2a4f8
hcan_mailbox_config_compare(channel, recs) (60E15120_N3J1E).

Builds the expected live HCAN register image from the ROM descriptor blocks
(0x4e01c: 16 records, 0x4e21c: 6 records), writes it to the emulated
controllers, and asserts the compare returns 0 on a match and nonzero on
perturbed registers — both channels.
Run: python -m pytest tests/test_can_mailbox_config_dynamic.py
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
ROM_PATH = os.path.join(
    os.path.dirname(__file__), "..", "submodules", "Mazda_RX8_PCM_ReverseEngineering",
    "Stock_ROMs", "60E15120_N3J1E.bin")
ROM = open(ROM_PATH, "rb").read()

CAN_COMPARE = 0x2A4F8


def _u32(a):
    return struct.unpack(">I", ROM[a:a + 4])[0]


def _can_expected_regs(block, count, mbcr, mbimr):
    """Expected live HCAN register image that 0x2a4f8 builds from the 16-byte
    descriptor records (MC[k] of mailbox mb at base+0x20+mb*8+(k-1); standard
    id: MC[5]=(id&0xff)<<5, MC[6]=id>>3; extended: MC[5..8] as in the code).
    BCR=0x803e, IMR=0xfcfe, MCR=0, LAFM=0. MBCR/MBIMR are the values the ROM's
    own build loops produce (captured at the compare sites 0x2a5c6/0x2a5d4
    for ch0, 0x2a65e/0x2a66c for ch1)."""
    regs = {0x00: (1, 0), 0x02: (2, 0x803E), 0x04: (2, mbcr), 0x14: (2, mbimr),
            0x16: (2, 0xFCFE), 0x1C: (2, 0), 0x1E: (2, 0)}
    for i in range(count):
        rec = block + i * 16
        mb = ROM[rec + 5] & 0xF
        mc = 0x20 + mb * 8
        regs[mc + 0] = (1, ROM[rec + 6])                 # MC[1] = control
        rid = _u32(rec)
        if ROM[rec + 7] == 0:                            # standard 11-bit
            regs[mc + 4] = (1, (ROM[rec + 7] * 8 + ((rid & 0xFF) << 5)) & 0xFF)
            regs[mc + 5] = (1, (rid >> 3) & 0xFF)
        else:                                            # extended 29-bit
            regs[mc + 4] = (1, ((rid >> 0x12 & 7) * 0x20 + (rid >> 0x10 & 3)
                                + ROM[rec + 7] * 8) & 0xFF)
            regs[mc + 5] = (1, (rid >> 0x15) & 0xFF)
            regs[mc + 6] = (1, rid & 0xFF)
            regs[mc + 7] = (1, (rid >> 8) & 0xFF)
    return regs


def _apply(bus, base, regs):
    for off, (size, v) in regs.items():
        (bus.write8 if size == 1 else bus.write16)(base + off, v)


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return prof, bus, cpu


def test_mailbox_config_compare(booted):
    _, bus, cpu = booted
    regs0 = _can_expected_regs(0x4E01C, 16, 0x0100, 0x0100)
    _apply(bus, 0xFFFFE400, regs0)
    r0, _, _ = harness.call(bus, cpu, CAN_COMPARE, r_args=(0, 0x4E01C))
    assert r0 == 0                                   # full match
    old = bus.read8(0xFFFFE428)                      # MC[1] of mailbox 1
    bus.write8(0xFFFFE428, old ^ 0xFF)
    assert harness.call(bus, cpu, CAN_COMPARE, r_args=(0, 0x4E01C))[0] != 0
    bus.write8(0xFFFFE428, old)
    bus.write16(0xFFFFE402, 0)                       # BCR wrong
    assert harness.call(bus, cpu, CAN_COMPARE, r_args=(0, 0x4E01C))[0] != 0
    _apply(bus, 0xFFFFE400, regs0)

    regs1 = _can_expected_regs(0x4E21C, 6, 0x0100, 0x09FF)
    _apply(bus, 0xFFFFE600, regs1)
    r0, _, _ = harness.call(bus, cpu, CAN_COMPARE, r_args=(1, 0x4E21C))
    assert r0 == 0
    bus.write16(0xFFFFE616, 0)                       # IMR wrong on HCAN1
    assert harness.call(bus, cpu, CAN_COMPARE, r_args=(1, 0x4E21C))[0] != 0


CAN_CONTROLLER_SETUP = 0x9744     # ref_CANControllerSetup(ch, recs, count)
BUS_OFF_FLAG = 0x9AC4             # hcan_bus_off_flag(ch) = HCANx_GSR_B bit0


def test_controller_setup_writes_record_fields(booted):
    """Writer path of the descriptor records (mulu-free parts): BCR/IMR
    constants and the per-mailbox MC control + ID bytes come straight from
    record bytes +6/+7 and word0. The MBCR/MBIMR bit writes use MULU.W, which
    the emulator models with the product in the operand register instead of
    MACL, so those two registers are not asserted here."""
    _, bus, cpu = booted
    for ch, block, count, base in ((0, 0x4E11C, 16, 0xFFFFE400),
                                   (0, 0x4E01C, 16, 0xFFFFE400),
                                   (1, 0x4E21C, 6, 0xFFFFE600)):
        harness.call(bus, cpu, CAN_CONTROLLER_SETUP, r_args=(ch, block, count))
        assert bus.read16(base + 0x02) == 0x803E          # BCR_W
        assert bus.read16(base + 0x16) == 0xFCFE          # IMR_W
        for i in range(count):
            rec = block + i * 16
            mb = ROM[rec + 5] & 0xF
            mc = base + 0x20 + mb * 8
            assert bus.read8(mc + 0) == ROM[rec + 6]      # MC control byte = record +6
            rid = _u32(rec)
            if ROM[rec + 7] == 0:                         # standard 11-bit id
                assert bus.read8(mc + 4) == ((ROM[rec + 7] * 8 + ((rid & 0xFF) << 5)) & 0xFF)
                assert bus.read8(mc + 5) == ((rid >> 3) & 0xFF)
            else:                                         # extended 29-bit id
                assert bus.read8(mc + 4) == (((rid >> 0x12 & 7) * 0x20 + (rid >> 0x10 & 3)
                                              + ROM[rec + 7] * 8) & 0xFF)
                assert bus.read8(mc + 5) == ((rid >> 0x15) & 0xFF)
                assert bus.read8(mc + 6) == (rid & 0xFF)
                assert bus.read8(mc + 7) == ((rid >> 8) & 0xFF)


def test_bus_off_flag_reads_gsr_bit0(booted):
    """hcan_bus_off_flag 0x9ac4 returns (HCANx_GSR_B & 1) != 0 per channel."""
    _, bus, cpu = booted
    bus.write8(0xFFFFE401, 0x00)
    bus.write8(0xFFFFE601, 0x00)
    assert harness.call(bus, cpu, BUS_OFF_FLAG, r_args=(0,))[0] == 0
    assert harness.call(bus, cpu, BUS_OFF_FLAG, r_args=(1,))[0] == 0
    bus.write8(0xFFFFE401, 0x01)                          # HCAN0 GSR bit0 set
    assert harness.call(bus, cpu, BUS_OFF_FLAG, r_args=(0,))[0] == 1
    assert harness.call(bus, cpu, BUS_OFF_FLAG, r_args=(1,))[0] == 0
    bus.write8(0xFFFFE601, 0x01)                          # HCAN1 GSR bit0 set
    assert harness.call(bus, cpu, BUS_OFF_FLAG, r_args=(1,))[0] == 1
