/* ROM address: 0x00065830; body bytes: 56; decompiled */

uint FUN_00065830(void)

{
  uint uVar1;
  
  uVar1 = FUN_00065d40();
  uVar1 = uVar1 & 0xff;
  if ((uVar1 != 0x60) && (uVar1 != 0x70)) {
    if (uVar1 == 0xc0) {
      uVar1 = FUN_00063744(0x50);
      return uVar1;
    }
    return uVar1;
  }
  uVar1 = FUN_00063744(0);
  return uVar1;
}


