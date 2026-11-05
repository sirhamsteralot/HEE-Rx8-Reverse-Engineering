#!/usr/bin/env python3
"""Verify machine-checkable prose claims in reports and label TSVs against the
export, the disassembly and the raw ROM.

Added after the C-item-7 self-review (PR #30) caught four hand-written
evidence mistakes: a wrong peripheral register letter (DCNT8E vs DCNT8G), a
wrong batch call count (24 vs 26), a loose literal-pool range, and a callee
misclassified from call-site shape / a wrong discrepancy-ID citation (the
latter two are covered by the write-time rule in AGENTS.md rule 7, not by
this script). The mechanical checks:

  1. "N-call batch" / "(N calls" claims: recount jsr/bsr instructions in the
     named function's disassembly range and compare. The function is the
     0x-address nearest before the claim on the line (report table rows start
     with the task entry, the batch address is later), falling back to the
     TSV row's own address for accepted_function_aliases.tsv evidence.
  2. peripheral register name<->address pairs ("DCNT8G 0xfffff64c", including
     grouped "GR1G/H 0xfffff450/0xfffff452" forms): the address must exist in
     symbols.tsv and the claimed name must be one of its accepted short forms.
  3. "pool (0xA-0xB, ...)" / "pool 0xA-0xB" claims: each range must lie inside
     a classified literal-pool range (non_instruction_ranges_classified.tsv),
     and all resolved jsr/bsr targets of the function named on the line (or
     the TSV row address) must be words inside the range.
  4. labels-pass records vs accepted_*_aliases.tsv: every function_aliases /
     ram_aliases entry in data/labels/<rom-id>/*.json must have a TSV row for
     the same address (recorded-but-not-applied is a failure; later alias
     refinement is a note, not a failure).

Scans docs/investigations/<rom-id>/*_report.md and the evidence column of
source_review/accepted_function_aliases.tsv.

Writes metadata/claim_validation.json; exits non-zero on any failure.
Run from the repo root: python utilities/scripts/rx8-pcm-pipeline/verify_claims.py
"""
from pathlib import Path
import csv, json, re, struct, sys

from paths import b, rom_file, ROOT, INV, DEC, DISASM, LABELS

ROM = rom_file().read_bytes()

REPORTS_DIR = INV
REPORTS = sorted(p.name for p in REPORTS_DIR.glob('*_report.md'))

index = {r['address']: r for r in csv.DictReader((b / 'decompiled/function_index.tsv').open(newline='', encoding='utf-8', errors='surrogateescape'), delimiter='\t')}
fn_bounds = sorted((int(a, 16), int(a, 16) + int(r['body_bytes'])) for a, r in index.items())

symbols = {}
for r in csv.DictReader((b / 'decompiled/symbols.tsv').open(newline='', encoding='utf-8', errors='surrogateescape'), delimiter='\t'):
    if r['address'].startswith('fffff'):
        symbols['0x' + r['address']] = r['name']


def reg_keys(symbol):
    """All acceptable short forms of a symbols.tsv name:
    ATUII_TSTR3_B -> {ATUII_TSTR3_B, TSTR3}, ADDR6H_B -> {ADDR6H_B, ADDR6H, ADC6}."""
    keys = {symbol}
    s = re.sub(r'^(?:ATUII?|HCAN|SCI|WDT|SYSC)_', '', symbol)
    keys.add(s)
    keys.add(re.sub(r'_[BWL]$', '', s))
    keys.add(re.sub(r'^ADDR(\d+)[HL]$', r'ADC\1', re.sub(r'_[BWL]$', '', s)))
    return keys


POOL_CLASSES = {'mixed_pool', 'u32_table', 'ptr_pool_code', 'ptr_pool_ram',
                'word_literal_pool', 'float_pool'}
pool_ranges = []
for r in csv.DictReader((DISASM / 'non_instruction_ranges_classified.tsv').open(newline='', encoding='utf-8', errors='surrogateescape'), delimiter='\t'):
    if r['class'] in POOL_CLASSES:
        pool_ranges.append((int(r['start'], 16), int(r['end'], 16), r['class']))

# --- parse the disassembly once: per function, call count + resolved targets ---
DISASM_FILE = DISASM / 'firmware_disassembly.asm'
line_re = re.compile(r'^([0-9a-f]{8})  ([0-9a-f]{4})  (.*)$')
movl_re = re.compile(r'mov\.l @\(0x([0-9a-f]+),pc\),r(\d+)')
jsr_re = re.compile(r'jsr @r(\d+)')
bsr_re = re.compile(r'bsr 0x([0-9a-f]+)')
jmp_re = re.compile(r'jmp @r(\d+)')
TASKEND = 0x3D58  # ref_taskEndRoutine_: the yield, not a batch call

