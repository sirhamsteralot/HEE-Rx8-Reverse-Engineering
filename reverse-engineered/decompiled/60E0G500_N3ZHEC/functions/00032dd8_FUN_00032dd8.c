/* ROM address: 0x00032dd8; body bytes: 180; decompiled */

uint FUN_00032dd8(void)

{
  bool bVar1;
  uint uVar2;
  
  if (((((DAT_ffffbd59 != '\x01') || (DAT_ffffc01d != '\0')) || (DAT_ffffc034 != '\0')) ||
      (DAT_ffffbca1 != '\x01')) ||
     ((2.0 < DAT_ffffc008 - DAT_ffffc00c &&
      ((6.4 < DAT_ffffc008 - DAT_ffffc00c || (DAT_ffffc01f != '\x01')))))) {
    DAT_ffffc01e = 0;
    bVar1 = false;
  }
  else {
    DAT_ffffc01e = 1;
    bVar1 = true;
  }
  if ((DAT_ffffc035 == '\0') && (bVar1)) {
    DAT_ffffc026 = 0x177;
    uVar2 = 1;
  }
  else {
    uVar2 = (uint)DAT_ffffc026;
    if (uVar2 != 0) {
      DAT_ffffc026 = DAT_ffffc026 - 1;
    }
  }
  if (DAT_ffffc026 == 0) {
    uVar2 = 0xffffc01f;
  }
  DAT_ffffc01f = DAT_ffffc026 != 0;
  DAT_ffffc034 = DAT_ffffbca1;
  DAT_ffffc035 = DAT_ffffc01e;
  return uVar2;
}


