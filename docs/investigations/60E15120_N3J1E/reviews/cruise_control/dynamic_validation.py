"""Cruise-control follow-up validation on the SH-2E emulator (60E15120_N3J1E).

Proves dynamically (ROM functions harness-called on a booted profile, inputs
set through the hardware paths where applicable):

1. 0xffffcf1c (cruise "band" selector) is produced by 0x4de1c as
   float(current gear 0xffffbc3d) on this ROM (config byte ROM 0x7d07f = 0);
   the alternative switch-code band map compiled into 0x4de1c
   (cf47->0.0, cf48->2.0 ... cf4c->6.0) is disabled by that config byte.
   Gear chain: 0x2c324 candidate from rpm/vss ratio, 0x2c3b2 latch (>0xb
   confirmation counts, 0 when neutral flag 0xffffb53a==1).
2. 0xffffbcf8 is a percent (0-100) cruise OUTPUT, not km/h: 0x4c896 sets
   enable flag 0xffffcf34 = cruise_on && bcf8 >= 0xffffa9b4 (TP1 percent) —
   pedal override; 0x193c4 mixes a9bc = min(max(a9b4, bcf8), limiter 0xffffc028)
   in the same percent domain; 0x228dc maps a9bc x rpm through the
   pedal->throttle-plate tables.
3. The set speed in km/h is the learned readValue cell 0xffff866c, latched by
   0x32614 from filtered vss 0xffffbfa0 clamped [27, 200] (100 when 0xffffbd49),
   with the cruise target 0xffffbfa4 clamped to the same range.
4. 0xffffa9b4 tracks the AN4 (TP1) ADC channel as a 0-100 percent (learned
   zero/span in the readValue cells 0xffff8068/0xffff8070), NOT vehicle speed.

Run from the repo root:
    python docs/investigations/60E15120_N3J1E/reviews/cruise_control/dynamic_validation.py
Output is recorded in dynamic_validation_log.txt.
"""
import os
import struct
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", "..", "..", ".."))
sys.path.insert(0, os.path.join(ROOT, "utilities", "scripts", "emu"))

import emu      # noqa: E402
import harness  # noqa: E402
import ui       # noqa: E402

PROFILE = os.path.join(ROOT, "utilities", "scripts", "emu", "profiles", "60E15120_N3J1E.json")
ROM_PATH = os.path.join(ROOT, "submodules", "Mazda_RX8_PCM_ReverseEngineering",
                        "Stock_ROMs", "60E15120_N3J1E.bin")

# RAM cells
A9EEC = 0xFFFF9EEC     # ADDR4H (AN4 = TP1) raw, via adc sweep 0x6884
A108 = 0xFFFFA108      # TP-derived scaled value (0x94f0)
A99C = 0xFFFFA99C      # min(25, a108[0]) (0x18f60)
A9AC = 0xFFFFA9AC      # max(0, a99c - learned zero) (0x1933a)
A9B4 = 0xFFFFA9B4      # TP1 percent (0x193c4)
A9B8 = 0xFFFFA9B8      # TP2 percent
A9BC = 0xFFFFA9BC      # demand percent min(max(a9b4, bcf8), c028)
BC3C = 0xFFFFBC3C      # candidate gear (0x2c324)
BC3D = 0xFFFFBC3D      # latched current gear (0x2c3b2)
B534 = 0xFFFFB534      # automatic_transmission mode select
B53A = 0xFFFFB53A      # neutral flag
BBB4 = 0xFFFFBBB4      # vehicle speed km/h
B548 = 0xFFFFB548      # engine rpm
BFA0 = 0xFFFFBFA0      # filtered vehicle speed
BFA4 = 0xFFFFBFA4      # cruise target speed
BCF8 = 0xFFFFBCF8      # cruise output percent
BD00 = 0xFFFFBD00      # control-law output
BD49 = 0xFFFFBD49      # set-speed cap select (100 vs 200 km/h)
BCED = 0xFFFFBCED      # cruise on flag
CF1C = 0xFFFFCF1C      # band selector float
CF34 = 0xFFFFCF34      # cruise enable flag
CF47 = 0xFFFFCF47      # decoded switch flags cf47..cf4c
C028 = 0xFFFFC028      # speed-limiter cap
A914 = 0xFFFFA914
CC9B = 0xFFFFCC9B
CC9C = 0xFFFFCC9C
A9D0 = 0xFFFFA9D0
A9D4 = 0xFFFFA9D4
C866C = 0xFFFF866C     # learned cruise set speed (km/h)
C8664 = 0xFFFF8664      # readValue 8-bit flag used by 0x2df62 gate
CAA68 = 0xFFFFAA68      # engine running flag

