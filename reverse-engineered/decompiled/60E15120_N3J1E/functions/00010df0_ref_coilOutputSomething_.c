/* ROM address: 0x00010df0; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00010e14 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_coilOutputSomething_(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(param_1 + 0xc);
  while( true ) {
    if ((char *)(param_1 + 0x2c) <= pcVar3) {
      return 1;
    }
    if (param_2 <= *(int *)(pcVar3 + 0xc)) break;
    iVar1 = FUN_00010f3e((int)*pcVar3);
    iVar2 = FUN_00010f30((int)*pcVar3);
    iVar1 = ref_LongFunc(iVar2 + iVar1,crank_period_accumulator_ffff9f88);
    if (param_2 < iVar1 * 0xb4 + *(int *)(pcVar3 + 0xc)) {
      return 0;
    }
    pcVar3 = pcVar3 + 0x10;
  }
  return 0;
}


