#!/usr/bin/env python3
"""Dynamic checks of the engine-start / cranking chain in the SH-2E emulator.

Runs the real ROM code through ``utilities/scripts/emu/harness.py`` and asserts
what `docs/subsystem-logic/starting_cranking_report.md` states for each stage.
The observed values are also written into a stable log and compared against the
committed copy, so the report's dynamic claims cannot drift:

  docs/investigations/60E15120_N3J1E/reviews/starting_cranking/dynamic_validation_log.txt

Covered:
  * 0x1481c  cranking state machine: rpm state, post-start blanking, output
  * 0x1a564  closed-throttle gate (throttle % + dwell count)
  * 0x532d0  cranking-in-progress flag and its bounded counter
  * 0x2fea8  cranking/running pulse arbitration and the decay counter
  * 0x303a8  flood-clear throttle factor (1.0 closed, 0.0 wide open)
  * 0x43934  closed-throttle leading advance (table 0x6b630)
  * 0x123da  timing fade weight step
  * 0x3a0ec  PD7 output follows the relay flag

Run: python -m pytest tests/test_starting_cranking_dynamic.py
"""
import os
import struct
import sys

import pytest

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
EMU = os.path.join(REPO, 'utilities', 'scripts', 'emu')
sys.path.insert(0, EMU)

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, 'profiles', '60E15120_N3J1E.json')
LOG = os.path.join(REPO, 'docs', 'investigations', '60E15120_N3J1E', 'reviews',
                   'starting_cranking', 'dynamic_validation_log.txt')

A428 = 0xFFFFA428       # engine_running
A644 = 0xFFFFA644       # timing fade weight, leading
A79C = 0xFFFFA79C       # candidate_engine_running_stable
A79D = 0xFFFFA79D       # candidate_post_start_blanking_counter
A79E = 0xFFFFA79E       # candidate_engine_running_state
A7AC = 0xFFFFA7AC       # rpm offset term of the fade gate
A98C = 0xFFFFA98C       # coolant
A9BC = 0xFFFFA9BC       # throttle demand, %
AA60 = 0xFFFFAA60       # candidate_closed_throttle_dwell (u16)
AA62 = 0xFFFFAA62       # cranking_active
AA63 = 0xFFFFAA63       # candidate_closed_throttle_flag
AD44 = 0xFFFFAD44       # throttle position fed to the flood table
B53C = 0xFFFFB53C       # at_drive_range_engaged
B548 = 0xFFFFB548       # engine_speed_rpm
BBB4 = 0xFFFFBBB4       # vehicle speed
BE24 = 0xFFFFBE24       # injector_pulse_time
BE3C = 0xFFFFBE3C       # cranking_decay_counter
BE4C = 0xFFFFBE4C       # running base pulse (primary slot)
BE40 = 0xFFFFBE40       # latency added to be24/be28
BE44 = 0xFFFFBE44       # latency added to be2c..be38
BE58 = 0xFFFFBE58       # injector_pulse_crank
BE5C = 0xFFFFBE5C       # injector_pulse_crank_base
BE68 = 0xFFFFBE68       # candidate_cranking_throttle_factor
CA9C = 0xFFFFCA9C       # cranking_angle_timing_leading_filtered
CAA4 = 0xFFFFCAA4       # cranking_angle_timing_leading_raw
CFB6 = 0xFFFFCFB6       # pd7_relay_flag
CFB7 = 0xFFFFCFB7       # pe0 relay flag (throttle side)
D15C = 0xFFFFD15C       # cranking_in_progress
DWELL = 0xFFFF86E8      # candidate_cranking_dwell_accumulator (validated u16)
DWINV = 0xFFFF86EA      # its one's complement (the cell carries value + ~value)
PDDR = 0xFFFFF746       # PDDR_W


def fbits(x):
    return struct.unpack('>I', struct.pack('>f', x))[0]


@pytest.fixture(scope='module')
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return bus, cpu


def rdf(bus, addr):
    return struct.unpack('>f', struct.pack('>I', bus.read32(addr)))[0]


def dwell(n):
    """0xffff86e8 is a validated pair: u16 value followed by its one's complement."""
    return {DWELL: (2, n), DWINV: (2, n ^ 0xFFFF)}


