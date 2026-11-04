# Free flash / free memory per ROM — corpus-wide resource scan (for patch planning)

Reference ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`).
Corpus: the 10 upstream stock ROMs + our own dump `binaries/dumps/60E0G500_N3ZHEC.bin`
= **11 unique ROMs** (`60E0FC00.bin` is byte-identical in `Stock_ROMs/` and
`Data_binaries/`, SHA-256 `476ddcbe…`, counted once). No binary is modified by
this study. Method disclaimer: free-flash numbers are scanned from raw ROM bytes;
free-memory numbers are measured by booting each real ROM in the SH-2E emulator
(`utilities/scripts/emu/`, 2M cycles to the idle loop 0x3dac) with per-byte RAM
write tracking.

**Related reports:** [live_tuning_feasibility_report.md](live_tuning_feasibility_report.md)
(the study these numbers feed — its 60E15120_N3J1E figures are cross-checked
against this scan in §7), [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md)
§12.1 (D3 checksum range/hole), [learnings.md](../../learnings.md) (patcher
free-run pattern), [calibration_extraction_report.md](calibration_extraction_report.md)
(cal-region layout per ROM).

## 1. Executive summary

- **Free memory (RAM) is identical on all 11 ROMs at idle boot:** after a
  2M-cycle boot, the only never-written run ≥32 B in the 32 KiB RAM
  (0xffff6000–0xffffe000) is **0xffff8000–0xffff92ff = 4,864 B**; 27,904 of
  32,768 bytes are touched. Excluding the 393 labeled RAM cells
  (`accepted_ram_aliases.tsv` union + 0xffff8038), the largest contiguous free
  runs are **0xffff8901–0xffff90f3 (2,035 B)** and **0xffff807d–0xffff8787
  (1,803 B)**. This matches the feasibility report's 60E15120_N3J1E numbers
  exactly (verification in §7). **The static allocation analysis (§10) then
  shows 308 B of that window are still code-referenced (latent use, e.g. the
  EEPROM mirror at 0xffff8000–0xffff80ff), leaving 3,852 B truly free, largest
  contiguous run 1,087 B (0xffff8109–0xffff8547).**
- **Free app flash varies widely: 899 B – 21,956 B** (0xFF runs ≥16 B in
  0x2000–0x7ffff). Common to **all 11 ROMs**: the 196 B run
  **0x7fb8c–0x7fc4f** (the patchers' code cave, right before the IVT at
  VBR 0x7fc50), a 127 B cal-area run, and the CVN-neutral SBL run
  **0xb0e–0xfdf (1,234 B)** (the app checksum starts at 0x2000, D3 — verified
  for 60E15120_N3J1E; see §9 before relying on it for other ROMs).
- **60E15120_N3J1E is nearly the tightest**: 2,378 B total app free (largest
  run 928 B at 0x7f760–0x7faff), only 60E32000_N3M5E is tighter (899 B).
  The roomiest are 60E0FB00/60E0FC00 (21,956 B, incl. a 13,244 B run
  0x69f44–0x6d2ff).
- Consequence for live tuning (feasibility report): the RAM shadow budget
  (~2 KiB contiguous) is the same on every ROM, so the patch design is portable;
  the code-cave budget is per-ROM and must be re-discovered per ROM (the
  patchers already do verified-all-0xFF discovery).

## 1a. Plain-language summary

We measured how much empty space each ROM has, two ways. Flash ("ROM") space is
just counted by scanning for erased (0xFF) bytes. RAM space can't be scanned —
memory starts random-ish and the firmware writes to its variables — so we booted
every ROM in the emulator for 2 million instructions and recorded every RAM byte
the firmware ever wrote; whatever was never touched is free. Result: every ROM
leaves the same 4.8 KB block at 0xffff8000–0xffff92ff untouched at idle (about
2 KB contiguous after skipping a handful of used cells) — enough for a RAM copy
of the handful of tables you live-tune. Flash headroom differs per ROM
(0.9–22 KB), but every ROM has the same 196-byte cave at 0x7fb8c plus ~1.2 KB
in the bootloader area that the checksum doesn't cover.

## 2. Method (condensed pseudocode)

```python
# --- free flash: raw byte scan per ROM ---
rom = read(path); sha = sha256(rom)
for region, lo, hi in (("sbl", 0, 0x2000), ("app", 0x2000, len(rom))):
    runs = maximal 0xFF runs with length >= 16 in [lo, hi)   # report all

