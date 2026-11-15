#!/usr/bin/env python3
"""Append reviewed ignition-key / power-state aliases to the curated TSVs (idempotent).

Runs after review_fan_control_labels.py and before annotate_source_review.py in
scripts/rebuild.sh. Covers the reset warm/cold split (0x4e0/0x1298/0x1038/0x6c8),
the key-on input path (PFDR bit0 -> 0xffff9ec8 -> 0xffffaa69/aa68; PF15 edge
0x454c0/0x454d2), the key-off shutdown state machine (0x252c2 cluster), the
relay-hold output PD11 (0x251d0) and PF3 (0x9e68/0x9ea2), the WDT heartbeat
(0x31c/0x11cc/0xa850), and the key-on/off timers (0x195cc/0x195f4).
Also writes metadata/ignition_power_state_labels.json.
"""

from pathlib import Path
import csv, json, sys

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py)
BASIS = 'source_review_ignition_power_state'


FUNCTIONS = [
    # address, alias, confidence, evidence
    ("000004e0", "reset_handler_warm_cold_select", "high",
     "Warm/cold entry select (was ref_resetHandler_): bsr 0x572; jsr 0x170 (pool 0x586=0x170), 0x41c (0x588=0x41c), 0x3d4 (0x58a=0x3d4); param==0: cmp u32 @0xffffdffc (pool 0x5a0=0xffffdffc) vs 0x5aa5a55a (pool 0x59c=0x5aa5a55a) at 0x508; on mismatch bsr 0x5b0 with r4=7 (WDT overflow count) - magic match or overflow selects warm entry = u32 @ROM 0x1000 (pool 0x58e=0x1000; ROM 0x1000 = 0x1298), else cold 0x6c8 (pool 0x58c=0x6c8); warm branch also tests u32 @0x7fffc (pool 0x5a4=0x7fffc; ROM 0x7fffc = 0x2000) with fallback u32 @0x7fff8 (pool 0x5a8=0x7fff8; ROM 0x7fff8 = 0xd204); writes 0x5aa5a55a to 0xffffdffc at 0x562-0x566, jsr 0x40 (pool 0x594=0x40) with r4 = chosen entry, halt. param!=0 branch stores param_2 byte to 0xffffdfa8 (pool 0x590=0xdfa8) and selects cold 0x6c8."),
    ("0000d20c", "manual_reset_finalize", "high",
     "Was ref_handleManualReset_: r1 = pool 0xd2c8=0xd730 (cell holding 0xffff768c), jsr 0x4c7a (pool 0xd2cc=0x4c7a) with r4 = *(0xd730), jsr 0x9e68 (pool 0xd2d0=0x9e68, recovery_finalize_set_pf3_halt), halt at 0xd21a. Entered from the recovery block at 0xd204 (ldc vbr 0x7fc50 pool 0xd2c0=0x7fc50, lds fpscr 0x40001 pool 0xd2c4=0x40001, then falls into 0xd20c); 0xd204 is the value of u32 @ROM 0x7fff8."),
    ("00001038", "warm_reset_dispatcher", "high",
     "Was ref_reset_ZERO: jsr 0x1364 (pool 0x107a=0x1364), 0x109c (0x107c=0x109c, ref_resetOBDCAN_), 0x16dc (0x107e=0x16dc); param!=0 -> jsr 0x12a2 (pool 0x1080=0x12a2) then entry 0x1378 (pool 0x1082=0x1378); param==0 -> flash-pointer check u32 @0x7fffc (pool 0x1088=0x7fffc) with fallback u32 @0x7fff8 (pool 0x108c=0x7fff8; ROM 0x7fff8 = 0xd204); jsr 0x1090 (pool 0x1084=0x1090; mov.l pool 0x1098 to r15, jmp @r4) then halt at 0x1076."),
    ("000006c8", "cold_entry_ring_dispatch_loop", "high",
     "Cold entry monitor loop (selected by pool 0x58c=0x6c8 in 0x4e0): zeroes 0xffffdfb8 (pool 0x796=0xdfb8); loop jsr 0x364 (pool 0x7a4=0x364; dispatches on reset cause 0xffffdfa8), remaining-count jsr 0x3e0 (pool 0x79e=0x3e0), ring record ptr jsr 0x3b0 (pool 0x7a6=0x3b0; 100 x 8-byte records at 0xffffd4e0); on pending record dispatches on first byte: 'z' with second byte & 0xf8 (pool 0x7a2=0xf8) -> handlers 0x806/0x4c/0x64/0x7c0/0x7c/0x8a/0xc0 (pools 0x7a8-0x7b6), 0xff/0xc8 -> 0xd8; services WDT via jsr 0x31c (pool 0x7be=0x31c)."),
    ("00009ea2", "shutdown_wait_key_pin_then_halt", "high",
     "Key-off wait/halt: SR = (SR & 0xff0f) | 0xf0 (pool 0x9f1c=0xff0f); ref_setSR_PARAM 0xe0 (pool 0x9f18=0xe0, jsr pool 0x9f28=0x2054); ref_setRegister_REG_BIT_VAL PFDR_W 0xfffff74e (pool 0x9f1a=0xf74e) mask 8 val 0 (r5=8 r6=0, jsr pool 0x9f2c=0x4bbc); loop 0x9ed0: busy-wait jsr 0x239c with r4=0x1388 (pools 0x9f40=0x239c, 0x9f1e=0x1388), WDT pulse jsr 0xa850 (pool 0x9f3c=0xa850), r0 = PFDR_W & 1 (r14=1) at 0x9ed8-0x9ee2; loops while bit0 == 0, bsr 0x9efe (masked halt) once bit0 == 1. Called from 0x252c2 via pool 0x253a8=0x9ea2."),
    ("00009e68", "recovery_finalize_set_pf3_halt", "high",
     "Finalize path called from the 0xd204 recovery entry (pool 0xd2d0=0x9e68): jsr 0x4c80 (pool 0x9f20=0x4c80), jsr 0xd518 (pool 0x9f24=0xd518, RAM swap + SBL semaphore mark), bsr 0x9f0c r4=0; ref_setSR_PARAM 0xe0 (pool 0x9f18=0xe0, jsr pool 0x9f28=0x2054); PFDR_W 0xfffff74e bit 3 = 1 (pool 0x9f1a=0xf74e, r5=8 r6=1, jsr pool 0x9f2c=0x4bbc); jsr 0x2064 (pool 0x9f30), jsr 0x4cf0 (pool 0x9f34), jsr 0x3ad8 r4=0 (pool 0x9f38); halt at 0x9e9e."),
    ("0000d21e", "main_task_software_reset_check", "medium",
     "Was ref_main__ (referenced from the task area via pool 0x655c near 0x64f6): bsr 0xd262 (pools 0xd2dc=0xd934, 0xd2e0=0x9890) and 0xd28e (pools 0xd2e4=0xffffa3e8, 0xd2bc=0x450); if result != -1 and byte @0xffff9f8c (pool 0xd2d4=0xffff9f8c) != 1: SR = (SR & 0xff0f) | 0xf0 (pool 0xd2b8=0xff0f), jsr 0x4e0 (pool 0xd2d8=0x4e0) with r4=1 r5=result - software reset via the param!=0 branch of 0x4e0, which stores the cause byte at 0xffffdfa8; halt 0xd258."),
    ("00006796", "vehicle_inputs_sticky_update", "high",
     "Sticky update of the input latches: 0xffff9ec8 = (prev 0xffff9ed8 | PFDR_W) & 0xffff9ec8 | prev & PFDR_W (pools 0x684a=0xf74e, 0x6850=0xffff9ed8, 0x6854=0xffff9ec8); same for PHDR_W 0xfffff72c (pool 0x684c=0xf72c) -> 0xffff9eca (pools 0x685c/0x6858); three expander channels via 0x70ac -> 0xffff9ecc/9ecd/9ece."),
    ("000070ac", "sci0_gpio_expander_read", "high",
     "Was ref_getFromGPIO_: external GPIO-expander read over SCI0 - reconfigures SCI0 (regs 0xfffff002/0xfffff000/0xfffff006/0xfffff001, pools 0x7160/0x7164/0x7166/0x7168), selects channel via PHDR_W 0xfffff72c (pool 0x716c=0xf72c) masks 0x4000/0x8000 (pools 0x716a=0x4000, 0x7180=0x8000) through 0x4bbc (pool 0x7170), sends 0xff (pool 0x716e=0xff) via 0x71ea (SCI0 exchange, toggles PGDR_W 0xfffff764 bit 1), returns the received byte; callers 0x6744/0x6796 store it to 0xffff9ecc/9ecd/9ede."),
    ("0001a5d8", "key_on_latch_from_pfdr_bit0", "high",
     "0xffffaa69 = (vehicle latch 0xffff9ec8 & 1) != 0: mov.l pool 0x1a610=0xffff9ec8, store pool 0x1a60c=0xffffaa69; called from 0x19640 and 0x19950. PFDR bit0 is the key-on (IG1) input sampled by 0x6744 vehicle_inputs_poll_pfdr_phdr."),
    ("0001a600", "key_on_flag_update", "high",
     "Copies 0xffffaa69 (pool 0x1a60c) to engine_running_flag 0xffffaa68 (pool 0x1a60a=0xaa68); called from 0x19640/0x19950. 0xffffaa68 gates the CAN RX/TX mains (0xdbf6/0xdb58), CAN error recovery 0xdcc0, the fan after-run clause in 0x2f51a and the key-off state machine 0x252c2."),
    ("000454c0", "key_input_pf15_sample", "high",
     "Reads PFDR_W (pool 0x45508=0xf74e), stores 0xffffcbd1 = (PFDR & 0x8000) == 0 (mask pool 0x4550c=0x8000, cell pool 0x45510=0xffffcbd1); called from 0x19640. PF15 is a second key-related input pin."),
    ("000454d2", "key_input_pf15_edge_latch", "high",
     "Edge latch on PF15: reads PFDR_W & 0x8000 (pools 0x45508=0xf74e, 0x4550c=0x8000); on pin 1->0 sets 0xffffcbd0 = 1 (pool 0x4550a=0xcbd0), on 0->1 clears it; keeps 0xffffcbd1 (pool 0x45510) as previous sample; called from 0x199d4; consumed by 0x48d38 key_voltage_timer_update."),
    ("00048d38", "key_voltage_timer_update", "medium",
     "0xffffccca held at 0x19 while (battery voltage 0xffffb590 < 6.0 and 0xffffcbd0 == 1), else counts down to 0; read by 0x48d70 into 0xffffccc4. Candidate START/crank correlation (PF15 active + low voltage); terminal routing unresolved."),
    ("00048d70", "voltage_key_sanity_flags", "medium",
     "Sets 0xffffccc5/0xffffccc2 = (voltage 0xffffb590 >= 6.0), 0xffffccc4 = (ccc2 && 0xffffccca == 0), 0xffffccc3 = (0xffffaa68 && 0xffffccc1 && stored 0xffffb4ed == 1); voltage/key sanity inputs to the shutdown decision."),
    ("00048cc0", "shutdown_allowed_flag", "high",
     "Computes 0xffffccc1 (pool 0x48da2): = 1 only when (engine flag 0xffffaa68 == 1 (pool 0x48d92) or (0xffffb4ee == 1 (pool 0x48d94) && 0xffffccb6 < 0x271 (pool 0x48d96))) and 0xffffcca0 == 0 (pool 0x48d98) and not 0xffffad60/0xffffad61 (pools 0x48d9a/0x48d9c) and E2-shadow 0xffff80a2 != 1 (pool 0x48d9e, read via 0x3db54 pool 0x48db0) and 0xffffb51a == 0 (pool 0x48da0); else 0. Drives the PD11 relay-hold output via 0x251d0."),
    ("000487d6", "engine_stop_conditions_eval", "high",
     "Engine-stop/shutdown condition evaluator (called from the slow-task step 0x22f86): snapshots rpm 0xffffb548 (pool 0x48884), battery 0xffffb590 (0x48886), coolant 0xffffa98c (0x48888); rpm < 200/300 -> 0xffffccec, voltage < 5.8/6.0 -> 0xffffcced, coolant < 98/100 -> 0xffffccee/0xffffccef; reads E2-shadow flags 0xffff873c/0xffff809e/0xffff809c/0xffff8104/0xffff80a0/0xffff80a2/0xffff8764 via 0x3db54/0x3dc70; sets 0xffffccbc-bf/ccc0/ccc9 from engine flag 0xffffaa68 (pool 0x4888e), injectors-off 0xffffa42c, counters 0xffffccb4/ccb6/ccba and stored flag 0xffffb4ed."),
    ("000251d0", "relay_hold_output_pd11", "high",
     "Relay-hold output: 0xffffb574 = (0xffffccc1 != 1) (pools 0x25278=0xffffb574, 0x2526c=0xccc1); under SR mask 0xe0 (pool 0x2526e=0xe0, jsr 0x2054 pool 0x2527c=0x2054) drives PDDR_W 0xfffff746 (pool 0x25272=0xf746) bit 0x800 (pool 0x25270=0x800) to (b574 == 1) via 0x4bbc (pool 0x25280=0x4bbc); PD11 high while shutdown is not allowed. Callers 0x22f54 (init fan-out 0x1102a) and 0x22f86 (slow task). Chip-pin -> connector-terminal routing is board-level unresolved (D2): candidates main relay control 4E / DBW relay control 4C per pinout v3."),
    ("000252c2", "key_off_shutdown_state_machine", "high",
     "Key-off state machine (called from 0x253e8, itself from slow task 0x11534): state in 0xffffb57a (pool 0x25380); engine flag 0xffffaa68 (pool 0x25378) == 1 && state 0 -> arm: 0xffffdf99 = 0x5a (pool 0x2537a=0xdf99), 0xffffb580 = 0, 0xffffb579 = 1 (pool 0x25374); engine stopped && state 0 -> state 1, 0xffffb578 = 1 (pool 0x2537c); counting: 0xffffb57c (u32, pool 0x2539c) ++ saturating at -1; state 2 when b57c >= u32 @ROM 0x74940 (pool 0x253a4=0x74940; ROM word = 0x36ee8) or when b57c >= 0x19 and 0xffffb582 (pool 0x2538c) <= 0xffffb583 (pool 0x25390): then state = 2, E2-shadow 0xffff8104 = 1 via 0x3dc70 (pools 0x25376=0x8104, 0x25384=0x3dc70), 0xffffb579 = 0, 0xffffdf99 = 0, jmp 0x9ea2 (pool 0x253a8=0x9ea2)."),
    ("000253e8", "key_off_state_machine_step", "high",
     "Interrupt-masked step wrapper: ref_setSR_PARAM 0xe0 (pool 0x2540e=0xe0, jsr pool 0x25428=0x2054), jsr 0x252c2 (pool 0x2542c=0x252c2), restore via 0x2064 (pool 0x25430); called from slow task 0x11534."),
    ("00025290", "key_off_state_init", "high",
     "State init: 0xffffb57a = 0 (pool 0x25380=0xffffb57a), 0xffffb579 = 1 (pool 0x25374=0xb579); reached from init fan-out 0x1102a via 0x253ac."),
    ("0002529e", "shutdown_e2_flag_clear", "medium",
     "Clears E2-shadow 0xffff8104 = 0 via 0x3dc70 (pools 0x25376=0x8104, 0x25384=0x3dc70); reached from 0x113b8 <- 0x6366 <- 0x9f52 (boot path)."),
    ("000252ae", "key_off_early_counter_a", "medium",
     "0xffffb582 += 1 (pool 0x2538c=0xffffb582); called from 0x253b8; compared against 0xffffb583 in the early shutdown condition of 0x252c2."),
    ("000252b8", "key_off_early_counter_b", "medium",
     "0xffffb583 += 1 (pool 0x25390=0xffffb583); called from 0x253d0."),
    ("000195cc", "key_on_time_counter_update", "high",
     "Was ref_calculateKeyOnTime: if engine flag 0xffffaa68 == 1 (pool 0x1961c=0xaa68) then 0xffffa9e0 = saturate(0xffffa9e0 + 1) via 0x2460 (pools 0x1961a=0xa9e0, 0x19620=0x2460), else 0; called from 0x199d4."),
    ("000195f4", "key_off_time_counter_update", "high",
     "Was ref_calculateKeyOffTime: 0xffffa9e2 saturating ++ while 0xffffaa68 == 0 (pools 0x1961e=0xa9e2, 0x1961c=0xaa68, 0x19620=0x2460); called from 0x199d4."),
    ("0000dbf6", "can_rx_main_key_gated", "high",
     "Was ref_CANRX_Main: processes CAN IDs 0x212 (0x2b29c, pool 0xdc9c), 0x216 (0x28dc0, 0xdca0), 0x231 (AT only, 0x29074, 0xdca4), 0x430 (0x32d24, 0xdca8), 0x4B0 (0x2aff0, 0xdac), 0x4B1 (0x4bd48, 0xdb0), 0x4C0 (0x2b958, 0xdb4), 0x47 (0x3811c, 0xdb8) only while (0xffffaa68 == 1 && 0xffffb578 != 1 && 0xffffa410 == 0) (pools 0xdc5c=0xaa68, 0xdc5e=0xb578, 0xdc68=0xffffa410); always jsr 0x34ae2 (pool 0xdcbc). Key-off stops all non-diag CAN RX processing."),
    ("0000db58", "can_tx_main_key_gated", "high",
     "Was ref_CANTX_Main: packs TX IDs 0x41/0x201/0x251/0x231/0x240/0x250/0x420/0x620/0x630/0x650 (pools 0xdc70-0xdc98) only while error poll 0xffffa40f < 100 (pool 0xdc64), latch 0xffffa40a == 0 (0xdc5a), setup error 0xffffa410 == 0 (0xdc68), comm error 0xffffa411 == 0 (0xdc6c), engine flag 0xffffaa68 == 1 (0xdc5c) && 0xffffb578 != 1 (0xdc5e); clears 0xffffc1d1 (pool 0xdc62)."),
    ("0000dcc0", "can_error_recovery_key_gated", "high",
     "Inherited name ref_checkCANsomethingKeyOnBased corrected: CAN error poll/recovery runs only while 0xffffaa68 == 1 && 0xffffb578 != 1 (pools 0xddbc=0xaa68, 0xddbe=0xb578); increments 0xffffa40f (pool 0xddc8) while ref_getHCANSomething 0x9b08 (pool 0xddcc) reports GSR error warning, saturating at 0xff (pool 0xddc0); latches 0xffffa40a (pool 0xddc2) above 100; re-runs CAN setup while retry counter 0xffffa40c (pool 0xddd0) == 0, full reset 0xdade at >= 1000 (pool 0xddc6=0x3e8, saturating add 0x2460 pool 0xddd8); sets 0xffffa409 (pool 0xddc4)."),
    ("0000e274", "engine_running_from_rpm", "high",
     "Was ref_calculateEngineRunning: engine_running 0xffffa428 = 1 when rpm 0xffffb548 >= 500.0 (pools 0xe29c=0xb548, 0xe29e=0xa428, float consts via pools 0xe2a0/0xe2a4 -> 0x6c190/0x6c194), cleared below 250.0; distinct from the key-on flag 0xffffaa68 (PFDR bit0 via 0xffff9ec8)."),
    ("000005b0", "wdt_overflow_reset_check", "high",
     "Was ref_checkWatchdogTimer_OVRCOUNT: loops param times - stores 0x624() result into reset cause 0xffffdfa8 (pool 0x6b6=0xdfa8), jsr 0x364 (pool 0x6ba=0x364), remaining 0x3e0 (0x6bc), ring 0x3b0 (0x6be); returns 0 when a record was processed; otherwise counts WDT TCSR 0xffffec10 (pool 0x6b8=0xec10) OVF bit 0x80, servicing via 0x31c (pool 0x6c0). Called from 0x4e0 with r4=7: any overflow => warm reset."),
    ("00000572", "wdt_keyed_reset", "high",
     "Was ref_resetWatchdog_: RSTCSR_W 0xffffec12 = 0x5a1f (pools 0x596=0x5a1f, 0x598=0xec12), then TCSR 0xffffec10 = 0x5a00 and keyed write 0xa53c (pools 0x59a=0xec10, 0x5ac=0xa53c) - SH keyed WDT/RSTCSR write idiom (0x5a/0xa5 upper bytes)."),
    ("0000a850", "external_wdt_heartbeat_pulse", "high",
     "External watchdog heartbeat on PB15: under SR mask 0xe0 (pool 0xa88a=0xe0, jsr 0x2054 pool 0xa894=0x2054) sets PBDR_W 0xfffff738 (pool 0xa88e=0xf738) |= 0x8000 (pool 0xa89c=0x8000), busy-waits 0x96*8 via 0x239c (pools 0xa890=0x96, 0xa8a0=0x239c), then PBDR &= 0x7fff (pool 0xa88c=0x7fff). Called from the 0x9ea2 shutdown wait loop, 0x60c8 and 0xd518."),
    ("0000d518", "shutdown_ram_swap_semaphore_mark", "high",
     "Shutdown RAM handling (called from 0x9e68 via pool 0x9f24=0xd518): checksum 0xd648 (pools 0xd620=0xd748, 0xd61c=0xd744) over 0xffff9300..0xffffdffb; if OK: 0x4c70 (pool 0xd628) writes u32 0x3c to the SBL semaphore cell 0xffffdff8, pulses WDT 0xa850 (pool 0xd624), swaps RAM 0xffff6000-0xffff7fff with the shadow at 0xffff9300 (pools 0xd62c=0xd734, 0xd630=0xd738), re-checksums, 0x4c76 (pool 0xd634), 0xd5ac; sets 0xffffa3f0 = checksum-ok (pool 0xd638=0xffffa3f0)."),
]