fn_calls = {}  # addr -> {'count': int, 'targets': [int]}
cur_fn = None
pending = {}
for line in DISASM_FILE.open(errors='surrogateescape'):
    m = line_re.match(line)
    if not m:
        continue
    addr = int(m.group(1), 16)
    mn = m.group(3)
    while fn_bounds and addr >= fn_bounds[0][1]:
        fn_bounds.pop(0)
    if fn_bounds and addr >= fn_bounds[0][0] and fn_bounds[0][0] != cur_fn:
        cur_fn = fn_bounds[0][0]
        fn_calls.setdefault(cur_fn, {'count': 0, 'targets': []})
        pending = {}
    if cur_fn is None:
        continue
    e = fn_calls[cur_fn]
    mm = movl_re.search(mn)
    if mm:
        pending[int(mm.group(2))] = int(mm.group(1), 16)
        continue
    jm = jsr_re.search(mn)
    if jm:
        e['count'] += 1
        reg = int(jm.group(1))
        if reg in pending and pending[reg] + 4 <= len(ROM):
            e['targets'].append(struct.unpack('>I', ROM[pending[reg]:pending[reg] + 4])[0])
        continue
    bm = bsr_re.search(mn)
    if bm:
        e['count'] += 1
        e['targets'].append(int(bm.group(1), 16))
        continue
    gm = jmp_re.search(mn)
    if gm:  # tail call: last batch call is a jmp, not jsr; taskEnd yield excluded
        reg = int(gm.group(1))
        if reg in pending and pending[reg] + 4 <= len(ROM):
            t = struct.unpack('>I', ROM[pending[reg]:pending[reg] + 4])[0]
            if t != TASKEND:
                e['count'] += 1
                e['targets'].append(t)

failures = []
notes = []
stats = {'reports': {}, 'tsv_rows': 0, 'labels_json_checked': 0}

NAME_SKIP = {'ATU', 'ADC', 'CAN', 'PWM', 'RAM', 'ROM', 'IVT', 'VBR', 'WDT', 'UDS',
             'DTC', 'GPIO', 'HCAN', 'SCI', 'E2RAM', 'OS'}
single_pair = re.compile(r'\b([A-Z][A-Z0-9_]{2,})\s*\(?(0xfffff[0-9a-f]{3})\)?')
slash_pair = re.compile(r'\b([A-Z][A-Z0-9_]{2,})/([A-Z][A-Z0-9_]*)\s*\(?(0xfffff[0-9a-f]{3})\s*/\s*(0xfffff[0-9a-f]{3})\)?')
call_claim = re.compile(r'\b(\d+)-call batch\b|\((\d+) calls?\b')
range_pair = re.compile(r'0x([0-9a-f]{4,6})[–-](0x[0-9a-f]{4,6})')
pool_list = re.compile(r'pools?\s*\(([^)]*)\)')
pool_direct = re.compile(r'pools?\s+(0x[0-9a-f]{4,6})[–-](0x[0-9a-f]{4,6})')
fn_addr = re.compile(r'0x([0-9a-f]{6})\b')


def reg_match(name, addr):
    sym = symbols.get(addr)
    if sym is None:
        return f'peripheral {addr} claimed as {name} but not in symbols.tsv'
    if name not in reg_keys(sym):
        return f'{name} claimed at {addr} but symbols.tsv says {sym}'
    return None


