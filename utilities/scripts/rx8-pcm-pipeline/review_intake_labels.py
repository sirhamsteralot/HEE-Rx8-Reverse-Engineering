#!/usr/bin/env python3
"""Append reviewed intake-solenoid actuator aliases to the curated TSVs (idempotent).

Runs after review_fueling_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers SSV / VDI / VFAD solenoids, APV motor + feedback,
secondary-air solenoid/pump, and the diagnostic actuator overrides. GPIO bits
are cross-checked against Sh7055h.pdf Table 1.3 (package pins). Also writes
metadata/intake_labels.json.
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
BASIS = 'source_review_intake'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("0002178c", "ssv_solenoid_control", "high",
     "Writes PEDR_W 0xfffff754 bit 0x80 (PE7, SH7055F pkg pin 16) via ref_setRegister_REG_BIT_VAL after diag override 0x5c9ac. On-condition: coolant hysteresis 197/200 C (b2b4), counter b2b2=0xbc, (aa68==0 && b2b5 prev) || becd. Harness: SSV solenoid PCM 1L (position switch is separate, PCM 1D). Reached from task 0x64f6 -> 0x11744 -> 0x21766."),
    ("00021760", "ssv_control_thunk", "medium", "4-byte thunk to 0x2178c; called from init fan-out 0x1102a."),
    ("00021766", "ssv_control_task_wrapper", "medium", "Mask-0x10 wrapper calling ssv_solenoid_control (0x2178c); called from 0x11744 (task 0x64f6 chain)."),
    ("00034844", "vdi_solenoid_control", "high",
     "Writes PDDR_W 0xfffff746 bit 0x20 (PD5, pkg pin 254; PD5/TIO1F alternate) after diag override ref_diagControlVDI. On = RPM >= 7250 (hysteresis 7062). Harness: VDI solenoid PCM 1W. Reached from 0x11744 -> 0x348ea."),
    ("000348e4", "vdi_control_thunk", "medium", "4-byte thunk to 0x34844; called from 0x1102a."),
    ("000348ea", "vdi_control_task_wrapper", "medium", "Mask-0x10 wrapper calling vdi_solenoid_control; called from 0x11744."),
    ("0003493c", "vfad_solenoid_control", "high",
     "Writes PEDR_W bit 0x400 (PE10, pkg pin 19) after diag override ref_diagControlVFADMAYBE. On = RPM >= 5250 (hysteresis 5062). Harness: VFAD solenoid PCM 5Z (high-power only). Reached from 0x11744 -> 0x34916."),
    ("00034910", "vfad_control_thunk", "medium", "4-byte thunk to 0x3493c; called from 0x1102a."),
    ("00034916", "vfad_control_task_wrapper", "medium", "Mask-0x10 wrapper calling vfad_solenoid_control; called from 0x11744."),
    ("00031c20", "apv_control_task", "high",
     "APV wrapper under mask 0x10: calls 0x31c6c (target/condition), ref_apvPositionVoltageCounter (0x31ece), ref_calcAPVCounter (0x31f0a), 0x31f32 (command), ref_setAPVDC_00031bec. Called from 0x11744 (task 0x64f6 chain). Harness: APV motor PCM 3J/3G, signal 3B, ref 1S, return 1U."),
    ("00031c6c", "apv_target_condition", "medium",
     "Computes APV target state bf8d from RPM >= 150/200 (bf99), counter bf92 > 0x32, aa68; uses MAF a9ec and coolant a98c snapshots."),
    ("00031ece", "apv_position_voltage_counter", "medium",
     "bf88: reset to 0 when bf8b==0 or (bf88 > 0x4e1 && cab4==0); else saturating increment — position-voltage dwell counter."),
    ("00031f0a", "apv_counter_calc", "medium", "bf8a: 0 when bf8b==1 else saturating u8 increment — APV drive counter."),
    ("00031f32", "apv_command_calc", "medium",
     "Sets command bf84: 0 in low-RPM/closed conditions; else staged float literals 100.0 (0x42c80000) / 12.5 (0x41480000) from 0x31f32's own literal pool (verified in ROM), selected by counter bf88 against u16 band thresholds referenced from ROM 0x78bb2-0x78bc0 (incl. 0x78bb8=0x32); RPM hysteresis 2800/3000 (bf98; binary encodes lower bound as 3000.0 minus 200 offset)."),
    ("00031bec", "apv_command_wrapper", "medium",
     "bf84 negated when bf8b==1, divided by 100, passed to apv_duty_split (0xaa90) — signed percent command."),
    ("0000aa90", "apv_duty_split", "high",
     "param * 96.0 (period u16 at ROM 0x78bb6); positive -> a1c4, negative -> a1c6 (other zeroed): signed duty split into forward/reverse tick counts. See reconstructed/rx8_apv.c."),
    ("0000a936", "apv_pwm_service", "medium",
     "Software-PWM service: consumes pending ticks a1c4/a1c6, latches a1c0/a1c2 at period boundary, drives PLDR_W 0xfffff75e bits 0x0020 (PL5, pkg pin 221) and 0x0100 (PL8, pkg pin 224) with opposite polarity; calls apv_drive_status_sample (0xaac4) at phase 4."),
    ("0000aac4", "apv_drive_status_sample", "medium",
     "Reads PHDR_W 0xfffff72c bits 0x1000/0x2000 (PH12 pkg pin 79 / PH13 pkg pin 80) when a drive-active flag is set; emits remapped 0..3 state at a1bc."),
    ("00043a86", "apv_position_voltage_scale", "medium",
     "cab0 = (float)(u16 9ef0) * 5/65536 (0x38a00000): APV position feedback ADC6 (reg 0xfffff80c, AN6 = pkg pin 92) scaled to volts. PCM 3B->AN6 not board-verified."),
    ("000187b8", "secondary_air_solenoid_control", "high",
     "Writes PEDR_W bit 0x100 (PE8, pkg pin 17) from diag-checked request: load > 0.8 (hyst 0.75, a961), RPM > 4000 (hyst 3900, a962), condition (bf6c && !a961 && !a962) || d26e; override via ref_diagCheckSecondaryAirRequest (0x5cf7c) -> a960. Harness: secondary air injection solenoid PCM 1O. Called from 0x117ac (task 0x6584 chain)."),
    ("000316f8", "secondary_air_pump_control", "high",
     "Writes PBDR_W 0xfffff738 bit 0x4 (PB2, pkg pin 147) = (bf6c == 1): secondary air pump relay/drive output. Called from 0x3174a."),
    ("0003174a", "secondary_air_on_time_task", "medium", "Mask-0x10 task: 0x3194a + 0x31a24 + secondary_air_pump_control (0x316f8)."),
    ("0005c9ac", "ssv_diag_override", "medium", "UDS actuator-test arbitration for SSV (d314 = -0x16da, d319/d326 state machine, d34b output); feeds ssv_solenoid_control (0x2178c)."),
    ("0005c3c0", "vdi_diag_override", "medium", "UDS actuator-test arbitration for VDI (d314 = -0x16db); output d33d feeds vdi_solenoid_control (0x34844)."),
    ("0005cdc4", "vfad_diag_override", "medium", "UDS actuator-test arbitration for VFAD (d314 = 0x17c8); output d353 feeds vfad_solenoid_control (0x3493c)."),
    ("0005cf7c", "secondary_air_diag_override", "medium", "UDS actuator-test arbitration for the secondary-air solenoid; output feeds secondary_air_solenoid_control (0x187b8)."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffffb2b0", "ssv_diag_override_result", "uint8", "0002178c", "Result of ssv_diag_override (0x5c9ac); 1 -> PEDR PE7 set."),
    ("ffffb2b2", "ssv_on_counter", "uint8", "0002178c", "Set to 0xbc when (aa68==0 && b2b5==1), else decremented; gates SSV on with b2b4."),
    ("ffffb2b4", "ssv_coolant_hot_flag", "uint8", "0002178c", "coolant >= 200 (clear below 197) hysteresis; blocks SSV on-condition."),
    ("ffffb2b5", "ssv_was_enabled", "uint8", "0002178c", "previous aa68 snapshot; edge term in the on-condition."),
    ("ffffc1c0", "vdi_command", "uint8", "00034844", "RPM 7062/7250 hysteresis -> ref_diagControlVDI -> PEDR PD5."),
    ("ffffc1c4", "vfad_command", "uint8", "0003493c", "RPM 5062/5250 hysteresis -> ref_diagControlVFADMAYBE -> PEDR PE10."),
    ("ffffa960", "secondary_air_request_final", "uint8", "000187b8", "diag-checked secondary-air solenoid request (PE8)."),
    ("ffffa961", "sec_air_load_high", "uint8", "000187b8", "load > 0.8 (hyst 0.75)."),
    ("ffffa962", "sec_air_rpm_high", "uint8", "000187b8", "RPM > 4000 (hyst 3900)."),
    ("ffffbf6c", "secondary_air_pump_request", "uint8", "000316f8", "Drives PBDR PB2 (pump) and feeds the solenoid condition in 0x187b8."),
    ("ffffbf84", "apv_command_percent", "float", "00031bec", "APV command from 0x31f32 (staged 100.0/12.5 constants); negated when bf8b, /100 -> 0xaa90."),
    ("ffffbf88", "apv_position_dwell_counter", "uint16", "00031ece", "Incremented unless bf8b==0 or (bf88>0x4e1 && cab4==0); bands in 0x31f32."),
    ("ffffbf8a", "apv_drive_counter", "uint8", "00031f0a", "0 when bf8b else saturating increment."),
    ("ffffbf8b", "apv_direction_flag", "uint8", "00031bec", "When 1, negates the APV command (reverse) and resets bf8a."),
    ("ffffbf8d", "apv_target_state", "uint8", "00031c6c", "APV target condition from RPM/counter/aa68."),
    ("ffffbf8e", "apv_target_state_prev", "uint8", "00031c6c", "previous bf8d."),
    ("ffffbf92", "apv_counter_92", "uint8", "00031c6c", "> 0x32 term in APV target logic."),
    ("ffffbf98", "apv_rpm_high_flag", "uint8", "00031f32", "RPM > 3000 (hyst 2800)."),
    ("ffffbf99", "apv_rpm_low_flag", "uint8", "00031c6c", "RPM >= 200 (clear below 150)."),
    ("ffffa1c4", "apv_pwm_forward_ticks", "uint16", "0000aa90", "Forward duty ticks from apv_duty_split (param*96)."),
    ("ffffa1c6", "apv_pwm_reverse_ticks", "uint16", "0000aa90", "Reverse duty ticks (other direction zeroed)."),
    ("ffffa1c0", "apv_pwm_forward_latched", "uint16", "0000a936", "Latched a1c4 at PWM period boundary."),
    ("ffffa1c2", "apv_pwm_reverse_latched", "uint16", "0000a936", "Latched a1c6 at PWM period boundary."),
    ("ffffa1bc", "apv_drive_status", "uint8", "0000aac4", "Remapped 0..3 state from PH12/PH13 (PHDR 0x1000/0x2000)."),
    ("ffffcab0", "apv_position_voltage", "float", "00043a86", "APV feedback volts = ADC6 raw 9ef0 * 5/65536."),
    ("ffff9ef0", "adc6_raw_apv_position", "uint16", "00043a86", "ADC6 (0xfffff80c, AN6 pkg pin 92) sample; candidate APV position input."),
]

LOOKUP = []


def read_rows(path, fields):
    if not path.exists():
        return []
    with path.open(newline='') as f:
        return list(csv.DictReader(f, delimiter='\t'))


def write_rows(path, fields, rows):
    with path.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=fields, delimiter='\t')
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
    val['date'] = '2026-10-30'
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    vp.write_text(json.dumps(val, indent=2) + '\n')

    record = {
        'date': '2026-10-30',
        'pass': 'intake_solenoid_actuator_labeling',
        'basis': BASIS,
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'rom_unchanged': True,
        'ghidra_database_updated': False,
        'pin_sources': 'Sh7055h.pdf (SH7055F HW manual ADE 602-155B) Tables 1.2/1.3; port regs from regs_7055_350.csv; harness terminals from hardware/pcm_connections.tsv; chip-pin->terminal routing unresolved (board)',
    }
    (b / 'metadata/intake_labels.json').write_text(json.dumps(record, indent=2) + '\n')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