def pd7(bus):
    return (bus.read16(PDDR) >> 7) & 1


class Recorder:
    """Collects observed values so the log and the asserts use one source."""

    def __init__(self):
        self.lines = []

    def add(self, text):
        self.lines.append(text)
        return text


def test_state_machine(booted):
    bus, cpu = booted
    rec = Recorder()
    harness.call(bus, cpu, 0x1481C, ram={B548: (4, fbits(600.0)), A98C: (4, fbits(20.0))})
    assert (bus.read8(A79E), bus.read8(A79D), bus.read8(A79C)) == (1, 4, 0)
    rec.add('0x1481c rpm=600 coolant=20  -> a79e=1 a79d=4 a79c=0 (primed from tbl 0x6a6cc)')
    harness.call(bus, cpu, 0x1481C, ram={B548: (4, fbits(600.0)), A98C: (4, fbits(20.0))})
    assert (bus.read8(A79E), bus.read8(A79D), bus.read8(A79C)) == (1, 3, 0)
    rec.add('0x1481c rpm=600 (next pass)   -> a79e=1 a79d=3 a79c=0 (blanking still active)')
    harness.call(bus, cpu, 0x1481C, ram={B548: (4, fbits(400.0))})
    assert bus.read8(A79E) == 1, 'state must hold between 300 and 500 rpm'
    rec.add('0x1481c rpm=400               -> a79e=1 (held between 300 and 500 rpm)')
    harness.call(bus, cpu, 0x1481C, ram={B548: (4, fbits(200.0))})
    assert (bus.read8(A79E), bus.read8(A79C)) == (0, 0)
    rec.add('0x1481c rpm=200               -> a79e=0 a79c=0')
    assert rec.lines


def test_closed_throttle_gate(booted):
    bus, cpu = booted
    harness.call(bus, cpu, 0x1A564, ram={A9BC: (4, fbits(1.0)), AA60: (2, 19)})
    assert (bus.read8(AA62), bus.read8(AA63)) == (1, 1)
    harness.call(bus, cpu, 0x1A564, ram={A9BC: (4, fbits(1.0)), AA60: (2, 18)})
    assert bus.read8(AA62) == 0, 'dwell 18 is below the 0x13 threshold'
    harness.call(bus, cpu, 0x1A564, ram={A9BC: (4, fbits(50.0)), AA60: (2, 19)})
    assert (bus.read8(AA62), bus.read8(AA63)) == (0, 0)


def test_cranking_in_progress(booted):
    bus, cpu = booted
    base = {BBB4: (4, fbits(0.0)), AA62: (1, 1), A428: (1, 1)}
    harness.call(bus, cpu, 0x532D0, ram={**base, **dwell(0)})
    assert bus.read8(D15C) == 1
    assert bus.read16(DWELL) == 1, 'the bounded counter increments while the flag is set'
    assert bus.read16(DWINV) == 0xFFFE, 'the complement half is rewritten with the value'
    harness.call(bus, cpu, 0x532D0, ram={**base, BBB4: (4, fbits(40.0)), **dwell(0)})
    assert bus.read8(D15C) == 0, 'vehicle speed outside the band must clear the flag'
    harness.call(bus, cpu, 0x532D0, ram={**base, AA62: (1, 0), **dwell(0)})
    assert bus.read8(D15C) == 0, 'an open throttle (aa62 = 0) must clear the flag'
    harness.call(bus, cpu, 0x532D0, ram={**base, A428: (1, 0), **dwell(0)})
    assert bus.read8(D15C) == 0, 'a stationary engine that never fired must clear the flag'
    harness.call(bus, cpu, 0x532D0, ram={**base, **dwell(233)})
    assert bus.read8(D15C) == 1, 'count 233 is still below the limit'
    harness.call(bus, cpu, 0x532D0, ram={**base, **dwell(234)})
    assert bus.read8(D15C) == 0, 'the counter limit is 234'


