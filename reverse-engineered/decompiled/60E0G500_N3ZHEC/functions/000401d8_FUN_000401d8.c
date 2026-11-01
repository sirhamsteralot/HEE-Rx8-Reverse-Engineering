/* ROM address: 0x000401d8; body bytes: 510; decompiled */

undefined4 * FUN_000401d8(void)

{
  float fVar1;
  float fVar2;
  char cVar5;
  uint uVar3;
  undefined4 *puVar4;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar2 = DAT_ffffb5b8;
  fVar1 = DAT_ffffaaf0;
  fVar9 = DAT_ffffb0e8 - 0.2;
  fVar8 = DAT_ffffb0e8 + 0.1;
  fVar10 = DAT_ffffaa10;
  fVar11 = DAT_ffffaa88;
  fVar12 = DAT_ffffb0e4;
  fVar13 = DAT_ffffad98;
  fVar6 = (float)FUN_0003eb72(0,&DAT_ffff8748);
  fVar7 = (float)FUN_0003eb72(0,&DAT_ffff8740);
  cVar5 = FUN_00002440(DAT_ffffb360,0,0x3727c5ac);
  uVar3 = FUN_000671a4(0x6e);
  puVar4 = (undefined4 *)(uVar3 & 0xff);
  if (puVar4 == (undefined4 *)0x0) {
    uVar3 = FUN_000671a4(0x6d);
    puVar4 = (undefined4 *)(uVar3 & 0xff);
    if ((((((puVar4 == (undefined4 *)0x0) &&
           (puVar4 = (undefined4 *)(uint)DAT_ffffae97, puVar4 == (undefined4 *)&UNK_00000001)) &&
          (puVar4 = (undefined4 *)(uint)DAT_ffffb0ed, puVar4 == (undefined4 *)&UNK_00000001)) &&
         ((1000.0 <= fVar2 && (fVar2 < 3200.0)))) &&
        ((puVar4 = &DAT_0007d99c, 6.0 <= fVar11 &&
         ((fVar11 < 80.0 && (puVar4 = &DAT_0007d9a4, 70.0 <= fVar10)))))) &&
       ((fVar10 < 150.0 && (puVar4 = &DAT_0007d9ac, DAT_ffffc1c0 < 0.05)))) {
      if (0.0 <= fVar1) {
        puVar4 = (undefined4 *)&UNK_00000004;
        if (((((fVar1 < 52.0) && (puVar4 = (undefined4 *)&DAT_ffffae90, DAT_ffffae90 == 0)) &&
             (puVar4 = (undefined4 *)&DAT_ffffd201, DAT_ffffd201 == '\0')) &&
            ((((fVar9 <= fVar13 && (fVar13 < fVar8)) ||
              ((fVar12 <= fVar7 + 0.0003 || ((fVar6 - 0.0003 <= fVar12 || (fVar13 < 0.2)))))) ||
             (puVar4 = (undefined4 *)&UNK_00000014, 0.7 <= fVar13)))) &&
           ((cVar5 == '\0' ||
            ((puVar4 = (undefined4 *)&UNK_00000010, DAT_ffffb290 < 0.2 &&
             (puVar4 = (undefined4 *)(int)DAT_ffffb364, (undefined4 *)0x270 < puVar4)))))) {
          DAT_ffffc74e = 1;
          if (0x1e < DAT_ffffc748) {
            DAT_ffffc74e = 1;
            return (undefined4 *)&DAT_0007d98e;
          }
          puVar4 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffc748,1);
          DAT_ffffc748 = (short)puVar4;
          return puVar4;
        }
      }
      else {
        puVar4 = (undefined4 *)&UNK_00000004;
      }
    }
  }
  DAT_ffffc74e = 0;
  DAT_ffffc748 = 0;
  return puVar4;
}


