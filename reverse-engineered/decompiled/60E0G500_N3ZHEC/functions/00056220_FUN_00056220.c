/* ROM address: 0x00056220; body bytes: 768; decompiled_with_warnings */

uint FUN_00056220(char param_1,uint param_2)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  uint *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  byte bVar9;
  int iVar10;
  char local_3c [4];
  char local_38 [4];
  undefined *local_34;
  uint *local_30;
  uint local_2c [2];
  undefined4 uStack_24;
  undefined1 auStack_23 [3];
  undefined1 local_20;
  undefined1 auStack_1f [2];
  undefined1 uStack_1d;
  
  bVar9 = 0;
  while( true ) {
    cVar3 = (&DAT_0005f2bc)[(uint)bVar9 * 8];
    if ((cVar3 == param_1) || (cVar3 == '\0')) break;
    bVar9 = bVar9 + 1;
  }
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(bVar9) {
  case 0:
    local_30 = (uint *)param_2;
    FUN_00038ed8(0x80,local_2c);
    local_34 = (undefined *)((uint)local_34 & 0xffffff);
    uVar7 = FUN_00055066(local_30,&local_34,1);
    bVar9 = 0;
    puVar4 = local_2c;
    do {
      cVar3 = *(char *)puVar4;
      puVar4 = (uint *)((int)puVar4 + 1);
      uVar7 = FUN_00055066(uVar7,&local_34,(int)cVar3);
      bVar9 = bVar9 + 1;
    } while (bVar9 < 0x11);
    return (int)local_34._0_1_;
  case 1:
    local_38[0] = '\0';
    uVar7 = FUN_00055066(param_2,local_38,1);
    pcVar8 = "N3ZHEC000.HEX";
    bVar9 = 0;
    local_30 = local_2c;
    puVar4 = local_30;
    do {
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      bVar9 = bVar9 + 1;
      *(char *)puVar4 = cVar3;
      puVar4 = (uint *)((int)puVar4 + 1);
    } while (bVar9 < 9);
    local_34 = &DAT_0005fe8c;
    FUN_00038ed8(100,auStack_23,3);
    local_34 = &DAT_0005fe98;
    FUN_00038ed8(0x68,&local_20,1);
    local_34 = &DAT_0005fea4;
    FUN_00038ed8(0x6a,auStack_1f,2);
    local_34 = &DAT_0005feb0;
    FUN_00038ed8(0x6c,&uStack_1d,1);
    bVar9 = 0;
    puVar4 = local_30;
    do {
      cVar3 = *(char *)puVar4;
      puVar4 = (uint *)((int)puVar4 + 1);
      uVar7 = FUN_00055066(uVar7,local_38,(int)cVar3);
      bVar9 = bVar9 + 1;
    } while (bVar9 < 0x10);
    return (int)local_38[0];
  case 2:
    cVar3 = FUN_0005ad4a(&stack0xfffffff4);
    if (cVar3 == '\0') {
      uVar7 = FUN_00055066(param_2,&stack0xfffffff0,1);
      FUN_00055090(uVar7,&stack0xfffffff0,param_2);
    }
    return 0;
  case 3:
    uVar7 = FUN_00055066(param_2,&stack0xffffffe4,0x10);
    puVar5 = &DAT_ffff9138;
    do {
      uVar2 = FUN_0003eb24(puVar5,0);
      uVar7 = FUN_00055090(uVar7,&stack0xffffffe4,uVar2);
      puVar5 = puVar5 + 8;
    } while (puVar5 < &DAT_ffff9178);
    return 0;
  case 4:
    return 0;
  }
  param_2 = param_2 & 0xffff;
  bVar1 = false;
  if ((param_2 == 0) || (6 < param_2)) {
    bVar1 = true;
  }
  local_34._0_1_ = cVar3;
  if (!bVar1) {
    DAT_ffffd852 = 1;
    local_38[0] = 'A';
    FUN_000688c8(1,local_38);
    iVar10 = 0;
    if (param_2 != 0) {
      do {
        FUN_00068928(1,local_3c);
        cVar3 = FUN_00066e1c(1,(int)local_3c[0]);
        if (cVar3 == '\0') {
          cVar3 = FUN_00066ebc((int)local_3c[0]);
          if (cVar3 == '\0') {
            FUN_000660da((int)local_3c[0]);
          }
          else {
            FUN_00066124((int)local_3c[0]);
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)param_2);
    }
    if (DAT_ffffd852 == 1) {
      bVar1 = false;
    }
  }
  uVar6 = (uint)bVar1;
  if (uVar6 == 0) {
    local_30 = (uint *)0x1;
    local_2c[0] = (uint)DAT_ffffd852;
    local_2c[1] = 8;
    uStack_24 = 0;
    uVar6 = FUN_000694fa();
  }
  else if (uVar6 == 1) {
    if (local_34._0_1_ == '\x01') {
      uVar7 = 2;
    }
    else {
      uVar7 = 1;
    }
    uVar6 = FUN_00066ece(1,0x12,uVar7);
  }
  else if (uVar6 == 2) {
    if (local_34._0_1_ == '\x01') {
      uVar7 = 2;
    }
    else {
      uVar7 = 1;
    }
    uVar6 = FUN_00066ece(1,0x12,uVar7);
  }
  return uVar6;
}


