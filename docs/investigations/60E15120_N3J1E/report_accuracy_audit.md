# Report accuracy audit — status and open findings

Binary-level re-derivation of the subsystem reports against
`submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`) and
`reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm`.

Every report was checked against the binary when it was written, and the
pipeline validators re-check ROM hashes, instruction bytes, report sections and
prose claim shapes on every run
([`validate_export.py`](../../../utilities/scripts/rx8-pcm-pipeline/validate_export.py),
[`validate_reports.py`](../../../utilities/scripts/rx8-pcm-pipeline/validate_reports.py),
[`verify_claims.py`](../../../utilities/scripts/rx8-pcm-pipeline/verify_claims.py)).
Those checks do not re-derive *numbers*: a branch polarity, an access width, a
threshold or a caller attribution can be wrong while every validator stays green.
The audit below re-derives them claim by claim — read the disassembly, resolve
the literal pool, check the compare operands and the access instruction — and
records what does not match.

Continuation is tracked as a ROADMAP item; see
[`ROADMAP.md`](../../../ROADMAP.md) (open work, C group).

## Status

| Report | Home | State |
|--------|------|-------|
| [`fuel_pump_control_report.md`](../../subsystem-logic/fuel_pump_control_report.md) | subsystem-logic | **audited, corrections applied** (12 findings, 12 corrected) |
| [`alternator_control_report.md`](../../subsystem-logic/alternator_control_report.md) | subsystem-logic | audited, 9 findings **pending** |
| [`immobilizer_report.md`](../../subsystem-logic/immobilizer_report.md) | subsystem-logic | audited, 12 findings **pending** |
| [`knock_control_report.md`](../../subsystem-logic/knock_control_report.md) | subsystem-logic | audited, 9 findings **pending** |
| [`sbl_bootloader_report.md`](../../subsystem-logic/sbl_bootloader_report.md) | subsystem-logic | audited, 7 findings **pending** |
| [`throttle_dbw_control_report.md`](../../subsystem-logic/throttle_dbw_control_report.md) | subsystem-logic | **audited, corrections applied** (12 findings, 12 corrected) |
| the 20 reports still at the `docs/investigations/60E15120_N3J1E/` root | investigations | not audited |

## Method

For one report: read it, list every claim that names an address, constant,
pool word, branch condition, access width, caller or table, then re-derive each
one from the disassembly and the raw ROM bytes, resolve the pool operand of the
`mov.l`/`mov.w @(disp,pc)` that loads it, and record the instruction address
that proves the corrected statement. Findings are listed with their proof
addresses so the next pass can re-check a claim in one lookup; nothing is applied
to a report before that re-check (AGENTS.md rule 7).

Two machine checks carry the numeric load where a report has many of them: the
per-subsystem verifier under `utilities/scripts/rx8-pcm-pipeline/`
(`verify_fuel_pump_chain.py` is the pattern) re-reads every cited pool,
instruction word and ROM threshold and writes its log into the subsystem's
`reviews/` folder, with a pytest that re-runs it and compares the committed log.

## Open findings — subsystem-logic reports

Each item is *unverified until re-checked at the binary level*: re-read the cited
instruction and pool before applying the correction. Addresses are ROM
addresses; RAM cells are `0xffff....`.

### [`alternator_control_report.md`](../../subsystem-logic/alternator_control_report.md)

