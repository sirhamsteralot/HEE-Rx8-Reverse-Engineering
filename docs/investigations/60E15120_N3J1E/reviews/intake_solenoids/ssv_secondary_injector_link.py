#!/usr/bin/env python3
"""Dynamic check: does the SSV follow the secondary-injector-active flag?

Boots 60E15120_N3J1E in the SH-2E emulator, drives the documented RAM input
cells, and harness-calls:
  - 0x2178c ssv_solenoid_control  (PEDR_W 0xfffff754 bit 0x80 = PE7 = SSV pin)
  - 0x30b08 (primary/secondary fuel split; computes 0xffffbecc/0xffffbecd)
Result: the SSV on-condition ORs in DAT_ffffbecd (0x30b08's
secondary-split-active flag) — becd=1 drives PE7 high even with the engine
running and even when the coolant-hot flag 0xffffb2b4 is set; becd=0 leaves
only the cold/engine-stopped counter path (aa68==0 && b2b2!=0 && !b2b4).
Run from anywhere: python3 docs/investigations/60E15120_N3J1E/reviews/intake_solenoids/ssv_secondary_injector_link.py
"""
import os, struct, sys

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", "..", "..", ".."))
EMU = os.path.join(REPO, "utilities", "scripts", "emu")
sys.path.insert(0, EMU)
import emu, harness  # noqa: E402

PROFILE = os.path.join(EMU, "profiles", "60E15120_N3J1E.json")
SSV = 0x2178C
SPLIT = 0x30B08
LOOKUP2D = 0x2068

PEDR_W = 0xFFFFF754
COOLANT = 0xFFFFA98C
RPM = 0xFFFFB548
BARO = 0xFFFFAD14
THROTTLE = 0xFFFFAD44
FUEL_VOL_FINAL = 0xFFFFBEB0
FUEL_A = 0xFFFFBEC8
FUEL_D = 0xFFFFBEDC
FUEL_B = 0xFFFFBEEC
FUEL_RATIO_A = 0xFFFFBEE4
BECC = 0xFFFFBECC
BECD = 0xFFFFBECD
BECE = 0xFFFFBECE
BF24 = 0xFFFFBF24
BF28 = 0xFFFFBF28
BF36 = 0xFFFFBF36
BF37 = 0xFFFFBF37
BF38 = 0xFFFFBF38
BF39 = 0xFFFFBF39
BF0C = 0xFFFFBF0C
BF0D = 0xFFFFBF0D
AA68 = 0xFFFFAA68
B2B2 = 0xFFFFB2B2   # ssv_on_counter (u16)
B2B4 = 0xFFFFB2B4   # ssv_coolant_hot_flag
B2B5 = 0xFFFFB2B5   # ssv_was_enabled
B2B0 = 0xFFFFB2B0   # ssv_diag_override_result
# diag state cells (must stay in passthrough: d326 == 0)
D314 = 0xFFFFD314
D319 = 0xFFFFD319
D326 = 0xFFFFD326
D36C = 0xFFFFD36C


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]

def wf(bus, a, v):
    bus.write32(a, harness.bits(f32(v)))

def rf(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a)))[0]

def ssv_pin(bus):
    return (bus.read16(PEDR_W) >> 7) & 1

def reset_diag(bus):
    for a in (D319, D326, D36C):
        bus.write8(a, 0)
    bus.write16(D314, 0x0000)  # != -0x16da -> passthrough

def ssv_case(bus, cpu, name, becd, aa68, b2b2, b2b4, b2b5, coolant):
    reset_diag(bus)
    bus.write8(BECD, becd)
    bus.write8(AA68, aa68)
    bus.write16(B2B2, b2b2)
    bus.write8(B2B4, b2b4)
    bus.write8(B2B5, b2b5)
    wf(bus, COOLANT, coolant)
    harness.call(bus, cpu, SSV)
    pin = ssv_pin(bus)
    print(f"  {name}: becd={becd} aa68={aa68} b2b2={b2b2:#x} b2b4={b2b4} b2b5={b2b5} "
          f"coolant={coolant} -> SSV pin(PE7)={pin} (b2b0={bus.read8(B2B0)}, b2b2 now={bus.read16(B2B2):#x})")
    return pin

