/* ROM address: 0x00066baa; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006549a (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066baa(uint param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = 1;
  do {
    bVar2 = FUN_000604c2(iVar4);
    iVar1 = iVar4 + (param_1 & 0xffff) * 2;
    iVar4 = iVar4 + 1;
    if (((&DAT_0007eb8c)[iVar1] & bVar2) != 0) {
      uVar3 = 0;
    }
  } while (iVar4 < 2);
  return uVar3;
}


