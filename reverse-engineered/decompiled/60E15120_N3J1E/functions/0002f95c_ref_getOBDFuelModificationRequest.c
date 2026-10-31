/* ROM address: 0x0002f95c; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fe14 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getOBDFuelModificationRequest(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002fc00();
  ref_filterFuelVolumeRequest();
  ref_calculateFuelingRequestMaxForOBDControl();
  ref_fuelingAddOBDControlMode_();
  FUN_0002f8ce();
  ref_setSR(uVar1);
  return;
}


