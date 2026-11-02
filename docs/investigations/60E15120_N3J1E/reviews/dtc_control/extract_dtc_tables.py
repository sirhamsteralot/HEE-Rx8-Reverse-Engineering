#!/usr/bin/env python
"""Generate repo artifacts: data/dtc/<rom>.tsv + data/dtc/defs_audit.tsv from ROMs+defs."""
import re, struct, os, json

REPO = r'C:\Users\SirHamsterAlot\source\repos\HEE-Rx8-Reverse-Engineering'
OUT = os.path.join(REPO, 'data', 'dtc')
os.makedirs(OUT, exist_ok=True)
ROMS = {
 '60E0E500':'60E0E500.bin','60E0E700_N3YLEE':'60E0E700_N3YLEE.bin','60E0FB00':'60E0FB00.bin',
 '60E0FC00':'60E0FC00.bin','60E0G500_N3ZHEC':'60E0G500_N3ZHEC.bin','60E15120_N3J1E':'60E15120_N3J1E.bin',
 '60E1B900':'60E1B900.bin','60E1C500_N3J6EB':'60E1C500_N3J6EB.bin','60E1D400':'60E1D400.bin',
 '60E32000_N3M5E':'60E32000_N3M5E.bin','60E32000_N3N5EB':'60E32000_N3N5EB.bin'}
def binpath(r):
    return ('binaries/dumps/%s.bin' % r) if r == '60E0G500_N3ZHEC' else ('submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/%s.bin' % r)
PREFIX = b'\x03\x00\x03\x01\x03\x02\x03\x00'

def find_layout(rom):
    idx = rom.find(PREFIX)
    if idx < 0: return None
    code_start = idx + 6
    s = 0
    while True:
        v = struct.unpack_from('>H', rom, code_start + 2*s)[0]
        if v == 0xffff or v > 0xf3ff: break
        s += 1
        if s > 0x200: return None
    used_end = code_start + 2*s
    p = used_end
    while p + 1 < len(rom) and rom[p] == 0xff and rom[p+1] == 0xff:
        p += 2
    nslots = (p - code_start) // 2
    return code_start, nslots, p

def parse_entries(body):
    return re.findall(r'<table name="(DTC ([0-9A-Fa-f]{4}) Enable/Disable (#\d)(?: \[additional site (0x[0-9a-f]+)\])?)" storageaddress="(0x[0-9A-Fa-f]+)"', body)

audit_rows = []
for romid in ROMS:
    xmlp = os.path.join(REPO, 'data/definitions/romraider/per-rom/%s.xml' % romid)
    rom = open(os.path.join(REPO, binpath(romid)), 'rb').read()
    lay = find_layout(rom)
    if not lay:
        print(romid, 'no layout'); continue
    code_start, nslots, enable_start = lay
    codes = [struct.unpack_from('>H', rom, code_start + 2*i)[0] for i in range(nslots)]
    e1 = enable_start; e2 = enable_start + nslots; e3 = enable_start + 2*nslots
    entries = parse_entries(open(xmlp, encoding='utf-8', errors='replace').read()) if os.path.exists(xmlp) else []
    defmap = {}
    for n, c, s, add, a in entries:
        if s == '#1':
            defmap.setdefault(int(a,16) - e1, c.upper())
    with open(os.path.join(OUT, romid + '.tsv'), 'w') as f:
        f.write('slot\tcode\tenable1\tenable2\tenable3\tdef_1_code_at_slot\tdef_match\tcode_table_addr\tenable1_addr\n')
        for s in range(nslots):
            code = codes[s]
            dc = defmap.get(s)
            f.write('%02x\t%04X\t%02x\t%02x\t%02x\t%s\t%s\t%06x\t%06x\n' % (
                s, code, rom[e1+s], rom[e2+s], rom[e3+s],
                dc if dc else '', 'Y' if (dc and dc == '%04X' % code) else ('N' if dc else ''),
                code_start + 2*s, e1 + s))
    # audit rows per suffix
    for suf, off in (('#1', 0), ('#2', nslots), ('#3', 2*nslots)):
        rows = [(int(a,16), c.upper(), n) for n, c, s, add, a in entries if s == suf]
        mism = oor = 0
        mism_rows = []
        for a, code, name in sorted(rows):
            slot = a - e1 - off
            rc = codes[slot] if 0 <= slot < nslots else None
            if rc is None or code != '%04X' % rc:
                mism += 1
                if len(mism_rows) < 8: mism_rows.append('%s@%#x(slot %s, rom %s)' % (name, a, slot, rc))
            if slot < 0 or slot >= nslots: oor += 1
        audit_rows.append((romid, suf, len(rows), mism, oor, '; '.join(mism_rows)))
    print(romid, 'code@%#x nslots=%d enable1=%#x' % (code_start, nslots, e1))

with open(os.path.join(OUT, 'defs_audit.tsv'), 'w') as f:
    f.write('rom\tsuffix\tdef_entries\tmismatches\tout_of_range\texamples\n')
    for r in audit_rows:
        f.write('\t'.join(str(x) for x in r) + '\n')
print('wrote', OUT)
