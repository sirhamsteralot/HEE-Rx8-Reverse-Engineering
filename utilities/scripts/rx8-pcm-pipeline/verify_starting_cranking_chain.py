#!/usr/bin/env python3
"""Verify the engine-start / cranking chain against the raw ROM bytes (rule-7 checks).

Re-reads every literal-pool word, instruction word, ROM float/threshold and
table descriptor cited by

  * docs/subsystem-logic/starting_cranking_report.md
  * data/labels/60E15120_N3J1E/starting_cranking_labels.json

and writes the evidence log

  docs/investigations/60E15120_N3J1E/reviews/starting_cranking/rawbin_reverify_log.txt

Usage (from the repo root):
  python utilities/scripts/rx8-pcm-pipeline/verify_starting_cranking_chain.py           # check only
  python utilities/scripts/rx8-pcm-pipeline/verify_starting_cranking_chain.py --write   # refresh the log

Pool operands are the absolute pool addresses the disassembler prints for
``mov.l @(0xPOOL,pc),rN`` / ``mov.w @(0xPOOL,pc),rN``; a 16-bit pool holds the
sign-extended low half of a RAM address (0xb548 -> 0xffffb548), a 32-bit pool
holds a full address, a ROM float or a ROM constant.
"""
from __future__ import annotations

import hashlib
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
ROM = (ROOT / 'submodules' / 'Mazda_RX8_PCM_ReverseEngineering' / 'Stock_ROMs'
       / '60E15120_N3J1E.bin')
LOG = (ROOT / 'docs' / 'investigations' / '60E15120_N3J1E' / 'reviews'
       / 'starting_cranking' / 'rawbin_reverify_log.txt')

ROM_SHA256 = 'a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1'

