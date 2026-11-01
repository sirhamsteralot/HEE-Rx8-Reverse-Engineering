/* ROM address: 0x000432f8; body bytes: 338; decompiled */

uint FUN_000432f8(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc9e9 = 0;
    DAT_ffffc9ea = 0;
    DAT_ffffc9eb = 0;
    DAT_ffffc9ec = 0;
    DAT_ffffc9ed = 0;
    DAT_ffffc9ee = 0;
    DAT_ffffc9f2 = 0;
    DAT_ffffc9f4 = 0;
    DAT_ffffc9f6 = 0;
    DAT_ffffc9f8 = 0;
    DAT_ffffc9fa = 0;
    DAT_ffffc9fc = 0;
    return 1;
  }
  if (DAT_ffffc9e8 != 1) {
    DAT_ffffc9f2 = 0;
    DAT_ffffc9f4 = 0;
    DAT_ffffc9f6 = 0;
    DAT_ffffc9f8 = 0;
    DAT_ffffc9fa = 0;
    DAT_ffffc9fc = 0;
    return (uint)DAT_ffffc9e8;
  }
  if (DAT_ffffa1dc == '\x01') {
    if (DAT_ffffc9f2 == 4) {
      DAT_ffffc9e9 = 1;
    }
    DAT_ffffc9f2 = FUN_00002460((int)DAT_ffffc9f2,1);
    DAT_ffffc9f4 = 0;
  }
  else {
    if (DAT_ffffa1dc != '\x02') {
      if (DAT_ffffc9f6 == 8) {
        DAT_ffffc9eb = 1;
      }
      DAT_ffffc9f6 = FUN_00002460((int)DAT_ffffc9f6,1);
      DAT_ffffc9f2 = 0;
      DAT_ffffc9f4 = 0;
      goto LAB_0004340e;
    }
    if (DAT_ffffc9f4 == 4) {
      DAT_ffffc9ea = 1;
    }
    DAT_ffffc9f4 = FUN_00002460((int)DAT_ffffc9f4,1);
    DAT_ffffc9f2 = 0;
  }
  DAT_ffffc9f6 = 0;
LAB_0004340e:
  if (DAT_ffffa1dd == '\x01') {
    if (DAT_ffffc9f8 == 4) {
      DAT_ffffc9ec = 1;
    }
    uVar1 = FUN_00002460((int)DAT_ffffc9f8,1);
    DAT_ffffc9fc = 0;
    DAT_ffffc9fa = 0;
    DAT_ffffc9f8 = (short)uVar1;
    return uVar1;
  }
  if (DAT_ffffa1dd != '\x02') {
    if (DAT_ffffc9fc == 8) {
      DAT_ffffc9ee = 1;
    }
    uVar1 = FUN_00002460((int)DAT_ffffc9fc,1);
    DAT_ffffc9f8 = 0;
    DAT_ffffc9fa = 0;
    DAT_ffffc9fc = (short)uVar1;
    return uVar1;
  }
  if (DAT_ffffc9fa == 4) {
    DAT_ffffc9ed = 1;
  }
  uVar1 = FUN_00002460((int)DAT_ffffc9fa,1);
  DAT_ffffc9f8 = 0;
  DAT_ffffc9fa = (short)uVar1;
  DAT_ffffc9fc = 0;
  return uVar1;
}