def split_case(bus, cpu, name, rpm, coolant, baro, throttle, fuel_vol, fuel_a):
    bus.write8(BECC, 0); bus.write8(BECD, 0); bus.write8(BECE, 0)
    bus.write8(BF0C, 0); bus.write8(BF0D, 0)
    wf(bus, RPM, rpm); wf(bus, COOLANT, coolant); wf(bus, BARO, baro)
    wf(bus, THROTTLE, throttle); wf(bus, FUEL_VOL_FINAL, fuel_vol)
    wf(bus, FUEL_A, fuel_a); wf(bus, FUEL_D, fuel_a); wf(bus, FUEL_B, fuel_a)
    wf(bus, FUEL_RATIO_A, fuel_a)
    harness.call(bus, cpu, SPLIT, max_steps=200000)
    print(f"  {name}: rpm={rpm} coolant={coolant} fuel_vol={fuel_vol} fuel_a={fuel_a} thr={throttle} -> "
          f"bf24(thr1)={rf(bus, BF24):.1f} bf36={bus.read8(BF36)} "
          f"bf28(sec-allow-thr)={rf(bus, BF28):.1f} bf37={bus.read8(BF37)} "
          f"bf38={bus.read8(BF38)} bf39={bus.read8(BF39)} => becd={bus.read8(BECD)} becc={bus.read8(BECC)}")
    return bus.read8(BECD), bus.read8(BECC)

def main():
    prof, bus, cpu = emu.build(PROFILE)
    emu.run(prof, bus, cpu, 300000)

    print("== threshold tables (ROM lookup 0x2068) ==")
    for cool in (20.0, 40.0, 60.0, 90.0):
        t1f = harness.call(bus, cpu, LOOKUP2D, r_args=(0x6AC74,), fr_args=(cool,))[1]
        t2f = harness.call(bus, cpu, LOOKUP2D, r_args=(0x6AC60,), fr_args=(cool,))[1]
        print(f"  coolant={cool}: tbl_0x6ac74 -> {t1f:.1f} rpm ; tbl_0x6ac60 (secondary allowed) -> {t2f:.1f} rpm")

    print("== SSV (0x2178c) pin vs becd ==")
    a = ssv_case(bus, cpu, "sec-inj flag set, engine running, coolant normal", 1, 1, 0, 0, 1, 90.0)
    b = ssv_case(bus, cpu, "sec-inj flag clear, engine running", 0, 1, 0, 0, 1, 90.0)
    c = ssv_case(bus, cpu, "sec-inj flag clear, engine stopped edge (sets counter)", 0, 0, 0, 0, 1, 90.0)
    d = ssv_case(bus, cpu, "counter path active (aa68=0, b2b2!=0, not hot)", 0, 0, 0xbc, 0, 0, 90.0)
    e = ssv_case(bus, cpu, "counter path but coolant hot (b2b4=1)", 0, 0, 0xbc, 1, 0, 250.0)
    f = ssv_case(bus, cpu, "becd=1 even though coolant hot", 1, 1, 0, 1, 1, 250.0)
    assert a == 1 and b == 0 and d == 1 and e == 0 and f == 1, "SSV cases failed"
    assert c == 1  # edge call sets counter 0xbc and turns on in the same pass

    print("== 0x30b08 split flags vs rpm/fuel ==")
    g = split_case(bus, cpu, "high rpm, normal fuel", 6000.0, 90.0, 1.0, 10.0, 0.02, 0.010)
    h = split_case(bus, cpu, "low rpm (below sec threshold)", 2000.0, 90.0, 1.0, 10.0, 0.02, 0.010)
    i = split_case(bus, cpu, "high rpm but zero fuel demand", 6000.0, 90.0, 1.0, 10.0, 0.0, 0.0)
    j = split_case(bus, cpu, "cold coolant, mid rpm", 4000.0, 20.0, 1.0, 10.0, 0.02, 0.010)
    k = split_case(bus, cpu, "warm, LOW fuel demand (below primary cap)", 6000.0, 90.0, 1.0, 10.0, 0.001, 0.010)
    l = split_case(bus, cpu, "cold (0C), rpm below 3000 gate", 2000.0, 0.0, 1.0, 10.0, 0.02, 0.010)
    m = split_case(bus, cpu, "cold (0C), rpm above 3000 gate", 4000.0, 0.0, 1.0, 10.0, 0.02, 0.010)
    n = split_case(bus, cpu, "warm, high rpm, WOT (throttle>=60) low fuel", 7000.0, 90.0, 1.0, 80.0, 0.001, 0.010)
    o = split_case(bus, cpu, "very high rpm 6500 (bf36 override), low fuel", 6500.0, 90.0, 1.0, 10.0, 0.001, 0.010)
    print("RESULT: warm+fuel =", g, "; low rpm warm =", h, "; zero fuel =", i, "; cold mid =", j)
    print("        warm low demand =", k, "; cold below gate =", l, "; cold above gate =", m, "; WOT low fuel =", n, "; 6500rpm low fuel =", o)

if __name__ == "__main__":
    main()
