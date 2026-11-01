/* ROM address: 0x0001ba88; body bytes: 44; decompiled */

ushort FUN_0001ba88(void)

{
  ushort uVar1;
  
  uVar1 = (ushort)DAT_ffffbdb4;
  if (DAT_ffffbdb4 == 1) {
    DAT_ffffad90 = (DAT_ffff9ec8 & 0x20) != 0;
    uVar1 = DAT_ffff9ec8;
    DAT_ffffad92 = DAT_ffffad90;
  }
  return uVar1;
}


