/* ROM address: 0x0002783c; body bytes: 88; decompiled */

uint FUN_0002783c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffb71d;
  if (uVar1 == 1) {
    DAT_ffffb71b = 0;
    DAT_ffffb718 = 0;
    DAT_ffffb71d = 0;
  }
  else {
    if (DAT_ffffb718 < 0xff) {
      uVar1 = FUN_00002460((int)(short)DAT_ffffb718,1);
      DAT_ffffb718 = (ushort)uVar1;
    }
    else {
      DAT_ffffb718 = 0xff;
    }
    if (DAT_ffffb718 == 0) {
      DAT_ffffb71b = 0;
    }
    else {
      DAT_ffffb71b = 1;
    }
  }
  return uVar1;
}