RAM = [
    # address, alias, type, reader, evidence
    ("ffffcbd0", "key_input_pf15_edge_latch", "uint8", "000454d2",
     "Edge latch of PFDR_W 0xfffff74e bit 0x8000: set 1 on pin 1->0, cleared on 0->1 by 0x454d2 (pools 0x4550a=0xcbd0, 0x45508=0xf74e, 0x4550c=0x8000); read by 0x48d38."),
    ("ffffcbd1", "key_input_pf15_prev", "uint8", "000454c0",
     "Previous PF15 sample: (PFDR_W & 0x8000) == 0 stored by 0x454c0 (pool 0x45510=0xffffcbd1)."),
    ("ffffb57a", "key_off_state", "uint8", "000252c2",
     "Key-off state machine state: 0 = armed/key-on, 1 = engine stopped (counting), 2 = shutdown (0x252c2, pool 0x25380=0xffffb57a)."),
    ("ffffb578", "engine_stopped_latch", "uint8", "000252c2",
     "Set 1 on the engine-stop transition by 0x252c2 (pool 0x2537c=0xb578); gates CAN RX/TX mains 0xdbf6/0xdb58 and CAN error recovery 0xdcc0."),
    ("ffffb579", "key_off_armed_flag", "uint8", "000252c2",
     "Armed flag of the key-off sequence (pool 0x25374=0xb579; init 1 in 0x25290)."),
    ("ffffb57c", "key_off_timer", "uint32", "000252c2",
     "Saturating u32 key-off timer (pool 0x2539c=0xffffb57c); shutdown when >= u32 @ROM 0x74940 = 0x36ee8 (pool 0x253a4=0x74940) or >= 0x19 with 0xffffb582 <= 0xffffb583."),
    ("ffffb582", "key_off_early_counter_a", "uint8", "000252ae",
     "Incremented by 0x252ae (pool 0x2538c=0xffffb582); compared with 0xffffb583 in the early shutdown condition of 0x252c2."),
    ("ffffb583", "key_off_early_counter_b", "uint8", "000252b8",
     "Incremented by 0x252b8 (pool 0x25390=0xffffb583)."),
    ("ffffb574", "relay_hold_flag", "uint8", "000251d0",
     "= (0xffffccc1 != 1); drives PDDR_W 0xfffff746 bit 0x800 (PD11 relay-hold output) via 0x251d0 (pool 0x25278=0xffffb574)."),
    ("ffffccc1", "shutdown_allowed", "uint8", "00048cc0",
     "Shutdown-allowed flag computed by 0x48cc0 from engine flag 0xffffaa68, 0xffffb4ee, 0xffffccb6 < 0x271, 0xffffcca0, 0xffffad60/ad61, E2-shadow 0xffff80a2 and 0xffffb51a (pool 0x48da2=0xccc1)."),
    ("ffff8104", "shutdown_e2_shadow_flag", "uint8", "0002529e",
     "E2RAM-shadow shutdown flag: written 0/1 by 0x2529e/0x252c2 via 0x3dc70 (pool 0x25376=0x8104), read back by 0x487d6 as the persistent shutdown marker."),
    ("ffffa9e0", "key_on_time_counter", "uint16", "000195cc",
     "Saturating u16 key-on time, ++ while 0xffffaa68 == 1 (0x195cc; pools 0x1961a=0xa9e0, 0x1961c=0xaa68, 0x19620=0x2460)."),
    ("ffffa9e2", "key_off_time_counter", "uint16", "000195f4",
     "Saturating u16 key-off time, ++ while 0xffffaa68 == 0 (0x195f4; pools 0x1961e=0xa9e2, 0x1961c=0xaa68, 0x19620=0x2460)."),
    ("ffffcfb8", "key_on_latch_cfb8", "uint8", "0004e7aa",
     "= (0xffff9ec8 & 1) != 0 copied by 0x4e7aa (pool 0x4e874=0xf74e for PFDR_W 0xfffff74e)."),
    ("ffffcfb9", "key_on_latch_cfb9", "uint8", "0004e7da",
     "= (0xffff9ec8 & 1) != 0 copied by 0x4e7da; callers 0x38a18/0x390fc."),
    ("ffffdf99", "key_off_marker_byte", "uint8", "000252c2",
     "Set to 0x5a when the key-off sequence arms, 0 on the shutdown transition (0x252c2, pool 0x2537a=0xdf99)."),
    ("ffffccca", "key_voltage_timer", "uint8", "00048d38",
     "Held at 0x19 while voltage 0xffffb590 < 6.0 and 0xffffcbd0 == 1, else counts down (0x48d38); read by 0x48d70 into 0xffffccc4."),
    ("ffffdfa8", "reset_cause", "uint8", "00000364",
     "Reset-cause selector: written by the param!=0 branch of 0x4e0 (pool 0x590=0xdfa8) and by 0x5b0; selects the 0x210 vs 0x450 dispatch in 0x364/0x338."),
    ("ffffdffc", "warm_boot_magic", "uint32", "000004e0",
     "Warm-boot magic 0x5aa5a55a, written on every reset by 0x4e0 (pool 0x5a0=0xffffdffc) and compared at 0x508 to select warm vs cold entry; top-of-RAM protected cell (range-checked in 0x87c)."),
    ("ffffaa69", "key_on_latch_aa69", "uint8", "0001a5d8",
     "= (0xffff9ec8 & 1) != 0 by 0x1a5d8 (pools 0x1a60c=0xffffaa69, 0x1a610=0xffff9ec8); copied to 0xffffaa68 by 0x1a600."),
]