def scan_line(src, line, fn_hint=None):
    """Run all per-line checks; fn_hint is the TSV row address for TSV evidence."""
    s = stats['reports'].setdefault(src, {'reg_pairs': 0, 'call_claims': 0, 'pool_claims': 0})
    for m in slash_pair.finditer(line):
        name1, name2 = m.group(1), m.group(2)
        # "GR1G/H" means GR1G and GR1H: expand a bare suffix onto the first stem
        full2 = name2 if len(name2) >= 3 else name1[:-len(name2)] + name2
        for name, addr in ((name1, m.group(3)), (full2, m.group(4))):
            if name in NAME_SKIP:
                continue
            s['reg_pairs'] += 1
            err = reg_match(name, addr)
            if err:
                failures.append(f'{src}: {err}')
    for m in single_pair.finditer(line):
        name, addr = m.group(1), m.group(2)
        if name in NAME_SKIP:
            continue
        if slash_pair.search(line[max(0, m.start() - 12):m.end() + 24]):
            continue  # first half of a slash pair, checked above
        s['reg_pairs'] += 1
        err = reg_match(name, addr)
        if err:
            failures.append(f'{src}: {err}')
    # call-count claims: function = nearest 0x-address before the claim, else hint
    for m in call_claim.finditer(line):
        claimed = int(m.group(1) or m.group(2))
        before = fn_addr.findall(line[:m.start()])
        cand = before[-1] if before else fn_hint
        if cand is None or cand not in index:
            continue
        actual = fn_calls.get(int(cand, 16), {'count': 0})['count']
        s['call_claims'] += 1
        if actual != claimed:
            failures.append(f'{src}: 0x{cand} claimed {claimed} calls but disassembly has {actual}')
    # pool claims
    spans = [(mm.group(1), mm.start()) for mm in pool_list.finditer(line)]
    spans += [(mm.group(0), mm.start()) for mm in pool_direct.finditer(line)]
    for span, pos in spans:
        for m in range_pair.finditer(span):
            a, z = int(m.group(1), 16), int(m.group(2), 16)
            if z <= a or a >= 0x80000:
                continue
            s['pool_claims'] += 1
            if z % 4:
                z += 4 - (z % 4)
            raw = m.group(0)
            if not any(a >= ps and z + 3 <= pe for ps, pe, _c in pool_ranges):
                failures.append(f'{src}: claimed pool {raw} not inside a classified pool range')
                continue
            before = fn_addr.findall(line[:pos])
            cand = before[-1] if before else fn_hint
            if cand is None or cand not in index:
                continue
            fc = fn_calls.get(int(cand, 16), {'count': 0, 'targets': []})
            words = {struct.unpack('>I', ROM[i:i + 4])[0] for i in range(a, min(z + 4, len(ROM) - 3), 4)}  # end word included
            for t in fc['targets']:
                if t not in words:
                    failures.append(f'{src}: function 0x{cand} call target 0x{t:x} missing from claimed pool {raw}')


for rep in REPORTS:
    text = (REPORTS_DIR / rep).read_bytes().decode('utf-8', errors='surrogateescape')
    for line in text.splitlines():
        scan_line(rep, line)

# label TSV evidence lines, with the row address as function hint
tsv_path = b / 'source_review/accepted_function_aliases.tsv'
for r in csv.DictReader(tsv_path.open(newline='', encoding='utf-8', errors='surrogateescape'), delimiter='\t'):
    stats['tsv_rows'] += 1
    scan_line('accepted_function_aliases.tsv', f"0x{r['address']} {r['alias']}\t{r['evidence']}", fn_hint=r['address'])

# --- labels-pass JSON <-> accepted TSV consistency ---
fn_tsv = {r['address']: r['alias'] for r in csv.DictReader(tsv_path.open(newline='', encoding='utf-8', errors='surrogateescape'), delimiter='\t')}
ram_tsv = {r['address']: r['alias'] for r in csv.DictReader((b / 'source_review/accepted_ram_aliases.tsv').open(newline='', encoding='utf-8', errors='surrogateescape'), delimiter='\t')}
for jp in sorted(LABELS.glob('*.json')):
    try:
        data = json.loads(jp.read_text(errors='surrogateescape'))
    except Exception:
        continue
    if not isinstance(data, dict) or ('function_aliases' not in data and 'ram_aliases' not in data):
        continue
    stats['labels_json_checked'] += 1
    for addr, entry in data.get('function_aliases', {}).items():
        alias = entry.get('alias') if isinstance(entry, dict) else entry
        row = fn_tsv.get(addr)
        if row is None:
            failures.append(f'{jp.name}: function {addr} alias {alias!r} has no accepted_function_aliases.tsv row (recorded but not applied)')
        elif row != alias:
            notes.append(f'{jp.name}: function {addr} record alias {alias!r} vs TSV {row!r} (later refinement)')
    for addr, entry in data.get('ram_aliases', {}).items():
        alias = entry.get('alias') if isinstance(entry, dict) else entry
        row = ram_tsv.get(addr)
        if row is None:
            failures.append(f'{jp.name}: RAM {addr} alias {alias!r} has no accepted_ram_aliases.tsv row (recorded but not applied)')
        elif row != alias:
            notes.append(f'{jp.name}: RAM {addr} record alias {alias!r} vs TSV {row!r} (later refinement)')

out = {'date': '2026-11-05', 'rom': rom_file().name, 'checks': stats, 'notes': notes,
       'failures': failures, 'result': 'PASS' if not failures else 'FAIL'}
(LABELS / 'claim_validation.json').write_text(json.dumps(out, indent=2) + '\n')

if __name__ == '__main__':
    print(json.dumps(out, indent=2))
    sys.exit(1 if failures else 0)
