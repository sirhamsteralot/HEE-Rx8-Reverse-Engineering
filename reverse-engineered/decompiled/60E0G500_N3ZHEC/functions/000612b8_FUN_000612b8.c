/* ROM address: 0x000612b8; body bytes: 318; decompiled */

void FUN_000612b8(uint param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 8;
  uVar2 = param_2 & 0xff;
  uVar4 = 0;
  if (uVar2 == 3) {
    uVar4 = FUN_0006147a(param_1);
    uVar3 = FUN_0006209c(param_1,uVar4,param_2);
    cVar1 = FUN_00062bc4(uVar3);
    if (cVar1 == '\x01') {
      FUN_00061580(param_1,uVar4);
      FUN_000616fc();
      FUN_000628dc(param_1);
      FUN_000616a6(param_1,0x20);
      FUN_000638ae(uVar3);
      FUN_000637ca(param_2);
      FUN_0006383c(1);
    }
  }
  else {
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        uVar4 = FUN_0006359c(param_1);
        uVar3 = FUN_0006209c(param_1,uVar4,param_2);
        cVar1 = FUN_00062bc4(uVar3);
        if (cVar1 == '\x01') {
          FUN_000637ca(param_2);
        }
        FUN_0006305c();
      }
      goto LAB_000613dc;
    }
    uVar4 = FUN_0006359c(param_1);
    if (((byte)uVar4 & 0x80) != 0x80) {
      uVar4 = 0;
    }
    uVar3 = FUN_0006209c(param_1,uVar4,param_2);
    cVar1 = FUN_00062bc4(uVar3);
    if (cVar1 == '\x01') {
      if (((byte)uVar4 & 0x80) != 0x80) {
        FUN_0006357c(uVar4);
        FUN_000638ae(uVar3);
      }
      FUN_000637ca(param_2);
    }
  }
  FUN_0006305c();
LAB_000613dc:
  DAT_ffffd6fc = (undefined1)uVar3;
  DAT_ffffd6ff = (undefined1)uVar4;
  FUN_00062b54();
  if ((uint)DAT_ffffd700 == (param_1 & 0xffff)) {
    FUN_00062824(param_1,0x20);
  }
  FUN_0006288c(param_1,0x20,uVar4);
  FUN_0006303e();
  return;
}