| # | Where | Wrong | Correct | Proof |
|---|-------|-------|---------|-------|
| 1 | report §2.7 | `0x2635c` "sets `low_voltage_latch` `0xffffb5b2` when `0xffffb654` ≥ 8.486699" | latch is **cleared** at ≥ 8.486699 and set only when the `0x138` timer `0xffffb60e` reaches 0 (i.e. below the threshold) | `0x263fe` `fcmp/gt`, `0x26400` `bf/s 0x26452` (reload from `0x7496e`), `0x264a0`–`0x264aa` (set when timer 0), `0x264b0`/`0x264b2` (clear) |
| 2 | `reviews/alternator_control/README.md` §4 | DTC timers "reload `0x138` under fault conditions and count down otherwise" | reload while the fault condition is **absent**, count down while it holds | `0x257f4`/`0x257f6`, `0x25802`/`0x25804`, `0x2580a` (`r12 = 1`), `0x25816` `bt/s 0x2585a` → `0x2585c` reload |
| 3 | `alternator_labels.json` `000257b4` | reload when `b654 > 18.471 \|\| b658 > 15.938 …` | reload requires `b654 <= 18.471 && b658 <= 15.938` (that branch is the P2504 confirmation) | same as #2; 18.471 @ `0x74978`, 15.938 @ `0x7497c` |
| 4 | `alternator_labels.json` `0002616e`, `reviews/…/README.md` §2 | "`b600`/`b604` = 406.25/700.0" | `b600` = 406.25 **or** 700.0, `b604` = 562.5 **or** 750.0 | `0x261ea` pool `0x749ec` = 406.25, `0x261ec` pool `0x749f0` = 562.5, default pools `0x749e4` = 700.0 / `0x749e8` = 750.0 |
| 5 | `alternator_labels.json` `0002ce18` | "called from the `0x25xxx` alternator chain" | only caller `0x2cb80` (pool `0x2cbe0`), mask-`0x10` batch `0x2cb64` (from `0x1153c`) | pool scan of `0x0002ce18` → `0x2cbe0` only |
| 6 | report §4.5, `reviews/…/README.md` §6 | "168,592 instruction **bytes**" | that is the instruction **count**; bytes = 337,184 | `wc -l` of the disassembly; `validation.json` holds both keys |
| 7 | report §4.2 | `high_load_flag` `0xffffb5b3` listed as a RAM alias of this pass | the record has 10 RAM aliases and `0xffffb5b3` is not one of them | `alternator_labels.json` `ram_aliases` keys |
| 8 | report header, `alternator_labels.json` `source` | `submodules/Mazda_RX8_PCM_Reverse_Engineering/…` | `submodules/Mazda_RX8_PCM_ReverseEngineering/…` | `git ls-files submodules` |
| 9 | report §3/§4.1/§4.2, JSON `0002590a` | `charging_dtc_timer_b` | `candidate_charging_dtc_timer_b` (medium confidence → `candidate_` prefix) | `named/firmware_named.c` definition |

Under-specified in the same report (decide whether to reword): `0xffffbcc4`
"for drivability compensation" (only reader `0x2ce66`), table `0x6a524` cell
encoding (descriptor type byte `0x04` against `0x08` everywhere else in the
subsystem), the `b617`/`b618` "cold mode" names, the 14.2 V path (also requires
`b619`, `b61a`, `b64c`), `0x25b36` described but unlabeled and absent from §4.1,
`0xffffb5b0` used with no map row, and the "36 export files renamed" /
"134 passed" bookkeeping in `validation.json`.

### [`immobilizer_report.md`](../../subsystem-logic/immobilizer_report.md)

| # | Where | Wrong | Correct | Proof |
|---|-------|-------|---------|-------|
| 1 | JSON `rom_code_patterns["0x34b10"]`, `reviews/immobilizer/REVIEW_NOTES.md` | pool `0x34fc4` → `0xffffc204`, `0x34fc8` → `0xffffc200` | the reverse: `0x34fc4` = `0xffffc200`, `0x34fc8` = `0xffffc204` | `0x34f54`/`0x34f56`, `0x34f58`/`0x34f5a`, `0x34f5c` `cmp/eq r2,r3` |
| 2 | JSON `ffffdfa0`, TSV type cell, JSON `00016b20`, report §4.6 | "`u8 bit0`", tested as `bit0 == 0` | u16 cell read as a byte; the test is a whole-byte zero test | `0x11ca` `mov.w`, `0x11f0`–`0x11f4` (u16 increment), `0x16b22` `mov.b` / `0x16b24` `tst` |
| 3 | JSON `000011c4` | "stores byte 0" | stores **u16** 0 | `0x11ca` `mov.w r3,@r2` |
| 4 | report §4.3/§4.6, JSON `ffffdfa0` reader | two accessors (`0x11c4`, `0x16b20`) | three: `0x169d4` also writes the byte there, `= (ROM[0x6e224]==0xff)` | `0x169d4` pool `0x16af6`, `0x169e4`/`0x169e8`, `0x169ea`/`0x169ec` |
| 5 | report §4.1, JSON `ffffd1e2` | type `u8/s16` | u16 (word accesses, saturates at `0xffff`) | `0x56766`–`0x56776`, pool `0x567dc` = `0xffff` |
| 6 | report §2.7, JSON `000360a8` | "mixed each dispatcher pass", "called in the dispatcher tail chain" | only reference is an indirect call in `0x371b6` when a parameter byte equals `0x20` | `0x371fa`, `0x37200` pool `0x37278`, `0x37202` `jsr` |
| 7 | report §2.3 | unpack `0x38150` "sets the pending flag `0xffffc4bf`" | `0x38111c` sets `c4bf` and `c4c0` after the unpack | `0x38140`/`0x38146`, `0x38148` |
| 8 | report §2.4 mermaid | edge `S5 --> S1 : c21e==1` | state 5 + `c21e==1` goes to `0x34e68`, which dispatches on `c221` → state 2 or state 0 | `0x35282`–`0x35286`, `0x34ea2`/`0x34ea6`, `0x34f22`/`0x34f28` |
| 9 | report §2.4 step 5 | "every exchange step has a ~500-count timer; expiry routes to the rejected state" | `c20c`/`c20e` = 500, `c214` = 500 (250 after authorization), `c210` = 250, `c216` = 750, `c212` = 15000/500; a `c210` expiry only drops the lamp and `c1d0`, a `c214` expiry in state 3 sets `c226` | pools `0x34b4a`/`0x34f9e`/`0x35304`, `0x35014`–`0x3501e`, `0x3515c` |
| 10 | JSON `00035f64` | "clamps `c276 <= 5`" | `c282` is clamped to ≤ 2; `c276` is **set to 0** when > 5 | `0x35fbe`–`0x35fca` (`c276`, pool `0x3607c`) vs `0x35ff6`/`0x35ffe` (`c282`, pool `0x36078`) |
| 11 | report §4.1, `REVIEW_NOTES` item 3 | pool range `0x00356b6–0x00356d2` | ends at `0x00356d3` (the u32 at `0x356d0` = `0xffffc204`) | `0x356d0`, `0x356d4` is code |
| 12 | JSON `00034ae2` | "7 EEPROM-write sequencer steps" | 8 calls after `0x36908`: 7 `jsr` plus tail `jmp 0x361e4` | `0x34ca0`–`0x34cb8`, `0x34c54`/`0x34c58` |

