# OS scheduler / interrupt controller / CAN-UDS transport report — 60E15120_N3J1E

Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — labels only, no binary change). Static-analysis disclaimer: findings below
come from the canonical export + disassembly + ROM bytes, **plus dynamic execution in
the SH-2E emulator** (`utilities/scripts/emu/`, harness `tests/test_phase1_dynamic.py`);
every dynamically-cited claim names the emulator observation. Full evidence:
`data/labels/60E15120_N3J1E/os_scheduler_can_ivt_labels.json`,
`source_review/accepted_{function,ram,lookup}_aliases.tsv`,
backup `backups/pre_os_scheduler_can_ivt_labels.zip`.

**Related reports:** infrastructure for all subsystem tasks — task table 0x4998 drives [fueling](fueling_control_report.md) task[11], [ignition timing](ignition_timing_report.md) task[6], [intake solenoids](intake_solenoids_report.md) chain 0x64f6, [knock control](knock_control_report.md); UDS transport serves all Mode 22 PIDs — the full dispatch tables are labeled in [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md); for the full scheduling model (task loops, queues, crank-synchronous tick, timers) see [os_scheduling_deep_dive_report.md](os_scheduling_deep_dive_report.md).

## 1. Executive summary

The Phase 1 fidelity-hardening emulator pass produced dynamically verified
knowledge of the SH7055 interrupt/OS/CAN plumbing, labeled in the decompiled code:

- The IVT lives at **VBR = 0x7fc50** (set at 0xd206); ROM vector slot = 0x7fc50 + offset.
  All IVT trampolines (0x28c0-0x30d0) jsr the common context-save **0x3238**
  (`interrupt_entry_save_context`), which saves r2-r7/fr0-fr11/fpscr/fpul, raises the
  SR mask, and returns to the restore path at 0x3280. Unused vectors end in a deliberate
  halt loop at **0xa4be**.
- The OS is cooperative: **0x3e10 `os_init`** sets up the control block at **0xffff7638**
  (task table ptr 0x4990, stack base 0xffff7408) and calls **0x3c2a `os_dispatch`**,
  which runs **0x3c68 → 0x375c `os_switch_to_task`** (computed jump via the task
  table at **0x4990**, rec[0].entry at 0x4998) or parks in the idle loop **0x3dac**. Task end (**0x3d58
  `ref_taskEndRoutine_`**) re-enters 0x3c2a. The ISR-exit wake is **0x3db0
  `os_wake_check_context_switch`** (called from `ref_setSR` 0x3934 when
  0xffff763c != 0xffff763e and 0xffff7640 & 0x1000 == 0).
- The CAN RX interrupt that drives UDS is **IVT offset 0x378** (trampoline 0x31c0): its
  handler polls HCAN0 RXPR/MBIMR, runs the CAN RX poll **0x11d88
  `can_rx_poll_move_to_uds_buffer`** and the scheduler 0x9630. In the emulator,
  `can.inject(0x7e0, ...)` raising 0x378 makes a plain `emu.run` move the frame into the
  UDS RX buffer **0xffffddc8** autonomously.
- Boot waits for **ICR_W (0xffffed18) bit15 = NMI pin level** at 0x8ea (Sh7055h.pdf 7.3.2);
  ICR_W bit15 is modeled as the SYSC `nmi_level` peripheral (E5 closed).
- Crank/rpm: the ch10B compare tick (CMI10B, IVT 0x2c8 at VBR 0x7fc50 → trampoline
  0x2ec0 → **0x5b3c**) chains 0x75f4 → 0x77f0 → 0x7c68 → **0x7fcc `ref_getCrankAngle`**
  (appends ring 0xffff9fd0 → `crank_period_accumulator_ffff9f88`, rpm = 1.2e8/sum into
  0xffff9f80); polled path **0x77f0 `crank_capture_poll`** reads ICR0AH/ICR10AH into
  0xffff9fb8/0xffff9fb0. ATU-II ch10 started by TSTR3 bit0; tick enabled by
  **0x7778 `atu_ch10b_tick_enable`** (TIER10 bit2).
