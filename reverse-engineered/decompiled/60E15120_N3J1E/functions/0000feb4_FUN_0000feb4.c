/* ROM address: 0x0000feb4; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000feb8 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0000feb4(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00010170((int)*param_1);
  iVar2 = FUN_000101ac((int)*param_1);
  iVar1 = ref_LongFunc(iVar2 + *(int *)(param_1 + 8) + iVar1,crank_period_accumulator_ffff9f88);
  return iVar1 * 0xb4 + *(int *)(param_1 + 0xc);
}


