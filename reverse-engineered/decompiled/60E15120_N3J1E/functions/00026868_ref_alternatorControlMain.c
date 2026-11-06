/* [ADDITIONAL SOURCE REVIEW]
 * alternator_pid_task [high]: Mask-0x10 wrapper calling only 0x25c6c (pool 0x268d8=0x25c6c, 0x26888=0x3920 mask, 0x268b0=0x3934 tail ref_setSR); called from task[14] body 0x11adc (charging_control_batch; its batch pool starts at 0x11ca8 with 7 entries). Inherited ref_alternatorControlMain confirmed as the voltage-target/PID task.
 */
/* ROM address: 0x00026868; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002718c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void alternator_pid_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  candidate_alternator_voltage_target_select();
  ref_setSR(uVar1);
  return;
}


