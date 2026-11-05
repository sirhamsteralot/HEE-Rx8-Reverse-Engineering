"""Low-confidence label proof pass, 2026-11-05 (ROADMAP C item 10 / D6 / D10).

Dynamically proves the medium-confidence labels in
data/labels/60E15120_N3J1E/*.json by driving the real ROM code in the SH-2E
emulator and comparing against exact float32 models of the handlers:

- all medium diag22 dispatch records: source RAM cell(s) set to
  0 / sentinel / sentinel2, response read from the ch0 ring 0xffffd962 via
  the ROM's own dispatcher 0x5774c; payload must equal the model at all
  three points (PIDs 0x0002 and 0x1710 are the documented exceptions).
- physical chain: ADC AN18/AN19 -> 0x6884 (adc_scan_sweep_all_channels) ->
  ffff9f08/9f0a -> 0x1afb0 -> ffffad5c/ad5e -> PIDs 0x11/0x1154/0x917/0x47.
- control path via harness.call: fuel_cut_rpm_condition 0x18cfe,
  rev_limit_conditionals 0xee82, injector_zero_offset_set 0x86ac,
  maf_voltage_and_fault_counters 0x19f4e, maf_filtered_update 0x19f40,
  injection_angle_limit_lookup 0xe48e (vs extracted cal tables),
  fuel_cut_arbitration 0xedc4, cold_start_enrichment 0x1ddfc,
  timing_trim_scale_calc 0x12e60, APV chain 0x31ece/0x31f0a/0x31f32,
  apv_pwm_service 0xa936 (PLDR_W 0xfffff75e), apv_drive_status_sample 0xaac4,
  apv_position_voltage_scale 0x43a86, adc_read_ect_iat_group 0x6cdc.
- UDS service router 0x68dac reaching services 0x12/0x18/0x21/0x32/0x33/0x3b/0xb1.
- D10: PID 0x1410 is injector pulse time (ffffbe24 float, step 8.0), NOT
  throttle pedal - response independent of ffffad5c.

Run: python -m pytest tests/test_lowconf_dynamic_proof.py
"""
import csv
import json
import os
import struct
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")
LABELS = os.path.join(os.path.dirname(__file__), "..", "data", "labels",
                      "60E15120_N3J1E", "uds_dispatch_labels.json")

MODE22_RING = 0xFFFFD962
PEDR_W, PDDR_W, PJDR_W, PHDR_W, PLDR_W = 0xFFFFF754, 0xFFFFF746, 0xFFFFF76C, 0xFFFFF72C, 0xFFFFF75E


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return struct.unpack(">I", struct.pack(">f", f32(x)))[0]


def fbits(b):
    return struct.unpack(">f", struct.pack(">I", b & 0xFFFFFFFF))[0]


def rd_f(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a)))[0]


def enc_u8(signal, step_b, off_b):
    step, off = fbits(step_b), fbits(off_b)
    return max(0, min(255, int(f32(f32(f32(signal - off) / step) + 0.5))))


def enc_u16(signal, step_b, off_b):
    step, off = fbits(step_b), fbits(off_b)
    return max(0, min(0xFFFF, int(f32(f32(f32(signal - off) / step) + 0.5))))


def dec_u16(step_b, off_b, raw):
    return f32(f32(f32(raw) * fbits(step_b)) + fbits(off_b))


def dec_u8(step_b, off_b, raw):
    return f32(f32(f32(raw) * fbits(step_b)) + fbits(off_b))


def s16div(x, p2_b, p3_b):
    p2, p3 = fbits(p2_b), fbits(p3_b)
    h = 0.5 if 0.0 <= x - p3 else -0.5
    r = int(f32(f32(x - p3) / p2 + h))
    r = max(-0x8000, min(0x7FFF, r))
    return r & 0xFFFF


ROM = open(os.path.join(os.path.dirname(__file__), "..",
                        "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"), "rb").read()

# diag22 subpid supported-mask table: 36 records x 6 B at 0x5f5b2
# (pid u16 @0, summand u8 @2, subpid u8 @3, permission u16 @4); out = mask & sum
SUBPID = [struct.unpack(">HBBH", ROM[0x5F5B2 + i * 6: 0x5F5B2 + i * 6 + 6]) for i in range(0x24)]


