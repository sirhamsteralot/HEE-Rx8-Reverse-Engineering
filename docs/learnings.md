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
- The disassembler prints the **computed EA** in `@(disp,pc)` annotations (e.g.
  `mov.w @(0x123fc,pc)` at 0x123e0 -> literal word at 0x123fc = pc+4+disp*2), so
  read the printed value directly as the literal-pool address — do NOT re-apply
  pc+4+scaling to it. Literal pools show up as gaps in the listing.
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
  with a mandatory memory map (function + RAM address tables) and a plain-language
  §1a after the executive summary (standard since 2026-10-31, AGENTS.md rule 8;
  style example `ignition_timing_report.md` §1a). Keep historical
  reports intact; append a dated "Update" addendum for later passes.
- `scripts/validate_reports.py` checks every report (sections, ROM hash, all
  memory-map addresses vs index/TSVs/ROM) — run it after any report edit.

## Emulator build-out (2026-10-31, Phase 1 fidelity pass)

Hardware facts that the first emulator pass got wrong (all fixed; keep them):

- **RAM is 0xffff6000-0xffffe000** (32 KiB; design doc §1). A profile with
  ram start 0xffff8000 silently unmapped task stacks at 0xffff74xx — stack
  writes were dropped and pr pops read 0 (PC jumped to 0). Symptom: boot crash
  at a task-return (`lds.l @r15+,pr` → 0).
- **ROM/flash is read-only**: CPU stores to 0x0-0x7ffff must be ignored (counted
  in `bus.rom_writes_blocked`). The boot's mailbox-clear loop writes low
  addresses; on real HW those hit flash and vanish, in the emulator they
  zeroed vectors/code (0x31c) and killed the WDT handler.
- **VBR is not 0**: the firmware sets VBR=0x7fc50 (ldc at 0xd206); the real IVT
  lives at 0x7fc50+offset (CMI10B = vec 178 → 0x7ff18 → trampoline 0x2ec0;
  WDT ITI = vec 214 → 0x7ffa8; HCAN0 RM0 = 0x7ffa0). `cpu.interrupt(offset)`
  must read `r32(vbr+offset)` and push SR+PC on the stack, set SR mask (SH-2E
  manual 6.1.3/7.2.5).
- **WDT**: 0x31c is a *subroutine* (ends rts, clobbers r0-r4) that the firmware
  polls/calls itself — it is NOT an interrupt entry. Overflow = TCSR OVF flag
  only; do not redirect PC (a direct jump mid-`dt`-loop clobbers the loop
  counter and hangs boot). Service = keyed 0xa53c write.
- **RCAN (HCAN0) at 0xffffe400**: MCR 0x00, GSR 0x01, BCR 0x02, MBCR 0x04,
  TXPR 0x06, TXCR 0x08, TXACK 0x0a, ABACK 0x0c, RXPR 0x0e, RFPR 0x10, IRR 0x12,
  MBIMR 0x14, IMR 0x16, UMSR 0x1a, MC mb at 0x20+8mb, MD mb at 0xb0+8(mb&0xf).
  Pending regs are write-1-to-clear (init writes RXPR=0xffff etc. to clear).
  GSR bit3 follows MCR bit0 (reset handshake; boot waits on it ~4000 iters).
  Mailbox mask = `1 << ((mb+8)&0xf)` (ROM table 0xd914). Standard CAN ID stored
  in MC[4..5] **low byte first** (`MC[4]=(id<<5)&0xff, MC[5]=id<<5>>8`); DLC in
  MC[0]. TX: write TXACK=mask, payload→MD, TXPR=mask → frame leaves (tx_log),
  TXACK sets, TXPR clears. RX poll: RXPR bit set → if UMSR bit clear, clear
  RXPR and copy MD out (FUN_000010fe). Diag mailboxes: 14=0x7e0 RX, 15=0x7e8 TX
  (ref_resetOBDCAN_ 0x109c); UDS RX descs 0x4dffc (0x7e0), 0x4dfec (0x7df) →
  buffer 0xffffddc8; TX desc 0x4e00c (0x7e8, buf 0xffffddd0).
- **DMAC at 0xffffecb0**: boot waits for CHCR0 TE (bit1) at 0xd5fa; model =
  CHCR write with DE (bit0) → copy DMATCR bytes SAR→DAR, set TE, clear DE.
