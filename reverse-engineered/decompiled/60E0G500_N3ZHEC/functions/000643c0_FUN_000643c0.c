/* ROM address: 0x000643c0; body bytes: 124; decompiled */

int FUN_000643c0(char param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = 1;
  uVar3 = 0;
  puVar6 = param_2 + 0x28;
  while( true ) {
    if (0x14 < (int)uVar3) goto LAB_0006441a;
    if (((&DAT_ffff8936)[uVar3 * 0x34] == param_1) && (DAT_ffff8d74 != uVar3)) break;
    uVar3 = uVar3 + 1;
  }
  puVar4 = &DAT_ffff893a + uVar3 * 0x34;
  puVar2 = param_2;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (puVar2 < puVar6);
  iVar5 = 0;
LAB_0006441a:
  if (iVar5 == 1) {
    do {
      *param_2 = 0;
      param_2 = param_2 + 1;
    } while (param_2 < puVar6);
  }
  return iVar5;
}


