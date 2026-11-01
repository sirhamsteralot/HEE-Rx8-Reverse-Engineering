"""Phase 1 open item: dynamic reproduction of static findings + reimplementation
cross-validation, executed in the emulator against the real ROM code.

- math helpers 0x23b0/0x23dc/0x23e4/0x23f4/0x2404 vs a float32-faithful port of
  reverse-engineered/reimplementation/rx8_math.c (host cc test needs a C
  compiler; the port mirrors the C line-by-line with f32 rounding, FMA where
  the ROM uses fmac)
- knock_retard_clamp 0x13bd2: dynamic proof of the [-10, 0] deg clamp
- injector_pulse_set_channel 0x8a68: channel -> ATU-II DCNT8A-P/GR1A-H map vs
  ROM table 0xd7d4
- ADC read path: ref_sensorADCRead 0x6884 consumes scripted ADDRnH channels
- RCAN (E4): inject -> ROM CAN RX poller -> UDS buffer; ROM tx -> 0x7e8 tx_log;
  Mode 22 dispatch 0x5774c (identifier 0x0043 -> handler 0x56b8a)
Run: python -m pytest tests/test_phase1_dynamic.py
"""
import math
import os
import struct
import sys

import pytest

EMU = os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts", "emu")
sys.path.insert(0, os.path.abspath(EMU))

import emu  # noqa: E402
import harness  # noqa: E402
from can import CANController  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def fma32(a, b, c):
    # ROM uses fmac (fused): emulate with exact double product + double add
    return f32(f32(a) * f32(b) + f32(c))


@pytest.fixture(scope="module")
def booted():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to the idle loop
    return prof, bus, cpu


# --- float32 port of reverse-engineered/reimplementation/rx8_math.c ---------

def ref_filter(cur, prev, coef, snap):  # rx8_first_order_filter @0x23b0
    # E1 closed: FR registers and every FPU result are float32. Mirror the ROM's
    # exact op order (0x23b0: fsub, fsub, fmac, fsub, fabs, fcmp/gt): round each
    # intermediate to f32; fmac rounds once (fused).
    cur, prev, coef, snap = f32(cur), f32(prev), f32(coef), f32(snap)
    if (harness.bits(prev) & 0x7F800000) == 0x7F800000:
        return float(cur)
    delta = f32(prev - cur)          # fsub fr4,fr5
    gain = f32(1.0 - coef)           # fldi1; fsub fr6,fr0
    filt = f32(cur + gain * delta)   # fmac fr0,fr5,fr6 (fused, single rounding)
    diff = f32(abs(f32(cur - filt))) # fsub fr6,fr5; fabs
    return float(cur) if snap > diff else filt  # fcmp/gt fr5,fr7; bf


def ref_absdiff(a, b):
    return f32(abs(f32(f32(a) - f32(b))))


def ref_max(a, b):
    a, b = f32(a), f32(b)
    return a if a > b else b


def ref_min(a, b):
    a, b = f32(a), f32(b)
    return a if b > a else b


def ref_clamp(v, lo, hi):  # rx8_clamp_float @0x2404
    v, lo, hi = f32(v), f32(lo), f32(hi)
    if not (v > lo):
        return lo
    return v if hi > v else hi


HELPERS = {  # ROM addr -> (python ref, arg count)
    0x23B0: (ref_filter, 4),
    0x23DC: (ref_absdiff, 2),
    0x23E4: (ref_max, 2),
    0x23F4: (ref_min, 2),
    0x2404: (ref_clamp, 3),
}

VECTORS = [
    (1.0, 0.0, 0.25, 0.0), (5.0, 4.0, 0.5, 0.1), (10.0, 2.0, 0.004, 1.0),
    (-3.0, 7.0, 0.9, 0.5), (0.0, 0.0, 0.0, 0.0), (2.5, 2.5, 1.0, 0.0),
    (1e30, -1e30, 0.5, 1.0), (-0.0, 0.0, 0.25, 0.0),
]


