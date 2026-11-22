#!/usr/bin/env python3
"""Tests for the throttle / DBW label record.

Covers data/labels/60E15120_N3J1E/throttle_dbw_labels.json (pedal -> plate
demand -> servo -> motor PWM chain, TP plausibility/learning, logger PID
0x1410 settlement, DBW power relay PE0):

  * every function alias address exists in the decompiled function index;
  * the accepted source-review TSV rows mirror the JSON function/RAM/lookup
    aliases;
  * the cited literal-pool words, dispatch-record bytes and float constants
    match the raw ROM bytes (SHA-256 pinned) at the exact addresses named in
    the evidence strings (rule-7 binary-level verification);
  * the port/ATU registers named in the evidence exist in symbols.tsv;
  * dynamic (SH-2E emulator, harness calls of the ROM's own functions):
    - task 0x64ba with pedal AN4 raw = 50000 -> accelerator_pedal_1_percent
      0xffffa9b4 = 100.0;
    - plate chain 0xb398 -> 0x1b08e -> 0x1b14c -> 0x1b940 with AN18/AN19 raw
      = 50000 -> inferred_throttle_position 0xffffad44 = 80.367,
      0xffffad48 = 95.676; limp flags cc98=1 + cc99=1 -> 0xffffad44 = 20.0;
    - logger PID 0x1410 handler 0x56f6c: injector pulse time 0xffffbe24 =
      80.0 encodes to u16 10 (step 8.0), 16.0 encodes to 2;
    - PEDR bit 0x1 (PE0) = (0xffffcfb7 == 0), driven by 0x3a0ec (DBW relay).

Run: python -m pytest tests/test_throttle_dbw.py
"""

import csv
import hashlib
import json
import os
import struct
import subprocess
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
LBL = REPO / "data" / "labels" / "60E15120_N3J1E" / "throttle_dbw_labels.json"
ROM = (
    REPO / "submodules" / "Mazda_RX8_PCM_ReverseEngineering" / "Stock_ROMs"
    / "60E15120_N3J1E.bin"
)
FUNC_INDEX = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "function_index.tsv"
SYMBOLS = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E" / "symbols.tsv"
SR = REPO / "docs" / "investigations" / "60E15120_N3J1E" / "labeling" / "source_review"
FN_TSV = SR / "accepted_function_aliases.tsv"
RAM_TSV = SR / "accepted_ram_aliases.tsv"
LOOKUP_TSV = SR / "accepted_lookup_aliases.tsv"

ROM_SHA256 = "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1"

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")

PEDR = 0xFFFFF754
PDDR = 0xFFFFF746      # pd7 drive register (0x3a0ec)
CFB6 = 0xFFFFCFB6      # pd7_relay_flag (PD7 half: starting_cranking_labels.json)
CFB7 = 0xFFFFCFB7      # pe0_relay_flag (DBW relay request, inverted)

# RAM cells exercised dynamically (see throttle_dbw_labels.json)
AN4 = 0xFFFF9EEC       # adc_an4_pedal_raw
AN18 = 0xFFFF9F08      # adc_an18_plate_tp1_raw
AN19 = 0xFFFF9F0A      # adc_an19_plate_tp2_raw
A9B4 = 0xFFFFA9B4      # accelerator_pedal_1_percent
AD44 = 0xFFFFAD44      # inferred_throttle_position
AD48 = 0xFFFFAD48      # plate position percent (ad44/84*100)
CC98 = 0xFFFFCC98
CC99 = 0xFFFFCC99      # limp-home flag inside 0x1b940
BE24 = 0xFFFFBE24      # injector_pulse_time (PID 0x1410 input)


def f32bits(x):
    return struct.unpack(">I", struct.pack(">f", x))[0]


@pytest.fixture(scope="module")
def record():
    return json.loads(LBL.read_text(encoding="utf-8"))


@pytest.fixture(scope="module")
def rom():
    data = ROM.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ROM_SHA256, "ROM hash changed"
    return data


@pytest.fixture(scope="module")
def func_addresses():
    with FUNC_INDEX.open(encoding="utf-8", errors="replace", newline="") as fh:
        return {int(r["address"], 16) for r in csv.DictReader(fh, delimiter="\t")}


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


def w16(rom, addr):
    return struct.unpack(">H", rom[addr:addr + 2])[0]


def w32(rom, addr):
    return struct.unpack(">I", rom[addr:addr + 4])[0]


def pe0(bus):
    return bus.read16(PEDR) & 1


def bus_f32(bus, addr):
    return struct.unpack(">f", struct.pack(">I", bus.read32(addr)))[0]


