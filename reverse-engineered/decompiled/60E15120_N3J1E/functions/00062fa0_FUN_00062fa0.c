/* ROM address: 0x00062fa0; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061890 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062fa0(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87ba)[iVar1] - param_1);
  (&DAT_ffff87ba)[iVar1] = param_1;
  return;
}


