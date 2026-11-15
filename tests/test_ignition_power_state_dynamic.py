"""Dynamic (emulator) verification of the ignition key-state / power-state findings.

Executes the real ROM code of 60E15120_N3J1E in the SH-2E emulator and checks
the behavior claimed in docs/investigations/60E15120_N3J1E/ignition_power_state_report.md:

- boot warm/cold entry selection in reset_handler_warm_cold_select 0x4e0
  (magic 0x5aa5a55a @0xffffdffc -> warm stub 0x1298, else cold 0x6c8) and the
  boot NMI poll loop 0x8ea (waits for ICR_W 0xffffed18 bit15 high)
- key-on pin PFDR bit0 driven through the real GPIO read path (profile input
  0x4e) -> latch 0xffff9ec8 (0x6744) -> 0xffffaa69 (0x1a5d8) -> 0xffffaa68
  (0x1a600); key on/off timers 0x195cc/0x195f4; RPM hysteresis 0xe274
  -> 0xffffa428; PF15 sample/edge latch 0x454c0/0x454d2 -> 0xffffcbd0/cbd1
- key-off state machine 0x252c2 via 0x253e8: arm -> counting -> shutdown
  (timeout u32@ROM 0x74940 = 0x36ee8 and the early condition), E2-shadow
  0xffff8104 = 1, then shutdown_wait_key_pin_then_halt 0x9ea2 (PFDR bit3
  cleared, external WDT pulsed while PFDR bit0 low, halt at 0x9efe when high)
- relay hold: relay_hold_output_pd11 0x251d0 drives PDDR_W bit 0x800 from
  NOT shutdown_allowed 0xffffccc1 (computed by shutdown_allowed_flag 0x48cc0)

Sensor/pin inputs enter through the hardware paths only (GPIO scripted input
pins OR'd into PFDR reads; ADC/ATU2 not needed here). RAM globals a callee
reads are set explicitly via harness ram= and stated per test.

Run: python -m pytest tests/test_ignition_power_state_dynamic.py
"""
import os
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

PFDR_W = 0xFFFFF74E
PFDR_OFF = 0x4E          # PFDR_W offset inside the GPIO block (base 0xfffff700)
PDDR_W = 0xFFFFF746
ICR_W = 0xFFFFED18

WARM_MAGIC_RAM = 0xFFFFDFFC
WARM_MAGIC = 0x5AA5A55A
WARM_STUB = 0x1298
COLD_ENTRY = 0x6C8
NMI_POLL = 0x8EA
HALT_LOOP = 0x9EFE       # ref_whileLoop (infinite) reached from 0x9ea2
KEY_OFF_TIMEOUT = 0x36EE8  # u32 @ ROM 0x74940


def _gpio(bus):
    return next(p for _, _, p in bus.peripherals if type(p).__name__ == "GPIO")


def _sysc(bus):
    return next(p for _, _, p in bus.peripherals if type(p).__name__ == "SYSC")


def set_key_pin(bus, high):
    """Drive the ignition key pin (PFDR bit0) through the GPIO hardware path.

    The GPIO model ORs scripted inputs into reads, but the firmware's port
    init wrote the output latch, and OR-ing cannot pull a pin low — so the pin
    level is also forced into the data-register bit (still the PFDR register
    path, not firmware RAM)."""
    g = _gpio(bus)
    g.inputs[PFDR_OFF] = 1 if high else 0
    if high:
        g.regs[PFDR_OFF + 1] |= 0x01   # PF0 = bit0 of the PFDR word = low byte bit0
    else:
        g.regs[PFDR_OFF + 1] &= 0xFE


def set_pf15(bus, high):
    """Drive PF15 (PFDR bit15 = high byte bit7) the same way."""
    g = _gpio(bus)
    g.inputs[PFDR_OFF] = (g.inputs.get(PFDR_OFF, 0) & 0xFF) | (0x8000 if high else 0)
    if high:
        g.regs[PFDR_OFF] |= 0x80
    else:
        g.regs[PFDR_OFF] &= 0x7F


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    assert cpu.pc == 0x3DAC, f"boot did not park in idle loop: pc=0x{cpu.pc:08x}"
    return prof, bus, cpu


