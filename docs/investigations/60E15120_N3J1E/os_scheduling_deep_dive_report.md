# OS / scheduling deep dive — task loops, timing loops, system timers, update loops — 60E15120_N3J1E

Target ROM: `submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`
(512 KiB, SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`,
untouched — no binary change; the labels are applied to the decompiled views, see §6).
Static-analysis disclaimer: findings come from the canonical export
(`reverse-engineered/decompiled/60E15120_N3J1E/`), the disassembly
(`reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm`) and the
raw ROM bytes, **plus dynamic execution in the SH-2E emulator**
(`utilities/scripts/emu/`, boot + `cpu.interrupt()` + `harness.call`); every
dynamically-cited claim names the emulator observation in §9. This report
generalizes the plumbing pass in
[`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md) into the full
scheduling model; where the two disagree, §7 lists the correction.

**Related reports:** infrastructure for all engine subsystems — the task table
0x4990 drives the [fueling](fueling_control_report.md) task[11] 0x6584, the
[ignition timing](ignition_timing_report.md) task[6] 0x661e, the
[intake solenoids](intake_solenoids_report.md) chain task[10] 0x64f6, the
[knock control](knock_control_report.md) tasks 0x65f6/0x661e/0x64ba; the
crank-angle tick feeds the [load & fuelling model](load_fueling_report.md) rpm
path (0x803e → 0xffff9f80); UDS transport runs through the CAN RX interrupt and
the message queues — see [uds_mode22_dispatch_report.md](uds_mode22_dispatch_report.md);
calibration tables in [calibration_extraction_report.md](calibration_extraction_report.md).

## 1. Executive summary

The PCM runs a small **cooperative, coroutine-style RTOS on the bare SH-2E** —
no hardware timer thread; scheduling is driven by interrupts and executed by a
hand-rolled dispatcher:

- **Boot**: reset → SBL → app init → `os_init` **0x3e10** builds the OS control
  block at **0xffff7638** (ISR mask level 0xb0, task-table ptr 0x4990, per-task
  context blocks at 0xffff7408+8·i) and enters `os_dispatch` **0x3c2a**. With
  nothing scheduled, dispatch parks the CPU in the idle spin **0x3dac**
  (`bra self; nop` — verified ROM bytes `affe 0009`), which is where the
  emulator boot trace ends.
- **Tasks**: 19 tasks in the ROM table at **0x4990** (16-byte records
  {param, stack-ctx ptr, entry, weight}, terminator at 0x4ac0). `os_dispatch`
  0x3c2a → `os_dispatch_next_task` 0x3c68 → `os_switch_to_task` **0x375c** sets
  ctrl+4 = task index, ctrl+0x18 = record, ctrl+0x14 = context block, builds a
  fresh stack frame for new tasks (jump table at 0x4b34 = {0x37c4, 0x3818,
  0x37c8, 0x381c} selects partial/full context restore for resumed ones) and
  jumps to the entry. A task runs until it calls `ref_taskEndRoutine_`
  **0x3d58**, which restores the weight byte, clears the context state byte and
  re-enters 0x3c2a — a **cooperative round-robin with explicit yield**.
- **Interrupts**: VBR = **0x7fc50** (set at 0xd206). Every used vector points to
  a 14-byte trampoline (0x2710–0x31f0) that calls `interrupt_entry_save_context`
  **0x3238** (saves r2–r7/fr0–fr11/fpscr/fpul, raises SR mask to ctrl+0x10 = 0xb0,
  bumps the nesting counter ctrl+8), jumps to the handler, and returns through
  the epilogue at **0x3280**, which on exit checks whether a higher-priority
  task was scheduled and, if so, takes the **context-switch path 0x32f4** (saves
  the interrupted task's registers, stores its SP at ctrl+0xc, sets state byte
  0xc, and jumps into the dispatcher) instead of `rte`. `ref_setSR` **0x3934**
  does the same check on the software path via `os_wake_check_context_switch`
  **0x3db0** (call-site literal 0x3950 = 0x3db0, byte-verified).
- **Event/message queues**: the system-call-style API is `os_schedule_task_event`
  **0x9630(group, idx, args…)**. It looks up a descriptor {target, nargs,
  handler} in the group tables (pointer table **0xd87c** → bases 0xd9cc / 0xd944
  / 0x67d00; 8-byte records). If target == −1 the handler is **called inline in
  the caller's (usually ISR) context**; otherwise a 5-word message
  {handler, arg1..arg4} is posted by **0x5f1c** into one of 4 ring queues (ROM
  records **0xd74c+8·i** = {buf, task-id, depth}; buffers 0xffff9310 / 0xffff93d8
  / 0xffff94a0 / 0xffff96f8; RAM state at 0xffff9304+3·i = {tail, head, count}),
  which also decrements the target task's credit byte (context[3]) via **0x3854**
  and marks it ready via **0x39ba** (ready bitmap 0xffff7668 + ready ring at
  ctrl+0x24 = 0xffff74a0, and ctrl+6 = scheduled task when it outranks the
  current one). Tasks 1–4 are the **queue consumer tasks**: entries
  0x969e / 0x96be / 0x96de / 0x96fe dequeue one message (`os_queue_dequeue_record`
  **0x6010**), call its handler, then `taskEnd`.
- **Timing loops / tick sources**: the periodic time base is **engine-angle
  synchronous**, not a fixed wall-clock tick. ATU-II channel 10B compare
  (**CMI10B**, IVT offset **0x2c8**, vector 178) → handler **0x5b3c**: clears
  TSR10, runs the crank bookkeeping **0x75f4** (→ 0x7f22/0x7b90/0x77f0/0x7be4/0x80f0,
  rearms the compare via **0x7b58**: OCR10B = table **0xd76d**[sector·2] & 0x7f,
  TCNT10B = 0), sets tick flag 0xffffa3fc (0xd716), and tracks the crank sector
  **0xcf96** (sector index **0xffff9f95**, 0x00–0x24 = 36 sectors/720°, next-sector
  table **0xd76c** in 0x787a) which on a matched edge posts a message to the
  scheduler (0xcf96 → 0xa156 → 0x9630(1, 9, …) → handler 0x11c98 → the fuel/load
  update 0x287aa in task context). The tick is armed by task[8] 0x648e →
  0x759e → `atu_ch10b_tick_enable` **0x7778** (TIER10 bit2; ch10 started by TSTR3
  bit0; ATU-II prescalers PSCR1–4 = 4 set at 0x4e6c/0x4f00). **CAN RX** (IVT
  0x378) → 0x5e78 → **0x9c86** → 0x9630(1, 12, …) whose descriptor has target
  −1, so the CAN RX poll **0x11d88** runs inline and moves the frame into the UDS
  buffer 0xffffddc8. Crank input capture feeds ICR0AH/ICR10AH; per crank edge
  `ref_getCrankAngle` **0x7fcc** (via 0x75f4 → 0x77f0 → 0x7c68) appends the
  period to ring 0xffff9fd0 and computes rpm = 1.2e8 / Σ ring[6] into
  **0xffff9f80** — see §7 for why 0x803e is *not* this path.