# (kind, address-or-value, expected, description)
#   w16 / w32      raw word at an address
#   f32            IEEE-754 single at an address
#   f32b           bit pattern of the IEEE-754 single at an address
#   bytes          hex string of a byte run at an address
#   ru16e          ROM u16 at an address (region constant used as a word)
CHECKS: list[tuple[str, object, object, str]] = [
    # --- 0x1481c ref_getEngineCrankingState__: cranking -> running state machine ---
    ('w16', 0x14882, 0xA79C, '0x1481c output-cell pool 0x14882 = 0xa79c (-> 0xffffa79c)'),
    ('w16', 0x14884, 0xB548, '0x1481c rpm pool 0x14884 = 0xb548 (-> 0xffffb548)'),
    ('w16', 0x14886, 0x00FF, '0x1481c byte-decrement pool 0x14886 = 0x00ff (-1 in a byte add)'),
    ('w16', 0x14888, 0xA98C, '0x1481c coolant pool 0x14888 = 0xa98c (-> 0xffffa98c)'),
    ('w32', 0x1488C, 0xFFFFA79E, '0x1481c state-cell pool 0x1488c = 0xffffa79e'),
    ('w32', 0x14890, 0xFFFFA79D, '0x1481c blanking-counter pool 0x14890 = 0xffffa79d'),
    ('w32', 0x14894, 0x000757A0, '0x1481c on-threshold pool 0x14894 = 0x757a0'),
    ('w32', 0x14898, 0x0006A6CC, '0x1481c blanking-table pool 0x14898 = 0x6a6cc'),
    ('w32', 0x1489C, 0x000020AC, '0x1481c table-lookup pool 0x1489c = 0x20ac'),
    ('w32', 0x148A0, 0x0007579C, '0x1481c off-threshold pool 0x148a0 = 0x7579c'),
    ('f32', 0x757A0, 500.0, '0x1481c on threshold f32 0x757a0 = 500.0 rpm'),
    ('f32', 0x7579C, 300.0, '0x1481c off threshold f32 0x7579c = 300.0 rpm'),
    ('w16', 0x1482A, 0x4215, '0x1481c cmp/pl on the state cell at 0x1482a'),
    ('w16', 0x14832, 0x342C, '0x1481c add r2,r4 (byte -1) at 0x14832'),
    # blanking table 0x6a6cc (Table 2D - 334) -> u8 count per coolant cell
    ('bytes', 0x6A6CC, '00060000 000757c8 000757e0 000d0800',
     '0x6a6cc descriptor: n=6 type=0 axis 0x757c8 data 0x757e0'),
    ('f32', 0x757C8, -30.0, '0x6a6cc axis[0] f32 0x757c8 = -30.0 degC'),
    ('f32', 0x757D8, 10.0, '0x6a6cc axis[4] f32 0x757d8 = 10.0 degC'),
    ('bytes', 0x757E0, '040404040404', '0x6a6cc data[0..5] = 4 counts (all cells)'),

    # --- 0xe274 engine_running_from_rpm: rpm hysteresis 250/500 -> 0xffffa428 ---
    ('w16', 0xE29C, 0xB548, '0xe274 rpm pool 0xe29c = 0xb548 (-> 0xffffb548)'),
    ('w16', 0xE29E, 0xA428, '0xe274 flag pool 0xe29e = 0xa428 (-> 0xffffa428)'),
    ('w32', 0xE2A0, 0x0006C190, '0xe274 off-threshold pool 0xe2a0 = 0x6c190'),
    ('w32', 0xE2A4, 0x0006C194, '0xe274 on-threshold pool 0xe2a4 = 0x6c194'),
    ('f32', 0x6C190, 250.0, '0xe274 off threshold f32 0x6c190 = 250.0 rpm'),
    ('f32', 0x6C194, 500.0, '0xe274 on threshold f32 0x6c194 = 500.0 rpm'),

    # --- 0x1a51c closed-throttle dwell counter, 0x1a564 closed-throttle gate ------
    ('w16', 0x1A5BE, 0xA9BC, '0x1a564 throttle-demand pool 0x1a5be = 0xa9bc (-> 0xffffa9bc)'),
    ('w32', 0x1A5C4, 0x0006F184, '0x1a564 open-throttle threshold pool 0x1a5c4 = 0x6f184'),
    ('w32', 0x1A5C8, 0x0006F188, '0x1a564 hysteresis-step pool 0x1a5c8 = 0x6f188'),
    ('w32', 0x1A5D4, 0xFFFFAA65, '0x1a564 latched-flag pool 0x1a5d4 = 0xffffaa65'),
    ('w32', 0x1A5C0, 0x0006F180, '0x1a564 dwell-threshold pool 0x1a5c0 = 0x6f180'),
    ('w16', 0x1A5B8, 0xAA60, '0x1a564 dwell-counter pool 0x1a5b8 = 0xaa60 (-> 0xffffaa60)'),
    ('w16', 0x1A5BA, 0xAA63, '0x1a564 closed-throttle flag pool 0x1a5ba = 0xaa63'),
    ('w16', 0x1A5BC, 0xAA62, '0x1a564 output flag pool 0x1a5bc = 0xaa62'),
    ('f32', 0x6F184, 2.5, '0x1a564 open-throttle threshold f32 0x6f184 = 2.5 %'),
    ('f32', 0x6F188, 0.5, '0x1a564 hysteresis step f32 0x6f188 = 0.5 %'),
    ('ru16e', 0x6F180, 0x0013, '0x1a564 dwell threshold ROM u16 0x6f180 = 0x13 (19 counts)'),
    ('w16', 0x1A59E, 0x3122, '0x1a564 cmp/hs on the 16-bit dwell counter at 0x1a59e'),

    # --- 0x532d0 cranking-in-progress flag --------------------------------------
    ('w16', 0x53364, 0x86E8, '0x532d0 dwell-counter pool 0x53364 = 0x86e8 (-> 0xffff86e8)'),
    ('w16', 0x53366, 0xBBB4, '0x532d0 vehicle-speed pool 0x53366 = 0xbbb4 (-> 0xffffbbb4)'),
    ('w16', 0x53368, 0xD15C, '0x532d0 output pool 0x53368 = 0xd15c (-> 0xffffd15c)'),
    ('w16', 0x5336A, 0xAA62, '0x532d0 gate pool 0x5336a = 0xaa62 (-> 0xffffaa62)'),
    ('w16', 0x5336C, 0xA428, '0x532d0 gate pool 0x5336c = 0xa428 (-> 0xffffa428)'),
    ('w32', 0x53374, 0x0003DC80, '0x532d0 tail-jump pool 0x53374 = 0x3dc80 (u16 store)'),
    ('w32', 0x53378, 0x0003DB94, '0x532d0 read pool 0x53378 = 0x3db94 (u16 read)'),
    ('f32b', 0x5337C, 0x3FF126E9, '0x532d0 speed band f32 0x5337c = 1.8859 (tolerance)'),
    ('w32', 0x53380, 0x00002440, '0x532d0 band test pool 0x53380 = 0x2440'),
    ('w32', 0x53384, 0x0007DC9E, '0x532d0 count-limit pool 0x53384 = 0x7dc9e'),
    ('w32', 0x53388, 0x0007DC9C, '0x532d0 extra-gate pool 0x53388 = 0x7dc9c'),
    ('w32', 0x5338C, 0x00002460, '0x532d0 saturating-add pool 0x5338c = 0x2460'),
    ('ru16e', 0x7DC9E, 0x00EA, '0x532d0 count limit ROM u16 0x7dc9e = 0x00ea (234)'),
    ('w16', 0x532FE, 0x8801, '0x532d0 cmp/eq 0x1 (closed-throttle flag) at 0x532fe'),
    ('w16', 0x5330A, 0x8801, '0x532d0 cmp/eq 0x1 (engine running) at 0x5330a'),

    # --- starter-relay output pair: condition -> flag -> PD7 pin ----------------
    ('w16', 0x4EDCE, 0xCFBE, '0x4ed3c first gate pool 0x4edce = 0xcfbe (-> 0xffffcfbe)'),
    ('w16', 0x4EDD0, 0xCFBC, '0x4ed3c output pool 0x4edd0 = 0xcfbc (-> 0xffffcfbc)'),
    ('w16', 0x4EDD2, 0xCFC1, '0x4ed3c clear gate pool 0x4edd2 = 0xcfc1 (-> 0xffffcfc1)'),
    ('w16', 0x4EDD4, 0xCFAA, '0x4ed3c u16 term pool 0x4edd4 = 0xcfaa (-> 0xffffcfaa)'),
    ('w16', 0x4EDD6, 0xCFA6, '0x4ed3c u16 term pool 0x4edd6 = 0xcfa6 (-> 0xffffcfa6)'),
    ('w16', 0x4EDD8, 0xD15C, '0x4ed3c cranking term pool 0x4edd8 = 0xd15c (-> 0xffffd15c)'),
    ('w16', 0x4EFB4, 0xCFBD, '0x4ef86 gate pool 0x4efb4 = 0xcfbd (-> 0xffffcfbd)'),
    ('w16', 0x4EFB6, 0xCFB6, '0x4ef86 PD7-flag pool 0x4efb6 = 0xcfb6 (-> 0xffffcfb6)'),
    ('w16', 0x4EFB8, 0xCFBC, '0x4ef86 source pool 0x4efb8 = 0xcfbc (-> 0xffffcfbc)'),
    ('w16', 0x3A1AA, 0xCFB6, '0x3a0ec PD7 source pool 0x3a1aa = 0xcfb6 (-> 0xffffcfb6)'),
    ('w16', 0x3A1AC, 0x0080, '0x3a0ec PD7 mask pool 0x3a1ac = 0x0080'),
    ('w16', 0x3A1AE, 0xF746, '0x3a0ec PDDR pool 0x3a1ae = 0xf746 (-> 0xfffff746)'),
    ('w16', 0x3A1B0, 0xCFB7, '0x3a0ec PE0 source pool 0x3a1b0 = 0xcfb7 (-> 0xffffcfb7)'),
    ('w16', 0x3A1B2, 0xF754, '0x3a0ec PEDR pool 0x3a1b2 = 0xf754 (-> 0xfffff754)'),
    ('w32', 0x3A1BC, 0x00004BBC, '0x3a0ec port-bit helper pool 0x3a1bc = 0x4bbc'),

    # --- cranking fuel: adder, arbitration, pulse-width and decay tables --------
    ('w16', 0x306AC, 0xBE94, '0x30678 adder pool 0x306ac = 0xbe94 (-> 0xffffbe94)'),
    ('w16', 0x306B2, 0xA428, '0x30678 running-gate pool 0x306b2 = 0xa428 (-> 0xffffa428)'),
    ('w16', 0x306B4, 0xA42C, '0x30678 injector-gate pool 0x306b4 = 0xa42c (-> 0xffffa42c)'),
    ('w16', 0x306B6, 0xCE32, '0x30678 io-status gate pool 0x306b6 = 0xce32 (-> 0xffffce32)'),
    ('w16', 0x306B8, 0xBE58, '0x30678 cranking-pulse pool 0x306b8 = 0xbe58 (-> 0xffffbe58)'),
    ('w16', 0x306A2, 0xF230, '0x30678 fadd fr3,fr2 at 0x306a2'),
    ('w16', 0x306A4, 0xF42A, '0x30678 write back to the adder cell at 0x306a4'),
    ('w16', 0x2FF4C, 0xA428, '0x2fea8 running-gate pool 0x2ff4c = 0xa428 (-> 0xffffa428)'),
    ('w16', 0x2FF4E, 0xBE3C, '0x2fea8 decay-counter pool 0x2ff4e = 0xbe3c (-> 0xffffbe3c)'),
    ('w16', 0x2FF50, 0xA98C, '0x2fea8 coolant pool 0x2ff50 = 0xa98c (-> 0xffffa98c)'),
    ('w16', 0x2FF52, 0x00FF, '0x2fea8 byte-decrement pool 0x2ff52 = 0x00ff'),
    ('w32', 0x2FF70, 0x0006BAB0, '0x2fea8 decay-table pool 0x2ff70 = 0x6bab0'),
    ('w32', 0x2FF74, 0x000020AC, '0x2fea8 table-lookup pool 0x2ff74 = 0x20ac'),
    ('w16', 0x2FED8, 0x312C, '0x2fea8 add r2,r1 (r2 = 0x00ff) at 0x2fed8'),
    ('w16', 0x30312, 0xBE68, '0x30228 throttle-factor pool 0x30312 = 0xbe68 (-> 0xffffbe68)'),
    ('w16', 0x30314, 0xBE7C, '0x30228 coolant-factor pool 0x30314 = 0xbe7c (-> 0xffffbe7c)'),
    ('w16', 0x30316, 0xBE80, '0x30228 baro-factor pool 0x30316 = 0xbe80 (-> 0xffffbe80)'),
    ('w16', 0x30318, 0xBE84, '0x30228 running-factor pool 0x30318 = 0xbe84 (-> 0xffffbe84)'),
    ('w16', 0x3031A, 0xBE88, '0x30228 pulse-width pool 0x3031a = 0xbe88 (-> 0xffffbe88)'),
    ('w32', 0x3032C, 0x00077F58, '0x30228 unity-factor pool 0x3032c = 0x77f58'),
    ('f32', 0x77F58, 1.0, '0x30228 unity factor f32 0x77f58 = 1.0'),
    ('w32', 0x30330, 0x0006AB48, '0x30274 pulse-width table pool 0x30330 = 0x6ab48'),
    ('w32', 0x30334, 0x00002068, '0x30274 scaled-lookup pool 0x30334 = 0x2068'),
    ('w32', 0x30338, 0x0006AB5C, '0x30274 second table pool 0x30338 = 0x6ab5c'),

    # --- flood cut: 0x303a8 throttle factor + table 0x6ab00 ---------------------
    ('w16', 0x3042C, 0xA428, '0x303a8 running-gate pool 0x3042c = 0xa428 (-> 0xffffa428)'),
    ('w16', 0x3042E, 0xA98C, '0x303a8 coolant pool 0x3042e = 0xa98c (-> 0xffffa98c)'),
    ('w16', 0x30430, 0xC5E6, '0x303a8 bypass-flag pool 0x30430 = 0xc5e6 (-> 0xffffc5e6)'),
    ('w16', 0x30432, 0xB423, '0x303a8 bypass-flag pool 0x30432 = 0xb423 (-> 0xffffb423)'),
    ('w16', 0x30434, 0xBE68, '0x303a8 output pool 0x30434 = 0xbe68 (-> 0xffffbe68)'),
    ('w16', 0x30436, 0xAD44, '0x303a8 throttle-position pool 0x30436 = 0xad44 (-> 0xffffad44)'),
    ('w32', 0x30458, 0x00077F6C, '0x303a8 hot-coolant pool 0x30458 = 0x77f6c'),
    ('w32', 0x3045C, 0x0006AB00, '0x303a8 flood-factor table pool 0x3045c = 0x6ab00'),
    ('w32', 0x30460, 0x00002068, '0x303a8 scaled-lookup pool 0x30460 = 0x2068'),
    ('f32', 0x77F6C, 150.0, '0x303a8 hot-coolant threshold f32 0x77f6c = 150.0 degC'),
    ('bytes', 0x6AB00, '00060400 00078008 00078020 3c000000',
     '0x6ab00 descriptor: n=6 type=4 axis 0x78008 data 0x78020 scale 1/128'),
    ('f32b', 0x6AB0C, 0x3C000000, '0x6ab00 scale f32 0x6ab0c = 0.0078125 (1/128)'),
    ('f32b', 0x6AB10, 0x00000000, '0x6ab00 offset f32 0x6ab10 = 0.0'),
    ('f32', 0x78008, 21.0210209, '0x6ab00 axis[0] f32 0x78008 = 21.021'),
    ('f32', 0x7800C, 22.5225201, '0x6ab00 axis[1] f32 0x7800c = 22.523'),
    ('bytes', 0x78020, '8000000000', '0x6ab00 data[0..4] = 128,0,0,0,0 (1.0 then 0.0)'),

    # --- cranking pulse width / decay tables ------------------------------------
    ('bytes', 0x6AB48, '000d0800 000780c8 000780fc 40a00000',
     '0x6ab48 descriptor: n=13 type=8 axis 0x780c8 data 0x780fc scale 5.0'),
    ('f32', 0x6AB54, 5.0, '0x6ab48 scale f32 0x6ab54 = 5.0 (microseconds per count)'),
    ('f32', 0x780C8, -30.0, '0x6ab48 axis[0] f32 0x780c8 = -30.0 degC'),
    ('bytes', 0x780FC, '60ad5e8e57cf468f',
     '0x6ab48 data[0..7] = 0x60ad 0x5e8e 0x57cf 0x468f ... (u16 counts)'),
    ('bytes', 0x6BAB0, '00090000 0007c968 0007c98c 00090000',
     '0x6bab0 descriptor: n=9 type=0 axis 0x7c968 data 0x7c98c'),
    ('f32', 0x7C968, -40.0, '0x6bab0 axis[0] f32 0x7c968 = -40.0 degC'),
    ('bytes', 0x7C98C, '030300000000000000',
     '0x6bab0 data[0..8] = 3,3,0,0,0,0,0,0,0 counts'),

    # --- cranking / closed-throttle timing chain --------------------------------
    ('w16', 0x43A1C, 0xCA9C, '0x43934 filtered-output pool 0x43a1c = 0xca9c (-> 0xffffca9c)'),
    ('w16', 0x43A20, 0xB53C, '0x43934 latch-source pool 0x43a20 = 0xb53c (-> 0xffffb53c)'),
    ('w16', 0x43A24, 0xA98C, '0x43934 coolant pool 0x43a24 = 0xa98c (-> 0xffffa98c)'),
    ('w32', 0x43A28, 0xFFFFCAA4, '0x43934 raw-value pool 0x43a28 = 0xffffcaa4'),
    ('w32', 0x43A2C, 0xFFFFCAA8, '0x439b2 raw-value pool 0x43a2c = 0xffffcaa8'),
    ('w32', 0x43A30, 0x0006B630, '0x43934 table pool 0x43a30 = 0x6b630'),
    ('w32', 0x43A34, 0x00002068, '0x43934 scaled-lookup pool 0x43a34 = 0x2068'),
    ('w32', 0x43A38, 0xFFFFCAAC, '0x43934 latch-cell pool 0x43a38 = 0xffffcaac'),
    ('w32', 0x43A3C, 0x0007ABFC, '0x43934 first-edge enable pool 0x43a3c = 0x7abfc'),
    ('w32', 0x43A44, 0x0003DB24, '0x43934 divide pool 0x43a44 = 0x3db24'),
    ('w32', 0x43A48, 0x3727C5AC, '0x43934 snap constant pool 0x43a48 = 1e-5'),
    ('w32', 0x43A4C, 0x0007AC00, '0x43934 filter coefficient pool 0x43a4c = 0x7ac00'),
    ('w32', 0x43A50, 0x000023B0, '0x43934 filter pool 0x43a50 = 0x23b0'),
    ('f32', 0x7ABFC, 1.0, '0x43934 first-edge enable f32 0x7abfc = 1.0'),
    ('f32', 0x7AC00, 1.0, '0x43934 filter coefficient f32 0x7ac00 = 1.0'),
    ('w32', 0x43A54, 0x0006B644, '0x439b2 table pool 0x43a54 = 0x6b644'),
    ('w32', 0x43A58, 0xFFFFCAAD, '0x439b2 latch-cell pool 0x43a58 = 0xffffcaad'),
    ('w32', 0x43A5C, 0x0007AC04, '0x439b2 first-edge enable pool 0x43a5c = 0x7ac04'),
    ('w32', 0x43A60, 0x0007AC08, '0x439b2 filter coefficient pool 0x43a60 = 0x7ac08'),
    ('f32', 0x7AC04, 1.0, '0x439b2 first-edge enable f32 0x7ac04 = 1.0'),
    ('f32', 0x7AC08, 1.0, '0x439b2 filter coefficient f32 0x7ac08 = 1.0'),
    ('bytes', 0x6B630, '00090400 0007ac0c 0007ac30 3f000000',
     '0x6b630 descriptor: n=9 type=4 axis 0x7ac0c data 0x7ac30 scale 0.5'),
    ('f32', 0x7AC0C, -40.0, '0x6b630 axis[0] f32 0x7ac0c = -40.0 degC'),
    ('bytes', 0x7AC30, '6e6e64646e78828282',
     '0x6b630 data[0..8] = 110,110,100,100,110,120,130,130,130 (off-throttle leading)'),
    ('bytes', 0x6B644, '00090400 0007ac3c 0007ac60 3f000000',
     '0x6b644 descriptor: n=9 type=4 axis 0x7ac3c data 0x7ac60 scale 0.5'),
    ('bytes', 0x7AC60, '6e6e646464646464',
     '0x6b644 data[0..8] = 110,110,100,100,100,100,100,100,100'),
    ('bytes', 0x6AF2C, '000c0400 000794fc 0007952c 3f800000',
     '0x6af2c descriptor (XML leading cranking advance): n=12 type=4 data 0x7952c scale 1.0'),
    ('bytes', 0x7952C, '3232322828281e140a0101',
     '0x6af2c data[0..11] = 50,50,50,40,40,40,30,20,10,1,1,1'),
    ('bytes', 0x69208, '00090400 0006d8c0 0006d8e4 3f000000',
     '0x69208 descriptor (idle base timing, cranking branch): n=9 type=4 scale 0.5'),
    ('bytes', 0x6D8E4, '5050505050505050', '0x69208 data = 80 in every cell (0.0 deg)'),

    # --- timing fade: 0x123da leading blend -------------------------------------
    ('w16', 0x123FC, 0xB548, '0x123da rpm pool 0x123fc = 0xb548 (-> 0xffffb548)'),
    ('w16', 0x12412, 0xA7AC, '0x123da rpm-offset pool 0x12412 = 0xa7ac (-> 0xffffa7ac)'),
    ('w32', 0x1244C, 0x0006D778, '0x123da upper-threshold pool 0x1244c = 0x6d778'),
    ('w32', 0x12450, 0xFFFFA668, '0x123da latch-cell pool 0x12450 = 0xffffa668'),
    ('w32', 0x12544, 0x0006D77C, '0x123da hysteresis pool 0x12544 = 0x6d77c'),
    ('w32', 0x12548, 0xFFFFA644, '0x123da multiplier-cell pool 0x12548 = 0xffffa644'),
    ('w32', 0x1254C, 0xFFFFA668, '0x123da latch reread pool 0x1254c = 0xffffa668'),
    ('w32', 0x12550, 0x0006D764, '0x123da step pool 0x12550 = 0x6d764'),
    ('w32', 0x12554, 0x000023E4, '0x123da max pool 0x12554 = 0x23e4'),
    ('w32', 0x12558, 0x0006D768, '0x123da recovery-amount pool 0x12558 = 0x6d768'),
    ('w32', 0x1255C, 0x000023F4, '0x123da min pool 0x1255c = 0x23f4'),
    ('w32', 0x12560, 0xFFFFA640, '0x123da output-cell pool 0x12560 = 0xffffa640'),
    ('f32', 0x6D764, 0.05, '0x123da step f32 0x6d764 = 0.05'),
    ('f32', 0x6D768, 1.0, '0x123da recovery amount f32 0x6d768 = 1.0'),
    ('f32', 0x6D778, 10000.0, '0x123da upper threshold f32 0x6d778 = 10000.0 rpm'),
    ('f32', 0x6D77C, 100.0, '0x123da hysteresis f32 0x6d77c = 100.0 rpm'),

    # --- idle base timing select: 0x14100 ---------------------------------------
    ('w16', 0x14156, 0xA98C, '0x14100 coolant pool 0x14156 = 0xa98c (-> 0xffffa98c)'),
    ('w16', 0x14158, 0xA780, '0x14100 output pool 0x14158 = 0xa780 (-> 0xffffa780)'),
    ('w32', 0x14164, 0x00069208, '0x14100 cranking-branch table pool 0x14164 = 0x69208'),
    ('w32', 0x14168, 0x0006D8BC, '0x14100 hot-coolant pool 0x14168 = 0x6d8bc'),
    ('w32', 0x1416C, 0x0006D8B8, '0x14100 load threshold pool 0x1416c = 0x6d8b8'),
    ('w32', 0x14170, 0x0006921C, '0x14100 crold branch table pool 0x14170 = 0x6921c'),
    ('w32', 0x14174, 0x00069230, '0x14100 warm branch table pool 0x14174 = 0x69230'),
    ('f32', 0x6D8BC, 90.0, '0x14100 hot threshold f32 0x6d8bc = 90.0 degC'),
    ('f32', 0x6D8B8, 0.5, '0x14100 load threshold f32 0x6d8b8 = 0.5'),

    # --- execution structure: task table entry 6 and entry 11 -------------------
    ('w32', 0x4990 + 16 * 6, 0x04000200, 'task[6] record 0x49f0 [+0] = 0x04000200'),
    ('w32', 0x4990 + 16 * 6 + 4, 0xFFFF7438, 'task[6] record 0x49f4 [+4] context block'),
    ('w32', 0x4990 + 16 * 6 + 8, 0x0000661E, 'task[6] record 0x49f8 [+8] entry = 0x661e'),
    ('w32', 0x4990 + 16 * 6 + 12, 0x02000000, 'task[6] record 0x49fc [+12] reload credit = 2'),
    ('w32', 0x4990 + 16 * 11 + 8, 0x00006584, 'task[11] record 0x4a48 [+8] entry = 0x6584'),
    ('ru16e', 0x493C, 0x0013, 'task-table count ROM u16 0x493c = 0x13 (19 records)'),
]

