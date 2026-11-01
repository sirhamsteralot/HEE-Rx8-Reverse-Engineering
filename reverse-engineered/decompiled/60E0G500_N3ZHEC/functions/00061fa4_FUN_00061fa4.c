/* ROM address: 0x00061fa4; body bytes: 56; decompiled */

uint FUN_00061fa4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0006359c();
  uVar2 = uVar1 & 0xff;
  if ((uVar2 == 0) || (0x3f < uVar2)) {
    if ((0x80 < uVar2) && (uVar2 < 0xc0)) {
      uVar1 = 0x70;
    }
  }
  else {
    uVar1 = 0x60;
  }
  return uVar1;
}


