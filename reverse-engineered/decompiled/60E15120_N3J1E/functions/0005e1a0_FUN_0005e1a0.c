/* ROM address: 0x0005e1a0; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c9ac (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e1a0(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (param_1 == '\0') {
    DAT_ffffd384 = 0x271;
    DAT_ffffd386 = 0;
    uVar1 = FUN_0005e1e8();
    return uVar1;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd386 = 2;
      uVar1 = FUN_0005e1e8();
      return uVar1;
    }
    if (param_1 != '\x03') {
      uVar1 = FUN_0005e1e8();
      return uVar1;
    }
    DAT_ffffd384 = 0;
  }
  DAT_ffffd386 = 1;
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


