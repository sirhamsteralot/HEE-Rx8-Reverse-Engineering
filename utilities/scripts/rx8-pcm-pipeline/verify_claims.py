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
  5. pool word value assignments ("0x2a448=0x3920", "0x5cb64 = f32 0.25"):
     the claimed word inside a classified pool must hold the claimed value
     in the ROM (u32 at 4-aligned addresses, u16 at 2-aligned, f32 for
     float literals).
  6. "N callees" claims: resolved call targets of the named batch function,
     excluding the mask/SR helpers 0x3920/0x3934, must number N.
  7. quoted ROM byte strings (backticked hex near "ROM 0x..", "at ROM 0x..:
     bytes ..", "at 0x.. read from ROM (..)"): the bytes at that ROM address
     must equal the quoted string exactly.
  8. mailbox descriptor field claims ("ID 0x212, DLC 7, buffer 0xffffbbc0"):
     the 16-byte record at the cited ROM address must have that id, ctrl
     byte r[6] (= DLC) and buffer pointer; descriptor tables (header with
     Descriptor+Type+Axis+Data columns) are re-parsed (>HBBII) and the
     1-D rows' Axis/Data cells must contain the descriptor's axis/data
     addresses.

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

# --- claim classes 5-8 (see module docstring) ---
word_assign = re.compile(r'(?<![\w/])0x([0-9a-f]{4,6})\s*=\s*(?:f32\s+)?(0x[0-9a-f]+|\d+\.\d+f?)(?![0-9a-f])')
callee_claim = re.compile(r'\b(\d+) callees\b')
desc_claim = re.compile(r'[Ii][Dd] 0x([0-9a-f]+),\s*(?:mailbox (\d+),\s*)?(?:ctrl 0x([0-9a-f]+)|DLC (\d+))(?:\s*=\s*DLC (\d+))?,\s*buffer (0xffff[0-9a-f]+)')
hex_backtick = re.compile(r'`((?:[0-9a-f]{2,8}[ ])+[0-9a-f]{2,8})`')
hex_bytes_kw = re.compile(r'\bat ROM (0x[0-9a-f]{4,6}): bytes ((?:[0-9a-f]{4,8}[ ]?)+)')
hex_readfrom = re.compile(r'\bat (0x[0-9a-f]{4,6}) read from ROM \(([0-9a-f ]+)\)')
rom_at = re.compile(r'\bROM (0x[0-9a-f]{4,6})')
MASK_SR = {0x3920, 0x3934}  # sh_raise_interrupt_mask_return_previous / ref_setSR: batch plumbing, not signal callees


def in_pool(a):
    return any(ps <= a <= pe for ps, pe, _c in pool_ranges)


def scan_text(src, text):
    """Text-level checks needing multi-line/table context: quoted ROM byte
    strings (class 7) and descriptor Axis/Data table rows (class 8)."""
    lines = text.splitlines()
    for i, line in enumerate(lines):
        for m in hex_backtick.finditer(line):
            hexs = m.group(1).replace(' ', '')
            if len(hexs) < 8 or len(hexs) % 2:
                continue
            prefix = '\n'.join(lines[max(0, i - 2):i]) + '\n' + line[:m.start()]
            rm = list(rom_at.finditer(prefix))
            if not rm:
                continue
            a = int(rm[-1].group(1), 16)
            if a >= 0x80000 or a + len(hexs) // 2 > len(ROM):
                continue
            s = stats['reports'].setdefault(src, {})
            s['hex_strings'] = s.get('hex_strings', 0) + 1
            if ROM[a:a + len(hexs) // 2].hex() != hexs:
                failures.append(f'{src}: quoted bytes at ROM 0x{a:x} are {ROM[a:a + len(hexs) // 2].hex()} but the claim says {hexs}')
        for m in hex_bytes_kw.finditer(line):  # address is inside the match: "at ROM 0x..: bytes .."
            a = int(m.group(1), 16)
            hexs = m.group(2).replace(' ', '')
            if a >= 0x80000 or len(hexs) < 8 or len(hexs) % 2 or a + len(hexs) // 2 > len(ROM):
                continue
            s = stats['reports'].setdefault(src, {})
            s['hex_strings'] = s.get('hex_strings', 0) + 1
            if ROM[a:a + len(hexs) // 2].hex() != hexs:
                failures.append(f'{src}: quoted bytes at ROM 0x{a:x} are {ROM[a:a + len(hexs) // 2].hex()} but the claim says {hexs}')
        for m in hex_readfrom.finditer(line):
            a = int(m.group(1), 16)
            hexs = m.group(2).replace(' ', '')
            if a >= 0x80000 or len(hexs) < 8 or len(hexs) % 2 or a + len(hexs) // 2 > len(ROM):
                continue
            s = stats['reports'].setdefault(src, {})
            s['hex_strings'] = s.get('hex_strings', 0) + 1
            if ROM[a:a + len(hexs) // 2].hex() != hexs:
                failures.append(f'{src}: quoted bytes at ROM 0x{a:x} are {ROM[a:a + len(hexs) // 2].hex()} but the claim says {hexs}')
    # descriptor tables: header row with Descriptor+Type+Axis+Data columns; check 1-D rows (Type 4/8)
    i = 0
    while i < len(lines):
        if lines[i].startswith('|') and 'Descriptor' in lines[i]:
            header = [c.strip() for c in lines[i].strip('|').split('|')]
            if 'Type' in header and any(c.startswith('Axis') for c in header) and any(c.startswith('Data') for c in header):
                ti = header.index('Type')
                ai = next(j for j, c in enumerate(header) if c.startswith('Axis'))
                di = next(j for j, c in enumerate(header) if c.startswith('Data'))
                j = i + 2
                while j < len(lines) and lines[j].startswith('|'):
                    cells = [c.strip() for c in lines[j].strip('|').split('|')]
                    if len(cells) > max(ti, ai, di) and cells[0] and not set(cells[0]) <= set('-: ') and cells[ti] in ('4', '8'):
                        for da in re.findall(r'0x([0-9a-f]{6})', cells[0]):
                            a = int(da, 16)
                            if a + 12 > len(ROM):
                                continue
                            _n, _u, _t, axis, data = struct.unpack('>HBBII', ROM[a:a + 12])
                            ax_cell = cells[ai]
                            d_cell = cells[di]
                            s = stats['reports'].setdefault(src, {})
                            s['desc_rows'] = s.get('desc_rows', 0) + 1
                            if axis < 0x80000 and re.search(r'0x[0-9a-f]', ax_cell) and f'0x{axis:x}' not in ax_cell.lower():
                                failures.append(f'{src}: descriptor 0x{a:x} axis 0x{axis:x} missing from Axis cell {ax_cell!r} (row {cells[0]!r})')
                            if data < 0x80000 and re.search(r'0x[0-9a-f]', d_cell) and f'0x{data:x}' not in d_cell.lower():
                                failures.append(f'{src}: descriptor 0x{a:x} data 0x{data:x} missing from Data cell {d_cell!r} (row {cells[0]!r})')
                    j += 1
                i = j
                continue
        i += 1



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
            raw = m.group(0)
            if not any(a >= ps and z <= pe for ps, pe, _c in pool_ranges):
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
    # class 5: pool word value assignments (ROM pool words only)
    for m in word_assign.finditer(line):
        a = int(m.group(1), 16)
        v = m.group(2)
        if a >= 0x80000 or not in_pool(a):
            continue
        s['word_assigns'] = s.get('word_assigns', 0) + 1
        if v.startswith('0x'):
            vv = int(v, 16)
            ok = (a % 4 == 0 and struct.unpack('>I', ROM[a:a + 4])[0] == vv) or \
                 (a % 2 == 0 and struct.unpack('>H', ROM[a:a + 2])[0] == vv)
        else:
            fv = float(v.rstrip('f'))
            ok = a % 4 == 0 and abs(struct.unpack('>f', ROM[a:a + 4])[0] - fv) <= max(abs(fv) * 1e-6, 1e-9)
        if not ok:
            failures.append(f'{src}: claimed pool word 0x{a:x} = {v} but the ROM word there differs')
    # class 6: "N callees" (batch callees excluding mask/SR helpers)
    for m in callee_claim.finditer(line):
        claimed = int(m.group(1))
        before = fn_addr.findall(line[:m.start()])
        cand = next((x for x in reversed(before) if x in index), fn_hint)
        if cand is None or cand not in index:
            continue
        s['callee_claims'] = s.get('callee_claims', 0) + 1
        n = len([t for t in fn_calls.get(int(cand, 16), {}).get('targets', []) if t not in MASK_SR])
        if n != claimed:
            failures.append(f'{src}: 0x{cand} claimed {claimed} callees but the disassembly resolves {n} (excl. mask/SR helpers)')
    # class 8a: mailbox descriptor field claims on one line
    for m in desc_claim.finditer(line):
        claimed_id = int(m.group(1), 16)
        cands = [int(x, 16) for x in re.findall(r'0x([0-9a-f]{5,6})', line[:m.start()]) if int(x, 16) < 0x80000]
        if not cands:
            continue
        s['desc_claims'] = s.get('desc_claims', 0) + 1
        base = [a for a in cands if a + 12 <= len(ROM) and struct.unpack('>I', ROM[a:a + 4])[0] == claimed_id]
        if not base:
            failures.append(f'{src}: claimed mailbox ID 0x{claimed_id:x} but no cited ROM address holds a record with that id')
            continue
        a = base[-1]
        ctrl = ROM[a + 6]
        buf = struct.unpack('>I', ROM[a + 8:a + 12])[0]
        mb = ROM[a + 5] & 0xf
        dlc = int(m.group(3), 16) if m.group(3) else int(m.group(4) or m.group(5) or 0)
        if ctrl != dlc or buf != int(m.group(6), 16) or (m.group(2) is not None and mb != int(m.group(2))):
            failures.append(f'{src}: descriptor record at 0x{a:x} is ctrl 0x{ctrl:02x} (DLC {ctrl}) buffer 0x{buf:08x}; claim said DLC {dlc} buffer {m.group(6)}')


SOURCES = [(rep, (REPORTS_DIR / rep).read_bytes().decode('utf-8', errors='surrogateescape')) for rep in REPORTS]
for extra in [INV / 'README.md'] + sorted(INV.glob('reviews/*/README.md')):
    name = extra.name if extra.parent == INV else f'reviews/{extra.parent.name}/README.md'
    SOURCES.append((name, extra.read_bytes().decode('utf-8', errors='surrogateescape')))
for src, text in SOURCES:
    for line in text.splitlines():
        scan_line(src, line)
    scan_text(src, text)

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
