/* ROM address: 0x0004eac0; body bytes: 80; decompiled */

uint FUN_0004eac0(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffcfc6;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfa8, uVar1 < (uint)(int)DAT_ffffcfaa)) {
    if (DAT_ffffcfe4 < DAT_ffffcfe0) {
      if ((DAT_ffffcff8 == '\0') && (DAT_ffffcfb1 != '\0')) {
        DAT_ffffcfb1 = DAT_ffffcfb1 + -1;
      }
    }
    else {
      uVar1 = 8;
      DAT_ffffcfb1 = '\b';
    }
  }
  return uVar1;
}


