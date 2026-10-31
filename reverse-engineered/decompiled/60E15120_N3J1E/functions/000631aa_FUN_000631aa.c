/* ROM address: 0x000631aa; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061a9a (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000631aa(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff87b0)[uVar1 * 8] != param_1 || (DAT_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0xffff;
    }
  }
  return (int)(short)(&DAT_ffff87b2)[uVar1 * 8];
}


