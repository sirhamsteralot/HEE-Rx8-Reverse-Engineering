/* ROM address: 0x00010248; body bytes: 216; decompiled */

void FUN_00010248(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *local_1c;
  
  iVar6 = 0;
  DAT_ffffa5d0 = 1;
  DAT_ffffa5d2 = 0;
  DAT_ffffa5d5 = 1;
  do {
    iVar7 = iVar6 * 0x2c;
    (&DAT_ffffa578)[iVar7] = 0;
    (&DAT_ffffa579)[iVar7] = 0;
    (&DAT_ffffa57a)[iVar7] = 0;
    puVar5 = &DAT_0004e344 + iVar6 * 4;
    iVar8 = iVar6 * 0x2c;
    (&DAT_ffffa57c)[iVar6 * 0xb] = (&DAT_0004e33c)[iVar6];
    (&DAT_ffffa580)[iVar7] = (char)iVar6;
    iVar3 = 0;
    (&DAT_ffffa581)[iVar7] = 0;
    iVar7 = 0;
    puVar4 = &DAT_ffffa584 + iVar8;
    do {
      iVar1 = 0;
      puVar2 = puVar4;
      local_1c = puVar5;
      do {
        puVar2 = puVar2 + 1;
        iVar1 = iVar1 + 1;
        *puVar2 = *local_1c;
        local_1c = local_1c + 1;
      } while (iVar1 < 2);
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 0x10;
      (&DAT_ffffa584)[iVar7 + iVar8] =
           (&DAT_ffffa584 + iVar7 + iVar8)[(byte)(&DAT_ffffa581)[iVar8] + 1];
      (&DAT_ffffa578)[iVar7 + iVar8 + 0xf] = 0;
      (&DAT_ffffa578)[iVar7 + iVar8 + 0x10] = 0;
      *(undefined4 *)(&DAT_ffffa578 + iVar7 + iVar8 + 0x14) = DAT_ffffbc24;
      iVar1 = iVar7 + iVar8;
      iVar7 = iVar7 + 0x10;
      *(undefined4 *)(&DAT_ffffa578 + iVar1 + 0x18) = DAT_ffffbc24;
      puVar5 = puVar5 + 2;
    } while (iVar3 < 2);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  FUN_00010fa8();
  return;
}