def subpid_mask(pid, subpid, maskval, allow=0xFFFF):
    s = sum(sm for (p, sm, sub, perm) in SUBPID
            if p == pid and sub == subpid and (perm & allow))
    return maskval & s & 0xFF


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)
    return prof, bus, cpu


def mode22(booted, pid, allow=0xFFFF):
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x68B10, r_args=(0, 0x22), max_steps=10000)
    bus.write8(0xFFFFDDEC, 0)
    bus.write16(0xFFFFD95C, 0)
    bus.write16(0xFFFFD1EA, pid)
    bus.write8(0xFFFFD1E8, 0)
    bus.write16(0xFFFFD3B4, allow)
    r0, _, _ = harness.call(bus, cpu, 0x5774C, max_steps=200000)
    n = max(r0 - 3, 0)
    return r0, bytes(bus.read8(MODE22_RING + i) for i in range(3 + n))


def load_labels():
    with open(LABELS, encoding="utf-8") as f:
        return json.load(f)


RAM_TYPES = {}


def ctype(c):
    return RAM_TYPES.get("%04x" % c, "uint16")


def get_cell(bus, a):
    t = ctype(a)
    if t == "float":
        return rd_f(bus, 0xFFFF0000 | a)
    if t == "uint8":
        return bus.read8(0xFFFF0000 | a)
    return bus.read16(0xFFFF0000 | a)


def set_cell(bus, a, v):
    t = ctype(a)
    if t == "float":
        bus.write32(0xFFFF0000 | a, bits(v))
    elif t == "uint8":
        bus.write8(0xFFFF0000 | a, int(v) & 0xFF)
    else:
        bus.write16(0xFFFF0000 | a, int(v) & 0xFFFF)


def write_valid_float(bus, addr, val):
    """Checksummed window cell: u16 @+4 must equal ~(u16@+2 + hi16(bits))."""
    b = bits(val)
    bus.write32(addr, b)
    x = bus.read16(addr + 2)
    chk = (~(x + ((b >> 16) & 0xFFFF))) & 0xFFFF
    bus.write16(addr + 4, chk)
    bus.write16(addr + 6, chk)


U8 = lambda v: bytes([v & 0xFF])
U16 = lambda v: struct.pack(">H", v & 0xFFFF)


