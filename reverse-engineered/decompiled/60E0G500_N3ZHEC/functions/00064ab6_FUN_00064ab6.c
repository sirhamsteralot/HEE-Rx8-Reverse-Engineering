/* ROM address: 0x00064ab6; body bytes: 72; decompiled */

uint FUN_00064ab6(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87de)[(uint)DAT_ffff8928 * 0x10];
  if (((uVar1 == 0) || (0x3f < uVar1)) && ((uVar1 < 0x81 || (0xbf < uVar1)))) {
    if (uVar1 == 0xc0) {
      uVar1 = FUN_00063744(0x50);
      return uVar1;
    }
    return uVar1;
  }
  uVar1 = FUN_00063744(0);
  return uVar1;
}


