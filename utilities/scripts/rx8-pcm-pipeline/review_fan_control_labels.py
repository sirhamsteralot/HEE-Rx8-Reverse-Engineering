#!/usr/bin/env python3
"""Append reviewed cooling-fan-control aliases to the curated TSVs (idempotent).

Runs after review_alternator_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the inherited ref_initFanControl 0x2f188 /
ref_setFanOutputGPIO 0x2f1dc pair, the fan task wrapper 0x2f266, the low/high
speed decision bodies 0x2f51a/0x2f65c and the fan diag overrides 0x5c724/0x5c648.
Fan outputs: PEDR_W 0xfffff754 bit 0x800 (PE11, pkg pin 21) and bit 0x10
(PE4, pkg pin 12). Also writes metadata/fan_control_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_fan_control'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("0002f266", "fan_control_task", "high",
     "Mask-0x10 fan task: pool 0x2f29c=0x2f51a, 0x2f2a0=0x2f65c, 0x2f2a4=0x2f1dc (words read from ROM; jsr at 0x2f276/0x2f27c/0x2f282); called from 0x117ac via pool 0x11a04 (load at 0x11826). Runs low-speed decision, high-speed decision, then the GPIO output."),
    ("0002f51a", "fan_low_speed_decision", "high",
     "Low-speed (fan 1) command 0xffffbda1: coolant hysteresis 94/97 C -> 0xffffbdaa/0xffffbdab; bda1 = 1 when (bdaa || (bdab && 0xffffb0cd)) || (engine stopped 0xffffaa68==0 && 0xffffbda0 && !0xffffccc6 && !0xffffa8ea && !0xffffbf8d) || (0xffffbd68 || 0xffffbd6a), gated by fault flags 0xffffd040/0xffffd0a8/0xffffd264/0xffffd269/0xffffd263. Reads bda1 via pool 0x2f63a at 0x2f58a."),
    ("0002f65c", "fan_high_speed_decision", "high",
     "High-speed (fan 2) command 0xffffbda2: coolant 98/101 C -> 0xffffbdac; load 0xffffc6ac 1.84/1.94 -> 0xffffbdb2; coolant 77/80 C -> 0xffffbdb3; vspeed 8/10 km/h -> 0xffffbdb4; bda2 = 1 when bda1==1 && counter 0xffffbda8 > 0x5c && (bdac || (bd68 && A/C switch bdb8) || (engine stopped && bda0 && !ccc6 && !a8ea && !bf8d) || bd6a || (bdb2==0 && bdb3 && !bdb4)) || 0xffffc5e6 || (d264 && !d269), gated by d263; bda8 counts up while bda1 (saturating u16)."),
    ("0002f1dc", "fan_output_gpio", "high",
     "Fan relay GPIO output: PEDR_W 0xfffff754 bit 0x800 (PE11, SH7055F pkg pin 21) from 0x5c724(0xffffbda1) and bit 0x10 (PE4, pkg pin 12) from 0x5c648(0xffffbda2), each via ref_setRegister_REG_BIT_VAL 0x4bbc under mask 0xe0 (ref_setSR_PARAM 0x2054). Pool words: 0x2f240=0xf754, 0x2f242=0x800, 0x2f244=0xbda1, 0x2f246=0x10, 0x2f248=0xbda2, 0x2f24c=0x2054, 0x2f250=0x4bbc, 0x2f254=0x2064, 0x2f258=0x5c724, 0x2f25c=0x5c648. PEDR_W at symbols.tsv 0xfffff754. Harness terminals: cooling fan relay 5X/5AD (pinout v3)."),
    ("0002f188", "fan_output_gpio_init", "high",
     "Same two PEDR_W 0xfffff754 bits (0x800 PE11 / 0x10 PE4) written directly from 0xffffbda1/0xffffbda2 without diag arbitration (pool 0x2f240-0x2f25c shared with 0x2f1dc, jsr @r13 = 0x4bbc at 0x2f1aa); reached via thunk 0x2f260 from the init fan-out 0x1102a (callgraph 0x1102a -> 0x2f260). Inherited ref_initFanControl name confirmed as init-time output writer."),
    ("0002f260", "fan_init_thunk", "medium", "4-byte thunk to 0x2f188; called from init fan-out 0x1102a."),
    ("0005c724", "fan1_diag_override", "medium",
     "UDS actuator-test arbitration for fan 1: DID 0x17c3 (mask 0xc0 on 0xffffd36c, state 0xffffd319/0xffffd323, output cell 0xffffd345); result feeds 0x2f1dc's PE11 write."),
    ("0005c648", "fan2_diag_override", "medium",
     "UDS actuator-test arbitration for fan 2: DID 0x17c4; result feeds 0x2f1dc's PE4 write."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffbda1", "fan_low_speed_cmd", "uint8", "0002f1dc",
     "Fan 1 (low-speed relay) command computed by 0x2f51a (coolant 94/97 C hysteresis, engine-off/APV/SSV and A/C conditions, DTC gates); written to PEDR_W 0xfffff754 bit 0x800 (PE11) by 0x2f188/0x2f1dc via diag override 0x5c724."),
    ("ffffbda2", "fan_high_speed_cmd", "uint8", "0002f1dc",
     "Fan 2 (high-speed relay) command computed by 0x2f65c (needs bda1 && counter bda8 > 0x5c plus coolant 98/101 C / load / vspeed / A/C conditions); written to PEDR_W bit 0x10 (PE4) by 0x2f188/0x2f1dc via diag override 0x5c648."),
    ("ffffbda8", "fan_low_speed_timer", "uint16", "0002f65c",
     "Saturating counter (rx8_add_u16_saturate) incremented while 0xffffbda1==1, cleared otherwise (0x2f65c); high-speed fan 2 requires bda8 > 0x5c (92 counts)."),
]

LOOKUP = []


def read_rows(path, fields):
    """Return list of dicts; rows keep their raw line in '_raw' for byte-exact rewrite."""
    if not path.exists():
        return []
    with path.open(newline='', encoding='utf-8', errors='surrogateescape') as f:
        text = f.read()
    lines = text.split('\n')
    rows = []
    rdr = csv.DictReader(lines, delimiter='\t')
    for raw, row in zip(lines[1:], rdr):
        if raw == '' and all(v in (None, '') for v in row.values()):
            continue
        row = {k: (v if v is not None else '') for k, v in row.items()}
        row['_raw'] = raw
        rows.append(row)
    return rows


def write_rows(path, fields, rows):
    """Rewrite preserving original lines byte-exactly; only appended rows are new."""
    with path.open('w', newline='', encoding='utf-8', errors='surrogateescape') as f:
        f.write('\t'.join(fields) + '\n')
        for r in rows:
            raw = r.get('_raw')
            if raw is not None:
                f.write(raw + '\n')
            else:
                f.write('\t'.join(r.get(k, '') for k in fields) + '\n')


def main():
    index = {r['address'] for r in read_rows(b / 'decompiled/function_index.tsv',
                                             ['address', 'name', 'body_bytes', 'status', 'file'])}
    for a, alias, conf, ev in FUNCTIONS:
        assert a in index, 'function %s not in index' % a
    for a, alias, typ, reader, ev in RAM:
        assert list((b / 'decompiled/functions').glob(reader + '_*')), 'reader %s has no function file' % reader

    added_fn = added_ram = added_lut = 0
    conflicts = []

    p = b / 'source_review/accepted_function_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'confidence', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, conf, ev in FUNCTIONS:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('function %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev, '_raw': None})
        added_fn += 1
    if not conflicts and added_fn:
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    p = b / 'source_review/accepted_ram_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, typ, reader, ev in RAM:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('ram %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'type': typ, 'reader': reader, 'evidence': ev, '_raw': None})
        added_ram += 1
    if not conflicts and added_ram:
        write_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'], rows)

    p = b / 'source_review/accepted_lookup_aliases.tsv'
    fields = ['original', 'alias', 'basis', 'evidence']
    rows = read_rows(p, fields)
    pairs = {(r['original'], r['alias']) for r in rows}
    for orig, alias, ev in LOOKUP:
        if (orig, alias) in pairs:
            continue
        rows.append({'original': orig, 'alias': alias, 'basis': BASIS, 'evidence': ev, '_raw': None})
        added_lut += 1
    if not conflicts and added_lut:
        write_rows(p, fields, rows)

    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')

    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text()) if vp.exists() else {
        'date': '', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    if BASIS not in val.get('sources', []):
        val.setdefault('sources', []).append(BASIS)
    vp.write_text(json.dumps(val, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    record = {
        'date': '',
        'pass': 'fan_control_labeling',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: cooling_fan_control_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'rom_unchanged': True,
        'ghidra_database_updated': False,
        'pin_sources': 'Sh7055h.pdf (SH7055F HW manual ADE 602-155B) Table 1.3: PE4=pin 12, PE11=pin 21; PEDR_W 0xfffff754 from symbols.tsv; harness terminals 5X/5AD from hardware pinout v3; chip-pin->terminal routing unresolved (board)',
    }
    (b / 'metadata/fan_control_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