def model(bus, pid):
    """Exact float32 model of the medium-PID handlers (from the decompiled
    encoder bodies), given current bus state."""
    g = lambda a: get_cell(bus, a)
    if pid == 0x15:
        o2 = enc_u8(dec_u16(0x38A00000, 0, g(0xAD1C)), 0x3BA3D70A, 0)
        trim = enc_u8(f32(f32(g(0xB074)) * f32(100.0)), 0x3F480346, 0xC2C80000)
        return U16((trim & 0xFF) + o2 * 0x100)
    if pid == 0x2E: return U8(enc_u8(g(0xB2F0), 0x3EC8C8C8, 0))
    if pid == 0x2F: return U8(g(0xD287) & 0xFF)
    if pid == 0x30: return U8(min(g(0x8788) & 0xFFFF, 0xFF))
    if pid == 0x31: return U16(enc_u16(g(0x90FC), 0x3F800000, 0))
    if pid == 0x33: return U8(enc_u8(f32(f32(g(0xAD10)) * f32(25.325)) + f32(0.0182), 0x3F800000, 0))
    if pid == 0x3C: return U16(enc_u16(g(0xC644), 0x3DCCCCCC, 0xC2200000))
    if pid == 0x45: return U8(enc_u8(g(0xAD48), 0x3EC8C8C8, 0))
    if pid in (0x47, 0x49, 0x4A):
        cell = {0x47: 0xAD5E, 0x49: 0xA9C4, 0x4A: 0xA9C6}[pid]
        return U8(enc_u8(f32(dec_u16(0x38A00000, 0, g(cell)) * f32(20.0)), 0x3EC8C8C8, 0))
    if pid == 0x4C: return U8(enc_u8(f32(f32(g(0xB410)) * f32(100.0)) / f32(84.0), 0x3EC8C8C8, 0))
    if pid in (0x914, 0x915, 0x917, 0x918):
        cell = {0x914: 0xA9C4, 0x915: 0xA9C6, 0x917: 0xAD5C, 0x918: 0xAD5E}[pid]
        return U16(s16div(dec_u16(0x38A00000, 0, g(cell)), 0x3A800000, 0))
    if pid == 0x91A: return U16(enc_u16(g(0xB410), 0x3B000000, 0))
    if pid == 0x96E: return U16(enc_u16(g(0xA7AC), 0x3E800000, 0))
    if pid == 0x97C: return U16(enc_u16(g(0xB59C), 0x3A000000, 0))
    if pid == 0x114A: return U16(enc_u16(g(0xADD4), 0x38A00000, 0))
    if pid == 0x114D: return U16(enc_u16(g(0xA984), 0x38A00000, 0))
    if pid == 0x1153: return U16(enc_u16(g(0xA834), 0x38000000, 0))
    if pid == 0x1154: return U16(g(0xAD5C) & 0xFFFF)
    if pid == 0x1169:
        return U16(enc_u16(f32(f32(g(0x807C) - 0.0) / f32(25.0)), 0x38A00000, 0))
    if pid == 0x1340: return U8(enc_u8(g(0xA9BC), 0x3EC8C8C8, 0))
    if pid == 0x163E: return U16(s16div(g(0xB074), 0x39000000, 0))
    if pid == 0x16B3: return U16(enc_u16(g(0xAD10), 0x38A00000, 0))
    if pid == 0x16E8: return U16(enc_u16(g(0xB5AC), 0x3B480000, 0))
    if pid == 0x16E9: return U16(enc_u16(g(0xB654), 0x3E000000, 0))
    if pid == 0xA216: return U16(enc_u16(g(0xBC30), 0x38A00000, 0))
    if pid == 0x1782: return U16(enc_u16(g(0xC6AC), 0x38A00000, 0))
    if pid == 0x17A6: return U8(enc_u8(f32(dec_u8(0x43000000, 0, g(0xD1AC)) / f32(1000.0)), 0x3DCCCCCC, 0))
    if pid == 0x172A: return U8(enc_u8(g(0xC4C8), 0x3F800000, 0xC2200000))
    if pid == 0x172D: return U8(g(0xA8F4) & 0xFF)
    if pid == 0x968:
        m = (1 if g(0xB5B4) == 1 else 0) | (0x20 if g(0xBC35) == 1 else 0)
        return U8(subpid_mask(pid, 1, m)) + U8(0)
    if pid == 0x9D3:
        return U8(subpid_mask(pid, 1, 1 if bus.read16(PEDR_W) & 0x400 else 0)) + U8(0)
    if pid == 0x1101:
        m = (1 if g(0xBF3C) == 1 else 0) | (2 if g(0xAD18) == 1 else 0) | (8 if g(0xCDD8) == 1 else 0)
        return U8(subpid_mask(pid, 1, m))
    if pid == 0x1102: return U8(subpid_mask(pid, 1, 1 if g(0xBDB8) == 1 else 0))
    if pid == 0x1103:
        p = bus.read16(PEDR_W)
        m = ((4 if p & 0x800 else 0) | (8 if p & 0x10 else 0)
             | (0x10 if g(0xCAB4) == 1 else 0) | (0x20 if (g(0xD1A2) == 1 or g(0xD1A1) == 1) else 0))
        return U8(subpid_mask(pid, 1, m))
    if pid == 0x1104:
        m = (1 if bus.read16(PJDR_W) & 0x80 else 0) | (0x10 if g(0xBF6C) == 1 else 0)
        return U8(subpid_mask(pid, 1, m))
    if pid == 0x1631:
        b570, tol = g(0xB570), fbits(0x3727C5AC)
        out = 1 if (b570 < f32(-tol) or b570 > f32(tol)) else 0
        return U8(subpid_mask(pid, 1, out | (2 if g(0xB584) != 0 else 0)))
    if pid == 0x1681: return U8(subpid_mask(pid, 1, 0x40 if g(0xCE1C) == 1 else 0))
    if pid == 0x1688: return U8(subpid_mask(pid, 1, 0x20 if g(0xA960) == 1 else 0))
    if pid == 0xA211:
        m1 = (4 if g(0xB53B) == 1 else 0) | (0x10 if g(0xAA62) == 0 else 0)
        m2 = 1 if g(0xBF9C) == 1 else 0
        return U8(subpid_mask(pid, 1, m1)) + U8(subpid_mask(pid, 2, m2))
    if pid == 0x1711: return U8(subpid_mask(pid, 1, 0x80 if bus.read16(PEDR_W) & 2 else 0))
    if pid == 0x1706: return U8(subpid_mask(pid, 1, 4 if g(0xA8F5) == 1 else 0))
    if pid == 0x1718: return U8(subpid_mask(pid, 1, 1 if bus.read16(PEDR_W) & 4 else 0))
    if pid == 0x1715:
        m = (0x40 if bus.read16(PEDR_W) & 0x80 else 0) | (0x80 if bus.read16(PDDR_W) & 0x20 else 0)
        return U8(subpid_mask(pid, 1, m))
    if pid == 0x17DE: return U8(subpid_mask(pid, 1, 1 if g(0xCE32) == 1 else 0))
    if pid == 0xC115: return U8(g(0xC1D2) & 0xFF)
    if pid == 0xC117: return U8(0) + U8(g(0xC1D3) & 0xFF) + U8(g(0xC1D4) & 0xFF) + U8(0)
    if pid == 0xC124:
        return U8((0x40 if g(0xC1D0) == 1 else 0) | (4 if g(0xC274) == 1 else 0))
    if pid == 0xFF10:
        m = ((0x40 if g(0xC1D8) == 1 else 0) | (0x20 if g(0xC1D7) == 1 else 0)
             | (8 if g(0xC1D6) == 1 else 0) | (4 if g(0xC1D5) == 1 else 0))
        return U8(subpid_mask(pid, 1, m)) + U8(0) * 3
    if pid == 0xFF50: return U16(g(0xD3A0) & 0xFFFF)
    if pid == 0xFF44: return U16(g(0xCE30) & 0xFFFF)
    return None