- ADC sweep **0x6884 `adc_scan_sweep_all_channels`** copies ADDR0H-31H → 0xffff9ee4+;
  vehicle inputs **0x6744 `vehicle_inputs_poll_pfdr_phdr`** latches PFDR (0xfffff74e) into
  0xffff9ec8 (bit0 gates the UDS service branch in 0x11d88).

## 1a. Plain-language summary (the PCM's "plumbing")

- This report covers the interrupt/OS/CAN plumbing, not a calibration: an
  interrupt vector table (VBR = 0x7fc50) dispatches hardware interrupts to
  handlers, a cooperative scheduler round-robins the tasks with an idle
  loop, and UDS/OBD diagnostic requests arrive over CAN as an interrupt,
  get moved into a receive buffer, and are answered by a task.
- The ADC sweep, crank-angle capture and RPM calculation that feed every
  other subsystem also live here.
- Nothing in this report changes what the car does — it is the groundwork
  that lets the simulator run the firmware so the other subsystems can be
  tested dynamically.

## 2. How it works (condensed pseudocode)

```python
# boot: 0x8b8 -> 0x8cc boot_wait_nmi_pin_high polls ICR_W bit15 (NMI high) at 0x8ea
#       -> 0x8f6 ... -> CAN init (0x9c0/0x9de MCR<->GSR handshake) -> 0x4c80 init chain
#       -> os_init 0x3e10 -> os_dispatch 0x3c2a -> ... -> idle loop 0x3dac
# interrupt (any IVT offset off): push SR,PC; pc = IVT[VBR+off] (VBR=0x7fc50)
#   trampoline: jsr 0x3238 (save ctx, raise mask) ; jmp epilogue -> handler ; rte
# CAN RX (IVT 0x378): poll RXPR via 0xce24; 0x11d88: placeCANRX desc 0x4dffc
#   (mb14/0x7e0) -> UDS RX buffer 0xffffddc8, clear RXPR; if 0xffff9ec8&1: 0x680a0(0x7e0)
# UDS entry 0x680a0: PCI check 0x683d4, service dispatch 0x6842c, 0x684b4 schedules
#   service task via ref_osTaskScheduler(2,...); response TX via 0x99b0 desc 0x4e00c
#   (mb15/0x7e8, buf 0xffffddd0)
# crank: CMI10B (IVT 0x2c8 @ VBR 0x7fc50) -> 0x2ec0 -> 0x5b3c -> 0x75f4 -> 0x77f0 -> 0x7c68
#   -> 0x7fcc ref_getCrankAngle: rpm = 1.2e8/sum(ring 0xffff9fd0[6]);
#   polled: 0x77f0 reads ICR0AH(0xfffff434)/ICR10AH(0xfffff6d0)
# ADC: 0x6884 sweep ADDR0H-31H -> RAM 0xffff9ee4+; 0x6744 PFDR->0xffff9ec8
# WDT: overflow = TCSR OVF flag only; firmware polls and calls 0x31c (keyed 0xa53c,
#   PB15 toggle); WDT ITI vector slot = 0x358 (vec 214, Sh7055h.pdf table 7.3)
```

## 3. Key tables / structures

| Address | Name | Contents |
|---|---|---|
| 0x7fc50 | `ivt_base_vbr` | u32[236] vector table (VBR target) |
| 0x4990 | `os_task_table` | 19 x 16-byte task records {param, stack, entry, mask}, terminator 0x4ac0; rec[0].entry at 0x4998, stack range 0xffff7410-0xffff7498 |
| 0xd914 | `can_mailbox_mask_table` | 16 x u16; mask = 1<<((mb+8)&0xf) |
| 0xd7d4 | `injector_channel_map` | 6 x 12-byte {DCNT8x ptr, GR1x ptr, TIER mask} — dynamically confirmed via 0x8a68 |
| 0x4dffc / 0x4dfec / 0x4e00c | CAN descriptors | RX 0x7e0 (mb14), RX 0x7df (mb13), TX 0x7e8 (mb15, buf 0xffffddd0) |
| 0x5f10c | `tbl_diag22_dispatch_records_0005f10c` | 99 x 12-byte records; all 99 labeled (PID 0x43 record at 0x5f268 -> handler 0x56b8a `diag22_pid0043_engine_load_g_rev`) — see [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md) |