Under-specified: the 93C56 byte↔device-word map (inherited from
[`eeprom_content_map_report.md`](eeprom_content_map_report.md)), the HCAN base
attribution (from [`can_mailbox_config_report.md`](can_mailbox_config_report.md)),
"seed regenerated per boot" (also refreshed in state 5, `0x35270`),
`inferred_ram_c1d0_*`-style placeholder names used as accepted aliases while the
prose calls the same cells `immo_authorized`/erased flags, the TSV `uint8[32]`
type for `0xffffc268` against the record's `u8[0x1b]`, the stale
"34 rows / 31 rows" counts in `REVIEW_NOTES`, "0x36acc–0x37bde" as the handler
extent (the handlers end at `0x37546`), and `0xffffc282` "2 = both keys
registered" (the code also accepts 1 and decrements on every seed request).

### [`knock_control_report.md`](../../subsystem-logic/knock_control_report.md)

| # | Where | Wrong | Correct | Proof |
|---|-------|-------|---------|-------|
| 1 | report §2.5/§3, `reviews/knock_control/README.md` §1.4 | `knock_enable` "run time ≥ 3 s" | timer ≥ **375** counts (`0x177` at ROM `0x795a0`); 3.75 s only if the tick is really 100 Hz, which is not established (the `0xfa` attack constant would otherwise be 2 s) | `0x13846`–`0x13850`, pools `0x1390c`, ROM `0x7a212` |
| 2 | report §4.1, §2.8, README §1.6 | `0x12300` clamps "both" timing outputs | it clamps `0xffffa638` only; `0xffffa630` is clamped by `0x121fc` | `0x123aa` (pool `0x1240e`), `0x122a8` (pool `0x122c8`) |
| 3 | JSON `ffffa744`, report §4.1 | "attack/recovery target … 0 when disabled, … else previous retard" | written on only two paths (fail-safe table, activation edge), and **no code reads it** | `0x13a7a`/`0x13aea`/`0x13ad2` (no store), only store `0x13abc` with `r13` = pool `0x13b18` |
| 4 | report §4.1, JSON `ffffc078` | "latched detection" | an unconditional copy of `(0xffffa324 != 0)` on every `0x336c4` call | `0x33942`–`0x33954` (both branches store) |
| 5 | report §2.7, §4.1 | `0xffff8038` "EEPROM address holder" | it is the learned-retard cell itself (float + three checksum fields) | `0x139d4` pool `0x13a0e`, `0x139f6` jmp `0x3dcd0`, `0x3dc36`–`0x3dcfc` |
| 6 | `reviews/knock_control/README.md` §6, `validation.json` | 33 high / 6 medium function aliases | 38 high / 1 medium (`0x00022144` → `candidate_fuel_open_loop_condition`) | `knock_loop_labels.json` |
| 7 | report §4.1, §2.2, §3, README §1 | `0x803e` as the live crank ISR / RPM producer | `0x803e` is the pre-VBR IVT slot; after `ldc r3,vbr` (`0xd206`, VBR `0x7fc50`) slot `0x2c8` = `0x00002ec0` | `0x7ff18`, `0x2ec2`/`0x2ed4` |
| 8 | JSON `ffffa344` | integrator step "floor 1.0" | 1.0 is an **upper bound** on the step | `0xc572`–`0xc57a` |
| 9 | report §2.6 mermaid | first gate `knock_active` | first gate `knock_enable` (`0xffffa73d`); the fail-safe table is taken whenever `0xffffa73e == 0` regardless of `0xffffa73c` | `0x13a70`–`0x13a86` |

