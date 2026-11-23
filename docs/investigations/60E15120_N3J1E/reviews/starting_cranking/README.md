# reviews/starting_cranking — evidence for the engine-start / cranking subsystem

Working evidence behind
[`docs/subsystem-logic/starting_cranking_report.md`](../../../../subsystem-logic/starting_cranking_report.md)
and [`starting_cranking_labels.json`](../../../../../data/labels/60E15120_N3J1E/starting_cranking_labels.json).

Reference ROM `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`,
SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`.

## Artifacts in this folder

| File | What it holds |
|------|---------------|
| [`rawbin_reverify_log.txt`](rawbin_reverify_log.txt) | 174 raw-word checks produced by [`verify_starting_cranking_chain.py`](../../../../../utilities/scripts/rx8-pcm-pipeline/verify_starting_cranking_chain.py) — regenerated and compared by [`tests/test_starting_cranking_chain.py`](../../../../../tests/test_starting_cranking_chain.py) |
| [`dynamic_validation_log.txt`](dynamic_validation_log.txt) | emulator observations behind the report's dynamic statements — regenerated and compared by [`tests/test_starting_cranking_dynamic.py`](../../../../../tests/test_starting_cranking_dynamic.py) |

## Method

Static analysis of the disassembly plus the raw ROM bytes: every claim in the
report is tied to an instruction address and, where it depends on a constant,
RAM cell or table, to the literal-pool word that supplies it. `mov.w
@(disp,pc)` pools hold the sign-extended low half of a RAM address
(`0xb548` → `0xffffb548`), `mov.l` pools hold a full address, a ROM float or a
ROM constant; the disassembler prints the computed effective address, so the
printed pool address is the one that was read.

Every table descriptor was resolved through its single longword reference in
the image: `0x6ab48` ← pool `0x30330`, `0x6b630` ← pool `0x43a30`, `0x6b644` ←
pool `0x43a54`, `0x6ab00` ← pool `0x3045c`, `0x6bab0` ← pool `0x2ff70`,
`0x6a6cc` ← pool `0x14898`, `0x69208` ← pool `0x14164`. `0x6af2c` has exactly
one longword reference (pool `0x33498`) and is therefore *not* part of the
cranking chain even though the merged definition names its payload
*Ignition Leading - Cranking Timing Advance*.

Dynamic checks run the real ROM functions through
`utilities/scripts/emu/harness.py` after booting the profile to the idle loop;
each value quoted in
[`dynamic_validation_log.txt`](dynamic_validation_log.txt) is read back from
RAM, not modelled separately.

## Points worth knowing when re-checking this subsystem

* `0xffff86e8` is a **validated pair**: the 16-bit value followed by its one's
  complement at `0xffff86ea`. `0x3db94` returns its default argument unless the
  halves agree, and `0x3dc80` writes both. Seeding only the value makes the
  counter read as 0 and hides the 234-count limit.
* `0xffffaa62` is computed from closed-throttle dwell (`0x1a51c` + `0x1a564`),
  not from engine speed; the cranking fuel chain gates on `0xffffa428 == 0`.
  See the report's §4.6 and the ROADMAP discrepancy register.
* `0xffffbe94` (the cranking-pulse accumulator written by `0x30678`) has exactly
  one reader, the 1e7 compare at `0x305fe` inside `0x30468`.
* The two timing "filters" ship with a coefficient of 1.0 (`0x7ac00` /
  `0x7ac08`), so the filtered cell equals the table value in this calibration;
  the first-activation path is still present (`0x7abfc` / `0x7ac04`).
* `0x142a4` does not call `0x14100`; the idle base timing select runs in the
  `0x6584` task chain through `0x117ac` → `0x1465e` → `0x14100`.

## State of the C fold-back

The names in this subsystem's label record are carried into the canonical TSVs
([`accepted_function_aliases.tsv`](../../labeling/source_review/accepted_function_aliases.tsv),
[`accepted_ram_aliases.tsv`](../../labeling/source_review/accepted_ram_aliases.tsv))
but **not** yet into the decompiled export. The annotation + integration passes
that would do it (`annotate_source_review.py`, then
`integrate_reviewed_names.py`) abort on this tree, before this subsystem's names
are involved:

* `integrate_reviewed_names.py` asserts that each function body still names
  itself after the rename. Fourteen bodies in the eeprom/misfire area keep their
  Ghidra name while the index already carries the alias (`0x26a42`,
  `0x26b34`, `0x270aa`, `0x271b0`, `0x276ec`, `0x27eec`, `0x27fb4`, `0x2837c`,
  `0x2842c`, `0x445ba`, …), so the assert fails at the first of them.
* Teaching the pass to map `FUN_<address>` as well gets past that assert but
  then fails on the thunk bodies, whose names embed a target name
  (`jump_to_FUN_000270aa` in `00028992_thunk_FUN_000270aa.c` versus the index
  name `jump_to_e2ram_learned_table_validate`); those bodies were never renamed
  and the pass is not idempotent over them.

Both are tracked as an open work item in [`ROADMAP.md`](../../../../../ROADMAP.md);
the fix belongs in the generator (rename thunk and `FUN_` forms, add an
idempotency test), not in the export files.

## Open questions recorded in the report

1. Whether `cranking_active` should be renamed after what `0xffffaa62`
   computes, and what the closed-throttle advance tables are called: the two
   upstream names (off-throttle leading, cranking trailing) disagree.
2. What the 1e7 threshold on `0xffffbe94` protects (the correction it enables
   subtracts 0.046875 from `0xffffbe84`).
3. Whether `be2c`/`be30`/`be34`/`be38` are read through a base register in the
   injector scheduling code; a literal-pool scan sees no reader.
4. Physical routing of PD7 to the starter relay, and the terminal identity of
   package pin 256 — board level, not firmware level.
