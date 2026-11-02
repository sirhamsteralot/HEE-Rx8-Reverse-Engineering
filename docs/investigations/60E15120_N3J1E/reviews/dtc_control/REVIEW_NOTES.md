# REVIEW_NOTES — DTC control deep dive

Date: 2026-11-01. Reviewer pass over the DTC findings before the report was
written.

## Binary-level re-checks performed

1. Re-dumped ROM bytes at the DTC region of all 11 ROMs and re-derived the
   layout independently of the decompiler: prefix `03 00 03 01 03 02` +
   slot0 `03 00`, code table (BE u16, 140 slots, 0xffff padding), then three
   enable blocks of 140 u8. Matches `data/dtc/*.tsv`.
2. Cross-checked the enable-block base against literal-pool references in each
   ROM (see README) — this is what convicts the 60E0E700 (+3 bytes), 60E1B900
   and 60E32000_N3M5E (point into the code table) per-rom defs, and acquits
   60E15120_N3J1E / 60E0FC00 / 60E0G500_N3ZHEC / 60E32000_N3N5EB.
3. Re-read disassembly of 0x5a130: r4 = 1 + 0x7f = 0x80 in the delay slot, so
   the stored-count query 0x61450 runs with filter arg r5=1 (enable#1 gate) —
   confirmed by the emulator: with slot 8 (P0077, enable1=0) stored, the MIL
   flag stayed 0; with slot 9 (P0101, enable1=1) stored, MIL flag = 1.
4. Dynamic run (`dynamic_validation_log.txt`): Mode 22 PID 0x0200 returns
   `62 02 00 01` and PID 0x0202 `62 02 02 01` through the ROM dispatcher
   0x5774c with one stored DTC; 0x615c6(0x80) collects slot 9 and 0x667c8 maps
   it to code 0x0101 via code table 0x7e560; enable1 filter drops the
   disabled slot. Set-path partially dynamic: 0x5fd38(id, mode) writes
   0xffffd458[slot] and 0xffffd3c2[id] (observed), but the full
   master-table insertion rides OS group-2 event 2 (handler 0x61092) which
   the emulator does not run autonomously (E6), so the stored-state planting
   in the log is done via the documented RAM cells (harness ram= equivalent).

## Corrections made during the pass

- The audit derives the enable-block start from the ROM itself (end of the 0xffff
  padding run after the code table), not from the def's minimum address — with the
  ROM-derived start, 60E0FC00 is correct (its first def entry binds slot 1, the
  duplicate P0300; slot 0 is unbound but harmless).
- 60E1D400 is +1 shifted (absorbed by the duplicate P0300 at slots 0/1) AND its
  def carries 14 codes this ROM does not have at those slots (0116, 0134,
  0137, 0411, 0444, 0445, 050A, 2009, 2010, 2016, 2067, 2068, 2102, 2103),
  shifting everything from slot 17 — matches the pre-existing
  `defs-merge/inheritance_issues.json` entries (0128/1574/1577/2008/2101/2406
  family).
- 60E0FB00's def has duplicated entries (0300 x3, 0030 x2, ...) and a gap at
  slot 23 — 98 mismatches; its #3 block is fine.
- 60E0E700's def #2 contains an entry with storageaddress 0x0 (bogus).

## Multi-gate verification (2026-11-01)

Confirmed per gate: monitor-source mask **0x7e29e** (ANDed with an 8-bit mask from the
ptr table 0x604f8 in 0x5fb68, called from the mode-1 store transition 0x60062), and
the report-class function **0x618f8** (class 3/4/5 for type-0 stored DTCs depending
on enable#1/#2). enable#1 predicates 0x60f02/0x64234 are called from the aging
handlers 0x60b14/0x63f64/0x64620/0x6477c; 0x6071e gates Mode 02 freeze-frame capture
on enable#2 + state 0xc0.

Dynamic proof with stock-asymmetric slot 0x74 (C073, #1=0/#2=1/#3=0x0e)
(`dynamic_multigate_log.txt`): 0x61450(0x80,filt=0) counts it (PID 0x0200),
filt=1 (enable#1) excludes it -> MIL stays 0 after 0x5a130, filt=2 (enable#2) still
lists it -> Mode-03-style response contains C073; 0x618f8 returns class 4.
Emulator ROM is read-only (write8 to 0x7e681 ignored), so the asymmetry was
exercised with the stock bytes themselves rather than by flipping cal bytes.

Conclusion for tuners: to fully suppress a DTC you must clear **#1 AND #2** (and the
relevant **#3 bits** to stop it being set/confirmed); clearing only one leaves it
visible in Mode 03 (#1-only clear) or in MIL/aging (#2-only clear). Stock ROMs have
exactly one used slot with asymmetric #1/#2 (0x74 C073) and 11 slots with 0/0.

## Not verified / limits

- The aging/confirmation counters (how many drive cycles until
  pending->confirmed->stored, and the 40-warm-up-style clear) live in
  0x60ca6/0x64918/0x64972/0x6400a and were read statically only; not executed
  dynamically (OS tick E6).
- MIL lamp GPIO pin not traced (flag 0xffffd286 verified; the physical output
  write is in the output task, not chased here).
- Upstream `rx8_defs.xml` child ROMs inheriting `Rx8Base` DTC addresses show
  the expected inheritance drift (97-98 mismatches for 60E0FC00-based blocks);
  already covered by `defs-merge/inheritance_issues.json`.
- Emulator self-check vs golden boot trace not re-run for this pass (no
  emulator changes); Renesas cross-check still pending (ROADMAP E-limits).

## Defs repair applied (2026-11-01)

`extend_defs_all_roms.py` gained `repair_dtc_tables()`: each per-ROM block's
`DTC xxxx Enable/Disable #N` entries are rebuilt from the ROM's own DTC layout
(code table + 3 enable blocks, `dtc_layout()`). After regeneration: 0 mismatches
across all 9 per-ROM defs for #1/#2/#3 (see `data/dtc/defs_audit.tsv`, regenerated).
The merged 60E15120 block gained its missing #2/#3 bindings (363 entries, 0
mismatches, XML re-parsed). Repair recorded in `defs-merge/definition_repairs.json`.
