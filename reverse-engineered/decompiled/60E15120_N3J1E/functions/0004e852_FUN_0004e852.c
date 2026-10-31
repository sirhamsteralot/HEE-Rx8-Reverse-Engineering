/* ROM address: 0x0004e852; body bytes: 64; decompiled */

char FUN_0004e852(void)

{
  if (DAT_ffffcfb9 == '\x01') {
    DAT_ffffcfb3 = '\x02';
  }
  else if (DAT_ffffcfb3 != '\0') {
    DAT_ffffcfb3 = DAT_ffffcfb3 + -1;
  }
  DAT_ffffcfc9 = DAT_ffffcfb3 != '\0';
  return DAT_ffffcfb9;
}


