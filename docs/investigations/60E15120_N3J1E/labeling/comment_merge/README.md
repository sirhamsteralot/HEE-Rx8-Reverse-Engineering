# Comment-block merge/reduce pass over the decompiled export

The per-function files under `reverse-engineered/decompiled/60E15120_N3J1E/functions/`
stack several review comment blocks (`[EXPORT CLEANUP]`, `[CROSS-ECU / RX8DEFS REVIEW]`,
`[ADDITIONAL SOURCE REVIEW]`, `[MATH AND UNITS REVIEW]`, `[LOOKUP FAMILY RECONSTRUCTION]`,
`[SORT RECORD RECONSTRUCTION]`, `[READABILITY RECONSTRUCTION]`) above the
`/* ROM address: ... */` anchor, and the same headers appear in the monolithic
[`firmware_decompiled.c`](../../../../../reverse-engineered/decompiled/60E15120_N3J1E/firmware_decompiled.c)
and [`named/firmware_named.c`](../../../../../reverse-engineered/decompiled/60E15120_N3J1E/named/firmware_named.c).
After the source-review comment sweep landed in
[`source_review/accepted_*.tsv`](../source_review/README.md), some statements were
restated across blocks and the three views ordered the blocks differently.

`utilities/scripts/rx8-pcm-pipeline/refine_comment_merge.py` is the re-runnable
normalization pass (wired into `rebuild.sh` after the last annotate pass, before the
validators). For every function in all three views it:

1. **applies** every accepted source-review row — `annotate_source_review.py` now keeps
   all rows per address (an address may carry a medium and a high hypothesis instead of
   last-one-wins), tolerates the legacy 4-field RAM rows whose evidence column is absent
   (rendered empty; the rows themselves are tracked as discrepancy D12), and rewrites
   `named/firmware_named.c` so the named view stays byte-identical to the canonical
   monolith. Result: `[ADDITIONAL SOURCE REVIEW]` blocks went from 511 to 525 files
   (14 functions whose accepted TSV rows had never been applied: 0x9ac4, 0xd9f4,
   0xdade, 0xdcc0, 0x193c4, 0x2a248, 0x2c324, 0x2c3b2, 0x2d638, 0x32614, 0x4db22,
   0x4de1c, 0x5fd38, 0x5fd3c — plus the second alias line on 7 addresses);
2. **orders** the tagged review blocks canonically (EXPORT CLEANUP, CROSS-ECU / RX8DEFS
   REVIEW, ADDITIONAL SOURCE REVIEW, MATH AND UNITS REVIEW, LOOKUP FAMILY
   RECONSTRUCTION, SORT RECORD RECONSTRUCTION, READABILITY RECONSTRUCTION) in all three
   views — previously the per-function files prepended the ASR block while the monoliths
   inserted it last, so 141 headers read in different orders depending on the view;
3. **reduces** redundant statements: exact-duplicate lines inside one block, machine-
   generated `[CROSS-ECU / RX8DEFS REVIEW]` descriptor lines whose descriptor address
   *and* table name the function's own ASR block already states, and `[MATH AND UNITS
   REVIEW]` affine-encoding lines whose signal *and* step literal the ASR block already
   states. The accepted TSV text stays authoritative; a review block left without
   content lines is removed entirely.

Measured application run (see [`validation.json`](validation.json), `applied_total`):
3 duplicate lines, 69 cross-ECU descriptor lines, 21 math-units affine lines dropped;
51 emptied blocks removed; 329 headers reordered; 106 per-function files changed; both
monoliths changed. The pass asserts every function body (from the `/* ROM address:`
anchor onward) is unchanged and still occurs intact in both monoliths (3,355/3,355),
and that the two monoliths remain byte-identical. Re-running the pass on the normalized
tree changes nothing (all per-run counters zero — the idempotency proof is in
`validation.json`). Re-running any annotate pass may reintroduce a redundant line; run
this pass again (or a full rebuild) to re-normalize. A diff of the whole export against
its pre-pass state shows zero non-comment, non-whitespace changes.

Verification: `validate_export.py`, `validate_reports.py`, `verify_readability.py`,
`verify_math_units.py`, `verify_claims.py` all PASS (on this Windows host the first two
need the default cp1252 locale, `validate_reports.py`/`verify_claims.py` need
`PYTHONUTF8=1`; each passes in its working mode), and `python -m pytest tests/` is
187 passed. `hash_binaries.py --check` is clean — no binary was touched.

No label was renamed or promoted by this pass; it only moves/applies existing accepted
comment text, so no new binary-level label verification was required beyond the body
invariants asserted above.
