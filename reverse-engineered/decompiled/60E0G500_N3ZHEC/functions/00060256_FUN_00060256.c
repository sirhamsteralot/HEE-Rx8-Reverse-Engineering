/* ROM address: 0x00060256; body bytes: 60; decompiled */

uint dtc_count_stored(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00061bf4(0x80,0);
  if ((uVar1 & 0xffff) != 0) {
    uVar2 = FUN_0006009e();
    if ((uVar2 & 0xffff) != 0) {
      uVar1 = (uVar1 - uVar2) + 1;
    }
    if (0xff < (uVar1 & 0xffff)) {
      uVar1 = 0xff;
    }
  }
  return uVar1;
}


