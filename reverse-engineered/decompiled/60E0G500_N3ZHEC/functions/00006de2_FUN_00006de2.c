/* ROM address: 0x00006de2; body bytes: 208; decompiled */

byte FUN_00006de2(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  if (DAT_ffff9f25 != '\x01') {
    if (DAT_ffff9f2e == 0xc) {
      bVar1 = DAT_fffff839;
      DAT_fffff839 = bVar1 & 0xdf;
      uVar2 = 0x33;
    }
    else {
      if (DAT_ffff9f2e == 8) {
        bVar1 = DAT_fffff839;
        DAT_fffff839 = bVar1 & 0xdf;
        DAT_fffff838 = 0x23;
        goto LAB_00006eb8;
      }
      if (DAT_ffff9f2e != 4) {
        if (DAT_ffff9f2e != 1) {
          return DAT_ffff9f2e;
        }
        bVar1 = DAT_fffff839;
        DAT_fffff839 = bVar1 & 0xdf;
        DAT_fffff838 = 0x10;
        goto LAB_00006eb8;
      }
      bVar1 = DAT_fffff839;
      DAT_fffff839 = bVar1 & 0xdf;
      uVar2 = 0x13;
    }
    DAT_fffff838 = uVar2;
LAB_00006eb8:
    bVar1 = DAT_fffff839;
    bVar1 = bVar1 & 0x2f | 0x20;
    DAT_fffff839 = bVar1;
    return bVar1;
  }
  if (DAT_ffff9f2e == 0xc) {
    bVar1 = DAT_fffff839;
    DAT_fffff839 = bVar1 & 0xdf;
    uVar2 = 0x73;
  }
  else {
    if (DAT_ffff9f2e == 8) {
      bVar1 = DAT_fffff839;
      DAT_fffff839 = bVar1 & 0xdf;
      DAT_fffff838 = 99;
      goto LAB_00006e48;
    }
    if (DAT_ffff9f2e != 4) {
      if (DAT_ffff9f2e != 1) {
        return DAT_ffff9f2e;
      }
      bVar1 = DAT_fffff839;
      DAT_fffff839 = bVar1 & 0xdf;
      DAT_fffff838 = 0x50;
      goto LAB_00006e48;
    }
    bVar1 = DAT_fffff839;
    DAT_fffff839 = bVar1 & 0xdf;
    uVar2 = 0x53;
  }
  DAT_fffff838 = uVar2;
LAB_00006e48:
  bVar1 = DAT_fffff839;
  bVar1 = bVar1 & 0x2f | 0x20;
  DAT_fffff839 = bVar1;
  return bVar1;
}


