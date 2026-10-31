/* ROM address: 0x00063ecc; body bytes: 48; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 000627bc (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063ecc(char param_1)

{
  undefined4 uVar1;
  
  _DAT_ffff8e70 = rx8_pack_u8_with_complement(((int)DAT_ffff8e74 - (int)param_1) + (int)DAT_ffff8e70);
  uVar1 = rx8_pack_u8_with_complement((int)param_1);
  _DAT_ffff8e74 = (short)uVar1;
  return uVar1;
}


