/* ROM address: 0x0004efcc; body bytes: 42; decompiled */

char FUN_0004efcc(void)

{
  if (DAT_ffffcff4 == '\x01') {
    DAT_ffffcff0 = '\x02';
  }
  else if (DAT_ffffcff0 != '\0') {
    DAT_ffffcff0 = DAT_ffffcff0 + -1;
  }
  return DAT_ffffcff4;
}


