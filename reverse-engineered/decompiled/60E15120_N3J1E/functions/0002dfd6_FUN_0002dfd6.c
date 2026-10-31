/* ROM address: 0x0002dfd6; body bytes: 78; decompiled */

uint FUN_0002dfd6(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = rx8_is_outside_tolerance_band(DAT_ffffbfa4,DAT_ffffbfa8,0x3727c5ac);
  if (DAT_ffffbced == '\0') {
    if ((uVar1 & 0xff) == 0) {
      DAT_ffffbcfe = 0;
      return uVar1;
    }
  }
  else {
    if (DAT_ffffbd3e != 1) {
      return (uint)DAT_ffffbd3e;
    }
    uVar2 = uVar1 & 0xff;
    uVar1 = 1;
    if (uVar2 == 0) {
      DAT_ffffbcfe = 0;
      return 1;
    }
  }
  DAT_ffffbcfe = 1;
  return uVar1;
}


