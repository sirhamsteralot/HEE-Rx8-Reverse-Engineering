#!/usr/bin/env python3
"""Label the primary/secondary fuel-split bodies (0x30b08, 0x30f5c) and their
RAM cells — the SSV on-term DAT_ffffbecd and its sibling flags.

Appends rows to source_review/accepted_function_aliases.tsv and
accepted_ram_aliases.tsv (idempotent; conflicts abort), refreshes
source_review/validation.json totals, and writes metadata/fuel_split_labels.json.
Run integrate_reviewed_names.py afterwards to apply the names to the views.
"""
import csv
import json
import sys

from paths import b  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo

BASIS = 'source_review_fuel_split'

FUNCTIONS = [
    ("00030b08", "primary_secondary_fuel_split", "high",
     "Computes the primary/secondary split in the fuel task 0x20e40 (called between "
     "0x30948 calculate_fuel_amount_per_rotation and 0x30f5c): rpm gates bf36/bf37 from "
     "coolant lookups tbl 0x6ac74 (flat 6250) / tbl 0x6ac60 (Secondary Injectors Allowed "
     "Threshold), fuel gates bf38/bf39 vs bec8/beb0 (WOT baro correction tbl 0x6ab84), "
     "then becd/becc flags and split volumes bef0/bef4/bef8/befc by ratio tbl 0x6ab70 "
     "when becc==1. becd is OR-ed into the SSV on-condition by 0x2178c; becc is read by "
     "open-loop logic 0x1f0c4/0x1fd48. Dynamically verified in the SH-2E emulator: "
     "docs/investigations/60E15120_N3J1E/reviews/intake_solenoids/ssv_secondary_injector_link.py."),
    ("00030f5c", "split_pulse_time_output", "high",
     "Split output stage called from fuel task 0x20e40 right after 0x30b08: converts the "
     "split volumes bef0/bef4 into pulse-time values (x6e7 / flow scalars 250.0 "
     "0x43b8bc6a primary, 475.93 0x43edf70a secondary) with first-order filtering "
     "(bebc) and on/off delay counters bf0c/bf0d, writing bf00/bec4/bec0; selects the "
     "all-primary path when bece==0."),
]

RAM = [
    ("ffffaa68", "engine_running_flag", "uint8", "0002178c",
     "1 = engine running, 0 = stopped/cranking; read by SSV control 0x2178c (cold edge "
     "aa68==0 && b2b5), fan logic 0x2f51a, CAN error counter 0xdcc0; mov.w pool word 0xaa68 "
     "sign-extends to 0xffffaa68 (e.g. pool 0x21886 in 0x2178c)."),
    ("ffffbecc", "secondary_split_gate_flag", "uint8", "00030b08",
     "becc = bf36 || (bf37 && bf39), computed in 0x30b08: 0 => all fuel to primaries "
     "(bef0=beb0, bef4=0), 1 => split by ratio tbl 0x6ab70; also read by open-loop request "
     "logic 0x1f0c4/0x1fd48 (b1db/b1da latches). Emulator-verified: set above the "
     "rpm/coolant gate with fuel demand, clear below (ssv_secondary_injector_link_log.txt)."),
    ("ffffbecd", "secondary_injectors_active_flag", "uint8", "00030b08",
     "becd = bf36 || (bf37 && bf38) in 0x30b08 (bf38 uses the WOT baro-corrected fuel gate); "
     "OR-ed into the SSV on-condition by 0x2178c (mov.w pool word 0xbecd at ROM 0x2188a). "
     "Emulator: becd=1 drives PEDR_W PE7 high with engine running and even at 250 C coolant."),
    ("ffffbece", "primary_split_sufficient_flag", "uint8", "00030b08",
     "bece = (bef0 >= bec8) && !(becd && !becc) with 0.005 hysteresis, in 0x30b08; read by "
     "0x30f5c to choose the all-primary pulse path when 0."),
    ("ffffbf08", "split_fuel_gate_hysteresis", "float", "00030b08",
     "Hysteresis band for the bf38/bf39 fuel gates in 0x30b08: 0.007 when coolant >= 40 C, "
     "else 0.02 (inline float compares); 32-bit pool value present in ROM."),
    ("ffffbf0c", "secondary_split_on_delay_counter", "uint8", "00030b08",
     "Loaded from raw-u8 lookup tbl 0x6ab98(coolant) on the becc 0->1 edge, decrements while "
     "becc==1, cleared when becc==1 and prev was 1; consumed by 0x30f5c delay logic."),
    ("ffffbf0d", "secondary_split_off_delay_counter", "uint8", "00030b08",
     "Loaded from raw-u8 lookup tbl 0x6aba4(coolant) on the becc 1->0 edge, decrements while "
     "becc==0; consumed by 0x30f5c delay logic."),
    ("ffffbf10", "split_covers_amounts_ab_flag", "uint8", "00030b08",
     "bf10 = bef0 >= bec8+beec (0.005 hysteresis) in 0x30b08."),
    ("ffffbf11", "split_covers_amounts_bc_flag", "uint8", "00030b08",
     "bf11 = bef0 >= bed8+beec (0.005 hysteresis) in 0x30b08."),
    ("ffffbf24", "split_high_rpm_threshold", "float", "00030b08",
     "lookup_2d_descriptor_scaled(coolant, tbl 0x6ac74) in 0x30b08; table data 0x78548 is "
     "flat u16 0x186a = 6250 rpm (scale 1.0) — the high-RPM override threshold."),
    ("ffffbf28", "secondary_allowed_rpm_threshold", "float", "00030b08",
     "lookup_2d_descriptor_scaled(coolant, tbl 0x6ac60 'Secondary Injectors Allowed Threshold "
     "- Coolant Temperature Based', data 0x78510, axis 0x784ec): u16 cells 3000 rpm at <= 0 C, "
     "0 above ~20 C; confirmed by ROM cell dump and emulator lookup in 0x30b08."),
    ("ffffbf2c", "primary_baro_correction", "float", "00030b08",
     "lookup_2d_descriptor_scaled(baro, tbl 0x6ab84 'Primary Injector Max Barometric Pressure "
     "Correction') in 0x30b08; scales bec8 into bf04 at throttle >= 60%."),
    ("ffffbf04", "split_fuel_gate_threshold", "float", "00030b08",
     "bf04 = bec8 (fuel_amount_per_rotation_a), or bec8*bf2c when throttle >= 60% WOT; "
     "beb0 is compared against it for bf38 in 0x30b08."),
    ("ffffbf36", "high_rpm_override_flag", "uint8", "00030b08",
     "bf36 = rpm >= bf24 (tbl 0x6ac74) with a 188 rpm hysteresis band, in 0x30b08; forces the "
     "secondary split (and SSV) at very high rpm."),
    ("ffffbf37", "secondary_allowed_rpm_flag", "uint8", "00030b08",
     "bf37 = rpm >= bf28 (tbl 0x6ac60 coolant-based Secondary Injectors Allowed Threshold) with "
     "188 rpm hysteresis, in 0x30b08."),
    ("ffffbf38", "split_fuel_gate_wot_flag", "uint8", "00030b08",
     "bf38 = beb0 >= bf04 (WOT-aware threshold) with bf08 hysteresis, in 0x30b08; part of becd."),
    ("ffffbf39", "split_fuel_gate_flag", "uint8", "00030b08",
     "bf39 = beb0 >= bec8 with bf08 hysteresis, in 0x30b08; part of becc."),
    ("ffffbef0", "fuel_volume_primary_split", "float", "00030b08",
     "Primary-side fuel volume after the 0x30b08 split: beb0 when becc==0, else beb0 minus the "
     "secondary share; converted to pulse time in 0x30f5c (x6e7 / 250.0)."),
    ("ffffbef4", "fuel_volume_secondary_split", "float", "00030b08",
     "Secondary-side fuel volume from the 0x30b08 split (0 when becc==0); converted to pulse "
     "time in 0x30f5c (x6e7 / 475.93)."),
    ("ffffbef8", "primary_secondary_split_ratio", "float", "00030b08",
     "Ratio lookup_2d_descriptor_scaled(rpm, tbl 0x6ab70) clamped to [0,1] in 0x30b08; used to "
     "split beb0 into bef0/bef4 when becc==1."),
    ("ffffbefc", "fuel_volume_secondary_amount", "float", "00030b08",
     "befc = bef8 * beb0, the uncapped secondary amount in 0x30b08 (capped against bec8/bedc "
     "when computing bef4)."),
]

