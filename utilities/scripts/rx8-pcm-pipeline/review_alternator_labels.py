#!/usr/bin/env python3
"""Append reviewed alternator/charging-control aliases to the curated TSVs (idempotent).

Runs after review_idle_control_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the three inherited ref_alternator* batch bodies
0x267c6/0x2680e/0x26868, the voltage target/PID chain, the field-duty PWM output
on ATU-II ch5B (0x25710/0x25674/0x57c6), the charging DTCs P2502/P2503/P2504 and
the diag encoders 0x5cba4/0x5c800. Also writes metadata/alternator_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_alternator'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("000267c6", "alternator_control_main_batch", "high",
     "Mask-0x10 batch called from 0x114d0 (callgraph 0x114d0 -> 0x267c6). Pool words 0x26888-0x268b0 read from ROM: 0x26888=0x3920 sh_raise_interrupt_mask_return_previous (r4=0x10), 0x2688c=0x25a22, 0x26890=0x25a3c, 0x26894=0x25a68, 0x26898=0x25b36, 0x2689c=0x25ba4, 0x268a0=0x2616e, 0x268a4=0x26624, 0x268a8=0x25710, 0x268ac=0x545bc, tail jmp via 0x268b0=0x3934 ref_setSR. Inherited ref_alternatorControlMain confirmed: speed/voltage/battery-temp/error/duty/PWM-output calc + P2502 DTC raise."),
    ("0002680e", "alternator_monitor_batch", "high",
     "Mask-0x10 batch called from task[10] body 0x11744 (callgraph 0x11744 -> 0x2680e). Pool words 0x268b4-0x268d0: 0x268b4=0x257b4, 0x268b8=0x2590a, 0x268bc=0x25aa0, 0x268c0=0x2635c, 0x268c4=0x264f0, 0x268c8=0x26760, 0x268cc=0x54590, 0x268d0=0x545a6, tail via 0x268b0=0x3934. Inherited ref_alternatorControl confirmed: DTC confirmation timers, high-load flag, warning-light flag, P2503/P2504 raises."),
    ("00026868", "alternator_pid_task", "high",
     "Mask-0x10 wrapper calling only 0x25c6c (pool 0x268d8=0x25c6c, 0x26888=0x3920 mask, 0x268b0=0x3934 tail ref_setSR); called from task[14] body 0x11adc (charging_control_batch; its batch pool starts at 0x11ca8 with 7 entries). Inherited ref_alternatorControlMain confirmed as the voltage-target/PID task."),
    ("00025a68", "alternator_speed_calc", "high",
     "0xffffb598 = engine_speed_rpm 0xffffb548 * 2.08 (belt ratio, f32 @ shared pool 0x74990); 0xffffb613 = alternator speed >= 859.0 (pool 0x74994, lower bound folded). Called from 0x267c6 via pool 0x26894."),
    ("00025a3c", "overvoltage_flags", "medium",
     "0xffffb612 = 1 when 0xffffb654 >= 18.471 (pool 0x74978/0x74988) or 0xffffb658 >= 15.938 (pool 0x7497c/0x7498c). Called from 0x267c6 via pool 0x26890."),
    ("00025ba4", "battery_temp_model", "medium",
     "Battery temperature estimate 0xffffb5c4 = IAT + max((coolant 0xffffa98c - 93.0)*0.43, 0) (pools 0x749b0/0x749b4) + filtered/clamped term (tbl 0x6a524(vspeed) decay, first_order_filter 2e-5, clamp [-7.2, 4.4]); 66.25 when 0xffffc5db set. Called from 0x267c6 via pool 0x2689c."),
    ("0002616e", "alternator_voltage_error_calc", "medium",
     "Voltage error: 0xffffb5c8 = clamp(0xffffb59c - 0xffffb65c, -2.5, 2.5) (2.5 at pool 0x2623c), delta 0xffffb5cc; target field 0xffffb5a0 = tbl 0x6a54c(alt speed) when b613, else 0; ramp (rpm - b600)/(b604 - b600) clamp [0.1, 1.0] with b600/b604 = 406.25/700.0 (pools 0x749ec/0x749e4, AT-in-neutral selects 406.25 when b534==1 && b53a==0); integral terms 0xffffb5d4 = clamp(b5c8*10, -125, 4.8828), 0xffffb5d8 accumulates. Called from 0x267c6 via pool 0x268a0."),
    ("00026624", "alternator_duty_calc", "medium",
     "Field duty: 0xffffb5f0 = 3.75 (pool 0x26734) when alt-speed flag b613 set and 0xffffb5e0 within band of b5a0, else 3-D lookup 0x6a5c4(alt speed, b5e0); filtered (factor 0.1244 pool 0x74a40) into 0xffffb5f4; 0xffffb5f8 = clamp((b5f4 - prev*0.9672)/0x3d065950, 0, 3.75); 0xffffb620 = clamp(tbl 0x6a560(b5f8), 0, 100) when b5e0 out of band and b612==0; 0xffffb5ac = ref_diagAlternatorSignalthing(0x5c800)(b620). Called from 0x267c6 via pool 0x268a4."),
    ("00025710", "alternator_field_pwm_output", "high",
     "Final field PWM duty: 0xffff9f48 = rx8_mul_s32_shift16_saturate((clamp(0xffffb5ac,0,100)/100.0)*65536, period u16 at 0xffff9f44). Disasm: pool 0x2578c = 0xffff9f44 (u32 address), 0x25780 = f32 100.0, 0x25788 = f32 65536.0, mov.w @r5 reads period, mov.w r0,@(0x4,r2) stores duty at 0xffff9f48. Called from 0x267c6 via pool 0x268a8."),
    ("00025674", "alternator_pwm_channel_init", "high",
     "ATU-II ch5B channel init: 0xffff9f44 = 1000 (period), 0xffff9f48 = 0 (duty), ATUII_GR5B_W 0xfffff4e4 = TCNT5 0xfffff4e0 + 1, TIOR5A_B 0xfffff4eb = (b & 0x8f) | 0x10, TSR3_W 0xfffff480 = 0xf7ff, TIER3 |= 0x800. Register names from symbols.tsv."),
    ("000057c6", "alternator_pwm_service", "high",
     "ATU-II ch5B PWM service: splits duty 0xffff9f48 vs period 0xffff9f44 into compare windows (0x7e margin) into 0xffff9f46/0xffff9f4a, then GR5B_W = TCNT5_W + compare with TIOR5A_B output config toggled (0x10/0x20); clears TSR3_W 0x77ff; called via pool 0x2b88 (load at 0x2b82) from the ch5B compare interrupt path. Registers from symbols.tsv: ATUII_TCNT5_W 0xfffff4e0, ATUII_GR5B_W 0xfffff4e4, ATUII_TIOR5A_B 0xfffff4eb, ATUII_TSR3_W 0xfffff480."),
    ("00026760", "alternator_warning_light_flag", "medium",
     "0xffffb5b4 = 1 when (b613==0 || b5b0==1 || b5b1==1 || b5b2==1 || 0xffffc5db==1). Flag is exported, not GPIO-driven from here: read by 0x28c78 (packed into CAN status word 0xffffbab2 bit 0x40 via pool 0x28d70 at 0x28cfe) and by Mode 22 PID 0x0968 handler 0x57138 (pool 0x5717e). Called from 0x2680e via pool 0x268c8."),
    ("00025a22", "charging_ok_latch", "medium",
     "0xffffb5b1 = (0xffffb60a == 0). Called from 0x267c6 via pool 0x2688c."),
    ("000257b4", "charging_dtc_timer_a", "medium",
     "0xffffb608 = 0x138 when (b654 > 18.471 || b658 > 15.938 || engine stopped || b638 < 0x3f || b645==0 || (b645==1 && b63a < 0x3f)), else counts down; counters b638/b63a saturate while running/voltage >= 10 (b645 from battery volts 9/10 thresholds). Called from 0x2680e via pool 0x268b4."),
    ("0002590a", "charging_dtc_timer_b", "medium",
     "0xffffb60a = 0x138 when (b654 <= 16.973 (pool 0x74980) || b658 >= 10.938 (pool 0x74984) || engine stopped || b63c < 0x3f || b646==0 || (b646==1 && b63e < 0x3f)), else counts down. Called from 0x2680e via pool 0x268b8."),
    ("00025aa0", "hot_engine_dtc_timer", "medium",
     "0xffffb648 = coolant >= 60 (hyst 55); 0xffffb60c = 100 when engine stopped && coolant hot, else counts down. Called from 0x2680e via pool 0x268bc."),
    ("0002635c", "low_voltage_dtc_timer", "medium",
     "0xffffb60e = 0x138 unless (b654 >= 8.486699 (pool 0x74a1c) && b5e0 > 19.531 && engine running && counters full && volts >= 10); 0xffffb5b2 = 1 when b60e==0, else 0 when b654 >= 8.486699. Called from 0x2680e via pool 0x268c0."),
    ("000545bc", "charging_dtc_raise_p2502", "medium",
     "FUN_0005fd38(0x7b, b5b1==0 ? 2 : 1): slot 0x7b -> code_id 0x71 (u16 at ROM 0x7df42+0xf6) -> raw 0x2502 at ROM 0x7e560+0xe2 = P2502 (charging system voltage problem). Called from 0x267c6 via pool 0x268ac."),
    ("00054590", "charging_dtc_raise_p2503", "medium",
     "FUN_0005fd38(0x7c, b5b2==0 ? 2 : 1): slot 0x7c -> code_id 0x72 -> raw 0x2503 = P2503 (charging system voltage low). Called from 0x2680e via pool 0x268cc."),
    ("000545a6", "charging_dtc_raise_p2504", "medium",
     "FUN_0005fd38(0x7d, b5b0==0 ? 2 : 1): slot 0x7d -> code_id 0x73 -> raw 0x2504 = P2504 (charging system voltage high). Called from 0x2680e via pool 0x268d0."),
    ("00025c6c", "alternator_voltage_target_select", "medium",
     "Target voltage 0xffffb61c: 14.2 (pool 0x749c8) when c6ac<=0 && b64c; tbl 0x6a5b0(battery temp b5c4) + clamp(b59c ± 0.2 hysteresis, b624) in cold mode (b617); tbl 0x6a59c + min(b59c+0.2, b624) in mode b618; then 0xffffb59c = ref_alternatorPIDsomething(0x5cba4)(b61c). Coolant/IAT 145/150 C flags b64a/b64b/b64c. Called from 0x26868 via pool 0x268d8 and from 0x25790."),
    ("0005cba4", "alternator_target_encode_u16", "medium",
     "Diag-override-aware u16 encoder for the voltage target, DID 0x97c (mask 0x60 on 0xffffd36c, state 0xffffd319/0xffffd328, cell 0xffffd34f): step f32 0x3a000000 via 0x2490 rx8_encode_u16_affine_saturate; decode via 0x24c0. Same pattern as 0x5ca94 (PID 0x096e). Sole caller 0x25c6c stores result into 0xffffb59c."),
    ("0005c800", "alternator_duty_encode_u16", "medium",
     "Diag-override-aware u16 encoder for the field duty %, DID 0x16e8 (mask 0x40, cell 0xffffd347): step f32 0x3b480000 via 0x2490; decode via 0x24c0. Sole caller 0x26624 stores result into 0xffffb5ac (also Mode 22 PID 0x16e8 source, handler 0x56fc8)."),
    ("0002ce18", "alternator_drag_torque_calc", "medium",
     "0xffffbcc4 = tbl 0x6a790(alt speed 0xffffb598) * (0xffffb5a4 / 0xffffb5a0) when b5a0 is outside the 0x3727c5ac tolerance band, else 0. Speed-dependent alternator drag estimate. Called from the 0x25xxx alternator chain."),
    ("000264f0", "electrical_load_flag_calc", "medium",
     "0xffffb5b3 = 1 when filtered 0xffffb5e0 >= 40.0, 0 below 30.0; 0xffffb5a4 = first_order_filter(b5e0, b5a4, 0.035335, 1e-5) maintained by 0x2633e; 0xffffb5a8 tracks b5ec = b5e0 * clamp((b5e0-b5e8)/50.0, 0, 1) with -124.51 decay. Called from 0x2680e via pool 0x268c4. Feeds idle high-load select (idle_control_report) and the drag ratio in 0x2ce18."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffff9f44", "alternator_pwm_period", "uint16", "000057c6",
     "ATU-II ch5B PWM period, init 1000 by 0x25674; duty fraction computed against it in 0x25710 (mov.w @r5 at 0x2573c) and split into compare windows in 0x57c6."),
    ("ffff9f48", "alternator_pwm_duty", "uint16", "000057c6",
     "ATU-II ch5B PWM duty counts, written by 0x25710 (mov.w r0,@(0x4,r2) at 0x2574a with base 0xffff9f44) from 0xffffb5ac percent; consumed by 0x57c6 into GR5B 0xfffff4e4."),
    ("ffffb5b1", "charging_ok_latch", "uint8", "00025a22",
     "Set by 0x25a22 = (0xffffb60a == 0), i.e. P2502 confirmation timer fully counted down; gates P2502 raise in 0x545bc and the warning flag in 0x26760."),
    ("ffffb5b2", "low_voltage_latch", "uint8", "00025c6c",
     "Set by 0x2635c when the 0xffffb60e timer (0x138) reaches 0 under low-voltage conditions (0xffffb654 >= 8.486699 pool 0x74a1c); gates P2503 raise in 0x54590 and the warning flag in 0x26760."),
    ("ffffb5a0", "alternator_target_field", "float", "0002616e",
     "Target field drive from tbl 0x6a54c(alt speed 0xffffb598) when b613, else 0; written by 0x2616e; used as band reference in 0x26624/0x2ce18."),
    ("ffffb5a4", "electrical_load_filtered", "float", "00025c6c",
     "first_order_filter(0xffffb5e0, b5a4, 0.035335) maintained by 0x2633e; numerator of the drag ratio in 0x2ce18 (b5a4/b5a0)."),
    ("ffffb5e0", "electrical_load_raw", "float", "0002616e",
     "Raw electrical-load quantity filtered into 0xffffb5a4 (0x2633e) and thresholded at 40/30 in 0x264f0 -> 0xffffb5b3; compared against b5a0 band in 0x26624."),
    ("ffffbcc4", "alternator_drag_torque", "float", "0002ce18",
     "Written by 0x2ce18 = tbl 0x6a790(alt speed) * (0xffffb5a4/0xffffb5a0), 0 when b5a0 within tolerance; alternator drag estimate for drivability compensation."),
    ("ffffb658", "system_voltage_alt", "float", "000257b4",
     "Second voltage rail used in the charging DTC timers (thresholds 15.938/10.938 pools 0x7497c/0x7498c/0x74984) by 0x257b4/0x2590a; distinct from filtered battery volts 0xffffb590."),
    ("ffffb65c", "battery_voltage_filtered", "float", "0002616e",
     "Filtered battery voltage subtracted from the target 0xffffb59c in 0x2616e to form the charging error 0xffffb5c8 (clamp ±2.5)."),
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
        'pass': 'alternator_control_labeling',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: alternator_control_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'notes': {
            'ffffb598': '0xffffb598 keeps its existing inferred_alternator_speed alias (already integrated); verified here as rpm*2.08 in 0x25a68 (pool 0x74990).',
            'ffffb5ac': '0xffffb5ac keeps inferred_ram_b5ac (PID 0x16e8 source, handler 0x56fc8); verified as field duty percent written by 0x26624 via 0x5c800.',
            'ffffb59c': '0xffffb59c keeps inferred_ram_b59c; verified as voltage target written by 0x25c6c via 0x5cba4 (PID 0x097c).',
            'ffffb5b4': '0xffffb5b4 keeps inferred_ram_b5b4 (PID 0x0968); verified as warning flag set by 0x26760, exported via CAN word 0xffffbab2 bit 0x40 (0x28c78).',
        },
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/alternator_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
