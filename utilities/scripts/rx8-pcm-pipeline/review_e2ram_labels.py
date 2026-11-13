#!/usr/bin/env python3
"""Append reviewed E2RAM device-layer aliases to the curated TSVs (idempotent).

Runs after review_fan_control_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the inherited ref_getDataFromE2RAM 0x3599c /
ref_writeToE2RAMArea_INDEX_ADDR_LEN 0x37ea4 parameter layer and the SCI4 device
protocol primitives (0xbdfa/0xbe30/0xbe5e/0xbe8c/0xbfa0/0xc02c/0xbf3a/0xbed8).
Also writes metadata/e2ram_device_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_e2ram_device'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("0003599c", "e2ram_boot_param_read", "high",
     "19 calls to 0x37ef0 (pool 0x35a48) reading indexed params into RAM 0xffffc268-0xffffc282 (dest pools 0x35a48-0x35a88: 0x35a48=0x37ef0, 0x35a4c=0xffffc268, 0x35a50=0xffffc26c, 0x35a54=0xffffc270, ... 0x35a7c=0xffffc27f etc.); indexes 0,2,6,10,0xc,0xd,0xe,0xf,0x10,0x16,0x18,0x12,0x13,0x14,0x1a,0x1b,0x1c,0x1d,0x1e. Called from 0x349e4 (callgraph), itself called from the boot fan-out 0x1102a. Inherited ref_getDataFromE2RAM confirmed as the boot parameter-block read."),
    ("00037ef0", "e2ram_cached_byte_read", "high",
     "Cached indexed byte read: if shadow 0xffffc28e[i] == ~0xffffc38e[i] (pools 0x37f7c/0x37f80) return shadow; else busy-check 0xbed8 (pool 0x37f70), then device read 0xbdfa (pool 0x37f88) at address 0x6000000 + ((i>>1)&0xff)*0x10000 (base pool 0x37f84 = 0x6000000); even index takes the high byte (big-endian u16). Updates shadow data+complement. Under mask 0x10 (pool 0x37f6c=0x3920, tail 0x3934). Returns error flag."),
    ("00037ea4", "e2ram_shadow_byte_write", "high",
     "Indexed shadow write under mask 0x10 (pools 0x37f6c=0x3920, 0x37f8c=0x3934): for len bytes, 0xffffc28e[i] = src byte and 0xffffc38e[i] = ~byte (pools 0x37f7c/0x37f80). Callers: 0x279d8, 0x27d06, 0x35a8c, 0x4b668, 0x5d9d8, 0x5e8a4 (callgraph). Inherited ref_writeToE2RAMArea_INDEX_ADDR_LEN confirmed as the RAM shadow writer (data + complement)."),
    ("00035d36", "e2ram_shadow_byte_write_trampoline", "high",
     "14-byte body (words 4e0b 0009 4f26 6cf6 6df6 000b 6ef6 at 0x35d36, ROM-verified; byte-exact match with 60E0FC00 0x36456): `jsr @r14; nop; lds.l @r15+,pr; mov.l @r15+,r12; mov.l @r15+,r13; rts; mov.l @r15+,r14`. Sole caller 0x35a8c loads r14 exactly once, at 0x35a94 `mov.l @(0x35b74,pc),r14` with pool 0x35b74 = 0x00037ea4 (e2ram_shadow_byte_write), and all 14 dispatch arms `bra 0x35d36`; the epilogue pops the frame 0x35a8c pushed, so this is a tail-call trampoline to 0x37ea4, not an unknown indirect call. Resolved by the thunk audit (review_thunk_audit_labels.py); inherited ref_writeToE2RAMAreaTHUNK_ was a misnomer."),
    ("00035a8c", "e2ram_param_write_dispatch", "medium",
     "Dispatch on param id (0..N) to 0x37ea4 / thunk 0x35d36 with (index, &src cell in 0xffffc268-0xffffc282, len): e.g. id 2 -> (2, 0xffffc26c, 8), id 0xd -> (0x1e, 0xffffc282, 1), id 3 -> (0, 0xffffc268, 1), id 4 -> (0xc/0xe/0x10), id 7 -> (0x16/0x18, 2). 30 calls total; pool 0x35b70-0x35b84. Called from 0x35ea0, 0x360c8, 0x36142, 0x361e4, 0x3665a, 0x36700, 0x3677a, 0x36830, 0x36acc, 0x36c3c, 0x36ed4, 0x3703c, 0x37134, 0x3728c, 0x374be."),
    ("00037cd8", "e2ram_bulk_read_into_shadow", "high",
     "Bulk device->shadow fill (inherited ref_E2IntoRAM_ confirmed): double busy-check 0xbed8 (pool 0x37f70), then for each u16 page p in [start>>1 .. (start+len-1)>>1] read word 0xbdfa(0x6000000 + p*0x10000) (pools 0x37f84/0x37f88) and store high byte at 0xffffc28e[2p], low byte at 0xffffc28f[2p], with complements at 0xffffc38e/0xffffc38f (pools 0x37f7c/0x37f80). Counters 0xffffc492/0xffffc494. Callers: 0x27b8e, 0x35956, 0x4b5b6, 0x5b482."),
    ("000379e4", "e2ram_verify_state_machine", "medium",
     "State machine over 0xffffc49c (states 1-4): busy-check 0xbed8, issue command 0x4c00000 via 0xbe30 (pools 0x37bd4/0x37bd8), then read-back verify with 0xbdfa(0x6000000 + (byte)0xffffc498*0x10000) (pools 0x37be8/0x37bec) comparing against 0xffffc49a; status cells 0xffffc4a0-a6. Called from 0x38082."),
    ("0000bdfa", "e2ram_read_word", "high",
     "Device read of one u16: 0xbf3a() CS/port setup, 0xbfa0(addr, 2) sends the 2 address bytes over SCI4, 0xc02c() clocks in the u16 from SCI_RDR4_B 0xfffff025, then CS down via ref_setRegister_REG_BIT_VAL 0x4bbc on PFDR_W 0xfffff74e bit 0x400 (pools 0xbecc=0x2054, 0xbed4=0x4bbc, 0xbed0=0x2064)."),
    ("0000be30", "e2ram_send_command2", "high",
     "Send a 2-byte command frame: 0xbf3a() CS up, 0xbfa0(cmd, 2), CS down (same helper pools 0xbecc/0xbed4/0xbed0). Used with 0x4c00000 (from 0x379e4, pool 0x37bd4)."),
    ("0000be5e", "e2ram_send_command4_a", "medium",
     "Send a 4-byte frame: 0xbf3a() CS up, 0xbfa0(cmd, 4), CS down. Called from 0x379e4."),
    ("0000be8c", "e2ram_send_command4_b", "medium",
     "Send a 4-byte frame: same shape as 0xbe5e (0xbf3a + 0xbfa0(cmd,4) + CS down)."),
    ("0000bfa0", "sci4_send_bytes", "high",
     "SCI4 byte transmit: SCI_SCR4_B 0xfffff022 |= 0x20 (TE), loop over len bytes: wait SCI_SSR4_B 0xfffff024 bit 0x80 (TDRE), write SCI_TDR4_B 0xfffff023, clear TDRE (SSR4 = b & 0x7f | 0x78); end wait bit 0x4 (TEND), SCR4 &= 0xb. Register names from symbols.tsv."),
    ("0000c02c", "sci4_read_u16", "high",
     "SCI4 receive of 2 bytes assembled into a u16: PLIR_W 0xfffff75c |= 0x200, SCI_SCR4_B |= 0x30 (TE|RE), dummy write SCI_TDR4_B = 0, wait SCI_SSR4_B bit 0x40 (RDRF), read SCI_RDR4_B 0xfffff025, repeat for second byte. Register names from symbols.tsv."),
    ("0000bf3a", "e2ram_cs_port_setup", "high",
     "E2RAM chip-select/port setup: PLIR_W 0xfffff75c &= ~0x200, PBCRH_W 0xfffff732 &= ~0x30, PBDR_W 0xfffff738 bit 0x400 = 0 (via 0x4bbc), PFDR_W 0xfffff74e bit 0x400 = 1 (CS high), PBCRH_W |= 0x10. Registers from symbols.tsv."),
    ("0000bed8", "e2ram_busy_status_read", "high",
     "E2RAM status/busy read: pulse PFDR_W 0xfffff74e bit 0x400 high then low (via 0x4bbc, pools 0xc014-0xc020), wait 0x239c (sh_busy_wait_count_times_8(1)), read PBDR_W 0xfffff738, return (val & 0x800) == 0. PBDR_W at symbols.tsv 0xfffff738."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffc28e", "e2ram_shadow_data", "uint8[256]", "00037ef0",
     "E2RAM byte shadow cache: written by 0x37ea4/0x37ef0/0x37cd8, read back for cached reads (0x37ef0 compares against the complement at 0xffffc38e)."),
    ("ffffc38e", "e2ram_shadow_complement", "uint8[256]", "00037ef0",
     "Complement shadow of 0xffffc28e (0xffffc38e[i] = ~data[i]); match means cache valid, mismatch triggers a device read via 0xbdfa in 0x37ef0."),
    ("ffffc268", "e2ram_param_block", "uint8[32]", "0003599c",
     "Boot parameter block 0xffffc268-0xffffc282 filled by 0x3599c via 0x37ef0 (19 indexed fields); source cells for the write dispatch 0x35a8c."),
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
        'pass': 'e2ram_device_layer_labeling',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: e2ram_device_layer_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/e2ram_device_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
