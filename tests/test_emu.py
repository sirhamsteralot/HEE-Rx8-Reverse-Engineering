"""Tests for the SH-2E emulator (utilities/scripts/emu). Run: python -m pytest tests/test_emu.py"""
import os
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

from bus import Bus  # noqa: E402
from peripherals import WDT, GPIO, RegisterFile  # noqa: E402
from profile import load_profile, list_profiles  # noqa: E402
from sh2e import SH2E, UnknownOpcode  # noqa: E402
import emu  # noqa: E402

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
PROFILES = os.path.join(EMU, "profiles")

IO = [0xFFFFE000, 0x100000000]
RAM = [0xFFFF6000, 0xFFFFE000]


def make_bus(rom=b"\x00" * 0x100):
    return Bus({"rom": [0, len(rom)], "ram": RAM, "io": IO}, rom)


# --- profiles ---------------------------------------------------------------

def test_all_profiles_valid_and_rom_hash_ok():
    paths = list_profiles(PROFILES)
    assert len(paths) >= 2
    for p in paths:
        prof = load_profile(p, REPO_ROOT)
        assert prof["rom"]["_size"] == prof["rom"]["size"]


def test_profile_rejects_bad_hash(tmp_path):
    import json
    prof = load_profile(os.path.join(PROFILES, "60E0FC00_N3Z2EU.json"), REPO_ROOT)
    bad = dict(prof)
    bad["rom"] = dict(prof["rom"], sha256="0" * 64)
    bp = tmp_path / "bad.json"
    bp.write_text(json.dumps(bad))
    with pytest.raises(Exception):
        load_profile(str(bp), REPO_ROOT)


# --- bus --------------------------------------------------------------------

def test_bus_rom_ram_routing():
    bus = make_bus(bytes(range(256)))
    assert bus.read8(0x10) == 0x10
    assert bus.read16(0x20) == 0x2021
    assert bus.read32(0x40) == 0x40414243
    bus.write32(0xFFFF6000, 0xDEADBEEF)
    assert bus.read32(0xFFFF6000) == 0xDEADBEEF


def test_bus_mmio_dispatch_and_log():
    bus = make_bus()
    rf = RegisterFile(0xFFFF8000, 4, {})
    bus.add_peripheral(0xFFFF8000, 4, rf)
    bus.pc = 0x1234
    bus.write32(0xFFFF8000, 0x42)
    assert rf.regs[0:4] == b"\x00\x00\x00\x42"
    assert bus.mmio_log[-1][2:] == (0xFFFF8000, 0x42, 4)
    assert bus.read32(0xFFFF8000) == 0x42


# --- cpu --------------------------------------------------------------------

# mov #0x42,r0 ; mov.l @(3,pc),r1 ; mov.l r0,@r1 ; bra +1 ; nop ; (skipped) ; bra -2 self-loop ; nop ; literal
PROG = bytes.fromhex(
    "e042" "d103" "2101" "a001" "0009" "e343" "affe" "0009" "ffff8000"
)


def test_cpu_hand_assembled_program():
    bus = make_bus(bytes(PROG).ljust(0x100, b"\x00"))
    rf = RegisterFile(0xFFFF8000, 4, {})
    bus.add_peripheral(0xFFFF8000, 4, rf)
    cpu = SH2E(bus)
    bus.cpu = cpu
    cpu.reset(0, 0xFFFF7000)
    for _ in range(10):
        bus.pc = cpu.pc
        cpu.step()
        bus.tick(1)
    assert cpu.r[0] == 0x42
    assert bus.read32(0xFFFF8000) == 0x42
    assert cpu.r[3] == 0  # bra skipped the mov #0x43
    assert cpu.pc == 0x0C  # self-loop


def test_cpu_unknown_opcode_stops():
    bus = make_bus(bytes.fromhex("0001"))  # not implemented
    cpu = SH2E(bus)
    cpu.reset(0, 0xFFFF7000)
    with pytest.raises(UnknownOpcode):
        cpu.step()


# --- watchdog ---------------------------------------------------------------

def test_wdt_overflow_fires_vector_and_service_clears():
    rom = bytearray(0x100)
    rom[0x40:0x44] = (0x00000200).to_bytes(4, "big")  # handler at 0x200 via vector slot 0x40
    bus = make_bus(bytes(rom))
    wdt = WDT(0xFFFFEC10, 3, {"enabled": True, "overflow_vector": 0x40})
    bus.add_peripheral(0xFFFFEC10, 3, wdt)
    cpu = SH2E(bus)
    bus.cpu = cpu
    cpu.reset(0x100, 0xFFFF7000)
    bus.write8(0xFFFFEC11, 0xFF)  # TCNT = 0xFF
    bus.tick(1)  # wraps -> OVF + interrupt
    assert bus.read8(0xFFFFEC10) & 0x80
    assert cpu.pc == 0x200
    bus.write16(0xFFFFEC10, 0xA53C)  # keyed service write
    assert not (bus.read8(0xFFFFEC10) & 0x80)


# --- gpio heartbeat ---------------------------------------------------------

def test_gpio_pb15_heartbeat_logged():
    bus = make_bus()
    gpio = GPIO(0xFFFFF700, 0x80, {"heartbeat": {"port_reg_offset": 0x38, "bit": 15}})
    bus.add_peripheral(0xFFFFF700, 0x80, gpio)
    bus.write16(0xFFFFF738, 0x8000)
    bus.write16(0xFFFFF738, 0x0000)
    assert [b for _, b in gpio.heartbeats] == [1, 0]


# --- real ROM smoke ---------------------------------------------------------

def test_real_rom_boot_smoke():
    prof, bus, cpu = emu.build(os.path.join(PROFILES, "60E15120_N3J1E.json"))
    stop = emu.run(prof, bus, cpu, cycles=20000)
    assert cpu.icount > 0
    assert "unknown opcode" in stop or "cycle limit" in stop


# --- trace comparator -------------------------------------------------------

def test_compare_traces(tmp_path):
    import compare_traces
    a = tmp_path / "a.txt"
    b = tmp_path / "b.txt"
    c = tmp_path / "c.txt"
    a.write_text("0 0x00000100\n1 0x00000102\n# mmio 0 0x100 0xfffff738 0x8000 2\n2 0x00000104\n")
    b.write_text("0x100\n0x102\n0x104\n")
    c.write_text("0x100\n0x999\n")
    assert compare_traces.main([str(a), str(b)]) == 0
    assert compare_traces.main([str(a), str(c)]) == 1
