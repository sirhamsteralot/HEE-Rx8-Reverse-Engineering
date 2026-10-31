/* ROM address: 0x00019da2; body bytes: 48; decompiled */

void FUN_00019da2(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getSpeedLimitCal_();
  ref_getAutoTransCal__();
  ref_getEngineOnTimeForOilMetering();
  ref_calculateEngineOnTime__();
  FUN_0004b668();
  ref_setSR(uVar1);
  return;
}


