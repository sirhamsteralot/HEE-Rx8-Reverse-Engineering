# patch_limiter_behavior.py — RX-8 S1 PCM rev-limiter behavior patcher

Implements the draft SPEC (`patch_limiter_behavior.py` spec): over-rev limiter
that inhibits **fuel and ignition together** through the stock shared cut flags,
with modes stock/hard/soft and RomRaider-editable setpoints.

```sh
python3 Utilities/patch_limiter_behavior.py Stock_ROMs/60E15120_N3J1E.bin --mode soft --out patched/
python3 Utilities/patch_limiter_behavior.py Stock_ROMs/ --mode hard --limit 9200 --recovery 200 --hard-margin 400
# modes: stock|hard|soft (0|1|2); --limit <=0 = stock limit (clamped to <= 9300)
```

## RE basis (what the patcher relies on)

- Limiter decision: 0xe910 (limit = 0xffffa44c+0xffffa448; coolant margins via 3D
  tables 0x68fe0/0x68ffc — warm-up protection stays upstream, untouched) →
  requests 0xffffa464/a465 → arbitration **0xedc4** sets the shared flags
  **0xffffa444/a445** and tail-jumps to combiner 0xe2d4 (→ 0xffffa430).
- Consumers of the shared flags: fuel via a430 (0xff04) into the injection
  scheduler; ignition via 0x12938 (a444/a445 → a68a → 0x128ac → a689 → 0x129c0
  timing zero). So gating a444/a445 gates fuel AND spark together — cat-safe
  pairing (spec I1/I2) holds by construction. **Option A** (shared flag), no
  ignition synthesis needed.
- The patcher repoints the single pool word at the 0xedc4 call site (found by
  scanning for the limiter address referenced by `mov.l @(disp,pc),rX` +
  `jsr @rX`) to a code cave in a verified-free cal-area run. The cave calls the
  stock 0xedc4 (jsr; returns via 0xe2d4), then — only when the mode cell is
  1/2 — rewrites a444/a445 per the state machine and calls 0xe2d4 again to
  refresh a430. Mode 0 / out-of-range = pure passthrough (I3).

## Cal table "Rev Limiter Behavior" (category Protection)

4 float32 cells at the reported data address (per-ROM free run; N3J1E:
descriptor 0x7f760, axis 0x7f770, data **0x7f780**): cell0 = limit override
(≤0 = stock, clamped ≤ 9300), cell1 = mode (0/1/2), cell2 = recovery band rpm
(150), cell3 = hard margin rpm (300). State toggle u16 at data+16. RomRaider
def added to `RX8Defs_Copy/RomRaider/rx8_defs.xml` (base + 60E15120 block) and
emitted per-run as `<output>.xml`. Edit cells with RomRaider or a hex editor —
no re-patch needed.

## Safety / validation (static only — not hardware-tested)

- Stock .bin read-only, input SHA-256 asserted unchanged; output asserted to
  differ only at the call-site pool word + cal block + cave.
- Cave decode-verified word-by-word (SH-2E BE encodings cross-checked against
  `firmware_disassembly.asm`); build-time invariant sweep (model of the state
  machine over rpm ramps/square waves) refuses to emit on violation.
- Locates uniquely in 8/10 stock ROMs; the two 60E32000 ROMs SKIP (limiter body
  differs) — per spec abort policy.
- Flash with `Rx8Man/`. Validation stages per spec §8 (mode-0 soak first, then
  low-limit proving at ~4000 rpm via the cal cell, then real limit). Sustained
  9k+ limiting is still e-shaft/seal stress — the 9300 clamp is a ceiling, not a
  recommendation.
