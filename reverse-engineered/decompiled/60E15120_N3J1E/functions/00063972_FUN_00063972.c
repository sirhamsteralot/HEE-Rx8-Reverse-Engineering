/* ROM address: 0x00063972; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062262 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063972(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + ((&DAT_ffff890e)[iVar1] - param_1);
  (&DAT_ffff890e)[iVar1] = param_1;
  return;
}