- **ADC at 0xfffff800**: ADDRnH/L at 2n (n<12), ADCSR0/ADCR0 0x18/0x19,
  ADDR12-23 at 0x20+2(n-12), ADCSR1/ADCR1 0x38/0x39, ADDR24-31 at 0x40+2(n-24),
  ADCSR2/ADCR2 0x58/0x59 (offsets overlap — check ADCSR/ADCR first). Firmware
  starts a scan (ADCRn |= 0x20), busy-waits ADCSRn bit7 (ADF), then reads ADDRn
  as a 16-bit word (0x6884 sweep → RAM 0xffff9ee4+). Channels: AN3=MAF,
  AN4/AN5=TP, AN6=APV, AN10=knock, AN28=ECT, AN29=IAT.
- **ATU-II at 0xfffff400**: TSTR3 (0xfffff402) **bit0** starts ch10; ch10B compare
  (TCNT10B 0x2c4 vs OCR10B 0x2d8, TIER10 bit2) → CMI10B interrupt → vector 0x2c8;
  OS tick setup ref_setInterruptTimer 0x7778. Crank input capture: ICR0AH
  0xfffff434, ICR10AH 0xfffff6d0 — the rpm path (0x77f0/0xcf96 read ICR0AH;
  ISR 0x803e computes rpm = 1.2e8/sum of the 6-entry ring at 0xffff9fd0).
  Injector outputs: DCNT8A-P 0xfffff640-0x65e, GR1A-H 0xfffff444-0x452; channel
  map ROM 0xd7d4 (12-byte records: DCNT ptr, GR1 ptr, TIER mask).
- **CPU fixes**: `fmov.s` needs @rN+ (load) and @-rN/@rN+ (store); `sts/lds`
  must cover fpscr/fpul; `fdiv` must follow IEEE (x/0=±inf, 0/0=NaN) — Python
  raises ZeroDivisionError; `dt`/`bf/s` delay-slot semantics are correct but
  fragile when a mis-modeled interrupt clobbers r4 mid-loop.
- **Direct-call harness** (`utilities/scripts/emu/harness.py`): set r15 to a RAM
  stack, pr=SENTINEL, pc=func, args in r4-r7 (int) / fr4-fr7 (float, SH-2E ABI),
  run until pc==SENTINEL (or stop_at e.g. the idle loop 0x3dac for the task
  dispatcher, which never rts). Return r0/fr0. Use it to execute the ROM's own
  functions for dynamic validation (`tests/test_phase1_dynamic.py`).
- **No C compiler on the current Windows box**: MSVC cl.exe exists but the VC
  headers (vcruntime.h) are not installed; mingw has no gcc. Host C tests
  (AGENTS.md `cc …` pattern) need a machine with a working toolchain; the
  emulator cross-check uses a float32 Python port of `rx8_math.c` meanwhile.
- **Emulator FPU is host double** (E1): `fmac` behaves as fused; results can
  differ from strict float32 SH semantics in the last ulp — compare with
  tolerance for filter-style code, bit-exact for min/max/clamp/absdiff.
- 60E1B900_N3ZBEH uses opcode 0x957a (outside the 60E15120 corpus) → unknown-opcode
- **IVT lives at VBR=0x7fc50** (set at 0xd206): ROM vector slot = 0x7fc50 + offset.
  Useful offsets: CMI10B 0x2c8 (crank/rpm path 0x803e), CAN-RX/scheduler 0x378
  (handler polls HCAN0 RXPR/MBIMR, runs CAN RX poll 0x11d88 + ref_osTaskScheduler
  0x9630 - found by sweeping all IVT entries and watching for those), WDT ITI
  0x358 (vec 214, Sh7055h.pdf table 7.3). Unused vectors' trampolines end in a
  deliberate halt loop at 0xa4be.
- **Boot polls ICR_W (0xffffed18) bit15 at 0x8ea** = NMI pin level (manual 7.3.2);
  model as a SYSC peripheral input (`nmi_level=1`), not an io_read_override.
- **CAN RX interrupt**: `can.inject()` raises IVT offset 0x378; the ROM's handler
  then moves the frame to the UDS buffer 0xffffddc8 by itself during a plain run.
  UDS service dispatch (FUN_000680a0) is gated by the vehicle-input latch
  DAT_ffff9ec8 bit0 (PFDR bit0, debounced by 0x6744/0x6796) and the OS task
  context switch (0x3db0, called from ref_setSR on ISR exit) - the remaining E6
  gap; until then drive the profile `uds` entry points (0x11d88/0x680a0/0x3c2a).
