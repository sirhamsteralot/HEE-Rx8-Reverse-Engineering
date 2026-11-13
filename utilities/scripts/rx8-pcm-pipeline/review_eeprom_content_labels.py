#!/usr/bin/env python3
"""Append reviewed 93C56 EEPROM content-map aliases to the curated TSVs (idempotent).

Runs after review_e2ram_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the chip-content consumers found while mapping the
whole 256 B of IC420 against the upstream dumps: immo key read 0x375c0,
learned-table load/save/erase 0x27b8e/0x279d8/0x27d06, flush request 0x378dc,
UDS dumpers 0x5b5d4/0x5b704, ECU ID readers 0x55b18(kept)/0x5e664, tire
marker/revs 0x543e4/0x5de74, config bit 0x5e748, tail bulk read 0x5b482, and
the RAM-magic handshake 0xd408/0xd44c. Also writes
metadata/eeprom_content_labels.json (incl. the chip-offset map).
"""
from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py)
BASIS = 'eeprom_content_map'

FUNCTIONS = [
    # address, alias, confidence, evidence
    ("000375c0", "e2ram_immo_key_read", "high",
     "Reads device words 0x6010000-0x6040000 (chip 0x02-0x09, 8-byte immo key), 0x60b0000/0x60c0000 (0x16-0x19 immo code), 0x6050000 (0x0a-0x0b status) via e2ram_read_word 0xbdfa under mask 0x10 with 0xbed8 busy checks; all-0x00/all-0xff patterns -> erased flags 0xffffc1d5-0xffffc1d8; gated by ref_securityNotUnlocked(1) and DAT_ffffd1ce. Called from 0x34a04 (boot, near ref_ImmoSomethingOrOther__ 0x349e4)."),
    ("00027b8e", "e2ram_learned_table_load", "high",
     "e2ram_bulk_read_into_shadow(0x20,0x44) then 0x22 iterations of e2ram_cached_byte_read(0x20+2i,..,2): value = rx8_decode_u8_affine(0x3f000000, 0xc27c0000, raw) = -63 + raw*0.5 (pools 0x27c84/0x27c80) -> float cells 0xffff8108+8i (+value) and 0xffff8328+8i (-value), flag byte (0xff->0) -> 0xffff8548+2i and 0xffff85d0+2i via ref_updateMemoryAtAddress_*. Called from 0x2874c/0x288be."),
    ("000279d8", "e2ram_learned_table_save", "high",
     "Reverse of 0x27b8e: 0x22 iterations reading float cells 0xffff8108+8i and byte cells 0xffff8548+2i, rx8_encode_u8_affine_saturate(val, 0x3f000000, 0xc27c0000), e2ram_shadow_byte_write(0x20+2i,..,2), flush FUN_000378dc(0x20,0x44,3); only when engine not running (engine_running_flag_ffffaa68==0) and DAT_ffffb6c7==1, timeout DAT_ffffba16 < 0x4e2. Called from 0x288be."),
    ("00027d06", "e2ram_learned_table_erase", "medium",
     "On engine stop (engine_running_flag_ffffaa68==1 && engine_stopped_latch_ffffa41c==1 && DAT_ffffba20==1) after DAT_ffffba1d reaches 0x14: writes (encode(0.0)=0x7e, flag 0) pairs to shadow 0x20+2i (rx8_encode_u8_affine_saturate(0, 0x3f000000, 0xc27c0000)) i.e. clears the learned table at key-off. Called from 0x288be."),
    ("000378dc", "e2ram_flush_request", "high",
     "Sets up a shadow->chip flush: DAT_ffffc48e = start>>1, DAT_ffffc490 = end word, mode in DAT_ffffc49c (1: read-verify 0xffffc288/0xffffc28b, 2: 0xffffc289/0xffffc28c, 3: 0xffffc28a/0xffffc28d), DAT_ffffc496 = start byte, DAT_ffffc4a1 = busy. Processed by the state machine 0x379e4 (called from 0x38082). Callers incl. 0x279d8 (0x20,0x44,3), 0x5e8a4 (0x78,2)."),
    ("0005b5d4", "e2ram_upper_half_uds_dump", "high",
     "e2ram_cached_byte_read(0x80, buf, 0x80) then ref_setupForUdsResponse_(svc, buf, 0x80): returns EEPROM bytes 0x80-0xff (128 B, VIN at 0x80-0x90) as a UDS response. Inherited ref_grablast28ByteFromE2 name was wrong about the length/offset."),
    ("0005e664", "e2ram_ecu_id_read", "high",
     "Reads chip 0x64 (len 3) -> DAT_ffffd394 (+0x20), 0x68 (1) -> DAT_ffffd39a, 0x6a (2) -> DAT_ffffd398 (u16), 0x6c (1) -> DAT_ffffd39b via e2ram_cached_byte_read 0x37ef0. RX8 dump: 0x64-0x66='13H', 0x68='6', 0x6a-0x6b='02', 0x6c='0'."),
    ("0005b704", "e2ram_field_6e_uds_dump", "high",
     "e2ram_cached_byte_read(0x6e, buf, 9); ref_setupForUdsResponse_(svc, buf, 9). Chip 0x6e-0x76 is erased (0xff) in both upstream dumps."),
    ("000543e4", "e2ram_tire_size_marker_check", "high",
     "e2ram_cached_byte_read(0x95, local, 1); byte == '*' (0x2a) -> DAT_ffffd1b5 = 0 (default tire size), else DAT_ffffd1b5 = 1. Inherited ref_getTireSizeChecksumthing_ confirmed. Chip 0x95 = 0x2a in both dumps."),
    ("0005de74", "e2ram_tire_revs_read", "high",
     "e2ram_cached_byte_read(0x9a, &local, 2) -> tire_revolutions_per_mile_ffffd380 (u16 BE); tolerance band vs 0x3727c5ac -> DAT_ffffd382. Inherited ref_getTireSize confirmed. Dumps: 0x030d = 781 rev/mile."),
    ("0005e748", "e2ram_config_bit_9f_read", "medium",
     "e2ram_cached_byte_read(0x9f, local, 1); (val & 1) == 0 && DAT_ffffd1b5 == 0 && DAT_ffffd1b8 == 0 -> DAT_ffffd39c = 1. RX8 dump 0x9f = 0xfe, SE3P = 0xff."),
    ("0005b482", "e2ram_tail_bulk_read", "high",
     "e2ram_bulk_read_into_shadow(100, 0x9c): bulk-reads chip 0x64-0xff (ID string, 9-byte field, VIN, tire fields, tail) into the shadow 0xffffc28e."),
    ("0000d408", "eeprom_mirror_magic_check", "high",
     "If *(u16*)0xffff8000 == 0xaa55 (pool 0xd4f4) -> DAT_ffffa3fb = 1 (pool 0xd4ec); if set, call 0x9f4c -> 0x6360 -> 0x11492 (validate via 0x3e020, pool 0x11674); if ==1 write 0x55aa (pool 0xd4ea) to 0xffff8000 (pool 0xd4f0) and jmp 0x9f58 -> 0xabfa. Called from 0x6372 (pool 0x63e8) <- ref_getSensorStuff__ 0x60c8."),
    ("0000d44c", "eeprom_mirror_magic_init", "high",
     "If DAT_ffffa3fb == 1 call 0x9f52 -> 0x6366 -> 0x113b8 (init fan-out); then write 0xaa55 (pool 0xd4f4) to 0xffff8000 (pool 0xd4f0). Called from ref_mainInit__ 0x61a8 (pool 0x6288)."),
    ("00027024", "e2ram_learned_table_clear", "high",
     "Clears 2 rotor banks x 0x44 cells: float 0 -> 0xffff8108+8i+bank*0x220 (pool 0x27154) and flag 0 -> 0xffff8548+2i+bank*0x88 (pool 0x27158) via ref_updateMemoryAtAddress_*, plus DAT_ffff8658/865a/865c. Called from 0x2897e."),
    ("000270aa", "e2ram_learned_table_validate", "high",
     "Checksum-validates the same 2 banks x 0x44 learned-table cells via ref_validateAddressCopy_float/8bit (pools 0x27154/0x27158). Called from 0x28992 (validate fan-out 0x3e020)."),
    ("0002711a", "e2ram_learned_table_cell_index", "high",
     "DAT_ffffb6c4 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548, tbl 0x6a694 [17 cells, RPM axis 0x755dc = 0,1125,1750,...,8750, identity u16 data 0x75620]) + 17*load_band; load bands from engine_load_ffffc0b4 vs 0.4/0.65/3.0 (float pools 0x755a4/0x755a8/0x755ac): <0.4 -> +0, <0.65 -> +0x11, <3.0 -> +0x22, else +0x33 (rx8_add_u16_saturate 0x2460, pool 0x2724c). Cell = rpm_cell(0..16) + 17*load_band(0..3). Called from 0x287aa."),
    ("000271b0", "e2ram_learned_table_learn_gate", "high",
     "rpm_cell = DAT_ffffb6c4 mod 17 (div FUN_00003fe8, pool 0x27258); DAT_ffffb8f0 = lookup_2d_descriptor_scaled(rpm_cell, tbl 0x6a6a0 [axis 0x75644 = 0..16, data 0x75688 = RPM breakpoints 750..9000]) = cell RPM breakpoint; reads flag_a + (cell-1)*2 / cell*2 / (cell+1)*2 + (DAT_ffffb660&1)*0x88 (pool 0x27270 = 0xffff8548) and sets DAT_ffffb6c6 = 1 only if the cell flag is set and a learned neighbour cell covers the current RPM (DAT_ffffb8f0). Called from 0x287aa."),
    ("000276ec", "e2ram_learned_table_cell_learn", "high",
     "If DAT_ffffba04!=0 && DAT_ffffba06==0 && DAT_ffffb8f0-100.0 <= engine_speed_rpm_ffffb548 < DAT_ffffb8f0+100.0 (100.0 = float pool 0x755d0): bumps counter DAT_ffffb8f4[bank*0x44+cell] (pool 0x277f0) and stores DAT_ffffba2c into live cell DAT_ffffb6cc[bank*0x44+cell] (pool 0x277f8), first time directly, later via rx8_first_order_filter k=0.031 (pool 0x755d4), eps 1e-5 (pool 0x277fc); bank = DAT_ffffb660&1, cell = DAT_ffffb6c4. Called from 0x287aa."),
    ("00027808", "e2ram_learned_table_ram_persist", "high",
     "Every 0xb ticks (DAT_ffffba04, pool 0x2791c): for 2 banks x 0x44 cells, if counter DAT_ffffb8f4[bank*0x44+cell] (pool 0x27928) > 0x1d: flag==0 -> copy live float DAT_ffffb6cc (pool 0x2792c) into value cell 0xffff8108+cell*8+bank*0x220 (pool 0x27938) and set flag 0xffff8548+cell*2+bank*0x88 = 1 (pool 0x27934); else filter the stored value toward the live one (rx8_first_order_filter 0x3db54, k=0.125, eps 1e-5 pool 0x27930). Then calls 0x27eec for cells 0..2 ((0x7>>cell)&1, pool 0x27a20). Called from 0x288be."),
    ("00027eec", "e2ram_learned_table_flag_mirror", "medium",
     "For bank 0..1 (mov #0x2 loop) and j 0..2 (mov #0x3 loop): copies the 2-byte flag cell at flag_a+param*0x88+param*2 to flag_a+param*0x88+(param+0x11*(j+1))*2 (bases pools 0x27fa4 = 0xffff8108 / 0x27fa8 = 0xffff8548, stride 0x11 via rx8_add_u8_saturate 0x2478 pool 0x27fac); mirrors learned flags from cell p to p+0x11/+0x22/+0x33 within each rotor bank. Called from 0x27808."),
    ("00028198", "e2ram_learned_table_apply", "high",
     "Reads the learned value for cell DAT_ffffb6c4: 0xffff8108+cell*8 (pool 0x282b8) when DAT_ffffb660&1==0, else +0x220 (value_neg 0xffff8328) -> DAT_ffffba64+4*parity; interpolates between adjacent RPM cells via 0x28484 using the tbl 0x6a6a0 axis/data arrays; computes DAT_ffffba2c = (DAT_ffffb668 - (DAT_ffffb680-DAT_ffffb668)/6.0) - DAT_ffffb664 (sector-speed ring copies from 0x26940) and DAT_ffffba30 = DAT_ffffba2c - learned_value. Called from 0x287aa."),
    ("00028484", "e2ram_learned_table_cell_read", "high",
     "Fetches two neighbouring learned floats: base 0xffff8108 (pool 0x2850c) + bank*0x220 (mov.w pool 0x284f6) + cell*8, via ref_readValue_float_DEFAULTVAL_ADDRESS 0x3dc22 (pool 0x28508); returns them for RPM interpolation. Called from 0x28198."),
    ("0002837c", "e2ram_learned_table_correction_filter", "medium",
     "Per rotor bank (DAT_ffffb660&1): if DAT_ffffb6c6==1, filters DAT_ffffba30 into DAT_ffffba34 / 0xffffba38 (rx8_first_order_filter k=0.125, eps 1e-5), else 0; DAT_ffffba3c = bank value, DAT_ffffba40 = max(0, DAT_ffffba3c). Called from 0x287aa."),
]

