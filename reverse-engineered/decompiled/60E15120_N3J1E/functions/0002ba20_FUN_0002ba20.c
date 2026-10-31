/* ROM address: 0x0002ba20; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c174 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0002ba20(void)

{
  DAT_ffffbc01 = 0;
  if (DAT_ffffbd4c == '\x01') {
    DAT_ffffbc01 = 0x80;
  }
  if (DAT_ffffbd4d == '\x01') {
    DAT_ffffbc01 = DAT_ffffbc01 | 0x40;
  }
  if (DAT_ffffbd61 == '\x01') {
    DAT_ffffbc01 = DAT_ffffbc01 | 0x20;
  }
  if (DAT_ffffbd60 == '\x01') {
    DAT_ffffbc01 = DAT_ffffbc01 | 0x10;
  }
  return DAT_ffffbd60;
}


