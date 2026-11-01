/* ROM address: 0x00042f08; body bytes: 474; decompiled */

undefined2 * FUN_00042f08(void)

{
  char cVar1;
  undefined2 *puVar2;
  char cVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  undefined2 uVar7;
  float fVar8;
  byte bStack_28;
  
  cVar1 = DAT_ffffc9be;
  cVar5 = DAT_ffffc9a0;
  cVar3 = DAT_ffffc99f;
  uVar6 = (uint)DAT_ffffc9b6;
  bStack_28 = DAT_ffffc99e;
  if (DAT_ffffd201 == '\x01') {
    puVar2 = &DAT_ffffc9b6;
    DAT_ffffc9b6 = 0;
    DAT_ffffc99f = '\0';
    DAT_ffffc9a0 = '\0';
    DAT_ffffc99e = 0;
    DAT_ffffc9d7 = '\0';
    DAT_ffffc9ca = 0;
    DAT_ffffc9cc = 0;
    DAT_ffffc9d2 = 0;
  }
  else {
    fVar8 = DAT_ffffc998;
    DAT_ffffc9a8 = (float)FUN_00002068(DAT_ffffc9b0,&PTR_DAT_0006bab0);
    if ((DAT_ffffc9d7 == '\0') && (cVar3 == '\x01')) {
      DAT_ffffc9ca = 0x14;
    }
    else if (DAT_ffffc9ca != 0) {
      DAT_ffffc9ca = DAT_ffffc9ca + -1;
    }
    if ((((cVar1 == '\x01') && (DAT_ffffb140 < 0.23)) && (fVar8 < DAT_ffffc9a8)) &&
       ((DAT_ffffc9ca == 0 || (cVar3 == '\0')))) {
      uVar6 = FUN_00002460(uVar6,1);
    }
    uVar7 = (undefined2)uVar6;
    if (cVar5 == '\x01') {
      cVar3 = '\0';
    }
    else if (3 < (uVar6 & 0xffff)) {
      cVar3 = '\x01';
    }
    if ((0x1e < (uVar6 & 0xffff)) && (cVar3 == '\x01')) {
      cVar5 = '\x01';
      bStack_28 = 0;
    }
    if (DAT_ffffc9db == '\x01') {
      DAT_ffffc9d2 = FUN_00002460((int)(short)DAT_ffffc9d2,1);
    }
    if ((((cVar1 != '\x01') || (DAT_ffffc9db != '\x01')) || (DAT_ffffc9d2 < 0x4e)) || (fVar8 < 0.73)
       ) {
      DAT_ffffc9cc = 0;
    }
    else {
      if (3 < DAT_ffffc9cc) {
        cVar5 = '\0';
        cVar3 = '\0';
        bStack_28 = 1;
        uVar7 = 0;
      }
      DAT_ffffc9cc = FUN_00002460((int)(short)DAT_ffffc9cc,1);
    }
    DAT_ffffc9d7 = DAT_ffffc99f;
    DAT_ffffc99e = bStack_28;
    DAT_ffffc99f = cVar3;
    DAT_ffffc9a0 = cVar5;
    DAT_ffffc9b6 = uVar7;
    if (cVar5 == '\x01') {
      puVar2 = (undefined2 *)FUN_000604dc(0x20,1);
    }
    else {
      puVar2 = (undefined2 *)(uint)bStack_28;
      if (puVar2 == (undefined2 *)&UNK_00000001) {
        cVar3 = FUN_00065e34(0x1f);
        if (cVar3 == '\0') {
          uVar4 = 4;
        }
        else {
          uVar4 = 2;
        }
        puVar2 = (undefined2 *)FUN_000604dc(0x20,uVar4);
      }
    }
  }
  return puVar2;
}


