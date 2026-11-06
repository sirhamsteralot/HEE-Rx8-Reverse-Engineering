/* [ADDITIONAL SOURCE REVIEW]
 * alternator_control_main_batch [high]: Mask-0x10 batch called from 0x114d0 (callgraph 0x114d0 -> 0x267c6). Pool words 0x26888-0x268b0 read from ROM: 0x26888=0x3920 sh_raise_interrupt_mask_return_previous (r4=0x10), 0x2688c=0x25a22, 0x26890=0x25a3c, 0x26894=0x25a68, 0x26898=0x25b36, 0x2689c=0x25ba4, 0x268a0=0x2616e, 0x268a4=0x26624, 0x268a8=0x25710, 0x268ac=0x545bc, tail jmp via 0x268b0=0x3934 ref_setSR. Inherited ref_alternatorControlMain confirmed: speed/voltage/battery-temp/error/duty/PWM-output calc + P2502 DTC raise.
 */
/* ROM address: 0x000267c6; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000270ea (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void alternator_control_main_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  candidate_charging_ok_latch();
  candidate_overvoltage_flags();
  alternator_speed_calc();
  FUN_00025b36();
  candidate_battery_temp_model();
  candidate_alternator_voltage_error_calc();
  candidate_alternator_duty_calc();
  alternator_field_pwm_output();
  candidate_charging_dtc_raise_p2502();
  ref_setSR(uVar1);
  return;
}


