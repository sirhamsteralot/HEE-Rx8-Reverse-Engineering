/* ROM address: 0x00055244; body bytes: 106; decompiled */

uint FUN_00055244(byte param_1)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  
  cVar2 = FUN_000565e2(0);
  if (cVar2 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = 3;
  }
  FUN_00056490(uVar3);
  FUN_0005c2a4(3);
  FUN_0005e944(3);
  FUN_0005e49c(3);
  FUN_00056e94(3);
  uVar1 = (uint)param_1;
  if (uVar1 != 0x11) {
    if (uVar1 != 0xb1) {
      return uVar1;
    }
    uVar1 = FUN_00056b82(2);
    return uVar1;
  }
  uVar1 = FUN_0005b7bc(3);
  return uVar1;
}


