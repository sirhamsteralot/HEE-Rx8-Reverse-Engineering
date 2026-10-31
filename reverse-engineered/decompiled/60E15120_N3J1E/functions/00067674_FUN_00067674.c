/* ROM address: 0x00067674; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065f64 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00067674(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8ea2)[uVar1 * 0x14];
}


