/* ROM address: 0x000094f0; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000094f0 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000094f0(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  byte bVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  ushort auStack_20 [2];
  
  DAT_ffffa112 = DAT_ffff9eec;
  DAT_ffffa114 = DAT_ffff9eee;
  puVar4 = &DAT_ffffa110;
  puVar5 = (undefined1 *)0x0;
  auStack_20[0] = DAT_ffff9eec;
  auStack_20[1] = DAT_ffff9eee;
  bVar3 = 0;
  puVar6 = puVar4;
  do {
    uVar9 = (uint)bVar3;
    uVar1 = auStack_20[uVar9];
    pcVar7 = &DAT_ffffa116 + bVar3;
    if ((uVar1 < *(ushort *)(&DAT_0006eeb0 + uVar9 * 2)) &&
       ((ushort)(&DAT_0006eeb4)[uVar9] <= uVar1)) {
      *pcVar7 = '\0';
      (&DAT_ffffa112)[uVar9] = auStack_20[uVar9];
    }
    else {
      if (*pcVar7 != -1) {
        *pcVar7 = *pcVar7 + '\x01';
      }
      if (2 < (byte)(&DAT_ffffa116)[bVar3]) {
        (&DAT_ffffa112)[uVar9] = auStack_20[uVar9];
      }
    }
    iVar8 = (uint)bVar3 * 4;
    (&DAT_ffffa108)[bVar3] =
         *(float *)(&DAT_0006eec0 + iVar8) +
         (float)(&DAT_ffffa112)[uVar9] * *(float *)(&DAT_0006eeb8 + iVar8) * 7.6293945e-05;
    if (*(ushort *)(&DAT_0006eeb0 + uVar9 * 2) < auStack_20[uVar9]) {
      (&DAT_ffffa110)[bVar3] = 1;
      puVar2 = &DAT_ffffa110;
    }
    else {
      puVar2 = puVar5;
      if (*(ushort *)((int)auStack_20 + (int)puVar5) < *(ushort *)((int)&DAT_0006eeb4 + (int)puVar5)
         ) {
        *puVar4 = 2;
      }
      else {
        *puVar6 = 0;
      }
    }
    bVar3 = bVar3 + 1;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 2;
  } while (bVar3 < 2);
  return puVar2;
}


