/* ROM address: 0x0003dd16; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e29e (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_validateAddressCopy_8bit_ADDRESS__(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  uVar3 = sh_raise_interrupt_mask_return_previous(0x10);
  bVar1 = *param_1;
  bVar2 = param_1[1];
  if (bVar1 != (byte)~bVar2) {
    FUN_0003df7c();
  }
  ref_setSR(uVar3);
  return bVar1 != (byte)~bVar2;
}


