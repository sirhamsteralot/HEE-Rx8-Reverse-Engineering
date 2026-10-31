/* ROM address: 0x00028c78; body bytes: 118; decompiled */

char FUN_00028c78(void)

{
  DAT_ffffbab2 = 0;
  if (DAT_ffffd1a1 == '\x01') {
    DAT_ffffbab2 = 0x8000;
  }
  else if (DAT_ffffd1a2 == '\x01') {
    DAT_ffffbab2 = 0x4000;
  }
  if (DAT_ffffbb64 == '\x01') {
    DAT_ffffbab2 = DAT_ffffbab2 | 0x400;
  }
  if (DAT_ffffbb65 == '\x01') {
    DAT_ffffbab2 = DAT_ffffbab2 | 0x100;
  }
  if (DAT_ffffbb66 == '\x01') {
    DAT_ffffbab2 = DAT_ffffbab2 | 0x80;
  }
  if (DAT_ffffb5b4 == '\x01') {
    DAT_ffffbab2 = DAT_ffffbab2 | 0x40;
  }
  if (DAT_ffffbb67 == '\x01') {
    DAT_ffffbab2 = DAT_ffffbab2 | 2;
  }
  return DAT_ffffbb67;
}


