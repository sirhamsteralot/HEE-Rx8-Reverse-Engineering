/* ROM address: 0x0003e8a4; body bytes: 214; decompiled */

uint FUN_0003e8a4(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc69e = 0x27;
    uVar1 = 8;
    DAT_ffffc69f = '\b';
    DAT_ffffc6a5 = 0;
    DAT_ffffc6a6 = 0;
  }
  else if (DAT_ffffb320 == '\0') {
    uVar1 = (uint)DAT_ffffc6a7;
    if (uVar1 == 1) {
      uVar1 = (uint)DAT_ffffc69e;
      if (uVar1 == 0) {
        uVar1 = FUN_000671a4(0x58);
        uVar1 = uVar1 & 0xff;
        if (((uVar1 == 0) && (DAT_ffffc6a0 == '\0')) && (uVar1 = (uint)DAT_ffffc6a1, uVar1 == 0)) {
          DAT_ffffc6a5 = 1;
          DAT_ffffc6a6 = 0;
        }
      }
      else {
        DAT_ffffc69e = DAT_ffffc69e - 1;
      }
      DAT_ffffc69f = '\b';
    }
    else {
      DAT_ffffc69e = 0x27;
      if (DAT_ffffc69f == '\0') {
        uVar1 = FUN_000671a4(0x58);
        uVar1 = uVar1 & 0xff;
        if (uVar1 == 0) {
          DAT_ffffc6a6 = 1;
          DAT_ffffc6a5 = 0;
        }
      }
      else {
        DAT_ffffc69f = DAT_ffffc69f + -1;
      }
    }
  }
  else {
    DAT_ffffc69e = 0x27;
    uVar1 = 8;
    DAT_ffffc69f = '\b';
  }
  return uVar1;
}


