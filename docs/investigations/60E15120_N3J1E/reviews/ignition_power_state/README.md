# Targeted static review: ignition key-state / power-state logic

Scope: how 60E15120_N3J1E (RX-8 PCM, SH7055F) senses the ignition-switch state
(key-off / ON / crank-relevant inputs) and reacts at boot, while running, and at
key-off shutdown. Read from the canonical export (`decompiled/`), the
disassembly and the raw ROM (SHA-256
`a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`, untouched).
Root report: [`../../ignition_power_state_report.md`](../../ignition_power_state_report.md);
record: `data/labels/60E15120_N3J1E/ignition_power_state_labels.json`.

## 1. Boot entry split (warm vs cold)

- `reset_handler_warm_cold_select` 0x4e0 (was `ref_resetHandler_`): param==0
  path compares u32 @0xffffdffc (pool 0x5a0) against 0x5aa5a55a (pool 0x59c) at
  0x508; on mismatch calls `wdt_overflow_reset_check` 0x5b0 with r4=7 (pool
  0x5a2 area; any WDT TCSR 0xffffec10 OVF bit 0x80 counts => warm). Warm entry
  = u32 @ROM 0x1000 (pool 0x58e; ROM 0x1000 = 0x1298), with flash-resident
  fallbacks u32 @0x7fffc (pool 0x5a4; = 0x2000) and u32 @0x7fff8 (pool 0x5a8;
  = 0xd204). Cold = 0x6c8 (pool 0x58c). Writes 0x5aa5a55a to 0xffffdffc at
  0x562-0x566, then `jsr` 0x40 with r4 = chosen entry (0x40 sets SP and jmps
  @r4) and halts. param!=0 branch stores the cause byte to 0xffffdfa8
  (pool 0x590) and selects cold 0x6c8 — this is the software-reset path taken
  from `candidate_main_task_software_reset_check` 0xd21e (was `ref_main__`)
  when byte 0xffff9f8c != 1.
- Warm stub at ROM 0x1298 (mid-function entry; bytes `93 56 43 0b e4 00 af fe
  00 09` = `jsr` 0x1038 via pool + halt): `warm_reset_dispatcher` 0x1038 (was
  `ref_reset_ZERO`) — param!=0 does port/CAN init 0x12a2 and jumps 0x1378;
  param==0 falls to the flash-pointer check → recovery entry 0xd204 (u32
  @0x7fff8): sets VBR=0x7fc50, FPSCR=0x40001, then `manual_reset_finalize`
  0xd20c (was `ref_handleManualReset_`): 0x4c7a(0xffff768c), 0x9e68, halt.
- `recovery_finalize_set_pf3_halt` 0x9e68: 0x4c80, `shutdown_ram_swap_semaphore_mark`
  0xd518 (checksum 0xffff9300..0xffffdffb, SBL semaphore u32 0x3c @0xffffdff8,
  WDT pulse 0xa850, RAM swap 0xffff6000-0x7fff ↔ shadow 0xffff9300), then
  PFDR_W 0xfffff74e bit3 = 1 (pool 0x9f1a=0xf74e, r5=8 r6=1 via 0x4bbc), halt.
- Cold entry `cold_entry_ring_dispatch_loop` 0x6c8: zeroes 0xffffdfb8, loops
  jsr 0x364 (dispatch on reset cause 0xffffdfa8), 0x3e0, 0x3b0 (100×8-byte
  ring at 0xffffd4e0), services WDT 0x31c.
- Boot NMI poll: `boot_wait_nmi_pin_high` 0x8cc zeroes ICR_W 0xffffed18; loop
  at 0x8ea-0x8f0 (bytes `62 41 62 2d 22 58 89 fb`) waits while (ICR_W & 0x8000)
  == 0. WDT keyed writes in `wdt_keyed_reset` 0x572 (RSTCSR=0x5a1f, TCSR=0x5a00
  then 0xa53c).

## 2. Key-on input chain (running)