- `tst Rm,Rn` sets T=1 when (Rn & Rm) == 0 - easy to get backwards when reading
  branch conditions by hand.
- Vector sweep method for "which interrupt does X": boot to idle, then for each
  IVT entry call `cpu.interrupt(off, priority)` once and grep the PC trace for
  the target function - cheap and decisive.

  stop; regenerate `opdec.py` from that ROM's disassembly before running it.

## Calibration descriptor scan (2026-10-31, P3)

- **Cal region auto-detect**: find `Copr.DENSO` in the ROM above 0x60000; the
  0x1000-aligned block containing it is the cal start (0x6c000 for most ROMs,
  0x6d000 for 60E0FB00/60E0FC00/60E1B900, 0x71000 for 60E32000). The region
  between code-end and cal-start holds the packed descriptor array.
- **Descriptor formats** (big-endian): 2D base 12 B `>HBBII` (n, type, res=0,
  axis_ptr, data_ptr); 2D scaled +8 B. 3D base 20 B `>HHIIIB`+3 pad (nx, ny,
  ax, ay, data, type). Type codes: 0=f32, 4=u8, 8=u16, 12=s8, 16=s16 (dispatch
  tables 0x2098/0x210c). Axes are always float32.
- **Scan every 4 B**, validate count/type/pointers-into-cal-region/bounds, then
  resolve overlaps by walking sorted addresses with a next-free cursor (base
  span 12/20 B) — descriptors are packed, so a candidate inside another's span
  is a false positive (dropped 1 in N3J1E out of 588).
- **Monotonic-axis check** is a strong false-positive filter: 0 non-monotonic
  axes across all 587 N3J1E tables and all 10 stock ROMs.
- **Scaled vs base** is NOT reliably detectable in packed arrays (the trailing
  8 B can look like the next descriptor); don't use the scaled flag for span.
- Scan window: [cal_start−0x8000, cal_start) — 32 KB covers all observed layouts.
- Cross-ROM matching by (dim, counts, type, axis values) is structural only;
  same-shape/different-meaning pairs exist (huge float diffs in the report are
  those, not real calibration changes).

## Emulator fidelity hardening (2026-10-31, ROADMAP group B)

- **DIV1 needs the Q/M SR bits** (bit8=Q, bit9=M per Sh7055h.pdf fig 2.2). The
  old impl only set T and did no arithmetic — the ROM's 161 div1 sites (32-bit
  divide at ref_LongFunc 0x2158) all broke. Full algorithm per the Renesas SH
  instruction-set reference (shared-ptr.com/sh_insns.html "void DIV1"):
  old_q=Q; Q=MSB(Rn); Rn=(Rn<<1)|T; conditional add/sub by (old_q,M) with
  borrow/carry detect; Q updated; T=(Q==M). Validate with the ROM itself as
  oracle: call 0x2158(r4=dividend,r5=divisor), quotient lands in r4.
- **ROTCR was aliased to ROTCL** — rotate-right-through-carry executed as
  rotate-left. 21 ROM sites affected. Separate "rotcr" shift kind now.
- **FPU is single precision**: round every arithmetic result to f32
  (`_f32(_bits(x))`), and f32-round float args in harness.call (FR regs are
  32-bit). The 0x23b0 filter then matches the reimplementation bit-exact.
- **Interrupt masking**: prioritized interrupts with level <= SR.I3-I0 are
  deferred, delivered when ldc/rte lower the mask (SH-2E manual 7.2.5).
  Previously every interrupt() fired immediately regardless of mask.
- **E6 trace findings**: CAN RX ISR exits via plain RTE (no ref_setSR call), so
  the 0x3db0 wake check never runs on that path. OS tick (ATU-II ch10B CMI10B
  0x2c8) never fires: ROM arms it from task[8] (0x648e→0x759e→0x7778→0x7b58,
  OCR10B = ROM table 0xd76d[ffff9f95*2] & 0x7f) which needs a scheduler pass
  that needs the tick. UDS entry 0x680a0 is gated by vehicle-latch word
  0xffff9ec8 bit0 (set by vehicle_inputs_poll 0x6744 = PFDR copy, task[17]).
  With tick + latch, uds_entry fires autonomously; response TX still needs the
  service task dispatched.