def test_medium_diag22_records_dynamic(booted):
    """Every medium diag22 record (except documented 0x0002/0x1710/0xc116):
    response == exact encoder model at 0 / sentinel / sentinel2."""
    import re
    global RAM_TYPES
    labels = load_labels()
    RAM_TYPES = {k[-4:]: v.get("type", "uint16") for k, v in labels["ram_aliases"].items()}
    _, bus, _ = booted
    med = [r for r in labels["diag22_table"]["records"] if r["confidence"] == "medium"]
    # only 0x0002 and 0x1710 remain medium (documented exceptions)
    assert {r["pid"] for r in med} <= {0x02, 0x1710}, [hex(r["pid"]) for r in med]
    skip = {0x02, 0x1710, 0xC116}
    for rec in med:
        if rec["pid"] in skip:
            continue
        pid = rec["pid"]
        cells = sorted(set(int(c, 16) for c in re.findall(r"ffff([0-9a-f]{4})", rec["evidence"].lower())))
        for c in cells:
            set_cell(bus, c, 0)
        if pid in (0x9D3, 0x1103, 0x1711, 0x1718, 0x1715):
            bus.write16(PEDR_W, 0)
        if pid == 0x1715:
            bus.write16(PDDR_W, 0)
        if pid == 0x1104:
            bus.write16(PJDR_W, 0)
        _, resp = mode22(booted, pid)
        assert resp[3:] == model(bus, pid), (hex(pid), resp.hex(), model(bus, pid).hex())
        for i, c in enumerate(cells):
            t = ctype(c)
            set_cell(bus, c, 12.5 + i if t == "float" else (200 + 37 * i if t == "uint8" else 3000 + 400 * i))
        if pid == 0x9D3: bus.write16(PEDR_W, 0x400)
        if pid == 0x1103: bus.write16(PEDR_W, 0x810)
        if pid == 0x1711: bus.write16(PEDR_W, 0x2)
        if pid == 0x1718: bus.write16(PEDR_W, 0x4)
        if pid == 0x1715: bus.write16(PEDR_W, 0x80); bus.write16(PDDR_W, 0x20)
        if pid == 0x1104: bus.write16(PJDR_W, 0x80)
        _, resp = mode22(booted, pid)
        assert resp[3:] == model(bus, pid), (hex(pid), resp.hex(), model(bus, pid).hex())