LOOKUP = []

# Mid-function entry points (not function starts, so not TSV rows): recorded here only.
CODE_ENTRY_POINTS = {
    "0x00001298": {
        "alias": "warm_entry_stub",
        "evidence": "Warm entry: u32 @ROM 0x1000 = 0x1298 (loaded via pool 0x58e in 0x4e0). 6-byte stub at 0x1298 (inside the 0x1272 function body): mov.w pool 0x1348=0x1038, jsr @r3 (warm_reset_dispatcher 0x1038), mov #0,r4, bra self halt at 0x129e.",
    },
    "0x0000d204": {
        "alias": "recovery_entry_set_vbr_fpscr",
        "evidence": "Recovery entry = u32 @ROM 0x7fff8 = 0xd204 (fallback warm-entry pointer used by 0x4e0/0x1038 when the 0x1000 cell is erased): ldc r3,vbr pool 0xd2c0=0x7fc50; lds r2,fpscr pool 0xd2c4=0x40001; falls into 0xd20c manual_reset_finalize; halt 0xd21a.",
    },
}


def read_rows(path, fields):
    """Return list of dicts; rows keep their raw line in '_raw' for byte-exact rewrite."""
    if not path.exists():
        return []
    with path.open(newline='', encoding='utf-8', errors='surrogateescape') as f:
        text = f.read()
    lines = text.split('\n')
    rows = []
    rdr = csv.DictReader(lines, delimiter='\t')
    for raw, row in zip(lines[1:], rdr):
        if raw == '' and all(v in (None, '') for v in row.values()):
            continue
        row = {k: (v if v is not None else '') for k, v in row.items()}
        row['_raw'] = raw
        rows.append(row)
    return rows