# --- boot: warm/cold split + NMI poll ---------------------------------------

def test_boot_magic_selects_warm_stub():
    prof, bus, cpu = emu.build(PROFILE)
    bus.write32(WARM_MAGIC_RAM, WARM_MAGIC)  # RAM retained across reset = warm
    trace = []
    emu.run(prof, bus, cpu, 200000, trace)
    assert WARM_STUB in trace, "warm stub 0x1298 never executed despite magic"
    assert COLD_ENTRY not in trace, "cold entry 0x6c8 executed despite warm magic"
    assert bus.read32(WARM_MAGIC_RAM) == WARM_MAGIC


def test_reset_handler_param0_magic_selects_warm(booted):
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x4E0, r_args=(0, 0), stop_at=(WARM_STUB, COLD_ENTRY),
                 ram={WARM_MAGIC_RAM: (4, WARM_MAGIC)})
    assert cpu.pc == WARM_STUB, "param==0 + magic 0x5aa5a55a must select the warm stub 0x1298"
    assert bus.read32(WARM_MAGIC_RAM) == WARM_MAGIC, "0x4e0 rewrites the magic before entry"


def test_reset_handler_param0_no_magic_takes_warm_via_wdt_overflow(booted):
    # no magic: 0x4e0 calls 0x5b0(7); each TCNT wrap sets TCSR OVF and is counted,
    # so after 7 overflows 0x5b0 returns 1 -> warm entry (watchdog reset = warm)
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x4E0, r_args=(0, 0), stop_at=(WARM_STUB, COLD_ENTRY),
                 ram={WARM_MAGIC_RAM: (4, 0)}, max_steps=300000)
    assert cpu.pc == WARM_STUB, "param==0 without magic + WDT overflow must still take the warm stub"


def test_reset_handler_param_nonzero_selects_cold_and_stores_cause(booted):
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x4E0, r_args=(1, 0x42), stop_at=(WARM_STUB, COLD_ENTRY),
                 ram={WARM_MAGIC_RAM: (4, 0)})
    assert cpu.pc == COLD_ENTRY, "param!=0 must select the cold entry 0x6c8"
    assert bus.read8(0xFFFFDFA8) == 0x42, "param_2 must land in the reset-cause cell"
    assert bus.read32(WARM_MAGIC_RAM) == WARM_MAGIC


def test_fresh_boot_with_wdt_enabled_takes_warm_via_overflow():
    # stock-profile boot: TCNT wraps within the first 256 cycles, so 0x5b0 sees
    # TCSR OVF and 0x4e0 picks the warm entry even with zeroed RAM; boot then
    # parks in the idle loop
    prof, bus, cpu = emu.build(PROFILE)
    trace = []
    emu.run(prof, bus, cpu, 200000, trace)
    assert WARM_STUB in trace and COLD_ENTRY not in trace
    assert cpu.pc == 0x3DAC, f"stock boot did not reach idle: pc=0x{cpu.pc:08x}"


def test_boot_nmi_poll_waits_for_icr_bit15_high():
    prof, bus, cpu = emu.build(PROFILE)
    _sysc(bus).nmi_level = 0  # NMI pin low: ICR_W 0xffffed18 bit15 reads 0
    trace = []
    emu.run(prof, bus, cpu, 30000, trace)
    assert NMI_POLL in trace
    assert max(trace) < 0x8F6, "boot left the 0x8ea NMI poll loop with NMI low"
    # with the pin high (profile default) the same boot passes the poll:
    prof2, bus2, cpu2 = emu.build(PROFILE)
    trace2 = []
    emu.run(prof2, bus2, cpu2, 300000, trace2)
    assert any(pc >= 0x8F6 for pc in trace2), "boot stuck in NMI poll with NMI high"
    assert cpu2.pc == 0x3DAC


