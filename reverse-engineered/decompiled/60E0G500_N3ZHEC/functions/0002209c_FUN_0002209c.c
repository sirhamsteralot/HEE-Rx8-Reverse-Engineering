/* ROM address: 0x0002209c; body bytes: 194; decompiled */

uint FUN_0002209c(void)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  
  cVar1 = DAT_ffffbdd4;
  if ((DAT_ffffb312 == '\x01') && (DAT_ffffbdd4 == '\0')) {
    DAT_ffffb310 = 1;
    if (DAT_ffffaada == '\x01') {
      DAT_ffffb300 = 0xc0a00000;
      pbVar3 = &DAT_00072ba1;
    }
    else {
      DAT_ffffb300 = 0;
      pbVar3 = &DAT_00072ba3;
    }
    DAT_ffffb30a = 0;
    DAT_ffffb30b = *pbVar3;
    DAT_ffffb309 = 0;
    DAT_ffffb308 = 0;
  }
  uVar2 = (uint)DAT_ffffb310;
  if (uVar2 == 1) {
    if (DAT_ffffb308 < DAT_ffffb30a) {
      uVar2 = FUN_00002478((int)(char)DAT_ffffb308,1);
      DAT_ffffb308 = (byte)uVar2;
    }
    else if (DAT_ffffb309 < DAT_ffffb30b) {
      DAT_ffffb2f8 = DAT_ffffb300;
      uVar2 = FUN_00002478((int)(char)DAT_ffffb309,1);
      DAT_ffffb309 = (byte)uVar2;
    }
    else {
      DAT_ffffb308 = 0;
      DAT_ffffb309 = 0;
      DAT_ffffb310 = 0;
      DAT_ffffb2f8 = 0;
    }
  }
  DAT_ffffb312 = cVar1;
  return uVar2;
}