# --- free memory: emulator boot with write tracking ---
import emu; from opdec import OPMNEM
# measurement-only opcode-table widening (E8): SH-2E software manual
# (rej09b0316_sh_2esm.pdf, operation code map) assigns the full
# 0x7xxx=ADD #imm,Rn, 0x9xxx=MOV.W @(disp,PC),Rn, 0xAxxx=BRA, 0xBxxx=BSR,
# 0xDxxx=MOV.L @(disp,PC),Rn spaces; the 60E15120 corpus table only has the
# combos that ROM executes, so inject the missing words (handlers recompute
# EA/target from the opcode bits themselves). Not a repo change.
for op in 0x7000..0x7fff: OPMNEM.setdefault(op, ('add', f'0x{op&0xff:02x},r{(op>>8)&0xf}'))
for op in 0x9000..0x9fff: OPMNEM.setdefault(op, ('mov.w', '@(0x0,pc),rN'))
for op in 0xa000..0xbfff: OPMNEM.setdefault(op, ('bra'/'bsr', '0x0'))
for op in 0xd000..0xdfff: OPMNEM.setdefault(op, ('mov.l', '@(0x0,pc),rN'))
prof, bus, cpu = emu.build(profile)          # existing profile, or the
                                             # 60E15120 profile cloned with
                                             # rom.path/sha256/size swapped