# --- running: key pin -> latch chain ----------------------------------------

def test_key_pin_drives_latch_chain_through_pfdr(booted):
    _, bus, cpu = booted
    try:
        set_key_pin(bus, True)
        harness.call(bus, cpu, 0x6744, ram={0xFFFF9EC8: (2, 0)})  # poll (16-bit latch store)
        assert bus.read16(0xFFFF9EC8) & 1 == 1, "PFDR bit0 high must set latch bit0"
        harness.call(bus, cpu, 0x1A5D8, ram={0xFFFFAA69: (1, 0)})
        assert bus.read8(0xFFFFAA69) == 1
        harness.call(bus, cpu, 0x1A600, ram={0xFFFFAA68: (1, 0)})
        assert bus.read8(0xFFFFAA68) == 1, "key-on flag must follow the latch"

        set_key_pin(bus, False)
        harness.call(bus, cpu, 0x6744, ram={0xFFFF9EC8: (2, 0)})
        assert bus.read16(0xFFFF9EC8) & 1 == 0, "PFDR bit0 low must clear latch bit0"
        harness.call(bus, cpu, 0x1A5D8)
        assert bus.read8(0xFFFFAA69) == 0
        harness.call(bus, cpu, 0x1A600)
        assert bus.read8(0xFFFFAA68) == 0
    finally:
        set_key_pin(bus, True)


def test_key_on_off_timers(booted):
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x195CC, ram={0xFFFFAA68: (1, 1), 0xFFFFA9E0: (2, 41)})
    assert bus.read16(0xFFFFA9E0) == 42, "key-on: 0xffffa9e0 saturating ++"
    harness.call(bus, cpu, 0x195CC, ram={0xFFFFAA68: (1, 0)})
    assert bus.read16(0xFFFFA9E0) == 0, "key-off: 0xffffa9e0 reset to 0"
    harness.call(bus, cpu, 0x195F4, ram={0xFFFFAA68: (1, 0), 0xFFFFA9E2: (2, 7)})
    assert bus.read16(0xFFFFA9E2) == 8, "key-off: 0xffffa9e2 saturating ++"
    harness.call(bus, cpu, 0x195F4, ram={0xFFFFAA68: (1, 1)})
    assert bus.read16(0xFFFFA9E2) == 0, "key-on: 0xffffa9e2 reset to 0"


def test_engine_running_rpm_hysteresis(booted):
    _, bus, cpu = booted
    rpm = lambda v: {0xFFFFB548: (4, harness.bits(float(v))), 0xFFFFA428: (1, 0)}
    harness.call(bus, cpu, 0xE274, ram=rpm(3000.0))
    assert bus.read8(0xFFFFA428) == 1, ">= 500 rpm sets engine_running"
    harness.call(bus, cpu, 0xE274, ram={0xFFFFB548: (4, harness.bits(300.0))})
    assert bus.read8(0xFFFFA428) == 1, "250..500 rpm holds the flag (hysteresis)"
    harness.call(bus, cpu, 0xE274, ram={0xFFFFB548: (4, harness.bits(200.0))})
    assert bus.read8(0xFFFFA428) == 0, "< 250 rpm clears engine_running"
    harness.call(bus, cpu, 0xE274, ram={0xFFFFB548: (4, harness.bits(500.0))})
    assert bus.read8(0xFFFFA428) == 1