KINDS = {'w16', 'w32', 'f32', 'f32b', 'bytes', 'ru16e'}


def read_checks(rom: bytes) -> list[tuple[bool, str]]:
    results: list[tuple[bool, str]] = []
    for kind, addr, expected, desc in CHECKS:
        assert kind in KINDS, kind
        if kind == 'bytes':
            want = expected.replace(' ', '')
            raw = rom[addr:addr + len(want) // 2]
            got = raw.hex()
            ok = got == want
            got_s, want_s = got, want
        elif kind == 'f32':
            got_v = struct.unpack('>f', rom[addr:addr + 4])[0]
            ok = abs(got_v - expected) <= abs(expected) * 1e-6 + 1e-9
            got_s, want_s = f'{got_v:g}', f'{expected:g}'
        else:
            nbytes = {'w16': 2, 'w32': 4, 'f32b': 4, 'ru16e': 2}[kind]
            raw = rom[addr:addr + nbytes]
            got_v = int.from_bytes(raw, 'big')
            ok = got_v == expected
            got_s = f'0x{got_v:0{nbytes * 2}x}'
            want_s = f'0x{expected:0{nbytes * 2}x}'
        mark = 'ok  ' if ok else 'FAIL'
        results.append((ok, f'{mark} {kind:5s} 0x{addr:05x} want {want_s} got {got_s}  {desc}'))
    return results


def main(argv: list[str]) -> int:
    rom = ROM.read_bytes()
    sha = hashlib.sha256(rom).hexdigest()
    lines = [f'ROM {ROM.name}', f'SHA-256 {sha}', f'checks {len(CHECKS)}', '']
    if sha != ROM_SHA256:
        lines.append(f'FAIL rom hash mismatch: expected {ROM_SHA256}')
        results = []
        failures = 1
    else:
        results = read_checks(rom)
        failures = sum(1 for ok, _ in results if not ok)
        lines.extend(text for _, text in results)
    lines += ['', f'result {"FAIL" if failures else "PASS"} ({len(results) - failures}/{len(results)} checks)']
    text = '\n'.join(lines) + '\n'
    if '--write' in argv:
        LOG.parent.mkdir(parents=True, exist_ok=True)
        LOG.write_text(text, encoding='utf-8')
        print(f'wrote {LOG.relative_to(ROOT)}')
    print(text)
    return 1 if failures else 0


if __name__ == '__main__':
    raise SystemExit(main(sys.argv[1:]))