RAM = [
    # address, alias, type, reader, evidence
    ("ffff8000", "eeprom_mirror_magic", "uint16", "0000d408",
     "Firmware-written magic of the E2 window 0xffff8000-0xffff80ff: 0xd44c writes 0xaa55, 0xd408 checks it and rewrites 0x55aa (pools 0xd4f4/0xd4ea, base 0xd4f0). Window holds 8-byte checksummed cells (float +0, u16 cksum +4/+6 = ~(lo16+hi16)) via 0x3dc22/0x3dcd0; 241 pc-relative literal refs land in 0xffff8000-0xffff80ff."),
    ("ffff8108", "e2ram_learned_table_value_pos", "float[68]", "00027b8e",
     "Learned-table decoded float cells (+value = -63 + raw*0.5) from chip pairs 0x20+2i, written by 0x27b8e/0x279d8; cleared in 2x0x44 pattern by 0x27024."),
    ("ffff8328", "e2ram_learned_table_value_neg", "float[68]", "00027b8e",
     "Negated copies of the learned-table floats (0xffff8108 mirrored at -value), written by 0x27b8e."),
    ("ffff8548", "e2ram_learned_table_flag_a", "uint8[136]", "00027b8e",
     "Learned-table flag bytes (chip 0x21+2i, 0xff->0) from 0x27b8e."),
    ("ffff85d0", "e2ram_learned_table_flag_b", "uint8[136]", "00027b8e",
     "Second flag array (0xffff8548+0x88), written by 0x27b8e/0x27024."),
    ("ffffb6c4", "e2ram_learned_table_cell_index", "uint16", "0002711a",
     "Current learned-table cell = rpm_cell(0..16) + 17*load_band(0..3), computed by 0x2711a from engine_speed_rpm_ffffb548 (tbl 0x6a694) and engine_load_ffffc0b4 (bands 0.4/0.65/3.0). Consumed by 0x271b0/0x276ec/0x28198."),
    ("ffffb660", "sector_parity_bank", "uint16", "00026982",
     "DAT_ffffb660 = DAT_ffffa3b0 = ATUII sector index 0..5 (set in the CMI10B sector ISR); &1 selects the rotor bank in the learned table (0x271b0/0x276ec/0x28198): bank 0 reads value_pos 0xffff8108, bank 1 reads value_neg 0xffff8328."),
    ("ffffb6cc", "e2ram_learned_table_live_value", "float[2][68]", "000276ec",
     "Live (RAM-only) learned values per rotor bank x cell, written by 0x276ec from DAT_ffffba2c when |rpm - cell breakpoint| <= 100; copied into the chip-backed cells by 0x27808 once counter DAT_ffffb8f4 > 0x1d."),
    ("ffffb8f4", "e2ram_learned_table_live_counter", "uint16[2][68]", "000276ec",
     "Per bank x cell learn counters bumped by 0x276ec; 0x27808 persists the live cell into the learned table when the counter exceeds 0x1d."),
    ("ffffba2c", "e2ram_learned_correction_value", "float", "00028198",
     "Learn value computed by 0x28198 = (DAT_ffffb668 - (DAT_ffffb680-DAT_ffffb668)/6.0) - DAT_ffffb664, a sector-speed-ring deviation term (ring 0xffffa390..0xffffa3ac copied by 0x26940); learned into the table cell by 0x276ec."),
]

