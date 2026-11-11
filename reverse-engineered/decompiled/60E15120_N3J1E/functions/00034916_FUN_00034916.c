/* [ADDITIONAL SOURCE REVIEW]
 * vfad_control_task_wrapper [high]: Mask-0x10 wrapper calling vfad_solenoid_control; called from 0x11744. | promoted to high (data/labels/60E15120_N3J1E/intake_labels.json/function_aliases)
 */
/* ROM address: 0x00034916; body bytes: 24; decompiled */

void vfad_control_task_wrapper(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  vfad_solenoid_control();
  ref_setSR(uVar1);
  return;
}