LOOKUP = []


def read_rows(path, fields):
    if not path.exists():
        return []
    with path.open(newline='') as f:
        return list(csv.DictReader(f, delimiter='\t'))


def write_rows(path, fields, rows):
    with path.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter='\t', lineterminator='\n')
        w.writeheader()
        w.writerows(rows)


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
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev})
        added_fn += 1
    if not conflicts:
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    p = b / 'source_review/accepted_ram_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, typ, reader, ev in RAM:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('ram %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'type': typ, 'reader': reader, 'evidence': ev})
        added_ram += 1
    if not conflicts:
        write_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'], rows)

    p = b / 'source_review/accepted_lookup_aliases.tsv'
    fields = ['original', 'alias', 'basis', 'evidence']
    rows = read_rows(p, fields)
    pairs = {(r['original'], r['alias']) for r in rows}
    for orig, alias, ev in LOOKUP:
        if (orig, alias) in pairs:
            continue
        rows.append({'original': orig, 'alias': alias, 'basis': BASIS, 'evidence': ev})
        added_lut += 1
    if not conflicts:
        write_rows(p, fields, rows)

    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')

    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text()) if vp.exists() else {
        'date': '2026-10-30', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    # keep the existing file formatting: patch the three fields in place
    import re as _re
    raw = vp.read_text() if vp.exists() else json.dumps(val, indent=1) + '\n'
    raw = raw  # date field left untouched
    raw = _re.sub(r'"function_annotations": \d+',
                  '"function_annotations": %d' % val['function_annotations'], raw, count=1)
    raw = _re.sub(r'"ram_aliases": \d+',
                  '"ram_aliases": %d' % val['ram_aliases'], raw, count=1)
    vp.write_text(raw)

    record = {
        'date': '2026-11-13',
        'pass': 'fuel_split_labeling',
        'basis': BASIS,
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'rom_unchanged': True,
        'ghidra_database_updated': False,
        'dynamic_evidence': 'docs/investigations/60E15120_N3J1E/reviews/intake_solenoids/ssv_secondary_injector_link.py (+ _log.txt), SH-2E emulator harness calls to 0x30b08/0x2178c',
    }
    (b / 'metadata/fuel_split_labels.json').write_text(json.dumps(record, indent=2) + '\n')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
