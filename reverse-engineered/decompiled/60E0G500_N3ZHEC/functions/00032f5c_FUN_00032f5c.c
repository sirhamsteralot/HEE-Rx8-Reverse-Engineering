/* ROM address: 0x00032f5c; body bytes: 140; decompiled */

uint FUN_00032f5c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffbca2;
  if (DAT_ffffc01d == '\x01') {
    if (uVar1 == 0) {
      DAT_ffffc037 = '\x01';
    }
  }
  else {
    DAT_ffffc037 = '\0';
  }
  if (((DAT_ffffbd59 == '\x01') &&
      (((DAT_ffffc01d == '\0' || (DAT_ffffc037 == '\x01')) && (DAT_ffffc02a == 0x3e)))) &&
     (uVar1 == 1)) {
    DAT_ffffc021 = 1;
  }
  else if (uVar1 == 0) {
    DAT_ffffc021 = 0;
  }
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)DAT_ffffc02a,1);
    DAT_ffffc02a = (short)uVar1;
  }
  else {
    DAT_ffffc02a = 0;
  }
  return uVar1;
}