@pytest.mark.parametrize("addr,ref,nargs", [(a, r, n) for a, (r, n) in HELPERS.items()])
def test_math_helpers_vs_reimplementation(booted, addr, ref, nargs):
    _, bus, cpu = booted
    for vec in VECTORS:
        args = vec[:nargs]
        _, rom_r, _ = harness.call(bus, cpu, addr, fr_args=args)
        exp = ref(*args)
        assert harness.bits(rom_r) == harness.bits(exp), (
            f"0x{addr:08x}{args}: rom={rom_r!r} ref={exp!r}")


def test_knock_retard_clamp_dynamic(booted):
    """knock_retard_clamp 0x13bd2 clamps to [tbl_0x6af68(rpm), tbl_0x6af90(rpm)=0]."""
    _, bus, cpu = booted
    for rpm in (1000.0, 3000.0):
        bus.write32(0xFFFFB548, harness.bits(f32(rpm)))  # engine_speed_rpm_ffffb548
        bus.write8(0xFFFFB534, 0)   # use tbl 0x6af68 (not alt 0x6af7c)
        bus.write8(0xFFFFBC3D, 0)
        results = {}
        for v in (-15.0, -10.0, -5.0, 0.0, 5.0):
            _, r, _ = harness.call(bus, cpu, 0x13BD2, fr_args=(v,))
            results[v] = r
        assert results[-15.0] == -10.0   # clamped to min table (-10 at low rpm)
        assert results[5.0] == 0.0       # clamped to max table (0)
        assert results[-5.0] == -5.0     # inside the window: unchanged
    # at 6000 rpm the min table is 0 -> everything clamps to 0 (reset at high rpm)
    bus.write32(0xFFFFB548, harness.bits(f32(6000.0)))
    _, r, _ = harness.call(bus, cpu, 0x13BD2, fr_args=(-15.0,))
    assert r == 0.0


def test_injector_channel_map_dynamic(booted):
    """injector_pulse_set_channel 0x8a68(ch) writes DCNT8x/GR1x per ROM 0xd7d4."""
    prof, bus, cpu = booted
    with open(prof["rom"]["_abs_path"], "rb") as f:
        rom = f.read()
    for ch in range(6):
        dcnt_ptr, gr1_ptr, _tier = struct.unpack(">III", rom[0xD7D4 + 12 * ch:0xD7D4 + 12 * ch + 12])
        fuel, lat = 0x1000 * (ch + 1), 0x40
        bus.write32(0xFFFFA010 + ch * 0x18, fuel)   # injector_fuel_request_array
        bus.write32(0xFFFFA094 + 4 * ch, lat)        # injector_latency (u32 array)
        bus.write16(0xFFFFA014 + ch * 0x18, 0x1234)  # start compare
        n0 = len(bus.mmio_log)
        harness.call(bus, cpu, 0x8A68, r_args=(ch,))
        writes = [(m[2], m[3]) for m in bus.mmio_log[n0:] if 0xFFFFF400 <= m[2] < 0xFFFFF700]
        dcnt_w = [w for w in writes if 0xFFFFF640 <= w[0] <= 0xFFFFF65E]
        gr1_w = [w for w in writes if 0xFFFFF444 <= w[0] <= 0xFFFFF452]
        assert dcnt_w and dcnt_w[0][0] == dcnt_ptr, f"ch{ch}: DCNT write {dcnt_w} != {dcnt_ptr:#x}"
        assert dcnt_w[0][1] == ((lat + fuel) >> 4) & 0xFFFF
        assert gr1_w and gr1_w[0][0] == gr1_ptr and gr1_w[0][1] == 0x1234


def test_adc_read_path_dynamic(booted):
    """ref_sensorADCRead 0x6884: scripted ADDRnH channels land in RAM."""
    _, bus, cpu = booted
    adc = next(p for _, _, p in bus.peripherals if type(p).__name__ == "ADC")
    adc.channels["AN3"] = 0xABCD   # MAF -> ADDR3H
    adc.channels["AN6"] = 0x1234   # APV -> ADDR6H
    adc.channels["AN10"] = 0x5678  # knock -> ADDR10H
    harness.call(bus, cpu, 0x6884, max_steps=100000)  # must not hang in ADCSR wait
    # the sweep reads ADDRn as a 16-bit word (H+L = full result)
    assert bus.read16(0xFFFF9EEA) == 0xABCD     # maf_adc_raw_ffff9eea = ADDR3
    assert bus.read16(0xFFFF9EF0) == 0x1234     # adc6_raw_apv_position_ffff9ef0 = ADDR6
    assert bus.read16(0xFFFF9EF8) == 0x5678     # knock_sensor_adc_raw_ffff9ef8 = ADDR10


