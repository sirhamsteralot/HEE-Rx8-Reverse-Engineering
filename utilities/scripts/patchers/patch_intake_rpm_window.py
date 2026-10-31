#!/usr/bin/env python3
"""Patcher: RPM-window control for the RX-8 (Series 1) intake valves (VDI / SSV),
with RomRaider-editable setpoints.

Patches a stock PCM ROM so the selected valve solenoid is energised only inside
an RPM window, e.g. --actuator vdi --open-rpm 7000 --close-rpm 8500:
valve OPEN when open_rpm <= engine_speed_rpm (0xffffb548) <= close_rpm.
The UDS diagnostic actuator override is preserved.

The two setpoints are written into the calibration area as a proper 2-cell
2D table (descriptor + axis + data at a verified-free address, default
0x7fb90/0x7fb9c/0x7fba4 — a 0xFF run present in all stock ROMs), so they can be
edited afterwards with RomRaider (see the emitted .xml fragment) or any binary
editor at the reported storageaddress. The patched code reads the cells
directly from that address. Use --pool-floats to instead embed the setpoints in
the function's literal pool (not RomRaider-visible).

IMMUTABILITY RULE (workspace AGENTS.md): stock ROMs are never modified. This
tool READS an input .bin and WRITES a NEW output file; the input is opened
read-only and its SHA-256 is asserted unchanged after the run, and the output
is asserted to differ only inside the located function's patched span plus the
calibration block.

Location across ROMs: the target function is found by an exact byte match of
its body in the reference ROM 60E15120_N3J1E (unique in all 10 stock ROMs;
ROM-internal pool pointers are relocated by the found delta).

Encodings (SH-2E BE) verified against
reverse_engineered/60E15120_N3J1E/decompiled/firmware_disassembly.asm.

Usage:
  python3 patch_intake_rpm_window.py Stock_ROMs/60E15120_N3J1E.bin --actuator vdi --open-rpm 7000 --close-rpm 8500 --out patched/
  python3 patch_intake_rpm_window.py Stock_ROMs/ --actuator vdi          # every *.bin
  options: --actuator vdi|ssv, --open-rpm, --close-rpm, --cal-base 0xADDR,
           --pool-floats, --out DIR, --dry-run, --report report.json
"""
import argparse, hashlib, json, struct, sys
from pathlib import Path

REF_ROM = Path(__file__).resolve().parents[1] / 'Stock_ROMs' / '60E15120_N3J1E.bin'

ACTUATORS = {
    'vdi': (0x34844, 126, 'PD5 / PDDR_W 0xfffff746 bit 0x20 (pkg pin 254, terminal 1W)'),
    'ssv': (0x2178c, 250, 'PE7 / PEDR_W 0xfffff754 bit 0x80 (pkg pin 16, terminal 1L)'),
}

# calibration block layout (all 4-aligned): descriptor(12B) + axis(2 floats) + data(2 floats)
CAL_DESC, CAL_AXIS, CAL_DATA = 0x7fb90, 0x7fb9c, 0x7fba4
CAL_SPAN = (CAL_DESC, CAL_DATA + 8)

NOP = 0x0009
F32_TYPE = 0  # descriptor type code for float32 tables (MAF Scaling 0x69788 uses 0)


