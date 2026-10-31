/* ROM address: 0x00060cd6; body bytes: 162; decompiled */

uint FUN_00060cd6(undefined4 param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar1 = FUN_00062df8();
  uVar3 = uVar1 & 0xff;
  if (uVar3 != 0) {
    if ((uVar3 == 0) || (0x3f < uVar3)) {
      if ((0x80 < uVar3) && (uVar3 < 0xc0)) {
        cVar2 = FUN_000630b8(param_1);
        if (cVar2 == '\x01') {
          uVar1 = FUN_00060dae(param_1,uVar1);
          return uVar1;
        }
        return 0x81;
      }
      if (uVar3 == 0xc0) {
        return uVar1;
      }
      if (uVar3 == 0xc1) {
        return 0xc0;
      }
      if (uVar3 != 0x50) {
        return uVar1;
      }
      uVar1 = FUN_00060dae(param_1,0);
      return uVar1;
    }
    cVar2 = FUN_000630b8(param_1);
    if (cVar2 != '\x01') {
      return 1;
    }
  }
  uVar1 = FUN_00060dae(param_1,uVar1);
  return uVar1;
}


