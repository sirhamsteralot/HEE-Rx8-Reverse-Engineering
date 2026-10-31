/* ROM address: 0x00062df8; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000616e8 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00062df8(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff87b0)[uVar1 * 8] != param_1 || (DAT_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87b6)[uVar1 * 0x10];
}


