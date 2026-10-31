/* [ADDITIONAL SOURCE REVIEW]
 * knock_rough_correction_update [medium]: 0x12ed0 + 0x13034 targets + 0x13210 rough knock correction toward a6bc/a6c0 + 0x43870; reached from task[13] 0x65b2 -> 0x118d0.
 */
/* ROM address: 0x0001467c; body bytes: 42; decompiled */

void candidate_knock_rough_correction_update(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00012ed0();
  knock_rough_correction_targets();
  ref_roughKnockCorrection();
  FUN_00043870();
  ref_setSR(uVar1);
  return;
}


