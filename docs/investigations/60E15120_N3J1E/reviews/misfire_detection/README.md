# Misfire detection — review evidence (60E15120_N3J1E)

Evidence for [`docs/subsystem-logic/misfire_detection_report.md`](../../../../subsystem-logic/misfire_detection_report.md)
and the label record
[`data/labels/60E15120_N3J1E/misfire_detection_labels.json`](../../../../../data/labels/60E15120_N3J1E/misfire_detection_labels.json).

## What was checked

- The whole monitor chain was traced in the decompiled export and re-read in
  the raw disassembly: crank capture `0xcf96` (ICR0AH `0xfffff434`,
  ring `0xffffa390..0xffffa3ac`, slot `0xffffa3b0`, post `0xa156`) →
  `crank_tick_message_handler` `0x11c98` → `misfire_monitor_tick` `0x287aa`
  (SR-masked, 44 `jsr` calls, order resolved from pool words) → snapshot
  (`0x26940`/`0x26982`), learned baseline (`0x2711a`/`0x271b0`/`0x28198`), delay
  line (`0x2842c`), filter (`0x2837c`), gates (`0x26bda`/`0x26d04`/`0x26d5c`/
  `0x26d70`/`0x26f38`/`0x26fc0`/`0x28b10`/`0x28b50`/`0x27306`/`0x27390`/`0x273d4`/
  `0x27520`), thresholds (`0x2853c`/`0x28648`), lookups (`0x44a78`/`0x44a9e`),
  arm (`0x27fb4`/`0x28022`), checks (`0x447e2`/`0x4489c`/`0x4493a`), counting
  (`0x26a42`/`0x26b34`/`0x26aa0`), sustained window (`0x44436`), and the two DTC
  windows (`0x44b16`/`0x44b46`/`0x44cec` at 400 ticks, `0x4458a`/`0x445ba`/
  `0x44724` at 2000 ticks → `dtc_set_fault_xdefault` `0x5fd3c`, slots 0/1,
  prefixes `0x7e55a` = P0300/P0301/P0302 via `0x5f98a`).
- Raw-bin re-verification of every cited pool word, instruction word, float
  constant, table descriptor and peripheral symbol:
  [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt) — 214/214 PASS, produced
  by
  [`utilities/scripts/rx8-pcm-pipeline/verify_misfire_chain.py`](../../../../../utilities/scripts/rx8-pcm-pipeline/verify_misfire_chain.py)
  (ROM SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`).
- Static label tests: `tests/test_misfire_detection.py` — function-index
  membership, TSV/JSON mirroring, ROM-byte verification of the cited anchors,
  and a regeneration test re-running the label generator and the verifier.
- One factual correction: the previous evidence for `0x27fb4` read the neutral
  flag and the load floor as AND-ed; the asm (`cmp/eq 0x1` at `0x27fda`,
  `bt/s 0x27fea`, `fcmp/gt` at `0x27fe4`) shows they are OR-ed. Corrected in the
  moved label record (report §4.3).
- `ref_misfireDetectInit_` `0xab8a` kept as inherited `ref_` name; its body
  initializes the ADC-pair block `0xffffa1cc..0xffffa207`, not misfire state
  (report §4.3).