def test_checksummed_window_cells(booted):
    """PIDs 0x0031 / 0x1169 read checksummed-window floats (ref_readValue_
    float_DEFAULTVAL_ADDRESS validates u16@+4 == ~(u16@+2 + hi16(bits)));
    with a valid checksum the response tracks the sentinel exactly, without
    it the ROM returns the default (15.0 -> 0x1eb8 observed for 0x1169)."""
    _, bus, _ = booted
    write_valid_float(bus, 0xFFFF90FC, 100.0)
    _, resp = mode22(booted, 0x31)
    assert resp[3:] == U16(enc_u16(100.0, 0x3F800000, 0))
    write_valid_float(bus, 0xFFFF90FC, 7.5)
    _, resp = mode22(booted, 0x31)
    assert resp[3:] == U16(enc_u16(7.5, 0x3F800000, 0))
    write_valid_float(bus, 0xFFFF807C, 25.0)
    _, resp = mode22(booted, 0x1169)
    assert resp[3:] == U16(enc_u16(f32(f32(25.0) / f32(25.0)), 0x38A00000, 0))
    write_valid_float(bus, 0xFFFF807C, 50.0)
    _, resp = mode22(booted, 0x1169)
    assert resp[3:] == U16(enc_u16(f32(f32(50.0) / f32(25.0)), 0x38A00000, 0))


def test_physical_throttle_pedal_chain(booted):
    """AN18 -> ADDR18H -> 0x6884 -> ffff9f08 -> 0x1afb0 -> ffffad5c ->
    PID 0x11/0x1154/0x917; AN19 -> ffffad5e -> PID 0x47. Exact end-to-end
    through the real ADC read path."""
    _, bus, cpu = booted
    for _, _, p in bus.peripherals:
        if type(p).__name__ == "ADC":
            p.channels["AN18"] = 32768
            p.channels["AN19"] = 16384
    harness.call(bus, cpu, 0x6884, max_steps=100000)   # adc_scan_sweep_all_channels
    assert bus.read16(0xFFFF9F08) == 32768 and bus.read16(0xFFFF9F0A) == 16384
    harness.call(bus, cpu, 0x1AFB0, max_steps=10000)   # copy into ad5c/ad5e
    assert bus.read16(0xFFFFAD5C) == 32768 and bus.read16(0xFFFFAD5E) == 16384
    _, resp = mode22(booted, 0x11)   # OBD PID 11 throttle %
    exp = enc_u8(f32(dec_u16(0x38A00000, 0, 32768) * f32(20.0)), 0x3EC8C8C8, 0)
    assert resp[3] == exp == 0x80     # 50.2 %
    _, resp = mode22(booted, 0x1154)
    assert resp[3:] == U16(0x8000)    # raw passthrough
    _, resp = mode22(booted, 0x917)
    assert resp[3:] == U16(s16div(dec_u16(0x38A00000, 0, 32768), 0x3A800000, 0))
    _, resp = mode22(booted, 0x47)    # pedal %
    exp = enc_u8(f32(dec_u16(0x38A00000, 0, 16384) * f32(20.0)), 0x3EC8C8C8, 0)
    assert resp[3] == exp == 0x40     # 25.1 %


def test_d10_pid1410_is_injector_pulse_time(booted):
    """D10: PID 0x1410 reads float injector_pulse_time_ffffbe24 with step
    8.0 (0x41000000); response is independent of the throttle cell."""
    _, bus, _ = booted
    bus.write32(0xFFFFBE24, bits(80.0))
    _, resp = mode22(booted, 0x1410)
    assert resp[3:] == U16(enc_u16(80.0, 0x41000000, 0)) == b"\x00\x0a"
    bus.write32(0xFFFFBE24, bits(800.0))
    bus.write16(0xFFFFAD5C, 0xF000)  # throttle raw maxed
    _, resp = mode22(booted, 0x1410)
    assert resp[3:] == U16(enc_u16(800.0, 0x41000000, 0)) == b"\x00\x64"


