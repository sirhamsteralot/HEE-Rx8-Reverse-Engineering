/* ROM address: 0x00010320; body bytes: 106; decompiled */

void FUN_00010320(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = 0;
  do {
    iVar7 = 0;
    (&DAT_ffffa580)[iVar5 * 0x2c] = (char)iVar5;
    (&DAT_ffffa57c)[iVar5 * 0xb] = (&DAT_0004e33c)[iVar5];
    puVar3 = &DAT_0004e344 + iVar5 * 4;
    puVar6 = &DAT_ffffa584 + iVar5 * 0x2c;
    do {
      iVar8 = 0;
      puVar2 = puVar3;
      puVar4 = puVar6;
      do {
        puVar4 = puVar4 + 1;
        iVar8 = iVar8 + 1;
        uVar1 = *puVar2;
        puVar2 = puVar2 + 1;
        *puVar4 = uVar1;
      } while (iVar8 < 2);
      iVar7 = iVar7 + 1;
      puVar6 = puVar6 + 0x10;
      puVar3 = puVar3 + 2;
    } while (iVar7 < 2);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  FUN_00010fa8();
  return;
}


