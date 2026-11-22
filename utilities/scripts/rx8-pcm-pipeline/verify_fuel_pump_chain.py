#!/usr/bin/env python3
"""Verify the fuel pump control chain against the raw ROM bytes (rule-7 checks).

Re-reads every literal-pool word, instruction word, ROM threshold/float and
peripheral symbol cited by

  * docs/subsystem-logic/fuel_pump_control_report.md
  * data/labels/60E15120_N3J1E/fuel_pump_control_labels.json

and writes the evidence log

  docs/investigations/60E15120_N3J1E/reviews/fuel_pump_control/rawbin_reverify_log.txt

Usage (from the repo root):
  python utilities/scripts/rx8-pcm-pipeline/verify_fuel_pump_chain.py           # check only
  python utilities/scripts/rx8-pcm-pipeline/verify_fuel_pump_chain.py --write   # refresh the log

Pool operands are the absolute pool addresses the disassembler prints for
``mov.l @(0xPOOL,pc),rN`` / ``mov.w @(0xPOOL,pc),rN``; a 16-bit pool holds the
sign-extended low half of a RAM address (0xbdd8 -> 0xffffbdd8).
"""
from __future__ import annotations

import csv
import hashlib
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
ROM = (ROOT / 'submodules' / 'Mazda_RX8_PCM_ReverseEngineering' / 'Stock_ROMs'
       / '60E15120_N3J1E.bin')
SYMBOLS = ROOT / 'reverse-engineered' / 'decompiled' / '60E15120_N3J1E' / 'symbols.tsv'
LOG = (ROOT / 'docs' / 'investigations' / '60E15120_N3J1E' / 'reviews'
       / 'fuel_pump_control' / 'rawbin_reverify_log.txt')

ROM_SHA256 = 'a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1'