def write_rows(path, fields, rows):
    """Rewrite preserving original lines byte-exactly; only appended rows are new."""
    with path.open('w', newline='', encoding='utf-8', errors='surrogateescape') as f:
        f.write('\t'.join(fields) + '\n')
        for r in rows:
            raw = r.get('_raw')
            if raw is not None:
                f.write(raw + '\n')
            else:
                f.write('\t'.join(r.get(k, '') for k in fields) + '\n')


def main():
    index = {r['address'] for r in read_rows(b / 'decompiled/function_index.tsv',
                                             ['address', 'name', 'body_bytes', 'status', 'file'])}
    for a, alias, conf, ev in FUNCTIONS:
        assert a in index, 'function %s not in index' % a
    for a, alias, typ, reader, ev in RAM:
        assert list((b / 'decompiled/functions').glob(reader + '_*')), 'reader %s has no function file' % reader

    added_fn = added_ram = added_lut = 0
    conflicts = []

    p = b / 'source_review/accepted_function_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'confidence', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, conf, ev in FUNCTIONS:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('function %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'confidence': conf, 'evidence': ev, '_raw': None})
        added_fn += 1
    if not conflicts and added_fn:
        write_rows(p, ['address', 'alias', 'confidence', 'evidence'], rows)

    p = b / 'source_review/accepted_ram_aliases.tsv'
    rows = read_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'])
    existing = {r['address']: r for r in rows}
    for a, alias, typ, reader, ev in RAM:
        if a in existing:
            if existing[a]['alias'] != alias:
                conflicts.append('ram %s: have %s, want %s' % (a, existing[a]['alias'], alias))
            continue
        rows.append({'address': a, 'alias': alias, 'type': typ, 'reader': reader, 'evidence': ev, '_raw': None})
        added_ram += 1
    if not conflicts and added_ram:
        write_rows(p, ['address', 'alias', 'type', 'reader', 'evidence'], rows)

    p = b / 'source_review/accepted_lookup_aliases.tsv'
    fields = ['original', 'alias', 'basis', 'evidence']
    rows = read_rows(p, fields)
    pairs = {(r['original'], r['alias']) for r in rows}
    for orig, alias, ev in LOOKUP:
        if (orig, alias) in pairs:
            continue
        rows.append({'original': orig, 'alias': alias, 'basis': BASIS, 'evidence': ev, '_raw': None})
        added_lut += 1
    if not conflicts and added_lut:
        write_rows(p, fields, rows)

    if conflicts:
        for c in conflicts:
            print('CONFLICT:', c, file=sys.stderr)
        raise SystemExit('alias conflicts; resolve before rerunning')

    vp = b / 'source_review/validation.json'
    val = json.loads(vp.read_text()) if vp.exists() else {
        'date': '', 'function_annotations': 0, 'ram_aliases': 0,
        'ghidra_database_updated': False, 'sources': []}
    val['function_annotations'] = len(read_rows(b / 'source_review/accepted_function_aliases.tsv',
                                                ['address', 'alias', 'confidence', 'evidence']))
    val['ram_aliases'] = len(read_rows(b / 'source_review/accepted_ram_aliases.tsv',
                                       ['address', 'alias', 'type', 'reader', 'evidence']))
    if BASIS not in val.get('sources', []):
        val.setdefault('sources', []).append(BASIS)
    vp.write_text(json.dumps(val, indent=2) + '\n', encoding='utf-8', errors='surrogateescape')

    record = {
        'date': '',
        'pass': 'ignition_power_state_labeling',
        'basis': BASIS,
        'source': 'Static analysis of reverse-engineered/decompiled/60E15120_N3J1E + reverse-engineered/disassembly/60E15120_N3J1E/firmware_disassembly.asm + raw ROM bytes (submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin, SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1). Report: ignition_power_state_report.md.',
        'function_aliases': {a: {'alias': al, 'confidence': c, 'evidence': ev} for a, al, c, ev in FUNCTIONS},
        'ram_aliases': {a: {'alias': al, 'type': t, 'reader': r, 'evidence': ev} for a, al, t, r, ev in RAM},
        'code_entry_points': CODE_ENTRY_POINTS,
        'rom_unchanged': True,
        'ghidra_database_updated': False,
        'pin_sources': 'PFDR_W/PDDR_W/PBDR_W/PHDR_W/PGDR_W/PJDR_W addresses from symbols.tsv; port-letter -> package-pin from Sh7055h.pdf (SH7055F HW manual ADE 602-155B); connector terminals 4Q (IG1), 4E (main relay control), 4C/5H (DBW relay), 5AC/5AF (main-relay supply), 5J (KAM), 4S/4V (CAN) from hardware pinout v3 (mazda-rx-8-pcm-pinout-series-1.md); chip-pin -> terminal routing is board-level unresolved (D2)',
    }
    (b / 'metadata/ignition_power_state_labels.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')

    print(json.dumps({
        'function_rows_added': added_fn,
        'ram_rows_added': added_ram,
        'lookup_rows_added': added_lut,
        'function_rows_total': val['function_annotations'],
        'ram_rows_total': val['ram_aliases'],
    }, indent=2))


if __name__ == '__main__':
    main()
