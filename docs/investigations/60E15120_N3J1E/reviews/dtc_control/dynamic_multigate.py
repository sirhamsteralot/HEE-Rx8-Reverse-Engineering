import sys
sys.path.insert(0, r'C:\Users\SirHamsterAlot\source\repos\HEE-Rx8-Reverse-Engineering\utilities\scripts\emu')
import emu, harness
REPO = r'C:\Users\SirHamsterAlot\source\repos\HEE-Rx8-Reverse-Engineering'
prof, bus, cpu = emu.build(REPO + r'\utilities\scripts\emu\profiles\60E15120_N3J1E.json')
emu.run(prof, bus, cpu, 300000)
def r8(a): return bus.read8(a)
def r16(a): return bus.read16(a)
harness.call(bus, cpu, 0x5FD6C, max_steps=300000)
bus.write8(0xFFFFD1C5, 0)
# plant a STORED DTC on slot 0x74 (C073): stock enable1[0x74]=0, enable2[0x74]=1 (asymmetric)
bus.write16(0xFFFF87B0 + 16, 0x74)
bus.write8(0xFFFF87B6 + 0x10, 0x80)
bus.write8(0xFFFFD570 + 0x74, 1)
bus.write8(0xFFFFD5FC + 0x74, 0x70)
print('stock cal bytes for slot 0x74 (C073): enable1=%d enable2=%d enable3=%#x' % (r8(0x7e678+0x74), r8(0x7e704+0x74), r8(0x7e790+0x74)))
for filt, name in [(0, 'no cal filter (PID 0x0200 count path)'), (1, 'filter=enable1 #1 (MIL/aging gate)'), (2, 'filter=enable2 #2 (Mode 03 stored list)')]:
    r0, _, _ = harness.call(bus, cpu, 0x61450, r_args=(0x80, filt), max_steps=100000)
    r0l, _, _ = harness.call(bus, cpu, 0x615C6, r_args=(0x80, filt, 0xFFFFE900), max_steps=200000)
    slots = [r16(0xFFFFE900 + 2*i) for i in range(r0l & 0xffff)]
    print(f'0x61450(0x80, filt={filt}) [{name}]: count={r0 & 0xffff} slots={[hex(s) for s in slots]}')
harness.call(bus, cpu, 0x5A130, max_steps=100000)
print('MIL flag (0x5a130, uses filter=enable1) with stored C073: %d  -> enable1=0 suppresses MIL' % r8(0xFFFFD286))
a, _, _ = harness.call(bus, cpu, 0x5FAB2, max_steps=100000)
b, _, _ = harness.call(bus, cpu, 0x5FB08, max_steps=100000)
print('PID 0x0200 count (filter 0): %d ; PID 0x0202 count (RAM flags): %d -> raw counts ignore cal enables' % (a & 0xffff, b & 0xffff))
BUF = 0xFFFFE900; OUT = 0xFFFFEA00
r0, _, _ = harness.call(bus, cpu, 0x615C6, r_args=(0x80, 2, BUF), max_steps=200000)
n = r0 & 0xffff
r0, _, _ = harness.call(bus, cpu, 0x667C8, r_args=(3, OUT, BUF, n), max_steps=200000)
print('Mode-03-style list (filter=enable2): count=%d codes=%s -> enable2=1 still REPORTS C073 in mode 03' % (r0 & 0xff, [f'{r16(OUT+2*i):04X}' for i in range(r0 & 0xff)]))
r0, _, _ = harness.call(bus, cpu, 0x618F8, r_args=(0x74, 0x80), max_steps=100000)
print('0x618f8 report-class for stored C073: %d (3=both on, 4=enable1 off, 5=enable2 off)' % (r0 & 0xff))
