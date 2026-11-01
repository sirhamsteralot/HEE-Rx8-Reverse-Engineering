/* ROM address: 0x00064378; body bytes: 72; decompiled */

void FUN_00064378(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  
  uVar4 = DAT_ffff8d74;
  uVar2 = (uint)DAT_ffff8d74;
  cVar6 = (&DAT_ffff8962)[uVar2 * 0x34];
  iVar5 = 0;
  do {
    pcVar1 = (char *)(param_1 + iVar5);
    iVar3 = iVar5 + uVar2 * 0x34;
    iVar5 = iVar5 + 1;
    cVar6 = cVar6 + ((&DAT_ffff893a)[iVar3] - *pcVar1);
    (&DAT_ffff893a)[iVar3] = *pcVar1;
  } while (iVar5 < 0x28);
  (&DAT_ffff8962)[(uint)uVar4 * 0x34] = cVar6;
  return;
}