- **Watchdog**: internal WDT is serviced by **polling**, not an ISR —
  `service_wdt_overflow_and_toggle_pb15` **0x31c** (keyed 0xa53c write to TCSR
  0xffffec10, PB15 heartbeat on 0xfffff738 bit15) called from 0x11a / 0x5b0 /
  0x6c8 (boot + task paths). The WDT overflow interrupt itself (IVT 0x358) is a
  **fatal trap**: 0x5e0c → `fatal_interrupt_trap`(0xd6) which raises the mask, reports
  via 0xa330 and spins forever — as do most unused ATU-II sub-vectors.
- **Software timers**: there is no central timer-decrement ISR; timers are
  **per-task counters advanced each time the owning task runs** (the task period
  is the time base). Examples: `engine_running_timer` 0xffffa424 (0xe21c, saturating
  +1 while engine running, called from task[9] chain 0x64ba → 0x1150e → 0x199d4),
  `rev_limit_countdown` 0xffffa4ae (0xee82), `ol_condition_timer` 0xffffb144,
  APV PWM tick counters 0xffffa1c4/a1c6, CAN RX timeouts (0x28df2, 0x4bdac),
  diag-mode timer (0x55d42), engine-off timer (0x31922), fuel-cut-after-reset
  (0x4a9c0).

## 1a. Plain-language summary (how the PCM "thinks" in time)

- Think of the PCM as having **19 background jobs** (tasks). A job runs until it
  says "I'm done" (`taskEnd`), then the dispatcher picks the next ready job; if
  none is ready the CPU just spins in an empty loop (`0x3dac`) and only wakes
  for interrupts.
- **Interrupts are the alarm clocks.** Most important: a timer tied to the
  crankshaft fires once per crank-angle sector (every ~20° of crank rotation at
  36 sectors per 720°), and a CAN interrupt fires whenever a diagnostic message
  arrives. Interrupt handlers can either do the work directly or drop a
  "please run function X with these arguments" note into one of four mailboxes;
  on the way out of the interrupt the OS checks whether a waiting job outranks
  the interrupted one and switches to it.
- **Time is measured in crank angle, not milliseconds.** The "1 ms tick" style
  timers you might expect don't exist as a single hardware tick; instead each
  job keeps its own counters (e.g. engine-running seconds) that increment each
  time that job runs. How often a job runs therefore *is* the clock.
- The watchdog is kicked by ordinary code polling it, and if the watchdog ever
  actually overflows, the firmware treats it as a fatal error and halts.

## 2. How it works (condensed pseudocode)

