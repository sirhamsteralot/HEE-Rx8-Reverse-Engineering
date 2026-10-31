/* ROM address: 0x00063998; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062288 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063998(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8908)[uVar1 * 0x1a] != param_1 || (DAT_ffff8d4c._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff890e)[uVar1 * 0x34];
}