# (kind, address-or-symbol, expected, description)
CHECKS: list[tuple[str, object, int | str, str]] = [
    # --- 0x2f890: direct PE2 drive -----------------------------------------
    ('w16', 0x2F92E, 0x00E0, '0x2f890 SR-mask word 0x2f92e = 0xe0'),
    ('w16', 0x2F930, 0xBDD8, '0x2f890 cell pool 0x2f930 = 0xbdd8 (-> 0xffffbdd8)'),
    ('w16', 0x2F932, 0xF754, '0x2f890 PEDR pool 0x2f932 = 0xf754 (-> 0xfffff754)'),
    ('w32', 0x2F938, 0x00002054, '0x2f890 lock helper pool 0x2f938 = 0x2054'),
    ('w32', 0x2F93C, 0x00004BBC, '0x2f890 bit helper pool 0x2f93c = 0x4bbc'),
    ('w32', 0x2F940, 0x00002064, '0x2f890 unlock helper pool 0x2f940 = 0x2064'),
    ('w16', 0x2F8A2, 0x8801, '0x2f890 cmp/eq 0x1,r0 at 0x2f8a2'),
    ('w16', 0x2F8B0, 0xE504, '0x2f890 mov #0x4,r5 (PE2 mask) at 0x2f8b0'),
    ('w16', 0x2F8B6, 0xE600, '0x2f890 clear-branch mov #0x0,r6 at 0x2f8b6'),
    # --- 0x2f8ce: gated PE2 + PE1 ------------------------------------------
    ('w32', 0x2F944, 0x0005C204, '0x2f8ce PE2 gate pool 0x2f944 = 0x5c204'),
    ('w16', 0x2F934, 0xBDBC, '0x2f8ce cell pool 0x2f934 = 0xbdbc (-> 0xffffbdbc)'),
    ('w16', 0x2F8EA, 0xE504, '0x2f8ce mov #0x4,r5 (PE2 mask) at 0x2f8ea'),
    ('w16', 0x2F912, 0xE502, '0x2f8ce mov #0x2,r5 (PE1 mask) at 0x2f912'),
    ('w16', 0x2F916, 0x8801, '0x2f8ce cmp/eq 0x1,r0 at 0x2f916'),
    # --- gates 0x5c204 / 0x5c2e4: diagnostic modes 5 and 7 -----------------
    ('w16', 0x5C298, 0x8805, '0x5c204 mode compare cmp/eq 0x5 at 0x5c298'),
    ('w16', 0x5C2A0, 0x8807, '0x5c204 mode compare cmp/eq 0x7 at 0x5c2a0'),
    ('w16', 0x5C378, 0x8805, '0x5c2e4 mode compare cmp/eq 0x5 at 0x5c378'),
    ('w16', 0x5C380, 0x8807, '0x5c2e4 mode compare cmp/eq 0x7 at 0x5c380'),
    # --- 0x2f948 / 0x2f98c / 0x2fcac: start-up prime + grace evaluation ----
    ('w32', 0x2F9A4, 0x0002FBF0, '0x2f948 callee pool 0x2f9a4 = 0x2fbf0'),
    ('w32', 0x2F9A8, 0x0002FBF8, '0x2f948 callee pool 0x2f9a8 = 0x2fbf8'),
    ('w32', 0x2F9AC, 0x0002F890, '0x2f948 tail-jump pool 0x2f9ac = 0x2f890'),
    ('w32', 0x2F9C8, 0x00003934, '0x2f948/0x2f98c SR-restore pool 0x2f9c8 = 0x3934'),
    ('w32', 0x2F9CC, 0x0002FCAC, '0x2f98c callee pool 0x2f9cc = 0x2fcac'),
    ('w32', 0x2F9B0, 0x00003920, '0x2f95c/0x2f98c SR-mask pool 0x2f9b0 = 0x3920'),
    ('w32', 0x2F9B4, 0x0002FC00, '0x2f95c callee pool 0x2f9b4 = 0x2fc00'),
    ('w32', 0x2F9B8, 0x0002F9D0, '0x2f95c callee pool 0x2f9b8 = 0x2f9d0'),
    ('w32', 0x2F9BC, 0x0002F9FC, '0x2f95c callee pool 0x2f9bc = 0x2f9fc'),
    ('w32', 0x2F9C0, 0x0002FB20, '0x2f95c callee pool 0x2f9c0 = 0x2fb20'),
    ('w32', 0x2F9C4, 0x0002F8CE, '0x2f95c tail-jump pool 0x2f9c4 = 0x2f8ce'),
    ('w32', 0x2FCDC, 0x00002460, '0x2fc00 saturating-increment helper pool 0x2fcdc = 0x2460'),
    ('w32', 0x2474, 0x0000FFFF, '0x2460 saturation limit at 0x2474 = 0xffff'),
    ('w16', 0x2FBF6, 0x2230, '0x2fbf0 store mov.b r3,@r2 at 0x2fbf6'),
    ('w16', 0x2FBFE, 0x2011, '0x2fbf8 store mov.w r1,@r0 at 0x2fbfe'),
    # --- 0x2fc00: request flag -------------------------------------------
    ('w16', 0x2FCCE, 0xBDD8, '0x2fc00 result-cell pool 0x2fcce = 0xbdd8'),
    ('w16', 0x2FCD0, 0xAA68, '0x2fc00 key-on pool 0x2fcd0 = 0xaa68'),
    ('w16', 0x2FCD2, 0xA42C, '0x2fc00 injectors-off pool 0x2fcd2 = 0xa42c'),
    ('w32', 0x2FCD4, 0x0000FFFF, '0x2fbf8 constant pool 0x2fcd4 = 0x0000ffff'),
    ('w32', 0x2FCD8, 0xFFFFBDDC, '0x2fc00 run-on counter pool 0x2fcd8 = 0xffffbddc'),
    ('w32', 0x2FCE0, 0xFFFFBDDA, '0x2fc00 key-on counter pool 0x2fce0 = 0xffffbdda'),
    ('w32', 0x2FCE4, 0xFFFFBDDE, '0x2fc00 injectors-off counter pool 0x2fce4 = 0xffffbdde'),
    ('w32', 0x2FCE8, 0xFFFFBDE0, '0x2fc00/0x2fcac injectors-off-seen pool 0x2fce8 = 0xffffbde0'),
    ('w32', 0x2FCEC, 0x0007BC58, '0x2fc00 threshold pointer pool 0x2fcec = 0x7bc58'),
    ('w32', 0x2FCF0, 0x0007BC5C, '0x2fc00 threshold pointer pool 0x2fcf0 = 0x7bc5c'),
    ('w32', 0x2FCF4, 0x0007BC5A, '0x2fcac threshold pointer pool 0x2fcf4 = 0x7bc5a'),
    ('w16', 0x7BC58, 0x001F, 'key-on grace threshold ROM 0x7bc58 = 0x001f'),
    ('w16', 0x7BC5C, 0x003E, 'run-on grace threshold ROM 0x7bc5c = 0x003e'),
    ('w16', 0x7BC5A, 0x0000, 'injectors-off-seen threshold ROM 0x7bc5a = 0x0000'),
    ('w16', 0x2FC64, 0x3232, '0x2fc00 bdda compare cmp/hs r3,r2 at 0x2fc64'),
    ('w16', 0x2FC66, 0x8F10, '0x2fc00 bdda branch bf/s 0x2fc8a at 0x2fc66'),
    ('w16', 0x2FC84, 0x3326, '0x2fc00 bddc compare cmp/hi r2,r3 at 0x2fc84 (keep while <= 0x3e)'),
    ('w16', 0x2FC86, 0x8D07, '0x2fc00 bddc branch bt/s 0x2fc98 (clear) at 0x2fc86'),
    ('w16', 0x2FC50, 0x23E0, '0x2fc00 clears 0xffffbde0 at 0x2fc50'),
    ('w16', 0x2FCAE, 0xE400, '0x2fcac mov #0x0,r4 (run-on counter clear) at 0x2fcae'),
    ('w16', 0x2FCBC, 0x3206, '0x2fcac bdde compare cmp/hi r0,r2 at 0x2fcbc'),
    ('w16', 0x2FCC6, 0x2500, '0x2fcac stores 1 into 0xffffbde0 at 0x2fcc6'),
    # --- 0x2fb20: speed request ------------------------------------------
    ('w16', 0x2FBC4, 0xA42C, '0x2fb20 injectors-off pool 0x2fbc4 = 0xa42c'),
    ('w16', 0x2FBC6, 0xA41C, '0x2fb20 engine-stopped pool 0x2fbc6 = 0xa41c'),
    ('w16', 0x2FBC8, 0xAA68, '0x2fb20 key-on pool 0x2fbc8 = 0xaa68'),
    ('w16', 0x2FBCA, 0xBDBC, '0x2fb20 result-cell pool 0x2fbca = 0xbdbc'),
    ('w16', 0x2FBCC, 0x00FF, '0x2fb20 hold-counter increment mov.w @0x2fbcc = 0x00ff'),
    ('w32', 0x2FBD0, 0xFFFFBDC4, '0x2fb20 max-demand pool 0x2fbd0 = 0xffffbdc4'),
    ('w32', 0x2FBD4, 0x000775D8, '0x2fb20 hysteresis constant pool 0x2fbd4 = 0x775d8 (3.5)'),
    ('w32', 0x2FBD8, 0xFFFFBDC0, '0x2fb20 filtered-demand pool 0x2fbd8 = 0xffffbdc0'),
    ('w32', 0x2FBDC, 0xFFFFBDD5, '0x2fb20 threshold-cell pool 0x2fbdc = 0xffffbdd5'),
    ('w32', 0x2FBE0, 0x000775BD, '0x2fb20 hold-term calibration pool 0x2fbe0 = 0x775bd'),
    ('w32', 0x2FBE4, 0xFFFFBDD4, '0x2fb20 hold-counter pool 0x2fbe4 = 0xffffbdd4'),
    ('w32', 0x2FBE8, 0x0005C2E4, '0x2fb20 gate pool 0x2fbe8 = 0x5c2e4'),
    ('w32', 0x2FBEC, 0x000775BE, '0x2fb20 hold-counter load pool 0x2fbec = 0x775be'),
    ('byte', 0x775BD, 0x01, 'hold-term calibration byte ROM 0x775bd = 0x01 (term inert)'),
    ('byte', 0x775BE, 0x01, 'hold-counter reload byte ROM 0x775be = 0x01'),
    ('f32', 0x775D8, 0x40600000, 'hysteresis constant ROM 0x775d8 = 3.5'),
    ('w16', 0x2FB3C, 0xF455, '0x2fb20 fcmp/gt fr5,fr4 at 0x2fb3c (bdc4 > bdc0)'),
    ('w16', 0x2FB44, 0x2460, '0x2fb20 sets 0xffffbdd5 = 1 at 0x2fb44'),
    ('w16', 0x2FB4C, 0x2450, '0x2fb20 clears 0xffffbdd5 at 0x2fb4c'),
    ('w16', 0x2FB7C, 0x8F08, '0x2fb20 hold-term branch bf/s 0x2fb90 at 0x2fb7c'),
    ('w16', 0x2FBBA, 0x343C, '0x2fb20 hold-counter add r3,r4 (saturating u8) at 0x2fbba'),
    # --- 0x2f9d0: filtered fuel-volume demand ----------------------------
    ('w16', 0x2FAC8, 0xBEB0, '0x2f9d0 fuel-volume pool 0x2fac8 = 0xbeb0'),
    ('w16', 0x2FACA, 0xB548, '0x2f9d0 rpm pool 0x2faca = 0xb548'),
    ('w32', 0x2FAD4, 0x3DF5C28F, '0x2f9d0 scale mova constant at 0x2fad4 = 0.12'),
    ('w32', 0x2FAD8, 0x3727C5AC, '0x2f9d0 filter snap threshold at 0x2fad8 = 1e-05'),
    ('w32', 0x2FADC, 0x000775C0, '0x2f9d0 coefficient pointer pool 0x2fadc = 0x775c0'),
    ('w32', 0x2FAE0, 0xFFFFBDC0, '0x2f9d0 output pool 0x2fae0 = 0xffffbdc0'),
    ('w32', 0x2FAE4, 0x000023B0, '0x2f9d0 filter helper pool 0x2fae4 = 0x23b0'),
    ('f32', 0x775C0, 0x3F400000, 'filter coefficient ROM 0x775c0 = 0.75'),
    # --- 0x2f9fc: max fueling request ------------------------------------
    ('w16', 0x2FACC, 0xADDC, '0x2f9fc intake-air-temperature pool 0x2facc = 0xaddc'),
    ('w16', 0x2FACE, 0xAD14, '0x2f9fc barometric-pressure pool 0x2face = 0xad14'),
    ('w16', 0x2FAD0, 0xB590, '0x2f9fc battery-voltage pool 0x2fad0 = 0xb590 (-> 0xffffb590)'),
    ('w32', 0x2FAE8, 0xFFFFBDD0, '0x2f9fc baro-table result pool 0x2fae8 = 0xffffbdd0'),
    ('w32', 0x2FAEC, 0x00002068, '0x2f9fc table-lookup helper pool 0x2faec = 0x2068'),
    ('w32', 0x2FAF0, 0x0006A968, '0x2f9fc descriptor 2D-166 pool 0x2faf0 = 0x6a968'),
    ('w32', 0x2FAF4, 0x000775C4, '0x2f9fc 200.0 constant pool 0x2faf4 = 0x775c4'),
    ('w32', 0x2FAF8, 0x000775C8, '0x2f9fc 190.0 constant pool 0x2faf8 = 0x775c8'),
    ('w32', 0x2FAFC, 0xFFFFBDC4, '0x2f9fc max-demand output pool 0x2fafc = 0xffffbdc4'),
    ('w32', 0x2FB00, 0xFFFFBDCC, '0x2f9fc margin flag pool 0x2fb00 = 0xffffbdcc'),
    ('w32', 0x2FB04, 0xFFFFBDC8, '0x2f9fc margin offset pool 0x2fb04 = 0xffffbdc8'),
    ('w32', 0x2FB08, 0x000775CC, '0x2f9fc zero constant pool 0x2fb08 = 0x775cc'),
    ('w32', 0x2FB0C, 0x0006A97C, '0x2f9fc descriptor 2D-167 pool 0x2fb0c = 0x6a97c'),
    ('w32', 0x2FB10, 0x0006A990, '0x2f9fc descriptor 2D-168 pool 0x2fb10 = 0x6a990'),
    ('w32', 0x2FB14, 0x000775BC, '0x2f9fc tail-gate pool 0x2fb14 = 0x775bc'),
    ('w32', 0x2FB18, 0x000775D0, '0x2f9fc 61.5 constant pool 0x2fb18 = 0x775d0'),
    ('w32', 0x2FB1C, 0x000775D4, '0x2f9fc zero constant pool 0x2fb1c = 0x775d4'),
    ('f32', 0x775C4, 0x43480000, 'margin scale ROM 0x775c4 = 200.0'),
    ('f32', 0x775C8, 0x433E0000, 'margin scale ROM 0x775c8 = 190.0'),
    ('f32', 0x775D0, 0x42760000, 'tail threshold ROM 0x775d0 = 61.5'),
    ('byte', 0x775BC, 0x00, 'tail gate byte ROM 0x775bc = 0x00 (branch taken)'),
    ('w16', 0x2FA40, 0xFF35, '0x2f9fc fcmp/gt fr3,fr15 at 0x2fa40'),
    ('w16', 0x2FA86, 0x2338, '0x2f9fc tail tst r3,r3 at 0x2fa86'),
    # --- call sites and task attribution ---------------------------------
    ('w32', 0x11308, 0x0002F948, 'start-up sequence callee pool 0x11308 = 0x2f948'),
    ('w16', 0x11136, 0x430B, 'jsr @r3 at 0x11136 calls 0x2f948'),
    ('w32', 0x0628C, 0x0001102A, 'init fan-out pool 0x628c = 0x1102a (sole start-up call site)'),
    ('w16', 0x061E4, 0x420B, 'jsr @r2 at 0x61e4 enters FUN_0001102a'),
    ('w32', 0x11A08, 0x0002F95C, 'fueling-task callee pool 0x11a08 = 0x2f95c'),
    ('w16', 0x1182E, 0x420B, 'jsr @r2 at 0x1182e calls 0x2f95c'),
    ('w32', 0x11D20, 0x0002F98C, '0x11b80 tail pool 0x11d20 = 0x2f98c'),
    ('w16', 0x11BA0, 0x432B, 'jmp @r3 at 0x11ba0 enters 0x2f98c'),
    # --- neighbouring outputs referenced in section 4.6 ------------------
    ('w16', 0x3A1AA, 0xCFB6, '0x3a0ec PD7 source pool 0x3a1aa = 0xcfb6'),
    ('w16', 0x3A1AC, 0x0080, '0x3a0ec PD7 mask pool 0x3a1ac = 0x0080'),
    ('w16', 0x3A1AE, 0xF746, '0x3a0ec PDDR pool 0x3a1ae = 0xf746'),
    ('w16', 0x3A1B0, 0xCFB7, '0x3a0ec PE0 source pool 0x3a1b0 = 0xcfb7'),
    ('w16', 0x3A1B2, 0xF754, '0x3a0ec PEDR pool 0x3a1b2 = 0xf754'),
    ('w16', 0x3A13C, 0xE501, '0x3a0ec PE0 mask mov #0x1,r5 at 0x3a13c'),
    ('w16', 0x4EFB4, 0xCFBD, '0x4ef86 source pool 0x4efb4 = 0xcfbd'),
    ('w16', 0x4EFB6, 0xCFB6, '0x4ef86 destination pool 0x4efb6 = 0xcfb6'),
    ('w16', 0x4EFB8, 0xCFBC, '0x4ef86 tested pool 0x4efb8 = 0xcfbc'),
    ('w16', 0x2E884, 0xBD68, '0x2e800/0x2e840 cell pool 0x2e884 = 0xbd68'),
    ('w16', 0x2E886, 0xF76C, '0x2e800 PJDR pool 0x2e886 = 0xf76c'),
    ('w16', 0x2E888, 0x0080, '0x2e800 PJ7 mask pool 0x2e888 = 0x0080'),
    ('w32', 0x2E898, 0x0005C56C, '0x2e840 gate pool 0x2e898 = 0x5c56c'),
    ('w16', 0x2E968, 0xB548, '0x2e89c rpm pool 0x2e968 = 0xb548'),
    ('f32', 0x774C0, 0x44160000, '0x2e89c rpm threshold ROM 0x774c0 = 600.0'),
    ('f32', 0x774C4, 0x45F3C000, '0x2e89c rpm threshold ROM 0x774c4 = 7800.0'),
    # --- peripheral symbols ----------------------------------------------
    ('sym', 'fffff754', 'PEDR_W', 'symbols.tsv 0xfffff754 = PEDR_W'),
    ('sym', 'fffff746', 'PDDR_W', 'symbols.tsv 0xfffff746 = PDDR_W'),
    ('sym', 'fffff76c', 'PJDR_W', 'symbols.tsv 0xfffff76c = PJDR_W'),
]


