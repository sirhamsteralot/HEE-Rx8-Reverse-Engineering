/* ROM address: 0x0000b398; body bytes: 18; decompiled */

undefined1 * FUN_0000b398(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  ushort auStack_20 [2];
  
  DAT_ffffa222 = DAT_ffff9f08;
  DAT_ffffa224 = DAT_ffff9f0a;
  puVar4 = &DAT_ffffa220;
  puVar5 = (undefined1 *)0x0;
  auStack_20[0] = DAT_ffff9f08;
  bVar3 = 0;
  auStack_20[1] = DAT_ffff9f0a;
  puVar6 = puVar4;
  do {
    uVar8 = (uint)bVar3;
    iVar9 = uVar8 * 2;
    uVar1 = auStack_20[uVar8];
    pcVar7 = &DAT_ffffa226 + bVar3;
    if ((uVar1 < *(ushort *)(&DAT_0006fefc + iVar9)) &&
       (*(ushort *)(&DAT_0006ff00 + iVar9) <= uVar1)) {
      *pcVar7 = '\0';
      (&DAT_ffffa222)[uVar8] = auStack_20[uVar8];
    }
    else {
      if (*pcVar7 != -1) {
        *pcVar7 = *pcVar7 + '\x01';
      }
      if (2 < (byte)(&DAT_ffffa226)[bVar3]) {
        (&DAT_ffffa222)[uVar8] = auStack_20[uVar8];
      }
    }
    (&DAT_ffffa218)[bVar3] =
         (float)(&DAT_0006ff0c)[bVar3] +
         (float)(&DAT_ffffa222)[uVar8] * (float)(&DAT_0006ff04)[bVar3] * 7.6293945e-05;
    if (*(ushort *)(&DAT_0006cf72 + iVar9) < auStack_20[uVar8]) {
      (&DAT_ffffa220)[bVar3] = 1;
      puVar2 = &DAT_ffffa220;
    }
    else {
      puVar2 = puVar5;
      if (*(ushort *)((int)auStack_20 + (int)puVar5) < *(ushort *)((int)&DAT_0006cf76 + (int)puVar5)
         ) {
        *puVar6 = 2;
      }
      else {
        *puVar4 = 0;
      }
    }
    bVar3 = bVar3 + 1;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 2;
  } while (bVar3 < 2);
  return puVar2;
}


