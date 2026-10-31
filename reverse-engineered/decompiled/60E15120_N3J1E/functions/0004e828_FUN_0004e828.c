/* ROM address: 0x0004e828; body bytes: 42; decompiled */

char FUN_0004e828(void)

{
  if (DAT_ffffcfb8 == '\x01') {
    DAT_ffffcfb4 = '\x02';
  }
  else if (DAT_ffffcfb4 != '\0') {
    DAT_ffffcfb4 = DAT_ffffcfb4 + -1;
  }
  return DAT_ffffcfb8;
}


