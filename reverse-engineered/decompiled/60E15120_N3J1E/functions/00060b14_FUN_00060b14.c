/* ROM address: 0x00060b14; body bytes: 318; decompiled */

void FUN_00060b14(uint param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 8;
  uVar2 = param_2 & 0xff;
  uVar4 = 0;
  if (uVar2 == 3) {
    uVar4 = FUN_00060cd6(param_1);
    uVar3 = FUN_000618f8(param_1,uVar4,param_2);
    cVar1 = FUN_00062420(uVar3);
    if (cVar1 == '\x01') {
      FUN_00060ddc(param_1,uVar4);
      FUN_00060f58();
      FUN_00062138(param_1);
      FUN_00060f02(param_1,0x20);
      FUN_0006310a(uVar3);
      FUN_00063026(param_2);
      FUN_00063098(1);
    }
  }
  else {
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        uVar4 = FUN_00062df8(param_1);
        uVar3 = FUN_000618f8(param_1,uVar4,param_2);
        cVar1 = FUN_00062420(uVar3);
        if (cVar1 == '\x01') {
          FUN_00063026(param_2);
        }
        FUN_000628b8();
      }
      goto LAB_00060c38;
    }
    uVar4 = FUN_00062df8(param_1);
    if (((byte)uVar4 & 0x80) != 0x80) {
      uVar4 = 0;
    }
    uVar3 = FUN_000618f8(param_1,uVar4,param_2);
    cVar1 = FUN_00062420(uVar3);
    if (cVar1 == '\x01') {
      if (((byte)uVar4 & 0x80) != 0x80) {
        FUN_00062dd8(uVar4);
        FUN_0006310a(uVar3);
      }
      FUN_00063026(param_2);
    }
  }
  FUN_000628b8();
LAB_00060c38:
  DAT_ffffd6c0 = (undefined1)uVar3;
  DAT_ffffd6c3 = (undefined1)uVar4;
  FUN_000623b0();
  if ((uint)DAT_ffffd6c4 == (param_1 & 0xffff)) {
    FUN_00062080(param_1,0x20);
  }
  FUN_000620e8(param_1,0x20,uVar4);
  FUN_0006289a();
  return;
}


