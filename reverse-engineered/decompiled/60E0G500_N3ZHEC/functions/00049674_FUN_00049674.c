/* ROM address: 0x00049674; body bytes: 230; decompiled */

uint FUN_00049674(void)

{
  bool bVar1;
  byte bVar3;
  uint uVar2;
  byte bVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  
  DAT_ffffcd10 = DAT_ffffb520;
  fVar7 = DAT_ffffb520;
  fVar6 = rx8_absolute_difference(DAT_ffffb52c,0.0);
  fVar7 = rx8_absolute_difference(fVar7,DAT_ffffcd20);
  bVar3 = FUN_0003eaa4(&DAT_ffff80c8,0);
  uVar2 = (uint)DAT_ffffccfc;
  if (((uVar2 != 1) || (fVar6 < 80.0)) ||
     (((bVar3 != 0 || (100.0 <= fVar7)) && ((uVar2 = (uint)bVar3, uVar2 != 1 || (100.0 <= fVar7)))))
     ) {
    DAT_ffffcd0c = 0;
  }
  else {
    uVar2 = FUN_0003eaa4(&DAT_ffff8766,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = FUN_00002460((int)(short)DAT_ffffcd0c,1);
      DAT_ffffcd0c = (ushort)uVar2;
    }
  }
  if (DAT_ffffcd0c < 10) {
    uVar2 = 0;
  }
  DAT_ffffcd07 = DAT_ffffcd0c >= 10;
  bVar3 = 4;
  puVar5 = (undefined4 *)0xffffcd24;
  bVar1 = true;
  bVar4 = bVar3;
  while (bVar1) {
    bVar4 = bVar4 - 1;
    uVar2 = (uint)bVar4 * 4;
    bVar3 = bVar3 - 1;
    puVar5 = puVar5 + -1;
    *puVar5 = (&DAT_ffffcd10)[bVar4];
    bVar1 = bVar3 != 0;
  }
  return uVar2;
}


