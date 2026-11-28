# Misfire detection — review notes

Method, in order:

1. Entry points: `ref_misfireDetectInit_` `0xab8a` (inherited name) and the
   DTC side (`0x7e55a` prefixes, slot table `0x7e560`) were the only named
   pieces; the detection logic was unanalyzed. Traced the producer side from the
   crank ISR: `0x5b3c` → `0xcf96` writes the sector-period ring and posts via
   `0xa156` (group-1 rec[9] @ ROM `0xd98c`) to `0x11c98`, which calls `0x287aa`.
2. Resolved all 44 `jsr` targets of `0x287aa` from its literal pools
   (0x287aa–0x288be) and read each callee body in the decompiled export plus the
   disassembly; grouped them into snapshot / learn / thresholds / gates / arm /
   check / count / windows-DTC stages (report §2.2).
3. Verified the arm polarity at instruction level: `0x27fda cmp/eq 0x1,r0` on
   `0xffffb53a`, `bt/s 0x27fea` skips the load compare (`fcmp/gt` `0x27fe4`) in
   neutral → OR semantics; `0x2800a fcmp/gt` requires `ba40 > ba78`; this
   corrected the earlier AND-ed evidence string.
4. Identified the rotor-bank mechanism: `sector_parity_bank` `0xffffb660` =
   `0xffffa3b0` & 1 (0x26982) indexes the event flags, counters and learned
   table bank everywhere.
5. Mapped the two DTC windows: 400-tick (`0x28b10`/`0x26aa0`/`0x44b16`/
   `0x44b46` → `0x44cec` → slot 0) and 2000-tick (`0x28b50`/`0x26aa0`/`0x4458a`/
   `0x445ba` → `0x44724` → slot 1), both feeding `dtc_set_fault_xdefault`
   `0x5fd3c` (pools `0x447ac`/`0x44d54`); rotor bits select P0301/P0302 via the
   prefix table `0x7e55a` (`0x5f98a`).
6. Re-read every cited pool word / float / descriptor from the raw ROM into
   `verify_misfire_chain.py` (214 checks) and generated
   `rawbin_reverify_log.txt`.
7. Labels: new generator `review_misfire_detection_labels.py` owns the
   `misfire_*` function/RAM aliases (moved out of the eeprom-content record,
   which keeps the `e2ram_learned_table_*` storage layer); fold-back chain
   `annotate_source_review.py` → `integrate_reviewed_names.py` →
   `refine_comment_merge.py` re-run to the fixed point;
   `tests/test_reviewed_name_foldback.py` green.

Open questions: `0xffffd1c5` (engine-stop state-clear flag) has no accepted
alias yet; the ADC-pair block initialized by `0xab8a` belongs to sensor
acquisition (the sensor-acquisition subsystem report), noted in report §4.6.