wrap bus.write8/16/32 to record touched RAM bytes in [0xffff6000, 0xffffe000)
emu.run(prof, bus, cpu, 2_000_000)           # all 11 ROMs reach the cycle limit
free_runs = maximal never-written runs >= 32 B
free_runs_excl = same but excluding the 393 labeled RAM cells
```

## 3. Key tables / structures (measured)

### Free flash per ROM (0xFF runs ≥16 B; app = 0x2000–0x7ffff, SBL = 0x0–0x1fff)

| ROM | SHA-256 (12) | app free total | largest app runs (addr–end, len) | SBL free |
|---|---|---:|---|---|
| 60E0E500 | c05dfd0422b2 | 16,738 B / 9 runs | 0x7d710–0x7faff 9200; 0x6aab4–0x6c5ff 6988; 0x7fb8c–0x7fc4f 196; 0x6c661–0x6c6df 127 | 0xb0e–0xfdf 1234 |
| 60E0E700_N3YLEE | bba52346a076 | 15,922 B / 9 runs | 0x7d7c0–0x7faff 9024; 0x6ad34–0x6c5ff 6348; 0x7fb8c–0x7fc4f 196; 0x6c661–0x6c6df 127 | 0xb0e–0xfdf 1234 |
| 60E0FB00 | 3d32e2591a11 | 21,956 B / 9 runs | 0x69f44–0x6d2ff 13244; 0x7db15–0x7faff 8171; 0x7fb8c–0x7fc4f 196; 0x6d361–0x6d3df 127 | 0xb0e–0xfdf 1234 |
| 60E0FC00 | 476ddcbed454 | 21,956 B / 9 runs | same layout as 60E0FB00 | 0xb0e–0xfdf 1234 |
| 60E15120_N3J1E | a7cd953c2a87 | 2,378 B / 9 runs | 0x7f760–0x7faff 928; 0x6bc7c–0x6bfff 900; 0x7fb8c–0x7fc4f 196; 0x6c061–0x6c0df 127; 0x7fb08–0x7fb7f 120 (checksum hole); +26/24/19/38 B gaps | 0xb0e–0xfdf 1234 |
| 60E1B900 | b0dc94f96e8e | 21,300 B / 8 runs | 0x6a1dc–0x6d2ff 12580; 0x7db15–0x7fb7f 8299; 0x7fb8c–0x7fc4f 196; 0x6d361–0x6d3df 127 | 0xb0e–0xfdf 1234 + 0x1fc4–0x1fff 60 |
| 60E1C500_N3J6EB | b3b6e1e41682 | 16,026 B / 8 runs | 0x7d710–0x7fb7f 9328; 0x6ad84–0x6c5ff 6268; 0x7fb8c–0x7fc4f 196; 0x6c661–0x6c6df 127 | 0xb0e–0xfdf 1234 + 0x1fc4–0x1fff 60 |
| 60E1D400 | 344cb8b960eb | 5,558 B / 8 runs | 0x6c270–0x6cdff 2960; 0x7f308–0x7fb7f 2168; 0x7fb8c–0x7fc4f 196; 0x6ce61–0x6cedf 127 | 0xb0e–0xfdf 1234 + 0x1fc4–0x1fff 60 |
| 60E32000_N3M5E | d5406459cc0b | 899 B / 8 runs | 0x7fa0c–0x7faff 244; 0x7fb8c–0x7fc4f 196; 0x7144c–0x714ff 180; 0x7fb08–0x7fb7f 120 (hole) | 0xb0e–0xfdf 1234 + 0x1fc4–0x1fff 60 |
| 60E32000_N3N5EB | 6c043bd4c958 | 1,117 B / 6 runs | 0x7f938–0x7fb7f 584; 0x70f38–0x70fff 200; 0x7fb8c–0x7fc4f 196; 0x71061–0x710bf 95 | 0xb0e–0xfdf 1234 + 0x1fc4–0x1fff 60 |
| 60E0G500_N3ZHEC | a33f79a4f1c4 | 6,214 B / 9 runs | 0x6bfd8–0x6cdff 3624; 0x7f308–0x7faff 2040; 0x7fb8c–0x7fc4f 196; 0x6ce61–0x6cedf 127 | 0xb0e–0xfdf 1234 |

Notes: the cal area starts at 0x6c000 (0x6d000 for 60E0FB00/60E0FC00/60E1B900,
0x71000 for 60E32000) — runs below that are in the descriptor/code gap, runs
above are inside the cal region; both are usable for cal blocks, but code caves
must be decode-verified (patcher pattern). Runs ending at 0x7fb7f include the
checksum hole 0x7fb00–0x7fb7f (CVN-neutral, D3 — verified for 60E15120_N3J1E).

### Free memory per ROM (measured, emulator write-tracking, 2M-cycle boot)

| ROM | boot result | touched RAM bytes | never-written run(s) ≥32 B | largest runs excl. labeled cells |
|---|---|---:|---|---|
| all 11 ROMs | cycle limit reached (idle 0x3dac) | 27,904 / 32,768 | 0xffff8000–0xffff92ff = 4,864 B (single run) | 0xffff8901–0xffff90f3 2035; 0xffff807d–0xffff8787 1803; 0xffff9151–0xffff92ff 431; 0xffff87b1–0xffff88ff 335 |

## 4. Labeling applied

None — measurement report; no labels changed. The 393 excluded RAM cells come
from the existing `accepted_ram_aliases.tsv` files (60E15120_N3J1E, 60E0G500_N3ZHEC)
plus the prose-documented 0xffff8038.

## 5. Corrections made in this pass

None. The opcode-table widening used for booting the 7 un-profiled ROMs is a
measurement-time shim only (E8 stays open for the repo's opdec.py); it changed
no committed file and no emulator semantics for the 60E15120 corpus.

## 6. Files

- This report: `docs/investigations/60E15120_N3J1E/free_resources_report.md`
- `docs/investigations/60E15120_N3J1E/live_tuning_feasibility_report.md` — §3/§7
  now cross-reference this scan (verification of its numbers)
- Raw measurement JSON: session scratchpad (`/tmp/free_res_scan.json`), method
  in §2; no binaries touched.

## 7. Validation

- **Cross-check against the feasibility report (the point of this pass):**
  | claim in live_tuning_feasibility_report.md | this scan (60E15120_N3J1E) | match |
  |---|---|---|
  | free-flash runs 0x7f760–0x7faff 928 / 0x7fb08–0x7fb7f 120 / 0x7fb8c–0x7fc4f 196 / 0x6bc7c–0x6bfff 900 / 0x6c061–0x6c0df 127 (+small gaps), total ≈2.2 KiB | identical runs; total 2,378 B | yes |
  | SBL-region run 0xb0e–0xfff 1,234 B | 0xb0e–0xfdf 1,234 B (0xfe0–0xfff is the vector area, not 0xFF) | yes |
  | never-written RAM 0xffff8000–0xffff92ff 4,864 B after 2M-cycle boot | identical | yes |
  | largest runs excl. labeled cells 0xffff8901–0xffff90f3 2,035 B / 0xffff807d–0xffff8787 1,803 B | identical (0xffff8901 len 2035, 0xffff807d len 1803) | yes |
- Every ROM's SHA-256 re-computed during the scan and quoted in §3; the
  reference ROM hash in the header equals the submodule ROM's hash.
- §10 static analysis re-run deterministically from the committed disassembly
  (`firmware_disassembly.asm`) and ROM bytes: 4,546 point refs + 768 intervals,
  392/393 labeled aliases matched, 308 window refs — quoted above.
- `python utilities/scripts/rx8-pcm-pipeline/validate_reports.py` — PASS.
- `python utilities/scripts/hash_binaries.py --check` — OK (no binary touched).
- `python -m pytest tests/` — 91 passed, 1 pre-existing cp1252 failure
  (also on `main`, unrelated).

## 8. Memory map for validation

### Functions (reference ROM, function_index.tsv names)

| Address | Name | Role here |
|---|---|---|
| 0x0005a3f4 | `FUN_0005a3f4` | checksum engine — defines the covered range 0x2000–0x7ffff + hole (D3) |
| 0x0005a714 | `FUN_0005a714` | checksum finalize |
| 0x00003c2a | `os_dispatch` | idle loop 0x3dac reached by all 11 boots |

### RAM (accepted_ram_aliases.tsv aliases)

| Address | Alias | Role here |
|---|---|---|
| 0xffff807c | `inferred_ram_807c_ffff807c` | labeled cell inside the free window (excluded) |
| 0xffff9150 | `inferred_sensor_block_ffff9150` | labeled cell inside the free window (excluded) |

## 9. Limits

- **Idle-boot lower bound:** all measurements are from a 2M-cycle boot to idle
  (0x3dac) with default sensor inputs. Under a real drive cycle more RAM may be
  touched — re-measure with `hee_replay_load`/`hee_replay_step` over
  `data/logs/*.csv` before picking shadow addresses (same caveat as the
  feasibility report).
- **Checksum hole is verified only for 60E15120_N3J1E** (D3: skip
  0x7fb00–0x7fb7f). Other ROMs' checksum routines need the same literal-pool
  check before treating their 0x7fbxx runs as CVN-neutral.
- **0xFF scan ≠ usable cave:** runs inside the cal region are fine for cal
  blocks; code caves must be decode-verified word-by-word (patcher pattern),
  and flash block boundaries (SBL vs app blocks) matter for what the SBL
  erases/programs — check before flashing anything (ROADMAP F gating).
- The 7 ROMs without committed profiles were booted on a clone of the
  60E15120 profile (rom path/sha swapped); per-ROM sensor/UDS addresses differ
  and their diag path is not dynamically executable yet (E8) — irrelevant for
  this RAM measurement, relevant for any per-ROM dynamic work.
- Free-RAM identity across ROMs is expected (same firmware family, same RAM
  map) but only *measured* at idle boot; treat per-ROM differences as
  "not yet measured" rather than "proven equal".
- §10 Method A caveats: base+disp intervals use light per-function register
  tracking (approximation — a base register reloaded mid-function may extend an
  interval); the static stack estimate covers call chains only, not interrupt
  nesting; Method B (raw u32 scan) misses mov.w sign-extended low16 literals on
  ROMs without a committed disassembly, so per-ROM window counts (137–180) are
  lower bounds. The EEPROM-mirror identification rests on the 0x55aa/0xaa55
  magic at 0xffff8000 (0xd408/0xd44c) + the 256 B 93c56 dump size — solid, but
  the exact mirror extent (0x100 B assumed) is not proven cell-by-cell.

## 10. Static allocation analysis (beyond idle-boot measurements)

Idle-boot write-tracking only shows what boot *happened* to touch. To see what
the code *can* touch, we extracted every static RAM reference from the
60E15120_N3J1E disassembly and cross-scanned all ROMs at byte level:

- **Method A (full disassembly, 60E15120_N3J1E):** every `mov.w/mov.l
  @(EA,pc),rN` whose literal-pool word lands in RAM (mov.w = sign-extended
  low16, mov.l = full32) is a direct cell reference; `mov.x @(disp,rN)` with rN
  tracked (light per-function register tracking) to a RAM base adds a
  base+disp interval; `add #imm,r15` prologues give stack frame sizes, combined
  with `callgraph.tsv` into a longest-chain estimate. Result: **4,546 direct
  point references + 768 base+disp intervals = 5,351 statically referenced RAM
  bytes** (range 0xffff6000–0xffffdffc), of which 392 match the labeled
  aliases — i.e. the label set covers the referenced cells well, and ~4,950
  referenced bytes were previously unlabeled.
- **Method B (raw byte scan, all 11 ROMs):** every 4-aligned big-endian u32 in
  the ROM with value in 0xffff6000–0xffffe000 is a mov.l literal-pool reference
  (2,674–2,810 per ROM). Inside the idle-free window 0xffff8000–0xffff92ff each
  ROM has **137–180 such literals** — the latent usage is corpus-wide, not an
  artifact of one ROM. (mov.w low16 literals are only captured by Method A;
  for other ROMs Method B is a lower bound.)
- **Method C (dynamic stack):** reset SP = 0xffffdfa0 (vector 4); task contexts
  at 0xffff7408+8·i grow down from ≈0xffff7498; observed low-water mark during
  the 2M idle boot = **0xffff73e8**; static longest-call-chain estimate ≈
  **10,284 B** (largest single frame 8,972 B, chain rooted at 0x61092), i.e.
  worst-case main-stack bottom ≈ 0xffffb584 — comfortably above the free
  window, but interrupt nesting is not included in that estimate.

**Classification:** static allocations = the 5,351 literal/interval-referenced
bytes (globals: engine state 0xffffa000–0xffffdxxx bins are densest, EEPROM
mirror at 0xffff8000–0xffff80ff — 0xffff8000 holds the 0x55aa/0xaa55 EEPROM
magic, see 0xd408/0xd44c, matching the 256 B 93c56 IC420 dump); dynamic
allocations = stacks (above) plus the pointer-driven ring buffers (queue state
0xffff9304+3i, bufs 0xffff9310/0xffff93d8/0xffff94a0/0xffff96f8, diag response
ring 0xffffd962, UDS RX 0xffffddc8).

### Latent references inside the idle-free window (60E15120_N3J1E, Method A)

| cluster | bytes | note |
|---|---:|---|
| 0xffff8000–0xffff8004, 0xffff802c–0xffff8108 | 195 | EEPROM mirror (magic at 0xffff8000; 93c56 = 256 B) |
| 0xffff8548, 0xffff8658–0xffff87be | 360 | incl. DTC master table 0xffff87b0 |
| 0xffff8900–0xffff8910, 0xffff893a | 18 | |
| 0xffff8d4c–0xffff8d56, 0xffff8e6c–0xffff8f97, 0xffff8f98–0xffff8fe8 | 125 | |
| 0xffff9010–0xffff9110, 0xffff9150–0xffff917e | 304 | incl. labeled 0xffff9150 |

308 bytes total. Subtracting them from the 4,864 B window leaves **3,852 B
static-free**, largest contiguous runs: **0xffff8109–0xffff8547 (1,087 B)**,
**0xffff893b–0xffff8d4b (1,041 B)**, 0xffff917f–0xffff92ff (385 B),
0xffff87bf–0xffff88ff (321 B).

## 11. Related subsystems / next steps

- Feeds [live_tuning_feasibility_report.md](live_tuning_feasibility_report.md)
  (ROADMAP F item 3): RAM shadow budget ~2 KiB contiguous on every ROM; cave
  budget per-ROM per §3.
- Next measurement step: re-run the write-tracking scan under drive-cycle
  replay (`data/logs/`) to get a running-condition free-RAM bound.
- If a ROM-specific patcher is written, re-run the free-flash scan for that
  ROM (the patchers already do verified-all-0xFF discovery) and record the
  chosen cave here.