```python
# --- boot ---
reset -> SBL (0x0-0x1fff) -> app init -> CAN/ATU/ADC/GPIO setup
      -> os_init 0x3e10:                      # ctrl block @ 0xffff7638
           ctrl+0x10 = 0xb0                   # ISR mask level
           ctrl+0x14 = 0xffff7408             # current ctx (task 0)
           ctrl+4    = 0xffff                 # no task scheduled yet
           ctrl+0x18 = 0x4990                 # task table ptr
           0x3964: ctrl+0 = 0xff, ready bitmap 0xffff7668 = 0, per-slot heads = -1
           0x3ec0: for i in 0..18: ctx[i] = {0, ?, 0xff, weight=task[i].mask.b0}
           0x3f10: schedule initial task list (ROM 0x4af0: tasks {17, 0})
           -> os_dispatch 0x3c2a

# --- dispatch / context switch ---
os_dispatch 0x3c2a(ctrl):
    if ctrl+6 (0xffff763e) != -1: os_dispatch_next_task 0x3c68 -> os_switch_to_task 0x375c(ctrl, ctrl+6)
    else: ctrl+8 = 0x80000000; ctrl+4 = 0xffff; ctrl+0x18 = 0x4990; ctrl+0x14 = 0xffff7408; idle 0x3dac  # bra self
os_switch_to_task 0x375c(ctrl, idx):        # pool 0x37b0 = 0x4990, stride 16
    rec = 0x4990 + idx*16; ctx = rec.stack    # 0xffff7408 + idx*8
    ctrl+4 = idx; ctrl+0x18 = rec; ctrl+0x14 = ctx; ctrl+8 = 0
    if ctx[0] == 0:                          # fresh task: build frame, enter via rte
        ctx[1] = rec.param.b2; ctx[4..] = ctrl+0xc; jmp 0x3848:
        r15 = ctrl+0xc; push SR=0; push entry; rte   # task starts with SR=0, PR-less
    else:                                    # resume: jump table 0x4b34[ctx[0]-rec.param.b0]
        jmp {0x37c4: partial restore, 0x3818/0x381c: ..., 0x37c8: full restore from r15=ctrl+0xc}
ref_taskEndRoutine_ 0x3d58:                  # task yield
    ctx = ctrl+0x14; ctx[3] += 1             # restore weight/credit
    flags 0xffff7640 = 0x100; consistencyCheck 0x3a28; ctx[0] = 0
    ctrl+0xc = ctx[4..]                      # save SP
    -> os_dispatch 0x3c2a

# --- interrupt entry/exit ---
IVT slot (VBR 0x7fc50 + off) -> trampoline (jsr 0x3238; jmp handler)
0x3238 interrupt_entry_save_context: save r2-r7, fr0-fr11, fpscr, fpul;
    SR = ctrl+0x10 (0xb0); ctrl+8 += 1; rts -> epilogue 0x3280
0x3280 epilogue: restore regs; SR = ctrl+0x10; ctrl+8 -= 1
    if ctrl+8 == 0 and a task is scheduled and outranks current:
        0x32f4: save r8-r14/gbr/mach/macl (+fr12-15 if ctx[0]==4), ctrl+0xc = r15,
                ctx[0] = 0xc, jmp dispatcher with r0 = ctrl+6   # context switch, no rte
    else: rte                                                    # 0x32e6
ref_setSR 0x3934 (software mask changes): ... -> os_wake_check_context_switch 0x3db0
0x3db0: if 0xffff763c != 0xffff763e and (0xffff7640 & 0x1000) == 0:
            flags = 0x100; 0x3bf4(ctrl) -> os_dispatch_next_task  # switch now

# --- message post (the "system call") ---
os_schedule_task_event 0x9630(group, idx, args...):
    rec = PTR[0xd87c + group*4] + idx*8      # {i16 target, u16 nargs, u32 handler}
    msg = {handler, arg1..arg4}
    if target == -1: handler(args)           # inline (ISR context), e.g. CAN poll 0x11d88
    else: 0x5f1c(target, msg)                # post to queue
0x5f1c post: raise mask 0xe0
    q = ROM[0xd74c + target*8]               # {buf, task_id, depth}
    state = RAM 0xffff9304 + target*3        # {tail, head, count}
    if count >= depth: return 2              # full
    0x3854(task_id): ctx[task_id][3] -= 1 (credit); 0x39ba(ctrl, task_id, class):
        class record = 0x4ac4 + class*8 {head, ptr -> RAM head/tail pair};
        if its head == -1 (empty): init head/tail, set bitmap 0xffff7668
        (bit 1<<(class&7) in byte class>>3, table 0x3d48 = 01 02 04 … 80),
        append task id to ready ring (ctrl+0x24 = 0xffff74a0)[tail];
        if class > ctrl[0] (cmp/hi, unsigned byte): ctrl[0] = class, ctrl+6 = task_id
        # preempt — note: at boot ctrl[0] = 0xff, so posts from idle do NOT set
        # ctrl+6 (dynamically observed); first real task run lowers ctrl[0]
    copy 5 words into buf[head*0x14]; head = (head+1) % depth; count += 1
    ref_setSR(old); return 0
0x6010 os_queue_dequeue_record(slot, out):   # called by consumer tasks
    if count == 0: return 3
    count -= 1; copy buf[tail*0x14] -> out (5 words); tail = (tail+1) % depth

# --- consumer tasks (rec[1..4]) ---
0x969e/0x96be/0x96de/0x96fe: r = 0x6010(slot 0/1/2/3, &scratch); if r == 0: msg.handler(msg.args); taskEnd 0x3d58

# --- the timing tick (crank-angle synchronous) ---
CMI10B (IVT 0x2c8) -> 0x5b3c: TSR10 = 0xb
    -> 0x75f4: if sync ok: 0x7f22/0x7b90/0x77f0 (ICR0AH->0xffff9fb8, ICR10AH->0xffff9fb0,
       0x787a advances sector 0xffff9f95 via tbl 0xd76c, wraps 0x24; 0x77f0 -> 0x7c68
       -> 0x7fcc ref_getCrankAngle: ring 0xffff9fd0 append, rpm = 1.2e8/sum -> 0xffff9f80)
       /0x7be4/0x80f0; then 0x7b58:
       OCR10B = tbl 0xd76d[0xffff9f95*2] & 0x7f; TCNT10B = 0   # rearm per sector
    -> 0xd716: 0xffffa3fc = 1
    -> 0xcf96: crank edge match -> period -> 0xa156: 0x9630(1, 9, arg)  # post to queue slot 2
       (dequeued by task 0x96de -> handler 0x11c98 -> 0x287aa fuel/load update + 0x3a0bc)
arm: task[8] 0x648e -> 0x759e -> 0x7778: TSR10 = 0xb; 0x7b58(); TIER10 |= 4 (CMFB); ch10 via TSTR3 bit0
CAN RX (IVT 0x378) -> 0x5e78 -> 0x9c86 -> 0x9630(1, 12, &0xffff7394) -> target -1 -> 0x11d88 inline:
    mailbox 14 (0x7e0) -> UDS RX buffer 0xffffddc8, clear RXPR
WDT: polled: 0x31c (keyed 0xa53c -> TCSR 0xffffec10, PB15 toggle); ITI (IVT 0x358) = fatal trap 0x5e0c -> 0x5348(0xd6)
```

## 3. Key tables / structures

| Address | Name | Contents |
|---|---|---|
| 0x7fc50 | IVT (VBR target, set at 0xd206) | 236 u32 vector slots (0x0–0x3ac); used ones point to trampolines 0x2710–0x31f0 (ctx save 0x3238 + handler) or, for reserved vec 0–63, to fatal-trap stubs 0x53a0+ |
| 0x4990 | task table | 19 × 16 B records {param, ctx ptr, entry, weight}, terminator 0x4ac0 = {0x04ffffff, 1, …}; entries listed in §4 |
| 0x4b34 | dispatch jump table | {0x37c4, 0x3818, 0x37c8, 0x381c} — resume-restore variants indexed by ctx[0] − param.b0 |
| 0x4aec–0x4b30 | OS init tables | 0x4aec = per-class base 0x4ac4; 0x4af4 = init task list 0x4af0 = {17, 0}; 0x4b24 → 0xffff7678 = 0x4b1d order table |
| 0xffff7638 | `os_ctrl_block` | +0 current class byte, +4 scheduled count (`os_scheduled_count` 0xffff763c), +6 next task (`os_dispatched_count` 0xffff763e), +8 ISR depth/flags (`os_state_flags` 0xffff7640), +0xc saved SP (`DAT_ffff7644`), +0x10 mask 0xb0, +0x14 ctx ptr (`os_current_task_record_ptr` 0xffff764c), +0x18 task-table ptr (`os_task_table_ptr` 0xffff7650), +0x20 class-records base 0x4ac4, +0x24 ready-ring ptr 0xffff74a0, +0x30 ready bitmap 0xffff7668 (bit 1<<(class&7) in byte class>>3) |
| 0xffff7408 + 8·i | per-task context blocks | byte0 state (0 fresh / 0xc preempted), byte1 class, byte2 0xff, byte3 weight/credit (task record mask byte0: 0x01/0x0a/0x1e/0x64/0x02) |
| 0xd74c + 8·i | queue ROM records (i = 0..3) | {buf ptr, task id 1..4, depth} = {0xffff9310,1,10}, {0xffff93d8,2,10}, {0xffff94a0,3,30}, {0xffff96f8,4,100} |
| 0xffff9304 + 3·i | queue RAM state | {tail, head, count} per slot |
| 0xd87c + 4·g | scheduler group pointer table | g0 → 0xd9cc, g1 → 0xd944 (engine events), g2 → 0x67d00 (diag/UDS); records 8 B {i16 target, u16 nargs, u32 handler}; target −1 = inline call |
| 0xa0de–0xa22c | post wrappers | 0x18-byte thunks calling 0x9630(1, idx∈{0..0xc}, arg) / 0x9630(2, idx∈{2,3}, arg) |
| 0xd76c / 0xd76d | crank sector tables | next-sector map and per-sector OCR10B (byte at +2·sector, & 0x7f), indexed by sector 0xffff9f95 (0x00–0x24) |
| 0x6010 / 0x5f1c / 0x9630 | queue API | dequeue / post / scheduler (above) |

