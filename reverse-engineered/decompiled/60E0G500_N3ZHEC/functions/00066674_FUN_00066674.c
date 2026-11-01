/* ROM address: 0x00066674; body bytes: 198; decompiled */

void FUN_00066674(char param_1,undefined1 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  byte bVar4;
  int iVar5;
  undefined *puVar6;
  byte bVar7;
  undefined1 local_20 [6];
  undefined1 local_1a;
  char local_19 [5];
  
  bVar4 = 0;
  uVar2 = 0;
  while( true ) {
    local_1a = param_2;
    local_19[0] = param_1;
    bVar7 = 0;
    if (((&DAT_0005f560)[(uVar2 & 0xff) * 2] == -1) || (0x27 < bVar4)) goto LAB_000666f2;
    iVar5 = (uVar2 & 0xff) * 2;
    bVar7 = (&DAT_0005f561)[iVar5];
    if ((&DAT_0005f560)[iVar5] == param_1) break;
    bVar4 = bVar4 + bVar7;
    uVar2 = uVar2 + 1;
  }
  iVar5 = 0;
  puVar6 = &DAT_ffffd856 + bVar4;
  puVar3 = local_20;
  if (bVar7 != 0) {
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    } while (iVar5 < (int)(uint)bVar7);
  }
LAB_000666f2:
  if (bVar7 != 0) {
    FUN_000688c8(2,local_19,1);
    FUN_000688c8(2,&local_1a,1);
    DAT_ffffd854 = DAT_ffffd854 + 2;
    FUN_000688c8(2,local_20);
    DAT_ffffd854 = DAT_ffffd854 + (ushort)bVar7;
  }
  return;
}