# ---------------------------------------------------------------- static


def test_function_aliases_exist_in_index(record, func_addresses):
    for addr in record["function_aliases"]:
        assert int(addr, 16) in func_addresses, f"0x{addr} not a function entry"


def test_tsv_rows_mirror_json(record):
    with FN_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        fn_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    with RAM_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        ram_rows = {r["address"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    with LOOKUP_TSV.open(encoding="utf-8", errors="surrogateescape", newline="") as fh:
        lk_rows = {r["original"]: r["alias"] for r in csv.DictReader(fh, delimiter="\t")}
    for addr, e in record["function_aliases"].items():
        assert fn_rows.get("%08x" % int(addr, 16)) == e["alias"]
    for addr, e in record["ram_aliases"].items():
        assert ram_rows.get(addr) == e["alias"]
    for addr, e in record["lookup_aliases"].items():
        assert lk_rows.get("%08x" % int(addr, 16)) == e["alias"]


def test_registers_in_symbols():
    with SYMBOLS.open(encoding="utf-8", errors="replace", newline="") as fh:
        syms = {r["address"]: r["name"] for r in csv.DictReader(fh, delimiter="\t")}
    assert syms["fffff754"] == "PEDR_W"
    assert syms["fffff730"] == "PBIOR_W"
    assert syms["fffff734"] == "PBCRL_W"
    assert syms["fffff400"] == "ATUII_TSTR2_B"
    assert syms["fffff586"] == "ATUII_TCNT7D_W"
    assert syms["fffff58e"] == "ATUII_CYLR7D_W"
    assert syms["fffff596"] == "ATUII_BFR7D_W"
    assert syms["fffff59e"] == "ATUII_DTR7D_W"


# ------------------------------------------- static: raw ROM pool evidence


def test_task_and_batch_pools(rom):
    # task rec[9] 0x64ba tail-calls the 0x1150e batch (pool at 0x64d4)
    assert w32(rom, 0x656C) == 0x0001150E          # 0x64ba -> 0x1150e
    assert w32(rom, 0x66D8) == 0x000118D0          # task rec[13] 0x65b2 -> 0x118d0 (PWM batch)
    # 0x1150e batch pools: sensor batch, DBW control batch, torque batch
    assert w32(rom, 0x116B8) == 0x000199D4
    assert w32(rom, 0x116C8) == 0x00022F86
    assert w32(rom, 0x116E4) == 0x00021B4C
    # 0x2253c PWM batch pools
    assert w32(rom, 0x22560) == 0x00003920
    assert w32(rom, 0x22564) == 0x00022574
    assert w32(rom, 0x22568) == 0x00022630
    assert w32(rom, 0x2256C) == 0x00025198


def test_pedal_chain_pools(rom):
    # 0x94f0 pedal raw range + scaling constants
    assert w16(rom, 0x6EEB0) == 0xF5C3              # upper raw range
    assert w16(rom, 0x6EEB4) == 0x11EC              # lower raw range
    assert w32(rom, 0x6EEB8) == 0x40CAE979          # 6.341f
    assert w32(rom, 0x6EEC0) == 0x00000000          # 0.0f base term
    assert w32(rom, 0x6EEC4) == 0x405F3B64          # 3.488f
    # 0x18f60 latch pools + clamp const
    assert w32(rom, 0x19058) == 0xFFFF9EEC         # AN4 raw cell
    assert w16(rom, 0x1904A) == 0xA9C4              # a9c4 output
    assert w32(rom, 0x6EED0) == 0x41C80000          # 25.0f clamp
    # 0x1933a learned-zero subtract pools
    assert w16(rom, 0x19386) == 0x8068              # learned_pedal_zero_1
    # 0x193c4 percent calc pools (12.7f scale, 100.0f, clamp helper)
    assert w32(rom, 0x194D4) == 0x00006EF18         # -> 12.7f pool
    assert struct.unpack(">f", rom[0x6EF18:0x6EF1C])[0] == pytest.approx(12.7)
    assert w32(rom, 0x194D0) == 0x42C80000          # 100.0f
    # ADC sweep base pool (0x6884): AN0 -> 0xffff9ee4, +2n
    assert w32(rom, 0x6A1C) == 0xFFFF9EE4


def test_plate_chain_pools(rom):
    # 0xb398 plate raw -> volts (per-channel scale/base at 0x6f3e4/0x6f3ec)
    assert w32(rom, 0x6F3E4) == 0x41C80000          # 25.0f TP1 scale
    assert w32(rom, 0x6F3E8) == 0x41FA0000          # 31.25f TP2 scale
    assert w32(rom, 0x6F3EC) == 0x00000000          # 0.0f TP1 base
    assert w32(rom, 0x6F3F0) == 0xC1FA0000          # -31.25f TP2 base
    # 0x1b08e / 0x1b14c latch pools
    assert w32(rom, 0x1B12C) == 0xFFFF9F08         # AN18 raw cell
    assert w16(rom, 0x1B0E6) == 0xAD5C              # ad5c output
    assert w32(rom, 0x1B1D0) == 0xFFFF9F0A         # AN19 raw cell
    assert w16(rom, 0x1B1C0) == 0xAD5E              # ad5e output
    # 0x1b940 plate position: 84.0f divisor is ROM 0x6f468, limp 20.0f is 0x6f464
    assert w32(rom, 0x6F468) == 0x42A80000
    assert w32(rom, 0x6F464) == 0x41A00000


def test_pedal_to_plate_map_pools(rom):
    # 0x228dc gear-selected 3D descriptors + clamp target/const
    assert w32(rom, 0x229DC) == 0x00006A458
    assert w32(rom, 0x229E0) == 0x00006A474
    assert w32(rom, 0x229E4) == 0x00006A490
    assert w32(rom, 0x229E8) == 0x00006A4AC
    assert w32(rom, 0x229EC) == 0xFFFFB398         # request output
    assert w32(rom, 0x229F0) == 0x0007372C          # -> 84.0f pool
    assert struct.unpack(">f", rom[0x7372C:0x73730])[0] == pytest.approx(84.0)


def test_servo_override_pools(rom):
    # 0x22db4 servo/homing override pools + constants
    assert w16(rom, 0x22EA0) == 0xB4B0
    assert w16(rom, 0x22EA2) == 0xCCBC              # servo mode byte
    assert w16(rom, 0x22EA4) == 0xB3F8              # override duty
    assert w16(rom, 0x22EA6) == 0xB410              # target counts
    assert w32(rom, 0x22EBC) == 0xFFFFB400         # direction
    assert w32(rom, 0x747B8) == 0x3F000000         # 0.5f min limit
    assert w32(rom, 0x747C4) == 0x3F000000         # 0.5f direction compare
    assert w32(rom, 0x747C8) == 0x00000000         # 0.0f direction band
    assert w32(rom, 0x747BC) == 0x40A00000         # 5.0f decay floor
    assert w32(rom, 0x747C0) == 0x3D4CCCCD         # 0.05f step
    assert w32(rom, 0x6F438) == 0x41700000         # 15.0f learned default


def test_pwm_chain_pools(rom):
    # 0x25198 duty ratio: cells, 100.0f, clamp helper, ch7d writer
    assert w32(rom, 0x251C0) == 0xB354B570         # b354/b570 cells (mov.w pool pair)
    assert w32(rom, 0x251C4) == 0x42C80000         # 100.0f
    assert w32(rom, 0x251C8) == 0x00002404         # clamp helper
    assert w32(rom, 0x251CC) == 0x0000B2C0         # ch7d_pwm_duty_write
    # 0xb2c0 motor duty write: duty q16 cell, enable flag, BFR7D reg, period cell, mul helper
    assert w32(rom, 0xB37C) == 0xFFFFA210
    assert w32(rom, 0xB380) == 0xFFFFA214
    assert w16(rom, 0xB374) == 0xF596              # ATUII_BFR7D_W low half
    assert w32(rom, 0xB38C) == 0xFFFF9F50          # 32000 period cell
    assert w32(rom, 0xB394) == 0x0000231C          # mul/shift/saturate helper
    assert w32(rom, 0xB390) == 0x47800000          # 65536.0f


def test_enable_condition_pools(rom):
    # 0x22574 enable gates: coolant -50, battery 9-16 V; PID consts 0x73548-0x7355c
    assert struct.unpack(">f", rom[0x7353C:0x73540])[0] == pytest.approx(-50.0)
    assert struct.unpack(">f", rom[0x73540:0x73544])[0] == pytest.approx(9.0)
    assert struct.unpack(">f", rom[0x73544:0x73548])[0] == pytest.approx(16.0)
    for a, v in ((0x73548, 45.0), (0x7354C, 44.0), (0x73550, 4.5),
                 (0x73554, 0.1875), (0x73558, 0.75), (0x7355C, 30.0)):
        assert struct.unpack(">f", rom[a:a + 4])[0] == pytest.approx(v), hex(a)


def test_fault_threshold_pools(rom):
    # 0x33e98 plate range-high fault: 200.0f threshold, 3.52f hysteresis, cells
    assert w32(rom, 0x79BE0) == 0x43480000         # 200.0f
    assert w32(rom, 0x79BE4) == 0x406147AE         # 3.52f
    assert w16(rom, 0x33F6A) == 0xAD48
    assert w16(rom, 0x33F6C) == 0xC108
    # 0x4595a TP correlation thresholds: 3.5f, 9.536f
    assert w32(rom, 0x7C77C) == 0x40600000         # 3.5f
    assert w32(rom, 0x7C790) == 0x41189375         # 9.536f


def test_pid_1410_dispatch_record_and_pools(rom):
    # UDS mode-22 dispatch record at 0x5f394: pid 0x1410, len 2, -4 (0xfffc), handler 0x56f6c
    assert rom[0x5F394:0x5F3A0].hex() == "14100200fffc000000056f6c"
    # 0x56f6c handler pools: injector_pulse_time cell, encoder helper, 8.0f step
    assert w16(rom, 0x57018) == 0xBE24
    assert w32(rom, 0x57038) == 0x00002490
    assert w32(rom, 0x57048) == 0x41000000         # 8.0f


def test_demand_and_learner_pools(rom):
    # 0x193c4 demand branches: calibration byte 0 -> nominal path; 13.5/100/15 limits
    assert rom[0x6EEC8] == 0x00                    # nominal demand branch selected
    assert struct.unpack(">f", rom[0x6EF20:0x6EF24])[0] == pytest.approx(13.5)
    assert struct.unpack(">f", rom[0x6EF24:0x6EF28])[0] == pytest.approx(100.0)
    assert struct.unpack(">f", rom[0x6EF28:0x6EF2C])[0] == pytest.approx(15.0)
    # pedal-zero learner: disarm/raise counters, floor/step/cap/agreement
    assert w16(rom, 0x6EECA) == 0x177
    assert w16(rom, 0x6EECC) == 0x177
    for a, v in ((0x6EEF8, 9.626), (0x6EEFC, 0.005), (0x6EF00, 10.856),
                 (0x6EF04, 0.01), (0x6EF08, 10.856), (0x6EF10, 0.032)):
        assert struct.unpack(">f", rom[a:a + 4])[0] == pytest.approx(v), hex(a)
    # plate learner gate + TP band/fault words
    assert w16(rom, 0x6F3F8) == 10
    assert rom[0x6C17A] == 3
    assert w16(rom, 0x6F3E0) == 0x0FD2             # TP1 band lower
    assert w16(rom, 0x6F3E2) == 0x2659             # TP2 band lower
    assert w16(rom, 0x6C176) == 0x0A3D             # TP fault low
    # correlation counter limits (>= 25 good, >= 29 bad)
    assert w16(rom, 0x7C794) == 25
    assert w16(rom, 0x7C796) == 29
    # MT/AT calibration byte: 0x00 -> 0xffffb534 = 1 (range/state branch of 0x2c15a)
    assert rom[0x74924] == 0x00


def test_target_plate_is_float_store(rom):
    # 0x233ec: b410 <- 0x5ccb4(b424) with fmov.s (4-byte float), not a u16 counter
    assert rom[0x2353C:0x2353E].hex() == "9226"    # mov.w @(0x2358c,pc),r2 -> 0xb410
    assert w16(rom, 0x2358C) == 0xB410
    assert rom[0x2353E:0x23540].hex() == "f20a"    # fmov.s fr0,@r2


def test_pd7_drive_dynamic(booted):
    """0x3a0ec: PDDR bit 0x80 (PD7) = (0xffffcfb6 == 1) — not inverted."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 1), CFB7: (1, 0)})
    assert bus.read16(PDDR) & 0x80
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 0)})
    assert not bus.read16(PDDR) & 0x80


# --------------------------------------------------------------- dynamic


def test_pe0_drive_dynamic(booted):
    """0x3a0ec: PEDR bit 0x1 (PE0) = (0xffffcfb7 == 0) — DBW relay (inverted)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 0)})
    assert pe0(bus) == 1
    harness.call(bus, cpu, 0x3A0EC, ram={CFB6: (1, 0), CFB7: (1, 1)})
    assert pe0(bus) == 0


