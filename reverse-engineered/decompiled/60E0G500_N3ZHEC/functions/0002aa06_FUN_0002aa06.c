/* ROM address: 0x0002aa06; body bytes: 52; decompiled */

char FUN_0002aa06(void)

{
  DAT_ffffbbc3 = 0;
  if (DAT_ffffbbb0 == '\x01') {
    DAT_ffffbbc3 = 0x80;
  }
  if (DAT_ffffbbb1 == '\x01') {
    DAT_ffffbbc3 = DAT_ffffbbc3 | 4;
  }
  if (DAT_ffffbbb2 == '\x01') {
    DAT_ffffbbc3 = DAT_ffffbbc3 | 1;
  }
  return DAT_ffffbbb2;
}


