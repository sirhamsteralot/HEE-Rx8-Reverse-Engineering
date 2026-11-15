# Ignition key-state / power-state logic report — 60E15120_N3J1E (RX-8 PCM, SH7055 / SH-2E)

Target ROM: `Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched). All findings are from static analysis of the canonical export
(`decompiled/`), the disassembly and the ROM bytes. The findings were
additionally exercised dynamically in the SH-2E emulator (ROM functions run
via `harness.call`, key pin PFDR bit0 / PF15 driven through the GPIO pin
model; `tests/test_ignition_power_state_dynamic.py`, log at
[`reviews/ignition_power_state/dynamic_validation_log.txt`](reviews/ignition_power_state/dynamic_validation_log.txt)).
No hardware execution was performed. Full evidence:
[`reviews/ignition_power_state/README.md`](reviews/ignition_power_state/README.md).

**Related reports:** reset/boot chain and OS entry in
[`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md) and
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md); E2RAM
commits in [`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md) and
[`eeprom_content_map_report.md`](eeprom_content_map_report.md); cooling-fan
after-run in [`cooling_fan_control_report.md`](cooling_fan_control_report.md);
CAN key gating in [`dsc_can_arbitration_report.md`](dsc_can_arbitration_report.md);
UDS gating in [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md);
pin functions/wire colours in
[`mazda-rx-8-pcm-pinout-series-1.md`](../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md).

## 1. Executive summary

The PCM learns the ignition-switch state from **two GPIO input pins on port F**
and reacts to it at three levels: boot entry, running supervision, and shutdown.

- **Key-on input**: PFDR bit 0 is sampled every slow tick by
  `vehicle_inputs_poll_pfdr_phdr` (0x6744) into the latch `0xffff9ec8`, then
  copied to `0xffffaa69` (0x1a5d8) and `0xffffaa68` (0x1a600) — the flag that
  gates the UDS entry (0x11d88), the CAN RX/TX mains (0xdbf6/0xdb58), CAN error
  recovery (0xdcc0) and the key-off state machine. A second input, PF15, is
  edge-latched into `0xffffcbd0` (0x454c0/0x454d2) and combined with battery
  voltage in 0x48d38/0x48d70 (candidate START-position correlation).
- **Warm/cold boot split**: `reset_handler_warm_cold_select` (0x4e0) compares
  the top-of-RAM magic `0xffffdffc` with `0x5aa5a55a` (plus a WDT-overflow check,
  0x5b0 with n=7). Warm (RAM retained on the KAM supply) → entry cell
  `u32 @ROM 0x1000` = 0x1298 → `warm_reset_dispatcher` (0x1038); cold →
  `cold_entry_ring_dispatch_loop` (0x6c8). Flash-resident fallback pointers:
  `u32 @ROM 0x7fffc` = 0x2000 (app), `u32 @ROM 0x7fff8` = 0xd204 (recovery entry,
  sets VBR/FPSCR then `manual_reset_finalize` 0xd20c).
- **Boot NMI/power-fail poll**: 0x8cc zeroes ICR_W and the boot loop at
  0x8ea–0x8f0 waits for ICR_W (0xffffed18) bit 15 — the NMI pin level — to read
  high before anything else runs.
- **Key-off shutdown**: when the key-on flag drops, the state machine
  `key_off_shutdown_state_machine` (0x252c2, stepped from slow task 0x11534 via
  0x253e8) counts in `0xffffb57c`; after the timeout (u32 at ROM 0x74940 =
  0x36ee8 slow-task ticks) or an early condition (0x252c2: b57c ≥ 0x19 and
  0xffffb582 ≤ 0xffffb583) it writes the E2RAM-shadow flag 0xffff8104 = 1 and
  calls `shutdown_wait_key_pin_then_halt` (0x9ea2): clear PFDR bit 3, keep
  pulsing the external watchdog (PB15, 0xa850) while PFDR bit 0 is low, halt
  with interrupts masked when it goes high.
- **Relay-hold output**: PDDR bit 11 (PD11) is driven by
  `relay_hold_output_pd11` (0x251d0) = NOT `shutdown_allowed` (0xffffccc1,
  computed by 0x48cc0 from the key flag, battery voltage sanity 0x48d70 and
  engine-stop conditions 0x487d6). PFDR bit 3 is set by
  `recovery_finalize_set_pf3_halt` (0x9e68) and cleared by 0x9ea2. Which of these
  drives connector terminal 4E (main relay control) vs 4C/5H (DBW relay) is
  board routing — unresolved (discrepancy D2); the pinout has no chip-pin data.
- **Persistence across key-off**: E2RAM commits run from the slow task
  (0x1150e → 0x236cc staging write, encode via `e2ram_save_encode_entry` 0x2377a)
  and task[0] (0x62a0 → 0x1122a → 0x23740); stored DTCs are replayed at load
  (`e2ram_stored_dtc_replay` 0x23f4e). The cooling fan keeps an after-run while
  the engine-off flag is set and coolant is hot (0x2f51a/0x2f65c clause).

## 1a. Plain-language summary (what "key state" means to the PCM)

- The PCM knows the ignition is **on** when one input pin (port F bit 0) reads
  high. That single bit enables the OBD/UDS diagnostic port and all normal
  CAN traffic; with the key off, diagnostics and non-essential CAN stop.
- At **power-up** the PCM checks a magic word in the battery-backed RAM: if it
  is there, this is a **warm** start (RAM survived) and it takes the short boot
  path; otherwise (or after a watchdog reset) it takes the **cold** path.
- When the key goes **off**, the PCM does not die immediately: the main relay
  keeps it powered for a while so it can save learned values to EEPROM, keep the
  cooling fan running if the engine is still hot, then release its relay hold
  and stop — waiting on the battery-backup supply and pulsing the external
  watchdog until the key comes back or power is cut.

## 2. How it works (condensed pseudocode)

```python
# --- boot (vector 0/2 -> 0x8b8 ref_Manual_Reset) ---
boot_init_wait_nmi_high()          # 0x8cc: WDT/MSTCR keyed writes, ICR_W = 0,
                                   # 0x8ea: wait while (ICR_W 0xffffed18 & 0x8000) == 0
wdt_keyed_reset()                  # 0x572: RSTCSR = 0x5a1f, TCSR = 0x5a00 then 0xa53c
reset_handler_warm_cold_select()   # 0x4e0:
if param == 0 and (RAM[0xffffdffc] != 0x5aa5a55a and wdt_overflow_reset_check(7) == 0):
    entry = cold_entry_ring_dispatch_loop        # 0x6c8
else:
    entry = u32 @ROM 0x1000                      # 0x1298 (warm); flash-ptr fallback
    #   checks u32 @0x7fffc (0x2000) and u32 @0x7fff8 (0xd204)
RAM[0xffffdffc] = 0x5aa5a55a
jmp entry via FUN_00000040 (0x40: set SP, jmp @r4)
# warm stub 0x1298: jsr warm_reset_dispatcher (0x1038); halt
#   0x1038 param!=0: port/CAN init 0x12a2, jump 0x1378; param==0: flash-ptr check
#   -> 0xd204 recovery (VBR=0x7fc50, FPSCR, 0xd20c manual_reset_finalize -> 0x9e68)

# --- running: key-on input (slow tick, task[17] 0x6744) ---
vehicle_inputs_pfdr_latch_ffff9ec8 = PFDR_W            # 0x6744 (0xfffff74e)
vehicle_inputs_sticky_update()                          # 0x6796: (prev|cur)&latch | prev&cur
key_input_pf15_prev  = (PFDR_W & 0x8000) == 0           # 0x454c0 -> 0xffffcbd1
key_input_pf15_edge_latch  = edge(PF15)                 # 0x454d2 -> 0xffffcbd0
key_on_latch_aa69 = (0xffff9ec8 & 1) != 0               # 0x1a5d8
engine_running_flag_ffffaa68 = key_on_latch_aa69        # 0x1a600
key_on_time_counter_ffffa9e0   += 1 while aa68==1 else 0    # 0x195cc
key_off_time_counter_ffffa9e2  += 1 while aa68==0 else 0    # 0x195f4
engine_running_ffffa428 = rpm >= 500 (clear < 250)      # 0xe274 — RPM-based, separate flag

# --- gating on the key flag ---
if (0xffff9ec8 & 1): dispatch UDS from CAN RX          # 0x11d88 -> uds_service_entry 0x680a0
can_rx_main_key_gated()   # 0xdbf6: CAN 0x212/216/231/430/4B0/4B1/4C0/47 only if aa68==1 && !b578
can_tx_main_key_gated()   # 0xdb58: TX packs only if aa68==1 && !b578 && error counters clear
can_error_recovery_key_gated()                         # 0xdcc0: error poll/recovery only if aa68==1

# --- key-off shutdown (slow task 0x11534 -> 0x253e8 -> 0x252c2) ---
state = key_off_state_ffffb57a                          # 0 armed, 1 counting, 2 shutdown
if aa68 == 1 and state == 0: arm (0xffffdf99 = 0x5a, 0xffffb579 = 1)
elif aa68 == 0 and state == 0: state = 1; engine_stopped_latch_ffffb578 = 1
elif state == 1:
    key_off_timer_ffffb57c += 1 (saturating)
    if b57c >= u32 @ROM 0x74940 (0x36ee8) or (b57c >= 0x19 and 0xffffb582 <= 0xffffb583):
        state = 2; E2shadow 0xffff8104 = 1; 0xffffdf99 = 0
        shutdown_wait_key_pin_then_halt()               # 0x9ea2:
        #   PFDR bit3 = 0; loop: WDT pulse 0xa850, wait while (PFDR & 1) == 0;
        #   halt masked (0x9efe) once PFDR bit0 == 1

# --- relay hold / shutdown allowance (0x22f54 init, 0x22f86 slow step) ---
shutdown_allowed_ffffccc1 = 0x48cc0(...)               # aa68 || (b4ee && ccb6 < 0x271), not cca0,
                                                        # not ad60/ad61, E2 0xffff80a2 != 1, !b51a
engine_stop_conditions_eval()                           # 0x487d6: rpm/voltage/coolant/E2 flags
relay_hold_output_pd11()                                # 0x251d0:
    0xffffb574 = (0xffffccc1 != 1); PDDR_W 0xfffff746 bit 0x800 = (b574 == 1)

# --- persistence + fan after-run ---
e2ram_save_encode_entry() 0x2377a -> fault collect 0x242ae + block encode 0x244bc
staging write 0x236cc (0xffffb440 magic 0xa55a + checksum -> E2RAM 0xb886)
stored DTC replay at load: 0x23f4e
fan after-run: 0x2f51a/0x2f65c set fan cmd while aa68==0 && coolant hot && !ccc6 && !a8ea && APV closed
```

## 3. Key ROM cells, registers and constants

| Address / register | Contents |
|---|---|
| ROM 0x1000 (u32) | warm-entry pointer = 0x1298 (family A ROMs; 0x12b4 on family B/C — see cross-ROM artifact) |
| ROM 0x7fff8 (u32) | recovery-entry pointer = 0xd204 (0xd49c/0xd494 on family B/C ROMs) |
| ROM 0x7fffc (u32) | app pointer = 0x2000 (all 11 ROMs; points at the fw-id string) |
| ROM 0x74940 (u32) | key-off shutdown timeout = 0x36ee8 slow-task ticks (read via pool 0x253a4 in 0x252c2) |
| 0xffffdffc (RAM u32) | warm-boot magic 0x5aa5a55a, written every reset by 0x4e0 |
| 0xffffdfa8 (RAM u8) | reset-cause selector (0x4e0 param branch, 0x5b0; dispatch in 0x364) |
| 0xffffed18 ICR_W | bit15 = NMI pin level, polled at boot 0x8ea |
| PFDR_W 0xfffff74e | bit0 key-on input (latch 0xffff9ec8), bit3 output (0x9e68 set / 0x9ea2 clear), bit7/0x80 knock-amp CS (0xb4ec), bit8/0x100 (0x7070/0x7088), bit10/0x400 E2RAM CS, bit15 second key input |
| PDDR_W 0xfffff746 | bit 0x800 = PD11 relay-hold output (0x251d0) |
| PBDR_W 0xfffff738 | bit 0x8000 = PB15 external-WDT heartbeat (0x31c/0x11cc/0xa850) |

## 4. Labeling applied

- **34 functions** named in `labeling/source_review/accepted_function_aliases.tsv`
  (28 high; 6 medium → `candidate_` prefix in the export:
  `candidate_main_task_software_reset_check` 0xd21e,
  `candidate_shutdown_e2_flag_clear` 0x2529e,
  `candidate_key_off_early_counter_a` 0x252ae / `_b` 0x252b8,
  `candidate_key_voltage_timer_update` 0x48d38,
  `candidate_voltage_key_sanity_flags` 0x48d70).
  Applied to all synchronized views by the idempotent
  `scripts/review_ignition_power_state_labels_apply.py` (the full
  `integrate_reviewed_names.py` is one-shot on a fresh export).
- **20 RAM locations** named in `labeling/source_review/accepted_ram_aliases.tsv`.
- Pass record: `data/labels/60E15120_N3J1E/ignition_power_state_labels.json`
  (written by the re-runnable `scripts/review_ignition_power_state_labels.py`,
  wired into `scripts/rebuild.sh`).
- **Per-ROM propagation**: `data/labels/cross_rom/ignition_power_state_addresses.json`
  (34 key functions byte-matched in all 11 dumped ROMs where the body is
  identical; entry cells per ROM), regenerated by
  `utilities/scripts/extract_ignition_power_state_addresses.py`.
- Thunk 0x253b2 re-derived to `jump_to_candidate_shutdown_e2_flag_clear`
  (target 0x2529e relabeled medium by this pass) via
  `scripts/review_thunk_audit_labels.py`.
- New medium candidates absorbed into `candidate_promotions.json`
  (generator `scripts/review_candidate_promotions.py` now folds new candidate_
  rows into `kept_candidate` on re-run).

## 5. Corrections made in this pass

1. **Misnomer** `ref_checkCANsomethingKeyOnBased` (0xdcc0) →
   `can_error_recovery_key_gated`: it gates CAN error poll/recovery on the
   key-on flag (0xffffaa68) and engine-stopped latch (0xffffb578); it decodes
   no key message.
2. **Semantics**: `engine_running_flag` 0xffffaa68 is driven by the PFDR bit0
   latch (0x1a5d8/0x1a600), i.e. it is the **key-on** flag; the RPM-derived
   engine-running flag is the separate 0xffffa428 (0xe274, set ≥ 500 RPM,
   clear < 250). The inherited name is kept (already accepted), but consumers
   reading "key off" semantics should use 0xffffaa68.
3. **Misnomer** `ref_reset_ZERO` (0x1038) → `warm_reset_dispatcher` (it
   dispatches warm/cold recovery, not a zeroing step); `ref_resetHandler_`
   (0x4e0) → `reset_handler_warm_cold_select`; `ref_main__` (0xd21e) →
   `candidate_main_task_software_reset_check` (medium: it may call
   0x4e0(1, cause), i.e. software reset, gated on 0xffff9f8c).
4. **Misnomer** `ref_getFromGPIO_` (0x70ac) → `sci0_gpio_expander_read`: it is
   an SCI0 exchange with an external expander selected by PH14/PH15, not a
   direct port read.

## 6. Files

| Artifact | Path |
|---|---|
| Full review (evidence, unresolved items) | [`reviews/ignition_power_state/README.md`](reviews/ignition_power_state/README.md) |
| Sceptical re-review notes | [`reviews/ignition_power_state/REVIEW_NOTES.md`](reviews/ignition_power_state/REVIEW_NOTES.md) |
| Review validation record | `reviews/ignition_power_state/validation.json` |
| Pass record (labels JSON) | `data/labels/60E15120_N3J1E/ignition_power_state_labels.json` |
| Cross-ROM propagation | `data/labels/cross_rom/ignition_power_state_addresses.json` (+ generator `utilities/scripts/extract_ignition_power_state_addresses.py`) |
| Labeling passes (idempotent, wired into `scripts/rebuild.sh`) | `scripts/review_ignition_power_state_labels.py`, `scripts/review_ignition_power_state_labels_apply.py` |
| Rename maps | `labeling/source_review/accepted_function_aliases.tsv`, `accepted_ram_aliases.tsv`, `data/labels/60E15120_N3J1E/integrated_names.json` |
| Subsystem test | `tests/test_ignition_power_state.py` |
| Pinout (terminals/colours) | [`mazda-rx-8-pcm-pinout-series-1.md`](../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md) |

## 7. Validation

- `scripts/validate_export.py` — pass: ROM SHA-256 verified, 3,355 function files,
  168,592 instructions byte-verified against the ROM, 1,833 exact reference matches.
- `scripts/verify_claims.py` — PASS (pool words, register↔address pairs and
  labels-JSON↔TSV coverage of the new rows machine-checked).
- `scripts/validate_reports.py` — PASS (this report's memory maps vs index/TSVs/ROM).
- Dynamic emulator verification — `python -m pytest
  tests/test_ignition_power_state_dynamic.py`: 16 passed. Boot: warm stub
  0x1298 selected with magic present (and via WDT-overflow path on a stock
  fresh boot, which then parks at idle 0x3dac), cold entry 0x6c8 + cause byte
  on param!=0, NMI poll loop 0x8ea blocks boot while ICR_W bit15 reads low.
  Key pin through PFDR: latch 0xffff9ec8 → 0xffffaa69 → 0xffffaa68 chain,
  key timers 0xffffa9e0/a9e2, RPM hysteresis 0xffffa428 (500/250), PF15
  latch 0xffffcbd0/cbd1. Key-off state machine 0x252c2: arm → count →
  shutdown on the 0x36ee8 timeout and on the early condition, E2-shadow
  0xffff8104 = 1, halt at 0x9efe via 0x9ea2 with PFDR bit3 cleared and PB15
  pulsed while the key pin is low. Relay hold PD11 bit 0x800 follows NOT
  0xffffccc1 (0x48cc0 conditions). Log:
  [`reviews/ignition_power_state/dynamic_validation_log.txt`](reviews/ignition_power_state/dynamic_validation_log.txt).
- `python -m pytest tests/` — 288 passed, 1 pre-existing failure
  (`test_extract_scalars.py` reads a cp1252-byte scalars.tsv as UTF-8 on this
  Windows box; unrelated to this pass and failing identically on `main`).
  `scripts/verify_readability.py` fails identically on `main` and here at
  function 0x28992 (pre-existing per-function-file vs monolith name divergence
  from the thunk pass, untouched by this pass).
- Rule-7 binary-level re-checks this pass: every new label's pool words, GPIO
  reg+mask+helper and branch polarities re-read from the raw ROM/disassembly —
  e.g. warm-stub bytes at ROM 0x1298 (`9356430be400affe0009`), NMI poll loop
  bytes at 0x8ea (`6241622d225889fb`), PF3 set/clear immediates at 0x9e82/0x9eb6,
  timeout u32 at ROM 0x74940 = 0x36ee8, entry cells ROM 0x1000/0x7fff8/0x7fffc.
  All encoded in `tests/test_ignition_power_state.py` (18 tests).

## 8. Memory map for validation

Every address below can be checked in `decompiled/firmware_disassembly.asm`
(ROM addresses), `decompiled/functions/<address>_*.c` (index:
`decompiled/function_index.tsv`), and the alias TSVs (evidence columns).

### 8.1 Functions (ROM addresses)

| Address | Name | Role |
|---|---|---|
| 0x000008cc | `boot_wait_nmi_pin_high` | WDT/MSTCR init + NMI pin poll loop 0x8ea |
| 0x000004e0 | `reset_handler_warm_cold_select` | warm/cold entry select on magic 0xffffdffc + WDT overflow |
| 0x00000572 | `wdt_keyed_reset` | RSTCSR/TCSR keyed writes |
| 0x000005b0 | `wdt_overflow_reset_check` | OVF count + ring dispatch; used by 0x4e0 with n=7 |
| 0x00001038 | `warm_reset_dispatcher` | warm reset dispatch (0x12a2/0x1378 or 0xd204) |
| 0x000006c8 | `cold_entry_ring_dispatch_loop` | cold entry: 100×8-byte ring at 0xffffd4e0 monitor loop |
| 0x0000d20c | `manual_reset_finalize` | 0x4c7a(0xffff768c) + 0x9e68, halt |
| 0x0000d21e | `candidate_main_task_software_reset_check` | may call 0x4e0(1, cause) — software reset |
| 0x0000d518 | `shutdown_ram_swap_semaphore_mark` | RAM checksum/swap 0xffff6000-0x7fff ↔ 0xffff9300, marks 0xffffdff8 |
| 0x00009e68 | `recovery_finalize_set_pf3_halt` | 0x4c80, 0xd518, PFDR bit3=1, halt |
| 0x00009ea2 | `shutdown_wait_key_pin_then_halt` | PFDR bit3=0, WDT pulse while PFDR bit0 low, halt |
| 0x0000a850 | `external_wdt_heartbeat_pulse` | PBDR bit 0x8000 pulse |
| 0x00006744 | `vehicle_inputs_poll_pfdr_phdr` | PFDR_W/PHDR_W → latches 0xffff9ec8/0xffff9eca + 3 expander inputs |
| 0x00006796 | `vehicle_inputs_sticky_update` | sticky latch update |
| 0x000070ac | `sci0_gpio_expander_read` | SCI0 expander channel read (PH14/PH15 select) |
| 0x000454c0 | `key_input_pf15_sample` | PF15 sample → 0xffffcbd1 |
| 0x000454d2 | `key_input_pf15_edge_latch` | PF15 edge → 0xffffcbd0 |
| 0x0001a5d8 | `key_on_latch_from_pfdr_bit0` | 0xffffaa69 = latch bit0 |
| 0x0001a600 | `key_on_flag_update` | 0xffffaa68 = 0xffffaa69 |
| 0x000195cc | `key_on_time_counter_update` | 0xffffa9e0 while key on |
| 0x000195f4 | `key_off_time_counter_update` | 0xffffa9e2 while key off |
| 0x0000e274 | `engine_running_from_rpm` | 0xffffa428 from RPM hysteresis |
| 0x0000dbf6 | `can_rx_main_key_gated` | CAN RX IDs, gated on 0xffffaa68/0xffffb578 |
| 0x0000db58 | `can_tx_main_key_gated` | CAN TX packs, gated the same way |
| 0x0000dcc0 | `can_error_recovery_key_gated` | CAN error recovery, gated the same way |
| 0x000251d0 | `relay_hold_output_pd11` | PDDR bit 0x800 = NOT 0xffffccc1 |
| 0x00025290 | `key_off_state_init` | state init (0x1102a via 0x253ac) |
| 0x0002529e | `candidate_shutdown_e2_flag_clear` | E2-shadow 0xffff8104 = 0 |
| 0x000252ae / 0x000252b8 | `candidate_key_off_early_counter_a` / `_b` | 0xffffb582/0xffffb583 ++ |
| 0x000252c2 | `key_off_shutdown_state_machine` | states in 0xffffb57a; → 0x9ea2 |
| 0x000253e8 | `key_off_state_machine_step` | masked step (slow task 0x11534) |
| 0x000487d6 | `engine_stop_conditions_eval` | rpm/voltage/coolant/E2-flag shutdown conditions |
| 0x00048cc0 | `shutdown_allowed_flag` | computes 0xffffccc1 |
| 0x00048d38 | `candidate_key_voltage_timer_update` | 0xffffccca vs PF15 latch + voltage |
| 0x00048d70 | `candidate_voltage_key_sanity_flags` | 0xffffccc2-ccc5 voltage/key sanity |

### 8.2 Data and entry points (ROM)

| Address | Contents |
|---|---|
| 0x00001000 | u32 warm-entry pointer = 0x1298 (0x12b4 on family B/C ROMs) |
| 0x00001298 | warm-entry stub bytes (mid-function entry, not a `function_index.tsv` row; tracked as `code_entry_points` in the labels JSON): `jsr` 0x1038 + halt |
| 0x0007fff8 | u32 recovery-entry pointer = 0xd204 (0xd49c/0xd494 on family B/C) |
| 0x0007fffc | u32 app pointer = 0x2000 (all 11 ROMs) |
| 0x00074940 | u32 key-off shutdown timeout 0x36ee8 (pool 0x253a4 in 0x252c2) |
| 0x00000596-0x000005a8 | 0x4e0/0x572 pool words (magic, entry pointers, call targets) |
| 0x00009f1a-0x00009f48 | 0x9e68/0x9ea2 pool words (PFDR_W, 0x4bbc, PF3 mask 8, 0xa850, 0x239c) |

### 8.3 RAM (0xffff…)

| Address | Name | Meaning |
|---|---|---|
| 0xffff9ec8 | `vehicle_inputs_pfdr_latch` | PFDR_W sample; bit0 = key on, gates UDS 0x11d88 |
| 0xffffaa69 | `key_on_latch_aa69` | latch bit0 copy (0x1a5d8) |
| 0xffffaa68 | `engine_running_flag` | key-on flag (0x1a600); gates CAN/UDS/state machine |
| 0xffffcbd0 / 0xffffcbd1 | `key_input_pf15_edge_latch` / `key_input_pf15_prev` | PF15 edge latch + previous sample |
| 0xffffa9e0 / 0xffffa9e2 | `key_on_time_counter` / `key_off_time_counter` | saturating u16 key-on/off time |
| 0xffffb57a | `key_off_state` | 0 armed / 1 counting / 2 shutdown |
| 0xffffb578 | `engine_stopped_latch` | set on engine-stop; gates CAN mains |
| 0xffffb579 | `key_off_armed_flag` | armed flag |
| 0xffffb57c | `key_off_timer` | u32 countdown to shutdown |
| 0xffffb582 / 0xffffb583 | `key_off_early_counter_a` / `_b` | early-shutdown condition counters |
| 0xffffb574 | `relay_hold_flag` | = NOT shutdown_allowed; drives PD11 |
| 0xffffccc1 | `shutdown_allowed` | shutdown-allowed flag (0x48cc0) |
| 0xffff8104 | `shutdown_e2_shadow_flag` | E2RAM-shadow shutdown flag (0x252c2/0x2529e) |
| 0xffffdf99 | `key_off_marker_byte` | 0x5a on arm, 0 on shutdown transition |
| 0xffffccca | `key_voltage_timer` | 0x19 while PF15 active + voltage < 6.0 |
| 0xffffdfa8 | `reset_cause` | reset-cause selector |
| 0xffffdffc | `warm_boot_magic` | 0x5aa5a55a warm-boot magic |
| 0xffffcfb8 / 0xffffcfb9 | `key_on_latch_cfb8` / `key_on_latch_cfb9` | other latch-bit0 copies (0x4e7aa/0x4e7da) |

## 9. Limits

Emulator verification covers the selection/state-machine/output behavior
listed in §7, but cycles are not real time, so the 0x36ee8-tick shutdown
timeout in wall-clock seconds and the relay drop delay remain unmeasured;
no hardware run and no full-car datalog replay were performed. Chip-pin ↔
connector-terminal routing is board-level unresolved (D2): PF0/PF15/PF3/PD11
are firmware-level facts; their assignment to terminals 4Q (IG1), 4E (main
relay), 4C/5H (DBW relay) is a candidate mapping from the pinout, not traced.
The starter-relay output (terminal 5A) driver was not identified here — that
belongs to the starting/cranking subsystem. The SBL/app handover (how 0x61a8 is
reached) is a separate open question; this pass only maps the warm/cold entry
selection. The `candidate_` names (0xd21e, 0x2529e, 0x252ae/b, 0x48d38,
0x48d70) are unproven hypotheses. The ROM was not modified.

## 10. Related subsystems

Boot/reset chain and scheduler:
[`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md),
[`os_scheduling_deep_dive_report.md`](os_scheduling_deep_dive_report.md);
E2RAM persistence:
[`e2ram_nv_storage_report.md`](e2ram_nv_storage_report.md),
[`eeprom_content_map_report.md`](eeprom_content_map_report.md); fan after-run:
[`cooling_fan_control_report.md`](cooling_fan_control_report.md); CAN gating and
0x212 arbitration: [`dsc_can_arbitration_report.md`](dsc_can_arbitration_report.md);
UDS: [`uds_mode22_dispatch_report.md`](uds_mode22_dispatch_report.md); hardware
terminals: [`mazda-rx-8-pcm-pinout-series-1.md`](../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md).
