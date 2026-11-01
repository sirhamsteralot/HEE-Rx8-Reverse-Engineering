/* ROM address: 0x0000f37c; body bytes: 212; decompiled */

void FUN_0000f37c(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = 0;
  DAT_ffffa56d = 0;
  DAT_ffffa56e = 0;
  DAT_ffffa571 = 1;
  do {
    iVar5 = iVar2 * 0x58;
    iVar6 = iVar2 * 0x58;
    (&DAT_ffffa4b4)[iVar5] = 0;
    iVar4 = 0;
    (&DAT_ffffa4b5)[iVar5] = 0;
    (&DAT_ffffa4b6)[iVar5] = 0;
    (&DAT_ffffa4b7)[iVar5] = 0;
    (&DAT_ffffa4b8)[iVar2 * 0x2c] = 0;
    (&DAT_ffffa4ba)[iVar5] = 0;
    (&DAT_ffffa4bb)[iVar5] = 0;
    (&DAT_ffffa4bc)[iVar2 * 0x16] = (&DAT_0004ea6c)[iVar2];
    (&DAT_ffffa4c0)[iVar5] = (char)iVar2;
    puVar3 = &DAT_0004ea74 + iVar2 * 3;
    iVar5 = 0;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      (&DAT_ffffa4c4)[iVar5 + iVar6] = uVar1;
      (&DAT_ffffa4b4)[iVar5 + iVar6 + 0x11] = 0;
      *(undefined4 *)(&DAT_ffffa4b4 + iVar5 + iVar6 + 0x14) = 0;
      *(undefined4 *)(&DAT_ffffa4b4 + iVar5 + iVar6 + 0x18) = 0;
      *(undefined4 *)(&DAT_ffffa4b4 + iVar5 + iVar6 + 0x1c) = 0x1680000;
      *(undefined4 *)(&DAT_ffffa4b4 + iVar5 + iVar6 + 0x20) = 0x1680000;
      (&DAT_ffffa4b4)[iVar5 + iVar6 + 0x24] = 0;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x18;
    } while (iVar4 < 3);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  FUN_00010208();
  DAT_ffffa564 = 0;
  DAT_ffffa568 = 0;
  DAT_ffffa56c = 0;
  return;
}


