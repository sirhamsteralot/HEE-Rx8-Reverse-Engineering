/* [ADDITIONAL SOURCE REVIEW]
 * dsc_can_arbitration_batch [high]: 15-call batch (14 jsr + 1 tail jmp; 13 signal callees + mask/SR helpers) under interrupt mask 0x10, called from task[10] body 0x11744 (callgraph 0x11744 -> 0x2a2ae). Pool words in classified pool 0x2a3e0-0x2a4f4 read from ROM: 0x2a448=0x3920 sh_raise_interrupt_mask_return_previous, 0x2a454=0x3934 ref_setSR (tail), 0x2a468=0x2b314, 0x2a46c=0x2b3b8, 0x2a470=0x2b496, 0x2a474=0x2b6a4, 0x2a478=0x2b6c2, 0x2a47c=0x2b754, 0x2a480=0x2b788, 0x2a484=0x2b7a6, 0x2a488=0x2b7c4, 0x2a48c=0x2b046, 0x2a490=0x2b156, 0x2a494=0x2b17e, 0x2a498=0x2b1aa. Inherited ref_updateDSCRelatedCANStuff__ confirmed: CAN 0x212 signal validity, max-torque-allowed, DSC mode bits, vehicle-moving and wheelspeed validity.
 */
/* ROM address: 0x0002a2ae; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002aa02 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void dsc_can_arbitration_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  can212_rx_signal_validity();
  engine_max_torque_allowed_calc();
  candidate_dsc_desired_torque_calc();
  candidate_dsc_mode_bit08_check();
  candidate_dsc_mode_bit80_check();
  candidate_dsc_mode_bit40_check();
  candidate_dsc_mode_bit20_check();
  candidate_dsc_mode_bit10_check();
  candidate_can212_timeout_flag();
  candidate_wheelspeed_rear_avg_calc();
  vehicle_moving_calc();
  wheelspeed_lr_validity();
  wheelspeed_rr_validity();
  ref_setSR(uVar1);
  return;
}


