/* [ADDITIONAL SOURCE REVIEW]
 * ssv_control_task_wrapper [medium]: Mask-0x10 wrapper calling ssv_solenoid_control (0x2178c); called from 0x11744 (task 0x64f6 chain).
 */
/* ROM address: 0x00021766; body bytes: 24; decompiled */

void candidate_ssv_control_task_wrapper(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ssv_solenoid_control();
  ref_setSR(uVar1);
  return;
}