def test_rcan_rx_tx_through_rom_driver(booted):
    """E4: inject -> ROM CAN RX poller -> UDS buffer; ROM txCAN -> 0x7e8 tx_log."""
    _, bus, cpu = booted
    can = next(p for _, _, p in bus.peripherals if isinstance(p, CANController))
    assert can._mailbox_id(14) == 0x7E0 and can._mailbox_id(15) == 0x7E8
    can.inject(0x7E0, bytes([0x02, 0x10, 0x03, 0, 0, 0, 0, 0]))
    assert can.read(0x0E, 2) & 0x40  # RXPR mb14 pending
    harness.call(bus, cpu, 0x11D88, max_steps=300000)  # FUN_00011d88 CAN RX poll
    assert bus.read32(0xFFFFDDC8).to_bytes(4, "big")[:3] == bytes.fromhex("021003")
    assert not (can.read(0x0E, 2) & 0x40)  # poller cleared RXPR
    # TX side: ROM's ref_txCAN_EventBased (0x99b0) with the 0x7e8 descriptor 0x4e00c
    resp = bytes([0x06, 0x50, 0x03, 0x00, 0x32, 0x01, 0xF4, 0x00])
    bus.write32(0xFFFFDDD0, int.from_bytes(resp[:4], "big"))
    bus.write32(0xFFFFDDD4, int.from_bytes(resp[4:], "big"))
    harness.call(bus, cpu, 0x99B0, r_args=(0x4E00C,), max_steps=100000)
    assert [(cid, d) for _, cid, d in can.tx_log] == [(0x7E8, resp)]
    assert can.read(0x0A, 2) & 0x80  # TXACK mb15


def test_mode22_dispatch_pid_0043(booted):
    """diag22_find_and_dispatch_identifier 0x5774c: identifier 0x0043 -> 0x56b8a."""
    _, bus, cpu = booted
    bus.write16(0xFFFFD1EA, 0x0043)   # diag22_current_identifier_ffffd1ea
    bus.write8(0xFFFFD1E8, 0)
    bus.write16(0xFFFFD3B4, 0xFFFF)   # availability mask: allow
    bus.write32(0xFFFFC0B4, harness.bits(f32(0.42)))  # engine_load g/rev
    r0, _, _ = harness.call(bus, cpu, 0x5774C, max_steps=200000)
    # record 0x5f268: response_length 2 -> return 2 + RX8_DIAG_READ_HEADER_SIZE(3)
    assert r0 == 5


# --- UDS Mode 22 dispatch table labeling (ROADMAP group C, 2026-10-31) -------

MODE22_RING = 0xFFFFD962  # channel-0 response ring written by ref_pack_for_OBD_response_


def _mode22_response(booted, pid, allow_mask=0xFFFF):
    """Drive the ROM's own diag22 dispatcher 0x5774c for one PID; return
    (return_value, full response bytes incl. 0x62 header) from the ch0 ring."""
    _, bus, cpu = booted
    harness.call(bus, cpu, 0x68B10, r_args=(0, 0x22), max_steps=10000)  # bind ch0<-svc 0x22
    bus.write8(0xFFFFDDEC, 0)        # current channel = 0
    bus.write16(0xFFFFD95C, 0)       # ring write position = 0
    bus.write16(0xFFFFD1EA, pid)     # diag22_current_identifier_ffffd1ea
    bus.write8(0xFFFFD1E8, 0)
    bus.write16(0xFFFFD3B4, allow_mask)  # diag_permission_mask_ffffd3b4
    r0, _, _ = harness.call(bus, cpu, 0x5774C, max_steps=200000)
    n = max(r0 - 3, 0)
    return r0, bytes(bus.read8(MODE22_RING + i) for i in range(3 + n))


