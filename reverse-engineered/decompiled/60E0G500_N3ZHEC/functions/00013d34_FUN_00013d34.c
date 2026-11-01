/* ROM address: 0x00013d34; body bytes: 128; decompiled */

uint FUN_00013d34(void)

{
  uint uVar1;
  
  if (DAT_ffffb5b8 < 8000.0) {
    if (DAT_ffffb5b8 < 7800.0) {
      DAT_ffffa786 = '\0';
    }
  }
  else {
    DAT_ffffa786 = '\x01';
  }
  uVar1 = 1;
  if (((DAT_ffffa786 == '\x01') || (uVar1 = (uint)DAT_ffffaada, uVar1 == 1)) || (DAT_ffffc12c < 0.1)
     ) {
    DAT_ffffa770 = 0;
  }
  else {
    uVar1 = FUN_00002440(DAT_ffffa760,0,0x3727c5ac);
    if (((uVar1 & 0xff) == 0) && (DAT_ffffa770 != 0)) {
      DAT_ffffa770 = DAT_ffffa770 + -1;
    }
  }
  return uVar1;
}