def movl_pc(n, ea, addr):
    d = ea - addr - 4
    assert 0 <= d <= 255 * 4 and d % 4 == 0 and addr % 4 == 0, (hex(ea), hex(addr))
    return 0xd000 | (n << 8) | (d // 4)


def movw_pc(n, ea, addr):
    d = ea - addr - 4
    assert 0 <= d <= 255 * 2 and d % 2 == 0
    return 0x9000 | (n << 8) | (d // 2)


def fmov_s(m, n):
    return 0xf000 | (n << 8) | (m << 4) | 0x8


def fcmp_gt(a, b):
    return 0xf000 | (b << 8) | (a << 4) | 5


def bts(disp):
    assert 0 <= disp <= 255
    return 0x8d00 | disp


def bra(disp):
    assert 0 <= disp <= 0xfff
    return 0xa000 | disp


def build_vdi(base, data_addr):
    """VDI cal-mode: region rel [0x08,0x2e); tail (diag override + PD5 write) kept.
    Pool: rel 0x88 = absolute address of the 2-cell data block (cal area)."""
    P_DATA = 0x88
    ON, OFF, END = 0x20, 0x26, 0x2e
    code = {
        0x08: movw_pc(3, base + 0x7e, base + 0x08),      # r3 = 0xffffb548 (rpm; pool u16 @rel 0x7e kept)
        0x0a: fmov_s(3, 4),                               # fr4 = rpm
        0x0c: movl_pc(0, base + P_DATA, base + 0x0c),     # r0 = data block addr
        0x0e: fmov_s(0, 7),                               # fr7 = cell0 = open_rpm
        0x10: 0x7004,                                     # add #4,r0
        0x12: fmov_s(0, 6),                               # fr6 = cell1 = close_rpm
        0x14: fcmp_gt(6, 4),                              # T = rpm > close
        0x16: bts((OFF - 0x16 - 4) // 2),                 # bt/s OFF
        0x18: NOP,
        0x1a: fcmp_gt(4, 7),                              # T = open > rpm
        0x1c: bts((OFF - 0x1c - 4) // 2),                 # bt/s OFF
        0x1e: NOP,
        ON:   0xe401,                                     # mov #1,r4 (open)
        0x22: bra((END - 0x22 - 4) // 2),
        0x24: NOP,
        OFF:  0xe400,                                     # mov #0,r4 (closed)
        0x28: bra((END - 0x28 - 4) // 2),
    }
    region = {off: code.get(off, NOP) for off in range(0x08, END, 2)}
    pool = {P_DATA: data_addr}
    return region, pool


def build_ssv(base, data_addr):
    """SSV cal-mode: region rel [0x10,0xa2); prologue + tail (diag override + PE7
    write) kept. Pool: rel 0xfc = 0xffffb548, rel 0x108 = data block addr,
    rel 0x124 = &becd (shared-pool ptr, relocated by delta)."""
    P_RPM, P_DATA, P_BECD = 0xfc, 0x108, 0x124
    ON, OFF, END = 0x34, 0x3c, 0xa2
    delta = base - ACTUATORS['ssv'][0]
    code = {
        0x10: movl_pc(3, base + P_BECD, base + 0x10),    # r3 = &becd (diag override flag)
        0x12: 0x6030,                                     # mov.b @r3,r0
        0x14: 0x600c,                                     # extu.b r0,r0
        0x16: 0x8801,                                     # cmp/eq #1,r0
        0x18: bts((ON - 0x18 - 4) // 2),                  # bt/s ON (becd==1 -> open)
        0x1a: NOP,
        0x1c: movl_pc(2, base + P_RPM, base + 0x1c),      # r2 = 0xffffb548
        0x1e: fmov_s(2, 4),                               # fr4 = rpm
        0x20: movl_pc(0, base + P_DATA, base + 0x20),     # r0 = data block addr
        0x22: fmov_s(0, 7),                               # fr7 = cell0 = open_rpm
        0x24: 0x7004,                                     # add #4,r0
        0x26: fmov_s(0, 6),                               # fr6 = cell1 = close_rpm
        0x28: fcmp_gt(6, 4),                              # T = rpm > close
        0x2a: bts((OFF - 0x2a - 4) // 2),                 # bt/s OFF
        0x2c: NOP,
        0x2e: fcmp_gt(4, 7),                              # T = open > rpm
        0x30: bts((OFF - 0x30 - 4) // 2),                 # bt/s OFF
        0x32: NOP,
        ON:   0xe401,                                     # mov #1,r4 (open)
        0x36: bra((END - 0x36 - 4) // 2),
        0x38: NOP,
        OFF:  0xe400,                                     # mov #0,r4 (closed)
    }
    region = {off: code.get(off, NOP) for off in range(0x10, END, 2)}
    pool = {P_RPM: 0xffffb548, P_DATA: data_addr, P_BECD: 0x72730 + delta}
    return region, pool


BUILDERS = {'vdi': build_vdi, 'ssv': build_ssv}


def find_free_cal(rom, prefer=(CAL_DESC, CAL_AXIS, CAL_DATA)):
    """Return (desc, axis, data) addresses in a verified all-0xFF cal-area run."""
    d, a, t = prefer
    if all(b == 0xff for b in rom[d:t + 8]) and 0x6c000 <= d and t + 8 <= 0x80000:
        return d, a, t
    i = 0x6c000
    while i < len(rom) - 48:
        if rom[i] == 0xff:
            j = i
            while j < len(rom) and rom[j] == 0xff:
                j += 1
            if j - i >= 48:
                d = i + (0 - i) % 4
                return d, d + 0xc, d + 0x14
            i = j
        else:
            i += 1
    raise SystemExit('no free >=48B cal-area run found')


def cal_block(open_rpm, close_rpm, desc, axis, data):
    """Bytes for descriptor + axis + data. 2D descriptor: >HBBII (n, typ, _, axis, data)."""
    f = lambda v: struct.pack('>f', v)
    out = {}
    out[desc] = struct.pack('>HBBII', 2, F32_TYPE, 0, axis, data)
    out[axis] = f(0.0) + f(1.0)
    out[data] = f(float(open_rpm)) + f(float(close_rpm))
    return out


XML_BASE = '''        <table name="{name}" category="Intake Valves" type="2D" storagetype="float" endian="big" sizey="2">
            <scaling units="RPM" expression="x" to_byte="x" format="0" />
            <table name="Index (0 = open rpm, 1 = close rpm)" type="Y Axis" storagetype="float" endian="big" expression="x" to_byte="x" />
        </table>'''

XML_ROM = '''        <table name="{name}" storageaddress="0x{data:06X}">
            <table type="Y Axis" storageaddress="0x{axis:06X}" />
        </table>'''


def patch_rom(in_path, actuator, open_rpm, close_rpm, out_dir=None, dry_run=False, cal_base=None):
    in_path = Path(in_path)
    ref_off, body_len, gpio = ACTUATORS[actuator]
    ref = REF_ROM.read_bytes()
    pat = ref[ref_off:ref_off + body_len]
    data = in_path.read_bytes()
    sha_in = hashlib.sha256(data).hexdigest()
    hits, pos = [], data.find(pat)
    while pos >= 0:
        if data[pos:pos + body_len] == pat:
            hits.append(pos)
        pos = data.find(pat, pos + 1)
    if len(hits) != 1:
        return {'rom': in_path.name, 'actuator': actuator, 'status': 'SKIP',
                'reason': f'unique body match failed ({len(hits)} hits)'}
    base = hits[0]
    desc, axis, cdata = (cal_base, cal_base + 0xc, cal_base + 0x14) if cal_base else find_free_cal(data)
    region, pool = BUILDERS[actuator](base, cdata)
    out = bytearray(data)
    old = {}
    for off, w in sorted(region.items()):
        a = base + off
        old[f'{a:#x}'] = f'{struct.unpack(">H", out[a:a+2])[0]:04x}'
        out[a:a+2] = struct.pack('>H', w)
    for off, v in sorted(pool.items()):
        a = base + off
        old[f'{a:#x}'] = f'{struct.unpack(">I", out[a:a+4])[0]:08x}'
        out[a:a+4] = struct.pack('>I', v)
    for a, blob in cal_block(open_rpm, close_rpm, desc, axis, cdata).items():
        assert all(b == 0xff for b in out[a:a+len(blob)]), f'cal area not free at {a:#x}'
        old[f'{a:#x}'] = 'ff' * len(blob)
        out[a:a+len(blob)] = blob
    # checks
    assert hashlib.sha256(in_path.read_bytes()).hexdigest() == sha_in, 'input modified!'
    allowed = {base + off + k for off in region for k in (0, 1)}
    allowed |= {base + off + k for off in pool for k in (0, 1, 2, 3)}
    allowed |= {a + k for a in cal_block(open_rpm, close_rpm, desc, axis, cdata) for k in range(len(cal_block(open_rpm, close_rpm, desc, axis, cdata)[a]))}
    diff = [i for i in range(len(data)) if data[i] != out[i]]
    assert all(i in allowed for i in diff), 'diff outside patched spans'
    for off, w in region.items():
        assert struct.unpack('>H', out[base + off:base + off + 2])[0] == w
    # verify the cal descriptor parses like correlate_rx8defs.py expects (2D >HBBII)
    n, typ, _b, ax, dp = struct.unpack_from('>HBBII', out, desc)
    assert (n, typ, ax, dp) == (2, F32_TYPE, axis, cdata)
    assert struct.unpack('>f', out[cdata:cdata+4])[0] == float(open_rpm)
    assert struct.unpack('>f', out[cdata+4:cdata+8])[0] == float(close_rpm)
    name = f'{actuator.upper()} RPM Window (open/close)'
    xml = XML_BASE.format(name=name) + '\n' + XML_ROM.format(name=name, data=cdata, axis=axis)
    result = {'rom': in_path.name, 'actuator': actuator, 'status': 'OK', 'gpio': gpio,
              'input_sha256': sha_in, 'func_offset': f'{base:#x}',
              'open_rpm': open_rpm, 'close_rpm': close_rpm,
              'cal': {'descriptor': f'{desc:#x}', 'axis': f'{axis:#x}', 'data_storageaddress': f'{cdata:#x}'},
              'bytes_changed': len(diff), 'old_words': old,
              'romraider_xml': xml}
    if not dry_run:
        out_dir = Path(out_dir) if out_dir else in_path.parent
        out_dir.mkdir(parents=True, exist_ok=True)
        out_path = out_dir / f'{in_path.stem}_{actuator}_{open_rpm}_{close_rpm}.bin'
        out_path.write_bytes(bytes(out))
        out_path.with_suffix('.xml').write_text(
            f'<!-- Add to rx8_defs.xml: the base <table> block in the base rom, and the rom-specific\n'
            f'     storageaddress entry inside each <rom> you flash. Data cells (float32, RPM):\n'
            f'     cell0=open at 0x{cdata:06X}, cell1=close at 0x{cdata+4:06X}. Edit with RomRaider or any hex editor. -->\n'
            + xml + '\n')
        result['output'] = str(out_path)
        result['output_sha256'] = hashlib.sha256(bytes(out)).hexdigest()
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('inputs', nargs='+')
    ap.add_argument('--actuator', choices=sorted(ACTUATORS), default='vdi')
    ap.add_argument('--open-rpm', type=int, default=7000)
    ap.add_argument('--close-rpm', type=int, default=8500)
    ap.add_argument('--cal-base', type=lambda x: int(x, 0), default=None,
                    help='descriptor address for the cal block (default: auto free run, 0x7fb90 in stock ROMs)')
    ap.add_argument('--out', default=None)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--report', default=None)
    args = ap.parse_args()
    assert 0 < args.open_rpm < args.close_rpm < 12000
    files = []
    for i in args.inputs:
        p = Path(i)
        files.extend(sorted(p.glob('*.bin')) if p.is_dir() else [p])
    results = [patch_rom(f, args.actuator, args.open_rpm, args.close_rpm, args.out, args.dry_run, args.cal_base)
               for f in files]
    for r in results:
        print(json.dumps({k: r[k] for k in ('rom', 'actuator', 'status', 'func_offset', 'output') if k in r}))
    if args.report:
        Path(args.report).write_text(json.dumps(
            {'actuator': args.actuator, 'open_rpm': args.open_rpm, 'close_rpm': args.close_rpm,
             'results': results}, indent=2) + '\n')
    sys.exit(1 if any(r['status'] != 'OK' for r in results) else 0)


if __name__ == '__main__':
    main()
