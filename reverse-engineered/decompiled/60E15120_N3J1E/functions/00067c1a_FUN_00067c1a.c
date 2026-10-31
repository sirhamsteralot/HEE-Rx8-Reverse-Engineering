/* ROM address: 0x00067c1a; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006650a (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00067c1a(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8fa0)[uVar1 * 5] != param_1 || (DAT_ffff8fb4 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8fa4)[uVar1 * 5];
}


