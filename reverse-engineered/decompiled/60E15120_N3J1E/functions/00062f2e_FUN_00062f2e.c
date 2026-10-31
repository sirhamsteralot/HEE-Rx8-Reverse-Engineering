/* ROM address: 0x00062f2e; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006181e (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062f2e(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87b9)[iVar1] - param_1);
  (&DAT_ffff87b9)[iVar1] = param_1;
  return;
}


