/* ROM address: 0x000322a8; body bytes: 70; decompiled */

uint FUN_000322a8(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffbced;
  if ((((uVar1 != 1) || (uVar1 = (uint)(char)DAT_ffffbfce, uVar1 != 0)) ||
      (uVar1 = (uint)DAT_ffffbc36, uVar1 != 1)) || (6.4 < DAT_ffffbfa4 - DAT_ffffbfa0)) {
    DAT_ffffbfb8 = 0;
  }
  else {
    DAT_ffffbfb8 = 1;
  }
  DAT_ffffbfce = DAT_ffffbc36;
  return uVar1;
}


