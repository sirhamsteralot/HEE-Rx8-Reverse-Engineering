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
    # with the corrected peripheral models (RCAN/DMAC/ADC/ATU-II, ROM read-only,
    # RAM 0xffff6000-0xffffe000) boot passes CAN init, programs ATU-II/SCI and
    # reaches the main idle loop at 0x3dac
    assert len(bus.mmio_log) > 200  # peripherals being programmed during init
    assert cpu.pc == 0x3DAC  # idle loop


def test_wdt_heartbeat_liveliness():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 100_000)
    gpio = next(p for _, _, p in bus.peripherals if type(p).__name__ == "GPIO")
    # firmware polls TCSR OVF and services the WDT itself (keyed 0xa53c writes);
    # the external-watchdog heartbeat PB15 toggles when an overflow is seen
    services = [m for m in bus.mmio_log if m[2] == 0xFFFFEC10 and m[3] == 0xA53C]
    assert len(services) >= 5   # firmware's own poll path services the WDT
    assert len(gpio.heartbeats) >= 5  # PB15 toggles when an overflow is seen


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
    emu.run(prof, bus, cpu, 300000)  # boot to idle so the ROM state is set up
    port = obd_port.OBDPort(prof, bus, cpu, port=0)
    port.handle_uds(bytes.fromhex("1003"))
    assert port.uds_log[-1][1] == "req"
    assert port.can.rx_frames  # request reached the emulated CAN bus (RCAN mailbox)
    # the ROM's own CAN RX poller (FUN_00011d88, driven by pump_uds) moved the
    # request into the UDS RX buffer 0xffffddc8 and cleared RXPR
    assert bus.read32(0xFFFFDDC8).to_bytes(4, "big")[:3] == bytes.fromhex("021003")


def test_ui_session_sensors_run_replay(tmp_path):
    session = ui.EmuSession(PROFILE)
    session.set_sensor("coolant_temp", 90)
    session.run_cycles(5000)
    st = session.state()
    assert st["icount"] >= 5000 and st["profile"] == "60E15120_N3J1E"
    # replay a real log
    csv_path = os.path.abspath(os.path.join(
        os.path.dirname(__file__), "..", "data", "logs", "rx8-666p",
        "trackLog-2026-Oct-04_09-31-12.csv"))
    session.start_replay(csv_path, speed=1)
    r = session.replay_step()
    assert r and r["of"] > 100
    # replay actually drove a mapped sensor into the bus overrides
    assert bus_addr_overridden(session)
    # watched emulated output (engine load RAM 0xffffc0b4) is readable
    assert "watch" in r and any("engine_load" in k for k in r["watch"])


def bus_addr_overridden(session):
    # rpm is wired to the real ATU-II crank input-capture path (E2): the ATU2
    # peripheral has a crank wheel period set after the replay drove the sensor
    atu = next((p for _, _, p in session.bus.peripherals if type(p).__name__ == "ATU2"), None)
    return atu is not None and atu._crank_period > 0


# --- debugger: breakpoints, watchpoints, UBC, inspection ---------------------

def test_debugger_breakpoint_and_watchpoint():
    import debugger
    prof, bus, cpu = emu.build(PROFILE)
    dbg = debugger.DebugSession(prof, bus, cpu)
    emu.run(prof, bus, cpu, 1000)
    dbg.add_break(0x31C, "exec")  # WDT overflow handler - recurs every ~256 cycles
    r = dbg.continue_(500000)
    assert "breakpoint at 0x0000031c" in r
    assert cpu.pc == 0x31C
    # write watchpoint on PBDR (toggled by the WDT handler)
    dbg.breaks.clear()
    dbg.add_break(0xFFFFF738, "mem", 2, "write")
    r = dbg.continue_(500000)
    assert r and "watchpoint write at 0xfffff738" in r
    # read watchpoint on WDT TCSR
    dbg.breaks.clear()
    dbg.add_break(0xFFFFEC10, "mem", 1, "read")
    r = dbg.continue_(500000)
    assert r and "watchpoint read" in r


def test_debugger_step_regs_mem_disasm():
    import debugger
    prof, bus, cpu = emu.build(PROFILE)
    dbg = debugger.DebugSession(prof, bus, cpu)
    dbg.step(5)
    assert cpu.icount == 5
    regs = dbg.regs()
    assert "pc" in regs and "r15" in regs
    assert dbg.mem(0x0, 2) == [bus.read32(0), bus.read32(4)]
    d = dbg.disasm(0x8b8, 3)
    assert d[0].startswith("0x000008b8") and "bsr" in d[0]


def test_ubc_hardware_breakpoint():
    import debugger
    from peripherals import UBC
    prof, bus, cpu = emu.build(PROFILE)
    ubc = UBC(0xFFFFFF60, 0x24, {})
    bus.add_peripheral(0xFFFFFF60, 0x24, ubc)
    dbg = debugger.DebugSession(prof, bus, cpu)
    emu.run(prof, bus, cpu, 500)
    # program UBC channel A: break when PC == 0x31c (recurring WDT handler)
    ubc.write(ubc.BARA, 4, 0x0000031C)
    ubc.write(ubc.BAMRA, 4, 0xFFFFFFFF)
    ubc.write(ubc.BRCR, 4, 0x1)
    r = dbg.continue_(500000)
    assert r and "UBC-A" in r and cpu.pc == 0x31C
