/* ROM address: 0x00008ee6; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008ee6 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00008ee6(byte param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((&DAT_ffffa0dc)[(uint)param_1 * 8] != '\0') {
    if ((&DAT_ffffa0dd)[(uint)param_1 * 8] == '\0') {
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
  }
  ref_setSR(uVar1);
  return uVar2;
}


