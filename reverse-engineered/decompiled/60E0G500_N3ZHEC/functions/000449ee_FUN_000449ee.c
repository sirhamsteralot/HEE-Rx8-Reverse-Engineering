/* ROM address: 0x000449ee; body bytes: 60; decompiled */

char FUN_000449ee(void)

{
  if (DAT_ffffcb20 < 1.5) {
    if (DAT_ffffcb20 < 1.4) {
      DAT_ffffcb25 = '\0';
    }
  }
  else {
    DAT_ffffcb25 = '\x01';
  }
  DAT_ffffcb24 = DAT_ffffcb25 == '\x01';
  return DAT_ffffcb25;
}