## 4. Task inventory (the 19 update loops)

| rec | entry | weight | contents (one run, then taskEnd unless noted) |
|---|---|---|---|
| 0 | 0x62a0 | 0x01 | **background loop, never yields** (do-while): 0xa50e, 0x4cb6, 0x7088, 0x69e2, 0x74b0, ATU ch3/4 PWM reconfig, 0x2064, 0xb5a0, 0xbdbc, 0x7568, 0xac02, 0xc176, 0x8268, 0x8f94, 0xb290, 0x1122a, 0xd46c, 0x9f0c(1) |
| 1 | 0x969e | 0x0a | consume queue slot 0 (scratch 0xffffa118) → call handler → taskEnd |
| 2 | 0x96be (`uds_service_task_entry`) | 0x0a | consume slot 1 (0xffffa12c) → handler → taskEnd |
| 3 | 0x96de | 0x1e | consume slot 2 (0xffffa140) → handler → taskEnd (crank-tick messages land here) |
| 4 | 0x96fe | 0x64 | consume slot 3 (0xffffa154) → handler → taskEnd |
| 5 | 0x65f6 (`ref_task1_`) | 0x02 | rotor-0 timing: `ref_getRotorNumberForControl_`(0), `ref_functionDrivingTiming`, 0x82d8, 0x9038, 0x11b7e → taskEnd |
| 6 | 0x661e (`ref_task2_`) | 0x02 | rotor-1 engine control: rotor(1), `knock_voltage_sample`, `ref_engineControlTASK`, 0x8320, `ref_getIgnitionDwellTime_00009110` → taskEnd (ignition task) |
| 7 | 0x63f0 (`ref_interruptSetup___`) | 0x02 | MAF scaling, ADC helpers, GPIO 0xfffff746 bit4, `candidate_apv_pwm_service` → taskEnd |
| 8 | 0x648e | 0x02 | 0x6796, 0x759e (**arms the CMI10B tick** via 0x7778/0x7b58), 0xb3aa, ECM voltage, rear O2, 0x114d0 → taskEnd |
| 9 | 0x64ba (`candidate_knock_sensor_fault_task`) | 0x02 | `ref_main__`, 0x6842, 0x94fc, `ref_knockSensorADCFault`, 0x1150e (→ 0x199d4 → `ref_calculateEngineRunningTimer` 0xe21c), 0x9fb2(0) → taskEnd |
| 10 | 0x64f6 | 0x02 | 0x6846, `ref_getBaroSensorVal`, 0x11744 → taskEnd (intake chain) |
| 11 | 0x6584 | 0x02 | 0x117ac → taskEnd (fueling task) |
| 12 | 0x6592 | 0x02 | 0xa4b6, 0xaee8, 0x11880, 0xb308 → taskEnd |
| 13 | 0x65b2 | 0x02 | 0x7298, 0x73a0, 0x118d0 → taskEnd |
| 14 | 0x65cc | 0x02 | 0x11adc → taskEnd |
| 15 | 0x65da | 0x02 | 0x11b08 → taskEnd |
| 16 | 0x65e8 | 0x02 | 0x11b22 → taskEnd |
| 17 | 0x60c8 (`ref_getSensorStuff__`) | 0x01 | sensor task: ADC sweep 0x6884, `vehicle_inputs_poll_pfdr_phdr` 0x6744 (→ 0xffff9ec8), ATU ch3/4 PWM, … → taskEnd |
| 18 | 0x64e8 | 0x02 | thunk → **slow/background task 0x11534** (29 calls: 0x2e5c6, torque params, 0x38f3e, 0x21186, `candidate_timing_retard_fast_task`, …, `ref_calculateDiagModeTimer` 0x55d42, `ref_runImmoRelatedCounter`, …, 0x2a290, 0x16b50) → taskEnd |

Weights (task record mask byte0) act as per-task credit counts: `0x3854`
decrements the target's credit on each post and `0x3d58` (taskEnd) increments it
back — dynamically observed (task[3] ctx[3] 0x1e → 0x1d on post).

## 5. Interrupt sources (the timing loops)

117 vectors (offsets 0x100–0x39c, vec 64–230) point at real trampolines
(byte-verified against ROM at 0x7fc50+off; every trampoline's first pool word =
0x3238). Of these, **98 end in the fatal trap** `fatal_interrupt_trap` (clear a
peripheral flag, report a code via 0xa330, spin at 0x535a forever) — any
unexpected interrupt is a deliberate halt. The **19 with real handlers**:

| IVT off | vec | handler | role |
|---|---|---|---|
| 0x2c8 | 178 | 0x5b3c | **CMI10B — the OS/crank tick** (see §2): sector advance, rearm, rpm ring, scheduler post |
| 0x260–0x274 | 152–157 | 0x59a4/0x59b2/0x59c0/0x59ce/0x59dc/0x59ea | **ATU-II ch8 compares → `candidate_injector_pulse_set_dispatch(0..5)`** — the per-channel injector pulse-set timing loop (one vector per output channel) |
| 0x290 | 164 | 0x5a4c | ch8 flag + `knock_reference_adc_read` (knock ADC sampling trigger) |
| 0x204 / 0x224 | 129/137 | 0x567a / 0x57c6 | ATU-II ch3 compares (TSR3 clear + PWM update math, 0x7e-window compares) |
| 0x2b0 | 172 | 0x5b14 | ATU-II ch9 (TSR9 clear → 0xb5fa) |
| 0x2f8 / 0x308 / 0x310 | 190/194/196 | 0x5ce2 / 0x5cfe / 0x5d0a | **ADC end-of-conversion** banks 0/1/2 (clear ADCSRn bit7; 0x5cfe also calls 0x6b60) |
| 0x300 | 192 | 0x5cee | CMCSR1 (refresh timer) → 0xa522 |
| 0x110 | 68 | 0x53f6 | ISR_W = 0xf7 (external IRQ flags) → 0xb6b2 |
| 0x378 | 222 | 0x5e78 → 0x9c86 | **CAN RX**: inline 0x9630(1,12) → 0x11d88 CAN poll → UDS buffer 0xffffddc8 (dynamically traced §9) |
| 0x37c | 223 | 0x5ebc | HCAN0 IRR bit0 → 0x9c9c (CAN status/error path) |
| 0x398 | 230 | 0x5eee → 0x9c86 | second CAN-related entry |
| 0x358 | 214 | 0x5e0c → 0x5348(0xd6) | WDT overflow = **fatal trap** (Sh7055h.pdf table 7.3; E3) — counted among the 98 |
| 0x0–0xfc | 0–63 | stubs 0x53a0–0x53c2 | reserved vectors: load a code into r4, bra 0x5348 → fatal trap |

