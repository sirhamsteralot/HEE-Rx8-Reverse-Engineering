/* ROM address: 0x0003cf82; body bytes: 124; decompiled */

char FUN_0003cf82(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc635 = 0;
    DAT_ffffc636 = 0;
  }
  else {
    uVar1 = FUN_000070ac(2);
    if ((uVar1 & 0x80) == 0) {
      DAT_ffffc634 = 0xf;
      DAT_ffffc635 = 0;
      DAT_ffffc636 = 1;
      return '\x01';
    }
    if (DAT_ffffd1e9 != '\x01') {
      if (DAT_ffffc634 != '\0') {
        DAT_ffffc634 = DAT_ffffc634 + -1;
        return DAT_ffffd1e9;
      }
      DAT_ffffc635 = 1;
      DAT_ffffc636 = 0;
      return DAT_ffffd1e9;
    }
  }
  DAT_ffffc634 = 0xf;
  return '\x01';
}


