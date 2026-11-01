/* ROM address: 0x000077f0; body bytes: 138; decompiled */

uint crank_capture_poll(void)

{
  uint uVar1;
  
  DAT_ffff9fb8 = DAT_fffff434;
  DAT_ffff9fb4 = DAT_ffff9fb0;
  DAT_ffff9fb0 = DAT_fffff6d0;
  FUN_0000787a();
  if (DAT_ffff9f95 == 0) {
    FUN_00007a86(0);
  }
  else if (DAT_ffff9f95 == 0x12) {
    FUN_00007a86(6);
  }
  uVar1 = (uint)DAT_ffff9fc0;
  if ((uVar1 == 1) && (uVar1 = 0, ((int)(char)(&DAT_0000d76d)[(uint)DAT_ffff9f95 * 2] & 0x80U) != 0)
     ) {
    DAT_ffff9fa8 = DAT_ffff9fb8 - DAT_ffff9fac;
    DAT_ffff9fac = DAT_ffff9fb8;
    uVar1 = (uint)DAT_ffff9fa3;
    if (uVar1 != 2) {
      uVar1 = FUN_00007c68();
      return uVar1;
    }
  }
  return uVar1;
}