So the *live* timing loops are: **CMI10B per crank sector** (OS tick),
**crank input capture** (ICR0AH/ICR10AH, polled by 0x77f0 / used by 0xcf96),
**ATU-II ch8 compare per injector channel** (pulse-set outputs),
**ADC EOC** per bank (sensor sampling), and **CAN RX** for diagnostics.
Everything else that fires is treated as a fault.

## 6. Labeling applied

**Labels applied** (all high-confidence, each tied to its ROM
address and backed by the binary-level + emulator evidence in §9; full record:
`data/labels/60E15120_N3J1E/os_scheduling_labels.json`; rows appended to
`source_review/accepted_{function,ram,lookup}_aliases.tsv`; applied via
`merge_reviewed_lookup_aliases.py` + `integrate_reviewed_names.py`; pre-change
backup `backups/pre_os_scheduling_labels.zip`):

- **33 functions** (all `high`): 0x5b3c `cmi10b_tick_isr`, 0x75f4
  `cmi10b_tick_service`, 0x7b58 `ch10b_compare_rearm`, 0x787a
  `crank_sector_advance`, 0xd716 `crank_tick_flag_set`, 0xcf96
  `crank_edge_period_update`, 0xa156 `post_crank_tick_message`, 0x5f1c
  `os_post_message`, 0x39ba `os_mark_task_ready`, 0x3854 `os_wake_posted_task`,
  0x3bf4 `os_context_switch`, 0x9c86 `can_rx_isr_handler`, 0x62a0
  `task0_background_loop`, 0x969e `msg_queue_task_slot0`, 0x96de
  `msg_queue_task_slot2`, 0x96fe `msg_queue_task_slot3`, 0x64e8 `slow_task_entry`,
  0x11534 `slow_background_task`, 0x11c98 `crank_tick_message_handler`, 0x5348
  `fatal_interrupt_trap`, 0xa330 `fatal_trap_report_halt`, 0x5e0c
  `wdt_iti_fatal_trap`, 0x59a4/0x59b2/0x59c0/0x59ce/0x59dc/0x59ea
  `atu_ch8_cmp_isr_ch0/3/1/4/2/5`, 0x5a4c `knock_adc_trigger_isr`, 0x5ce2/0x5cfe/0x5d0a
  `adc_eoc_isr_bank0/1/2`, and 0x9630 `ref_osTaskScheduler` →
  `os_schedule_task_event` (upgrade of the inherited ref_ name on new dynamic
  evidence).
- **10 RAM cells**: 0xffff9304 `queue_state_base`, 0xffff9f95
  `crank_sector_index`, 0xffffa3fc `crank_tick_flag`, 0xffff7668
  `os_ready_bitmap`, 0xffff74a0 `os_ready_ring`, 0xffff9fd0 `crank_period_ring`,
  0xffffa118/a12c/a140/a154 `msg_dequeue_scratch_slot0..3`.
- **6 tables**: `tbl_os_queue_records_0000d74c`, `tbl_os_schedule_group_ptrs_0000d87c`,
  `tbl_crank_next_sector_0000d76c`, `tbl_crank_sector_ocr10b_0000d76d`,
  `tbl_os_resume_jumptable_00004b34`, `tbl_os_class_bit_00003d48`.

Not labeled (deliberately left at FUN_/ref_ level): the LAB_ addresses 0x32f4 /
0x3848 (epilogue switch / first-entry tails — verified but label-as-function not
applied), 0x803e (see §7 — pre-VBR vector target, name kept), the ch3/ch9
compare handlers 0x567a/0x57c6/0x5b14 and IRQ-flag handler 0x53f6 (role clear,
naming left for a future pass), and the task entries 0x65f6–0x65e8 (already
carry ref_/candidate_ names from earlier passes).

## 7. Corrections made in this pass

- **0x803e is not the post-VBR CMI10B handler.** IVT 0x7fc50+0x2c8 → trampoline
  0x2ec0 → handler **0x5b3c** (byte-verified). 0x803e has no callgraph callers; its
  only ROM reference is the *default* (VBR=0) vector table slot 0x2c8 (u32 at ROM
  0x2c8 = 0x803e) — the pre-relocation entry, superseded once VBR=0x7fc50 is set
  at 0xd206. The live rpm path is `ref_getCrankAngle` **0x7fcc** (ring 0xffff9fd0
  append, rpm = 1.2e8/Σ → 0xffff9f80), called from 0x7c68 ← 0x77f0 ← tick
  handler 0x75f4; 0x803e duplicates 0x7fcc's math for the pre-VBR entry.
- **The "OS tick" is crank-angle-synchronous, not a fixed-period timer.**
  OCR10B is reloaded per crank sector from table 0xd76d indexed by sector
  0xffff9f95 (0x00–0x24), TCNT10B cleared on rearm (0x7b58) — so CMI10B fires per
  sector, with per-sector intervals in ROM, not every N µs.
- **0x5348 is a fatal trap, not a dispatcher.** The vec 0–63 stubs and 98 of
  the 117 real-trampoline vectors call it; it raises SR to 0xe0, reports the
  code via 0xa330 and spins at 0x535a forever. Only 19 vectors have real
  handlers (§5): CMI10B tick, the six ATU-II ch8 injector-compare vectors,
  knock-ADC trigger, ch3/ch9 compares, three ADC EOC banks, CMCSR1, one IRQ
  flag vector, and the CAN vectors.
- **Vector count corrected**: 117 vectors (IVT 0x100–0x39c) have real
  trampolines, not 114 — the earlier count mis-parsed the 0x378 trampoline's
  pool word (re-derived with correct mov.l disp extraction, all 117 ctx words
  = 0x3238).