## 4. Labeling applied

- **27 functions** renamed in `symbols.tsv`, `function_index.tsv`, `callgraph.tsv`,
  `functions/*.c`, `named/firmware_named.c`, `firmware_decompiled.c`
  (see `os_scheduler_can_ivt_labels.json`; 7 upgraded from `ref_` names with new dynamic
  evidence: 0x9890, 0x803e, 0x7778, 0x6884, 0x6744, 0x6fb0, 0x6cdc).
- **16 RAM locations** named (`accepted_ram_aliases.tsv`): OS ctrl block
  0xffff7638/763c/763e/7640/764c/7650/7408; vehicle-input latches 0xffff9ec8/9eca/
  9ed8/9eda; UDS buffers 0xffffddc8/0xffffddd0; crank samples 0xffff9fa8/9fb0/9fb8.
- **9 lookup tables** named (`accepted_lookup_aliases.tsv`, list in section 3).

## 5. Corrections made in this pass

- `ref_INT_ATU101_IMI10AG` (0x803e) is a misnomer: 0x803e is the default (VBR=0) IVT
  slot 0x2c8 target, not the live CMI10B handler (see §12); its math computes
  rpm from the crank ring, hence the name `crank_isr_compute_rpm` (high, dynamic).
- ICR_W (0xffffed18) bit15 is the NMI pin level, not a ready-bit — modeled as the
  SYSC `nmi_level` peripheral; profiles carry no read override (E5 closed).
- 0x31c is a polled subroutine (ends rts, clobbers r0-r4), not an interrupt entry —
  WDT overflow is OVF-flag-only in the emulator; ITI vector slot documented as 0x358 (E3 closed).

## 6. Files

