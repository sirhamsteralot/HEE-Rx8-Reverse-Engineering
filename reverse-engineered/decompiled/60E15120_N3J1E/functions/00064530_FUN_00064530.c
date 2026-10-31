/* ROM address: 0x00064530; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062e20 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064530(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8e7c;
  if (uVar1 == 1) {
    DAT_ffff8e78 = rx8_pack_u8_with_complement((int)DAT_ffff8d54);
    uVar1 = rx8_pack_u8_with_complement((int)DAT_ffff8d56);
    DAT_ffff8e7a = (undefined2)uVar1;
  }
  return uVar1;
}


