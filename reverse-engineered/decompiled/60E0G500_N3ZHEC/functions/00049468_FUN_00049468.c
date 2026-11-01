/* ROM address: 0x00049468; body bytes: 120; decompiled */

uint FUN_00049468(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (((DAT_ffffaae0 == '\x01') ||
      ((uVar1 = (uint)DAT_ffffb55e, uVar1 == 1 && (uVar1 = (uint)DAT_ffffccf6, uVar1 < 0x271)))) &&
     (DAT_ffffcce0 == '\0')) {
    if ((DAT_ffffadd8 != '\x01') && (DAT_ffffadd9 != '\x01')) {
      uVar1 = FUN_0003eaa4(&DAT_ffff80ca,1);
      if ((uVar1 & 0xff) != 1) {
        DAT_ffffcd01 = 0;
        return uVar1 & 0xff;
      }
    }
    uVar1 = 1;
    if (DAT_ffffb58a == '\0') {
      DAT_ffffcd01 = 1;
      return 1;
    }
  }
  DAT_ffffcd01 = 0;
  return uVar1;
}


