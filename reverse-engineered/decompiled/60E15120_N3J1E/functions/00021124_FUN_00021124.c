/* ROM address: 0x00021124; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021a90 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00021124(undefined4 param_1,char param_2)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_somethingFuelCutRelated(param_1,(int)param_2);
  ref_setSR(uVar1);
  return;
}