- `vehicle_inputs_poll_pfdr_phdr` 0x6744 (was `ref_getVehicleStatusInputs_`):
  samples PFDR_W 0xfffff74e / PHDR_W 0xfffff72c into latch 0xffff9ec8 /
  0xffff9eca; `vehicle_inputs_sticky_update` 0x6796 keeps the sticky form;
  three external expander channels read via `sci0_gpio_expander_read` 0x70ac
  (was `ref_getFromGPIO_`; SCI0 regs 0xfffff000-0xfffff006, channel select via
  PHDR masks 0x4000/0x8000, exchange byte 0xff, PGDR_W 0xfffff764 bit1 toggle)
  → 0xffff9ecc/9ecd/9ede.
- `key_on_latch_from_pfdr_bit0` 0x1a5d8: 0xffffaa69 = (0xffff9ec8 & 1) != 0;
  `key_on_flag_update` 0x1a600: 0xffffaa68 = 0xffffaa69. Consumers of
  0xffffaa68: UDS dispatch gate 0x11d88 → 0x680a0, `can_rx_main_key_gated`
  0xdbf6 (IDs 0x212/216/231/430/4b0/4b1/4c0/47, also gated on engine-stopped
  latch 0xffffb578), `can_tx_main_key_gated` 0xdb58, `can_error_recovery_key_gated`
  0xdcc0 (was `ref_checkCANsomethingKeyOnBased`; bus-off/error recovery +
  full reset `can_error_full_reset` 0xdade at error counter ≥ 1000),
  key-off state machine 0x252c2, fan after-run clause 0x2f51a/0x2f65c.
- Second key-related input: PF15 (PFDR bit 0x8000) — `key_input_pf15_sample`
  0x454c0 → 0xffffcbd1 (previous), `key_input_pf15_edge_latch` 0x454d2 →
  0xffffcbd0 (edge). Combined with battery voltage in
  `candidate_key_voltage_timer_update` 0x48d38 (0xffffccca held at 0x19 while
  0xffffb590 < 6.0 V and cbd0 == 1) and `candidate_voltage_key_sanity_flags`
  0x48d70 (0xffffccc2-ccc5) — candidate START/crank correlation, unproven.
- Timers: `key_on_time_counter_update` 0x195cc (0xffffa9e0 while key on),
  `key_off_time_counter_update` 0x195f4 (0xffffa9e2 while key off). The
  RPM-derived engine-running flag is separate: `engine_running_from_rpm` 0xe274
  → 0xffffa428 (set ≥ 500 RPM, clear < 250).

## 3. Key-off shutdown and relay hold

- `key_off_state_machine_step` 0x253e8 (SR mask 0xe0 via 0x2054, jsr 0x252c2,
  restore 0x2064; called from slow task 0x11534) →
  `key_off_shutdown_state_machine` 0x252c2: state 0xffffb57a; key on & state 0
  → arm (0xffffdf99 = 0x5a, 0xffffb580 = 0, 0xffffb579 = 1); engine stopped &
  state 0 → state 1 + 0xffffb578 = 1; counting: u32 0xffffb57c ++ saturating;
  state 2 when b57c ≥ u32 @ROM 0x74940 (pool 0x253a4; = 0x36ee8) or early
  condition b57c ≥ 0x19 && 0xffffb582 ≤ 0xffffb583 (`candidate_key_off_early_counter_a`
  0x252ae / `_b` 0x252b8, called from 0x253b8): then E2-shadow 0xffff8104 = 1
  via 0x3dc70, 0xffffb579 = 0, 0xffffdf99 = 0, jmp `shutdown_wait_key_pin_then_halt`
  0x9ea2. Thunk 0x253b2 → 0x2529e `candidate_shutdown_e2_flag_clear` (E2-shadow = 0).
