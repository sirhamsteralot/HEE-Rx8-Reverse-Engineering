/* ROM address: 0x00064708; body bytes: 160; decompiled */

void FUN_00064708(undefined4 param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 8;
  uVar3 = 0;
  if ((param_2 & 0xff) == 3) {
    uVar3 = FUN_0006482c(param_1);
    uVar2 = FUN_0006209c(param_1,uVar3,param_2);
    cVar1 = FUN_00062bc4(uVar2);
    if (cVar1 == '\x01') {
      FUN_000648c6(param_1,uVar3);
      FUN_00064a5c();
      FUN_000628dc(param_1);
      FUN_000649d8(param_1,0x20);
      FUN_00064ab6();
      FUN_000638ae(uVar2);
      FUN_000637ca(param_2);
      FUN_0006383c(1);
      FUN_00064bbc(param_1,uVar3);
    }
    FUN_0006305c();
  }
  DAT_ffffd6fc = (undefined1)uVar2;
  DAT_ffffd6ff = (undefined1)uVar3;
  FUN_00062b54();
  FUN_00062824(param_1,0x20);
  FUN_0006288c(param_1,0x20,uVar3);
  FUN_0006303e();
  return;
}


