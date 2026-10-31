/* [ADDITIONAL SOURCE REVIEW]
 * vdi_control_task_wrapper [medium]: Mask-0x10 wrapper calling vdi_solenoid_control; called from 0x11744.
 */
/* ROM address: 0x000348ea; body bytes: 24; decompiled */

void candidate_vdi_control_task_wrapper(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  vdi_solenoid_control();
  ref_setSR(uVar1);
  return;
}


