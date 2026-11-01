/* ROM address: 0x00042c70; body bytes: 476; decompiled */

undefined2 * FUN_00042c70(void)

{
  char cVar1;
  undefined2 *puVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined2 uVar6;
  char cVar7;
  float fVar8;
  byte bStack_28;
  
  cVar7 = DAT_ffffc9bf;
  cVar1 = DAT_ffffc9bd;
  cVar3 = DAT_ffffc99d;
  uVar5 = (uint)DAT_ffffc9b4;
  bStack_28 = DAT_ffffc99c;
  if (DAT_ffffd201 == '\x01') {
    puVar2 = &DAT_ffffc9b4;
    DAT_ffffc9b4 = 0;
    DAT_ffffc9bf = '\0';
    DAT_ffffc99d = '\0';
    DAT_ffffc99c = 0;
    DAT_ffffc9d9 = '\0';
    DAT_ffffc9ce = 0;
    DAT_ffffc9c8 = 0;
    DAT_ffffc9d0 = 0;
  }
  else {
    fVar8 = DAT_ffffc998;
    DAT_ffffc9a4 = (float)FUN_00002068(DAT_ffffc9b0,&PTR_DAT_0006baa4);
    if ((cVar7 == '\x01') && (DAT_ffffc9d9 == '\0')) {
      DAT_ffffc9ce = 0x14;
    }
    else if (DAT_ffffc9ce != 0) {
      DAT_ffffc9ce = DAT_ffffc9ce + -1;
    }
    if ((((cVar1 == '\x01') && (-0.23 <= DAT_ffffb140)) && (DAT_ffffc9a4 <= fVar8)) &&
       ((DAT_ffffc9ce == 0 || (DAT_ffffc9bf == '\0')))) {
      uVar5 = FUN_00002460(uVar5,1);
    }
    uVar6 = (undefined2)uVar5;
    if (cVar3 == '\x01') {
      cVar7 = '\0';
    }
    else if (3 < (uVar5 & 0xffff)) {
      cVar7 = '\x01';
    }
    if ((0x1e < (uVar5 & 0xffff)) && (cVar7 == '\x01')) {
      cVar3 = '\x01';
      bStack_28 = 0;
    }
    if (DAT_ffffc9da == '\x01') {
      DAT_ffffc9d0 = FUN_00002460((int)(short)DAT_ffffc9d0,1);
    }
    if ((((cVar1 != '\x01') || (DAT_ffffc9da != '\x01')) || (DAT_ffffc9d0 < 0x4e)) ||
       (1.25 <= fVar8)) {
      DAT_ffffc9c8 = 0;
    }
    else {
      if (3 < DAT_ffffc9c8) {
        cVar7 = '\0';
        cVar3 = '\0';
        bStack_28 = 1;
        uVar6 = 0;
      }
      DAT_ffffc9c8 = FUN_00002460((int)(short)DAT_ffffc9c8,1);
    }
    DAT_ffffc9d9 = DAT_ffffc9bf;
    DAT_ffffc99c = bStack_28;
    DAT_ffffc99d = cVar3;
    DAT_ffffc9b4 = uVar6;
    DAT_ffffc9bf = cVar7;
    if (cVar3 == '\x01') {
      puVar2 = (undefined2 *)FUN_000604dc(0x1f,1);
    }
    else {
      puVar2 = (undefined2 *)(uint)bStack_28;
      if (puVar2 == (undefined2 *)&UNK_00000001) {
        cVar3 = FUN_00065e34(0x1e);
        if (cVar3 == '\0') {
          uVar4 = 4;
        }
        else {
          uVar4 = 2;
        }
        puVar2 = (undefined2 *)FUN_000604dc(0x1f,uVar4);
      }
    }
  }
  return puVar2;
}


