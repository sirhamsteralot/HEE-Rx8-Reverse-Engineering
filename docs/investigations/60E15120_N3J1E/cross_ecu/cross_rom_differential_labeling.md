# Cross-ROM differential function labeling (byte-match) — 2026-10-31

ROADMAP group D item 1 (and feeds C item 6 for 60E0G500). Target: propagate the
60E15120_N3J1E labels to every other ROM by exact byte matching — no Ghidra run
needed for the propagation itself.

Method (`utilities/scripts/cross_rom_match.py`, run from the repo root):
base ROM SHA-256 asserted against `data/labels/60E15120_N3J1E/input.json`
(`a7cd953c…264f1`); for each of the 10 stock ROMs in the pinned submodule +
the 4 own dumps in `binaries/dumps/`, every `function_index.tsv` body
(`body_bytes` re-read from the base ROM) is searched for a **unique exact
occurrence** in the target ROM (same `unique_exact_bytes` method as
`data/labels/60E15120_N3J1E/matched_functions.tsv`). Matches inherit the base
ROM's accepted aliases from
`source_review/accepted_function_aliases.tsv` at the same confidence.

## Results

33,644 base→target function matches over 14 ROMs; 2,999 alias propagations.
Per-ROM (matched functions / propagated aliases of 3,355 base functions):

| ROM | matched | aliases |
|-----|--------:|--------:|
| 60E15120_N3J1E.bin (self) | 3215 | 315 |
| 60E0E500.bin | 2572 | 263 |
| 60E0E700_N3YLEE.bin | 2566 | 263 |
| 60E0FB00.bin | 2129 | 127 |
| 60E0FC00.bin | 2129 | 127 |
| 60E1B900.bin | 2057 | 120 |
| 60E1C500_N3J6EB.bin | 2505 | 256 |
| 60E1D400.bin | 2510 | 255 |
| 60E32000_N3M5E.bin | 1779 | 108 |
| 60E32000_N3N5EB.bin | (see summary JSON) | |
| dumps/aron-N3ZHEC-2026-10-31.bin (60E0G500/N3ZHEC) | (see summary JSON) | |
| 3 streetport tunes | (cal-only diffs vs the stock dump; see summary JSON) | |

Full data: `data/labels/cross_rom_function_matches.tsv` (one row per match) and
`docs/investigations/60E15120_N3J1E/cross_ecu/cross_rom_function_aliases.tsv`
(per-ROM target address → alias); summary with per-ROM SHA-256:
`data/labels/cross_rom_match_summary.json`.

Spot checks (byte-verified): 60E0FC00 0x4c/0x64/0x7c match at identical
addresses; `uds_service_dispatch_table_scan` base 0x68dac → 60E0FC00 **0x6769c**
(consistent with the roadmap note that the 60E0FC00 diag area sits at 0x5fa0c+);
`ref_udsResponseRelated2` base 0x68e3e → 0x6772e; alias sample
`boot_wait_nmi_pin_high` 0x8cc → 0x8cc in 60E0FC00.

See also [cross_rom_mode22_pid_handlers.md](cross_rom_mode22_pid_handlers.md) —
the Mode 22 dispatch table + PID handlers located and mapped in all 14 ROMs
(2026-11-01), using the matches TSV produced here.

## Notes / limits

- Byte-exact bodies only: functions whose PC-relative pools moved between ROMs
  do not match (that is why 60E0FB00/60E0FC00 match fewer functions than the
  60E1xxxx family — the diag/UDS block moved). Unmatched functions keep their
  base-ROM `FUN_` identity; nothing is renamed on plausibility alone (label
  ladder).
- The self-match is 3215/3355: the remaining 140 are overlapping thunks/pools
  that are not byte-unique even against the base ROM itself.
- Streetport tunes match the stock 60E0G500 dump on all code (cal-only diffs, as
  established in the P2 streetport diff) — their match counts equal the stock
  dump's, confirming no code patches.
- RAM aliases are not propagated by byte match (RAM addresses are referenced via
  mov.w/mov.l literals inside bodies; where bodies match, the RAM layout is
  identical, so `accepted_ram_aliases.tsv` transfers for matched functions —
  recorded here as a note, not re-derived per ROM).