## Renesas Simulator Debugger cross-check (2026-10-31, ROADMAP group B)

HEW 9.4.3 SH-2E simulator (`Sdsh2e.dll`, SH7055F) used as an external oracle for
`utilities/scripts/emu/` via `compare_traces.py`. Setup + recipes live in
[the emulator README](../utilities/scripts/emu/README.md); findings here.

- **Trace export**: no console TRACE command — use the Trace window (Ctrl+T),
  set Trace ON, GO, stop, then save the TSV. Console trace commands
  (`trace ON/GO`, `st ...`) reject parameters. `compare_traces.py` auto-parses
  the TSV: header row starts with `PTR`, execute-stage rows have `E` in the
  Pipeline column and the instruction text; rows are sorted by the Cycle column
  (the file is not cycle-ordered).
- **No NMI pin model**: Sdsh2e does not simulate the NMI pin, and the ROM
  zeroes ICR_W at 0x8e6 before polling 0x8ea — so from reset the sim takes the
  non-NMI path. Workaround ROM `input/60E15120_N3J1E_sim-nmi-nop.bin` NOPs the
  `bt 0x8ea` at 0x8f0 (PC-trace-equivalent). Never commit anything from
  `input/`.
- **Console radix gotcha**: the console wants `H'...'` hex; `0x...` arguments
  mis-parse (`go H'D5FA'` then fails as an address). Use `H'08F0'` style.
- **Console command arity**: `memory_fill <start> <end> <data> <mode>` needs
  start AND end (`memory_fill 0xFFFFED18` errors "Parameter '<end>' is empty");
  `memory_display <addr>` shows 16 bytes. `sdb <addr>` sets a breakpoint from
  the console (Goto Line/Ctrl+G may be unavailable in the disassembly view).
  Memory writes made in the IO/memory view are volatile — they are cleared on
  `go` (reset) + stop, so set breakpoints instead of relying on patched memory.
- **Results**: NMI-poll loop 0x8ea vs our emulator (NMI low): MATCH 20000/20000
  steps. Full boot from reset (NOP-patched ROM): MATCH 147/147 steps, then
  divergence at the `bf` at 0x9d0 reading GPIO PLIOR_W 0xfffff756 bit3 — a
  peripheral-pin default difference (Sdsh2e has no PLIOR model), not a CPU
  bug. Zero CPU-caused divergence in both segments.
- **Trace format change**: our emulator trace now appends the delay-slot PC
  after every branch (`sh2e.py` `_branch`), so a taken branch is two entries
  (branch + delay slot). Golden fixture
  `tests/fixtures/boot-60E15120_N3J1E-200k.trace` regenerated (319731 entries,
  header documents the format); re-verified MATCH after the E1/E7/interrupt/
  delay-slot changes.

## Decompiler triage (2026-10-31, group C item 2)

- `triage_export.py` classifies every `non_instruction_ranges.tsv` blob by content AND by
  referrers: the disassembly's `@(0xEA,pc)` operand is the **computed EA**, so grep/scan
  it directly for range referrers — no pc+4+scaling re-application (see SH-2E facts above).
  1,695/1,759 ranges have pc-relative referrers; the 64 without are pointer-reached data.
- Gotchas found while calibrating: the IVT is only 0x0-0x3f (code starts at 0x40, so a
  pool at 0x3f8 is NOT vectors); "ascii_string" needs a printable run >=12 + NUL/space,
  else pointer blocks and the 0x4414 `40 21` shar-sled classify as text; float pools can
  be tiny-magnitude (|x| >= 1e-6 counts as sane).
- Warning categories that mean nothing: `unreachable_ram_block_removed` (dead-code elim),
  `overlapping_symbol_labels` (inner LAB_/DAT_ labels), `infinite_loop_block` with a
  `bra self` spin (halt idiom, e.g. 0xd8/0xd21e/0x563de). `jumptable_truncated` on the
  0x54d90/0x55a7c pattern = 8-byte `{key:u8<<24, handler:u32}` record tables (same format
  as UDS 0x5eb18/0x5eb40) — recover by reading the pool word, then the records to key==0.
- 0x33b6 is a 2-byte orphan (`7638` + illegal 0x0000): no u32 ref, no branch target, no
  callers — treat 0x33b6-0x348f as data, keep the FUN_ label address-only.