def test_pedal_task_dynamic(booted):
    """Task 0x64ba -> 0x94fc (pedal volts) -> 0x1150e -> 0x199d4 -> 0x193c4:
    AN4 raw 50000 ends up as accelerator_pedal_1_percent 0xffffa9b4 = 100.0
    (clamped from 105 %); AN5 stays 0, so pedal_range_fault_2 reads 2."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x64BA, ram={AN4: (2, 50000)}, stop_at=(0x3DAC,))
    assert bus_f32(bus, A9B4) == pytest.approx(100.0)


def test_plate_chain_dynamic(booted):
    """0xb398 -> 0x1b08e -> 0x1b14c -> 0x1b940 with AN18/AN19 raw = 50000:
    TP1 volts 0xffffa218 = 95.367, plate 0xffffad44 = 95.367 - 15.0 learned
    = 80.367, percent 0xffffad48 = 80.367/84*100 = 95.676."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0xB398, ram={AN18: (2, 50000), AN19: (2, 50000)})
    harness.call(bus, cpu, 0x1B08E)
    harness.call(bus, cpu, 0x1B14C)
    harness.call(bus, cpu, 0x1B940)
    assert bus_f32(bus, 0xFFFFA218) == pytest.approx(95.367431640625)
    assert bus_f32(bus, AD44) == pytest.approx(80.367431640625)
    assert bus_f32(bus, AD48) == pytest.approx(80.367431640625 / 84.0 * 100.0)


