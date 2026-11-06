/* [ADDITIONAL SOURCE REVIEW]
 * alternator_monitor_batch [high]: Mask-0x10 batch called from task[10] body 0x11744 (callgraph 0x11744 -> 0x2680e). Pool words 0x268b4-0x268d0: 0x268b4=0x257b4, 0x268b8=0x2590a, 0x268bc=0x25aa0, 0x268c0=0x2635c, 0x268c4=0x264f0, 0x268c8=0x26760, 0x268cc=0x54590, 0x268d0=0x545a6, tail via 0x268b0=0x3934. Inherited ref_alternatorControl confirmed: DTC confirmation timers, high-load flag, warning-light flag, P2503/P2504 raises.
 */
/* ROM address: 0x0002680e; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027132 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void alternator_monitor_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  candidate_charging_dtc_timer_a();
  candidate_charging_dtc_timer_b();
  candidate_hot_engine_dtc_timer();
  candidate_low_voltage_dtc_timer();
  candidate_electrical_load_flag_calc();
  candidate_alternator_warning_light_flag();
  candidate_charging_dtc_raise_p2503();
  candidate_charging_dtc_raise_p2504();
  ref_setSR(uVar1);
  return;
}