- `data/labels/60E15120_N3J1E/os_scheduler_can_ivt_labels.json` (this pass, with evidence)
- `docs/investigations/60E15120_N3J1E/source_review/accepted_{function,ram,lookup}_aliases.tsv` (appended)
- `reverse-engineered/decompiled/60E15120_N3J1E/`: symbols.tsv, function_index.tsv,
  callgraph.tsv, functions/*.c, named/firmware_named.c, firmware_decompiled.c (renamed)
- `data/labels/60E15120_N3J1E/integrated_names.json` (identifier_map extended)
- backup: `docs/investigations/60E15120_N3J1E/backups/pre_os_scheduler_can_ivt_labels.zip`

## 7. Validation

- Every function address verified present in `function_index.tsv`; ROM bytes untouched
  (`rom_unchanged: true`; binaries not modified, `hash_binaries.py --check` unaffected).
- Dynamic evidence executed in the emulator: inject→IVT 0x378→0x11d88→
  0xffffddc8 (test_can_rx_interrupt_autonomous); TX 0x99b0 desc 0x4e00c → 0x7e8
  (test_rcan_rx_tx_through_rom_driver); Mode 22 0x0043 → 0x56b8a (test_mode22_dispatch_pid_0043);
  0x6884 ADC sweep lands channels in RAM (test_adc_read_path_dynamic);
  boot to idle 0x3dac with zero overrides (test_nmi_pin_replaces_guessed_override).
- `python -m pytest tests/` — 38/38 pass.
- Pipeline validators run from the repo root via
  `utilities/scripts/rx8-pcm-pipeline/paths.py`:
  `validate_export.py`, `validate_reports.py` (this report included),
  `verify_readability.py`, `verify_math_units.py` all PASS.
  Ghidra-dependent `rebuild.sh` steps still need `GHIDRA_HOME` + JDK and were
  not run here.

## 8. Memory map for validation

Functions (address -> label): 0x3238 interrupt_entry_save_context; 0x3e10 os_init;
0x3c2a os_dispatch; 0x3c68 os_dispatch_next_task; 0x375c os_switch_to_task;
0x3db0 os_wake_check_context_switch; 0x3934 ref_setSR; 0x11d88 can_rx_poll_move_to_uds_buffer;
0x9c8e can_rx_pending_check; 0xce24 can_rx_pending_bits; 0xcee8 can_mailbox_reg_addr;
0xcf12 can_mailbox_bitmask; 0xccda can_mailbox_write_payload; 0xcca4 can_mailbox_read_payload;
0xcd40 can_mailbox_dlc; 0x680a0 uds_service_entry; 0x684b4 uds_request_schedule_service_task;
0x9890 can_rx_copy_mailbox_to_buffer; 0x8cc boot_wait_nmi_pin_high; 0x9c0 can_enter_reset_mode;
0x9de can_exit_reset_mode; 0x77f0 crank_capture_poll; 0x803e crank_isr_compute_rpm;
0x7778 atu_ch10b_tick_enable; 0x6884 adc_scan_sweep_all_channels;
0x6744 vehicle_inputs_poll_pfdr_phdr; 0x6fb0 adc_read_result_bank2; 0x6cdc adc_read_ect_iat_group;
0xa4be halt_loop_unused_vector (label); 0x31c0 IVT-0x378 trampoline.

RAM: 0xffff7638 os_ctrl_block; 0xffff763c/763e scheduled/dispatched counts;
0xffff7640 os_state_flags; 0xffff764c/7650 task record/table ptrs; 0xffff7408 task stacks;
0xffff9ec8/9eca/9ed8/9eda vehicle input latches; 0xffffddc8 uds_rx_buffer; 0xffffddd0
uds_tx_buffer; 0xffff9fa8/9fb0/9fb8 crank period/samples; 0xffff9f80/9f88 rpm/accumulator.

Registers: ICR_W 0xffffed18 (bit15 NMI); WDT TCSR/TCNT 0xffffec10/11; UBC 0xffffec00;
DMAC 0xffffecb0 (CHCR0 0xffffeccc); HCAN0 0xffffe400 (RXPR 0xe40e, MBIMR 0xe414, MC 0xe420+,
MD 0xe4b0+); HCAN1 0xffffe600; ATU-II 0xfffff400 (TSTR3 0xfffff402 bit0=ch10, ICR0AH 0xfffff434,
TIER10 0xfffff6ea, TSR10 0xfffff6e8, OCR10B 0xfffff6d8, ICR10AH 0xfffff6d0, DCNT8A-P 0xfffff640-0x65e,
GR1A-H 0xfffff444-0x452); SCI 0xfffff000; ADC 0xfffff800 (ADDRn, ADCSR0/1/2 0x818/0x838/0x858);
GPIO 0xfffff700 (PBDR 0xfffff738 bit15 heartbeat, PFDR 0xfffff74e).

## 9. Limits

- Dynamic claims are emulator observations at 1 cycle/instruction (E7: not real time);
  the OS task context switch (0x3db0 via ref_setSR) still does not fire in emulation, so
  UDS response TX is driven via the profile `uds` entry points — labeled functions were
  observed executing, but the full task graph is not yet autonomously scheduled.
- `adc_read_result_bank2` (0x6fb0) and `adc_read_ect_iat_group` (0x6cdc) are medium
  confidence (static + partial dynamic; bank/channel mapping from labels).
- IVT offset 0x378 is identified empirically (handler behavior), not from a manual source
  name — the Sh7055h.pdf table extraction is fragmented there; treat the source name as
  inferred, the behavior as verified.
- `ref_setSR` (0x3934) keeps its ref_ name (behavior partially dynamic); the 0x3db0 wake
  call site at literal 0x3950 is static evidence.

## 10. Related dispatch labeling

The UDS/Mode-22 dispatch labeling ([uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md))
labels every record of
the 0x5f10c table, the UDS service table at 0x5eb40 (router 0x68dac,
which this report's task[2] chain feeds), and the ISO-TP frame dispatcher 0x6842c that
0x680a0 calls — the transport picture is fully named end to end.

## 11. Task table

Derivation from 0x375c `os_switch_to_task`'s disassembly (pool 0x37b0 ->
**0x4990**, stride 16 via `shll2`x2, r14 = record+4 used as a stack pointer)
shows the task table is **19 records based at 0x4990** with layout
{param, stack, entry, mask}, terminated at 0x4ac0 by {0x04ffffff, 0x00000001, ...}.
0x4998 is rec[0].entry, and
0x4ab8 is
rec[18].entry -> 0x64e8, a thunk {jsr 0x11534; jmp 0x3d58 taskEnd} where 0x11534 is
the 29-call slow/background task. Byte-verified against the raw ROM
(0x4990..0x4ad0). Details: [fueling_control_report.md](fueling_control_report.md)
§10.6.

## 12. Corrections from the OS scheduling deep dive

The deep dive ([os_scheduling_deep_dive_report.md](os_scheduling_deep_dive_report.md))
re-derived the interrupt/OS plumbing from raw ROM bytes and emulator
traces:

- **CMI10B handler chain.** The IVT slot
  0x7fc50+0x2c8 points at trampoline 0x2ec0 whose handler is **0x5b3c** (byte-verified:
  TSR10=0xb; then 0x75f4 → 0x77f0 → 0x7c68 → `ref_getCrankAngle` 0x7fcc, which does the
  ring-0xffff9fd0 append and rpm = 1.2e8/Σ → 0xffff9f80; plus 0xd716 and 0xcf96, and
  0x7b58 rearms OCR10B from tbl 0xd76d[sector 0xffff9f95*2] & 0x7f — the tick is
  **crank-angle-synchronous**, 36 sectors/720°). 0x803e has **no callgraph callers**; its only ROM
  reference is the default (VBR=0) vector table slot 0x2c8 (u32 at ROM 0x2c8 = 0x803e) —
  the pre-relocation CMI10B entry, inactive once VBR=0x7fc50 is set at 0xd206. It
  duplicates 0x7fcc's rpm math for that pre-VBR entry, so
  `crank_isr_compute_rpm`/`ref_INT_ATU101_IMI10AG` is a misnomer for that legacy handler.
- **Unused/fatal vectors**: 117 IVT slots (0x100–0x39c) have real trampolines (all ctx
  word = 0x3238); 98 of their handlers end in the fatal trap 0x5348 (raise mask 0xe0,
  report via 0xa330, halt 0xa4be / spin 0x535a). Only 19 have real handlers: CMI10B
  0x5b3c, six ATU-II ch8 injector compares 0x59a4–0x59ea →
  `candidate_injector_pulse_set_dispatch(0..5)`, knock-ADC trigger 0x5a4c, ch3/ch9
  compares, three ADC EOC banks, CMCSR1 0x5cee, IRQ flags 0x53f6, CAN 0x378/0x37c/0x398.
  WDT ITI 0x358 → 0x5e0c → fatal trap (as E3 said, overflow is polled-only; the ITI
  firing is deliberate halt). Reserved vectors 0x0–0xfc → stubs 0x53a0–0x53c2 → 0x5348.
- **Scheduler mechanics**: fresh tasks are entered via `rte` at 0x3848
  (push SR=0 + entry), resume via jump table 0x4b34 indexed by ctx[0] − param byte0;
  preemption in 0x39ba fires only when `class > ctrl[0]` as an **unsigned** byte
  (`cmp/hi`) — at boot ctrl[0]=0xff so posts from idle do not set ctrl+6 (dynamically
  observed; the decompiled signed compare is a sign-extension artifact). Ready bitmap
  0xffff7668 is class-indexed (bit 1<<(class&7) at byte class>>3, table 0x3d48).
  Init schedules tasks {17, 0} (list at ROM 0x4af0 walked by 0x3f10) — dynamically
  confirmed (bitmap 0x11000000 after boot; tasks 0/17 credit bytes read 0).
- The full model — task inventory, message queues (0x9630/0x5f1c/0x6010, ROM 0xd74c,
  RAM 0xffff9304+3i), ISR-exit context switch 0x32f4, per-task software timers, and the
  end-to-end emulator reproduction (post → queue → dequeue → handler 0x11c98 → taskEnd →
  dispatch → idle) — is in [os_scheduling_deep_dive_report.md](os_scheduling_deep_dive_report.md).
