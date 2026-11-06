#!/usr/bin/env python3
"""Append reviewed idle-speed-control aliases to the curated TSVs (idempotent).

Runs after review_intake_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the task[10] idle batch ref_updateIdleControl__
0x167c0 (26 callees), the idle air feedback/target/trim chain, the
0x5ca94 target encoder (Mode 22 PID 0x096e source) and the select flags.
Also writes metadata/idle_control_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_idle_control'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("000167c0", "idle_control_calc_batch", "high",
     "28-call batch (27 jsr + 1 tail jmp in the 174-byte body) under interrupt mask 0x10, called from task[10] body 0x11744 (task rec[10].entry thunk 0x64f6 at ROM 0x4a38). First jsr 0x167c6 -> 0x3920 sh_raise_interrupt_mask_return_previous with r4=0x10; callees via pool 0x16888-0x168fc (classified mixed_pool) words read from ROM: 0x1688c=0x148a4, 0x16890=0x16748, 0x16894=0x16358, 0x16898=0x16900, 0x1689c=0x148c4, 0x168a0=0x15f5c, 0x168a4=0x14944, 0x168a8=0x14baa, 0x168ac=0x1506c idle_target_rpm_calculate, 0x168b0=0x14d10, 0x168b4=0x14f6c, 0x168b8=0x16432, 0x168bc=0x165d6, 0x168c0=0x16672, 0x168c4=0x15ffc, 0x168c8=0x1617e, 0x168cc=0x15fa0, 0x168d0=0x15a40, 0x168d4=0x16380, 0x168d8=0x16720, 0x168dc=0x3337c, 0x168e0=0x3354e, 0x168e4=0x34650, 0x168e8=0x34814, 0x168ec=0x15a9a, 0x168f0=0x216f8; tail jmp 0x1686a -> 0x3934 ref_setSR. Callee set is the idle air/target/trim chain (inherited name confirmed)."),
    ("00015a9a", "idle_air_feedback_calc", "high",
     "Idle air feedback: compares engine_speed_rpm 0xffffb548 with quantized target 0xffffa7ac -> flag 0xffffa844 (312.0 rpm floor at pool 0x6df44), air-per-rev terms 0xffffa834*a7ac/rpm, filter 0x23b0, tables 0x6947c/0x69490/0x694a4 (rpm axis) and 0x69440/0x69454 (coolant axis) with descriptors parsed from ROM (n=9/5/6/9/9, type 4); pool floats 0x6df48=29.1969, 0x6df54=0.5, 0x6df58=0.892, 0x6df5c=0.15, 0x6df60=2.72, shared 0x7a088=0.6345; writes 0xffffa850/a854/a864/a868/a860/a84c/a848/a83c/a838. Called from 0x167c0 via pool 0x168ec (jsr at 0x1685a)."),
    ("000216f8", "idle_air_output_clamp", "high",
     "Final idle air output: 0xffffb2a4 = clamp(tbl 0x6a218(0xffffa838), tbl 0x6a240(coolant), tbl 0x6a22c(coolant)) via 0x2404 rx8_clamp_float; pool 0x21740-0x2175c (classified mixed_pool) words: 0x21744=0x2068 (lookup helper), 0x21748=0x6a218, 0x2174c=0x6a240, 0x21750=0xffffb2a8, 0x21754=0x6a22c, 0x21758=0xffffb2ac, 0x2175c=0x2404 (clamp); descriptors parsed (0x6a218 n=21 type 4 axis 0x732dc data 0x73330; 0x6a22c n=13 axis 0x73348 data 0x7337c; 0x6a240 n=13 axis 0x7338c data 0x733c0). 0xffffb2a4 is read by 0x21a80 ref_throttlePlatePosToTorqueOutput_ (pool 0x21b10 at 0x21a88) - the electronic-throttle torque chain, plus 0x1b940/0x233ec/0x29d4c/0x48558."),
    ("0005ca94", "idle_target_encode_u16", "high",
     "Encodes idle_target_rpm (fr4) to u16 with step 0.25 (f32 0x3e800000 at ROM 0x5cb64, loaded by mova at 0x5cb1a) through 0x2490 rx8_encode_u16_affine_saturate when diag override state 0xffffd319==0 and the active DID 0xffffd314==0x96e (word at pool 0x5cb42) passes mask 0xc0 (word at 0x5cb3e) on 0xffffd36c; result stored to 0xffffd34d (base 0xffffd335 + 0x18); otherwise decodes override cell 0xffffd34d via 0x24c0. Pool words of the function (classified mixed_pool starting 0x5cb3e): 0x5cb44=0xffffd319, 0x5cb4c=0xffffd335, 0x5cb50=0x5f728, 0x5cb54=0xffffd314, 0x5cb58=0xffffd318, 0x5cb5c=0xffffd316, 0x5cb60=0x5f734, 0x5cb68=0x2490. Sole caller 0x1506c stores the u16 to 0xffffa7ac, the Mode 22 PID 0x096e source (handler 0x56e22, encode *0.25). Not an actuator register."),
    ("0001617e", "idle_trim_integrator", "medium",
     "Long-term idle trim: reads learned trim floats 0xffff8040/0xffff8048 (mov.w pools 0x16260/0x16262, sign-extended) via 0x3dcd0/0x3dc22 ref_readValue_float_DEFAULTVAL_ADDRESS, nudges by 1e-5 toward the sign of 0xffffa7a8 when learn flag 0xffffa890==1 (pool 0x16264 at 0x161cc), clamps to [-0.12, 0.12], writes back via ref_updateMemoryAtAddress_float; 0xffffb534/0xffffb53c select which cell. Called from 0x167c0 via pool 0x168c8."),
    ("00015fa0", "idle_trim_load", "medium",
     "0xffffa88c = learned idle trim read from 0xffff8040 (when 0xffffb534==1) or 0xffff8048 (MT: 0xffffb53c selects; addresses as sign-extended mov.w -0x7fc0/-0x7fb8) via ref_readValue_float_DEFAULTVAL_ADDRESS. Called from 0x167c0 via pool 0x168cc."),
    ("00016900", "idle_air_correction_select", "medium",
     "Selects idle air correction 0xffffa8cc/0xffffa8d0 from 2-D tables 0x69244/0x69258/0x6926c/0x69280/0x69294/0x692a8 by flags 0xffffbd69/0xffffb534/0xffffb53c/0xffffb540/0xffffbdb8; bd69==0 forces a8cc=0. Called from 0x167c0 via pool 0x16898."),
    ("00016748", "idle_ac_load_calc", "medium",
     "A/C load term: b534==1 -> tbl 0x69530, else 3-D tbl 0x69544(coolant, catalyst temp model 0xffffa998); result 0xffffa8c4, filtered into 0xffffa8c8 (updates only when below a8c8+20.0). Called from 0x167c0 via pool 0x16890."),
    ("00016358", "idle_baro_comp", "medium",
     "0xffffa898 = 3-D tbl 0x6a814(baro 0xffffad14, 0xffffa834). Called from 0x167c0 via pool 0x16894."),
    ("000148c4", "idle_maf_airflow_term", "medium",
     "0xffffa7a4 = tbl(0x6a100 if b534==1 else 0x6a114/0x6a128 by b53c)(0xffffb5a8) * 0.6345 * 60 / 0xffffa7ac via divide-with-zero-fallback (0.6345 at shared pool 0x7a088). Called from 0x167c0 via pool 0x1689c."),
    ("000148a4", "idle_target_term_lookup", "medium",
     "0xffffa7a0 = tbl 0x692bc(0xffffa7ac). Called from 0x167c0 via pool 0x1688c."),
    ("00015f5c", "idle_air_terms_sum", "medium",
     "0xffffa888 = 0xffffa8cc + 0xffffa7a4. Called from 0x167c0 via pool 0x168a0."),
    ("00016720", "idle_iat_comp", "medium",
     "0xffffa8c0 = tbl 0x6a830(IAT 0xffffaddc). Called from 0x167c0 via pool 0x168d8."),
    ("00016380", "idle_aux_air_term", "medium",
     "When 0xffffb2f6==1: 0xffffa89c = clamp(0xffffb1dc * 0.6345 * tbl 0x6a13c(0xffffb220) * 60 / rpm, 0, 0.2), else 0. Called from 0x167c0 via pool 0x168d4."),
    ("00015a40", "fuel_cut_resume_threshold", "medium",
     "0xffffa830 = tbl 0x69768(rough knock correction leading 0xffffa6ac) when 0xffffa6b7/a6b8/a6b9 are clear, else 0. Called from 0x167c0 via pool 0x168d0."),
    ("00014944", "idle_drive_flags", "medium",
     "Vehicle-speed thresholds 3/4 km/h -> 0xffffa827; 0xffffa9bc < 1.0/1.5 -> 0xffffa821; sets 0xffffa7b6 when a821==1 && a820>1; snapshots bd69/b53a/b534. Called from 0x167c0 via pool 0x168a4."),
    ("00014baa", "idle_mode_timers", "medium",
     "Countdowns 0xffffa80c/a80e (reload 0x1f on bd69/b53c change), 0xffffa810=0xc / 0xffffa812=0x5c on 0xffffad18 edges. Called from 0x167c0 via pool 0x168a8."),
    ("00014d10", "idle_stall_flags", "medium",
     "Vehicle speed 9/10 km/h -> 0xffffa82b; engine-stopped latch 0xffffa41c or (a7a8<0 && mode flags) forces 0xffffa7a8=0; selects among 2-D tables 0x692d0-0x69348. Called from 0x167c0 via pool 0x168b0."),
    ("00014f6c", "idle_trim_ramp", "medium",
     "0xffffa7c0 ramped down by 0.00087 (pool 0x6dabc) toward 3-D floor tbl 0x69424(coolant, baro) when 0xffffa7b4==0; counters 0xffffa814/a816 gated by a7b4/a7b5. Called from 0x167c0 via pool 0x168b4."),
    ("00016432", "idle_ac_request_calc", "medium",
     "0xffffa8bd/a8be set when 0xffffa7ac + 3.0 <= rpm; 0xffffa8b8 = tbl 0x694cc(coolant) if 0xffffce32 else 0; decay steps from ROM 0x6e0ac/0x6e0b0 (secondary-air-pump-dependent); 90 C coolant / 40 C IAT gates. Called from 0x167c0 via pool 0x168b8."),
    ("000165d6", "idle_ac_clutch_gate", "medium",
     "0xffffa8bc = 0 when (bd69==0 && a8bf) or engine-running timer < 0x80 or flags 0xffffbbb8/a7b6/c5e6/c5db/c5d7/c61e set; else 1; mirrors bd69 into a8bf. Called from 0x167c0 via pool 0x168bc."),
    ("00016672", "idle_stall_detect", "medium",
     "0xffffa8a8 = 1 when a8bc==1 && 0xffffa7ac <= rpm && (a8bd || a8be) && engine running && a8a4 >= 0.01 && within tolerance band (0x3727c5ac); else 0. Called from 0x167c0 via pool 0x168c0."),
    ("00015ffc", "idle_learn_condition", "medium",
     "0xffffa890 learn flag from counters 0xffffa892/a894 (reload 0x138) and gates (a7b4, coolant >= 80, IAT >= 60, |a7ac - 0xffffb550| > 37, a8cc tolerance band, b2f0 > 35, a838 vs a840/a83c, a7b7, 0xffffcc91). Called from 0x167c0 via pool 0x168c4."),
    ("0003337c", "idle_ratio_calcs", "medium",
     "0xffffc04c = 0xffffbacc / 0xffffa7ac when engine running; tables 0x6af18(coolant) and 0x6af40(c04c) selected by b534/b53c; 0xffffc050 zeroed when engine stopped. Called from 0x167c0 via pool 0x168dc."),
    ("0003354e", "idle_ac_blend_ramp", "medium",
     "0xffffc048: MT (b534==0) 0 when b53c==0, 0.04 when c05b==0, else decays 0.0008 to 0; AT (b534==1) forces 0. Called from 0x167c0 via pool 0x168e0."),
    ("00034650", "idle_vehicle_speed_flags", "medium",
     "AT branch: 0xffffc1b4 = tbl 0x6b318(vspeed), 0xffffc1b8 = tbl 0x6b32c(rpm), 0xffffc1a0 = c1b4 * clamp((680.0 - rpm)/130.0, 0, 1), 0xffffc1a8 = max(c1a0, c1a8 - c1b8), 0xffffc1bc = rpm >= 680 (clears below 672.1875). Called from 0x167c0 via pool 0x168e4."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffb2a4", "idle_air_required", "float", "000216f8",
     "Clamped idle air output of 0x216f8: clamp(tbl 0x6a218(a838), tbl 0x6a240(coolant), tbl 0x6a22c(coolant)). Read by 0x21a80 ref_throttlePlatePosToTorqueOutput_ (pool 0x21b10 at 0x21a88 -> electronic throttle torque chain, terminals 1B/1C), also 0x1b940/0x233ec/0x29d4c/0x48558."),
    ("ffffa838", "idle_air_calc_total", "float", "00014d10",
     "Written by 0x15a9a: a838 = min(a898 * a8c0 * a848, a83c) where a898 = baro comp (0x16358, tbl 0x6a814), a8c0 = IAT comp (0x16720, tbl 0x6a830), a83c from tbl 0x694b8(rpm - a7ac); then clamped into 0xffffb2a4 by 0x216f8 (reads a838 via pool 0x21740 at 0x21706)."),
    ("ffffa890", "idle_trim_learn_active", "uint8", "0001617e",
     "Learn-enable flag computed by 0x15ffc (counters a892/a894 reload 0x138; coolant/IAT/error gates); gates the trim integration in 0x1617e (read via pool 0x16264 at 0x161cc)."),
    ("ffffbd69", "ac_clutch_on", "uint8", "000165d6",
     "Set by 0x2e9a4 under a gating chain (engine-running timer 0xffffa424, injectors-off 0xffffa42c, rpm < 7800, coolant < 118 C, flags bd72/bd73/bd76/bd92/bd96/bd97/bd98/0xffffc5e6); adjacent to ref_calculateACClutchOn__ 0x2e89c; consumed as A/C-clutch select in the idle chain (0x16900/0x165d6/0x14944)."),
    ("ffffb534", "automatic_transmission", "uint8", "00016748",
     "Set to 1 by ref_getAutoTransCal__ 0x24b44 (store at 0x24b58 via pool 0x24b5e); 0x24b8c clears 0xffffb53c/b53e/b540 when b534==1; selects AT vs MT table paths across the idle batch (0x16748/0x148c4/0x16900/0x15fa0/0x3354e/0x34650)."),
    ("ffffb5b3", "high_load_flag", "uint8", "0001506c",
     "Set by 0x264f0 when filtered 0xffffb5e0 >= 40.0 (clears below 30.0); 0xffffb5a4 = first_order_filter(b5e0, b5a4, 0.035335) in 0x2633e; 0xffffb5a4/0xffffb5a0 ratio appears in the alternator domain (0x2ce18); selects an idle-target table path in 0x1506c."),
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
        'pass': 'idle_control_labeling',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: idle_control_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'notes': {
            'ffffbdb8': 'Producer identified: ref_getACSwitchStatus 0x2f868 writes inferred_ram_bdb8 (PID 0x1102 cell) = (0xffff9ecd & 4) == 0, i.e. A/C switch input. TSV row keeps the existing inferred_ alias (already integrated into the export); the semantic is recorded here and in idle_control_report.md.',
        },
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/idle_control_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
