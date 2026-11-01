/* ROM address: 0x00064c22; body bytes: 40; decompiled */

uint FUN_00064c22(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87de)[(uint)DAT_ffff8928 * 0x10];
  if ((uVar1 != 0) && (uVar1 != 0x50)) {
    return uVar1;
  }
  uVar1 = FUN_00067f04();
  return uVar1;
}


