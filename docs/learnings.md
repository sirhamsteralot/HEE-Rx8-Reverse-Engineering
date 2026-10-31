# Learnings — RX-8 PCM RE session log (2026-10-29/30)

Practical lessons from the knock → fueling → intake → patcher passes on
`60E15120_N3J1E`. See `AGENTS.md` for the standing rules; this file is the
session-specific know-how. Everything here is backed by artifacts in
`reverse_engineered/60E15120_N3J1E/` (reviews, metadata, validation JSONs).

## Working method that scaled

- **Chain-first reviews**: start from the task table (0x4998) / dispatch table
  (0x5f10c), trace through the canonical C, cross-match RX8Defs descriptors and
  logger PIDs, then label via `source_review/accepted_*.tsv` + an idempotent
  `scripts/review_*.py` wired into `rebuild.sh`. One pass = one review folder +
  one root report + one metadata record + one backup zip.
- **Label confidence ladder works**: high = direct evidence; medium →
  `candidate_` prefix automatically; `ref_` = inherited hypothesis; never upgrade
  without new evidence.
- **Binary-level verification is mandatory and catches real bugs**: re-check
  labels against raw ROM (literal pools, constants, descriptors, GPIO
  reg+mask+helper, dispatch records) — it caught a wrong `>>4` scope (0x8a68:
  shift applies to latency+request sum), a wrong constant location (APV 100/12.5
  are inline pool literals of 0x31f32, not ROM 0x78bb8), and decompiler constant
  folding (hysteresis lower bounds are encoded as threshold−offset, e.g.
  7250−188=7062, so those literals don't exist in ROM).

## SH-2E / encoding facts (verified against `firmware_disassembly.asm`)

- PC-relative loads: `mov.w @(disp,pc),rN` **sign-extends** (0xa428 → 0xffffa428);
  `mov.l @(disp,pc),rN` EA = `((addr+4) & ~3) + disp*4` — note the align-down,
  instructions may sit at 2 mod 4. `mova` EA = addr+4+disp*4 (addr 4-aligned).
- `fmov.s @rM,frN` = `0xf000|(N<<8)|(M<<4)|8`; `fcmp/gt frA,frB` =
  `0xf000|(B<<8)|(A<<4)|5`, T = frB > frA; `fadd/fsub` = `0xf0..|0/1`;
  `fmov frA,frB` = `...|0xc`; `bt/s`=0x8d.., `bf/s`=0x8f.., `bra`=0xa...;
  `mov #imm,rN`=0xe...; `push/pop` = 0x2f../0x6f..; jsr @rX = 0x4000|(X<<8)|0x2b.
- RAM addresses in pools appear as mov.w low16 (sign-extended) or mov.l full32;
  indexed arrays appear as base+offset (stride computed by shifts, e.g. 0x18).
- Float constants often live in a **shared pool** (0x7xxxx) reached via mov.l
  pointer + fmov.s @r; some are folded (computed) — search the ROM for the
  expected bits before claiming a constant "doesn't exist".

## Pipeline pitfalls (don't repeat)

- `name_lookup_variables.py` regenerates `named/lookup_aliases.tsv` from scratch
  and must only run on a **fresh export** (raw DAT_ tokens). Running it on an
  integrated export wipes the generated rows — restore from backup if so.
- TSV append scripts must consume the header (DictReader without fieldnames);
  passing fieldnames duplicates the header row and breaks downstream scripts.
- `refine_*` passes are one-shot on a processed export ("already applied"); the
  0x13bd2 fix lives in `review_knock_loop_labels_apply.py` for that reason.
- Report tables: grouped rows (`a/b`), unnamed `DAT_` rows and base-pointer rows
  are legitimate — `validate_reports.py` knows them.

## Hardware documents

- `Sh7055h.pdf` = silicon truth (package pins: TO8A-F=195/197-201, PE7=16,
  PE10=19, PD5=254, PL5/PL8=221/224, PH12/13=79/80, AN6=92, PB2=147).
- `mazda-rx-8-pcm-pinout-series-1.pdf` = terminal→function+colour (FSM); v3 has
  colours for all used terminals except 5L/5Z; honour `*`/`†`/`³`/`–` markers.
  It has **no chip-pin numbers** — package-pin↔terminal is board routing; never
  assert it from the pinout. On each pinout update: re-diff and propagate into
  `hardware/pcm_connections.tsv` (wire_colour), `firmware_annotations.tsv`, and
  the `[WIRING REVIEW]` blocks in all three synchronized views (marker string
  `[WIRING REVIEW 2026-09-08]` must be kept so `AnnotateHardware.java` rebuilds
  reproduce them).
- Wiring annotations flow: `firmware_annotations.tsv` → `AnnotateHardware.java`
  (Ghidra rebuild) → per-function plate comments; edit the TSV + views together.

## Patchers (Utilities/)

- Pattern: byte-match locate the function body in the reference ROM (unique match
  required, else SKIP), relocate ROM-internal pool pointers by the found delta,
  patch only the located function's span + own pool, write a NEW output file,
  assert input SHA-256 unchanged and output diff confined to reported spans,
  emit JSON report + RomRaider XML fragment. Cal tables go in a verified-all-0xFF
  cal-area free run (common one: 0x7fb8c–0x7fc50; per-ROM discovery is fine, report
  addresses), descriptor format `>HBBII` (n, type 0 = float32, _, axis, data) —
  discoverable by the same pointer scan as `correlate_rx8defs.py`.
- Code caves work well: repoint one pool word at the call site to a cave in the
  free run; the cave can jsr the stock function (it tail-jumps and returns) then
  post-process. Decode-verify every emitted word with a mini-decoder built from
  the encodings above.
- Never modify stock `.bin`s; flash outputs with `Rx8Man/`; static validation
  only — hardware stages are the user's validation plan.

## Reports

- Root `*_report.md` files follow `knock_control_report.md`'s 10-section format,
  with a mandatory memory map (function + RAM address tables). Keep historical
  reports intact; append a dated "Update" addendum for later passes.
- `scripts/validate_reports.py` checks every report (sections, ROM hash, all
  memory-map addresses vs index/TSVs/ROM) — run it after any report edit.