LOOKUP = []

# Per-index meaning of the 34 chip pairs 0x20-0x63 (pair i = value byte 0x20+2i,
# flag byte 0x21+2i). Index = rpm_cell + 17*load_band; only load bands 0-1
# (cells 0..33) are persisted to the chip; bands 2-3 (cells 34..67) are RAM-only.
# RPM breakpoints from tbl 0x6a6a0 data array 0x75688 (750..9000 step 500);
# load thresholds from float pools 0x755a4/0x755a8/0x755ac (0.4/0.65/3.0).
LOAD_BANDS = [("< 0.4", 0x00), ("0.4 - 0.65", 0x11), ("0.65 - 3.0", 0x22), (">= 3.0", 0x33)]
# RPM breakpoints of the 17 cells, tbl 0x6a6a0 data array 0x75688 (ROM-verified)
RPM_BP = [750, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500,
          6000, 6500, 7000, 7500, 8000, 8500, 9000]
PAIRS = [
    {
        "index": i,
        "chip": "0x%02x-0x%02x" % (0x20 + 2 * i, 0x21 + 2 * i),
        "rpm_cell": i % 17,
        "rpm_breakpoint": RPM_BP[i % 17],
        "load_band": i // 17,
        "load_range": LOAD_BANDS[i // 17][0],
        "value_ram_pos": "0xffff8108+0x%x" % (8 * i),
        "value_ram_neg": "0xffff8328+0x%x" % (8 * i),
        "flag_ram": "0xffff8548+0x%x / 0xffff85d0+0x%x" % (2 * i, 2 * i),
        "meaning": "learned correction, RPM cell %d (%d rpm breakpoint), load band %d (%s); +value applied to even sectors (DAT_ffffb660&1==0), -value to odd sectors" % (i % 17, RPM_BP[i % 17], i // 17, LOAD_BANDS[i // 17][0]),
    }
    for i in range(34)
]

# chip-offset map (93C56 byte offsets), recorded in the labels JSON
OFFSETS = {
    "0x00-0x01": ("eeprom_device_marker_word", "5a ff in both dumps; boot param index 0 len 4 -> 0xffffc26c (0x3599c)"),
    "0x02-0x09": ("eeprom_immobilizer_secret_key", "8 B per-ECU; device words 0x6010000-0x6040000 in 0x375c0; RX8 d3 d7 1a ef 41 3d 15 00"),
    "0x0a-0x0b": ("eeprom_immobilizer_status_word", "01 ff both dumps; word 0x6050000 in 0x375c0"),
    "0x0c-0x15": ("eeprom_config_param_bytes", "param indices 0xc-0x14 (0x3599c/0x35a8c); identical in both dumps"),
    "0x16-0x19": ("eeprom_immobilizer_code_id", "per-ECU; words 0x60b0000/0x60c0000 in 0x375c0; RX8 8d fd 47 da"),
    "0x1a-0x1f": ("eeprom_param_block_tail", "indices 0x1a-0x1e; bulk boot read 0x35956 (0,0x20)"),
    "0x20-0x63": ("e2ram_learned_correction_table", "34 x (u8 value, u8 flag); bulk 0x20 len 0x44 by 0x27b8e, value=-63+raw*0.5 (pools 0x27c84/0x27c80), save 0x279d8"),
    "0x64-0x6d": ("eeprom_ecu_id_string", "7 ASCII chars at 0x64-66,0x68,0x6a-6b,0x6c; RX8 '13H'+'6'+'020'; 0x55b18/0x5e664/0x5b644"),
    "0x6e-0x76": ("eeprom_field_6e", "9 B UDS-served (0x5b704); erased in both dumps"),
    "0x78-0x79": ("eeprom_field_78", "2 B written by 0x5e8a4 (shadow write 0x78, flush 0x378dc(0x78,2))"),
    "0x7a-0x7b": ("eeprom_field_7a", "2 B; bulk (0x7a,2) in 0x4b5b6 -> 0xffffce30"),
    "0x80-0x90": ("eeprom_vin", "17 ASCII; upper half 0x80-0xff UDS dump 0x5b5d4; RX8 'JM1FE173940102548'"),
    "0x95": ("eeprom_tire_size_marker", "'*' 0x2a both dumps; 0x543e4: '*' -> default tire size"),
    "0x9a-0x9b": ("eeprom_tire_revolutions_per_mile", "u16 BE; 0x5de74; 0x030d = 781 both dumps"),
    "0x9f": ("eeprom_config_bits", "bit0 read by 0x5e748; RX8 fe, SE3P ff"),
    "0xa0-0xfb": ("eeprom_erased_reserve", "all ff in both dumps; bulk-covered by 0x5b482 (0x64,0x9c)"),
    "0xfc-0xfd": ("eeprom_tail_id_u16", "per-ECU (RX8 ff 0c, SE3P 5f 41); no ROM consumer this pass"),
    "0xfe": ("eeprom_tail_erased", "ff both dumps"),
    "0xff": ("eeprom_tail_marker", "0x30 ('0') both dumps"),
}


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
        'pass': BASIS,
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1) + upstream dumps Data_binaries/RX8_93c56_ECU_IC420_Read.bin (SHA-256 64b13ddf353a06976729114179204f56b7a2869ea891f3f9d9400a2a56d205e3) and se3p_ecm_eeprom.bin (d7f4bb0a289f086610d8a9aafac58f6329b96c5be96ec75f7aef7418cf77c264). Report: eeprom_content_map_report.md.',
        'eeprom_offsets': {k: {'alias': v[0], 'evidence': v[1]} for k, v in OFFSETS.items()},
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'learned_table_pairs': {
            'format': '34 x (u8 value, u8 flag) at chip 0x20-0x63; value = -63 + raw*0.5; flag 0xff -> 0 (not learned), 1 = learned',
            'index': 'cell = rpm_cell + 17*load_band; rpm_cell = lookup(engine_speed_rpm, tbl 0x6a694) 0..16; load_band from engine_load: <0.4 -> 0, <0.65 -> 1, <3.0 -> 2, else 3 (0x2711a); only bands 0-1 (pairs 0..33) are chip-persisted, bands 2-3 live in RAM cells 34..67 only',
            'rotor': 'pair i feeds both rotor banks: +value at 0xffff8108+8i (even sector parity, DAT_ffffb660&1==0) and -value at 0xffff8328+8i (odd parity); flags at 0xffff8548+2i and 0xffff85d0+2i (0x27b8e load / 0x279d8 save)',
            'pairs': PAIRS,
        },
        'rom_unchanged': True,
        'ghidra_database_updated': False,
    }
    (b / 'metadata/eeprom_content_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
