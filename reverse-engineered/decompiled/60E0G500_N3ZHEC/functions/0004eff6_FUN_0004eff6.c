/* ROM address: 0x0004eff6; body bytes: 64; decompiled */

char FUN_0004eff6(void)

{
  if (DAT_ffffcff5 == '\x01') {
    DAT_ffffcfef = '\x02';
  }
  else if (DAT_ffffcfef != '\0') {
    DAT_ffffcfef = DAT_ffffcfef + -1;
  }
  DAT_ffffd005 = DAT_ffffcfef != '\0';
  return DAT_ffffcff5;
}


