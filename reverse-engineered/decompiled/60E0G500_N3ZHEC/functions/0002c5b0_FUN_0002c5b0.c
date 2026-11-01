/* ROM address: 0x0002c5b0; body bytes: 68; decompiled */

char FUN_0002c5b0(void)

{
  DAT_ffffbc69 = 0;
  if (DAT_ffffbdb8 == '\x01') {
    DAT_ffffbc69 = 0x80;
  }
  if (DAT_ffffbdb9 == '\x01') {
    DAT_ffffbc69 = DAT_ffffbc69 | 0x40;
  }
  if (DAT_ffffbdcd == '\x01') {
    DAT_ffffbc69 = DAT_ffffbc69 | 0x20;
  }
  if (DAT_ffffbdcc == '\x01') {
    DAT_ffffbc69 = DAT_ffffbc69 | 0x10;
  }
  return DAT_ffffbdcc;
}


