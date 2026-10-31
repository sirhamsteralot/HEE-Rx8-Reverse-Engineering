"""Direct ROM-function call harness for dynamic validation.

Sets up a stack in RAM, loads argument registers (SH-2E ABI: integer args
r4-r7, float args fr4-fr7, return in r0 / fr0), points PR at a sentinel, and
runs until the function's rts reaches the sentinel. Lets us execute the ROM's
own functions in the emulator and compare against static findings / the
reimplementation — the Phase 1 "dynamic reproduction" item.

RAM globals the callee reads are set explicitly via `ram` (documented per
test); sensor *inputs* still enter through the hardware paths (ADC/ATU/CAN
registers) where the test says so.
"""
import struct

SENTINEL = 0xFFFFFFF0  # in IO space; never executed (we stop when PC reaches it)
STACK = 0xFFFF7000


def f32(x):
    return struct.unpack("<f", struct.pack("<f", x))[0]


def bits(x):
    return struct.unpack("<I", struct.pack("<f", x))[0]


def call(bus, cpu, addr, r_args=(), fr_args=(), ram=None, max_steps=200000, stop_at=()):
    """Call ROM function at `addr`. r_args -> r4.., fr_args -> fr4..
    ram: {addr: (size, value)} written before the call.
    stop_at: extra PCs that count as "returned" (e.g. the idle loop 0x3dac,
    which the task dispatcher jumps to instead of returning).
    Returns (r0, fr0, steps)."""
    for a, (size, v) in (ram or {}).items():
        if size == 1:
            bus.write8(a, v)
        elif size == 2:
            bus.write16(a, v)
        else:
            bus.write32(a, v)
    cpu.r[15] = STACK
    cpu.pr = SENTINEL
    cpu.pc = addr & 0xFFFFFFFF
    for i, v in enumerate(r_args):
        cpu.r[4 + i] = v & 0xFFFFFFFF
    for i, v in enumerate(fr_args):
        cpu.fr[4 + i] = f32(float(v))  # FR registers are 32-bit single precision
    stops = (SENTINEL,) + tuple(stop_at)
    steps = 0
    while cpu.pc not in stops and steps < max_steps:
        bus.pc = cpu.pc
        cpu.step()
        bus.tick(1)
        steps += 1
    if cpu.pc not in stops:
        raise RuntimeError(f"call to 0x{addr:08x} did not return within {max_steps} steps (pc=0x{cpu.pc:08x})")
    return cpu.r[0], cpu.fr[0], steps
