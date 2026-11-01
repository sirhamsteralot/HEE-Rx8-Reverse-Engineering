/* ROM address: 0x00060218; body bytes: 62; decompiled */

uint FUN_00060218(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00061bf4(0x80);
  if ((uVar1 & 0xffff) != 0) {
    uVar2 = FUN_0006009e();
    if ((uVar2 & 0xffff) != 0) {
      uVar1 = (uVar1 - uVar2) + 1;
    }
    if (0x7f < (uVar1 & 0xffff)) {
      uVar1 = 0x7f;
    }
  }
  return uVar1;
}


