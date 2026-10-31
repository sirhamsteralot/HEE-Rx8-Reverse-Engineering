/* ROM address: 0x000609fe; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f2ee (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000609fe(void)

{
  uint uVar1;
  
  uVar1 = FUN_00063998();
  if ((uVar1 & 0xff) == 0) {
    if (DAT_ffff8794._0_2_ == -1) {
      uVar1 = (int)DAT_ffff877c._0_1_ + 1;
      DAT_ffff877c = rx8_pack_u8_with_complement(uVar1);
    }
    else {
      uVar1 = FUN_00063998();
    }
  }
  return uVar1;
}


