/* ROM address: 0x0002d188; body bytes: 60; decompiled */

void FUN_0002d188(void)

{
  undefined4 uVar1;
  
  if ((DAT_ffffbcd9 < 5) && (DAT_ffffbcda < 5)) {
    DAT_ffffbcd8 = '\0';
  }
  else {
    DAT_ffffbcd8 = '\x01';
  }
  if (DAT_ffffbcd8 == '\x01') {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  FUN_0005fd38(0x40,uVar1);
  return;
}