def test_arbitration_and_decay(booted):
    bus, cpu = booted
    harness.call(bus, cpu, 0x2FEA8, ram={A428: (1, 0), A98C: (4, fbits(-30.0)), BE58: (4, fbits(10.0)),
                                         BE5C: (4, fbits(4.0)), BE40: (4, fbits(1.0)), BE44: (4, fbits(2.0))})
    assert bus.read8(BE3C) == 3, 'coolant -30 degC loads 3 decay counts'
    assert rdf(bus, BE24) == 11.0, 'cranking slot = pulse + latency'
    rec_be24 = rdf(bus, BE24)
    harness.call(bus, cpu, 0x2FEA8, ram={A428: (1, 1), A98C: (4, fbits(-30.0)), BE3C: (1, 3),
                                         BE58: (4, fbits(10.0)), BE5C: (4, fbits(4.0)),
                                         BE40: (4, fbits(1.0)), BE44: (4, fbits(2.0))})
    assert bus.read8(BE3C) == 2, 'one count is consumed per pass once running'
    assert rdf(bus, BE24) == 11.0, 'the cranking pulse stays selected while the counter is non-zero'
    harness.call(bus, cpu, 0x2FEA8, ram={A428: (1, 1), A98C: (4, fbits(20.0)), BE3C: (1, 0),
                                         BE58: (4, fbits(10.0)), BE5C: (4, fbits(4.0)), BE4C: (4, fbits(3.0)),
                                         BE40: (4, fbits(1.0)), BE44: (4, fbits(2.0))})
    assert rdf(bus, BE24) == 4.0, 'running slot takes over when the counter reaches 0'
    assert rec_be24 == 11.0


def test_flood_factor(booted):
    bus, cpu = booted
    harness.call(bus, cpu, 0x303A8, ram={A428: (1, 0), A98C: (4, fbits(20.0)), AD44: (4, fbits(10.0))})
    assert rdf(bus, BE68) == 1.0, 'closed throttle keeps the full cranking pulse'
    harness.call(bus, cpu, 0x303A8, ram={A428: (1, 0), A98C: (4, fbits(20.0)), AD44: (4, fbits(50.0))})
    assert rdf(bus, BE68) == 0.0, 'wide-open throttle zeroes the cranking pulse (clear flood)'
    harness.call(bus, cpu, 0x303A8, ram={A428: (1, 1), A98C: (4, fbits(20.0)), AD44: (4, fbits(50.0))})
    assert rdf(bus, BE68) == 0.0, 'the factor is only updated while the engine is not running'


def test_closed_throttle_advance_and_fade(booted):
    bus, cpu = booted
    harness.call(bus, cpu, 0x43934, ram={AA62: (1, 1), B53C: (1, 1), A98C: (4, fbits(-40.0))})
    assert rdf(bus, CA9C) == 5.0 and rdf(bus, CAA4) == 5.0, 'table 0x6b630 at -40 degC = 110 * 0.5 - 50'
    harness.call(bus, cpu, 0x43934, ram={AA62: (1, 0), B53C: (1, 1), A98C: (4, fbits(-40.0))})
    assert rdf(bus, CA9C) == 0.0, 'an open throttle zeroes the closed-throttle advance'
    harness.call(bus, cpu, 0x123DA, ram={AA62: (1, 1), A644: (4, fbits(1.0)), B548: (4, fbits(800.0)),
                                        A7AC: (4, fbits(0.0)), 0xFFFFA668: (1, 0)})
    assert abs(rdf(bus, A644) - 0.95) < 1e-6, 'one fade step is 0.05'
    for _ in range(20):
        harness.call(bus, cpu, 0x123DA, ram={AA62: (1, 1), B548: (4, fbits(800.0)),
                                            A7AC: (4, fbits(0.0)), 0xFFFFA668: (1, 0)})
    assert rdf(bus, A644) == 0.0, 'the fade floors at 0.0'
    harness.call(bus, cpu, 0x123DA, ram={AA62: (1, 0), B548: (4, fbits(800.0)), A7AC: (4, fbits(0.0)),
                                        A644: (4, fbits(0.0)), 0xFFFFA668: (1, 0)})
    assert rdf(bus, A644) == 1.0, 'an open throttle recovers the weight to 1.0 in one step'


def test_pd7_follows_flag(booted):
    bus, cpu = booted
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 1), CFB7: (1, 0)})
    assert pd7(bus) == 1
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 0)})
    assert pd7(bus) == 0


