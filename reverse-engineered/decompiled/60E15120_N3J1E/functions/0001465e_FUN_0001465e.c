/* ROM address: 0x0001465e; body bytes: 30; decompiled */

void FUN_0001465e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00014100();
  ref_calcLeadingTimingIATCompensation();
  ref_setSR(uVar1);
  return;
}