- **Fresh-task entry is `rte`, not a jump**: 0x3848 sets r15 = ctrl+0xc, pushes
  SR=0 and the entry address, and executes `rte` (disasm 0x3848–0x3850) —
  new tasks start with interrupt mask 0.
- **Preemption condition**: 0x39ba sets ctrl+6 only when `class > ctrl[0]`
  (`cmp/hi`, unsigned byte); at boot ctrl[0] = 0xff so posts from the idle
  state do not schedule a task (dynamically observed — the decompiled signed
  comparison `(char)ctrl[0] < class` is a decompiler sign-extension artifact).
- Task table orientation re-confirmed: 19 records at **0x4990**
  {param, ctx, entry, weight} (fueling pass §10.6 stands); rec[0].entry 0x62a0
  is the never-yielding background loop, rec[18].entry 0x4ab8 → 0x64e8 is the
  slow-task thunk.

## 8. Files

- This report: `docs/investigations/60E15120_N3J1E/os_scheduling_deep_dive_report.md`
- Cross-link added to [`os_scheduler_can_ivt_report.md`](os_scheduler_can_ivt_report.md) (Related reports line + §12 addendum).
- Labeling pass artifacts (§6): `data/labels/60E15120_N3J1E/os_scheduling_labels.json`;
  appended rows in `source_review/accepted_{function,ram,lookup}_aliases.tsv`;
  renamed views: `reverse-engineered/decompiled/60E15120_N3J1E/` (symbols.tsv,
  function_index.tsv, callgraph.tsv, functions/*.c, firmware_decompiled.c,
  named/firmware_named.c, named/lookup_aliases.tsv, metadata/integrated_names.json);
  pre-change backup `backups/pre_os_scheduling_labels.zip` (LFS).
  No `binaries/` file touched (`hash_binaries.py --check` OK); ROM SHA unchanged.

## 9. Validation

- **Binary-level (rule 7)**: task table 0x4990–0x4acf, group pointer table
  0xd87c (→ 0xd9cc/0xd944/0x67d00), queue records 0xd74c–0xd76c, sector tables
  0xd76c/0xd76d, pools 0x37b0–0x37c0 (0x4990 / 0x4b0c / 0x35cc / 0x3848 / 0x4b34),
  jump table 0x4b34, IVT entries at 0x7fc50+0x2c8/0x358/0x378, idle loop bytes
  `affe 0009` at 0x3dac, wake call literal 0x3950 = 0x3db0, post wrappers
  0xa0de–0xa22c — all re-read from the raw ROM this session and matched.
  Every function address cited in §10 was checked against `function_index.tsv`.
- **Dynamic (emulator, profile 60E15120_N3J1E, boot 300k cycles → idle 0x3dac)**:
  - after boot: ctrl block 0xffff7638 = 0xff000000, 0xffff763c = 0xffff,
    0xffff7640 = 0x80000000, 0xffff7648 = 0xb0, 0xffff7650 = 0x4990,
    0xffff7658 = 0x4ac4, 0xffff765c = 0xffff74a0, ready bitmap 0xffff7668 =
    0x11000000 (= classes {0, 4} marked ready — matches the init list
    {task 17 (class 4), task 0 (class 0)} at ROM 0x4af0 walked by 0x3f10);
    ctx blocks 0xffff7408+8i = {00 00 ff weight} with weights
    0a/0a/1e/64/02… for tasks 1–16/18 matching the task-record mask bytes —
    and tasks 0/17 read weight **0** (their initial 1 was consumed by 0x3f10),
    which dynamically confirms the init task list {17, 0};
  - `cpu.interrupt(0x2c8)` trace: 0x3238 → 0x5b3c → 0x75f4 → 0x7b58 → 0xd716 →
    0xcf96 → 0x3280 → rte → 0x3dac (tick handler chain, no scheduler post without
    a crank edge match in 0xcf96);
  - `can.inject(0x7e0, [03 22 00 43 …])` + `cpu.interrupt(0x378)` trace:
    0x3238 → 0x5e78 → 0x9c86 → **0x9630(r4=1, r5=0xc, r6=0xffff7394)** → 0x11d88 →
    0x3280 → rte → 0x3dac, and UDS RX buffer 0xffffddc8 = `03 22 00 43 00…`
    (group-1 record 12 has target −1 → inline 0x11d88);
  - `harness.call(0x9630, r_args=(1, 9, 0xffffa118), ram={0xffffa118: 0xdeadbeef})`
    → r0 = 0; queue slot 2 state 0xffff930a–0xc = tail 01 / head 00 / count 01,
    message at 0xffff94a0 = {0x00011c98, 0xdeadbeef, 0, 0, 0}; ready bitmap
    0x11000000 → 0x15000000; task[3] ctx[3] 0x1e → 0x1d (credit consumed);
  - then running task entry 0x96de: trace 0x96de → 0x6010 (count 01 → 00, head
    00 → 01) → handler **0x11c98** → 0x287aa → 0x3db0 → 0x3a0bc → 0x3d58
    (taskEnd) → 0x3c2a → idle 0x3dac. Full post → queue → dequeue → handler →
    yield → dispatch → idle loop reproduced end to end.
- **Targeted report validation**: `validate_reports.py` currently crashes on
  `main` before reaching any report because the pre-existing
  `uds_mode22_dispatch_report.md` contains a non-UTF-8 byte (0x97, cp1252 dash) —
  reproduced on clean `main`, not caused by this branch. Running the same checks
  (required sections, ROM SHA, memory-map addresses/names vs `function_index.tsv`
  + `accepted_ram_aliases.tsv`/`integrated_names.json`, ROM bounds) against this
  report only: PASS.
- After the labeling pass (§6): `validate_export.py` PASS (input SHA-256 verified,
  3,355 function files, 168,592 instructions / 337,184 bytes verified, 1,833 exact
  reference matches; `semantic_equivalence_verified: false` is the pre-existing
  state, unchanged in `validation.json`), `verify_readability.py` PASS (3,355
  bodies consistent), `verify_math_units.py` PASS, targeted report checks PASS on
  all UTF-8-clean reports incl. this one. `python -m pytest tests/` could not run
  in this environment (pytest not installed here); last full run on `main` was 61/61.

## 10. Memory map for validation

#### Functions

| Address | Name (function_index.tsv) |
|---|---|
| 0x003238 | `interrupt_entry_save_context` |
| 0x003490 | `FUN_00003490` |
| 0x0035cc | `FUN_000035cc` |
| 0x00375c | `os_switch_to_task` |
| 0x003854 | `os_wake_posted_task` |
| 0x003920 | `sh_raise_interrupt_mask_return_previous` |
| 0x003934 | `ref_setSR` |
| 0x0039ba | `os_mark_task_ready` |
| 0x003a28 | `ref_consistencyCheck` |
| 0x003ac0 | `FUN_00003ac0` |
| 0x003bf4 | `os_context_switch` |
| 0x003c2a | `os_dispatch` |
| 0x003c68 | `os_dispatch_next_task` |
| 0x003d58 | `ref_taskEndRoutine_` |
| 0x003dac | `FUN_00003dac` (idle spin `bra self`) |
| 0x003db0 | `os_wake_check_context_switch` |
| 0x003e10 | `os_init` |
| 0x003964 | `FUN_00003964` |
| 0x003ec0 | `FUN_00003ec0` |
| 0x003f10 | `FUN_00003f10` |
| 0x005348 | `fatal_interrupt_trap` (fatal trap) |
| 0x005b2e | `FUN_00005b2e` |
| 0x005b3c | `cmi10b_tick_isr` (CMI10B handler) |
| 0x005b56 | `FUN_00005b56` |
| 0x005e0c | `wdt_iti_fatal_trap` (WDT ITI trap) |
| 0x005e78 | `thunk_FUN_00009c86_00005e78` (CAN RX thunk -> 0x9c86 `can_rx_isr_handler`) |
| 0x005f1c | `os_post_message` (post) |
| 0x006010 | `os_queue_dequeue_record` |
| 0x0060c8 | `ref_getSensorStuff__` (task[17]) |
| 0x0062a0 | `task0_background_loop` (task[0] background loop) |
| 0x0063f0 | `ref_interruptSetup___` (task[7]) |
| 0x00648e | `FUN_0000648e` (task[8], arms tick) |
| 0x0064ba | `candidate_knock_sensor_fault_task` (task[9]) |
| 0x0064e8 | `slow_task_entry` (task[18] thunk) |
| 0x0064f6 | `FUN_000064f6` (task[10]) |
| 0x006584 | `FUN_00006584` (task[11], fueling) |
| 0x006592 | `FUN_00006592` (task[12]) |
| 0x0065b2 | `FUN_000065b2` (task[13]) |
| 0x0065cc | `FUN_000065cc` (task[14]) |
| 0x0065da | `FUN_000065da` (task[15]) |
| 0x0065e8 | `FUN_000065e8` (task[16]) |
| 0x0065f6 | `ref_task1_` (task[5]) |
| 0x00661e | `ref_task2_` (task[6], ignition) |
| 0x006648 | `FUN_00006648` (grp1[0] handler) |
| 0x006670 | `FUN_00006670` (grp1[4] handler, fuel-array stuff) |
| 0x006744 | `vehicle_inputs_poll_pfdr_phdr` |
| 0x006884 | `adc_scan_sweep_all_channels` |
| 0x00759e | `FUN_0000759e` |
| 0x007778 | `atu_ch10b_tick_enable` |
| 0x0077f0 | `crank_capture_poll` |
| 0x00787a | `crank_sector_advance` (sector advance) |
| 0x007b58 | `ch10b_compare_rearm` (OCR10B rearm) |
| 0x007eca | `FUN_00007eca` |
| 0x007f22 | `FUN_00007f22` |
| 0x007c68 | `ref_geteShaftAngle_` (calls 0x7fcc from the tick chain) |
| 0x007fcc | `ref_getCrankAngle` (live rpm path: ring append, rpm → 0xffff9f80) |
| 0x00803e | `crank_isr_compute_rpm` (pre-VBR base-IVT CMI10B target at ROM slot 0x2c8; superseded post-VBR by 0x5b3c; duplicates 0x7fcc's math — §7) |
| 0x009630 | `os_schedule_task_event` |
| 0x00969e | `msg_queue_task_slot0` (task[1], slot 0) |
| 0x0096be | `uds_service_task_entry` (task[2], slot 1) |
| 0x0096de | `msg_queue_task_slot2` (task[3], slot 2) |
| 0x0096fe | `msg_queue_task_slot3` (task[4], slot 3) |
| 0x009c86 | `can_rx_isr_handler` (CAN RX handler body) |
| 0x00a0de | `FUN_0000a0de` (post wrapper grp1[6]) |
| 0x00a10e | `ref_putTaskInSchedule_FuelArrayStuff` (grp1[4]) |
| 0x00a156 | `post_crank_tick_message` (grp1[9], crank-tick post) |
| 0x00a330 | `fatal_trap_report_halt` (fatal report) |
| 0x00a218 | `FUN_0000a218` (post wrapper grp2[3]) |
| 0x0011d88 | `can_rx_poll_move_to_uds_buffer` |
| 0x0011534 | `slow_background_task` (slow task, 29 calls) |
| 0x0011c98 | `crank_tick_message_handler` (grp1[9] handler) |
| 0x000287aa | `FUN_000287aa` (per-tick fuel/load update) |
| 0x0003a0bc | `FUN_0003a0bc` |
| 0x0000cf96 | `crank_edge_period_update` (crank edge/sector track) |
| 0x0000d716 | `crank_tick_flag_set` (tick flag) |
| 0x0000e21c | `ref_calculateEngineRunningTimer` |
| 0x00031c | `service_wdt_overflow_and_toggle_pb15` |

#### RAM

| Address | Name |
|---|---|
| 0xffff7638 | `os_ctrl_block` (fields: +4 `os_scheduled_count` 0xffff763c, +6 `os_dispatched_count` 0xffff763e, +8 `os_state_flags` 0xffff7640, +0xc DAT_ffff7644 saved SP, +0x14 `os_current_task_record_ptr` 0xffff764c, +0x18 `os_task_table_ptr` 0xffff7650, +0x20 class base, +0x24 ready ring, +0x30 bitmap DAT_ffff7668) |
| 0xffff7408 | `os_task_stack_base` (per-task ctx blocks 0xffff7408+8·i, i=0..18) |
| 0xffff9304 | DAT_ffff9304 queue state base {tail, head, count} per slot i at +3·i |
| 0xffff9310 | DAT_ffff9310 queue slot 0 buffer (depth 10 × 0x14 B) |
| 0xffff93d8 | DAT_ffff93d8 queue slot 1 buffer |
| 0xffff94a0 | DAT_ffff94a0 queue slot 2 buffer (crank-tick messages) |
| 0xffff96f8 | DAT_ffff96f8 queue slot 3 buffer (depth 100) |
| 0xffff9f80 | `engine_speed_rpm_raw` (rpm float) |
| 0xffff9f88 | `crank_period_accumulator` |
| 0xffff9f95 | DAT_ffff9f95 crank sector index 0x00–0x24 |
| 0xffff9fa8 | `crank_period_last` |
| 0xffff9fb0 | `crank_icr10ah_sample` |
| 0xffff9fb8 | `crank_icr0ah_sample` |
| 0xffff9fd0 | DAT_ffff9fd0 crank period ring [6] |
| 0xffff9ec8 | `vehicle_inputs_pfdr_latch` |
| 0xffffa3fc | DAT_ffffa3fc tick flag (0xd716) |
| 0xffffa118 | DAT_ffffa118 dequeue scratch (slot 0; slots 1–3 at 0xffffa12c/a140/a154) |
| 0xffffa424 | `engine_running_timer` |
| 0xffffddc8 | `uds_rx_buffer` |
| 0xffffddd0 | `uds_tx_buffer` |

#### ROM data tables

| Address | Contents |
|---|---|
| 0x004990–0x004acf | task table, 19 × 16 B {param, ctx, entry, weight} + terminator (entries in §4) |
| 0x004b34 | dispatch jump table {0x37c4, 0x3818, 0x37c8, 0x381c} |
| 0x004aec–0x004b30 | OS init tables (class base 0x4ac4, init list 0x4af0 = {17, 0}) |
| 0x00d74c–0x00d76b | queue ROM records {buf, task id, depth} × 4 |
| 0x00d76c / 0x00d76d | crank next-sector / per-sector OCR10B tables (byte at +2·sector) |
| 0x00d87c | scheduler group pointer table → 0xd9cc, 0xd944, 0x67d00 (8 B records {target, nargs, handler}) |
| 0x00d9cc / 0x00d944 / 0x00d9f4… | group 0 / group 1 / group 2 descriptor records |
| 0x00a0de–0x00a22c | post wrappers (0x9630 with fixed group/idx) |
| 0x07fc50 | IVT at VBR (236 slots; used: 0x2c8 CMI10B, 0x378 CAN RX, 0x358 WDT ITI, …) |

#### Registers

| Address | Role |
|---|---|
| 0xfffff400 | ATU-II base: TSTR3 0xfffff402 bit0 = ch10 start; PSCR1–4 0xfffff404–0xa = 4; TCR10 0xfffff6e4; TCNT10B 0xfffff6c4; OCR10B 0xfffff6d8; TSR10 0xfffff6e8; TIER10 0xfffff6ea bit2 = CMFB enable; ICR0AH 0xfffff434; ICR10AH 0xfffff6d0; DCNT8A–P 0xfffff640–0x65e / GR1A–H 0xfffff444–0x452 (injector/coil outputs) |
| 0xffffe400 | HCAN0: RXPR 0xe40e, MBIMR 0xe414, MC 0xe420+8·mb, MD 0xe4b0+8·(mb&0xf); mb14 = 0x7e0 RX, mb15 = 0x7e8 TX |
| 0xffffec10 | WDT TCSR (keyed 0xa53c service writes, OVF flag polled) |
| 0xfffff738 | GPIO PBDR bit15 = external watchdog heartbeat |
| 0xfffff800 | ADC: ADDRn, ADCSR0/1/2 (0x818/0x838/0x858); sweep result → RAM 0xffff9ee4+ |
| 0xffffed18 | SYSC ICR_W bit15 = NMI pin (boot poll at 0x8ea) |

## 11. Limits

- Emulator observations are at 1 cycle/instruction (E7: not real time); the ATU
  tick storm seen when arming ch10B by hand (OCR10B small) is an artifact of
  that — on hardware the per-sector OCR values fit inside the handler time.
- The autonomous **ISR-exit context switch** (epilogue path 0x32f4 → dispatcher)
  was *not* observed firing in emulation (E6): with ctrl+6 preset and a CAN RX
  interrupt, the trace returned to idle via plain `rte`. The post path marks
  readiness (bitmap/credits, dynamically shown) but the preemption condition
  in 0x39ba/0x32f4 did not trigger from the idle state; the full task graph is
  therefore driven via `harness.call` on task entries in this report. Closing E6
  remains open.
- Ready-ring/priority micro-semantics (exact bit order of 0xffff7668 vs task id,
  the `ctrl[0]` comparison polarity in 0x39ba, resume jump-table indices beyond
  the 4 verified entries) are read from decompiled C + disassembly, not all
  dynamically exercised — treat as medium confidence.
- Per-sector tick intervals (table 0xd76d) are in ATU-II count units; the exact
  µs conversion needs the Pφ/PSCR/TCR10 CKSEL math from Sh7055h.pdf, not derived
  here. The emulator counts 1 ATU count = 1 cycle.
- Software timers are named only for the examples traced to their owning tasks
  (§1); a full timer-cell inventory is future work (register D6 stays open).
- `validate_reports.py` could not run end-to-end on this branch because of the
  pre-existing non-UTF-8 byte in `uds_mode22_dispatch_report.md` on `main`;
  equivalent checks were run against this report only (§9).


## 13. Label application + re-check

§6 is applied: 33 functions + 10 RAM cells + 6 tables renamed in the decompiled
views via `merge_reviewed_lookup_aliases.py` + `integrate_reviewed_names.py`
(backup `backups/pre_os_scheduling_labels.zip`, committed as LFS pointer;
record `data/labels/60E15120_N3J1E/os_scheduling_labels.json`). Re-check: no duplicate names in `function_index.tsv`; all 33 labels match
`symbols.tsv`; JSON ↔ TSV rows consistent (33/33); call sites renamed correctly
(e.g. 0x9c86 `can_rx_isr_handler` calls `os_schedule_task_event(1, 0xc, …)`);
RAM/lookup tokens landed in code (`queue_state_base_ffff9304`,
`tbl_crank_next_sector_0000d76c`, …); the 117/98/19 IVT classification is re-verified; pre-existing cp1252 bytes in two TSVs / two function files verified
byte-identical to HEAD (surrogateescape round-trip). `validate_export.py`,
`verify_readability.py`, `verify_math_units.py` and the targeted report checks all
PASS; `hash_binaries.py --check` OK. Not re-run here: `pytest tests/` (pytest not
installed in this environment; last full run on `main` 61/61).
