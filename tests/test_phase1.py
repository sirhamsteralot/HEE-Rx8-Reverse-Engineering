"""Phase 1 tests: full boot, golden trace, ISO-TP, CAN injection, OBD port, UI session."""
import os
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import isotp  # noqa: E402
from can import CANController  # noqa: E402
import obd_port  # noqa: E402
import ui  # noqa: E402

FIXTURE = os.path.join(os.path.dirname(__file__), "fixtures", "boot-60E15120_N3J1E-200k.trace")
PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")


def test_full_boot_no_unknown_opcode_1m():
    prof, bus, cpu = emu.build(PROFILE)
    stop = emu.run(prof, bus, cpu, 1_000_000)
    assert cpu.icount == 1_000_000
    assert "cycle limit" in stop  # no UnknownOpcode
    assert len(bus.mmio_log) > 1000  # peripherals being programmed


def test_wdt_heartbeat_liveliness():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 100_000)
    gpio = next(p for _, _, p in bus.peripherals if type(p).__name__ == "GPIO")
    assert len(gpio.heartbeats) > 100  # PB15 toggling: firmware services the WDT


def test_golden_boot_trace():
    prof, bus, cpu = emu.build(PROFILE)
    trace = []
    emu.run(prof, bus, cpu, 200_000, trace)
    golden = [int(l.split()[1], 16) for l in open(FIXTURE) if not l.startswith("#")]
    assert trace == golden


def test_isotp_roundtrip():
    for payload in (b"\x10\x03", b"\x22\x22\x43", bytes(range(60))):
        frames = isotp.encode(payload, 0x7E0)
        r = isotp.Reassembler()
        out = None
        for _, d in frames:
            out = r.feed(d) or out
        assert out == payload


def test_can_inject_and_tx_log():
    prof, bus, cpu = emu.build(PROFILE)
    can = next(p for _, _, p in bus.peripherals if isinstance(p, CANController))
    can.inject(0x7E0, b"\x02\x10\x03\x00\x00\x00\x00\x00")
    assert can.rx_frames and can.rx_frames[-1][1] == 0x7E0
    can.note_tx(0x7E8, b"\x06\x50\x03\x00\x32\x01\xf4\x00")
    assert can.tx_log[-1][1] == 0x7E8


def test_obd_port_uds_log():
    prof, bus, cpu = emu.build(PROFILE)
    port = obd_port.OBDPort(prof, bus, cpu, port=0)
    port.handle_uds(bytes.fromhex("1003"))
    assert port.uds_log[-1][1] == "req"
    assert port.can.rx_frames  # request reached the emulated CAN bus


def test_ui_session_sensors_run_replay(tmp_path):
    session = ui.EmuSession(PROFILE)
    session.set_sensor("coolant_temp_raw", 90)
    session.run_cycles(5000)
    st = session.state()
    assert st["icount"] >= 5000 and st["profile"] == "60E15120_N3J1E"
    # replay a real log
    csv_path = os.path.abspath(os.path.join(
        os.path.dirname(__file__), "..", "data", "logs", "rx8-666p",
        "trackLog-2026-Oct-04_09-31-12.csv"))
    session.prof.setdefault("replay_map", {})
    session.start_replay(csv_path, speed=1)
    r = session.replay_step()
    assert r and r["of"] > 100