def test_dynamic_log_matches_committed_copy(booted):
    """The committed evidence log must list the same observations."""
    bus, cpu = booted
    rows = []
    harness.call(bus, cpu, 0x1481C, ram={B548: (4, fbits(600.0)), A98C: (4, fbits(20.0))})
    rows.append(f'0x1481c rpm=600 coolant=20  -> a79e={bus.read8(A79E)} a79d={bus.read8(A79D)} a79c={bus.read8(A79C)}')
    harness.call(bus, cpu, 0x1A564, ram={A9BC: (4, fbits(1.0)), AA60: (2, 19)})
    rows.append(f'0x1a564 thr=1.0 dwell=19   -> aa62={bus.read8(AA62)} aa63={bus.read8(AA63)}')
    harness.call(bus, cpu, 0x1A564, ram={A9BC: (4, fbits(50.0)), AA60: (2, 19)})
    rows.append(f'0x1a564 thr=50.0 dwell=19  -> aa62={bus.read8(AA62)} aa63={bus.read8(AA63)}')
    harness.call(bus, cpu, 0x532D0, ram={BBB4: (4, fbits(0.0)), AA62: (1, 1), A428: (1, 1), **dwell(0)})
    rows.append(f'0x532d0 vspeed=0 running    -> d15c={bus.read8(D15C)} counter={bus.read16(DWELL)}')
    harness.call(bus, cpu, 0x2FEA8, ram={A428: (1, 0), A98C: (4, fbits(-30.0)), BE58: (4, fbits(10.0)),
                                         BE5C: (4, fbits(4.0)), BE40: (4, fbits(1.0)), BE44: (4, fbits(2.0))})
    rows.append(f'0x2fea8 cranking -30 degC   -> be3c={bus.read8(BE3C)} be24={rdf(bus, BE24):g}')
    harness.call(bus, cpu, 0x303A8, ram={A428: (1, 0), A98C: (4, fbits(20.0)), AD44: (4, fbits(10.0))})
    closed = rdf(bus, BE68)
    harness.call(bus, cpu, 0x303A8, ram={A428: (1, 0), A98C: (4, fbits(20.0)), AD44: (4, fbits(50.0))})
    open_ = rdf(bus, BE68)
    rows.append(f'0x303a8 throttle 10/50 %    -> be68={closed:g} / {open_:g}')
    harness.call(bus, cpu, 0x43934, ram={AA62: (1, 1), B53C: (1, 1), A98C: (4, fbits(-40.0))})
    rows.append(f'0x43934 throttle closed -40 -> ca9c={rdf(bus, CA9C):g} caa4={rdf(bus, CAA4):g}')
    harness.call(bus, cpu, 0x123DA, ram={AA62: (1, 1), A644: (4, fbits(1.0)), B548: (4, fbits(800.0)),
                                        A7AC: (4, fbits(0.0)), 0xFFFFA668: (1, 0)})
    rows.append(f'0x123da one fade step       -> a644={rdf(bus, A644):g}')
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 1), CFB7: (1, 0)})
    rows.append(f'0x3a0ec flag=1              -> PD7={pd7(bus)}')
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 0)})
    rows.append(f'0x3a0ec flag=0              -> PD7={pd7(bus)}')

    header = [
        'Dynamic validation — engine start / cranking chain (SH-2E emulator)',
        'ROM 60E15120_N3J1E, profile utilities/scripts/emu/profiles/60E15120_N3J1E.json',
        'Every value below is read back from RAM after a harness.call() into the real ROM function.',
        '',
    ]
    expected = '\n'.join(header + rows) + '\n'
    if os.environ.get('STARTING_CRANKING_WRITE_LOG'):
        os.makedirs(os.path.dirname(LOG), exist_ok=True)
        with open(LOG, 'w', encoding='utf-8') as fh:
            fh.write(expected)
    with open(LOG, encoding='utf-8') as fh:
        committed = fh.read()
    assert committed == expected, (
        'reviews/starting_cranking/dynamic_validation_log.txt is stale — the '
        'observed emulator values changed. Rewrite it from this test.')
