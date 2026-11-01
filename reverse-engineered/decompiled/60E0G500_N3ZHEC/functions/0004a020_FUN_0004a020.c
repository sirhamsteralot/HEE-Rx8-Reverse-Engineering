/* ROM address: 0x0004a020; body bytes: 60; decompiled */

uint FUN_0004a020(void)

{
  uint uVar1;
  
  DAT_ffffcd7e = DAT_ffffb13d;
  if (DAT_ffffb13d == '\x01') {
    DAT_ffffcd60 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffcd7f;
    if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcd5c, 0x1f < uVar1)) {
      DAT_ffffcd60 = 1;
    }
  }
  return uVar1;
}