def read_rom() -> bytes:
    data = ROM.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    assert digest == ROM_SHA256, f'ROM hash changed: {digest}'
    return data


def read_symbols() -> dict[str, str]:
    with SYMBOLS.open(encoding='utf-8', errors='replace', newline='') as fh:
        return {r['address']: r['name'] for r in csv.DictReader(fh, delimiter='\t')}


def run() -> tuple[list[str], int, int]:
    rom = read_rom()
    symbols = read_symbols()
    lines: list[str] = []
    passed = 0
    for kind, target, expected, desc in CHECKS:
        if kind == 'w16':
            got: object = struct.unpack_from('>H', rom, target)[0]
        elif kind == 'w32' or kind == 'f32':
            got = struct.unpack_from('>I', rom, target)[0]
        elif kind == 'byte':
            got = rom[target]
        elif kind == 'sym':
            got = symbols.get(target)
        else:  # pragma: no cover - table typo guard
            raise AssertionError(f'unknown check kind {kind}')
        ok = got == expected
        passed += ok
        if kind == 'f32' and ok:
            lines.append(f'PASS {desc} (f32 {struct.unpack(">f", struct.pack(">I", expected))[0]!r})')
        elif kind == 'sym':
            lines.append(f'{"PASS" if ok else "FAIL"} {desc} (got {got!r})')
        else:
            want = f'{expected:#06x}' if kind in ('w16', 'byte') else f'{expected:#010x}'
            have = f'{got:#06x}' if kind in ('w16', 'byte') else f'{got:#010x}'
            lines.append(f'{"PASS" if ok else "FAIL"} {desc} (want {want}, got {have})')
    return lines, passed, len(CHECKS)


def render(lines: list[str], passed: int, total: int) -> str:
    header = (f'ROM SHA-256: {ROM_SHA256} size {len(read_rom())}\n')
    return header + '\n'.join(lines) + f'\n{passed}/{total} checks pass\n'


def main(argv: list[str]) -> int:
    lines, passed, total = run()
    text = render(lines, passed, total)
    if '--write' in argv:
        LOG.write_text(text, encoding='utf-8', newline='\r\n')
        print(f'wrote {LOG.relative_to(ROOT)} ({passed}/{total})')
    else:
        for line in lines:
            if line.startswith('FAIL'):
                print(line)
        print(f'{passed}/{total} checks pass')
    return 0 if passed == total else 1


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