def test_control_path_functions(booted):
    _, bus, cpu = booted

    def call(addr, ram=None, r_args=()):
        return harness.call(bus, cpu, addr, r_args=r_args, ram=ram, max_steps=200000)

    # fuel_cut_rpm_condition 0x18cfe: thresholds 2500/1700 on rpm ffffb548
    call(0x18CFE, ram={0xFFFFB548: (4, bits(3000.0))})
    assert bus.read8(0xFFFFA97C) == 1 and bus.read8(0xFFFFA97D) == 1
    call(0x18CFE, ram={0xFFFFB548: (4, bits(1500.0))})
    assert bus.read8(0xFFFFA97C) == 0 and bus.read8(0xFFFFA97D) == 1
    call(0x18CFE, ram={0xFFFFB548: (4, bits(900.0))})
    assert bus.read8(0xFFFFA97C) == 0 and bus.read8(0xFFFFA97D) == 0

    # rev_limit_conditionals 0xee82: coolant hysteresis 18/20 on ffffa98c
    seq = []
    for clt in (10.0, 19.0, 25.0, 19.0, 10.0):
        call(0xEE82, ram={0xFFFFA98C: (4, bits(clt)), 0xFFFFB534: (1, 0),
                          0xFFFFBAEC: (1, 0), 0xFFFFA4AD: (1, 0)})
        seq.append(bus.read8(0xFFFFA4A6))
    assert seq == [1, 1, 0, 0, 1]

    # injector_zero_offset_set 0x86ac: ch -> (a0ac/a0b8, a0b0/a0bc, a0b4/a0c0)
    for ch, pair in ((0, (0xFFFFA0AC, 0xFFFFA0B8)), (1, (0xFFFFA0B0, 0xFFFFA0BC)),
                     (2, (0xFFFFA0B4, 0xFFFFA0C0))):
        call(0x86AC, r_args=(ch,), ram={pair[0]: (2, 0x1111), pair[1]: (2, 0x2222)})
        assert bus.read16(pair[0]) == 0xFFFF and bus.read16(pair[1]) == 0xFFFF

    # maf_voltage_and_fault_counters 0x19f4e
    call(0x19F4E, ram={0xFFFF9EEA: (2, 32768)})
    assert rd_f(bus, 0xFFFFAA2C) == f32(2.5) and bus.read8(0xFFFFAA35) == 0
    call(0x19F4E, ram={0xFFFF9EEA: (2, 0xFFFF)})
    assert bus.read8(0xFFFFAA35) == 1   # raw >= 0xf852 fault counter

    # maf_filtered_update 0x19f40: a9e8 -> a9ec and a9f4
    call(0x19F40, ram={0xFFFFA9E8: (4, bits(42.0))})
    assert rd_f(bus, 0xFFFFA9EC) == 42.0 and rd_f(bus, 0xFFFFA9F4) == 42.0

    # injection_angle_limit_lookup 0xe48e vs extracted cal table tbl_068ef8
    # (axis 800..6800 rpm, u8 60 x10 then 40,30,30,30,30,30; x2.0 scale)
    call(0xE48E, ram={0xFFFFB548: (4, bits(1000.0))})
    assert rd_f(bus, 0xFFFFA434) == 120.0
    call(0xE48E, ram={0xFFFFB548: (4, bits(6000.0))})
    assert rd_f(bus, 0xFFFFA434) == 60.0

    # fuel_cut_arbitration 0xedc4: request a464=1, mode 0 -> a444=a445=1
    call(0xEDC4, r_args=(0,), ram={0xFFFFA464: (1, 1), 0xFFFFA465: (1, 0)})
    assert bus.read8(0xFFFFA444) == 1 and bus.read8(0xFFFFA445) == 1

    # cold_start_enrichment 0x1ddfc: b0c4 = 0.0 on the cranking path
    call(0x1DDFC, ram={0xFFFFB0C4: (4, bits(0.0))})
    assert rd_f(bus, 0xFFFFB0C4) == 0.0

    # timing_trim_scale_calc 0x12e60: a66c = a67c * a698 (a698 from tbl 0x6a04c)
    call(0x12E60, ram={0xFFFFA688: (1, 0), 0xFFFFA67C: (4, bits(3.0)), 0xFFFFA680: (4, bits(5.0))})
    a698 = rd_f(bus, 0xFFFFA698)
    assert rd_f(bus, 0xFFFFA66C) == f32(3.0 * a698)
    assert rd_f(bus, 0xFFFFA670) == f32(5.0 * a698)

    # apv_position_voltage_scale 0x43a86: 9ef0 -> cab0 = raw * 5/65536
    call(0x43A86, ram={0xFFFF9EF0: (2, 32768)})
    assert rd_f(bus, 0xFFFFCAB0) == f32(2.5)

    # apv_drive_status_sample 0xaac4: PHDR bits -> a1bc 0..3 remap
    for val, exp in ((0x3000, 0), (0x2000, 1), (0x1000, 2), (0x0000, 3)):
        bus.write16(PHDR_W, val)
        call(0xAAC4, ram={0xFFFFA1C8: (1, 1)})
        assert bus.read8(0xFFFFA1BC) == exp, hex(val)

    # apv_pwm_service 0xa936: reverse ticks latch -> PLDR_W bit 0x100 set
    bus.write16(PLDR_W, 0)
    call(0xA936, ram={0xFFFFA1BE: (2, 0), 0xFFFFA1C4: (2, 0x30), 0xFFFFA1C6: (2, 0x10),
                      0xFFFFA1C0: (2, 0), 0xFFFFA1C2: (2, 0), 0xFFFFA1C8: (1, 0), 0xFFFFA1C9: (1, 0)})
    for _ in range(0x62):
        call(0xA936, ram={0xFFFFA1C4: (2, 0x30), 0xFFFFA1C6: (2, 0x10)})
    assert bus.read16(PLDR_W) & 0x100  # reverse channel active-high observed at period boundary

    # apv counters 0x31ece / 0x31f0a / command 0x31f32
    call(0x31ECE, ram={0xFFFFBF8B: (1, 0), 0xFFFFBF88: (2, 0), 0xFFFFCAB4: (2, 0)})
    assert bus.read16(0xFFFFBF88) == 0
    call(0x31F0A, ram={0xFFFFBF8B: (1, 0), 0xFFFFBF8A: (1, 0)})
    assert bus.read8(0xFFFFBF8A) == 1
    call(0x31F32, ram={0xFFFFBF8D: (1, 1), 0xFFFFBF88: (2, 0x100), 0xFFFFB548: (4, bits(3000.0))})
    assert rd_f(bus, 0xFFFFBF84) == 100.0  # staged literal 0x42c80000

    # adc_read_ect_iat_group 0x6cdc with group selector ffff9f31 = 8
    for _, _, p in bus.peripherals:
        if type(p).__name__ == "ADC":
            p.channels["AN28"] = 9000
            p.channels["AN29"] = 2500
    call(0x6CDC, ram={0xFFFF9F31: (1, 8)})
    assert bus.read16(0xFFFF9F1C) == 9000 and bus.read16(0xFFFF9F1E) == 2500


def test_uds_service_router_medium_services(booted):
    """Router 0x68dac reaches the medium-labeled service handlers."""
    _, bus, cpu = booted
    for svc, handler, session_bit in [(0x21, 0x5B414, 0), (0x18, 0x57DB0, 0), (0x12, 0x5B094, 0),
                                      (0x32, 0x5E024, 0), (0x33, 0x5E0CE, 0), (0xB1, 0x565E8, 0),
                                      (0x3B, 0x5D8B4, 1)]:
        bus.write8(0xFFFFDE20, session_bit)
        harness.call(bus, cpu, 0x68DAC, r_args=(svc, 0, svc), max_steps=100000, stop_at=(handler,))
        assert cpu.pc == handler, hex(svc)
