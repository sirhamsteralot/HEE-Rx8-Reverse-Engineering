/* ROM address: 0x000639dc; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000622cc (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000639dc(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + ((&DAT_ffff8910)[iVar1] - param_1);
  (&DAT_ffff8910)[iVar1] = param_1;
  return;
}


