/* ROM address: 0x0006508c; body bytes: 56; decompiled */

uint FUN_0006508c(void)

{
  uint uVar1;
  
  uVar1 = FUN_0006559c();
  uVar1 = uVar1 & 0xff;
  if ((uVar1 != 0x60) && (uVar1 != 0x70)) {
    if (uVar1 == 0xc0) {
      uVar1 = FUN_00062fa0(0x50);
      return uVar1;
    }
    return uVar1;
  }
  uVar1 = FUN_00062fa0(0);
  return uVar1;
}