def test_pf15_sample_and_edge_latch(booted):
    _, bus, cpu = booted
    try:
        set_pf15(bus, True)
        harness.call(bus, cpu, 0x454C0, ram={0xFFFFCBD1: (1, 9)})
        assert bus.read8(0xFFFFCBD1) == 0, "pin high -> prev sample 0"
        set_pf15(bus, False)
        harness.call(bus, cpu, 0x454C0)
        assert bus.read8(0xFFFFCBD1) == 1, "pin low -> prev sample 1"
        # edge latch: sustained low sets 0xffffcbd0 (two-call debounce), high clears
        harness.call(bus, cpu, 0x454D2, ram={0xFFFFCBD0: (1, 0), 0xFFFFCBD1: (1, 1)})
        harness.call(bus, cpu, 0x454D2)
        assert bus.read8(0xFFFFCBD0) == 1, "PF15 low sustained -> edge latch set"
        set_pf15(bus, True)
        harness.call(bus, cpu, 0x454D2)
        harness.call(bus, cpu, 0x454D2)
        assert bus.read8(0xFFFFCBD0) == 0, "PF15 high sustained -> edge latch clear"
    finally:
        set_pf15(bus, False)
        set_key_pin(bus, True)


# --- key-off shutdown ---------------------------------------------------------

def test_key_off_state_machine_arm_count_timeout_halt(booted):
    _, bus, cpu = booted
    set_key_pin(bus, True)  # key pin high: 0x9ea2 wait loop exits to the halt
    # arm: key on, state 0
    harness.call(bus, cpu, 0x253E8, stop_at=(HALT_LOOP,), ram={
        0xFFFFAA68: (1, 1), 0xFFFFB57A: (1, 0), 0xFFFFB57C: (4, 0),
        0xFFFFB579: (1, 0), 0xFFFFB578: (1, 0), 0xFFFFB580: (1, 0),
        0xFFFFDF99: (1, 0), 0xFFFF8104: (1, 0),
    })
    assert bus.read8(0xFFFFDF99) == 0x5A and bus.read8(0xFFFFB579) == 1
    assert bus.read8(0xFFFFB57A) == 0, "armed but still state 0"
    # engine stopped (key off): state 0 -> 1
    harness.call(bus, cpu, 0x253E8, stop_at=(HALT_LOOP,), ram={0xFFFFAA68: (1, 0)})
    assert bus.read8(0xFFFFB57A) == 1 and bus.read8(0xFFFFB578) == 1
    # counting: timer increments, state stays 1 below the timeout
    harness.call(bus, cpu, 0x253E8, stop_at=(HALT_LOOP,),
                 ram={0xFFFFAA68: (1, 0), 0xFFFFB57C: (4, 0)})
    assert bus.read8(0xFFFFB57A) == 1 and bus.read32(0xFFFFB57C) == 1
    # timeout reached (u32@ROM 0x74940 = 0x36ee8): state 2, E2-shadow set,
    # then jmp shutdown_wait_key_pin_then_halt 0x9ea2 -> halt at 0x9efe
    bus.write16(PFDR_W, 0x0008)  # PF3 set beforehand; 0x9ea2 must clear it
    harness.call(bus, cpu, 0x253E8, stop_at=(HALT_LOOP,), ram={
        0xFFFFAA68: (1, 0), 0xFFFFB57C: (4, KEY_OFF_TIMEOUT - 1),
        0xFFFF8104: (1, 0), 0xFFFFDF99: (1, 0x5A),
    })
    assert bus.read8(0xFFFFB57A) == 2
    assert bus.read32(0xFFFFB57C) == KEY_OFF_TIMEOUT
    assert bus.read8(0xFFFF8104) == 1, "E2-shadow shutdown flag set"
    assert bus.read8(0xFFFFDF99) == 0
    assert cpu.pc == HALT_LOOP, "shutdown path must end in the 0x9efe halt loop"
    assert (bus.read16(PFDR_W) & 8) == 0, "0x9ea2 clears PFDR bit3"


