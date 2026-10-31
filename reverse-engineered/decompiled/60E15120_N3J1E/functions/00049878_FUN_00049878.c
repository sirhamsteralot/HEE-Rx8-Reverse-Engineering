/* ROM address: 0x00049878; body bytes: 60; decompiled */

uint FUN_00049878(void)

{
  uint uVar1;
  
  DAT_ffffcd3e = DAT_ffffb0cd;
  if (DAT_ffffb0cd == '\x01') {
    DAT_ffffcd20 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffcd3f;
    if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcd1c, 0x1f < uVar1)) {
      DAT_ffffcd20 = 1;
    }
  }
  return uVar1;
}


