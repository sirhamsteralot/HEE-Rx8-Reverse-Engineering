/* ROM address: 0x0003dd52; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e2da (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_validateAddressCopy_16bit_ADDRESS__(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar3 = sh_raise_interrupt_mask_return_previous(0x10);
  uVar1 = *param_1;
  uVar2 = param_1[1];
  if (uVar1 != (ushort)~uVar2) {
    FUN_0003df7c();
  }
  ref_setSR(uVar3);
  return uVar1 != (ushort)~uVar2;
}


