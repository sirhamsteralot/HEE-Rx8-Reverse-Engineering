#!/usr/bin/env python3
"""Append reviewed DSC-related CAN arbitration aliases to the curated TSVs (idempotent).

Runs after review_e2ram_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the inherited ref_updateDSCRelatedCANStuff__ 0x2a2ae
batch (CAN 0x212 signal processing from task[10]), the 0x212 RX main/unpack
chain and the DSC mode/torque/wheelspeed helpers. Also writes
metadata/dsc_can_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_dsc_can'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("0002a2ae", "dsc_can_arbitration_batch", "high",
     "15-call batch (14 jsr + 1 tail jmp; 13 signal callees + mask/SR helpers) under interrupt mask 0x10, called from task[10] body 0x11744 (callgraph 0x11744 -> 0x2a2ae). Pool words in classified pool 0x2a3e0-0x2a4f4 read from ROM: 0x2a448=0x3920 sh_raise_interrupt_mask_return_previous, 0x2a454=0x3934 ref_setSR (tail), 0x2a468=0x2b314, 0x2a46c=0x2b3b8, 0x2a470=0x2b496, 0x2a474=0x2b6a4, 0x2a478=0x2b6c2, 0x2a47c=0x2b754, 0x2a480=0x2b788, 0x2a484=0x2b7a6, 0x2a488=0x2b7c4, 0x2a48c=0x2b046, 0x2a490=0x2b156, 0x2a494=0x2b17e, 0x2a498=0x2b1aa. Inherited ref_updateDSCRelatedCANStuff__ confirmed: CAN 0x212 signal validity, max-torque-allowed, DSC mode bits, vehicle-moving and wheelspeed validity."),
    ("0002b29c", "can212_rx_main", "high",
     "CAN 0x212 RX handler: can_rx_copy_mailbox_to_buffer(&DAT_0004e21c) (mailbox descriptor at ROM 0x4e21c: bytes 00000212 01210700 ffffbbc0 01000000 = ID 0x212, ctrl 0x07 = DLC 7, buffer 0xffffbbc0); on success calls 0xe038, 0x2b7e2 (unpack), 0x2b816 (0xffffbbc8 = 0xffffbbf2), 0x2b8f4 and resets 0xffffbbee/0xffffbbf0; on failure counts 0xffffbbee (every 4th -> 0xffffbbf0) and 0xffffbbc7. 8 calls total."),
    ("0002b7e2", "can212_rx_unpack", "high",
     "Unpacks CAN 0x212 payload buffer 0xffffbbc0-0xffffbbc6 into working cells: 0xffffbbf2=bbc0, bbf3=bbc1, bbf4=bbc2, bbf5=bbc3, 0xffffbbde = bbc4*0x100+bbc5 (u16), 0xffffbbf6=bbc6 (mode byte). Called from 0x2b29c."),
    ("0002b816", "can212_torque_extract", "medium", "0xffffbbc8 = 0xffffbbf2 (torque-related signal from the 0x212 payload); called from 0x2b29c."),
    ("0002b314", "can212_rx_signal_validity", "high",
     "Validity timers for three 0x212 signals: when 0xffffbbf2/bbf3/bbf4 != -1 reload counters 0xffffbbe8/bbea/bbec = 0x1f, else count down; a signal is stale when its counter reaches 0. Called from 0x2a2ae via pool 0x2a468."),
    ("0002b3b8", "engine_max_torque_allowed_calc", "high",
     "0xffffbbd8 = clamp((0xffffbb20 * decode_u8_affine(0x3ec99326, 0, 0xffffbbc8)/100.0 - 0xffffbcb8) - 0xffffbcbc, 0, 512.0); 512.0 (failsafe) when engine running and validity/fault flags clear, else decode of the 0x212 torque byte. Read by 0x17f20 and 0x1815c dsc_timing_derate_select (pool 0x1827c at 0x18188). Called from 0x2a2ae via pool 0x2a46c."),
    ("0002b496", "dsc_desired_torque_calc", "medium",
     "0xffffbbe0 = 0xffffbca0 - ((bb20 * decode(bbc9))/100 - bcb8 - bcbc); filter 0xffffbbf8 = first_order_filter(decode(bbc9), bbf8, 0.25, 0.19685039) -> 0xffffbbf7 = encode_u8_affine_saturate(bbf8); 0xffffbbc9 = -2 when engine stopped, 0xfe = 0xfe when validity/fault flags. Called from 0x2a2ae via pool 0x2a470."),
    ("0002b6a4", "dsc_mode_bit08_check", "medium",
     "0xffffbbcf = ((0xffffbbde & 8) == 8). Called from 0x2a2ae via pool 0x2a474."),
    ("0002b6c2", "dsc_mode_bit80_check", "medium",
     "0xffffbbcb = 1 when (0xffffbbf6 & 0x80) == 0x80 && engine running. Called from 0x2a2ae via pool 0x2a478."),
    ("0002b754", "dsc_mode_bit40_check", "medium",
     "0xffffbbcc = 1 when (0xffffbbf6 & 0x40) == 0x40 && engine running. Pool 0x2a47c."),
    ("0002b788", "dsc_mode_bit20_check", "medium",
     "0xffffbbcd = ((0xffffbbf6 & 0x20) == 0x20). Pool 0x2a480."),
    ("0002b7a6", "dsc_mode_bit10_check", "medium",
     "0xffffbbce = ((0xffffbbf6 & 0x10) == 0x10). Pool 0x2a484."),
    ("0002b7c4", "can212_timeout_flag", "medium",
     "0xffffbbd0 = (0x1e < 0xffffbbf0) — 0x212 RX timeout flag from the failure counter. Pool 0x2a488."),
    ("0002b046", "wheelspeed_rear_avg_calc", "medium",
     "Averages the two rear wheelspeed signals from CAN (0xffffbbac/0xffffbbae, written by 0x2b1d6 from payload bytes bba4-bba7): decode_u16_affine(0x3c23d70a, 0xc2c80000, x) each, mean, re-encode saturate; 0xffff (invalid) handling when either is -1 or 0xffffbbbc < 6 or 0xffffc61e set. Pool 0x2a48c."),
    ("0002b156", "vehicle_moving_calc", "high",
     "0xffffbbb8 = 1 when vehicle_speed 0xffffbbb4 <= 4.0 (clears only at >= 5.0) — vehicle-not-moving flag; read by 0x165d6 (pool 0x166ee at 0x16626) in the idle A/C gate. Pool 0x2a490."),
    ("0002b17e", "wheelspeed_lr_validity", "high",
     "0xffffbbb9 = 1 when 0xffffbbac == -1 (invalid) or 0xffffbbbe > 0x1e (stale). Pool 0x2a494."),
    ("0002b1aa", "wheelspeed_rr_validity", "high",
     "0xffffbbba = 1 when 0xffffbbae == -1 or 0xffffbbbe > 0x1e. Pool 0x2a498."),
    ("0002b1d6", "can4b0_wheelspeed_extract", "medium",
     "0xffffbbac = bba4*0x100 + bba5; 0xffffbbae = bba6*0x100 + bba7 (two u16 wheelspeed signals from a CAN payload buffer at 0xffffbba4)."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffbbf6", "dsc_mode_byte", "uint8", "0002b6c2",
     "DSC/ABS mode byte from CAN 0x212 payload byte 6 (via 0x2b7e2: bbf6 = bbc6); bits 0x80/0x40/0x20/0x10 checked by 0x2b6c2/0x2b754/0x2b788/0x2b7a6 -> 0xffffbbcb-ce."),
    ("ffffbbac", "wheelspeed_lr_raw", "uint16", "0002b046",
     "Raw LR wheelspeed from CAN payload (0x2b1d6: bba4*0x100+bba5); validity flag 0xffffbbb9 by 0x2b17e; averaged in 0x2b046."),
    ("ffffbbae", "wheelspeed_rr_raw", "uint16", "0002b046",
     "Raw RR wheelspeed (0x2b1d6: bba6*0x100+bba7); validity flag 0xffffbbba by 0x2b1aa; averaged in 0x2b046."),
    ("ffffbbd8", "engine_max_torque_allowed", "float", "0001815c",
     "Max engine torque allowed for DSC, computed by 0x2b3b8 (clamp(..., 0, 512)); consumed by dsc_timing_derate_select 0x1815c (pool 0x1827c at 0x18188) and 0x17f20."),
    ("ffffbbb8", "vehicle_not_moving", "uint8", "000165d6",
     "Set by 0x2b156 when vspeed <= 4 km/h (hyst 5); read in the idle A/C clutch gate 0x165d6 (pool 0x166ee at 0x16626)."),
    ("ffffbbb9", "wheelspeed_lr_invalid", "uint8", "0002b17e",
     "LR wheelspeed invalid/stale flag from 0x2b17e (0xffffbbac == -1 || 0xffffbbbe > 0x1e)."),
    ("ffffbbba", "wheelspeed_rr_invalid", "uint8", "0002b1aa",
     "RR wheelspeed invalid/stale flag from 0x2b1aa (0xffffbbae == -1 || 0xffffbbbe > 0x1e)."),
    ("ffffbbf0", "can212_timeout_counter", "uint16", "0002b29c",
     "0x212 RX failure counter incremented in 0x2b29c on mailbox-copy failure (every 4th failure); 0xffffbbd0 = (0x1e < bbf0) timeout flag by 0x2b7c4."),
    ("ffffbbde", "can212_status_word", "uint16", "0002b6a4",
     "u16 from CAN 0x212 payload bytes 4-5 (0x2b7e2: bbc4*0x100+bbc5); bit 0x08 checked by 0x2b6a4 -> 0xffffbbcf."),
    ("ffffbbc8", "can212_torque_signal", "uint8", "0002b816",
     "Torque-related signal from CAN 0x212 (0x2b816: bbc8 = bbf2); decoded with affine step 0x3ec99326 in 0x2b3b8/0x2b496 for the max-torque-allowed calc."),
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
        'pass': 'dsc_can_labeling',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: dsc_can_arbitration_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/dsc_can_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
