/* ROM address: 0x00045a6a; body bytes: 318; decompiled */

undefined2 * FUN_00045a6a(void)

{
  bool bVar1;
  undefined2 *puVar2;
  ushort uVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar4 = DAT_ffffb700;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcc09 = 0;
    DAT_ffffcc0a = 0;
    DAT_ffffcc08 = 0;
    DAT_ffffcc0b = 0;
    DAT_ffffcc0c = '\0';
    puVar2 = (undefined2 *)0x1;
  }
  else {
    puVar2 = (undefined2 *)0x190;
    if (DAT_ffffbb04 == 400) {
      uVar7 = 0x3f800000;
      uVar8 = 0;
      fVar5 = (float)FUN_000024c0(0x3f800000,0,(int)(short)DAT_ffffb700);
      fVar6 = (float)FUN_000024c0(0x3e800000,uVar8,4);
      uVar3 = FUN_00002490(fVar5 * fVar6,uVar7,uVar8);
      bVar1 = false;
      if ((uVar4 < DAT_ffffcc0e) || (uVar3 < DAT_ffffcbd0)) {
        if (DAT_ffffcbf3 == '\0') {
          DAT_ffffcc09 = 1;
          DAT_ffffcc0a = 0;
        }
        else {
          bVar1 = true;
        }
      }
      else {
        DAT_ffffcc09 = 0;
        DAT_ffffcc0a = 1;
        uVar4 = FUN_00002490(fVar5 * 0.9,uVar7,uVar8);
        if (uVar4 < DAT_ffffb6f8) {
          DAT_ffffcc0b = 1;
        }
        if (uVar4 < DAT_ffffb6fa) {
          DAT_ffffcc0c = '\x01';
        }
        DAT_ffffcc08 = DAT_ffffcc0c << 1 | DAT_ffffcc0b;
      }
      if (!bVar1) {
        FUN_00045be0();
      }
      DAT_ffffcc08 = 0;
      DAT_ffffb6f8 = 0;
      DAT_ffffb6fa = 0;
      DAT_ffffcbe4 = 0;
      DAT_ffffcbe8 = 0;
      DAT_ffffcbd0 = 0;
      puVar2 = &DAT_ffffcbf0;
      DAT_ffffcbf0 = 1000;
      DAT_ffffcbf3 = '\0';
      DAT_ffffcc0b = 0;
      DAT_ffffcc0c = '\0';
    }
  }
  return puVar2;
}