def test_plate_limp_dynamic(booted):
    """0x1b940 limp-home: cc98==1 selects the TP2 branch and cc99==1 forces
    0xffffad44 = 20.0 (limp plate position)."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0xB398, ram={AN18: (2, 50000), AN19: (2, 50000)})
    harness.call(bus, cpu, 0x1B08E)
    harness.call(bus, cpu, 0x1B14C)
    harness.call(bus, cpu, 0x1B940, ram={CC98: (1, 1), CC99: (1, 1)})
    assert bus_f32(bus, AD44) == pytest.approx(20.0)
    assert bus_f32(bus, AD48) == pytest.approx(20.0 / 84.0 * 100.0)


def _pid1410_encoded(booted, pulse_float):
    """Run handler 0x56f6c with 0xffffbe24 = pulse_float; return the u16
    values the handler stores into its response buffer on the stack."""
    _, bus, cpu = booted
    ow8, ow16 = bus.write8, bus.write16
    log = []

    def w8(a, v):
        if a >= 0xFFFF6F00:
            log.append((a, v, 1))
        return ow8(a, v)

    def w16(a, v):
        if a >= 0xFFFF6F00:
            log.append((a, v, 2))
        return ow16(a, v)

    bus.write8, bus.write16 = w8, w16
    try:
        harness.call(bus, cpu, 0x56F6C, ram={BE24: (4, f32bits(pulse_float))})
    finally:
        bus.write8, bus.write16 = ow8, ow16
    mem = {}
    for a, v, s in log:
        if s == 1:
            mem[a] = v & 0xFF
        else:
            mem[a] = (v >> 8) & 0xFF
            mem[a + 1] = v & 0xFF
    return {(mem[a] << 8) | mem.get(a + 1, 0) for a in mem if a in mem}


def test_pid_1410_injector_pulse_time_dynamic(booted):
    """PID 0x1410 (dispatch record 0x5f394 -> handler 0x56f6c) encodes
    injector_pulse_time 0xffffbe24 with step 8.0 (pool 0x57048=0x41000000):
    80.0 -> u16 10, 16.0 -> u16 2. Not the throttle pedal."""
    assert 10 in _pid1410_encoded(booted, 80.0)
    assert 2 in _pid1410_encoded(booted, 16.0)


PIPELINE = REPO / "utilities" / "scripts" / "rx8-pcm-pipeline"
DECOMPILED = REPO / "reverse-engineered" / "decompiled" / "60E15120_N3J1E"


def test_generators_idempotent_on_committed_artifacts():
    """Rule 6d: re-running the label pass and its fold-back apply script must leave
    the label record, the TSV rows and the exported names byte-identical."""
    watched = [
        LBL,
        REPO / "data" / "labels" / "60E15120_N3J1E" / "integrated_names.json",
        FN_TSV,
        RAM_TSV,
        LOOKUP_TSV,
        FUNC_INDEX,
        SYMBOLS,
        DECOMPILED / "callgraph.tsv",
        DECOMPILED / "firmware_decompiled.c",
        DECOMPILED / "named" / "firmware_named.c",
    ]
    before = {p: p.read_bytes() for p in watched}
    for script in ("review_throttle_dbw_labels.py", "review_throttle_dbw_labels_apply.py"):
        subprocess.run([sys.executable, str(PIPELINE / script)], cwd=REPO, capture_output=True, check=True)
    for path, data in before.items():
        assert path.read_bytes() == data, f"{path.name}: generator not idempotent"

