import sys
sys.path.insert(0, r'C:\Users\SirHamsterAlot\source\repos\HEE-Rx8-Reverse-Engineering\utilities\scripts\emu')
import emu, harness
REPO = r'C:\Users\SirHamsterAlot\source\repos\HEE-Rx8-Reverse-Engineering'
prof, bus, cpu = emu.build(REPO + r'\utilities\scripts\emu\profiles\60E15120_N3J1E.json')
emu.run(prof, bus, cpu, 300000)
def r8(a): return bus.read8(a)
def r16(a): return bus.read16(a)
def r32(a): return bus.read32(a)
harness.call(bus, cpu, 0x5FD6C, max_steps=300000)  # DTC RAM init, as boot task 0x1102a does
# master 21-entry table: entry i at 0xffff87b0+16i (u16 slot id at +0, state byte at +6);
# entry 0 is skipped by scanners (== DAT_ffff8900 current index) -> use entries 1 and 2
bus.write16(0xFFFF87B0 + 16, 9);  bus.write8(0xFFFF87B6 + 0x10, 0x80)   # slot 9 = P0101 (enable1[9]=1), stored/MIL
bus.write16(0xFFFF87B0 + 32, 8);  bus.write8(0xFFFF87B6 + 0x20, 0x01)   # slot 8 = P0077 (enable1[8]=0), active only
bus.write8(0xFFFFD570 + 9, 1); bus.write8(0xFFFFD5FC + 9, 0x70)
bus.write16(0xFFFFD3C0, 0x0101); bus.write8(0xFFFFD1C5, 0)  # first stored code; clear garbage in diag-force flag
def counts():
    a, _, _ = harness.call(bus, cpu, 0x5FAB2, max_steps=100000)
    b, _, _ = harness.call(bus, cpu, 0x5FB08, max_steps=100000)
    return a & 0xffff, b & 0xffff
print('counts pid0200/pid0202 (expect 1/1):', counts())
BUF = 0xFFFFE900; OUT = 0xFFFFEA00
for mode, name in [(0x80,'stored 0x80'), (0xf0,'active|stored 0xf0'), (0x60,'active 0x60'), (0x70,'0x70'), (0xc0,'0xc0'), (0x00,'inactive 0x00'), (0x50,'0x50')]:
    r0, _, _ = harness.call(bus, cpu, 0x615C6, r_args=(mode, 0, BUF), max_steps=200000)
    count = r0 & 0xffff
    slots = [r16(BUF + 2*i) for i in range(count)]
    r0, _, _ = harness.call(bus, cpu, 0x667C8, r_args=(3, OUT, BUF, count), max_steps=200000)
    n = r0 & 0xff
    print(f'615c6({name}): count={count} slots={[hex(s) for s in slots]} codes={[f"{r16(OUT+2*i):04X}" for i in range(n)]}')
# with filter=1 (enable1 cal gate): slot 8 (P0077, enable1=0) must drop out, slot 9 stays
r0, _, _ = harness.call(bus, cpu, 0x615C6, r_args=(0xf0, 1, BUF), max_steps=200000)
count = r0 & 0xffff
slots = [r16(BUF + 2*i) for i in range(count)]
print(f'615c6(0xf0, filter=enable1): count={count} slots={[hex(s) for s in slots]} (expect only 0x9: P0077 filtered out)')
harness.call(bus, cpu, 0x68B10, r_args=(0, 0x03), max_steps=10000)
bus.write8(0xFFFFDDEC, 0); bus.write16(0xFFFFD95C, 0); bus.write16(0xFFFFD3B4, 0xFFFF); bus.write8(0xFFFFD1E8, 0)
r0, _, _ = harness.call(bus, cpu, 0x65FF8, r_args=(0, 0), max_steps=300000)
print('mode03 handler 0x65ff8(0,0) executed, r0=%x' % r0)
def mode22(pid):
    harness.call(bus, cpu, 0x68B10, r_args=(0, 0x22), max_steps=10000)
    bus.write8(0xFFFFDDEC, 0); bus.write16(0xFFFFD95C, 0)
    bus.write16(0xFFFFD1EA, pid); bus.write8(0xFFFFD1E8, 0); bus.write16(0xFFFFD3B4, 0xFFFF)
    r0, _, _ = harness.call(bus, cpu, 0x5774C, max_steps=200000)
    return r0, bytes(r8(0xFFFFD962 + i) for i in range(max(r0, 0)))
for pid in (0x0200, 0x0202):
    r0, resp = mode22(pid)
    print(f'PID {pid:04x} via dispatcher 0x5774c: r0={r0} resp={resp.hex()} (expect 62 0200 01 / 62 0202 01)')
harness.call(bus, cpu, 0x5A130, max_steps=100000)
print('MIL flag DAT_ffffd286 with stored+enabled DTC present (expect 1):', r8(0xFFFFD286))
harness.call(bus, cpu, 0x5FD6C, max_steps=300000)
print('after init-reset 0x5fd6c counts:', counts())
harness.call(bus, cpu, 0x5A130, max_steps=100000)
print('MIL flag after reset (expect 0):', r8(0xFFFFD286))