# ROM functions
ADC_SWEEP = 0x6884
TP_RAW_MAP = 0x94F0
TP_FILTER = 0x18F44
TP_DELTA = 0x1933A
TP_PCT = 0x193C4
GEAR_CAND = 0x2C324
GEAR_LATCH = 0x2C3B2
BAND_PRODUCER = 0x4DE1C
SW_DECODE = 0x4C828
ENABLE_FLAG = 0x4C896
PLAUS_TIMERS = 0x4D700
PLAUS_STAGE = 0x4DB22
SET_SPEED_LATCH = 0x32614
CTRL_LAW = 0x2D638


def f32(bus, a):
    return struct.unpack(">f", struct.pack(">I", bus.read32(a) & 0xFFFFFFFF))[0]


def wf(bus, a, v):
    bus.write32(a, struct.unpack(">I", struct.pack(">f", v))[0])


def u8(bus, a):
    return bus.read8(a) & 0xFF


def main():
    with open(ROM_PATH, "rb") as f:
        rom = f.read()
    print(f"ROM 60E15120_N3J1E.bin, config byte ROM[0x7d07f] = 0x{rom[0x7d07f]:02x}")

    prof, bus, cpu = emu.build(PROFILE)
    print("boot:", emu.run(prof, bus, cpu, 300000))
    ui.apply_sensor(bus, prof, "rpm", 3000)
    ui.apply_sensor(bus, prof, "maf", 30.0)
    ui.apply_sensor(bus, prof, "coolant_temp", 90)
    ui.apply_sensor(bus, prof, "iat", 25)
    emu.run(prof, bus, cpu, 100000)

    print("\n== 1) 0xffffcf1c producer: 0x4de1c = float(gear 0xffffbc3d) on this ROM ==")
    for gear in range(7):
        bus.write8(BC3D, gear)
        for i in range(6):
            bus.write8(CF47 + i, 0)
        harness.call(bus, cpu, BAND_PRODUCER)
        base = f32(bus, CF1C)
        bus.write8(CF47 + 2, 1)  # press switch code 3 -> cf49
        harness.call(bus, cpu, BAND_PRODUCER)
        with_sw = f32(bus, CF1C)
        bus.write8(CF47 + 2, 0)
        print(f"  gear={gear}: cf1c={base}  (with switch flag cf49=1: {with_sw} -> "
              f"{'switch map DISABLED by ROM[0x7d07f]=0' if base == with_sw else 'OVERRIDE ACTIVE'})")

    print("\n== 1b) gear chain 0x2c324 (rpm/vss ratio) -> 0x2c3b2 (latch) ==")
    bus.write8(B534, 1)   # AT mode select
    bus.write8(B53A, 0)   # not neutral
    wf(bus, BBB4, 80.0)   # 80 km/h
    wf(bus, B548, 80.0 * 71.9)   # ratio 71.9 rpm per km/h -> between 71.887 and 110.741 -> gear 2
    harness.call(bus, cpu, GEAR_CAND)
    cand = u8(bus, BC3C)
    for _ in range(20):
        harness.call(bus, cpu, GEAR_LATCH)
    print(f"  vss=80 km/h, rpm=5752 (ratio 71.9) -> candidate bc3c={cand}, latched bc3d={u8(bus, BC3D)} (expect 2)")
    bus.write8(B53A, 1)   # neutral
    harness.call(bus, cpu, GEAR_LATCH)
    print(f"  neutral flag b53a=1 -> bc3d={u8(bus, BC3D)} (expect 0)")
    bus.write8(B53A, 0)

    print("\n== 2) 0xffffbcf8 is a percent output, compared against TP% 0xffffa9b4 ==")
    bus.write8(BCED, 1)
    wf(bus, A9B4, 80.0)   # TP1 at 80%
    wf(bus, BCF8, 50.0)
    harness.call(bus, cpu, ENABLE_FLAG)
    r1 = u8(bus, CF34)
    wf(bus, BCF8, 90.0)
    harness.call(bus, cpu, ENABLE_FLAG)
    r2 = u8(bus, CF34)
    print(f"  0x4c896: bcf8=50 < a9b4=80 -> cf34={r1} (expect 0, pedal override); "
          f"bcf8=90 > a9b4=80 -> cf34={r2} (expect 1)")
    bus.write8(CC9B, 0); bus.write8(CC9C, 0); bus.write8(A914, 0)
    wf(bus, A9B4, 30.0); wf(bus, BCF8, 70.0); wf(bus, C028, 100.0)
    wf(bus, A9D0, 0.0); wf(bus, A9D4, 0.0)
    harness.call(bus, cpu, TP_PCT)
    print(f"  0x193c4: TP%=30, bcf8=70, limiter c028=100 -> a9bc={f32(bus, A9BC):.2f} "
          f"(expect 70: max(TP%, cruise output) in the same percent domain)")

    print("\n== 3) set speed in km/h lives in learned cell 0xffff866c (0x32614) ==")
    bus.write8(BD49, 0)   # cap 200 km/h
    bus.write8(0xFFFFBCE9, 0); bus.write8(0xFFFFBFC4, 0)
    bus.write8(0xFFFFBFB4, 1)  # "latch current speed" path
    for vss in (80.0, 250.0, 10.0):
        wf(bus, BFA0, vss)
        wf(bus, BFA4, 0.0)
        wf(bus, C866C, 0.0)
        harness.call(bus, cpu, SET_SPEED_LATCH)
        print(f"  vss={vss:6.1f} km/h -> 866c={f32(bus, C866C):7.3f} km/h, target bfa4={f32(bus, BFA4):7.3f}")

    print("\n== 4) 0xffffa9b4 tracks AN4 (TP1) as percent via the ADC hardware path ==")
    for tp in (0, 25, 50, 75, 100):
        ui.apply_sensor(bus, prof, "throttle", tp)
        harness.call(bus, cpu, ADC_SWEEP)   # ADDR4H -> 0xffff9eec
        harness.call(bus, cpu, TP_RAW_MAP)  # 0x94f0
        harness.call(bus, cpu, TP_FILTER)   # 0x18f44 -> 0x18f60
        harness.call(bus, cpu, TP_DELTA)    # 0x1933a
        harness.call(bus, cpu, TP_PCT)      # 0x193c4
        print(f"  throttle={tp:3d}%  AN4raw={bus.read16(A9EEC) & 0xFFFF:6d}  "
              f"a108={f32(bus, A108):8.4f}  a9b4={f32(bus, A9B4):8.3f}%")

    print("\n== 5) plausibility timers 0x4d700 / stage 0x4db22 still behave ==")
    bus.write8(CF34, 1)
    wf(bus, 0xFFFFCEF4, 5.0)   # filtered error
    wf(bus, 0xFFFFCEFC, 1.0); wf(bus, 0xFFFFCF04, 1.0)
    wf(bus, 0xFFFFCF0C, 1.0); wf(bus, 0xFFFFCF14, 1.0)
    wf(bus, BBB4, 100.0)
    for i in range(6):
        bus.write8(CF47 + i, 0)
    bus.write8(0xFFFFCF50, 0); bus.write8(0xFFFFCF53, 0)
    bus.write8(0xFFFFCF56, 0); bus.write8(0xFFFFCF59, 0)
    harness.call(bus, cpu, PLAUS_TIMERS)
    print(f"  after 0x4d700 with cf34=1, error=5: cf51..cf5b="
          f"{[u8(bus, 0xFFFFCF51 + i) for i in range(0, 11, 2)]} (timers armed at 0x3e when error > max+1.5)")
    harness.call(bus, cpu, PLAUS_STAGE)
    print(f"  after 0x4db22: cf35..cf38={[u8(bus, 0xFFFFCF35 + i) for i in range(4)]}")

    print("\n== 6) control-law output 0x2d638 (bd00) uses gear band + speed error ==")
    bus.write8(BCED, 1); bus.write8(0xFFFFBD3E, 1)
    wf(bus, BFA0, 100.0); wf(bus, BFA4, 90.0)   # error +10 km/h
    wf(bus, CF1C, 3.0)                          # gear 3 band
    wf(bus, BCF8, 50.0); wf(bus, A9B4, 20.0)
    bus.write8(0xFFFFBBc8, 0xfd); bus.write8(0xFFFFBBC9, 0xfd)
    harness.call(bus, cpu, CTRL_LAW)
    print(f"  0x2d638: vss=100, target=90, band=3 -> bd00={f32(bus, BD00):.4f} "
          f"(clamp [-100,100] percent-domain control output)")


if __name__ == "__main__":
    main()