- `shutdown_wait_key_pin_then_halt` 0x9ea2: SR |= 0xf0; PFDR_W bit3 = 0
  (r5=8 r6=0 via 0x4bbc, pool 0x9f1a=0xf74e); loop 0x9ed0: busy-wait 0x239c
  (r4=0x1388), WDT pulse `external_wdt_heartbeat_pulse` 0xa850 (PBDR_W
  0xfffff738 |= 0x8000 then &= 0x7fff), read PFDR_W & 1; loops while bit0 == 0,
  `bsr` 0x9efe (masked halt) once bit0 == 1.
- Relay hold: `relay_hold_output_pd11` 0x251d0: 0xffffb574 = (0xffffccc1 != 1);
  PDDR_W 0xfffff746 bit 0x800 = (0xffffb574 == 1). `shutdown_allowed_flag`
  0x48cc0 computes 0xffffccc1 = key-on 0xffffaa68 || (0xffffb4ee && 0xffffccb6
  < 0x271), and !0xffffcca0, !0xffffad60/0xffffad61, E2 0xffff80a2 != 1,
  !0xffffb51a; `engine_stop_conditions_eval` 0x487d6 feeds the rpm/voltage/
  coolant conditions.
- Persistence across key-off: E2RAM encode `e2ram_save_encode_entry` 0x2377a
  (fault collect 0x242ae, block encode 0x244bc), staging write 0x236cc
  (magic 0xa55a + checksum → 0xffffb440 → E2RAM 0xb886), stored-DTC replay
  at load 0x23f4e; slow task 0x1150e and task[0] 0x62a0 → 0x1122a → 0x23740.
- Fan after-run: 0x2f51a/0x2f65c keep the fan commanded while 0xffffaa68 == 0,
  coolant hot, !0xffffccc6, !0xffffa8ea, APV closed (0xffffbf8d) — see
  [`../cooling_fan_control/README.md`](../cooling_fan_control/README.md).

## 4. Cross-ROM propagation

`data/labels/cross_rom/ignition_power_state_addresses.json` (generator
`utilities/scripts/extract_ignition_power_state_addresses.py`, regeneration test
in `tests/test_ignition_power_state.py`): the 34 key function bodies were
byte-matched across all 11 dumped ROMs; entry cells differ per family — warm
0x1298 (family A) vs 0x12b4 (family B/C), recovery 0xd204 vs 0xd49c/0xd494,
app pointer 0x2000 in all 11.

## 5. Unresolved / limits

- Chip-pin ↔ connector-terminal routing is board-level unresolved (D2):
  PF0/PF15/PF3/PD11 ↔ terminals 4Q (IG1), 4E (main relay), 4C/5H (DBW relay),
  5J (KAM) is a candidate mapping from the pinout, not traced.
- Starter-relay output (terminal 5A) driver not identified — belongs to the
  starting/cranking subsystem.
- SBL→app handover into 0x61a8 remains a separate open question; this review
  maps only the warm/cold entry selection.
- Static analysis only; timeout (0x36ee8 ticks) in real seconds and the
  key-return behavior of the 0x9ea2 loop are unmeasured.
- The 6 `candidate_` names (0xd21e, 0x2529e, 0x252ae/0x252b8, 0x48d38,
  0x48d70) are hypotheses, kept candidate per the label ladder.

## 6. Validation

See `validation.json` in this folder: `validate_export.py` (ROM SHA-256,
3,355 function files, 168,592 instructions / 337,184 bytes byte-verified,
1,833 exact reference matches), `verify_claims.py` PASS (619 TSV rows, 23
labels JSONs), `verify_math_units.py` PASS, `validate_reports.py` PASS,
`python -m pytest tests/` 272 passed + 1 pre-existing failure
(`test_extract_scalars.py`, cp1252-byte scalars.tsv read as UTF-8 on Windows —
fails identically on `main`); `verify_readability.py` fails identically on
`main` (per-function-file vs monolith name divergence at 0x28992 from the
thunk pass, untouched here). Labels applied by
`review_ignition_power_state_labels.py` +
`review_ignition_power_state_labels_apply.py` (idempotent, wired into
`rebuild.sh`): 34 function + 20 RAM rows; thunk 0x253b2 re-derived;
`tests/test_ignition_power_state.py` 18 tests.
