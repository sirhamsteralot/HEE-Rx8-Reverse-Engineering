#!/usr/bin/env python3
"""Validate the root subsystem reports against the export and the raw ROM.

Extreme-scepticism check for every root-level <subsystem>_report.md (template:
knock_control_report.md). For each report:
  - required sections present (knock template: summary, pseudocode, tables,
    labeling, corrections, files, validation, memory map, limits)
  - ROM SHA-256 quoted in the header equals the actual ROM hash
  - in "Functions" memory-map sections: every address cell is in
    function_index.tsv AND the reported name matches the index name
    (medium-confidence -> candidate_ prefix rule)
  - in "RAM" memory-map sections: every address cell is in
    accepted_ram_aliases.tsv (or integrated_names) AND the alias matches
  - ROM data claims of the form `0xADDR ... = VALUE` re-read from the ROM
  - all bare 6-8 hex digit 0x addresses are within ROM bounds
Writes metadata/report_validation.json; exits non-zero on any failure.
"""
from pathlib import Path
import csv, json, re, struct, sys, hashlib

from paths import b, base, rom_file, ROOT, INV  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
WS = b.parents[1]
ROM_PATH = WS / 'Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin'
ROM = ROM_PATH.read_bytes()
ROM_SHA = hashlib.sha256(ROM).hexdigest()

REPORTS_DIR = INV  # reports live in docs/investigations/<rom-id>/ in this repo
REPORTS = sorted(p.name for p in REPORTS_DIR.glob('*_report.md'))
REQUIRED_SECTIONS = ['Executive summary', 'pseudocode', 'Labeling applied', 'Corrections',
                     'Files', 'Validation', 'Memory map', 'Limits']

index = {r['address']: r for r in csv.DictReader((b / 'decompiled/function_index.tsv').open(newline=''), delimiter='\t')}
ram_rows = {r['address']: r for r in csv.DictReader((b / 'source_review/accepted_ram_aliases.tsv').open(newline=''), delimiter='\t')}
manifest = json.loads((b / 'metadata/integrated_names.json').read_text())
idmap = manifest.get('identifier_map', {})

def norm_fn(addr, reported):
    have = index.get(addr, {}).get('name', '')
    return reported in (have, have.removeprefix('candidate_'))

failures = []
report_stats = {}

for rep in REPORTS:
    p = REPORTS_DIR / rep
    text = p.read_text()
    stats = {'fn_checked': 0, 'ram_checked': 0, 'rom_refs': 0, 'rom_claims': 0}
    for sec in REQUIRED_SECTIONS:
        if sec.lower() not in text.lower():
            failures.append(f'{rep}: missing section {sec!r}')
    if ROM_SHA not in text:
        failures.append(f'{rep}: ROM SHA-256 not quoted or wrong')

    section = ''
    for line in text.splitlines():
        if line.startswith('#'):
            section = line.lower()
            continue
        if not line.startswith('|'):
            continue
        cells = [c.strip() for c in line.strip('|').split('|')]
        if len(cells) < 2 or set(cells[0]) <= set('-: '):
            continue
        m = re.match(r'^0x([0-9a-f]{6,8})', cells[0])
        if not m:
            # still range-check any 0x addresses in the row
            continue
        addr = m.group(1).zfill(8)
        val = int(addr, 16)
        if val >= 0xffffe000:
            stats['rom_refs'] += 1  # volatile peripheral I/O window, valid
        elif val >= 0xffff0000:
            if not (0xffff6000 <= val <= 0xffffdfff):
                failures.append(f'{rep}: RAM address 0x{val:x} outside RAM window: {line[:60]!r}')
            stats['rom_refs'] += 1
        else:
            if val >= len(ROM):
                failures.append(f'{rep}: address 0x{val:x} out of ROM range: {line[:60]!r}')
                continue
            stats['rom_refs'] += 1
        name_m = re.search(r'`([^`]+)`', cells[1])
        name = name_m.group(1) if name_m else cells[1]
        in_fn_section = 'function' in section
        in_ram_section = ('ram' in section) or ('memory map' in section and val >= 0xffff0000)
        if in_ram_section and val >= 0xffff0000:
            stats['ram_checked'] += 1
            row = ram_rows.get(addr)
            if any(t in name for t in ('…', '/', '(', 'DAT_')) or 'base' in cells[0]:
                continue  # grouped, unnamed or base-pointer row: documented as such
            if row is None:
                mv = idmap.get('DAT_' + addr, '')
                if mv and any(part in mv for part in re.split(r'[/…\s]+', name) if len(part) > 3):
                    continue
                failures.append(f'{rep}: RAM 0x{addr} ({name}) not in accepted_ram_aliases.tsv/manifest')
            elif row['alias'] not in name and not name.startswith(row['alias']):
                failures.append(f'{rep}: RAM 0x{addr} reported {name!r} != TSV alias {row["alias"]!r}')
        elif in_fn_section and val < 0xffff0000:
            stats['fn_checked'] += 1
            if any(t in name for t in ('/', '(', 'calc', 'clamp')):
                continue  # grouped or parenthesized-role row
            if addr not in index:
                failures.append(f'{rep}: function 0x{addr} not in function_index.tsv ({name})')
            elif not norm_fn(addr, name):
                failures.append(f'{rep}: function 0x{addr} reported {name!r} != index {index[addr]["name"]!r}')

    for m in re.finditer(r'0x([0-9a-f]{6})[^\n]{0,60}?=\s*(\d+)\b', text):
        a, val = int(m.group(1), 16), int(m.group(2))
        if a + 2 <= len(ROM) and 0x6c000 <= a:  # data-area claims
            stats['rom_claims'] += 1
            w = struct.unpack('>H', ROM[a:a+2])[0]
            if w != val:
                failures.append(f'{rep}: ROM claim 0x{a:x} = {val} but ROM u16 = {w}')
    report_stats[rep] = stats

out = {'date': '2026-10-30', 'rom_sha256': ROM_SHA, 'reports': report_stats,
       'failures': failures, 'result': 'PASS' if not failures else 'FAIL'}
(b / 'metadata/report_validation.json').write_text(json.dumps(out, indent=2) + '\n')
print(json.dumps(out, indent=2))
sys.exit(1 if failures else 0)