def test_key_off_early_condition(booted):
    _, bus, cpu = booted
    set_key_pin(bus, True)
    # counting with b57c >= 0x19 and 0xffffb582 <= 0xffffb583 -> immediate shutdown
    harness.call(bus, cpu, 0x253E8, stop_at=(HALT_LOOP,), ram={
        0xFFFFAA68: (1, 0), 0xFFFFB57A: (1, 1), 0xFFFFB57C: (4, 0x19),
        0xFFFFB582: (1, 0), 0xFFFFB583: (1, 5), 0xFFFF8104: (1, 0),
    })
    assert bus.read8(0xFFFFB57A) == 2 and bus.read8(0xFFFF8104) == 1
    assert cpu.pc == HALT_LOOP


def test_shutdown_wait_pulses_external_wdt_while_key_pin_low(booted):
    _, bus, cpu = booted
    g = _gpio(bus)
    try:
        set_key_pin(bus, False)  # key pin low: 0x9ea2 must wait, pulsing PB15
        hb0 = len(g.heartbeats)
        try:
            # the 0x239c(0x1388) busy-wait alone is ~80k steps per loop iteration
            harness.call(bus, cpu, 0x9EA2, max_steps=200000)
        except RuntimeError:
            pass  # expected: the wait loop never returns while the pin is low
        assert cpu.pc != HALT_LOOP, "halted although key pin still low"
        assert len(g.heartbeats) > hb0, "external WDT (PB15) not pulsed in wait loop"
        set_key_pin(bus, True)   # key returns: loop exits to the halt
        harness.call(bus, cpu, 0x9EA2, stop_at=(HALT_LOOP,))
        assert cpu.pc == HALT_LOOP
    finally:
        set_key_pin(bus, True)


# --- relay hold / shutdown allowance ------------------------------------------

def test_relay_hold_pd11_follows_shutdown_allowed(booted):
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x251D0, ram={0xFFFFCCC1: (1, 1)})
    assert bus.read8(0xFFFFB574) == 0
    assert (bus.read16(PDDR_W) & 0x800) == 0, "shutdown allowed -> PD11 low"
    harness.call(bus, cpu, 0x251D0, ram={0xFFFFCCC1: (1, 0)})
    assert bus.read8(0xFFFFB574) == 1
    assert (bus.read16(PDDR_W) & 0x800) == 0x800, "shutdown not allowed -> PD11 high (relay held)"


def test_shutdown_allowed_flag_conditions(booted):
    _, bus, cpu = booted
    base = {0xFFFFAA68: (1, 0), 0xFFFFB4EE: (1, 0), 0xFFFFCCB6: (1, 0),
            0xFFFFCCA0: (1, 0), 0xFFFFAD60: (1, 0), 0xFFFFAD61: (1, 0),
            0xFFFF80A2: (1, 0), 0xFFFFB51A: (1, 0), 0xFFFFCCC1: (1, 0)}
    r0, _, _ = harness.call(bus, cpu, 0x48CC0, ram={**base, 0xFFFFAA68: (1, 1)})
    assert r0 == 1 and bus.read8(0xFFFFCCC1) == 1, "key on -> shutdown allowed"
    harness.call(bus, cpu, 0x48CC0, ram=base)
    assert bus.read8(0xFFFFCCC1) == 0, "key off, no alt condition -> not allowed"
    r0, _, _ = harness.call(bus, cpu, 0x48CC0,
                            ram={**base, 0xFFFFB4EE: (1, 1), 0xFFFFCCB6: (1, 0x100)})
    assert r0 == 1 and bus.read8(0xFFFFCCC1) == 1, "b4ee && ccb6 < 0x271 -> allowed"
    harness.call(bus, cpu, 0x48CC0, ram={**base, 0xFFFFAA68: (1, 1), 0xFFFFCCA0: (1, 1)})
    assert bus.read8(0xFFFFCCC1) == 0, "cca0 set -> not allowed"


def test_external_wdt_heartbeat_pulse_toggles_pb15(booted):
    _, bus, cpu = booted
    g = _gpio(bus)
    hb0 = len(g.heartbeats)
    harness.call(bus, cpu, 0xA850)
    assert len(g.heartbeats) >= hb0 + 2, "0xa850 must toggle PBDR bit15 (set+clear)"
