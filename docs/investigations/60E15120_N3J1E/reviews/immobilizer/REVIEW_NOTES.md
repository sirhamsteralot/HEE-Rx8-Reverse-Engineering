# Immobilizer review notes — check log (60E15120_N3J1E, 2026-11-17)

ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`,
SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
verified unchanged before and after the pass (`validate_export.py`).

## Static checks (all re-read from the raw ROM this session)

1. `0x34b10..0x34b1f` = `B56E000960D0600C88008D1100098801`; disassembly:
   0x34b10 `bsr 0x355f0`, 0x34b14 `mov.b @r13,r0` (r13 = pool 0x34b90 → c21d),
   0x34b18 `cmp/eq #0` … state dispatch chain 0x34b40/0x34b98/0x34ba0/0x34ba8/
   0x34bb0/0x34bb8 → 0x34c5c/0x34d12/0x34f42/0x35062/0x351ae/0x35258.
2. `0x34f5c..` = `3320 8F08 0009 B1AF 0009 E27F` — `cmp/eq r2,r3` (pools
   0x34fc4 → 0xffffc204, 0x34fc8 → 0xffffc200), `bf/s 0x34f72` (reject),
   fall-through `bsr 0x352c4` (authorized), `mov #0x7f,r2`.
3. `0x355f0` command decoder: pool words 0x356b6=0xc4bf (pending flag, must
   be 1), 0x356bc=0xc4b9 (cmd), 0x356ba=0xc4ba, 0x356b8=0xc4bb, 0x356c4=0xc4bc,
   0x356c6=0xc4bd, consts 0x356be=0x0090, 0x356c0=0x00c9, 0x356c2=0x00ff;
   store longs 0x356c8=0xffffc21e, 0x356cc=0xffffc221, 0x356d0=0xffffc204.
   Branch map: cmd 0 → c21e=0; cmd 6 → (c4ba,c4bb): (0,ff)→c221=1,
   (1,ff)→c221=3, 0x7f→c221=2, else c21e=6; cmd 8 → c21e=2 + c204=BE32(c4ba..bd);
   cmd 0x90 → c4ba∈{1..4} → c21e=4 + c1ec=BE32(c4ba..bd), else c21e=6;
   cmd 0xc9 → c21e=3; c4bf==0 → c21e=5; always clears c4bf.
4. CAN descriptors: `0x4dfac` id=0x00000041 mbcr=0x00 mb=9 mc=0x08 ide=0
   buf=0xffffc4a8; `0x4e26c` id=0x00000047 mbcr=0x01 mb=39 mc=0x08 ide=0
   buf=0xffffc4b0. Both records sit in the ROM mailbox tables (0x4e01c ch0
   16 recs, 0x4e21c ch1 6 recs).
5. `0x35738` TX frame build: byte order verified in disasm + emulator —
   param 7: c1c9=c208>>24, c1ca=(c208>>16)&ff, c1cb=(c208>>8)&ff,
   c1cc=c208&ff (big-endian seed); param 9: c1c9=c220, payload = selected
   computed word c1dc/c1e0/c1e4/c1e8; params 1/0x81: c1c9=c224; 0xc6/0xc8: zeros.
   Common tail: c1d1=1, c21f=0, c226=0, c229=1.
6. `0x380c8` copies c1c8..c1cf → c4a8..c4af when c1d1==1 and calls
   `ref_txCAN_EventBased(&DAT_0004dfac)`; `0xdb58` clears c1d1 afterwards.
7. `0xe2d4` fuel-cut gate: pool 0xe406=0xc1d0 and 0xe43c=0xc1d0 read with
   `tst r0,r0` (0xe368 / 0xe42a); store `mov.w r4,@r3` at 0xe438 with pool
   0xe43e=0xa430 (16-bit store — read back as a word).
8. `0x375c0` reads device words 0x6010000-0x6040000 (EEPROM 0x02-0x09),
   0x60b0000/0x60c0000 (0x16-0x19), 0x6050000 (0x0a-0x0b); erased flags
   c1d5-c1d8; gated by d1ce==1 + `ref_securityNotUnlocked(1)`.
9. `0x2556c` lamp: `ref_setRegister_REG_BIT_VAL(0xfffff754, 0x40/0x20, v)`;
   PEDR_W 0xfffff754 from `symbols.tsv`.
10. Cross-ROM: `cross_rom_function_matches.tsv` gives unique_exact_bytes
    targets for the chain in all 11 ROMs (26-40 functions each) — extracted
    into `data/labels/cross_rom/immobilizer_function_map.json` and checked by
    `tests/test_immobilizer_labels.py`. 60E0G500_N3ZHEC own dump: pattern at
    0x35af8/0x35f44, descriptors 0x4e758 (0x041, buf 0xffffc518) and
    0x4ea18 (0x047, buf 0xffffc520).

## Dynamic checks (emulator, profile 60E15120_N3J1E)

Full assertions in `tests/test_immobilizer_dynamic.py`; summary in
[`README.md`](README.md) §Dynamic validation. Boot 1e6 cycles; harness calls
on 0x38150 / 0x34ae2 / 0x380c8 / 0xe2d4 with primed RAM (engine_running
0xffffaa68=1, rpm 0). All four tests pass; the challenge/response sequence,
the key-word exchange and the fuel-cut gate were reproduced exactly as the
static analysis predicts.

## Artifact consistency

- `tests/test_label_artifact_consistency.py` (TSV↔JSON both directions,
  symbols.tsv coverage): pass after appending the immo rows to
  `accepted_function_aliases.tsv` (34 rows), `accepted_ram_aliases.tsv`
  (31 rows) and aligning aliases in `immobilizer_labels.json`.
- `tests/test_source_review_ram_aliases.py` (rule-7 pool anchoring of every
  accepted RAM row): pass.
- `tests/test_immobilizer_labels.py`: pass (patterns, descriptors, pool words,
  cross-ROM map vs matches TSV).
