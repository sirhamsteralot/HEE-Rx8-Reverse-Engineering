# REVIEW_NOTES — ignition key-state / power-state review

Skeptical re-review notes on the findings in
[`../../ignition_power_state_report.md`](../../ignition_power_state_report.md) and
[`README.md`](README.md) in this folder.

## Binary-level re-checks performed

1. Re-read the raw ROM at every cited entry cell: u32 @0x1000 = 0x00001298,
   u32 @0x7fff8 = 0x0000d204, u32 @0x7fffc = 0x00002000; warm-stub bytes at
   0x1298 = `93 56 43 0b e4 00 af fe 00 09` (jsr 0x1038 + halt); NMI poll loop
   bytes at 0x8ea = `62 41 62 2d 22 58 89 fb`; key-off timeout u32 @0x74940 =
   0x00036ee8. Cross-checked against the same cells in all 11 ROMs via
   `data/labels/cross_rom/ignition_power_state_addresses.json` (warm 0x12b4 and
   recovery 0xd49c/0xd494 on the family B/C ROMs, app 0x2000 everywhere).
2. Re-read the literal pools of every renamed function against the disassembly:
   0x4e0 pool 0x586-0x5a8 (0x170, 0x41c, 0x3d4, 0x6c8, 0x1000, 0x5aa5a55a,
   0xffffdffc, 0x2000-fallback 0x7fffc, 0x7fff8, 0xdfa8, 0x40);
   0x252c2 pool 0x25374-0x253a8 (0xffffb57a/aa68/df99/b578/b582/b583/0x74940/
   0x8104/0x3dc70/0x9ea2); 0x9e68/0x9ea2 pool 0x9f18-0x9f40 (0xe0, 0xff0f,
   0xfffff74e, 8, 0x4bbc, 0x2054, 0xa850, 0x239c, 0x1388); 0x6744/0x6796 pool
   (0xfffff74e, 0xfffff72c, latches 0xffff9ec8/9eca/9ed8, 0x70ac).
3. Re-checked the GPIO idioms end to end: PFDR_W = 0xfffff74e, PDDR_W =
   0xfffff746, PBDR_W = 0xfffff738, ICR_W = 0xffffed18 against `symbols.tsv`;
   PF3 set/clear immediates r5=8 r6=1 (0x9e68) vs r5=8 r6=0 (0x9ea2) through
   the shared helper 0x4bbc; PB15 heartbeat 0x8000 set/0x7fff clear in 0xa850.
4. Re-derived the thunk 0x253b2 from its body: `mov.l @(0x25414,pc),r3; jmp @r3`
   with pool 0x25414 = 0x0002529e → `jump_to_candidate_shutdown_e2_flag_clear`.
5. Labels JSON ↔ TSV ↔ function_index coverage machine-checked by
   `verify_claims.py` (PASS) and pinned by `tests/test_ignition_power_state.py`
   (18 tests: ROM cells/bytes, pools, TSV/JSON/index consistency, cross-ROM
   artifact regeneration idempotency).

## Corrections made during review

1. `ref_checkCANsomethingKeyOnBased` (0xdcc0) renamed
   `can_error_recovery_key_gated` — it gates CAN error recovery on the key-on
   flag; references updated in `can_mailbox_config_report.md` too.
2. 0xffffaa68 documented as the key-on flag (driven by PFDR bit0 via
   0x1a5d8/0x1a600); the RPM-derived engine-running flag is 0xffffa428 (0xe274)
   — the inherited name `engine_running_flag` is kept but its producer is now
   explicit.
3. `ref_reset_ZERO` (0x1038) → `warm_reset_dispatcher`, `ref_resetHandler_`
   (0x4e0) → `reset_handler_warm_cold_select`, `ref_getFromGPIO_` (0x70ac) →
   `sci0_gpio_expander_read`; stale name references updated in
   `can_mailbox_config_report.md`, `labeling/thunk_audit_report.md` and the
   design doc §3/§5.6.
4. The warm-entry stub 0x1298 is a mid-function entry, not a function_index
   row — moved out of the report's function memory map into the ROM entry-point
   table and tracked as `code_entry_points` in the labels JSON.

## Not verified / open

- No emulator or hardware run: the 0x36ee8-tick shutdown timeout in wall-clock
  seconds, the relay drop delay, and the 0x9ea2 loop's behavior on key return
  are unmeasured.
- Chip-pin ↔ connector-terminal mapping (PF0/PF15/PF3/PD11 ↔ 4Q/4E/4C/5H/5J)
  is board routing, unresolved (discrepancy D2); the pinout has no chip-pin
  data.
- Starter-relay driver (terminal 5A) not found; SBL→app handover into 0x61a8
  out of scope here.
- The 6 `candidate_` names remain unproven hypotheses (0xd21e, 0x2529e,
  0x252ae/0x252b8, 0x48d38, 0x48d70).
