/* ROM address: 0x00063bd4; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000624c4 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063bd4(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  
  uVar4 = DAT_ffff8d4c._0_2_;
  uVar2 = (uint)DAT_ffff8d4c._0_2_;
  cVar6 = (&DAT_ffff893a)[uVar2 * 0x34];
  iVar5 = 0;
  do {
    pcVar1 = (char *)(param_1 + iVar5);
    iVar3 = iVar5 + uVar2 * 0x34;
    iVar5 = iVar5 + 1;
    cVar6 = cVar6 + ((&DAT_ffff8912)[iVar3] - *pcVar1);
    (&DAT_ffff8912)[iVar3] = *pcVar1;
  } while (iVar5 < 0x28);
  (&DAT_ffff893a)[(uint)uVar4 * 0x34] = cVar6;
  return;
}


