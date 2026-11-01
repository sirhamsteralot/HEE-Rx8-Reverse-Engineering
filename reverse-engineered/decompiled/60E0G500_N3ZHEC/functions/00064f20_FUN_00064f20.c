/* ROM address: 0x00064f20; body bytes: 268; decompiled */

void FUN_00064f20(undefined4 param_1,char param_2,short param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  
  FUN_00062e0c();
  uVar1 = FUN_0006359c(param_1);
  uVar2 = FUN_00065a14(param_1);
  uVar3 = FUN_00065418(param_1,uVar1,uVar2);
  uVar4 = FUN_0006209c(param_1,uVar3,(int)param_2);
  cVar5 = FUN_00062bc4(uVar4);
  if (cVar5 == '\x01') {
    FUN_00063660(0);
    FUN_000636d2(0);
    if (((uVar2 & 0xff) == 0) || ((uVar2 & 0xff) == 1)) {
      FUN_00065518(uVar1,uVar3);
      FUN_00065674(uVar3);
      FUN_00065830(uVar3);
      FUN_000638ae(uVar4);
      FUN_000637ca((int)param_2);
      FUN_0006383c(1);
      FUN_00065b84(param_1,(int)param_3,uVar3);
      FUN_00062b54();
      FUN_00062824(param_1,0x20);
      FUN_0006288c(param_1,0x20,uVar3);
      FUN_0006303e();
      cVar5 = FUN_00065d40(uVar3);
      cVar6 = FUN_00065d40(uVar1);
      if (((cVar6 != '`') && (cVar5 == '`')) || ((cVar6 != 'p' && (cVar5 == 'p')))) {
        DAT_ffffd7f0 = 1;
      }
    }
  }
  FUN_0006305c();
  FUN_00063098();
  DAT_ffffd6fc = (char)uVar4;
  DAT_ffffd6ff = (char)uVar3;
  return;
}


