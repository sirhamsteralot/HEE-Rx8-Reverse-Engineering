# Immobilizer subsystem review — 60E15120_N3J1E

Scope: the PCM-side immobilizer — CAN challenge/response with the keyless
control module (IDs 0x047 RX / 0x041 TX), the seed/key state machine in
`0x34ae2`, the EEPROM key read (`0x375c0`), the fuel-cut gate (`0xe2d4` reading
`0xffffc1d0`), the security lamp (`0x2556c`), and the immo-off patch sites
(`0x34b10` / `0x34f5c`). Read from the canonical export (`decompiled/`), the
disassembly and the untouched ROM (SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`), plus a
dynamic run in the SH-2E emulator. No firmware changes were made.

Deliverables: [`docs/subsystem-logic/immobilizer_report.md`](../../../../subsystem-logic/immobilizer_report.md)
(the human-first report), label records
`data/labels/60E15120_N3J1E/immobilizer_labels.json`,
`data/labels/60E0G500_N3ZHEC/immobilizer_labels.json`,
`data/labels/cross_rom/immobilizer_function_map.json`, and tests
`tests/test_immobilizer_labels.py` + `tests/test_immobilizer_dynamic.py`.

## Binary-level verification (AGENTS.md rule 7)

Re-checked against the raw ROM bytes (all re-read 2026-11-17, hashes pinned):

- Start patterns: `0x34b10` = `B56E000960D0600C88008D1100098801` (the
  `bsr 0x355f0` at +0x2e of `FUN_00034ae2`); `0x34f5c` =
  `33208F080009B1AF...` (`cmp/eq r2,r3` + `bf/s` + `bsr 0x352c4` in
  `FUN_00034f42`).
- CAN mailbox descriptors: record at ROM `0x4dfac` = id 0x041, mbcr 0x00 (TX),
  mb 9, DLC 8, buffer 0xffffc4a8; record at `0x4e26c` = id 0x047, mbcr 0x01
  (RX), mb 39, DLC 8, buffer 0xffffc4b0 (last record of the HCAN1 table at
  0x4e21c).
- Literal pools: `0x355f0` pool words at 0x356b6-0x356d2 (0xc4bf, 0xc4b9,
  0xc4ba/0xc4bb/0xc4bc/0xc4bd, consts 0x0090/0x00c9/0x00ff, longs
  0xffffc21e/0xffffc221/0xffffc204); `0xe2d4` pool words 0xe406/0xe43c =
  0xc1d0, 0xe43e = 0xa430; `0x11c4` pool long 0x1284 = 0xffffdfa0.
- GPIO: `ref_setImmoLight__` 0x2556c writes `PEDR_W` 0xfffff754 masks
  0x40/0x20 (register name from `symbols.tsv`); timer mix uses
  `ATUII_TCNT0H_W` 0xfffff430.
- Callgraph anchors: 0xdbf6 → {0x3811c, 0x34ae2}; 0xdb58 → 0x380c8;
  0x1102a → 0x349e4; 0x114d0 → 0x34a04; 0x11534 → 0x5674a; 0x34a04 → 0x375c0.
- Every RAM alias added to `accepted_ram_aliases.tsv` is pool-anchored in the
  raw ROM — proven by `tests/test_source_review_ram_aliases.py` (31 new rows,
  pass).

## Dynamic validation (emulator)

`tests/test_immobilizer_dynamic.py` (4/4 pass) boots the ROM in the SH-2E
emulator (profile 60E15120_N3J1E, 1e6 cycles), primes the immo state, and
drives the real functions with `harness.call`: RX frames are written to the
0x047 buffer 0xffffc4b0 and unpacked by 0x38150 (what 0x3811c does after the
mailbox copy); 0x34ae2 runs the state machine; 0x380c8 packs the TX frame into
the 0x041 buffer. Observed (asserted in the test):

- cmd 0x06/0x7f → c21e=1, c221=2, TX `[07][c208 BE]`, c21d=2, c1d0=1
- cmd 0x08 with c200 → c224=0x7f, c21d=3, c1d0=1, TX `[81][7f]`; TX buffer
  copy verified (e.g. `[09][01][77 b2 76][00 00 00]` for cmd 9 word #1)
- cmd 0x08 with a wrong word → c224=0x81, c21d=4, c1d0=0, c22a=1, TX `[01][81]`
- cmd 0xc9 → c21d=1, c220=1, c1f0..c1fc = tagged words (01..04 << 24);
  cmd 0x90 tags 1-4 with those words → c220 2,3,4, then c21d=0, TX 0xc6
- fuel_cut_arbitration 0xe2d4: DAT_ffffa430 = 0x0003 with c1d0=0, 0x0000 with
  c1d0=1 (other cut flags zeroed)

## Notes / corrections

- 0x169d4 was inherited as `ref_ImmoRelatedFaultSomething_`, a misnomer (body
  copies the cal-ID string `N3J1E_1W.Z05` to 0xffffdf70..df7f); renamed to
  `cal_id_string_copy` in the label record on that body evidence.
- The per-ROM start-pattern addresses were already folded into the label
  records by the upstream-sync pass; this pass extends those records with the
  challenge/response analysis and does not duplicate them.
- Open discrepancy carried over: D13 (upstream def address for
  60E32000_N3N5EB with-RKE site is wrong for that ROM) — see
  `labeling/rx8defs-analysis/upstream-sync-validation.md` §3.

See [`REVIEW_NOTES.md`](REVIEW_NOTES.md) for the full check log and
[`validation.json`](validation.json) for the validator results.
