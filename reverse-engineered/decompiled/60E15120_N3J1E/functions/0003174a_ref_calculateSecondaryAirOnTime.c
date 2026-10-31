/* [ADDITIONAL SOURCE REVIEW]
 * secondary_air_on_time_task [medium]: Mask-0x10 task: 0x3194a + 0x31a24 + secondary_air_pump_control (0x316f8).
 */
/* ROM address: 0x0003174a; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00031bf2 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_secondary_air_on_time_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0003194a();
  FUN_00031a24();
  secondary_air_pump_control();
  ref_setSR(uVar1);
  return;
}