def test_mode22_dispatch_table_payloads(booted):
    """End-to-end through 0x5774c: each dispatch record's handler produces the
    labeled response. Encodings verified against the ROM's own fixed-point
    encoder semantics (trunc((signal-offset)/step + 0.5), f32, clamp)."""
    _, bus, _ = booted
    bus.write32(0xFFFF9F70, harness.bits(f32(90.0)))    # coolant_temperature_ffff9f70
    bus.write32(0xFFFFB548, harness.bits(f32(3000.0)))  # engine_speed_rpm_ffffb548
    bus.write32(0xFFFFC0B4, harness.bits(f32(0.42)))    # engine_load_ffffc0b4 g/rev
    bus.write32(0xFFFFBBB4, harness.bits(f32(88.0)))    # vehicle_speed_ffffbbb4

    def enc_u16(signal, step_bits, offset=0.0):
        step = struct.unpack(">f", struct.pack(">I", step_bits))[0]
        t = f32(f32(f32(signal) - f32(offset)) / f32(step))
        c = int(t + 0.5)  # trunc(t+0.5) on non-negative values
        return max(0, min(0xFFFF, c))

    # pid -> expected payload after the 62 <pid> header
    cases = {
        0x0000: bytes.fromhex("be1fe813"),                # supported-PID bitmap (const)
        0x0005: bytes([enc_u16(90.0, 0x3F800000, -40.0)]),  # ECT: (90+40)/1 = 130
        0x000C: enc_u16(3000.0, 0x3E800000).to_bytes(2, "big"),  # rpm: 3000/0.25 = 12000
        0x000D: bytes([88]),                               # vss km/h
        0x0043: enc_u16(0.42, 0x3B808080).to_bytes(2, "big"),    # g/rev, step 1/255 -> 107
        0xE611: b"SW-N3ZHEB000.HEX" + bytes(8),            # cal-id string from ROM 0x6c043, 24-byte field
        0x0200: bytes([0]),                                # stored DTC count (empty)
        0x0202: bytes([0]),                                # RAM DTC list count (empty)
    }
    for pid, payload in cases.items():
        r0, resp = _mode22_response(booted, pid)
        assert resp == bytes([0x62]) + pid.to_bytes(2, "big") + payload, hex(pid)
        assert r0 == 3 + len(payload)

    # permission mask gates the record: PID 0xc115 has availability_mask 0x3bfc;
    # with DAT_ffffd3b4 = 0 the handler must not run -> NRC 0x31 (7f 22 31)
    r0, resp = _mode22_response(booted, 0xC115, allow_mask=0x0000)
    assert (r0, resp) == (3, bytes.fromhex("7f2231"))


def test_nmi_pin_replaces_guessed_override():
    """E5 closed: profiles carry no io_read_overrides; boot reaches idle because
    SYSC models ICR_W bit15 = NMI pin level (boot polls it at 0x8ea)."""
    prof, bus, cpu = emu.build(PROFILE)
    assert not prof["memory"].get("io_read_overrides")
    emu.run(prof, bus, cpu, 1_000_000)
    assert cpu.pc == 0x3DAC  # idle loop reached
    sysc = next(p for _, _, p in bus.peripherals if type(p).__name__ == "SYSC")
    assert sysc.read(sysc.ICR, 2) & 0x8000  # NMI high


def test_can_rx_interrupt_autonomous():
    """E4/E6 progress: inject() raises the CAN RX interrupt (IVT offset 0x378);
    a plain emu.run then runs the ROM's CAN RX poll (0x11d88) and moves the frame
    into the UDS RX buffer 0xffffddc8 without any manual entry-point calls."""
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)  # boot to idle
    can = next(p for _, _, p in bus.peripherals if isinstance(p, CANController))
    assert int(str(can.rx_vector), 0) == 0x378
    can.inject(0x7E0, bytes([0x02, 0x10, 0x03, 0x55, 0, 0, 0, 0]))
    assert can.read(0x0E, 2) & 0x40  # RXPR mb14 pending
    emu.run(prof, bus, cpu, 20000)
    assert bus.read32(0xFFFFDDC8).to_bytes(4, "big") == bytes.fromhex("02100355")
    assert not (can.read(0x0E, 2) & 0x40)  # poller cleared RXPR
    assert cpu.pc == 0x3DAC  # back at idle


# --- ignition timing chain (Phase 2 labeling pass, 2026-10-31) ---------------

