/* ROM address: 0x00020f88; body bytes: 24; decompiled */

void FUN_00020f88(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getCrankEnrichment_();
  ref_setSR(uVar1);
  return;
}