Also in the same record: `ffffa378` evidence says the 200–2000 rpm filter output
"filters into `a378`" — the float lands in `a374` (`0xc40c`) and `a378` receives
its u16 truncation (`0xc410`/`0xc416`).

Under-specified: "84 RAM locations" (the rename map holds 271 entries),
`snapshot_local_renames: 8 / 192` against the record's 3, the asserted 100 Hz
tick of `0xffffa424`, the SCI0 knock-amplifier identification (firmware side
provable, peer device is a hypothesis), the unlisted `0x7a20d` calibration gate,
"resets at very high RPM" (only `a384`/`a385`/`a324` are reset, never `a734`),
"per cycle" wording for `0x13a60`/`0x13b40` steps, and the stale "section 8
memory map" pointer in `tests/test_knock_retard_dynamic.py`.

### [`sbl_bootloader_report.md`](../../subsystem-logic/sbl_bootloader_report.md)

| # | Where | Wrong | Correct | Proof |
|---|-------|-------|---------|-------|
| 1 | report §2.2, JSON `0x000011cc` | `0x11cc` increments "unless OVF is set"; `0xffffdfa0` "counts loop passes" | the keyed write, the PB15 toggle and the increment run only when OVF **is set**, so the counter advances once per WDT-overflow period | `0x11d0`–`0x11d6` (`c880`/`890e`), `0x11f0`–`0x11f6` |
| 2 | report §2.2 `0x27`, JSON `0x00001858` | "either seed reply clears `0xffffdfb2`" | the fixed-seed reply **sets** it, the zero-seed reply clears it, any `27 02` clears it at `0x1968` | `0x1914` + `0x1916` (set), `0x18c2` + `0x18c4` (clear) |
| 3 | report §2.2, §4.1, four JSON keys | `0x154c` first / `0x15a6` consecutive / `0x1624` single / `0x1654` flow control | `0x154c` **single** frame, `0x15a6` **first** frame, `0x1624` flow-control **transmit**, `0x1654` **consecutive** frame | dispatch `0x13a4`/`0x13aa`/`0x13ae`, calls `0x13b6`/`0x13d0`/`0x13e0`/`0x13f2`, `0x154e`, `0x15b6`, `0x1626`, `0x165c`–`0x166e` |
| 4 | report §2.2 ("no flash-write path"), README, JSON `0x1d78` | "only HCAN0 (`0xffffe400`) and SYSC (`0xffffed00`)" | the `0x1000`–`0x1ffb` pools reach HCAN0, the WDT pair `0xffffec10`/`0xffffec12` and ports `0xfffff720`/`f738`/`f756`; there is no `0xffffed00` reference (the no-flash-control-register conclusion still holds: nothing in `0xffffe800`–`0xffffe8ff`) | pool enumeration over the block, `0x1278`, `0x1288`, `0x129a`-region port pools |
| 5 | report §2.1, §3, JSON `0x000004e0` | warm/cold selection driven only by magic + WDT overflow | a non-zero parameter writes `0xffffdfa8`, inits mailboxes (`0x8f6`) and goes cold `0x6c8` unconditionally; the erased-flash fallback repeats the WDT check and drops to cold when it returns 0 | `0x4fc`–`0x500`, `0x556`–`0x560`, `0x532`–`0x53a` |
| 6 | report §4.5, JSON `0x16dc`, README | "9 tests" / "7 tests" / "11 tests" | 11 test functions | `tests/test_sbl_bootloader.py` |
| 7 | JSON `0x00001038` | erased-flash checks "pools `0x1088`/`0x108c`" | pool `0x1088` = `0x7fffc` (checked and dereferenced to obtain the `0x2000` word); `0x108c` = `0x7fff8` is the fallback **app entry** | `0x1052`–`0x105c`, `0x1062`/`0x1066` |

Under-specified: the cross-ROM build-A/B anchors (only the reference instance is
checkable here and holds), the dynamic cycle counts (which inherit finding 1's
premise), the on-car handshake log, `0x680de → 0x6892a` (no reference to
`0x0006892a` exists anywhere in the ROM — the edge is a callgraph artifact),
`0x1ed0`'s mailbox-format wording, `0x5a3d8`'s callers, and the phase reuse of
`0xffffdfb4` (cold-loop ring index vs `sbl_transfer_active`).

Note that this report's memory map is backtick-wrapped, so `validate_reports.py`
skips all of it today (see the `validate_reports` entry in the ROADMAP
discrepancy register): the 102 map rows become checked only after that parser
gap is closed.

## Reports not yet audited

The 20 reports still at the `docs/investigations/60E15120_N3J1E/` root are
migrated into [`docs/subsystem-logic/`](../../subsystem-logic/README.md) by the
C group's migration items; they are audited **after** their migration so each
subsystem is re-derived once, in its final shape. The four subsystem-logic
reports whose findings are listed above are the head of the queue.