def _wf(bus, addr, v):
    bus.write32(addr, harness.bits(f32(v)))


def _rf(bus, addr):
    return f32(struct.unpack("<f", struct.pack("<I", bus.read32(addr)))[0])


def test_timing_cranking_blend_equation(booted):
    """0x123da/0x124d6: a640 = a5e8*a644 + (a5f0+a718+ca9c)*(1-a644) + a780 - a778.
    Verified bit-exact in the emulator for both rotors (thread section 9 equation)."""
    _, bus, cpu = booted
    _wf(bus, 0xFFFFA5E8, 30.0); _wf(bus, 0xFFFFA5F0, -2.0); _wf(bus, 0xFFFFA718, 0.5)
    _wf(bus, 0xFFFFCA9C, 12.0); _wf(bus, 0xFFFFA780, 8.0); _wf(bus, 0xFFFFA778, 1.5)
    _wf(bus, 0xFFFFA644, 0.5); _wf(bus, 0xFFFFB548, 5000.0); _wf(bus, 0xFFFFA7AC, 0.0)
    bus.write8(0xFFFFAA62, 1)  # cranking -> a644 decays 0.05/call
    harness.call(bus, cpu, 0x123DA, max_steps=50000)
    m = max(0.5 - 0.05, 0.0)
    exp = 30.0 * m + (-2.0 + 0.5 + 12.0) * (1 - m) + 8.0 - 1.5
    assert abs(_rf(bus, 0xFFFFA644) - m) < 1e-6
    assert abs(_rf(bus, 0xFFFFA640) - exp) < 1e-4
    bus.write8(0xFFFFAA62, 0)  # not cranking -> a644 -> 1.0, blend collapses
    _wf(bus, 0xFFFFA644, 0.5)
    harness.call(bus, cpu, 0x123DA, max_steps=50000)
    assert abs(_rf(bus, 0xFFFFA644) - 1.0) < 1e-6
    assert abs(_rf(bus, 0xFFFFA640) - (30.0 + 8.0 - 1.5)) < 1e-4
    # trailing mirror 0x124d6
    _wf(bus, 0xFFFFA5EC, 20.0); _wf(bus, 0xFFFFA5F4, -1.0); _wf(bus, 0xFFFFA71C, 0.3)
    _wf(bus, 0xFFFFCAA0, 10.0); _wf(bus, 0xFFFFA784, 6.0); _wf(bus, 0xFFFFA77C, 2.0)
    _wf(bus, 0xFFFFA654, 0.5)
    bus.write8(0xFFFFAA62, 1)
    harness.call(bus, cpu, 0x124D6, max_steps=50000)
    exp_t = 20.0 * m + (-1.0 + 0.3 + 10.0) * (1 - m) + 6.0 - 2.0
    assert abs(_rf(bus, 0xFFFFA650) - exp_t) < 1e-4


def test_timing_correction_add_and_final_clamp(booted):
    """0x123ba adds base+corrections; 0x121fc clamps into a630 with min/max tables."""
    _, bus, cpu = booted
    _wf(bus, 0xFFFFA640, 25.0); _wf(bus, 0xFFFFA648, -3.5)
    harness.call(bus, cpu, 0x123BA)
    assert abs(_rf(bus, 0xFFFFA634) - 21.5) < 1e-6
    _wf(bus, 0xFFFFA634, 100.0); _wf(bus, 0xFFFFA64C, -24.0); _wf(bus, 0xFFFFB548, 3000.0)
    bus.write8(0xFFFFAA62, 0); bus.write8(0xFFFFCE1C, 0); bus.write8(0xFFFFBBCE, 0)
    _wf(bus, 0xFFFFA934, 0.0)
    harness.call(bus, cpu, 0x121FC, max_steps=100000)
    a660 = _rf(bus, 0xFFFFA660)
    assert a660 > 0  # max advance table 0x69190 read at 3000 rpm
    assert abs(_rf(bus, 0xFFFFA630) - min(100.0, a660)) < 1e-4
    _wf(bus, 0xFFFFA634, -100.0)
    harness.call(bus, cpu, 0x121FC, max_steps=100000)
    assert abs(_rf(bus, 0xFFFFA630) - (-24.0)) < 1e-6
