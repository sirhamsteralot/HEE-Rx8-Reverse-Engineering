/* ROM address: 0x0002219c; body bytes: 194; decompiled */

uint FUN_0002219c(void)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  
  cVar1 = DAT_ffffbdd4;
  if ((DAT_ffffb313 == '\x01') && (DAT_ffffbdd4 == '\0')) {
    DAT_ffffb311 = 1;
    if (DAT_ffffaada == '\x01') {
      DAT_ffffb304 = 0xc0a00000;
      pbVar3 = &DAT_00072bad;
    }
    else {
      DAT_ffffb304 = 0;
      pbVar3 = &DAT_00072baf;
    }
    DAT_ffffb30e = 0;
    DAT_ffffb30f = *pbVar3;
    DAT_ffffb30d = 0;
    DAT_ffffb30c = 0;
  }
  uVar2 = (uint)DAT_ffffb311;
  if (uVar2 == 1) {
    if (DAT_ffffb30c < DAT_ffffb30e) {
      uVar2 = FUN_00002478((int)(char)DAT_ffffb30c,1);
      DAT_ffffb30c = (byte)uVar2;
    }
    else if (DAT_ffffb30d < DAT_ffffb30f) {
      DAT_ffffb2fc = DAT_ffffb304;
      uVar2 = FUN_00002478((int)(char)DAT_ffffb30d,1);
      DAT_ffffb30d = (byte)uVar2;
    }
    else {
      DAT_ffffb30c = 0;
      DAT_ffffb30d = 0;
      DAT_ffffb311 = 0;
      DAT_ffffb2fc = 0;
    }
  }
  DAT_ffffb313 = cVar1;
  return uVar2;
}


