/* ROM address: 0x000628f4; body bytes: 36; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 000611e4 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000628f4(void)

{
  uint uVar1;
  
  FUN_000675f4();
  uVar1 = (uint)DAT_ffff87aa;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    _DAT_ffff87aa = (undefined2)uVar1;
  }
  return uVar1;
}


